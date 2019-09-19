#include "gameManager.h"
#include <cmath>

void GameManager::controlar_inputs(System::Windows::Forms::KeyEventArgs^ e) {
	int aux = 0;
	if (vidas > 0) {
		if (menu_act == true) {
			switch (e->KeyCode)
			{
			case System::Windows::Forms::Keys::Left: if (n > -1) {
				n--;
			}break;
			case System::Windows::Forms::Keys::Right: if (n < 1) {
				n++;
			}break;
			case System::Windows::Forms::Keys::Up:if (n == 0)vidas++; if (n == 1)tiempo++; if (n == -1 && menu->getOpcion() < 5) {
				menu->setOpcion(menu->getOpcion() + 1);
				nivel = menu->getOpcion() - 1;
			}break;
			case System::Windows::Forms::Keys::Down:if (n == 0 && vidas > 1)vidas--; if (n == 1 && tiempo > 10)tiempo--; if (n == -1 && menu->getOpcion() > 1) {
				menu->setOpcion(menu->getOpcion() - 1);
				nivel = menu->getOpcion() - 1;
			} break;
			case  System::Windows::Forms::Keys::Enter:
					n = 4;
					menu->setY(0);
					menu->setX(500);
					menu_act = false;
					reiniciar_lvl();
					break;
			}
			if (n == 0) {
				menu->setX(150);
				menu->setY(480);
			}
			else if (n == 1) {
				menu->setX(430);
				menu->setY(480);
			}
			else if (n == -1) {
				menu->setX(318);
				menu->setY(75);
			}
		}
		else if (pierdevid && vidas > 0) {
			switch (e->KeyCode)
			{
			case System::Windows::Forms::Keys::Left: n = 1;	menu->setX(240); break;
			case System::Windows::Forms::Keys::Right: n = 2; menu->setX(400); break;
			case System::Windows::Forms::Keys::Enter: if(n == 1){
				reiniciar_lvl();
				pierdevid = false;
				menu->setY(0);
				menu->setX(500);
				n = 4;
			}else if (n == 2) {
				jugador->setX(318);
				jugador->setY(264);
				menu->setX(318);
				menu->setY(75);
				vidas = 5;
				tiempo = 45;
				menu->setOpcion(1);
				nivel = 0;
				menu_act = true;
				pierdevid = false;
				n = -1;
				}
			}
		}else {
			switch (e->KeyCode)
			{
			case System::Windows::Forms::Keys::Left:
				for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
					if (*it == izquierda) {
						aux++;
						break;
					}
				}
				if (aux < 1) {
					jugador->teclas_presionadas.push_back(izquierda);
					for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
						if (*it == ninguna) {
							jugador->teclas_presionadas.erase(it);
							break;
						}
					}
				}
				break;
			case System::Windows::Forms::Keys::Right:
				for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
					if (*it == derecha) {
						aux++;
						break;
					}
				}
				if (aux < 1) {
					jugador->teclas_presionadas.push_back(derecha);
					for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
						if (*it == ninguna) {
							jugador->teclas_presionadas.erase(it);
							break;
						}
					}
				}
				break;
			case System::Windows::Forms::Keys::Up:
				for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
					if (*it == arriba) {
						aux++;
						break;
					}
				}
				if (aux < 1) {
					jugador->teclas_presionadas.push_back(arriba);
					for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
						if (*it == ninguna) {
							jugador->teclas_presionadas.erase(it);
							break;
						}
					}
				}
				break;
			case System::Windows::Forms::Keys::Down:
				for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
					if (*it == abajo) {
						aux++;
						break;
					}
				}
				if (aux < 1) {
					jugador->teclas_presionadas.push_back(abajo);
					for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
						if (*it == ninguna) {
							jugador->teclas_presionadas.erase(it);
							break;
						}
					}
				}
				break;
			case System::Windows::Forms::Keys::C: if (stop_time != -1)stop_time++;
			}
		}
	}
	else {
		if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
			jugador->setX(318);
			jugador->setY(264);
			menu->setX(318);
			menu->setY(75);
			vidas = 5;
			tiempo = 45;
			nivel = 0;
			menu->setOpcion(1);
			menu_act = true;
			pierdevid = false;
			n = -1;
		}
	}
}

void GameManager::controlar_inputs_soltar(System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode)
	{
	case System::Windows::Forms::Keys::Left: 
		for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
			if (*it == izquierda) {
				jugador->teclas_presionadas.erase(it);
				break;
			}
		}
		break;
	case System::Windows::Forms::Keys::Right:
		for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
			if (*it == derecha) {
				jugador->teclas_presionadas.erase(it);
				break;
			}
		}
		break;
	case System::Windows::Forms::Keys::Up: 
		for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
			if (*it == arriba) {
				jugador->teclas_presionadas.erase(it);
				break;
			}
		}
		break;
	case System::Windows::Forms::Keys::Down:
		for (std::vector<direcciones>::iterator it = jugador->teclas_presionadas.begin(); it != jugador->teclas_presionadas.end(); it++) {
			if (*it == abajo) {
				jugador->teclas_presionadas.erase(it);
				break;
			}
		}
		break;
	}
}

