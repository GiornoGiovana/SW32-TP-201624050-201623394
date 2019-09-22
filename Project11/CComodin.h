#pragma once
#include "CPersonaje.h"
using namespace System;
using namespace System::Drawing;


class CComodin{
	Rectangle area;
	short x, y;
public:
	CComodin(short x, short y): x(x), y(y) {}
	~CComodin(){}
	void dibujar(Bitmap^ imagen, BufferedGraphics^ buffer) {
		area = Rectangle(50, 50, 40, 40);
		Color color = imagen->GetPixel(0, 0);
		imagen->MakeTransparent(color);
		buffer->Graphics->DrawImage(imagen, area);
	}
	bool colision(CPersonaje* per) {
		return this->area.IntersectsWith(per->getArea());
	}
};