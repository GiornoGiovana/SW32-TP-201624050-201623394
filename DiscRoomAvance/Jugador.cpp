#include "Jugador.h"



Jugador::Jugador()
{
}


Jugador::~Jugador()
{
}

Jugador::Jugador(int x, int y) {

	this->x = x;
	this->y = y;
	dx = 0;
	dy = 0;
	anchoActor = 25;
	altoActor = 39;
	indiceX = 0;
	indiceY = 0;
}

void Jugador::mover(BufferedGraphics ^buffer, Bitmap^ bmp) {

	if (teclas_presionadas.size() == 0) {
		teclas_presionadas.push_back(ninguna);
	}

	if (teclas_presionadas.size() > 2) {
		teclas_presionadas.erase(teclas_presionadas.begin());
	}

	for (int i = 0; i < teclas_presionadas.size(); i++) {
		switch (teclas_presionadas.at(i))
		{
		case ninguna:
			dx = 0; dy = 0;
			break;
		case abajo:indiceX = 0; if (indiceY >= 0 && indiceY < 2) indiceY++; else
		{
			indiceY = 0;
		}
		dy = 10; dx = 0;
			break;
		case arriba:
			indiceX = 2; if (indiceY >= 0 && indiceY < 2) indiceY++; else
			{
				indiceY = 0;
			}
			dy = -10; dx = 0;
			break;
		case derecha:
			indiceX = 3; if (indiceY >= 0 && indiceY < 2) indiceY++; else
			{
				indiceY = 0;
			}
			dx = 10; dy = 0;
			break;
		case izquierda:
			indiceX = 1;
			if (indiceY >= 0 && indiceY < 2) indiceY++;
			else
			{
				indiceY = 0;
			}
			dx = -10; dy = 0;
			break;
		}
		if ((x > buffer->Graphics->VisibleClipBounds.Right / 10 && dx < 0) || (x - anchoActor < buffer->Graphics->VisibleClipBounds.Right - buffer->Graphics->VisibleClipBounds.Right / 5 && dx > 0)) {
			x += dx;
		}
		if ((y + altoActor > buffer->Graphics->VisibleClipBounds.Bottom / 10 && dy < 0) || (y < buffer->Graphics->VisibleClipBounds.Bottom - buffer->Graphics->VisibleClipBounds.Bottom / 5 && dy > 0)) {
			y += dy;
		}
	}

	dibujar(buffer, bmp, 1.5, 1.5);
}