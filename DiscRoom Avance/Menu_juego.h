#pragma once
using namespace System::Drawing;

class Menu_juego
{
	int cursorX, cursorY;
	int opcion;
public:
	Menu_juego() {
		opcion = 1;
		cursorX = 150;
		cursorY = 480;
	}
	int getX() { return cursorX; }
	int getOpcion() { return opcion; }

	void setX(int x) { cursorX = x; }
	void setY(int y) { cursorY = y; }
	void setOpcion(int op) { opcion = op; }

	bool mover_cursor(int n) {
		if (cursorX <= 640) {
			cursorX += n;
			return false;
		}
		else {
			cursorX = 500;
			return true;
		}
	}

	void Dibujar_menu(BufferedGraphics ^buffer, Bitmap^ bmp, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Bitmap^ bmp4, Bitmap^ bmp5, System::Drawing::SolidBrush^ brush, System::Drawing::Font ^ font) {
		Rectangle size = Rectangle(0, 0, buffer->Graphics->VisibleClipBounds.Right, buffer->Graphics->VisibleClipBounds.Bottom);
		Rectangle sizepic = Rectangle(buffer->Graphics->VisibleClipBounds.Right / 6, buffer->Graphics->VisibleClipBounds.Bottom / 6, buffer->Graphics->VisibleClipBounds.Right - buffer->Graphics->VisibleClipBounds.Right/3, buffer->Graphics->VisibleClipBounds.Bottom - buffer->Graphics->VisibleClipBounds.Bottom/3);
		buffer->Graphics->DrawImage(bmp,size);
		if (opcion == 1) {
			buffer->Graphics->DrawImage(bmp1, sizepic);
		}
		else if (opcion == 2) {
			buffer->Graphics->DrawImage(bmp2, sizepic);
		}
		else if (opcion == 3) {
			buffer->Graphics->DrawImage(bmp3, sizepic);
		}
		else if (opcion == 4) {
			buffer->Graphics->DrawImage(bmp4, sizepic);
		}
		else if (opcion == 5) {
			buffer->Graphics->DrawImage(bmp5, sizepic);
		}
		buffer->Graphics->DrawString("Vidas: ", font, brush, buffer->Graphics->VisibleClipBounds.Right / 6, 500);
		buffer->Graphics->DrawString("Tiempo: ", font, brush, (buffer->Graphics->VisibleClipBounds.Right / 6) + 270, 500);
	}
	void Dibujar_hud(BufferedGraphics ^buffer, Bitmap^ bmp, System::Drawing::SolidBrush^ brush, System::Drawing::Font ^ font) {
		buffer->Graphics->DrawString("Vidas: ",font, brush, 10, 0);
		buffer->Graphics->DrawString("Nivel: ", font, brush, 150, 0);
		buffer->Graphics->DrawString("Tiempo: ", font, brush, 290, 0);
		buffer->Graphics->DrawImage(bmp, 500, 0);
	}
	void Dibujar_cursor(BufferedGraphics ^buffer, Bitmap^ bmp) {
		buffer->Graphics->DrawImage(bmp, cursorX, cursorY);
	}
};