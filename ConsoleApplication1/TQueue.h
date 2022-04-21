#pragma once
#include "TStack.h"

template <class T>
class TQueue : public TStack<T>
{
protected:
	size_t low_ind = 0;
	virtual int GetNextIndex(int ind)const //override
	{
		return ++ind % this->size;
	}
public:
	TQueue() { }
	TQueue(size_t _size) :TStack<T>(_size) {}
	virtual T pop()override
	{
		if (this->IsEmpty())
		{
			throw std::runtime_error("Queue is empty");
		}
		T& tmp = this->mass[low_ind];
		this->num--;
		low_ind = GetNextIndex(low_ind);
		return tmp;
	}
	
};
