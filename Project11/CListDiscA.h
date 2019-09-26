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
	void agregarDisco() {
		Random r;
		CDiscoA* discA = new CDiscoA(f(0, 450), f(0, 500));
		this->listA->push_back(discA);
	}
	void animarDiscos(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
		for (short i = 0; i < this->listA->size(); i++) {
			CDiscoA* disc = listA->at(i);
			disc->animarDiscoA(imagen, buffer, limite);
		}
	}
	short _find(CDiscoA* otro) {
		return this->listA->find(otro);
	}
	short getPosicionX(uint i) {
		return this->listA->at(i)->getX();
	}
	short getPosicionY(uint i) {
		return this->listA->at(i)->getY();
	}
	CDiscoA* at(uint pos) {
		return this->listA->at(pos);
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