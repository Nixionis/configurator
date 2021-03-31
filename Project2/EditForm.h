#pragma once

#include <vector>
//#include "MyForm.h"
#include "Sborka.h"

//Configurator::MyForm^ _MainForm;

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static std::vector<GraphicsCard> _cardss;
	static std::vector<Motherboard> _motherss;
	static std::vector<Processor> _processorss;
	static std::vector<RAM> _ramss;
	static std::vector<SATA> _satss;
	static std::vector<PowerBlock> _powerss;
	static Sborka _sborka;

	/// <summary>
	/// Сводка для EditForm
	/// </summary>
	public ref class EditForm : public System::Windows::Forms::Form
	{			

		int comsel = -1;
	private: System::Windows::Forms::TextBox^ textName;

	private: System::Windows::Forms::Label^ labelName;
		   int k = 0;
	public:

		EditForm(Void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listComponents;
	protected:
	private: System::Windows::Forms::ListBox^ listAvailable;
	private: System::Windows::Forms::Label^ labelComponents;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonClose;
	private: System::Windows::Forms::ListBox^ listNote;
	private: System::Windows::Forms::Button^ button1;
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
			this->listComponents = (gcnew System::Windows::Forms::ListBox());
			this->listAvailable = (gcnew System::Windows::Forms::ListBox());
			this->labelComponents = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonClose = (gcnew System::Windows::Forms::Button());
			this->listNote = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listComponents
			// 
			this->listComponents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listComponents->FormattingEnabled = true;
			this->listComponents->ItemHeight = 20;
			this->listComponents->Location = System::Drawing::Point(43, 87);
			this->listComponents->Name = L"listComponents";
			this->listComponents->Size = System::Drawing::Size(256, 224);
			this->listComponents->TabIndex = 0;
			this->listComponents->DoubleClick += gcnew System::EventHandler(this, &EditForm::listComponents_DoubleClick);
			// 
			// listAvailable
			// 
			this->listAvailable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listAvailable->FormattingEnabled = true;
			this->listAvailable->ItemHeight = 20;
			this->listAvailable->Location = System::Drawing::Point(320, 87);
			this->listAvailable->Name = L"listAvailable";
			this->listAvailable->Size = System::Drawing::Size(256, 224);
			this->listAvailable->TabIndex = 1;
			this->listAvailable->DoubleClick += gcnew System::EventHandler(this, &EditForm::listAvailable_DoubleClick);
			// 
			// labelComponents
			// 
			this->labelComponents->AutoSize = true;
			this->labelComponents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelComponents->Location = System::Drawing::Point(91, 64);
			this->labelComponents->Name = L"labelComponents";
			this->labelComponents->Size = System::Drawing::Size(160, 20);
			this->labelComponents->TabIndex = 2;
			this->labelComponents->Text = L"Компоненты сборки";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(350, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Доступные компоненты";
			// 
			// buttonClose
			// 
			this->buttonClose->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClose->Location = System::Drawing::Point(455, 408);
			this->buttonClose->Name = L"buttonClose";
			this->buttonClose->Size = System::Drawing::Size(121, 34);
			this->buttonClose->TabIndex = 4;
			this->buttonClose->Text = L"Сохранить";
			this->buttonClose->UseVisualStyleBackColor = true;
			this->buttonClose->Click += gcnew System::EventHandler(this, &EditForm::buttonClose_Click);
			// 
			// listNote
			// 
			this->listNote->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listNote->FormattingEnabled = true;
			this->listNote->ItemHeight = 20;
			this->listNote->Location = System::Drawing::Point(43, 317);
			this->listNote->Name = L"listNote";
			this->listNote->Size = System::Drawing::Size(533, 84);
			this->listNote->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(43, 408);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 34);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Отмена";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EditForm::button1_Click);
			// 
			// textName
			// 
			this->textName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textName->Location = System::Drawing::Point(220, 35);
			this->textName->MaxLength = 15;
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(165, 26);
			this->textName->TabIndex = 7;
			this->textName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditForm::textName_KeyPress);
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelName->Location = System::Drawing::Point(255, 9);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(96, 20);
			this->labelName->TabIndex = 8;
			this->labelName->Text = L"Имя сборки";
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 454);
			this->Controls->Add(this->labelName);
			this->Controls->Add(this->textName);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listNote);
			this->Controls->Add(this->buttonClose);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelComponents);
			this->Controls->Add(this->listAvailable);
			this->Controls->Add(this->listComponents);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"EditForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Изменение конфигурации";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &EditForm::EditForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Создание делегатов для привязывания событий между формами
public: delegate void EventDelegate1(System::Object^ sender, System::EventArgs^ e, Sborka mysb, int type, System::String^ name);
public: event EventDelegate1^ myEvent1;
public: delegate void EventDelegate2(System::Object^ sender, System::EventArgs^ e);
public: event EventDelegate2^ myEvent2;

//Нажата кнопка отмены
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//Разблокируем главную форму и прячем форму с заменой комплектующих
	myEvent2(this, e);
	this->Hide();	
}

