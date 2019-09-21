#pragma once
#include"CProtagonista.h"
#include "CListDiscA.h"
#include "CListDiscB.h"
#include "CListBalas.h"
#include "Stack.h"
class CGame {
	CProtagonista* prota;
	CListDiscB* lstB;
	CListDiscA* lstA;
	CListBalas* lstBalas;
	Stack<CBalas*>* stckBalas;
public:
	CGame() {
		this->prota = new CProtagonista();
		this->lstB = new CListDiscB();
		this->lstA = new CListDiscA();
		this->lstBalas = new CListBalas();
		this->stckBalas = new Stack<CBalas*>;
		this->lstBalas->agregarBalas();
	}
	~CGame() {
		delete this->prota;
	}
	void jugar(Bitmap^ imgA, Bitmap^ imgB, Bitmap^ imgPro, BufferedGraphics^ buffer, Size limite) {
		this->lstA->animarDiscos(imgA, buffer, limite);
		this->lstB->animarDiscos(imgB, buffer, limite);
		this->prota->dibujar(imgPro, buffer);
		this->guardarBalas();
	}
	void agregarDiscA() {
		this->lstA->agregarDisco();
	}
	void agregarDiscB() {
		this->lstB->agregarDisco();
	}
	void removerDiscA() {
		this->lstA->pop_back();
	}
	void dibujarBalas(Bitmap^ bal1, Bitmap^ bal2, Bitmap^ bal3, Bitmap^ bal4, BufferedGraphics^ buffer) {
		this->lstBalas->animarBalas(bal1, bal2, bal3, bal4, buffer);
	}
	void removerDiscB() {
		this->lstB->pop_back();
	}
	void animarProta(Size limite, short tecla) {
		this->prota->animar(limite, tecla);
	}
	void guardarBalas() {
		if (!this->lstBalas->isEmpty()) {
			for (short i = 0; i < this->lstBalas->size(); i++) {
				CBalas* bullet = this->lstBalas->at(i);
				if (this->prota->colision(bullet)) {
					CBalas* pBullet = bullet;
					this->stckBalas->push(pBullet);
					delete bullet;
					this->lstBalas->eliminarBalasEn(i);
				}
			}
		}
	}
	void disparar(BufferedGraphics^ buffer) {
		if (!this->stckBalas->isEmpty()) {
			for (short i = 0; i < this->stckBalas->size(); i++) {
				CBalas* bulleto = this->stckBalas->_top();
				bulleto = new CBalas(this->prota->getArea().X + (this->prota->getArea().Width / 2), this->prota->getArea().Y + (this->prota->getArea().Height / 2));
				bulleto->dibujarBala(gcnew Bitmap("Imagenes\\bala1.png"), buffer);
				//bulleto->setPosition(this->prota->getArea().X + (this->prota->getArea().Width / 2), this->prota->getArea().Y + (this->prota->getArea().Height / 2));
				bulleto->dirigirBala(this->prota->getPos());
				//this->stckBalas->pop();
			}
		}
	}







	/*void animarDiscoA(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
	this->lstA->animarDiscos(imagen, buffer, limite);
}
void animarDiscoB(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
	this->lstB->animarDiscos(imagen, buffer, limite);
}
void dibujarProta(Bitmap^ imagen, BufferedGraphics^ buffer) {
	this->prota->dibujar(imagen, buffer);
}*/
};
