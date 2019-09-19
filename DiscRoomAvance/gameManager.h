#pragma once

#include "Jugador.h"
#include "Menu_juego.h"
#include "nivel.h"

using namespace System::Drawing;


class GameManager {

	Nivel** niveles;
	Jugador* jugador;
	Menu_juego* menu;

	int nivel;
	int vidas;
	int stop_time;
	int velocidad;
	int n;
	int tiempo;
	bool menu_act;
	bool pierdevid;

public:

	GameManager() {
		niveles = new Nivel*[5];
		jugador = new Jugador(318, 264);
		menu = new Menu_juego();

		tiempo =  15;

		stop_time = 0;
		velocidad = 1;
	
		n = -1;
		pierdevid = false;

		menu_act = true;

		nivel = 0;
		vidas = 5;

		Nivel* lvl1 = new Nivel();
		Nivel* lvl2 = new Nivel();
		Nivel* lvl3 = new Nivel();
		Nivel* lvl4 = new Nivel();
		Nivel* lvl5 = new Nivel();

		//CIERRAS CON MOVIMIENTO RELO HORARIO
		Cierra* cierra_c1 = new Cierra(122, 144, 30, 30, 5, 40);
		Cierra* cierra_c2 = new Cierra(440, 144, 30, 30, 5, 30);
		Cierra* cierra_c3 = new Cierra(122, 408, 30, 30, 5, 20);
		Cierra* cierra_c4 = new Cierra(440, 408, 30, 30, 5, 60);
		Cierra* cierra_c5 = new Cierra(102, 300, 30, 30, 5, 100);
		Cierra* cierra_c7 = new Cierra(302, 220, 45, 45, 5, 150);
		Cierra* cierra_c6 = new Cierra(302, 244, 45, 45, 5, 150);

		//CIERRAS CON MOVIMIENTO RELOJ ANTIHORARIO
		Cierra* cierra_cuad1 = new Cierra(585, 500, 4, 4, 40, 40, 4);
		Cierra* cierra_cuad2 = new Cierra(2, 500, 5, 5, 50, 50, 4);
		Cierra* cierra_cuad3 = new Cierra(445, 500, 5, 5, 50, 50, 4);
		Cierra* cierra_cuad4 = new Cierra(625, 500, 5, 5, 50, 50, 4);
		Cierra* cierra_cuad5 = new Cierra(245, 500, 5, 5, 40, 40, 4);

		//CIERRAS CON MOVIMIENTO DIAGONAL
		Cierra* cierra_diag1 = new Cierra(122, 344, 2, 2, 75, 75, 1);
		Cierra* cierra_diag2 = new Cierra(500, 144, 2, 2, 30, 30, 1);
		Cierra* cierra_diag3 = new Cierra(122, 408, 2, 2, 60, 60, 1);
		Cierra* cierra_diag4 = new Cierra(440, 408, 2, 2, 40, 40, 1);
		Cierra* cierra_diag5 = new Cierra(244, 144, 2, 2, 20, 20, 1);
		Cierra* cierra_diag6 = new Cierra(400, 100, 2, 2, 80, 80, 1);
		Cierra* cierra_diag7 = new Cierra(90, 300, 2, 2, 80, 80, 1);

		//CIERRRAS CON MOVIMIENTO HORIZONTAL
		Cierra* cierra_hor1 = new Cierra(238, 376, 10, 10, 75, 75, 2);
		Cierra* cierra_hor2 = new Cierra(102, 144, 10, 10, 40, 40, 2);
		Cierra* cierra_hor3 = new Cierra(142, 360, 10, 10, 50, 50, 2);
		Cierra* cierra_hor4 = new Cierra(100, 360, 5, 5, 80, 80, 2);
		Cierra* cierra_hor5 = new Cierra(264, 144, 15, 15, 50, 50, 2);

		//CIERRRAS CON MOVIMIENTO VERTICAL
		Cierra* cierra_ver1 = new Cierra(238, 376, 15, 15, 75, 75, 3);
		Cierra* cierra_ver2 = new Cierra(102, 144, 5, 5, 80, 80, 3);
		Cierra* cierra_ver3 = new Cierra(142, 288, 5, 5, 50, 50, 3);
		Cierra* cierra_ver4 = new Cierra(224, 288, 8, 8, 50, 50, 3);
		Cierra* cierra_ver5 = new Cierra(440, 144, 5, 5, 90, 90, 3);

		//CIERRAS PERSEGUIDORAS
		Cierra* cierra_per1 = new Cierra(480, 90, 2, 3, 40, 40, 6);
		Cierra* cierra_per2 = new Cierra(240, 104, 2, 2, 45, 45, 6);	
		Cierra* cierra_per3 = new Cierra(0, 250, 3, 2, 30, 30, 6);

		lvl1->Agregar_cierra(cierra_cuad5);
		lvl1->Agregar_cierra(cierra_cuad2);
		lvl1->Agregar_cierra(cierra_cuad3);
		lvl1->Agregar_cierra(cierra_diag1);

		lvl2->Agregar_cierra(cierra_c3);
		lvl2->Agregar_cierra(cierra_c1);
		lvl2->Agregar_cierra(cierra_c4);
		lvl2->Agregar_cierra(cierra_diag3);
		lvl2->Agregar_cierra(cierra_diag4);
		lvl2->Agregar_cierra(cierra_diag2);

		lvl3->Agregar_cierra(cierra_hor2);
		lvl3->Agregar_cierra(cierra_hor5);
		lvl3->Agregar_cierra(cierra_ver2);
		lvl3->Agregar_cierra(cierra_ver3);
		lvl3->Agregar_cierra(cierra_ver5);
		lvl3->Agregar_cierra(cierra_diag6);

		lvl4->Agregar_cierra(cierra_hor4);
		lvl4->Agregar_cierra(cierra_cuad1);
		lvl4->Agregar_cierra(cierra_per2);
		lvl4->Agregar_cierra(cierra_c4);

		lvl5->Agregar_cierra(cierra_diag1);
		lvl5->Agregar_cierra(cierra_diag3);
		lvl5->Agregar_cierra(cierra_diag4);
		lvl5->Agregar_cierra(cierra_cuad5);
		lvl5->Agregar_cierra(cierra_per1);
		lvl5->Agregar_cierra(cierra_cuad1);
		lvl5->Agregar_cierra(cierra_per3);

		niveles[0] = lvl1;
		niveles[1] = lvl2;
		niveles[2] = lvl3;
		niveles[3] = lvl4;
		niveles[4] = lvl5;
	}

