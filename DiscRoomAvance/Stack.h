#pragma once
#include "CBalas.h"
ref class Nodin {
public:
	CSprite^ elem;
	Nodin^ next;
	Nodin(CSprite^ elem, Nodin^ next)
		:elem(elem), next(next){}
};

ref class Stackin {
	Nodin^ top;
	int len;
public:
	Stackin() :top(nullptr), len(0){}
	~Stackin() {
		while (top != nullptr) {
			Nodin^ aux = top;
			aux = aux->next;
			delete aux;
		}
	}
	int size() { return len; }
	bool isEmpty() { return len == 0; }
	void push(CSprite^ elem) {
		top = gcnew Nodin(elem, top);
		++len;
	}
	void pop() {
		if (!isEmpty()) {
			Nodin^ aux = top;
			top = top->next;
			delete aux;
			--len;
		}
		
	}
	CSprite^ _top() {
		if (!isEmpty()) {
			return top->elem;
		}	
	}
};