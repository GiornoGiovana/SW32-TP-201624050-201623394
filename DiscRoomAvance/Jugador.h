#pragma once
#include "actor.h"
#include <vector>


class Jugador : Actor
{
public:
	Jugador();
	~Jugador();
	Jugador(int x, int y);

	int getX() { return x; }
	int getY() { return y; }
	int getDX() { return dx; }
	int getDY() { return dy; }
	int getAncho() { return anchoActor; }
	int getAlto() { return altoActor; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	std::vector<direcciones> teclas_presionadas;
	void mover(BufferedGraphics ^buffer, Bitmap^ bmp);
};