#pragma once

template <typename T>
class Stack {
	struct Node {
		T elem;
		Node*   next;

		Node(T elem, Node* next = nullptr) : elem(elem), next(next) {}
	};

	Node* top;
	int len;
public:
	Stack() : top(nullptr), len(0) {}
	~Stack() {
		while (top != nullptr) {
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
		if (!is_empty()) {
			Node* aux = top;
			top = top->next;
			delete aux;
			--len;
		}
	}
	T _top() {
		if (!is_empty()) {
			return top->elem;
		}
		return 0;
	}
	bool is_empty() { return top == nullptr; }
	int size() { return len; }

};