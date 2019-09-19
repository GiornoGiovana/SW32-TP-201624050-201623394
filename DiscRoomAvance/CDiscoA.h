#pragma once
#include "CSprite.h"

ref class CDiscoA : public CSprite {
	short dx, dy;
	Size limite;
public:
	CDiscoA(Bitmap^ imagen, Rectangle areaDibujo, Size limite)
		:CSprite(imagen, areaDibujo, 4, 1), dx(7), dy(7), limite(limite) {}
	void animar(BufferedGraphics^ buffer)override {
		CSprite::animar(buffer);
		this->mover();
	}
private:
	void mover() {
		if (this->areaDibujo.X + this->dx < 0 || this->areaDibujo.X + this->areaDibujo.Width + this->dx > limite.Width)
			this->dx *= -1;
		this->areaDibujo.X += this->dx;
		if (this->areaDibujo.Y + this->dy < 0 || this->areaDibujo.Y + this->areaDibujo.Height + this->dy > limite.Height)
			this->dy *= -1;
		this->areaDibujo.Y += this->dy;
	}
};
