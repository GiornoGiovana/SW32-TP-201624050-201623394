#pragma once
typedef unsigned int uint;
template <typename T>

class Stack {
	struct Node {
		T elem;
		Node* next;
		Node(T elem, Node* next = nullptr){}
	};
	Node* top;
	uint len;
public:
	Stack():top(nullptr), len(0){}
	~Stack() {
		while (top = nullptr) {
			Node* aux = top;
			top = top->next;
			delete aux;
		}
	}
	void push(T elem) {
		top = new Node(elem, top);
		++len;
	}
	void pop() {
		if (!isEmpty()) {
			Node* aux = top;
			top = top->next;
			delete aux;
		}
	}
	T _top() { return top->elem; }
	uint size() { return len; }
	bool isEmpty() { return len == 0; }
};