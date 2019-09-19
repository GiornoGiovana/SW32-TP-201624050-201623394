#pragma once
#include "CProta.h"
#include "CListaDiscosA.h"
#include "CListaDiscosB.h"
#include "Stack.h"
ref class CJuego {
	CProtagonista^ prota;
	CImagen^ escenario;
	CListaDiscosA^ listaDiscosA;
	CListaDiscosB^ listaDiscosB;
	ListBalas^ balas;
	Stackin^ Sbalines;
public:
	CJuego(Rectangle areaFormulario, Size limite) {
		this->escenario = gcnew CImagen("imagenes\\escenario.jpg", areaFormulario);
		this->prota = gcnew CProtagonista(Rectangle(200, 100, 75, 100));
		this->listaDiscosA = gcnew CListaDiscosA(limite);
		this->listaDiscosB = gcnew CListaDiscosB(limite);
		this->balas = gcnew ListBalas();
		this->balas->crearBala();
		this->Sbalines = gcnew Stackin();
	}
	~CJuego() {
		delete this->escenario;
		delete this->prota;
		delete this->listaDiscosA;
		delete this->listaDiscosB;
	}
	void play(BufferedGraphics^ buffer) {
		this->escenario->dibujar(buffer);
		this->prota->dibujar(buffer);
		this->listaDiscosA->animarDiscos(buffer);
		this->listaDiscosB->animarDiscos(buffer);
		this->balas->dibujarBalas(buffer);
		this->guardarBalas();
	}
	void moverJugador(short dir, Size limite) {
		this->prota->animar(limite, dir);
	}
	void agregardiscoA() {
		this->listaDiscosA->agregarDisco();
		this->listaDiscosB->agregarDisco();
	}
	void eliminarDiscoA() {
		this->listaDiscosA->eliminarDisco(this->listaDiscosA->size() - 1);
	}
private:
	void guardarBalas() {
		for (short i = 0; i < this->balas->size(); i++) {
			CSprite^ balin = this->balas->at(i);
			if (prota->colision(balin)) {
				this->Sbalines->push(balin);
				delete balin;
				this->balas->removeBala(i);
			}
		}
	}
};