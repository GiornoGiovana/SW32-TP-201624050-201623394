#pragma once
#include "CProtagonista.h"
using namespace System;
using namespace System::Drawing;


class CComodin{
	Rectangle area;
public:
	CComodin(Rectangle _area) {
		area = _area;
	}
	~CComodin(){}
	void dibujarComodin(Bitmap^ imagen, BufferedGraphics^ buffer) {	
		buffer->Graphics->DrawImage(imagen, area);
	}
	virtual void Skill(CProtagonista* prota) {
	}
	bool colision(CProtagonista* per) {
		return this->area.IntersectsWith(per->getArea());
	}
};

class Hongo1 : public CComodin {
public:
	Hongo1(Rectangle a) : CComodin(a){}
	void Skill(CProtagonista* prota)override {
		prota->setSpeed(30);
	}
};
class Hongo2 : public CComodin {
public:
	Hongo2(Rectangle a): CComodin(a){}
	void Skill(CProtagonista* prota)override {
		prota->setSpeed(5);
	}
};
class Hongo3 : public CComodin {
public:
	Hongo3(Rectangle a) : CComodin(a){}
	void Skill(CProtagonista* prota)override {
		prota->setSpeed(15);
	}
};

/*
	void setArea(short x, short y, Rectangle a) { this->area.X = x; this->area.Y = y; this->area = a; }
	Rectangle getArea() { return this->area; }
*/