	~GameManager() {};

	Jugador* getJugador() { return jugador; }
	Menu_juego* getMenu() { return menu; }
	int getNivel() { return nivel; }
	int getTiempo() { return tiempo; }
	bool getMenuact() { return menu_act; }
	int getVidas() { return vidas; }
	bool getPierdevid() { return pierdevid; }
	void setVidas(int vid) { vidas = vid; }

	void mover_jugador(BufferedGraphics ^buffer, Bitmap^ bmp);
	void controlar_inputs(System::Windows::Forms::KeyEventArgs^ e);
	void controlar_inputs_soltar(System::Windows::Forms::KeyEventArgs^ e);
	void dibujar_menu(BufferedGraphics ^buffer, Bitmap^ bmp, Bitmap^ bmp1, Bitmap^ bmp2, Bitmap^ bmp3, Bitmap^ bmp4, Bitmap^ bmp5);
	void dibujar_hud(BufferedGraphics ^buffer, Bitmap^ bmp, int tiempo);
	void controlar_cursor();
	void Colisiones();
	void movimientos_cierras(BufferedGraphics ^buffer, Bitmap^ bmp, Bitmap^ bmp2);
	void dibujar_mapa(BufferedGraphics ^buffer, Bitmap^ bmp);
	void dibujar_opcion(BufferedGraphics ^buffer, Bitmap^ bmp);
	void cambiar_nivel();
	bool calcularHitbox(Jugador* jugador, Cierra* cierra);
	void reiniciar_lvl();
};