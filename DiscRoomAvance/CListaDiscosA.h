#pragma once
#include "CDiscoA.h"
#include "List.h"

ref class CListaDiscosA {
	CDiscoA^ discA;
	List^ listA;
	Bitmap^ imagenDiscoA;
	Size limite;
public:
	CListaDiscosA(Size limite): limite(limite) {
		this->imagenDiscoA = gcnew Bitmap("imagenes\\discoA.png");
		this->listA = gcnew List();
	}
	~CListaDiscosA() {
		delete listA;
	}
	void agregarDisco() {
		Random r;
		short x = r.Next(50, 600);
		short y = r.Next(50, 450);
		this->discA = gcnew CDiscoA(this->imagenDiscoA, Rectangle(x, y, 70, 70), limite);
		this->listA->add(discA);
	}
	void eliminarDisco(int pos) {
		this->listA->remove(pos);
	}
	void animarDiscos(BufferedGraphics^ buffer) {
		for (short i = 0; i < this->listA->size(); i++) {
			this->listA->elemet(i)->animar(buffer);
		}
	}
	int size() {
		return this->listA->size();
	}
};