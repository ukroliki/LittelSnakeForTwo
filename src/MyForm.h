#pragma once
#include "data.h"
#include <ctime>
#include <Windows.h>

namespace LittleSnakeForTwo 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using System::Drawing::Size;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		Graphics^ g = nullptr;



		const int WIDTH = 1440;
		const int HEIGHT = 25 * 26;
		Bitmap^ canvas = nullptr;

		List<Image^>^ images;

		SolidBrush^ blackSolidBrush = gcnew SolidBrush(Color::Black);
		Pen^ whitePen = nullptr;

		int x1 = 8;
		int y1 = 8;
		int x2 = 8;
		int y2 = 8;
		int imgIndex1 = 3;
		int imgIndex2 = 5;
		bool gameOn = false;
		int nodesToWin = 0;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;


	public:
		MyForm(void)
		{
			InitializeComponent();

			srand(time(0));
			//
			//TODO: Add the constructor code here
			//

			whitePen = gcnew Pen(Color::White);

			images = gcnew List<Image^>();

			images->Add(gcnew Bitmap(Image::FromFile("ruby.png", true)));
			images->Add(gcnew Bitmap(Image::FromFile("opal.png", true)));
			images->Add(gcnew Bitmap(Image::FromFile("sapphire.png", true)));
			images->Add(gcnew Bitmap(Image::FromFile("emerald.png", true)));
			images->Add(gcnew Bitmap(Image::FromFile("citrine.png", true)));
			images->Add(gcnew Bitmap(Image::FromFile("garnet.png", true)));
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
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(101, 110);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(785, 308);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(376, 340);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(242, 56);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start Game!!!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(162, 97);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(262, 31);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"A";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(560, 97);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(273, 31);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"B";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(158, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(266, 24);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Введите имя левого игрока:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(556, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(277, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Введите имя правого игрока:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(358, 200);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(260, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Длина змеи для победы:";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(439, 238);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 31);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"10";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 458);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Змейка 2016";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {


		timer1->Interval = 250;

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		snake.move();
		snake2.move();

		checkForFail();

		if (snake.dir == Direction::NORTH && x1 == snake.nodes[0].getX() && y1 == snake.nodes[0].getY() - 1 ||
			snake.dir == Direction::EAST && x1 == snake.nodes[0].getX() + 1 && y1 == snake.nodes[0].getY() ||
			snake.dir == Direction::SOUTH && x1 == snake.nodes[0].getX() && y1 == snake.nodes[0].getY() + 1 ||
			snake.dir == Direction::WEST && x1 == snake.nodes[0].getX() - 1 && y1 == snake.nodes[0].getY()) {

			snake.eat(x1, y1, imgIndex1);



			newBlock1();
		}
		if (snake2.dir == Direction::NORTH && x2 == snake2.nodes[0].getX() && y2 == snake2.nodes[0].getY() - 1 ||
			snake2.dir == Direction::EAST && x2 == snake2.nodes[0].getX() + 1 && y2 == snake2.nodes[0].getY() ||
			snake2.dir == Direction::SOUTH && x2 == snake2.nodes[0].getX() && y2 == snake2.nodes[0].getY() + 1 ||
			snake2.dir == Direction::WEST && x2 == snake2.nodes[0].getX() - 1 && y2 == snake2.nodes[0].getY()) {

			snake2.eat(x2, y2, imgIndex2);
			newBlock2();
		}
		RepaintAll();

		checkForWin();
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if (e->KeyCode == Keys::Up) {

			snake.setDirection(1);
			if (x1 == snake.nodes[0].getX() && y1 == snake.nodes[0].getY() - 1) {

				snake.eat(x1, y1, imgIndex1);
				newBlock1();
			}
		}
		if (e->KeyCode == Keys::Right) {

			snake.setDirection(2);
			if (x1 == snake.nodes[0].getX() + 1 && y1 == snake.nodes[0].getY()) {

				snake.eat(x1, y1, imgIndex1);
				newBlock1();
			}
		}
		if (e->KeyCode == Keys::Down) {

			snake.setDirection(3);
			if (x1 == snake.nodes[0].getX() && y1 == snake.nodes[0].getY() + 1) {

				snake.eat(x1, y1, imgIndex1);
				newBlock1();
			}
		}
		if (e->KeyCode == Keys::Left) {

			snake.setDirection(4);
			if (x1 == snake.nodes[0].getX() - 1 && y1 == snake.nodes[0].getY()) {

				snake.eat(x1, y1, imgIndex1);
				newBlock1();
			}
		}
		if (e->KeyCode == Keys::W) {

			snake2.setDirection(1);
			if (x2 == snake2.nodes[0].getX() && y2 == snake2.nodes[0].getY() - 1) {

				snake2.eat(x2, y2, imgIndex2);
				newBlock2();
			}
		}
		if (e->KeyCode == Keys::D) {

			snake2.setDirection(2);
			if (x2 == snake2.nodes[0].getX() + 1 && y2 == snake2.nodes[0].getY()) {

				snake2.eat(x2, y2, imgIndex2);
				newBlock2();
			}
		}
		if (e->KeyCode == Keys::S) {

			snake2.setDirection(3);
			if (x2 == snake2.nodes[0].getX() && y2 == snake2.nodes[0].getY() + 1) {

				snake2.eat(x2, y2, imgIndex2);
				newBlock2();
			}
		}
		if (e->KeyCode == Keys::A) {

			snake2.setDirection(4);
			if (x2 == snake2.nodes[0].getX() - 1 && y2 == snake2.nodes[0].getY()) {

				snake2.eat(x2, y2, imgIndex2);
				newBlock2();
			}
		}


		//snake.move();
		RepaintAll();

		checkForWin();
	}

			 void checkForFail() {

				 bool leftFail = false;
				 bool rightFail = false;

				 int hx = snake2.nodes[0].getX();
				 int hy = snake2.nodes[0].getY();
				 
				 if (hx < 0 || hx >= 20 || hy < 0 || hy >= 18) {

					 timer1->Stop();
					 leftFail = true;
					 
					 
				 }
				 hx = snake.nodes[0].getX();
				 hy = snake.nodes[0].getY();
				 if (hx < 0 || hx >= 20 || hy < 0 || hy >= 18) {

					 timer1->Stop();
					 rightFail = true;
					 
				 }

				 if (leftFail && !rightFail) {

					 MessageBox::Show("Проиграл " + textBox1->Text);
					 Application::Exit();
				 }
				 if (rightFail && !leftFail) {

					 MessageBox::Show("Проиграл " + textBox2->Text);
					 Application::Exit();
				 }
				 if (leftFail && rightFail) {

					 MessageBox::Show("Ничья!");
					 Application::Exit();
				 }

			 }

			 void checkForWin() {



				 if (snake2.nodes.size() >= nodesToWin) {

					 timer1->Stop();
					 MessageBox::Show("Победил " + textBox1->Text);
					 Application::Exit();
				 }
				 if (snake.nodes.size() >= nodesToWin) {

					 timer1->Stop();
					 MessageBox::Show("Победил " + textBox2->Text);
					 Application::Exit();
				 }
			 }

			 void RepaintAll() {


				 if (g == nullptr)return;

				 g->FillRectangle(blackSolidBrush, 0, 0, WIDTH, HEIGHT);


				 for (int i = 0; i < snake.nodes.size(); i++) {

					 int xx = snake.nodes[i].getX();
					 int yy = snake.nodes[i].getY();
					 int imgInd = snake.nodes[i].getImgIndex();

					 g->DrawImage(images[imgInd], xx * 36 + 720, yy * 36);
				 }
				 for (int i = 0; i < snake2.nodes.size(); i++) {

					 int xx = snake2.nodes[i].getX();
					 int yy = snake2.nodes[i].getY();
					 int imgInd = snake2.nodes[i].getImgIndex();

					 g->DrawImage(images[imgInd], xx * 36, yy * 36);
				 }


				 g->DrawImage(images[imgIndex1], x1 * 36 + 720, y1 * 36);
				 g->DrawImage(images[imgIndex2], x2 * 36, y2 * 36);

				 whitePen->Width = 2;
				 g->DrawLine(whitePen, 719, 0, 719, 1440);

				 String^ review = "";

				 review = String::Concat(review, textBox1->Text, "->");
				 review = String::Concat(review, (snake2.nodes.size()).ToString(), " : ");
				 review = String::Concat(review, textBox2->Text, "->");
				 review = String::Concat(review, (snake.nodes.size()).ToString());

				 this->Text = review;

				 pictureBox1->BackgroundImage = nullptr;
				 pictureBox1->BackgroundImage = canvas;
			 }
			 void newBlock1() {

				 x1 =1+rand() % 19;
				 y1 = 1+rand() % 17;
				 imgIndex1 = rand() % 6;
			 }
			 void newBlock2() {

				 x2 =1+rand() % 19;
				 y2 = 1+rand() % 17;
				 imgIndex2 = rand() % 6;
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "") {

			MessageBox::Show("Заполните все поля!");
			return;
		}

		try {
			nodesToWin = Convert::ToInt32(textBox3->Text);
			if (nodesToWin < 2 || nodesToWin > 100) {

				MessageBox::Show("Неподходящее значение. Пожалуйста, замените!");
				return;
			}
		}
		catch (FormatException^ fe) {

			MessageBox::Show("Введите число в центральное поле!");
			return;
		}



		this->SetClientSizeCore(WIDTH, HEIGHT);
		pictureBox1->Top = 0;
		pictureBox1->Left = 0;
		pictureBox1->Width = WIDTH;
		pictureBox1->Height = HEIGHT;

		canvas = gcnew Bitmap(WIDTH, HEIGHT);
		g = Graphics::FromImage(canvas);

		pictureBox1->Visible = true;
		textBox1->Visible = false;
		textBox2->Visible = false;
		textBox3->Visible = false;
		label1->Visible = false;
		label2->Visible = false;
		label3->Visible = false;
		button1->Visible = false;
		this->Location = Point(10, 10);
		this->Focus();

		gameOn = true;
		timer1->Start();
	}
	};



}






























