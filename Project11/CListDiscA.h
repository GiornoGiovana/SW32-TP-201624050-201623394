#pragma once
#include "List.h"
#include "CDiscoA.h"

class CListDiscA {
	List<CDiscoA*>* listA;
public:
	CListDiscA() {
		this->listA = new List<CDiscoA*>();
	}
	~CListDiscA() {
		for (short i = 0; i < this->listA->size(); i++) {
			CDiscoA* disc = listA->at(i);
			delete disc;
		}
		delete listA;
	}
	void animarDiscos(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
		for (short i = 0; i < this->listA->size(); i++) {
			CDiscoA* disc = listA->at(i);
			disc->animarDiscoA(imagen, buffer, limite);
		}
	}
	void agregarDisco() {
		Random r;
		short x = r.Next(0, 450);
		short y = r.Next(0, 500);
		CDiscoA* discA = new CDiscoA(x, y);
		this->listA->push_back(discA);
	}
	void eliminarDisco(uint pos) {
		this->listA->removePosition(pos);
	}
	void pop_back() {
		this->listA->pop_back();
	}
	uint size() { return this->listA->size(); }
	bool isEmpty() { return this->listA->isEmpty(); }
};