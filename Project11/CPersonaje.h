#pragma once
#include <cstdlib>
#include <ctime>
#include <functional>
using namespace System;
using namespace System::Drawing;
using namespace std;
function<short(short, short)>f = [](short limInf, short limiSup) { return rand() % (limiSup - limInf + 1) + limInf; };
class CPersonaje {
protected:
	Rectangle areaDibujo;
	short x, y;
	short nImagenesX, nImagenesY;
	short ancho, alto;
	short indiceX, indiceY;
public:
	CPersonaje(short nImX,short nImY, Rectangle area)
		:nImagenesX(nImX), nImagenesY(nImY) {
		this->areaDibujo = area;
		this->indiceX = 0;
		this->indiceY = 0;
	}
	~CPersonaje(){}
	int getX() { return this->areaDibujo.X; }
	int getY() { return this->areaDibujo.Y; }
	void setPosition(short x, short y) {
		this->areaDibujo.X = x;
		this->areaDibujo.Y = y;
	}
	void dibujar(Bitmap^ imagen, BufferedGraphics^ buffer) {
		this->ancho = imagen->Width / this->nImagenesX;
		this->alto = imagen->Height / this->nImagenesY;
		this->x = indiceX * ancho;
		this->y = indiceY * alto;
		Color color = imagen->GetPixel(0, 0);
		imagen->MakeTransparent(color);
		Rectangle areaRecorte = Rectangle(this->x, this->y, this->ancho, this->alto);
		buffer->Graphics->DrawImage(imagen, this->areaDibujo, areaRecorte, GraphicsUnit::Pixel);
	}
	Rectangle getArea() { return this->areaDibujo; }
	bool colision(CPersonaje* otro) { return this->areaDibujo.IntersectsWith(otro->getArea()); }

};