void GameManager::controlar_cursor() {
	if (stop_time >= 1 || stop_time == -1) {
		if (menu->mover_cursor(n)) {
			stop_time = 0;
			velocidad = 1;
			n = 4;
		}
	}
	if (stop_time >= 2) {
		if (menu->getX() <= 554) {
			velocidad = 2;
			n = 1;
		}
		if (menu->getX() > 554 && menu->getX() <= 604) {
			velocidad = 4;
			n = 1;
		}
		if (menu->getX() > 604 && menu->getX() <= 630) {
			velocidad = 5;
			n = 1;
		}
		stop_time = -1;
	}
}

bool GameManager::calcularHitbox(Jugador* jugador, Cierra* cierra) {

	System::Drawing::Rectangle rectangleA;

	rectangleA.X = jugador->getX();
	rectangleA.Y = jugador->getY();

	rectangleA.Width = jugador->getAncho();
	rectangleA.Height = jugador->getAlto();

	System::Drawing::Rectangle rectangleB;

	rectangleB.X = cierra->getX();
	rectangleB.Y = cierra->getY();
	rectangleB.Width = cierra->getAncho();
	rectangleB.Height = cierra->getAlto();

	return rectangleB.IntersectsWith(rectangleA);
}

void GameManager::reiniciar_lvl() {

	for (size_t  i = 0; i < niveles[nivel]->getN_cierras_lista(); i++) {
		niveles[nivel]->getlista_cierras()->elementoEnPosicion(i)->reiniciar_pos();
	}
	jugador->setX(318);
	jugador->setY(264);
}

void GameManager::Colisiones() {
	for (size_t  i = 0; i < niveles[nivel]->getN_cierras_lista(); i++) {
		if (calcularHitbox(jugador,niveles[nivel]->getlista_cierras()->elementoEnPosicion(i))) {
			vidas--;
			pierdevid = true;
			menu->setY(280);
			menu->setX(240);
			n = 1;
		}
	}
}
void GameManager::movimientos_cierras(BufferedGraphics ^buffer, Bitmap^ bmp, Bitmap^ bmp2) {
	double angulo;
	for (size_t  i = 0; i < niveles[nivel]->getN_cierras_lista(); i++) {
		angulo = atan2((jugador->getX() + jugador->getAncho()/2) - (niveles[nivel]->getlista_cierras()->elementoEnPosicion(i)->getX() + niveles[nivel]->getlista_cierras()->elementoEnPosicion(i)->getAncho()/2), (jugador->getY() + jugador->getAlto() / 2) - (niveles[nivel]->getlista_cierras()->elementoEnPosicion(i)->getY() + niveles[nivel]->getlista_cierras()->elementoEnPosicion(i)->getAlto() / 2));
		niveles[nivel]->getlista_cierras()->elementoEnPosicion(i)->mover(buffer,bmp,bmp2, angulo, velocidad);
	}
}

void GameManager::dibujar_mapa(BufferedGraphics ^buffer, Bitmap^ bmp) {
		niveles[nivel]->Dibujar_mapa(buffer, bmp);
}

void GameManager::dibujar_menu(BufferedGraphics ^buffer, Bitmap^ bmp, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Bitmap^ bmp4, Bitmap^ bmp5) {
	char *gg = new char[1000];
	System::Drawing::Font ^ font = gcnew Font("OCR A Extended", 19);
	System::Drawing::SolidBrush ^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);;
	System::String ^s = gcnew System::String(itoa(vidas, gg, 10));
	System::String ^n = gcnew System::String(itoa(tiempo, gg, 10));
	menu->Dibujar_menu(buffer, bmp,bmp1,bmp2,bmp3,bmp4,bmp5, brush, font);
	buffer->Graphics->DrawString(s, font, brush, (buffer->Graphics->VisibleClipBounds.Right / 6) + 100, 500);
	buffer->Graphics->DrawString(n, font, brush, (buffer->Graphics->VisibleClipBounds.Right / 6) + 380, 500);
}

void GameManager::dibujar_hud(BufferedGraphics ^buffer, Bitmap^ bmp, int tiempo) {
	char *gg = new char[1000];
	System::Drawing::Font ^ font = gcnew Font("OCR A Extended", 19);
	System::Drawing::SolidBrush ^ brush;
	System::String ^s = gcnew System::String(itoa(vidas, gg, 10));
	System::String ^n = gcnew System::String(itoa(nivel + 1, gg, 10));
	System::String ^t = gcnew System::String(itoa(tiempo, gg, 10));
	if (nivel == 0) {
		brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkOliveGreen);
	}
	else if (nivel == 1) {
		brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::HotPink);
	}
	else if (nivel == 2) {
		brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::LightBlue);
	}
	else if (nivel == 3) {
		brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow);
	}
	else if (nivel == 4) {
		brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);
	}
	buffer->Graphics->DrawString(n, font, brush, 250, 0);
	buffer->Graphics->DrawString(t, font, brush, 400, 0);
	buffer->Graphics->DrawString(s, font, brush, 110, 0);
	menu->Dibujar_hud(buffer, bmp, brush, font);
}

void GameManager::dibujar_opcion(BufferedGraphics ^buffer, Bitmap^ bmp) {
	buffer->Graphics->DrawImage(bmp, buffer->Graphics->VisibleClipBounds.Right / 3.7, buffer->Graphics->VisibleClipBounds.Bottom / 3);
}

void GameManager::cambiar_nivel() {
	nivel++;
	reiniciar_lvl();
}

void GameManager::mover_jugador(BufferedGraphics ^buffer, Bitmap^ bmp) {
	jugador->mover(buffer, bmp);
}