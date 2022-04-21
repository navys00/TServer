#pragma once
#include<iostream>
#include<string>
#include"CardWorker.h"
template <class T>
class Doctor 
{private:
	Patient p;
public:

	Patient GetNextPatient();
	void PaintCurrentPatient();




};



template<class T>
inline Patient Doctor<T>::GetNextPatient()
{
	return Patient();
}

template<class T>
inline void Doctor<T>::PaintCurrentPatient()
{
	GetNextPatient();
}
