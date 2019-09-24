#pragma once
#include <vector>
#include"CProtagonista.h"
#include "CListDiscA.h"
#include "CListDiscB.h"
#include "CListDiscX.h"
#include "CStackX.h"
#include "CComodin.h"
using namespace std;
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
public:
	CGame():c1(nullptr), c2(nullptr), c3(nullptr) {
		this->SStar = new Stack<CComodin*>();
		this->prota = new CProtagonista();
		this->lstB = new CListDiscB();
		this->lstA = new CListDiscA();
		this->lstX = new CListDiscX();
		this->botton = false;
		this->agregarStar();
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
	}
	void agregarDiscA() {
		this->lstA->agregarDisco();
	}
	void agregarDiscB() {
		this->lstB->agregarDisco();
	}
	void choqueDiscos(Bitmap^ imgX, BufferedGraphics^ buffer, Size limite) {
		Random r;
		int pos = 0;
		for (short i = 0; i < this->lstA->size(); i++) {
			for(short j = 0; j < this->lstB->size(); j++) {
				if (this->lstA->at(i)->colision(this->lstB->at(j))) {		
				}
			}
		}
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
		this->c1 = new Hongo1(Rectangle(50, 50, 40, 40));
		this->c2 = new Hongo2(Rectangle(397, 300, 40, 40));
		this->c3 = new Hongo3(Rectangle(200, 400, 40, 40));
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
};
/*
	void agregarComodin(Bitmap^ imgStar, Bitmap^ imgX, BufferedGraphics^ buffer, Size limite) {


	}
	void popDiscX() {

	}
	void animarDiscX(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
	}
	//this->choqueDiscos(imgStar, imgX, buffer, limite);

		//this->animarDiscX(imgX, buffer, limite);
		//this->agregarComodin(imgStar, imgX, buffer, limite);
		//this->agregarComodin(imgStar, imgX, buffer, limite);
		//this->popDiscX();
*/