#pragma once
#include "List.h"
#include "CDiscoB.h"

class CListDiscB {
	List<CDiscoB*>* listB;
public:
	CListDiscB() {
		this->listB = new List<CDiscoB*>();
	}
	~CListDiscB() {
		for (short i = 0; i < this->listB->size(); i++) {
			CDiscoB* disc = listB->at(i);
			delete disc;
		}
		delete listB;
	}
	void animarDiscos(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
		for (short i = 0; i < this->listB->size(); i++) {
			CDiscoB* disc = listB->at(i);
			disc->animarDiscoA(imagen, buffer, limite);
		}
	}
	void agregarDisco() {
		Random r;
		short x = r.Next(0, 450);
		short y = r.Next(0, 500);
		CDiscoB* discB = new CDiscoB(x, y);
		this->listB->push_back(discB);
	}
	void eliminarDisco(uint pos) {
		this->listB->removePosition(pos);
	}
	void pop_back() {
		this->listB->pop_back();
	}
	uint size() { return this->listB->size(); }
	bool isEmpty() { return this->listB->isEmpty(); }
};