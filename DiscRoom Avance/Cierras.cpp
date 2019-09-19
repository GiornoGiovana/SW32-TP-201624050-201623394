#define _USE_MATH_DEFINES

#include "cierras.h"
#include <cmath>

Cierra::Cierra(int x, int y, int alto, int ancho, int tipo_mov, int radio) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	angulo = 0;
	altoActor = alto;
	anchoActor = ancho;
	indiceX = 0;
	indiceY = 0;
	this->tipo_mov = tipo_mov;
	this->radio = radio;
	constX = x;
	constY = y;
	direccion = derecha;
	xguradado = this->x;
	yguardado = this->y;
	dxguardado = this->dx;
	dyguardado = this->dy;
}

Cierra::Cierra(int x, int y, int dx, int dy, int alto, int ancho, int tipo_mov) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	angulo = 0;
	altoActor = alto;
	anchoActor = ancho;
	indiceX = 0;
	indiceY = 0;
	this->tipo_mov = tipo_mov;
	constX = x;
	constY = y;
	direccion = derecha;
	xguradado = this->x;
	yguardado = this->y;
	dxguardado = this->dx;
	dyguardado = this->dy;
}

void Cierra::dibujar(BufferedGraphics ^buffer, Bitmap ^bmp) {
	Rectangle porcionAusar = Rectangle(indiceX*40, indiceY*40, 40, 40);
	Rectangle aumentoPersonaje = Rectangle(x, y, anchoActor, altoActor);
	buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionAusar, GraphicsUnit::Pixel);
	indiceX++;
	if (indiceX > 4) {
		indiceX = 0;
	}
}

void Cierra::mover(BufferedGraphics ^buffer, Bitmap^ bmp, Bitmap^ bmp2, double angle, int velocidad) {
	if (velocidad != 5) {
		switch (tipo_mov)
		{
		case 1:

			x += dx / velocidad;
			y += dy / velocidad;
			if (x > buffer->Graphics->VisibleClipBounds.Right - buffer->Graphics->VisibleClipBounds.Right / 5 || x < buffer->Graphics->VisibleClipBounds.Right / 10) {
				dx *= -1;
			}
			if (y > buffer->Graphics->VisibleClipBounds.Bottom - buffer->Graphics->VisibleClipBounds.Bottom / 5 || y < buffer->Graphics->VisibleClipBounds.Bottom / 10) {
				dy *= -1;
			}
			break;//diagonal
		case 2:
			x += dx / velocidad;
			if (x > buffer->Graphics->VisibleClipBounds.Right - buffer->Graphics->VisibleClipBounds.Right / 5 || x < buffer->Graphics->VisibleClipBounds.Right / 10) {
				dx *= -1;
			}
			break;//horizontal
		case 3:
			y += dy / velocidad;
			if (y > buffer->Graphics->VisibleClipBounds.Bottom - buffer->Graphics->VisibleClipBounds.Bottom / 5 || y < buffer->Graphics->VisibleClipBounds.Bottom / 10) {
				dy *= -1;
			}
			break;//vertical
		case 4:


			switch (direccion)
			{
			case abajo: y += dy / velocidad;
				break;
			case arriba: y -= dy / velocidad;
				break;
			case derecha: x += dx / velocidad;
				break;
			case izquierda: x -= dx / velocidad;
				break;
			}
			if (x - (anchoActor / 4) > buffer->Graphics->VisibleClipBounds.Right - buffer->Graphics->VisibleClipBounds.Right / 5) {
				x -= dx / velocidad;
				direccion = arriba;
			}
			if (y + (altoActor / 4) < buffer->Graphics->VisibleClipBounds.Bottom / 10) {
				y += dy / velocidad;
				direccion = izquierda;
			}
			if (x + (anchoActor / 2) < buffer->Graphics->VisibleClipBounds.Right / 10) {
				x += dx / velocidad;
				direccion = abajo;
			}
			if (y - (altoActor / 4) > buffer->Graphics->VisibleClipBounds.Bottom - buffer->Graphics->VisibleClipBounds.Bottom / 5) {
				y -= dy/velocidad;
				direccion = derecha;
			}
			break;//pegado a la pared
		case 5:
			x = constX + cos(angulo) * radio;
			y = constY + sin(angulo) * radio;
			angulo += M_PI / (24 * velocidad);
			break;//circular
		case 6:
			x += sin(angle) * (dx / velocidad);
			y += cos(angle) * (dy / velocidad);
			break;//perseguidor
		}
	}
			if (tipo_mov == 6) {
				dibujar(buffer, bmp2);
			}
			else {
				dibujar(buffer, bmp);
			}
}