//Нажата кнопка сохранения сборки
private: System::Void buttonClose_Click(System::Object^ sender, System::EventArgs^ e) {
	//Разблокируем главную форму и прячем форму с заменой комплектующих
	myEvent1(this, e, _sborka, k, textName->Text);
	this->Hide();
}

//Копирование данных о компонентах для работы с заменой комплектующих
public: void SetDatas(std::vector<GraphicsCard> &cards,
	std::vector<Motherboard> &mboards, std::vector<Processor> &procs,
	std::vector<RAM> &rams, std::vector<SATA> &sats, std::vector<PowerBlock> &powers)
{
	_cardss = cards;
	_motherss = mboards;
	_processorss = procs;
	_ramss = rams;
	_satss = sats;
	_powerss = powers;
}

//Меняем сборку с новым компонентом
public: void SetSborka(Sborka sbor, int type, int selind)
{
	_sborka = sbor;
	k = type;

	//Выводим все компоненты сборки в лист бокс
	textName->Text = (gcnew String(sbor.GetName().c_str()));

	listComponents->Items->Clear();

	System::String^ str = gcnew String(_sborka.GetCard().GetName().c_str());
	str = str + " (" + _sborka.GetCard().GetCost().ToString() + "р.)";
	listComponents->Items->Add(str);

	str = gcnew String(_sborka.GetMother().GetName().c_str());
	str = str + " (" + _sborka.GetMother().GetCost().ToString() + "р.)";
	listComponents->Items->Add(str);

	str = gcnew String(_sborka.GetProts().GetName().c_str());
	str = str + " (" + _sborka.GetProts().GetCost().ToString() + "р.)";
	listComponents->Items->Add(str);

	str = gcnew String(_sborka.GetRam().GetName().c_str());
	str = str + " (" + _sborka.GetRam().GetCost().ToString() + "р.)";
	listComponents->Items->Add(str);

	str = gcnew String(_sborka.GetSata().GetName().c_str());
	str = str + " (" + _sborka.GetSata().GetCost().ToString() + "р.)";
	listComponents->Items->Add(str);

	str = gcnew String(_sborka.GetPower().GetName().c_str());
	str = str + " (" + _sborka.GetPower().GetCost().ToString() + "р.)";
	listComponents->Items->Add(str);
}

void ClearLists()
{
	listComponents->Items->Clear();
	listAvailable->Items->Clear();
}

//Начата выборка компонента
private: System::Void listComponents_DoubleClick(System::Object^ sender, System::EventArgs^ e) 
{
	//Подготавливаем логи для вывода информации о замене
	System::String^ str;
	listAvailable->Items->Clear();
	int _selected = listComponents->SelectedIndex;
	if (_selected == -1) return;

	else if (_selected == 0) //Если выбрали видеокарту
	{
		int y = _cardss.size();
		for (int i = 0; i < y; i++)
		{
			str = gcnew String((_cardss)[i].GetName().c_str());
			str = str + " (" + (_cardss)[i].GetCost().ToString() + "р.)";
			listAvailable->Items->Add(str);
		}
	}
	else if (_selected == 1) //Если выбрали материнскую плату
	{
		int y = _motherss.size();
		for (int i = 0; i < y; i++)
		{
			str = gcnew String(_motherss[i].GetName().c_str());
			str = str + " (" + _motherss[i].GetCost().ToString() + "р.)";
			listAvailable->Items->Add(str);
		}
	}
	else if (_selected == 2) //Если выбрали процессор
	{
		int y = _processorss.size();
		for (int i = 0; i < y; i++)
		{
			str = gcnew String(_processorss[i].GetName().c_str());
			str = str + " (" + _processorss[i].GetCost().ToString() + "р.)";
			listAvailable->Items->Add(str);
		}
	}
	else if (_selected == 3) //Если выбрали оперативную память
	{
		int y = _ramss.size();
		for (int i = 0; i < y; i++)
		{
			str = gcnew String(_ramss[i].GetName().c_str());
			str = str + " (" + _ramss[i].GetCost().ToString() + "р.)";
			listAvailable->Items->Add(str);
		}
	}
	else if (_selected == 4) //Если выбрали жесткий диск
	{
		int y = _satss.size();
		for (int i = 0; i < y; i++)
		{
			str = gcnew String(_satss[i].GetName().c_str());
			str = str + " (" + _satss[i].GetCost().ToString() + "р.)";
			listAvailable->Items->Add(str);
		}
	}
	else if (_selected == 5) //Если выбрали блок питания
	{
		int y = _powerss.size();
		for (int i = 0; i < y; i++)
		{
			str = gcnew String(_powerss[i].GetName().c_str());
			str = str + " (" + _powerss[i].GetCost().ToString() + "р.)";
			listAvailable->Items->Add(str);
		}
	}
	comsel = _selected;
}

