#pragma once
#include "Stack.h"
#include "CDiscoX.h"

class CStackX {
	Stack<CDiscoX*>* stcX;
public:
	CStackX(){
		this->stcX = new Stack<CDiscoX*>;
	}
	~CStackX() {
		delete this->stcX;
	}
	void push(CDiscoX* discX) {
		//CDiscoX* discX = new CDiscoX(50, 50);
		this->stcX->push(discX);
	}
	void pop() {
		this->stcX->pop();
	}
	CDiscoX* top() {
		return this->stcX->_top();
	}
	int size() { return this->stcX->size(); }
	bool isEmpty() { return this->stcX->is_empty(); }
};