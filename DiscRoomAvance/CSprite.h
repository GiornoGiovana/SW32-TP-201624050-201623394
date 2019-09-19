#pragma once

using namespace System;
using namespace System::Drawing;

ref class CImagen {
protected:
	Bitmap^ imagen;
	Rectangle areaDibujo;
public:
	CImagen(Bitmap^ imagen, Rectangle areaDibujo)
		:imagen(imagen), areaDibujo(areaDibujo) {}
	CImagen(String^ ruta, Rectangle areaDibujo) {
		this->imagen = gcnew Bitmap(ruta);
		this->areaDibujo = areaDibujo;
	}
	CImagen(){}
	virtual void dibujar(BufferedGraphics^ buffer) {
		buffer->Graphics->DrawImage(this->imagen, this->areaDibujo);
	}
	Rectangle getArea() { return this->areaDibujo; }
	void setPosition(int x, int y) {
		this->areaDibujo.X = x;
		this->areaDibujo.Y = y;
	}
	bool colision(CImagen^ otro) {
		return this->areaDibujo.IntersectsWith(otro->getArea());
	}
protected:
	void hacerTransparente() {
		Color color = this->imagen->GetPixel(0, 0);
		this->imagen->MakeTransparent(color);
	}
};

ref class CSprite : public CImagen{
protected:
	short indiceX, indiceY;
	short nImagenesX, nImagenesY;
	short ancho, alto;
public:
	CSprite(String^ ruta, Rectangle areaDibujo, short nroSIAncho, short nroSIAlto)
		: CImagen(ruta, areaDibujo), nImagenesX(nroSIAncho), nImagenesY(nroSIAlto) {
		this->indiceX = 0;
		this->indiceY = 0;
	}
	CSprite(Bitmap^ imagen, Rectangle areaDibujo, short nroSIAncho, short nroSIAlto)
		: CImagen(imagen, areaDibujo), nImagenesX(nroSIAncho), nImagenesY(nroSIAlto) {
		this->hacerTransparente();
		this->indiceX = 0;
		this->indiceY = 0;
	}
	virtual void animar(BufferedGraphics^ buffer) {
		this->dibujar(buffer);
		this->indiceX = (this->indiceX == nImagenesX - 1) ? 0 : this->indiceX + 1;
	}
	void dibujar(BufferedGraphics^ buffer)override {
		buffer->Graphics->DrawImage(this->imagen, this->areaDibujo, this->areaRecorte(), GraphicsUnit::Pixel);
	}
private:
	Rectangle areaRecorte() {
		this->ancho = this->imagen->Width / nImagenesX;
		this->alto = this->imagen->Height / nImagenesY;
		short x = this->indiceX*ancho;
		short y = this->indiceY*alto;
		return Rectangle(x, y, ancho, alto);
	}
};