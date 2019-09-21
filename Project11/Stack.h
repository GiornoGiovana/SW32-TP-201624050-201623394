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
		if (!isEmpry()) {
			Node* aux = top;
			top = top->next;
			delete aux;
		}
	}
	uint size() { return len; }
	bool isEmpry() { return len == 0; }
	T _top() { return top->elem; }
};