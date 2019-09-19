#pragma once
#include "Node.h"
typedef unsigned int uint;

template <typename E>

class CList {
	struct Node {
		E elem;
		Node* next;
		Node(E elem = nada, Node* next = nullptr)
			:elem(elem), next(next){}
	};
	Node* head;
	uint len;
public:
	CList():head(nullptr), len(0){}
	~CList() {
		while (head != nullptr) {
			Node* aux = head;
			head = head->next;
			delete aux;
		}
	}
///// AGREGAR ELEMENTOS
	void addFirst(E elem) {
		head = new Node(elem, head);
		++len;
	}
	void addPosition(E elem, uint pos) {
		if (pos == 0) {
			addFirst(elem);
		} else if (pos > 0 && pos <= len) {
			Node* aux = head;
			for (short i = 0; i < pos - 1; ++i) {
				aux = aux->next;
			}
			Node* newNode = new Node(elem, aux->next);
			aux->next = newNode;
			++len;
		}
	}
	void addLast(E elem) {
		addPosition(elem, len);
	}
///// Eliminar Pos
	void removeFirst() {
		Node* aux = head;
		head = head->next;
		delete aux;
		--len;
	}
	void removePosition(uint pos) {
		if (pos == 0) {
			removeFirst(pos);
		} else if (pos > 0 && pos <= len) {
			Node* aux = head;
			for (short i = 0; i < pos - 1; ++i) {
				aux = aux->next;
			}
			Node* aux2 = aux->next;
			aux->next = aux2->next;
			--len;
		}
	}
	void removeLast() {
		removePosition(len - 1);
	}
////  Otras operaciones
	bool isEmpty() {
		return len == 0;
	}
	int size() {
		return len;
	}
	int find(float elem) {
		Node* aux = head;
		int pos = 0;
		while (aux != nullptr) {
			if (aux->elem == elem)
				return pos;
			aux = aux->next;
			++pos;
		}
		return -1;
	}
//// 
	E at(uint pos) {
		if (pos >= 0 && pos < len) {
			Node* aux = head;
			for (short i = 0; i < pos; ++i) {
				aux = aux->next;
			}
			return aux->elem;
		}

	}
};