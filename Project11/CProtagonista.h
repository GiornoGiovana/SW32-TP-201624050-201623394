#pragma once
#include "CPersonaje.h"

enum Direcciones{Arriba = 72, Abajo = 80, Derecha = 77, Izquierda = 75};

class CProtagonista : public CPersonaje {
	short dx, dy;
	short pos;
public:
	CProtagonista() :CPersonaje(9,4, Rectangle(250,250, 70,70)),dx(10), dy(10){}
	void moverProta(Bitmap^ image, BufferedGraphics^ buffer) {
		CPersonaje::dibujar(image, buffer);
	}
	void setSpeed(short _d) { this->dx = _d; this->dy = _d; }
	void animar(Size limite, int tecla)  {
		switch (Direcciones(tecla))
		{
		case Arriba:
			if (areaDibujo.Y - dy > 0) {
				this->indiceY = 0; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.Y -= dy;
				this->pos = 4;
			}
			break;
		case Abajo:
			if (this->areaDibujo.Y + dy + this->alto < limite.Height) {
				this->indiceY = 2; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.Y += dy;
				this->pos = 3;
			}
			break;
		case Derecha:
			if (this->areaDibujo.X + dx + this->ancho < limite.Width) {
				this->indiceY = 3; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.X += dx;
				this->pos = 1;
			}
			break;
		case Izquierda:
			if (this->areaDibujo.X - dx > 0) {
				this->indiceY = 1; this->indiceX++; this->indiceX %= nImagenesX; this->areaDibujo.X -= dx;
				this->pos = 2;
			}
			break;
		default:
			break;
		}
	}
	short getPos() { return pos; }
};