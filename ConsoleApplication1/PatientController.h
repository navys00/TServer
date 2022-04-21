#pragma once
#include<vector>
#include"TQueue.h"
#include<iostream>
#include"TStack.h"
#include"CardWorker.h"
#include<string>
class PatientController 
{
private:
	CardWorker cw;
	TQueue<Patient> Patients;
public:
	PatientController() 
	{
		Patients = TQueue<Patient>(10);
		
		cw.ParseCard();
	}
	void Parser() 
	{
		Patient tmp;//������� �������� �� ������� �� �������
		std::vector<std::string> pat_list; //��� �������� ����� � ����������� � ���������
		while (!cw._pQueuePatient->IsEmpty()) {
			std::string Pat;//���������� �� ������� �������� �� �������, ������� ����� �������� �������, �� ������� �������� ����� ������, ����� � ���������� � ������
			tmp = cw._pQueuePatient->pop();
			Pat += tmp.FIO;
			Pat += ' ';
			Pat += tmp.BornDate;
			Pat += ' ';
			Pat += tmp.Gender;
			pat_list.push_back(Pat);
		}
	}
	/*Patient Getpatient2() {
		Patient tmp= cw._pQueuePatient->pop();
		return tmp;
	}*/
	Patient GetPatient() 
	{
		//return Patients.pop();//������� ���������� �������
		Patient returnpatient = Patients.Pop();
		return returnpatient;
	}
	~PatientController() {
		Patients.~TQueue();
	}

};