#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LittleSnakeForTwo::MyForm form;

	Application::Run(%form);
}

#include "MyForm.h"

