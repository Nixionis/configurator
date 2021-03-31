#pragma once

#include <vector>
#include "Functions.h"
#include "Sborka.h"
#include "EditForm.h"
#include "SurveyForm.h"

int _selected = -1, _saveselected = -1;
int _maxcost = 0, _mincost = 0;

namespace Configurator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static std::vector<GraphicsCard> _cards;
	static std::vector<Motherboard> _mothers;
	static std::vector<Processor> _processors;
	static std::vector<RAM> _rams;
	static std::vector<SATA> _sats;
	static std::vector<PowerBlock> _powers;
	static std::vector<Sborka> _sborki;
	static std::vector<Sborka> _savedsborki;

	static Sborka MinSborka;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		

	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)	delete components;
		}

	private: 
	Project2::EditForm^ ef1;
	Project2::SurveyForm^ sf1;

	System::Windows::Forms::RadioButton^ radioOffice;
	System::Windows::Forms::RadioButton^ radioHome;
	System::Windows::Forms::RadioButton^ radioGame;
	System::Windows::Forms::RadioButton^ radioPro;
	System::Windows::Forms::Label^ labelFrom;
	System::Windows::Forms::Label^ labelTo;
	System::Windows::Forms::ListBox^ listBoxConfig;
	System::Windows::Forms::GroupBox^ Radioblock;
	System::Windows::Forms::ListBox^ listBoxSysParts;
	System::Windows::Forms::NumericUpDown^ numericFrom;
	System::Windows::Forms::NumericUpDown^ numericTo;
	System::Windows::Forms::Label^ labelPrice;
	System::Windows::Forms::Label^ labelConfig;
	System::Windows::Forms::Label^ labelComponents;
	System::Windows::Forms::ListBox^ Memo;
	System::Windows::Forms::Button^ buttonSetup;
	System::Windows::Forms::ListBox^ listSaved;
	System::Windows::Forms::Label^ labelSaved;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Label^ labelSborkaName;

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
			this->Memo = (gcnew System::Windows::Forms::ListBox());
			this->buttonSetup = (gcnew System::Windows::Forms::Button());
			this->listSaved = (gcnew System::Windows::Forms::ListBox());
			this->labelSaved = (gcnew System::Windows::Forms::Label());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->labelSborkaName = (gcnew System::Windows::Forms::Label());
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
			this->radioOffice->Location = System::Drawing::Point(15, 47);
			this->radioOffice->Margin = System::Windows::Forms::Padding(2);
			this->radioOffice->Name = L"radioOffice";
			this->radioOffice->Size = System::Drawing::Size(100, 24);
			this->radioOffice->TabIndex = 1;
			this->radioOffice->TabStop = true;
			this->radioOffice->Text = L"Офисный";
			this->radioOffice->UseVisualStyleBackColor = true;
			this->radioOffice->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioOffice_CheckedChanged);
			// 
			// radioHome
			// 
			this->radioHome->AutoSize = true;
			this->radioHome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioHome->Location = System::Drawing::Point(15, 19);
			this->radioHome->Margin = System::Windows::Forms::Padding(2);
			this->radioHome->Name = L"radioHome";
			this->radioHome->Size = System::Drawing::Size(108, 24);
			this->radioHome->TabIndex = 2;
			this->radioHome->TabStop = true;
			this->radioHome->Text = L"Домашний";
			this->radioHome->UseVisualStyleBackColor = true;
			this->radioHome->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioHome_CheckedChanged);
			// 
			// radioGame
			// 
			this->radioGame->AutoSize = true;
			this->radioGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioGame->Location = System::Drawing::Point(15, 75);
			this->radioGame->Margin = System::Windows::Forms::Padding(2);
			this->radioGame->Name = L"radioGame";
			this->radioGame->Size = System::Drawing::Size(90, 24);
			this->radioGame->TabIndex = 3;
			this->radioGame->TabStop = true;
			this->radioGame->Text = L"Игровой";
			this->radioGame->UseVisualStyleBackColor = true;
			this->radioGame->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioGame_CheckedChanged);
			// 
			// radioPro
			// 
			this->radioPro->AutoSize = true;
			this->radioPro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioPro->Location = System::Drawing::Point(15, 105);
			this->radioPro->Margin = System::Windows::Forms::Padding(2);
			this->radioPro->Name = L"radioPro";
			this->radioPro->Size = System::Drawing::Size(181, 24);
			this->radioPro->TabIndex = 4;
			this->radioPro->TabStop = true;
			this->radioPro->Text = L"Профессиональный";
			this->radioPro->UseVisualStyleBackColor = true;
			this->radioPro->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioPro_CheckedChanged);
			// 
			// labelFrom
			// 
			this->labelFrom->AutoSize = true;
			this->labelFrom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelFrom->Location = System::Drawing::Point(9, 183);
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
			this->labelTo->Location = System::Drawing::Point(122, 183);
			this->labelTo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelTo->Name = L"labelTo";
			this->labelTo->Size = System::Drawing::Size(30, 20);
			this->labelTo->TabIndex = 7;
			this->labelTo->Text = L"До";
			// 
			// listBoxConfig
			// 
			this->listBoxConfig->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxConfig->FormattingEnabled = true;
			this->listBoxConfig->ItemHeight = 18;
			this->listBoxConfig->Location = System::Drawing::Point(249, 45);
			this->listBoxConfig->Margin = System::Windows::Forms::Padding(2);
			this->listBoxConfig->Name = L"listBoxConfig";
			this->listBoxConfig->Size = System::Drawing::Size(164, 166);
			this->listBoxConfig->TabIndex = 10;
			this->listBoxConfig->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::listBoxConfig_MouseClick);
			this->listBoxConfig->DoubleClick += gcnew System::EventHandler(this, &MyForm::listBoxConfig_DoubleClick);
			// 
			// Radioblock
			// 
			this->Radioblock->Controls->Add(this->radioPro);
			this->Radioblock->Controls->Add(this->radioGame);
			this->Radioblock->Controls->Add(this->radioHome);
			this->Radioblock->Controls->Add(this->radioOffice);
			this->Radioblock->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Radioblock->Location = System::Drawing::Point(11, 9);
			this->Radioblock->Margin = System::Windows::Forms::Padding(2);
			this->Radioblock->Name = L"Radioblock";
			this->Radioblock->Padding = System::Windows::Forms::Padding(2);
			this->Radioblock->Size = System::Drawing::Size(203, 137);
			this->Radioblock->TabIndex = 11;
			this->Radioblock->TabStop = false;
			// 
			// listBoxSysParts
			// 
			this->listBoxSysParts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxSysParts->FormattingEnabled = true;
			this->listBoxSysParts->ItemHeight = 18;
			this->listBoxSysParts->Location = System::Drawing::Point(420, 45);
			this->listBoxSysParts->Margin = System::Windows::Forms::Padding(2);
			this->listBoxSysParts->Name = L"listBoxSysParts";
			this->listBoxSysParts->Size = System::Drawing::Size(254, 166);
			this->listBoxSysParts->TabIndex = 12;
			// 
			// numericFrom
			// 
			this->numericFrom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericFrom->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericFrom->Location = System::Drawing::Point(37, 183);
			this->numericFrom->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numericFrom->Name = L"numericFrom";
			this->numericFrom->Size = System::Drawing::Size(83, 26);
			this->numericFrom->TabIndex = 13;
			this->numericFrom->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericFrom_ValueChanged);
			this->numericFrom->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::numericFrom_KeyUp);
			// 
			// numericTo
			// 
			this->numericTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericTo->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericTo->Location = System::Drawing::Point(157, 183);
			this->numericTo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numericTo->Name = L"numericTo";
			this->numericTo->Size = System::Drawing::Size(83, 26);
			this->numericTo->TabIndex = 14;
			this->numericTo->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericTo_ValueChanged);
			this->numericTo->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::numericTo_KeyUp);
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
			this->labelConfig->Location = System::Drawing::Point(245, 16);
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
			this->labelComponents->Location = System::Drawing::Point(416, 16);
			this->labelComponents->Name = L"labelComponents";
			this->labelComponents->Size = System::Drawing::Size(104, 20);
			this->labelComponents->TabIndex = 17;
			this->labelComponents->Text = L"Компоненты";
			// 
			// Memo
			// 
			this->Memo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Memo->FormattingEnabled = true;
			this->Memo->ItemHeight = 20;
			this->Memo->Location = System::Drawing::Point(12, 252);
			this->Memo->Name = L"Memo";
			this->Memo->Size = System::Drawing::Size(832, 164);
			this->Memo->TabIndex = 18;
			// 
			// buttonSetup
			// 
			this->buttonSetup->Enabled = false;
			this->buttonSetup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSetup->Location = System::Drawing::Point(419, 216);
			this->buttonSetup->Name = L"buttonSetup";
			this->buttonSetup->Size = System::Drawing::Size(254, 32);
			this->buttonSetup->TabIndex = 20;
			this->buttonSetup->Text = L"Изменить сборку";
			this->buttonSetup->UseVisualStyleBackColor = true;
			this->buttonSetup->Click += gcnew System::EventHandler(this, &MyForm::buttonSetup_Click);
			// 
			// listSaved
			// 
			this->listSaved->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listSaved->FormattingEnabled = true;
			this->listSaved->ItemHeight = 18;
			this->listSaved->Location = System::Drawing::Point(680, 45);
			this->listSaved->Margin = System::Windows::Forms::Padding(2);
			this->listSaved->Name = L"listSaved";
			this->listSaved->Size = System::Drawing::Size(164, 202);
			this->listSaved->TabIndex = 21;
			this->listSaved->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::listSaved_MouseClick);
			this->listSaved->DoubleClick += gcnew System::EventHandler(this, &MyForm::listSaved_DoubleClick);
			// 
			// labelSaved
			// 
			this->labelSaved->AutoSize = true;
			this->labelSaved->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSaved->Location = System::Drawing::Point(676, 16);
			this->labelSaved->Name = L"labelSaved";
			this->labelSaved->Size = System::Drawing::Size(166, 20);
			this->labelSaved->TabIndex = 22;
			this->labelSaved->Text = L"Сохраненные сборки";
			// 
			// buttonSave
			// 
			this->buttonSave->Enabled = false;
			this->buttonSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSave->Location = System::Drawing::Point(249, 216);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(164, 32);
			this->buttonSave->TabIndex = 23;
			this->buttonSave->Text = L"Сохранить";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MyForm::buttonSave_Click);
			// 
			// labelSborkaName
			// 
			this->labelSborkaName->AutoSize = true;
			this->labelSborkaName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSborkaName->Location = System::Drawing::Point(526, 16);
			this->labelSborkaName->Name = L"labelSborkaName";
			this->labelSborkaName->Size = System::Drawing::Size(0, 20);
			this->labelSborkaName->TabIndex = 24;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 430);
			this->Controls->Add(this->labelSborkaName);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->labelSaved);
			this->Controls->Add(this->listSaved);
			this->Controls->Add(this->buttonSetup);
			this->Controls->Add(this->Memo);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Рекомендация конфигурации ПК";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Radioblock->ResumeLayout(false);
			this->Radioblock->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericFrom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericTo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
	System::Void radioHome_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		AddSborks(1, false);
	}
	System::Void radioOffice_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		AddSborks(2, false);
	}
	System::Void radioGame_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		AddSborks(3, false);
	}
	System::Void radioPro_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (radioPro->Checked) sf1->Show();

		//AddSborks(4);
	}

	//Свзяка событий с формой про замену
	void EditForm_Save(System::Object^ sender, System::EventArgs^ e, Sborka mysb, int type, System::String^ name)
	{

		mysb.SetName(msclr::interop::marshal_as<std::string>(name)); // Имя сборки

		//Получили сохраненную сборку
		if (type == 0) _savedsborki.push_back(mysb);
		else _savedsborki[type-1] = mysb;
		listSaved->Items->Clear();
		//Добавить в лист сохраненок
		int y = _savedsborki.size();

		for (int i = 0; i < y; i++) 
			listSaved->Items->Add(gcnew String(_savedsborki[i].GetName().c_str()));
		labelSborkaName->Text = "";

		listSaved->SetSelected(0, 0);
		listBoxConfig->SetSelected(0, 0);

		this->Enabled = true;
		listBoxSysParts->Items->Clear();

		if(type != 0) buttonSave->Enabled = false;
		buttonSetup->Enabled = false;
		Memo->Items->Clear();
	}

	void EditForm_Cancel(System::Object^ sender, System::EventArgs^ e)
	{
		//Просто закрыли форму
		this->Enabled = true;
	}

	void SurveyForm_Save(System::Object^ sender, System::EventArgs^ e, Sborka mysb, int type)
	{
		//Получили сохраненную сборку
		MinSborka = mysb;
		AddSborks(4, true);
	}

	void SurveyForm_Cancel(System::Object^ sender, System::EventArgs^ e)
	{
		//Просто закрыли форму
		this->Enabled = true;
	}

	// Загрузка формы
	System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		//Привязывание событий для формы с изменением сборки
		//Связка события с сохранением сборки
		this->ef1 = gcnew Project2::EditForm();
		ef1->myEvent1 += gcnew Project2::EditForm::EventDelegate1
		(this, &Configurator::MyForm::EditForm_Save);
		//Свзяка событий с отменой
		ef1->myEvent2 += gcnew Project2::EditForm::EventDelegate2
		(this, &Configurator::MyForm::EditForm_Cancel);

		//Связка события с сохранением сборки
		this->sf1 = gcnew Project2::SurveyForm();
		sf1->myEvent3 += gcnew Project2::SurveyForm::EventDelegate3
		(this, &Configurator::MyForm::SurveyForm_Save);
		//Свзяка событий с отменой
		sf1->myEvent4 += gcnew Project2::SurveyForm::EventDelegate4
		(this, &Configurator::MyForm::SurveyForm_Cancel);

		//Загрузка комплектующих из файлов в базу данных программы
		_cards = LoadGraphicsData();   // Видеокарты
		_mothers = LoadMothersData();  // Материнские платы
		_processors = LoadProcData();  // Процессоры
		_rams = LoadRAMData();         // Оперативная память
		_sats = LoadSATAData();        // Жесткие диски
		_powers = LoadPowerData();     // Блоки питания
		
		MinSborka.SetConfig(_cards[0], _mothers[0], _processors[0], _rams[0], _sats[0], _powers[0]);
		// Перенос данных в форму изменений сборки
		ef1->SetDatas(_cards, _mothers, _processors, _rams, _sats, _powers);
		sf1->SetDatas(_cards, _mothers, _processors, _rams, _sats, _powers);
	}

	
	void AddSborks(int configtype, bool MinBind)
	{
		// Считывание выбранного критерия и максимального и минимального бюджета
		// configtype - номер выбранного критерия (домашний и т.д)
		// Копирование минимального и максимального бюджета
		_mincost = (int)numericFrom->Value;
		_maxcost = (int)numericTo->Value;

		// Очищение текста в логах программы
		listBoxSysParts->Items->Clear();
		listBoxConfig->Items->Clear();
		Memo->Items->Clear();
		buttonSetup->Enabled = false;

		//Очищение данных о сборках
		_sborki.clear();

		// Генерация сборок по заданным критериям
		_sborki = CreateConfigs(configtype, _mincost, _maxcost, _cards, _mothers, _processors, _rams, _sats, _powers, MinBind, MinSborka);

		//Если нету ни одной сборки, то выводим сообщение об отсутсвии сборок
		if (_sborki.empty())
		{
			listBoxConfig->Items->Add("Нет доступных");
			listBoxConfig->Items->Add("сборок");
			listBoxConfig->Enabled = false;
			Memo->Items->Add("Измените ценовой диапазон.");
			return;
		}

		//Сортировка сборок по снижению цены
		int y = _sborki.size();
		
		Sborka z;
		for (int i = 1; i < y; i++)
			for (int j = i - 1; j >= 0 && _sborki[j] < _sborki[j + 1]; j--)
			{
				z = _sborki[j]; _sborki[j] = _sborki[j + 1]; _sborki[j + 1] = z;
			}
		
		//Удаление одинаковых сборок
		z = _sborki[0];
		for (int i = 1; i < _sborki.size(); i++)
			if (z == _sborki[i])
			{
				_sborki.erase(_sborki.begin() + i);
				i--;
			}
			else z = _sborki[i];

		//Вывод сборок в лист
		y = _sborki.size();
		for (int _i = 0; _i < y; _i++) {
			_sborki[_i].SetName(String::Format("Сборка {0}", _i + 1));
			listBoxConfig->Items->Add(gcnew String(_sborki[_i].GetName().c_str()));
		}
		
		listBoxConfig->Enabled = true;
	}
	
	//Выбрали сборку в левом лист боксе
	System::Void listBoxConfig_DoubleClick(System::Object^ sender, System::EventArgs^ e) 
	{
		//Очистка текста
		Memo->Items->Clear();
		listBoxSysParts->Items->Clear();
		_selected = listBoxConfig->SelectedIndex;


		if (_selected == -1) return;
		listSaved->SelectedIndex = -1;

		buttonSetup->Enabled = true;
		buttonSave->Enabled = true;
		labelSborkaName->Text = gcnew String(_sborki[_selected].GetName().c_str());

		//Вывод компонентов сборки
		System::String^ str = gcnew String(_sborki[_selected].GetCard().GetName().c_str());
		str = str + " (" + _sborki[_selected].GetCard().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_sborki[_selected].GetMother().GetName().c_str());
		str = str + " (" + _sborki[_selected].GetMother().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_sborki[_selected].GetProts().GetName().c_str());
		str = str + " (" + _sborki[_selected].GetProts().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_sborki[_selected].GetRam().GetName().c_str());
		str = str + " (" + _sborki[_selected].GetRam().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_sborki[_selected].GetSata().GetName().c_str());
		str = str + " (" + _sborki[_selected].GetSata().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_sborki[_selected].GetPower().GetName().c_str());
		str = str + " (" + _sborki[_selected].GetPower().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		//Комментарии к сборке
		int fullprice = _sborki[_selected].GetCost() + _sborki[_selected].GetRam().GetCost();
		String^ ramprice = (fullprice - _sborki[_selected].GetCost()).ToString() + "р.";
		String^ price = fullprice.ToString();

		Memo->Items->Add("Цена сборки: " + _sborki[_selected].GetCost().ToString() + " р.");

		if (_selected == 0) Memo->Items->Add("Данная сборка является самой мощной в данной ценовой категории");
		else if (_selected == _sborki.size()-1) Memo->Items->Add("Данная сборка является самой слабой в данной ценовой категории");

		String^ ozu;

		if (_sborki[_selected].GetRam().GetGB() == 4) {
			ozu = "4 Гб";
		}
		else if (_sborki[_selected].GetRam().GetGB() == 8) {
			ozu = "8 Гб";
		}
		else if (_sborki[_selected].GetRam().GetGB() == 16) {
			ozu = "16 Гб";
		}
		else if (_sborki[_selected].GetRam().GetGB() == 32) {
			ozu = "32 Гб";
		}

		if (fullprice <= _maxcost) {
			Memo->Items->Add("На оставшиеся деньги можете приобрести ещё " + ozu + " ОЗУ за " + ramprice);
			Memo->Items->Add("Итоговая цена сборки составит " + price + " р.");
		}
	}

	void StartAddSborks()
	{
		if (radioHome->Checked == true) AddSborks(1, false);
		if (radioOffice->Checked == true) AddSborks(2, false);
		if (radioGame->Checked == true) AddSborks(3, false);
		if (radioPro->Checked == true) AddSborks(4, true);
	}
	//Сменили бюджет
	System::Void numericTo_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		StartAddSborks();
	}
	System::Void numericFrom_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		StartAddSborks();
	}
	 System::Void numericTo_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		StartAddSborks();
	}
	System::Void numericFrom_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		StartAddSborks();
	}

	//Нажата кнопка замены и сохранения комплектующих в сборке
	System::Void buttonSetup_Click(System::Object^ sender, System::EventArgs^ e) {
		//Проверяем из какого лист бокса была выбрана сборка
		ef1->ClearLists();
		if (listSaved->SelectedIndex == -1)
		{
			ef1->SetSborka(_sborki[_selected], 0, listBoxConfig->SelectedIndex); //Из сгенерированных сборок
		}
		else if (listBoxConfig->SelectedIndex == -1)
		{
			ef1->SetSborka(_savedsborki[_saveselected], _saveselected+1, listSaved->SelectedIndex); //Из уже сохраненных сборок
		}
		ef1->Show();
		this->Enabled = false;
	}

	//Выбрали сохраненные сборки
	System::Void listSaved_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
		//Очищаем тексты
		Memo->Items->Clear();
		listBoxSysParts->Items->Clear();
		_saveselected = listSaved->SelectedIndex;

		buttonSetup->Enabled = true;

		if (_saveselected == -1) return;
		buttonSave->Enabled = false;
		listBoxConfig->SelectedIndex = -1;

		labelSborkaName->Text = gcnew String(_savedsborki[_saveselected].GetName().c_str());

		//Вывод комплектации
		System::String^ str = gcnew String(_savedsborki[_saveselected].GetCard().GetName().c_str());
		str = str + " (" + _savedsborki[_saveselected].GetCard().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_savedsborki[_saveselected].GetMother().GetName().c_str());
		str = str + " (" + _savedsborki[_saveselected].GetMother().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_savedsborki[_saveselected].GetProts().GetName().c_str());
		str = str + " (" + _savedsborki[_saveselected].GetProts().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_savedsborki[_saveselected].GetRam().GetName().c_str());
		str = str + " (" + _savedsborki[_saveselected].GetRam().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_savedsborki[_saveselected].GetSata().GetName().c_str());
		str = str + " (" + _savedsborki[_saveselected].GetSata().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		str = gcnew String(_savedsborki[_saveselected].GetPower().GetName().c_str());
		str = str + " (" + _savedsborki[_saveselected].GetPower().GetCost().ToString() + "р.)";
		listBoxSysParts->Items->Add(str);

		int fullprice = _savedsborki[_saveselected].GetCost() + _savedsborki[_saveselected].GetRam().GetCost();
		String^ ramprice = (fullprice - _savedsborki[_saveselected].GetCost()).ToString() + "р.";
		String^ price = fullprice.ToString();

		Memo->Items->Add("Цена сборки: " + _savedsborki[_saveselected].GetCost().ToString() + " р.");

		if (abs(_savedsborki[_saveselected].GetCard().GetPoints() - _savedsborki[_saveselected].GetProts().GetPoints()) > 30)
		{
			Memo->Items->Add("Не оптимальная сборка - нарушен баланс видеокарты и процессора.");

			if (_savedsborki[_saveselected].GetCard().GetPoints() > _savedsborki[_saveselected].GetProts().GetPoints()) Memo->Items->Add("Слишком мощная видеокарта.");
			else  Memo->Items->Add("Слишком мощный процессор.");
		}
	}

	//Сохранение сборки
	System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listBoxConfig->SelectedIndex == -1) return;

	//Получили сохраненную сборку
	_savedsborki.push_back(_sborki[listBoxConfig->SelectedIndex]);

	listSaved->Items->Clear();

	//Добавить в лист сохраненных сборок
	int y = _savedsborki.size();
	System::String^ str;
	for (int _i = 0; _i < y; _i++) {
		str = gcnew String(_savedsborki[_i].GetName().c_str());
		listSaved->Items->Add(str);
	}
}

private: System::Void listSaved_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	_saveselected = listSaved->SelectedIndex;
	buttonSetup->Enabled = true;
	if (_saveselected == -1) return;
	listBoxConfig->SelectedIndex = -1;
	buttonSave->Enabled = false;
}
private: System::Void listBoxConfig_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	_selected = listBoxConfig->SelectedIndex;
	if (_selected == -1) return;
	listSaved->SelectedIndex = -1;
	buttonSetup->Enabled = true;
	buttonSave->Enabled = true;
}
};
}
