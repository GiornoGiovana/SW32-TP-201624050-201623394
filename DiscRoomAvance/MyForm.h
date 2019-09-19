#pragma once
#include "CJuego.h"


namespace Project12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		BufferedGraphics^ buffer;
		CJuego^ jugar;
	private: System::Windows::Forms::Timer^  timer1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->buffer = BufferedGraphicsManager::Current->Allocate(this->CreateGraphics(), this->ClientRectangle);
			this->jugar = gcnew CJuego(this->ClientRectangle, this->ClientSize);
		}

	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete this->jugar;
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::animarJuego);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(760, 477);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::mover);
			this->ResumeLayout(false);

		}

	private: System::Void animarJuego(System::Object^  sender, System::EventArgs^  e) {
		this->jugar->play(this->buffer);
		this->buffer->Render();
	}
	private: System::Void mover(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::Up   : this->jugar->moverJugador(3, this->ClientSize); break;
		case Keys::Left : this->jugar->moverJugador(1, this->ClientSize); break;
		case Keys::Down : this->jugar->moverJugador(0, this->ClientSize); break;
		case Keys::Right: this->jugar->moverJugador(2, this->ClientSize); break;
		case Keys::Space: this->jugar->agregardiscoA(); break;
		case Keys::Enter: this->jugar->eliminarDiscoA(); break;
		case Keys::Escape: this->Close(); break;
		}
	}
	};
}
