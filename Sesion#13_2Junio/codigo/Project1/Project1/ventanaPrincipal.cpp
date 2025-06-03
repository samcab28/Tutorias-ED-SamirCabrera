#include "ventanaPrincipal.h"

using namespace System;
using namespace System::Windows::Forms;

void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::ventanaPrincipal form;
	Application::Run(%form);
}