//Начата замена компонента
private: System::Void listAvailable_DoubleClick(System::Object^ sender, System::EventArgs^ e) {

	listNote->Items->Clear();
	System::String^ str;

	int componentselect = listAvailable->SelectedIndex;

	if (componentselect == -1) return;
	
	//Заменили выбранный компонент в сборке
	if (comsel == 0) _sborka.SetConfig(_cardss[componentselect], _sborka.GetMother(), _sborka.GetProts(), _sborka.GetRam(), _sborka.GetSata(), _sborka.GetPower());
	else if (comsel == 1) _sborka.SetConfig(_sborka.GetCard(), _motherss[componentselect], _sborka.GetProts(), _sborka.GetRam(), _sborka.GetSata(), _sborka.GetPower());
	else if (comsel == 2) _sborka.SetConfig(_sborka.GetCard(), _sborka.GetMother(), _processorss[componentselect], _sborka.GetRam(), _sborka.GetSata(), _sborka.GetPower());
	else if (comsel == 3) _sborka.SetConfig(_sborka.GetCard(), _sborka.GetMother(), _sborka.GetProts(), _ramss[componentselect], _sborka.GetSata(), _sborka.GetPower());
	else if (comsel == 4) _sborka.SetConfig(_sborka.GetCard(), _sborka.GetMother(), _sborka.GetProts(), _sborka.GetRam(), _satss[componentselect], _sborka.GetPower());
	else if (comsel == 5) _sborka.SetConfig(_sborka.GetCard(), _sborka.GetMother(), _sborka.GetProts(), _sborka.GetRam(), _sborka.GetSata(), _powerss[componentselect]);
			
	SetSborka(_sborka, k,0);
	
	buttonClose->Enabled = true;
	
	//Смотрим, совместим ли выбранный компонент в нашей сборке
	//Проверка сокета процессора и материнской платы
	if (_sborka.GetMother().GetSocket() != _sborka.GetProts().GetSocket())
	{
		listNote->Items->Add("Невозможная сборка - разница в сокетах!");

		str = gcnew String(_sborka.GetMother().GetName().c_str());
		str = str + " использует " + _sborka.GetMother().GetSocket().ToString() + " сокет.";
		listNote->Items->Add(str);

		str = gcnew String(_sborka.GetProts().GetName().c_str()) + " использует " + _sborka.GetProts().GetSocket().ToString() + " сокет.";;
		listNote->Items->Add(str);

		buttonClose->Enabled = false;
	}
	//Проверка баланса мощности процессора и видеокарты
	if (abs(_sborka.GetCard().GetPoints() - _sborka.GetProts().GetPoints()) > 30)
	{
		listNote->Items->Add("Не оптимальная сборка - нарушен баланс видеокарты и процессора.");

		if (_sborka.GetCard().GetPoints() > _sborka.GetProts().GetPoints()) listNote->Items->Add("Слишком мощная видеокарта.");
		else  listNote->Items->Add("Слишком мощный процессор.");
	}
	//Проверка энергопторебления сборки
	if ((_sborka.GetCard().GetTdp() + _sborka.GetProts().GetTdp() + 175) > _sborka.GetPower().GetWatt())
	{
		int tdp = 0;
		listNote->Items->Add("Невозможная сборка - слабый блок питания");

		str = gcnew String(_sborka.GetPower().GetName().c_str());
		str = str + " формирует напряжение в " + _sborka.GetPower().GetWatt().ToString() + " ватт.";
		listNote->Items->Add(str);

		str = gcnew String(_sborka.GetCard().GetName().c_str()) + " потребляет " + _sborka.GetCard().GetTdp().ToString() + " ватт.";;
		listNote->Items->Add(str);
		tdp += _sborka.GetCard().GetTdp();

		str = gcnew String(_sborka.GetProts().GetName().c_str()) + " потребляет " + _sborka.GetProts().GetTdp().ToString() + " ватт.";;
		listNote->Items->Add(str);
		tdp += _sborka.GetProts().GetTdp();

		listNote->Items->Add("Нужды остальной системы - 175 ватт.");
		tdp += 175;

		str = "Всего система использует " + tdp + " ватт.";
		listNote->Items->Add(str);

		buttonClose->Enabled = false;
	}
	//Стоимость сборки
	str = "Стоимость сборки составит " + _sborka.GetCost() + " руб.";
	listNote->Items->Add(str);
}

//Закртыие формы
private: System::Void EditForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	e->Cancel = true;
	myEvent2(this, e);
	this->Hide();
}

//Ввод названия сборки
private: System::Void textName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	int i;
	//setlocale(LC_ALL, "rus");

	if (!((e->KeyChar >= 65 && e->KeyChar <= 90) || (e->KeyChar >= 48 && e->KeyChar <= 57) || // цифры
		(e->KeyChar >= 97 && e->KeyChar <= 122) ||
		(e->KeyChar == 8) || (e->KeyChar == 1)) && // Russian + English
		!((e->KeyChar >= 1072 && e->KeyChar <= 1103) || (e->KeyChar == 1105) ||
			(e->KeyChar >= 1040 && e->KeyChar <= 1071) || (e->KeyChar == 1025) || (e->KeyChar == 32)
			))
		e->Handled = true;
}
};
}
