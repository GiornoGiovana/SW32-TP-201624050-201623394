#pragma once
#include "CSprite.h"
enum Direcciones { Abajo, Izquierda, Derecha, Arriba };
ref class CProtagonista : public CSprite{
	short dx, dy;
public:
	CProtagonista(Rectangle areaDibujo)
		:CSprite("imagenes\\protagonista.png", areaDibujo, 9, 4), dx(10),dy(10) {
	}
	void animar(Size limite, int tecla) override {
		switch (Direcciones(tecla))
		{
		case Abajo: if (this->areaDibujo.Y + dy + this->alto < limite.Height) {
			this->indiceY = 2; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.Y += dy;
		}break;
		case Izquierda:if (this->areaDibujo.X - dx > 0) {
			this->indiceY = 1; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.X -= dx;
		}break;
		case Derecha:if (this->areaDibujo.X + dx + this->ancho < limite.Width) {
			this->indiceY = 3; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.X += dx;
		}break;
		case Arriba: if (areaDibujo.Y - dy > 0) {
			this->indiceY = 0; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.Y -= dy;
		}break;
		default:
			break;
		}
	}

};