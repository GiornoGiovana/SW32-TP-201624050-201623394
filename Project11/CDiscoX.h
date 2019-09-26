#pragma once
#include "CPersonaje.h"

class CDiscoX : public CPersonaje {
	short dx, dy;
public:
	CDiscoX(short x, short y) : CPersonaje(4, 1, Rectangle(100, 300, 75, 75)), dx(15), dy(15) {}
	void animarDiscoX(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
		CPersonaje::dibujar(imagen, buffer);
		this->indiceX = (this->indiceX == nImagenesX - 1) ? 0 : this->indiceX + 1;
		this->mover(limite);
	}
private:
	void mover(Size limite) {
		if (this->areaDibujo.X + this->dx < 0 || this->areaDibujo.X + this->areaDibujo.Width + this->dx > limite.Width)
			this->dx *= -1;
		this->areaDibujo.X += this->dx;
		if (this->areaDibujo.Y + this->dy < 0 || this->areaDibujo.Y + this->areaDibujo.Height + this->dy > limite.Height)
			this->dy *= -1;
		this->areaDibujo.Y += this->dy;

	}
};