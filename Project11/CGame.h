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
	CStackX* stcX;
	CComodin* cmdStar;
	bool comodin;
public:
	CGame() {
		this->prota = new CProtagonista();
		this->lstB = new CListDiscB();
		this->lstA = new CListDiscA();
		this->lstX = new CListDiscX();
		this->stcX = new CStackX();
		this->cmdStar = nullptr;
		this->comodin = false;
	}
	~CGame() {
		delete this->prota;
		delete this->lstA;
		delete this->lstB;
		delete this->lstX;
	}
	void jugar(Bitmap^ imgA, Bitmap^ imgB, Bitmap^ imgX, Bitmap^ imgStar, Bitmap^ imgPro, BufferedGraphics^ buffer, Size limite) {
		this->lstA->animarDiscos(imgA, buffer, limite);
		this->lstB->animarDiscos(imgB, buffer, limite);
		this->prota->dibujar(imgPro, buffer);
	
		this->choqueDiscos(imgStar, imgX, buffer, limite);

		//this->animarDiscX(imgX, buffer, limite);
		//this->agregarComodin(imgStar, imgX, buffer, limite);
		this->agregarComodin(imgStar, imgX, buffer, limite);
		this->popDiscX();
	}
	void agregarDiscA() {
		this->lstA->agregarDisco();
	}
	void agregarDiscB() {
		this->lstB->agregarDisco();
	}
	void choqueDiscos(Bitmap^ imgStar, Bitmap^ imgX, BufferedGraphics^ buffer, Size limite) {
		Random r;
		int pos = 0;
		for (short i = 0; i < this->lstA->size(); i++) {
			for(short j = 0; j < this->lstB->size(); j++) {
				if (this->lstA->at(i)->colision(this->lstB->at(j))) {
					//if (this->lstX->size() < 2) {
						this->lstX->agregarDisco(280, 210);
						////CDiscoX* discX = new CDiscoX(50, 50);
						//this->stcX->push(/*discX*/);
						////this->stcX->top()->animarDiscoX(imgX, buffer, limite);
						this->cmdStar = new CComodin(r.Next(0, 560), r.Next(0, 410));
						////->cmdStar->dibujar(imgStar, buffer);
					//}		
				}
			}
		}
	}
	void agregarComodin(Bitmap^ imgStar, Bitmap^ imgX, BufferedGraphics^ buffer, Size limite) {
		
		for (short i = 0; i < this->lstX->size(); i++) {
			this->stcX->push(this->lstX->at(i));
			//this->lstX->at(i)->animarDiscoX(imgX, buffer, limite);
		}
		if (!this->stcX->isEmpty() && cmdStar) {
			this->stcX->top()->animarDiscoX(imgX, buffer, limite);
			this->cmdStar->dibujar(imgStar, buffer);
		}
		//if (cmdStar) this->cmdStar->dibujar(imgStar, buffer);
	}
	void popDiscX() {
		if (!this->stcX->isEmpty()) {
			if (cmdStar) {
				if (cmdStar->colision(this->prota)) {
					this->stcX->pop();
					delete cmdStar;
					cmdStar = nullptr;
				}
			}
		}
	
	}
	void animarDiscX(Bitmap^ imagen, BufferedGraphics^ buffer, Size limite) {
		for (short i = 0; i < this->stcX->size(); i++) {
			CDiscoX* discX = this->stcX->top();
			discX->animarDiscoX(imagen, buffer, limite);

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

};
