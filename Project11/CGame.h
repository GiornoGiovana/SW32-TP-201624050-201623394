#pragma once
#include"CProtagonista.h"
#include "CListDiscA.h"
#include "CListDiscB.h"
#include "CListDiscX.h"
#include "CStackX.h"
#include "CComodin.h"

class CGame {
	CProtagonista* prota;
	CListDiscB* lstB;
	CListDiscA* lstA;
	CListDiscX* lstX;
	Stack<CComodin*>* SStar;
	Hongo1* c1;
	Hongo2* c2;
	Hongo3* c3;
	bool botton;
	bool ganar, perder;
public:
	CGame():c1(nullptr), c2(nullptr), c3(nullptr) {
		this->SStar = new Stack<CComodin*>();
		this->prota = new CProtagonista();
		this->lstB = new CListDiscB();
		this->lstA = new CListDiscA();
		this->lstX = new CListDiscX();
		this->botton = false;
		this->ganar = this->perder = false;
		this->agregarStar();
		this->prota->setVidas(50);
	}
	~CGame() {
		delete this->prota;
		delete this->lstA;
		delete this->lstB;
		delete this->lstX;
		if(c1) delete this->c1;
		if(c2) delete this->c2;
		if(c3) delete this->c3;
		delete this->SStar;
	}
	void jugar(Bitmap^ imgA, Bitmap^ imgB, Bitmap^ imgX, Bitmap^ hon1, Bitmap^ hon2, Bitmap^ hon3, Bitmap^ imgPro, BufferedGraphics^ buffer, Size limite) {
		this->lstA->animarDiscos(imgA, buffer, limite);
		this->lstB->animarDiscos(imgB, buffer, limite);
		this->prota->dibujar(imgPro, buffer);
		this->animarStar(hon1, hon2, hon3, buffer);
		this->stackComodin();
		this->activarComodin();
		this->matarProta();
		this->agregarDiscoX();
		this->animarDiscoX(imgX, buffer, limite);
	}
	void matarProta() {
		for (short i = 0; i < this->lstA->size(); i++) {
			CDiscoA* disquito = this->lstA->at(i);
			if (disquito->colision(this->prota)) {
				this->prota->perderVida();
			}
		}
		for (short i = 0; i < this->lstB->size(); i++) {
			CDiscoB* disquito = this->lstB->at(i);
			if (disquito->colision(this->prota)) {
				this->prota->perderVida();
			}
		}
		if (!this->lstX->isEmpty()) {
			if (this->lstX->at(0)->colision(this->prota))
				this->perder = true;
		}
	}
	void agregarDiscA() {
		this->lstA->agregarDisco();
	}
	void agregarDiscB() {
		this->lstB->agregarDisco();
	}
	void agregarDiscoX() {
		for (short i = 0; i < this->lstA->size(); i++) {
			CDiscoA* disquito = this->lstA->at(i);
			for(short j = 0; j < this->lstB->size(); j++) {
				CDiscoB* discaso = this->lstB->at(j);
				if (disquito->colision(discaso)){
					if (this->lstX->size() < 1)
						this->lstX->agregarDisco(disquito->getX(), discaso->getY());
				}
			}
		}
	}
	void animarDiscoX(Bitmap^ imgX, BufferedGraphics^ buffer, Size limite) {
		if (!this->lstX->isEmpty())
			this->lstX->at(0)->animarDiscoX(imgX, buffer, limite);
	}
	void removerDiscA() {
		this->lstA->pop_back();
	}
	void removerDiscB() {
		this->lstB->pop_back();
	}
	void animarProta(Size limite, short tecla) {
		this->prota->animar(limite, tecla);
	}
	void agregarStar() {
		Random r;
		this->c1 = new Hongo1(Rectangle(f(50, 100), f(50, 300), 60, 50));
		this->c2 = new Hongo2(Rectangle(f(350, 400), f(25, 200), 70, 60));
		this->c3 = new Hongo3(Rectangle(f(450, 650), f(350, 500), 40, 40));
	}
	void animarStar(Bitmap^ hon1, Bitmap^ hon2, Bitmap^ hon3, BufferedGraphics^ buffer) {
		if(c1) this->c1->dibujarComodin(hon1, buffer);
		if(c2) this->c2->dibujarComodin(hon2, buffer);
		if(c3) this->c3->dibujarComodin(hon3, buffer);
	}
	void stackComodin() {
		if (c1) {
			if (this->c1->colision(this->prota)) {
				this->SStar->push(c1);
				c1 = nullptr;
			}
		}
		if (c2) {
			if (this->c2->colision(this->prota)) {
				this->SStar->push(c2);
				c2 = nullptr;
			}
		}
		if (c3) {
			if (this->c3->colision(this->prota)) {
				this->SStar->push(c3);
				this->c3 = nullptr;
			}
		}
	}
	void activarComodin() {
		if (this->getBotton()) {
			if (!this->SStar->is_empty()) {
				CComodin* Star = this->SStar->_top();
				Star->Skill(this->prota);
				this->SStar->pop();
				this->botton = false;
			}
		}
	}
	bool getBotton() { return this->botton; }
	void setBotton(short x) { if (x == 1)this->botton = true; }
	bool getPerder() { return this->perder; }
	int getVidas() { return this->prota->getVidas(); }
};
