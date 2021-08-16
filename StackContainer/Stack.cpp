#include "Stack.h"

Stack::Element::Element(int src)
	:
	val(src),
	nextPtr(nullptr)
{
}

Stack::Element::Element(int src, Element* next)
	:
	val(src),
	nextPtr(next)
{
}


Stack::Stack(const Stack& src)
	:
	index(src.index)
{
	for (int i = 0; i < index + 1; i++)
	{
		ptrArr[i] = new Element(src.ptrArr[i]->val, src.ptrArr[i]->nextPtr);
	}
}

Stack& Stack::operator=(const Stack& src)
{
	index = src.index;
	for (int i = 0; i < index + 1; i++)
	{
		ptrArr[i] = new Element(src.ptrArr[i]->val, src.ptrArr[i]->nextPtr);
	}
	return *this;
}

Stack::~Stack()
{
	for (int i = 0; i < index + 1; i++)
	{
		delete ptrArr[i];
	}
	delete[] ptrArr;
}

void Stack::Push(int val)
{
	Element* e = new Element(val);
	if (index == -1)
	{
		index = 0;
	}
	else
	{
		ptrArr[index]->nextPtr = e;
		index++;
	}
	ptrArr[index] = e;
}

int Stack::Pop()
{
	if (index == -1)
	{
		return -1;
	}
	else if (index == 0)
	{
		int val = ptrArr[index]->val;
		delete ptrArr[index];
		index = -1;
		return val;
	}
	else
	{
		int val = ptrArr[index]->val;
		ptrArr[index - 1]->nextPtr = nullptr;
		delete ptrArr[index];
		index--;
		return val;
	}
}

int Stack::Size() const
{
	return index + 1;
}

bool Stack::Empty() const
{
	return index == -1;
}
