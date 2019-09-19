#pragma once
#include "actor.h"

class Cierra : Actor
{
	int tipo_mov;
	int constX, constY;
	int radio;
	int xguradado, yguardado,dxguardado,dyguardado;
	double angulo;

public:
	
	Cierra(int x, int y, int alto, int ancho, int tipo_mov, int radio);
	Cierra(int x, int y, int dx, int dy, int alto, int ancho, int tipo_mov);

	int getX() { return x; }
	int getY() { return y; }
	int getDX() { return dx; }
	int getDY() { return dy; }
	int getAncho() { return anchoActor; }
	int getAlto() { return altoActor; }

	void mover(BufferedGraphics ^buffer, Bitmap^ bmp, Bitmap^ bmp2, double angulo, int velocidad);
	void dibujar(BufferedGraphics ^buffer, Bitmap^ bmp);
	void reiniciar_pos() {

		x = xguradado;
		y = yguardado;
		dx = dxguardado;
		dy = dyguardado;
		angulo = 0;
	}
	~Cierra() {};
};