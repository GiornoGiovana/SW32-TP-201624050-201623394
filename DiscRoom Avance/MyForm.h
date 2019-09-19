#pragma once

#include "gameManager.h"

namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.

		Bitmap ^ bmpJugador = gcnew Bitmap("goku.png");
		Bitmap ^ bmpMenu = gcnew Bitmap("Menu.png");
		Bitmap ^ bmplvl1 = gcnew Bitmap("nivel1.png");
		Bitmap ^ bmplvl2 = gcnew Bitmap("nivel2.png");
		Bitmap ^ bmplvl3 = gcnew Bitmap("nivel3.png");
		Bitmap ^ bmplvl4 = gcnew Bitmap("nivel4.png");
		Bitmap ^ bmplvl5 = gcnew Bitmap("nivel5.png");
		Bitmap ^ bmpcierra = gcnew Bitmap("cierra.png");
		Bitmap ^ bmpcierra2 = gcnew Bitmap("cierra_p.png");
		Bitmap ^ bmpcursor = gcnew Bitmap("cursor.png");
		Bitmap ^ bmpindicador = gcnew Bitmap("medidor.png");
		Bitmap ^ bmpfin = gcnew Bitmap("Fin_juego.png");
		Bitmap ^ bmppierdevid = gcnew Bitmap("pierdevida.png");
		GameManager* game = new GameManager();
		Bitmap ^ bmpActual;
		int tiempo = 0;


	private: System::Windows::Forms::Timer^  timer2;
			


		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(669, 548);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::test);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::soltar_tecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		if (game->getMenuact()) {
			game->dibujar_menu(buffer, bmpMenu, bmplvl1, bmplvl2, bmplvl3, bmplvl4, bmplvl5);
			if (game->getNivel() == 0) {
				bmpActual = bmplvl1;
			}
			else if (game->getNivel() == 1) {
				bmpActual = bmplvl2;
			}
			else if (game->getNivel() == 2) {
				bmpActual = bmplvl3;
			}
			else if (game->getNivel() == 3) {
				bmpActual = bmplvl4;
			}
			else if (game->getNivel() == 4) {
				bmpActual = bmplvl5;
			}
		}
		else if (game->getVidas() > 0) {
			if (!game->getPierdevid()) {
				game->Colisiones();
				game->controlar_cursor();
			}
			game->dibujar_mapa(buffer, bmpActual);
			game->mover_jugador(buffer, bmpJugador);
			game->movimientos_cierras(buffer, bmpcierra, bmpcierra2);
			game->dibujar_hud(buffer, bmpindicador,tiempo);
			if (game->getPierdevid() && game->getVidas() > 0) {
				game->dibujar_opcion(buffer, bmppierdevid);
				tiempo = 0;
			}
		}
		game->getMenu()->Dibujar_cursor(buffer, bmpcursor);
		if (game->getVidas() <= 0) {
			game->dibujar_mapa(buffer, bmpfin);
		}
		buffer->Render(g);

		delete buffer;
		delete espacio;
		delete g;
	}

	private: System::Void test(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		game->controlar_inputs(e);
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (!game->getMenuact() && game->getVidas() > 0) {
			if (game->getNivel() < 5 && !game->getPierdevid()) {
				tiempo++;
				if (tiempo >= game->getTiempo() && game->getNivel() < 4) {
					tiempo = 0;
					game->cambiar_nivel();
						switch (game->getNivel())
						{
						case 0: bmpActual = bmplvl1;
							break;

						case 1: bmpActual = bmplvl2;
							break;

						case 2: bmpActual = bmplvl3;
							break;

						case 3: bmpActual = bmplvl4;
							break;

						case 4: bmpActual = bmplvl5;
							break;
						default: bmpActual = bmpMenu;
							break;
					}
				}
				else if (tiempo >= game->getTiempo() && game->getNivel() == 4) {
					game->setVidas(0);
				}
			}
		}
		else {
			tiempo = 0;
		}
	}
private: System::Void soltar_tecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	game->controlar_inputs_soltar(e);
}
};
}
