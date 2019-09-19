#pragma once
using namespace System::Drawing;

enum direcciones
{
	ninguna,
	abajo,
	arriba,
	derecha,
	izquierda,
};

class Actor
{
protected:
	int x;
	int y;
	int dx;
	int dy;
	int anchoActor;
	int altoActor;
	int indiceX;
	int indiceY;

	direcciones direccion;

public:
	Actor() {};
	void dibujar(BufferedGraphics ^buffer, Bitmap^ bmp, float zoomX, float zoomY) {
		Rectangle porcionAusar = Rectangle(indiceX*anchoActor, indiceY*altoActor, anchoActor, altoActor);
		Rectangle aumentoPersonaje = Rectangle(x, y, anchoActor*zoomX, altoActor*zoomY);
		buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionAusar, GraphicsUnit::Pixel);
	}

	~Actor() {};
};