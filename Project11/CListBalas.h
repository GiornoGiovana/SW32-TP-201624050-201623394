#pragma once
#include "CBalas.h"
#include "List.h"
class CListBalas {
	List<CBalas*>* balas;
	CBalas* bala1;
	CBalas* bala2;
	CBalas* bala3;
	CBalas* bala4;
public:
	CListBalas() {
		this->balas = new List<CBalas*>();
		bala1 = new CBalas(154, 89);
		bala2 = new CBalas(50, 50);
		bala3 = new CBalas(204, 300);
		bala4 = new CBalas(450, 200);
	}
	void animarBalas(Bitmap^ bal1, Bitmap^ bal2, Bitmap^ bal3, Bitmap^ bal4, BufferedGraphics^ buffer) {
		bala1->dibujarBala(bal1, buffer);
		bala2->dibujarBala(bal2, buffer);
		bala3->dibujarBala(bal3, buffer);
		bala4->dibujarBala(bal4, buffer);
	}
	void agregarBalas() {
		this->balas->push_back(bala1);
		this->balas->push_back(bala2);
		this->balas->push_back(bala3);
		this->balas->push_back(bala4);
	}
	void eliminarBalasEn(uint pos) {
		this->balas->removePosition(pos);
	}
	void eliminarBala() {
		this->balas->pop_back();
	}
	CBalas* at(uint i) { return this->balas->at(i); }
	uint size() { return this->balas->size(); }
	bool isEmpty() { return this->balas->isEmpty(); }
};