#pragma once
#include "CGame.h"
namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		CGame* juegito;
		Bitmap^ prota;
		Bitmap^ mapa;
		Bitmap^ discoA;
	private: System::Windows::Forms::Timer^  ZaWarudo;
			 BufferedGraphics^ buffer;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->prota = gcnew Bitmap("Imagenes\\protagonista.png");
			this->mapa = gcnew Bitmap("Imagenes\\escenario.jpg");
			this->discoA = gcnew Bitmap("Imagenes\\discoA.png");
			this->buffer = BufferedGraphicsManager::Current->Allocate(this->CreateGraphics(), this->ClientRectangle);
			this->juegito = new CGame();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete this->prota;
			delete this->mapa;
			delete this->buffer;
			delete this->juegito;
		}

	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ZaWarudo = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// ZaWarudo
			// 
			this->ZaWarudo->Enabled = true;
			this->ZaWarudo->Tick += gcnew System::EventHandler(this, &MyForm::StarPlatinum);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 468);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::teclita);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void StarPlatinum(System::Object^  sender, System::EventArgs^  e) {
		this->buffer->Graphics->DrawImage(this->mapa, this->ClientRectangle);
		this->juegito->dibujarProta(this->prota, this->buffer);
		this->juegito->animarDiscoA(this->discoA, this->buffer, this->ClientSize);
		this->buffer->Render();
	}
	private: System::Void teclita(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch(e->KeyCode){
		case Keys::Up:this->juegito->animarProta(this->ClientSize, 72); break;
		case Keys::Down:this->juegito->animarProta(this->ClientSize, 80); break;
		case Keys::Left:this->juegito->animarProta(this->ClientSize, 75); break;
		case Keys::Right:this->juegito->animarProta(this->ClientSize, 77); break;
		}
	}
	};
}
