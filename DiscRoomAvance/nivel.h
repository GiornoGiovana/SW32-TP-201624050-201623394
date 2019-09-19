#pragma once

#include "cierras.h"
#include "lista.hpp"

class Nivel {
	Lista<Cierra *>* lista_cierras = new Lista<Cierra *>();
public:
	Nivel() {
	}
	void Agregar_cierra(Cierra* cierra) {
		lista_cierras->agregarInicio( cierra );
	}
	void Dibujar_mapa(BufferedGraphics ^buffer, Bitmap^ bmp) {
		Rectangle size = Rectangle(0, 0, buffer->Graphics->VisibleClipBounds.Right, buffer->Graphics->VisibleClipBounds.Bottom);
		buffer->Graphics->DrawImage(bmp, size);
	}
	int getN_cierras_lista() { return lista_cierras->getNe(); };

	Lista<Cierra *>* getlista_cierras() { return lista_cierras; };

	~Nivel() {};
};