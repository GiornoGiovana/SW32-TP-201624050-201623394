#pragma once
#include "CDiscoB.h"
#include "List.h"
ref class CListaDiscosB {
	CDiscoA^ discB;
	List^ listB;
	Bitmap^ imagenDiscoB;
	Size limite;
public:
	CListaDiscosB(Size limite) : limite(limite) {
		this->imagenDiscoB = gcnew Bitmap("imagenes\\discoB.png");
		this->listB = gcnew List();
	}
	~CListaDiscosB() {
		delete listB;
	}
	void agregarDisco() {
		this->discB = gcnew CDiscoA(this->imagenDiscoB, Rectangle(350, 350, 70, 70), limite);
		this->listB->add(discB);
	}
	void eliminarDisco(int pos) {
		this->listB->remove(pos);
	}
	void animarDiscos(BufferedGraphics^ buffer) {
		for (short i = 0; i < this->listB->size(); i++) {
			this->listB->elemet(i)->animar(buffer);
		}
	}
	int size() {
		return this->listB->size();
	}

};