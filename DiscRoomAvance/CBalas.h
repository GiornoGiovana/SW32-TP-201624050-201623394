#pragma once
#include "CSprite.h"
#include "List.h"
ref class CBala : public CSprite{
	short dx, dy;
public:
	CBala(Bitmap^ imagen, short x, short y)
		:CSprite(imagen, Rectangle(x, y, 30, 30), 1, 1), dx(10), dy(10){
	}
	void disparar(BufferedGraphics^ buffer, short dir) {
		this->dirigirBala(dir);
		CImagen::dibujar(buffer);
	}
private:
	void dirigirBala(short dir) {
		switch (dir)
		{
		case 1: this->dx += dx; break;
		case 2: this->dx -= dx; break;
		case 3: this->dy += dy; break;
		case 4: this->dy -= dy; break;
		default:
			break;
		}
	}
};

ref class ListBalas {
	List^ balitas;
	Bitmap^ bala1, ^bala2, ^bala3, ^bala4;
	CBala^ balita1, ^balita2, ^balita3, ^balita4;
public:
	ListBalas() {
		this->imagenBalas();
		this->balitas = gcnew List();
	}
	void dibujarBalas(BufferedGraphics^ buffer) {
		for (short i = 0; i < this->balitas->size(); i++) {
			this->balitas->elemet(i)->dibujar(buffer);
		}
	}
	uint size() {
		return this->balitas->size();
	}
	bool isEmpty() {
		return this->balitas->isEmpty();
	}
	CSprite^ at(uint pos) {
		return this->balitas->elemet(pos);
	}
	void removeBala(uint pos) {
		this->balitas->remove(pos);
	}
	void crearBala() {
		Random r;
		short x = r.Next(200, 400);
		short y = r.Next(0, 400);
		this->balita1 = gcnew CBala(this->bala1, x, y);
		this->balitas->add(balita1);
		short x1 = r.Next(250, 500);
		short y1 = r.Next(100, 400);
		this->balita2 = gcnew CBala(this->bala2, x1, y1);
		this->balitas->add(balita2);
		short x2 = r.Next(0, 600);
		short y2 = r.Next(0, 400);
		this->balita3 = gcnew CBala(this->bala3, x2, y2);
		this->balitas->add(balita3);
		short x3 = r.Next(0, 700);
		short y3 = r.Next(0, 400);
		this->balita4 = gcnew CBala(this->bala4, x3, 3);
		this->balitas->add(balita4);
	}
private:
	void imagenBalas() {
		this->bala1 = gcnew Bitmap("Imagenes\\Bala1.png");
		this->bala2 = gcnew Bitmap("Imagenes\\Bala2.png");
		this->bala3 = gcnew Bitmap("Imagenes\\Bala3.png");
		this->bala4 = gcnew Bitmap("Imagenes\\Bala4.png");
	}

};
