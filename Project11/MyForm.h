#pragma once
#include "CGame.h"
namespace Project11 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	public ref class MyForm : public System::Windows::Forms::Form
	{
		Stopwatch^ cronometro;
		BufferedGraphics^ buffer;
		CGame* juegito;
		Bitmap^ prota;
		Bitmap^ mapa;
		Bitmap^ discoA;
		Bitmap^ discoB;
		Bitmap^ discoX;
		Bitmap^ hon1;
		Bitmap^ hon2;
		Bitmap^ hon3;
	private: System::Windows::Forms::TextBox^  txtMin;
	private: System::Windows::Forms::TextBox^  txtMil;
	private: System::Windows::Forms::TextBox^  txtSeg;
	private: System::Windows::Forms::Timer^  ZaWarudo;
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->prota = gcnew Bitmap("Imagenes\\protagonista.png");
			this->mapa = gcnew Bitmap("Imagenes\\escenario.jpg");
			this->discoA = gcnew Bitmap("Imagenes\\discoA.png");
			this->discoB = gcnew Bitmap("Imagenes\\discoB.png");
			this->discoX = gcnew Bitmap("Imagenes\\discoX.png");
			this->hon1 = gcnew Bitmap("Imagenes\\hon1.png");
			this->hon2 = gcnew Bitmap("Imagenes\\hon2.png");
			this->hon3 = gcnew Bitmap("Imagenes\\hon3.png");
			this->buffer = BufferedGraphicsManager::Current->Allocate(this->CreateGraphics(), this->ClientRectangle);
			this->juegito = new CGame();
			this->cronometro = gcnew Stopwatch;
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
			this->txtMin = (gcnew System::Windows::Forms::TextBox());
			this->txtMil = (gcnew System::Windows::Forms::TextBox());
			this->txtSeg = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ZaWarudo
			// 
			this->ZaWarudo->Enabled = true;
			this->ZaWarudo->Tick += gcnew System::EventHandler(this, &MyForm::StarPlatinum);
			// 
			// txtMin
			// 
			this->txtMin->Enabled = false;
			this->txtMin->Location = System::Drawing::Point(2, 12);
			this->txtMin->Name = L"txtMin";
			this->txtMin->Size = System::Drawing::Size(70, 20);
			this->txtMin->TabIndex = 0;
			// 
			// txtMil
			// 
			this->txtMil->Enabled = false;
			this->txtMil->Location = System::Drawing::Point(154, 12);
			this->txtMil->Name = L"txtMil";
			this->txtMil->Size = System::Drawing::Size(70, 20);
			this->txtMil->TabIndex = 1;
			// 
			// txtSeg
			// 
			this->txtSeg->Enabled = false;
			this->txtSeg->Location = System::Drawing::Point(78, 12);
			this->txtSeg->Name = L"txtSeg";
			this->txtSeg->Size = System::Drawing::Size(70, 20);
			this->txtSeg->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 600);
			this->Controls->Add(this->txtSeg);
			this->Controls->Add(this->txtMil);
			this->Controls->Add(this->txtMin);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::teclita);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void StarPlatinum(System::Object^  sender, System::EventArgs^  e) {
		TimeSpan^ ts = gcnew TimeSpan(0, 0, 0, 0, (int)cronometro->ElapsedMilliseconds);
		txtMin->Text = ts->Minutes.ToString()->Length < 2 ? "0" + ts->Minutes.ToString() : ts->Minutes.ToString();
		txtSeg->Text = ts->Seconds.ToString()->Length < 2 ? "0" + ts->Seconds.ToString() : ts->Seconds.ToString();
		txtMil->Text = ts->Milliseconds.ToString();
		this->cronometro->Start();
		this->buffer->Graphics->DrawImage(this->mapa, this->ClientRectangle);
		this->juegito->jugar(this->discoA, this->discoB, this->discoX, this->hon1, this->hon2, this->hon3, this->prota, this->buffer, this->Size);
		this->buffer->Render();
		if (this->juegito->getVidas() == 0 || this->juegito->getPerder()) {
			this->ZaWarudo->Enabled = false;
			MessageBox::Show("Perdiste");
		}
		if ("01" == txtMin->Text) {
			this->ZaWarudo->Enabled = false;
			MessageBox::Show("Ganaste, ella si te ama :')");
		}
	}
	private: System::Void teclita(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch(e->KeyCode){
		case Keys::Up:this->juegito->animarProta(this->ClientSize, 72); break;
		case Keys::Down:this->juegito->animarProta(this->ClientSize, 80); break;
		case Keys::Left:this->juegito->animarProta(this->ClientSize, 75); break;
		case Keys::Right:this->juegito->animarProta(this->ClientSize, 77); break;
		case Keys::Space:this->juegito->agregarDiscA(); break;
		case Keys::Enter:this->juegito->agregarDiscB(); break;
		case Keys::A:this->juegito->setBotton(1); break;
		case Keys::Escape:this->Close(); break;
		}
	}
	};
}
