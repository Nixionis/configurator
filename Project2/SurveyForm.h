#pragma once

#include <vector>
#include <msclr\marshal_cppstd.h>
//#include "MyForm.h"
#include "Sborka.h"
#include "Programm.h"




namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static std::vector<GraphicsCard> _cardons;
	static std::vector<Motherboard> _motherfs;
	static std::vector<Processor> _processorfs;
	static std::vector<RAM> _ramfs;
	static std::vector<SATA> _satfs;
	static std::vector<PowerBlock> _powerfs;
	static Sborka _sborkaf;

	static std::vector<Programm> _progs;
	static std::vector<Programm> selectedProgs;

	/// <summary>
	/// Сводка для SurveyForm
	/// </summary>
	public ref class SurveyForm : public System::Windows::Forms::Form
	{
		bool* Progs;
		int* AmountProgs;

		bool* Discs;
		int* AmountDiscs;
	private: System::Windows::Forms::Button^ button3;

		int** MinPoints;
	private: System::Windows::Forms::Label^ label2;
		   bool** SystemsWind;

		
	public:
		SurveyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SurveyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ radioLinux;
	protected:

	private: System::Windows::Forms::RadioButton^ radioWin7;

	private: System::Windows::Forms::RadioButton^ radioWin8;

	private: System::Windows::Forms::RadioButton^ radioWin10;
	private: System::Windows::Forms::ListBox^ listMemo;

	private: System::Windows::Forms::ListBox^ listDisc;
	private: System::Windows::Forms::ListBox^ listPrograms;
	private: System::Windows::Forms::ListBox^ listSysReq;

	private: System::Windows::Forms::Label^ labelDisc;
	private: System::Windows::Forms::Label^ labelPrograms;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioLinux = (gcnew System::Windows::Forms::RadioButton());
			this->radioWin7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioWin8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioWin10 = (gcnew System::Windows::Forms::RadioButton());
			this->listMemo = (gcnew System::Windows::Forms::ListBox());
			this->listDisc = (gcnew System::Windows::Forms::ListBox());
			this->listPrograms = (gcnew System::Windows::Forms::ListBox());
			this->listSysReq = (gcnew System::Windows::Forms::ListBox());
			this->labelDisc = (gcnew System::Windows::Forms::Label());
			this->labelPrograms = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioLinux);
			this->groupBox1->Controls->Add(this->radioWin7);
			this->groupBox1->Controls->Add(this->radioWin8);
			this->groupBox1->Controls->Add(this->radioWin10);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(23, 47);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(243, 173);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Операционная система";
			// 
			// radioLinux
			// 
			this->radioLinux->AutoSize = true;
			this->radioLinux->Location = System::Drawing::Point(15, 138);
			this->radioLinux->Name = L"radioLinux";
			this->radioLinux->Size = System::Drawing::Size(60, 22);
			this->radioLinux->TabIndex = 3;
			this->radioLinux->Text = L"Linux";
			this->radioLinux->UseVisualStyleBackColor = true;
			this->radioLinux->CheckedChanged += gcnew System::EventHandler(this, &SurveyForm::radioLinux_CheckedChanged);
			// 
			// radioWin7
			// 
			this->radioWin7->AutoSize = true;
			this->radioWin7->Location = System::Drawing::Point(15, 105);
			this->radioWin7->Name = L"radioWin7";
			this->radioWin7->Size = System::Drawing::Size(100, 22);
			this->radioWin7->TabIndex = 2;
			this->radioWin7->Text = L"Windows 7";
			this->radioWin7->UseVisualStyleBackColor = true;
			this->radioWin7->CheckedChanged += gcnew System::EventHandler(this, &SurveyForm::radioWin7_CheckedChanged);
			// 
			// radioWin8
			// 
			this->radioWin8->AutoSize = true;
			this->radioWin8->Location = System::Drawing::Point(15, 72);
			this->radioWin8->Name = L"radioWin8";
			this->radioWin8->Size = System::Drawing::Size(100, 22);
			this->radioWin8->TabIndex = 1;
			this->radioWin8->Text = L"Windows 8";
			this->radioWin8->UseVisualStyleBackColor = true;
			this->radioWin8->CheckedChanged += gcnew System::EventHandler(this, &SurveyForm::radioWin8_CheckedChanged);
			// 
			// radioWin10
			// 
			this->radioWin10->AutoSize = true;
			this->radioWin10->Location = System::Drawing::Point(15, 39);
			this->radioWin10->Name = L"radioWin10";
			this->radioWin10->Size = System::Drawing::Size(108, 22);
			this->radioWin10->TabIndex = 0;
			this->radioWin10->Text = L"Windows 10";
			this->radioWin10->UseVisualStyleBackColor = true;
			this->radioWin10->CheckedChanged += gcnew System::EventHandler(this, &SurveyForm::radioWin10_CheckedChanged);
			// 
			// listMemo
			// 
			this->listMemo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listMemo->FormattingEnabled = true;
			this->listMemo->ItemHeight = 18;
			this->listMemo->Location = System::Drawing::Point(23, 258);
			this->listMemo->Name = L"listMemo";
			this->listMemo->Size = System::Drawing::Size(621, 130);
			this->listMemo->TabIndex = 1;
			// 
			// listDisc
			// 
			this->listDisc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listDisc->FormattingEnabled = true;
			this->listDisc->ItemHeight = 18;
			this->listDisc->Location = System::Drawing::Point(478, 47);
			this->listDisc->Name = L"listDisc";
			this->listDisc->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listDisc->Size = System::Drawing::Size(166, 184);
			this->listDisc->TabIndex = 2;
			this->listDisc->SelectedIndexChanged += gcnew System::EventHandler(this, &SurveyForm::listDisc_SelectedIndexChanged);
			// 
			// listPrograms
			// 
			this->listPrograms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listPrograms->FormattingEnabled = true;
			this->listPrograms->ItemHeight = 18;
			this->listPrograms->Location = System::Drawing::Point(272, 47);
			this->listPrograms->Name = L"listPrograms";
			this->listPrograms->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listPrograms->Size = System::Drawing::Size(166, 184);
			this->listPrograms->TabIndex = 3;
			this->listPrograms->SelectedIndexChanged += gcnew System::EventHandler(this, &SurveyForm::listPrograms_SelectedIndexChanged);
			// 
			// listSysReq
			// 
			this->listSysReq->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listSysReq->FormattingEnabled = true;
			this->listSysReq->ItemHeight = 18;
			this->listSysReq->Location = System::Drawing::Point(667, 47);
			this->listSysReq->Name = L"listSysReq";
			this->listSysReq->Size = System::Drawing::Size(205, 184);
			this->listSysReq->TabIndex = 4;
			// 
			// labelDisc
			// 
			this->labelDisc->AutoSize = true;
			this->labelDisc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDisc->Location = System::Drawing::Point(475, 15);
			this->labelDisc->Name = L"labelDisc";
			this->labelDisc->Size = System::Drawing::Size(106, 18);
			this->labelDisc->TabIndex = 5;
			this->labelDisc->Text = L"Жесткий диск";
			// 
			// labelPrograms
			// 
			this->labelPrograms->AutoSize = true;
			this->labelPrograms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPrograms->Location = System::Drawing::Point(269, 15);
			this->labelPrograms->Name = L"labelPrograms";
			this->labelPrograms->Size = System::Drawing::Size(177, 18);
			this->labelPrograms->TabIndex = 6;
			this->labelPrograms->Text = L"Программы для работы";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(664, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 18);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Минимальные требования";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(668, 304);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 37);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Принять настройки";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SurveyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(667, 351);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(204, 37);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &SurveyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F));
			this->button3->Location = System::Drawing::Point(668, 258);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(204, 37);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Показать требования";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &SurveyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(269, 234);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(331, 18);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Зажмите Ctrl для множественного выделения";
			// 
			// SurveyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 400);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelPrograms);
			this->Controls->Add(this->labelDisc);
			this->Controls->Add(this->listSysReq);
			this->Controls->Add(this->listPrograms);
			this->Controls->Add(this->listDisc);
			this->Controls->Add(this->listMemo);
			this->Controls->Add(this->groupBox1);
			this->Name = L"SurveyForm";
			this->Text = L"SurveyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SurveyForm::SurveyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &SurveyForm::SurveyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Создание делегатов для привязывания событий между формами
	public: delegate void EventDelegate3(System::Object^ sender, System::EventArgs^ e, Sborka mysb, int type);
	public: event EventDelegate3^ myEvent3;
	public: delegate void EventDelegate4(System::Object^ sender, System::EventArgs^ e);
	public: event EventDelegate4^ myEvent4;

	public: void SetDatas(std::vector<GraphicsCard>& cards,
		std::vector<Motherboard>& mboards, std::vector<Processor>& procs,
		std::vector<RAM>& rams, std::vector<SATA>& sats, std::vector<PowerBlock>& powers)
	{
		_cardons = cards;
		_motherfs = mboards;
		_processorfs = procs;
		_ramfs = rams;
		_satfs = sats;
		_powerfs = powers;
	}

	private: System::Void SurveyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		Programm tempprg;

		Discs = new bool[3];
		AmountDiscs = new int;
		*AmountDiscs = 3;
		//winp  
		//gp
		//pp
		//rp
		//sp
		//st

		tempprg.SetData("3ds max", 45, 40, 4, 256, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("3ds maya", 45, 40, 8, 256, 1, 1, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Blender", 20, 20, 4, 256, 1, 1, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Photoshop", 20, 20, 4, 256, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Krita", 10, 20, 4, 256, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Adobe after effects", 20, 40, 8, 256, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Vegas pro", 10, 30, 4, 256, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Visual studio", 10, 30, 4, 512, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("MatLab", 10, 20, 4, 256, 1, 0, 1, 0, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("AutoCad 2022", 30, 40, 8, 256, 1, 0, 0, 0, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("SolidWorks", 20, 20, 8, 256, 1, 0, 1, 0, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Компас 3Д", 40, 40, 8, 256, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("T-FLEX", 20, 40, 8, 256, 2, 0, 1, 1, 0);
		_progs.push_back(tempprg);
		tempprg.SetData("NX", 20, 30, 8, 256, 1, 0, 1, 0, 1);
		_progs.push_back(tempprg);
		tempprg.SetData("Fl studio 12", 10, 20, 8, 256, 1, 0, 1, 1, 1);
		_progs.push_back(tempprg);

		listDisc->Items->Add("Быстрая работа");
		listDisc->Items->Add("Высокая ёмкость");
		listDisc->Items->Add("Возможность бэкапов");
	}

	void FindPrograms(int SysType)
	{
		listPrograms->Items->Clear();

		for (int i = 0; i < _progs.size(); i++)
			if (SysType == 0 && _progs[i].GetLinux()) listPrograms->Items->Add(gcnew String(_progs[i].GetName().c_str()));
			else if (SysType == 1 && _progs[i].GetWin7()) listPrograms->Items->Add(gcnew String(_progs[i].GetName().c_str()));
			else if (SysType == 2 && _progs[i].GetWin8()) listPrograms->Items->Add(gcnew String(_progs[i].GetName().c_str()));
			else if (SysType == 3 && _progs[i].GetWin10()) listPrograms->Items->Add(gcnew String(_progs[i].GetName().c_str()));
	}

private: System::Void radioWin10_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	FindPrograms(3);
	button1->Enabled = false;
}
private: System::Void radioWin8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	FindPrograms(2);
	button1->Enabled = false;
}
private: System::Void radioWin7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	FindPrograms(1);
	button1->Enabled = false;
}
private: System::Void radioLinux_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	FindPrograms(0);
	button1->Enabled = false;
}

