#pragma once
#include <functional>
typedef unsigned int uint;
using namespace std;
template <typename T>

class List {
	struct Node {
		T elem;
		Node* next;
		Node(T elem, Node* next = nullptr)
			:elem(elem), next(next){}
	};
	Node* head;
	uint len;
	typedef function<bool(T, T)> Comp;
	Comp compare;
public:
	List() :head(nullptr), len(0), compare([](T a, T b) {return a == b; }) {}
	~List() {
		while (head != nullptr) {
			Node* aux = head;
			head = head->next;
			delete aux;
		}
	}
	short find(T elem) {
		Node* aux = head;
		short cont = 0;
		while (aux != nullptr) {
			if (compare(aux->elem, elem)) {
				return cont;
			}
			cont++;
			aux = aux->next;
		}
		return -1;
	}
	void addPosition(T elem, uint pos) {
		if (pos == 0) {
			head = new Node(elem, head);
			++len;
		}else if (pos > 0 && pos <= len) {
			Node* aux = head;
			for (short i = 0; i < pos - 1; ++i) {
				aux = aux->next;
			}
			Node* newNode = new Node(elem, aux->next);
			if (newNode != nullptr) {
				aux->next = newNode;
				++len;
			}
		}
	}
	void push_back(T elem) {
		addPosition(elem, len);
	}
	void removePosition(uint pos) {
		if (pos == 0) {
			Node* aux = head;
			head = head->next;
			delete aux;
			--len;
		} else if (pos > 0 && pos < len) {
			Node* aux = head;
			for (short i = 0; i < pos - 1; i++) {
				aux = aux->next;
			}
			Node* aux2 = aux->next;
			if (aux != nullptr) {
				aux->next = aux2->next;
				delete aux2;
				--len;
			}
		}
	}
	void pop_back() {
		removePosition(len - 1);
	}
	T at(uint pos) {
		if (pos >= 0 && pos < len) {
			Node* aux = head;
			for (short i = 0; i < pos; ++i) {
				aux = aux->next;
			}
			return aux->elem;
		}
	}
	int size() {
		return len;
	}
	bool isEmpty() {
		return len == 0;
	}
};