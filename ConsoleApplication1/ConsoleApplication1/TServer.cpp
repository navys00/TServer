#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>



void handle_connections()
{
    //Создаём 'Планировщик задач'
    boost::asio::io_service ios;

    boost::asio::streambuf buff;
    std::ostringstream copy;
    //Создаём адресс нашего сервера. Если подать ip::tcp::v4(), то будет доступна только локальная сеть
    boost::asio::ip::tcp::endpoint ep = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 9999);
    //Создаём объект, следящий за подключением к нашему сокету.
    boost::asio::ip::tcp::acceptor acceptor(ios, ep);
    std::string msg("");

    while (true) {
        // Создаём сокет (вилку/разетку)
        boost::asio::ip::tcp::socket sock(ios);
        // Запускаем метод, который будет находиться в ожидании подключения к нам.
        // Как только к серверу подключаться программа продолжит своё выполнение
        acceptor.accept(sock);
        // Считывает в буфер собщение, отправленное клиентом
        size_t bytes = read_until(sock, buff, '\n');
        // Копируем буфер в объект, который может его расшифровать
        copy.str("");
        copy << &buff;
        buff.consume(bytes);

        msg = copy.str();
        std::cout << "server receive message: " << msg << std::unitbuf;
        //Пишем сообщение клиенту
        sock.write_some(boost::asio::buffer(msg));
        // Обрываем связь с клиентом
        sock.close();
    }
}

int main(int argc, char* argv[])
{
    handle_connections();

}