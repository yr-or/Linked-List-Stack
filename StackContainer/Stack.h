#pragma once

class Stack
{
public:
	class Element
	{
	public:
		int val;
		Element* nextPtr = nullptr;
	public:
		Element() = default;
		Element(int src);
		Element(int src, Element* next);
	};
public:
	Stack() = default;
	Stack(const Stack& src);
	Stack& operator=(const Stack& src);
	~Stack();
private:
	Element** ptrArr = new Element*[100];
	int index = -1;
public:
	void Push(int val);
	int Pop();
	int Size() const;
	bool Empty() const;
};