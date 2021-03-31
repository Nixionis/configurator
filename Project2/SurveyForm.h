#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SurveyForm
	/// </summary>
	public ref class SurveyForm : public System::Windows::Forms::Form
	{
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
			this->radioWin10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioWin8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioWin7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioLinux = (gcnew System::Windows::Forms::RadioButton());
			this->listMemo = (gcnew System::Windows::Forms::ListBox());
			this->listDisc = (gcnew System::Windows::Forms::ListBox());
			this->listPrograms = (gcnew System::Windows::Forms::ListBox());
			this->listSysReq = (gcnew System::Windows::Forms::ListBox());
			this->labelDisc = (gcnew System::Windows::Forms::Label());
			this->labelPrograms = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			// radioWin10
			// 
			this->radioWin10->AutoSize = true;
			this->radioWin10->Location = System::Drawing::Point(15, 39);
			this->radioWin10->Name = L"radioWin10";
			this->radioWin10->Size = System::Drawing::Size(108, 22);
			this->radioWin10->TabIndex = 0;
			this->radioWin10->TabStop = true;
			this->radioWin10->Text = L"Windows 10";
			this->radioWin10->UseVisualStyleBackColor = true;
			// 
			// radioWin8
			// 
			this->radioWin8->AutoSize = true;
			this->radioWin8->Location = System::Drawing::Point(15, 72);
			this->radioWin8->Name = L"radioWin8";
			this->radioWin8->Size = System::Drawing::Size(100, 22);
			this->radioWin8->TabIndex = 1;
			this->radioWin8->TabStop = true;
			this->radioWin8->Text = L"Windows 8";
			this->radioWin8->UseVisualStyleBackColor = true;
			// 
			// radioWin7
			// 
			this->radioWin7->AutoSize = true;
			this->radioWin7->Location = System::Drawing::Point(15, 105);
			this->radioWin7->Name = L"radioWin7";
			this->radioWin7->Size = System::Drawing::Size(100, 22);
			this->radioWin7->TabIndex = 2;
			this->radioWin7->TabStop = true;
			this->radioWin7->Text = L"Windows 7";
			this->radioWin7->UseVisualStyleBackColor = true;
			// 
			// radioLinux
			// 
			this->radioLinux->AutoSize = true;
			this->radioLinux->Location = System::Drawing::Point(15, 138);
			this->radioLinux->Name = L"radioLinux";
			this->radioLinux->Size = System::Drawing::Size(60, 22);
			this->radioLinux->TabIndex = 3;
			this->radioLinux->TabStop = true;
			this->radioLinux->Text = L"Linux";
			this->radioLinux->UseVisualStyleBackColor = true;
			// 
			// listMemo
			// 
			this->listMemo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listMemo->FormattingEnabled = true;
			this->listMemo->ItemHeight = 18;
			this->listMemo->Location = System::Drawing::Point(23, 258);
			this->listMemo->Name = L"listMemo";
			this->listMemo->Size = System::Drawing::Size(621, 148);
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
			this->listDisc->Size = System::Drawing::Size(166, 184);
			this->listDisc->TabIndex = 2;
			// 
			// listPrograms
			// 
			this->listPrograms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listPrograms->FormattingEnabled = true;
			this->listPrograms->ItemHeight = 18;
			this->listPrograms->Location = System::Drawing::Point(272, 47);
			this->listPrograms->Name = L"listPrograms";
			this->listPrograms->Size = System::Drawing::Size(166, 184);
			this->listPrograms->TabIndex = 3;
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
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(668, 258);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 64);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Принять";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(668, 342);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(204, 64);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// SurveyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 421);
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
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
