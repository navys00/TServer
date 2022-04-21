#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>



void handle_connections()
{
    //������ '����������� �����'
    boost::asio::io_service ios;

    boost::asio::streambuf buff;
    std::ostringstream copy;
    //������ ������ ������ �������. ���� ������ ip::tcp::v4(), �� ����� �������� ������ ��������� ����
    boost::asio::ip::tcp::endpoint ep = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 9999);
    //������ ������, �������� �� ������������ � ������ ������.
    boost::asio::ip::tcp::acceptor acceptor(ios, ep);
    std::string msg("");

    while (true) {
        // ������ ����� (�����/�������)
        boost::asio::ip::tcp::socket sock(ios);
        // ��������� �����, ������� ����� ���������� � �������� ����������� � ���.
        // ��� ������ � ������� ������������ ��������� ��������� ��� ����������
        acceptor.accept(sock);
        // ��������� � ����� ��������, ������������ ��������
        size_t bytes = read_until(sock, buff, '\n');
        // �������� ����� � ������, ������� ����� ��� ������������
        copy.str("");
        copy << &buff;
        buff.consume(bytes);

        msg = copy.str();
        std::cout << "server receive message: " << msg << std::unitbuf;
        //����� ��������� �������
        sock.write_some(boost::asio::buffer(msg));
        // �������� ����� � ��������
        sock.close();
    }
}

int main(int argc, char* argv[])
{
    handle_connections();

}