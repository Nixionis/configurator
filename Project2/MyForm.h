#pragma once

#include "Functions.h"
#include "GraphicsCard.h"

GraphicsCard* _cards;

namespace Configurator {

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
	private: System::Windows::Forms::RadioButton^ radioOffice;
	private: System::Windows::Forms::RadioButton^ radioHome;
	private: System::Windows::Forms::RadioButton^ radioGame;
	private: System::Windows::Forms::RadioButton^ radioPro;
	private: System::Windows::Forms::Label^ labelFrom;
	private: System::Windows::Forms::Label^ labelTo;
	private: System::Windows::Forms::ListBox^ listBoxConfig;

	protected:

	protected:








	private: System::Windows::Forms::GroupBox^ Radioblock;
	private: System::Windows::Forms::ListBox^ listBoxSysParts;




	private: System::Windows::Forms::NumericUpDown^ numericFrom;
	private: System::Windows::Forms::NumericUpDown^ numericTo;
	private: System::Windows::Forms::Label^ labelPrice;
	private: System::Windows::Forms::Label^ labelConfig;
	private: System::Windows::Forms::Label^ labelComponents;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->radioOffice = (gcnew System::Windows::Forms::RadioButton());
			this->radioHome = (gcnew System::Windows::Forms::RadioButton());
			this->radioGame = (gcnew System::Windows::Forms::RadioButton());
			this->radioPro = (gcnew System::Windows::Forms::RadioButton());
			this->labelFrom = (gcnew System::Windows::Forms::Label());
			this->labelTo = (gcnew System::Windows::Forms::Label());
			this->listBoxConfig = (gcnew System::Windows::Forms::ListBox());
			this->Radioblock = (gcnew System::Windows::Forms::GroupBox());
			this->listBoxSysParts = (gcnew System::Windows::Forms::ListBox());
			this->numericFrom = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericTo = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelPrice = (gcnew System::Windows::Forms::Label());
			this->labelConfig = (gcnew System::Windows::Forms::Label());
			this->labelComponents = (gcnew System::Windows::Forms::Label());
			this->Radioblock->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericFrom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericTo))->BeginInit();
			this->SuspendLayout();
			// 
			// radioOffice
			// 
			this->radioOffice->AutoSize = true;
			this->radioOffice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioOffice->Location = System::Drawing::Point(22, 15);
			this->radioOffice->Margin = System::Windows::Forms::Padding(2);
			this->radioOffice->Name = L"radioOffice";
			this->radioOffice->Size = System::Drawing::Size(100, 24);
			this->radioOffice->TabIndex = 1;
			this->radioOffice->TabStop = true;
			this->radioOffice->Text = L"Офисный";
			this->radioOffice->UseVisualStyleBackColor = true;
			this->radioOffice->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioHome
			// 
			this->radioHome->AutoSize = true;
			this->radioHome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioHome->Location = System::Drawing::Point(22, 45);
			this->radioHome->Margin = System::Windows::Forms::Padding(2);
			this->radioHome->Name = L"radioHome";
			this->radioHome->Size = System::Drawing::Size(108, 24);
			this->radioHome->TabIndex = 2;
			this->radioHome->TabStop = true;
			this->radioHome->Text = L"Домашний";
			this->radioHome->UseVisualStyleBackColor = true;
			// 
			// radioGame
			// 
			this->radioGame->AutoSize = true;
			this->radioGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioGame->Location = System::Drawing::Point(22, 75);
			this->radioGame->Margin = System::Windows::Forms::Padding(2);
			this->radioGame->Name = L"radioGame";
			this->radioGame->Size = System::Drawing::Size(90, 24);
			this->radioGame->TabIndex = 3;
			this->radioGame->TabStop = true;
			this->radioGame->Text = L"Игровой";
			this->radioGame->UseVisualStyleBackColor = true;
			// 
			// radioPro
			// 
			this->radioPro->AutoSize = true;
			this->radioPro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioPro->Location = System::Drawing::Point(22, 105);
			this->radioPro->Margin = System::Windows::Forms::Padding(2);
			this->radioPro->Name = L"radioPro";
			this->radioPro->Size = System::Drawing::Size(172, 24);
			this->radioPro->TabIndex = 4;
			this->radioPro->TabStop = true;
			this->radioPro->Text = L"Профессинальный";
			this->radioPro->UseVisualStyleBackColor = true;
			// 
			// labelFrom
			// 
			this->labelFrom->AutoSize = true;
			this->labelFrom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelFrom->Location = System::Drawing::Point(11, 179);
			this->labelFrom->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelFrom->Name = L"labelFrom";
			this->labelFrom->Size = System::Drawing::Size(30, 20);
			this->labelFrom->TabIndex = 6;
			this->labelFrom->Text = L"От";
			// 
			// labelTo
			// 
			this->labelTo->AutoSize = true;
			this->labelTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTo->Location = System::Drawing::Point(119, 179);
			this->labelTo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelTo->Name = L"labelTo";
			this->labelTo->Size = System::Drawing::Size(30, 20);
			this->labelTo->TabIndex = 7;
			this->labelTo->Text = L"До";
			// 
			// listBoxConfig
			// 
			this->listBoxConfig->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxConfig->FormattingEnabled = true;
			this->listBoxConfig->ItemHeight = 20;
			this->listBoxConfig->Location = System::Drawing::Point(231, 45);
			this->listBoxConfig->Margin = System::Windows::Forms::Padding(2);
			this->listBoxConfig->Name = L"listBoxConfig";
			this->listBoxConfig->Size = System::Drawing::Size(125, 144);
			this->listBoxConfig->TabIndex = 10;
			// 
			// Radioblock
			// 
			this->Radioblock->Controls->Add(this->radioPro);
			this->Radioblock->Controls->Add(this->radioGame);
			this->Radioblock->Controls->Add(this->radioHome);
			this->Radioblock->Controls->Add(this->radioOffice);
			this->Radioblock->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Radioblock->Location = System::Drawing::Point(15, 9);
			this->Radioblock->Margin = System::Windows::Forms::Padding(2);
			this->Radioblock->Name = L"Radioblock";
			this->Radioblock->Padding = System::Windows::Forms::Padding(2);
			this->Radioblock->Size = System::Drawing::Size(191, 137);
			this->Radioblock->TabIndex = 11;
			this->Radioblock->TabStop = false;
			// 
			// listBoxSysParts
			// 
			this->listBoxSysParts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxSysParts->FormattingEnabled = true;
			this->listBoxSysParts->ItemHeight = 20;
			this->listBoxSysParts->Location = System::Drawing::Point(386, 45);
			this->listBoxSysParts->Margin = System::Windows::Forms::Padding(2);
			this->listBoxSysParts->Name = L"listBoxSysParts";
			this->listBoxSysParts->Size = System::Drawing::Size(125, 144);
			this->listBoxSysParts->TabIndex = 12;
			// 
			// numericFrom
			// 
			this->numericFrom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericFrom->Location = System::Drawing::Point(37, 177);
			this->numericFrom->Name = L"numericFrom";
			this->numericFrom->Size = System::Drawing::Size(70, 26);
			this->numericFrom->TabIndex = 13;
			// 
			// numericTo
			// 
			this->numericTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericTo->Location = System::Drawing::Point(146, 177);
			this->numericTo->Name = L"numericTo";
			this->numericTo->Size = System::Drawing::Size(68, 26);
			this->numericTo->TabIndex = 14;
			// 
			// labelPrice
			// 
			this->labelPrice->AutoSize = true;
			this->labelPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPrice->Location = System::Drawing::Point(48, 149);
			this->labelPrice->Name = L"labelPrice";
			this->labelPrice->Size = System::Drawing::Size(152, 20);
			this->labelPrice->TabIndex = 15;
			this->labelPrice->Text = L"Ценовой диапазон";
			// 
			// labelConfig
			// 
			this->labelConfig->AutoSize = true;
			this->labelConfig->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelConfig->Location = System::Drawing::Point(227, 9);
			this->labelConfig->Name = L"labelConfig";
			this->labelConfig->Size = System::Drawing::Size(64, 20);
			this->labelConfig->TabIndex = 16;
			this->labelConfig->Text = L"Сборки";
			// 
			// labelComponents
			// 
			this->labelComponents->AutoSize = true;
			this->labelComponents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelComponents->Location = System::Drawing::Point(382, 9);
			this->labelComponents->Name = L"labelComponents";
			this->labelComponents->Size = System::Drawing::Size(104, 20);
			this->labelComponents->TabIndex = 17;
			this->labelComponents->Text = L"Компоненты";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(541, 287);
			this->Controls->Add(this->labelComponents);
			this->Controls->Add(this->labelConfig);
			this->Controls->Add(this->labelPrice);
			this->Controls->Add(this->numericTo);
			this->Controls->Add(this->numericFrom);
			this->Controls->Add(this->listBoxSysParts);
			this->Controls->Add(this->Radioblock);
			this->Controls->Add(this->listBoxConfig);
			this->Controls->Add(this->labelTo);
			this->Controls->Add(this->labelFrom);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Radioblock->ResumeLayout(false);
			this->Radioblock->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericFrom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericTo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		LoadFileData(_cards);
	}
};
}
