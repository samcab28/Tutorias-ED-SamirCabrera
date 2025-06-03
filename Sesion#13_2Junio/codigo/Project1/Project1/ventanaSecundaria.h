#pragma once

namespace Project1 {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class ventanaSecundaria : public Form
    {
    public:
        ventanaSecundaria()
        {
            InitializeComponent();
            PersonalizarVentana();
        }

    private:
        void InitializeComponent()
        {
            this->SuspendLayout();
            // 
            // ventanaSecundaria
            // 
            this->ClientSize = System::Drawing::Size(578, 344);
            this->Name = L"ventanaSecundaria";
            this->Text = L"Ventana Secundaria";
            this->ResumeLayout(false);

        }

        void PersonalizarVentana()
        {
            // Crear y configurar el label
            Label^ label = gcnew Label();
            label->Text = "Esta es la ventana secundaria";
            label->Font = gcnew Drawing::Font("Arial", 20, Drawing::FontStyle::Bold);
            label->AutoSize = true;
            label->Location = Drawing::Point(150, 150);
            this->Controls->Add(label);

            // Crear y configurar el botón "Volver"
            Button^ btnVolver = gcnew Button();
            btnVolver->Text = "Volver";
            btnVolver->Location = Drawing::Point(250, 250);
            btnVolver->Click += gcnew EventHandler(this, &ventanaSecundaria::btnVolver_Click);
            this->Controls->Add(btnVolver);
        }

        void btnVolver_Click(Object^ sender, EventArgs^ e)
        {
            this->Close();
        }
    };
}
