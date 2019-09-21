#pragma once
#include"CProtagonista.h"
#include "CDiscoA.h"
class CGame {
	CProtagonista* prota;
	CDiscoA* discA;

public:
	CGame() {
		this->prota = new CProtagonista();
		this->discA = new CDiscoA(300, 300);
	}
	~CGame() {
		delete this->prota;
	}
	void animarDiscoA(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
		this->discA->animarDiscoA(imagen, buffer, limite);
	}
	void dibujarProta(Bitmap^ imagen, BufferedGraphics^ buffer) {
		this->prota->dibujar(imagen, buffer);
	}
	void animarProta(Size limite, short tecla) {
		this->prota->animar(limite, tecla);
	}
};
