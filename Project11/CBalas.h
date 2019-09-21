#pragma once
#include "CPersonaje.h"

class CBalas : public CPersonaje {
	short dx, dy;
public:
	CBalas(short x, short y) :CPersonaje(1, 1, Rectangle(x, y, 20, 20)),dx(15), dy(15) {}
	void dibujarBala(Bitmap^ imagen, BufferedGraphics^ buffer) {
		CPersonaje::dibujar(imagen, buffer);
	}
	void dirigirBala(short d) {
		switch (d) {
		case 1: this->areaDibujo.X += dx; break;
		case 2: this->areaDibujo.X -= dx; break;
		case 3: this->areaDibujo.Y += dy; break;
		case 4: this->areaDibujo.Y -= dy; break;
		}
	}
};

class CBala1 : public CPersonaje {
	short dx, dy;
public:
	CBala1():CPersonaje(1,1, Rectangle(154,89,20,20)){}
	void dibujarBala(Bitmap^ imagen, BufferedGraphics^ buffer) {
		CPersonaje::dibujar(imagen, buffer);
	}
	//void dirigirBala(short d) {
	//	switch (d) {
	//	case 1: this->areaDibujo.X += dx; break;
	//	case 2: this->areaDibujo.X -= dx; break;
	//	case 3: this->areaDibujo.Y += dy; break;
	//	case 4: this->areaDibujo.Y -= dy; break;
	//	}
	//}

};
class CBala2 : public CPersonaje {
	short dx, dy;
public:
	CBala2():CPersonaje(1,1,Rectangle(50,300,20,20)){}
	void dibujarBala(Bitmap^ imagen, BufferedGraphics^ buffer) {
		CPersonaje::dibujar(imagen, buffer);
	}
};
class CBala3 : public CPersonaje {
	short dx, dy;
public:
	CBala3() :CPersonaje(1, 1, Rectangle(250, 143, 20, 20)) {}
	void dibujarBala(Bitmap^ imagen, BufferedGraphics^ buffer) {
		CPersonaje::dibujar(imagen, buffer);
	}
};
class CBala4 : public CPersonaje {
	short dx, dy;
public:
	CBala4() :CPersonaje(1, 1, Rectangle(400, 250, 20, 20)) {}
	void dibujarBala(Bitmap^ imagen, BufferedGraphics^ buffer) {
		CPersonaje::dibujar(imagen, buffer);
	}
};