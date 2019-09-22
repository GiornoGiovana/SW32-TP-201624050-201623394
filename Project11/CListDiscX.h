#pragma once
#include "List.h"
#include "CDiscoX.h"

class CListDiscX {
	List<CDiscoX*>* listX;
public:
	CListDiscX() {
		this->listX = new List<CDiscoX*>();
	}
	~CListDiscX() {
		for (short i = 0; i < this->listX->size(); i++) {
			CDiscoX* disc = listX->at(i);
			delete disc;
		}
		delete listX;
	}
	void animarDiscos(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
		for (short i = 0; i < this->listX->size(); i++) {
			CDiscoX* disc = listX->at(i);
			disc->animarDiscoX(imagen, buffer, limite);
		}
	}
	void agregarDisco(short x, short y) {
		CDiscoX* discX = new CDiscoX(x, y);
		this->listX->push_back(discX);
	}
	void eliminarDisco(uint pos) {
		this->listX->removePosition(pos);
	}
	void pop_back() {
		this->listX->pop_back();
	}
	CDiscoX* at(uint pos) {
		return this->listX->at(pos);
	}
	uint size() { return this->listX->size(); }
	bool isEmpty() { return this->listX->isEmpty(); }
};