void FindProg(System::String^ name, std::vector<Programm> &progs)
{
	msclr::interop::marshal_context context;
	std::string ProgName = context.marshal_as<std::string>(name);


	for(int j = 0; j<_progs.size();j++)
		if (ProgName == _progs[j].GetName())
		{
			progs.push_back(_progs[j]);
			return;
		}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
	listMemo->Items->Clear();

	if (listPrograms->SelectedIndices->Count == 0)
	{
		listMemo->Items->Add("Вы не выбрали необходимые программы!");
		return;
	}

	GraphicsCard card;
	Processor proces;
	Motherboard mother;
	RAM ram;
	SATA sata;
	PowerBlock power;

	int y = listDisc->SelectedIndices->Count;
	int spb = 256;
	int stb = 1;

	if (listDisc->SelectedIndices->Count == 3)
	{
		listMemo->Items->Add("Жесткий диск не может совпадать трём критериям сразу!");
		return;
	}
	else
		for (int i = 0; i < y; i++)
			if (listDisc->Items[listDisc->SelectedIndices[i]]->ToString() == "Быстрая работа")
				stb = 2;
			else if (listDisc->Items[listDisc->SelectedIndices[i]]->ToString() == "Высокая ёмкость")
				spb = 1024;
			else if (listDisc->Items[listDisc->SelectedIndices[i]]->ToString() == "Возможность бэкапов")
				stb = 1;
	
	
	y = listPrograms->SelectedIndices->Count;

	for (int i = 0; i < y; i++) FindProg(listPrograms->Items[listPrograms->SelectedIndices[i]]->ToString(), selectedProgs);

	card = _cardons[0];
	proces = _processorfs[0];
	ram = _ramfs[0];
	sata = _satfs[0];

	y = selectedProgs.size();
	
	for (int i = 0; i < y; i++)
	{
		int b, e, c;
		if (card.GetPoints() < selectedProgs[i].GetGP())
		{
			b = 0;
			e = _cardons.size();

			while (b < e)
			{
				c = (b + e) / 2;

				if (_cardons[c].GetPoints() < selectedProgs[i].GetGP()) b = c + 1;
				else e = c;
			}

			card = _cardons[b];
		}
		if (proces.GetPoints() < selectedProgs[i].GetPP())
		{
			b = 0;
			e = _processorfs.size();

			while (b < e)
			{
				c = (b + e) / 2;

				if (_processorfs[c].GetPoints() < selectedProgs[i].GetPP()) b = c + 1;
				else e = c;
			}

			proces = _processorfs[b];
		}
		if (ram.GetGB() < selectedProgs[i].GetRP())
		{
			b = 0;
			e = _ramfs.size();

			while (b < e)
			{
				c = (b + e) / 2;

				if (_ramfs[c].GetGB() < selectedProgs[i].GetRP()) b = c + 1;
				else e = c;
			}
			if (b > (_ramfs.size() - 1)) b = _ramfs.size() - 1;
			ram = _ramfs[b];
		}

		(spb < selectedProgs[i].GetSP()) ? spb = selectedProgs[i].GetSP() : spb = spb;
		(stb < selectedProgs[i].GetST()) ? stb = selectedProgs[i].GetST() : stb = stb;

		if (sata.GetGB() < spb || sata.GetType() < stb)
		{
			b = 0;
			e = _satfs.size();
			for (int j = 0; j < e; j++)
				if (_satfs[j].GetGB() == spb && _satfs[j].GetType() == stb)
				{
					b = j;
					break;
				}

			sata = _satfs[b];
		}
		int tdp = card.GetTdp() + proces.GetTdp() + 175;
		b = 0;
		e = _powerfs.size();

		while (b < e)
		{
			c = (b + e) / 2;

			if (_powerfs[c].GetWatt() < tdp) b = c + 1;
			else e = c;
		}

		power = _powerfs[b];
	}
	
	int k = 0;
	for (; _motherfs[k].GetSocket() != proces.GetSocket(); k++);
	mother = _motherfs[k];

	_sborkaf.SetConfig(card, mother, proces, ram, sata, power);

	listSysReq->Items->Clear();

	System::String^ str = gcnew String(_sborkaf.GetCard().GetName().c_str());
	str = str + " (" + _sborkaf.GetCard().GetCost().ToString() + "р.)";
	listSysReq->Items->Add(str);

	str = gcnew String(_sborkaf.GetMother().GetName().c_str());
	str = str + " (" + _sborkaf.GetMother().GetCost().ToString() + "р.)";
	listSysReq->Items->Add(str);

	str = gcnew String(_sborkaf.GetProts().GetName().c_str());
	str = str + " (" + _sborkaf.GetProts().GetCost().ToString() + "р.)";
	listSysReq->Items->Add(str);

	str = gcnew String(_sborkaf.GetRam().GetName().c_str());
	str = str + " (" + _sborkaf.GetRam().GetCost().ToString() + "р.)";
	listSysReq->Items->Add(str);

	str = gcnew String(_sborkaf.GetSata().GetName().c_str());
	str = str + " (" + _sborkaf.GetSata().GetCost().ToString() + "р.)";
	listSysReq->Items->Add(str);

	str = gcnew String(_sborkaf.GetPower().GetName().c_str());
	str = str + " (" + _sborkaf.GetPower().GetCost().ToString() + "р.)";
	listSysReq->Items->Add(str);

	button1->Enabled = true;
}
private: System::Void SurveyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	e->Cancel = true;
	myEvent4(this, e);
	this->Hide();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	myEvent3(this, e, _sborkaf, 3);
	this->Hide();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	myEvent4(this, e);
	this->Hide();
}
private: System::Void listPrograms_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	button1->Enabled = false;
}
private: System::Void listDisc_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	button1->Enabled = false;
}
};
}
