#pragma once
#include <string>
#include"TQueue.h"
#include <iostream>
#include<fstream>
struct Patient {
    std::string FIO;
    std::string BornDate;
    bool Gender;

};
class CardWorker
{
public:
    TQueue<Patient>* _pQueuePatient;

    std::string _path = "PatientDatabase\\patient_";
    void ParseCard() {
        std::fstream fin;
       // bool fileCheck = true;
        std::string fio;
        std::string borndate;
        std::string gender;
        for (int i = 0;; i++) {
            std::string fullpath = this->_path + std::to_string(i) + ".txt";
            fin.open(fullpath);
            if (fin.is_open()) {
                
                std::getline(fin, fio);
                std::getline(fin, borndate);
                std::getline(fin, gender);
                Patient p;
                p.BornDate = borndate;
                p.FIO = fio;
                p.Gender = gender == "m" ? false : true;
                _pQueuePatient->Push(p);
                fin.close();
            }
            else {
                break;
            }
        }

    }
    CardWorker() {
        _pQueuePatient = new TQueue<Patient>(10);
        ParseCard();
    }

    


};


