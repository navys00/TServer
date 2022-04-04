#pragma once
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
	
	Patient GetPatient() 
	{
		return Patients.pop();//сделать сохранение ретюрна
	}
	~PatientController() {
		Patients.~TQueue();
	}

};