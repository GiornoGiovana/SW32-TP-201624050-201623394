#pragma once
#include "Node.h"
typedef unsigned int uint;

ref class List {
	Node^ head;
	uint len;
public:
	List():head(nullptr), len(0){}
	~List() {
		while (head != nullptr) {
			Node^ aux = head;
			head = head->next;
			delete aux;
		}
	}
	bool isEmpty() { return len == 0; }
	uint size() { return len; }
	void add(CSprite^ disc) {
		head = gcnew Node(disc, head);
		++len;
	}
	void remove(uint pos) {
		if (pos == 0) {
			Node^ aux = head;
			head = head->next;
			delete aux;
			--len;
		} else if (pos > 0 && pos < len) {
			Node^ aux = head;
			for (short i = 0; i < pos - 1; i++)
				aux = aux->next;
			Node^ aux1 = aux->next;
			aux->next = aux1->next;
			delete aux1;
			--len;
		}
	}
	CSprite^ elemet(uint pos) {
		Node^ aux = head;
		for (short i = 0; i < pos; i++) 
			aux = aux->next;
		return aux->disc;
	}
};