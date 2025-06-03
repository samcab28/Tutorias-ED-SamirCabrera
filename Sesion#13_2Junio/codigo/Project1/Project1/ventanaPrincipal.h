#pragma once
#include "listaSimple.h"

namespace Project1 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ventanaPrincipal : public Form
    {
    public:
        ventanaPrincipal(void)
        {
            InitializeComponent();
            miLista = new lista();
        }

    protected:
        ~ventanaPrincipal()
        {
            if (components)
            {
                delete components;
            }
            if (miLista)
            {
                delete miLista;
            }
        }

    private:
        System::Windows::Forms::GroupBox^ groupBoxOperaciones;
        System::Windows::Forms::TextBox^ textBoxValor;
        System::Windows::Forms::TextBox^ textBoxPosicion;
        System::Windows::Forms::Button^ btnInsertarInicio;
        System::Windows::Forms::Button^ btnInsertarFinal;
        System::Windows::Forms::Button^ btnInsertarPosicion;
        System::Windows::Forms::Button^ btnBorrarInicio;
        System::Windows::Forms::Button^ btnBorrarFinal;
        System::Windows::Forms::Button^ btnBorrarPosicion;
        System::Windows::Forms::Button^ btnMostrar;
        System::Windows::Forms::Button^ btnLimpiar;
        System::Windows::Forms::Label^ labelValor;
        System::Windows::Forms::Label^ labelPosicion;
        System::Windows::Forms::Label^ labelResultado;
        System::Windows::Forms::TextBox^ textBoxResultado;
        System::Windows::Forms::GroupBox^ groupBoxVisualizacion;
        System::ComponentModel::IContainer^ components;

        lista* miLista;

        void InitializeComponent(void)
        {
            this->groupBoxOperaciones = (gcnew System::Windows::Forms::GroupBox());
            this->labelValor = (gcnew System::Windows::Forms::Label());
            this->textBoxValor = (gcnew System::Windows::Forms::TextBox());
            this->labelPosicion = (gcnew System::Windows::Forms::Label());
            this->textBoxPosicion = (gcnew System::Windows::Forms::TextBox());
            this->btnInsertarInicio = (gcnew System::Windows::Forms::Button());
            this->btnInsertarFinal = (gcnew System::Windows::Forms::Button());
            this->btnInsertarPosicion = (gcnew System::Windows::Forms::Button());
            this->btnBorrarInicio = (gcnew System::Windows::Forms::Button());
            this->btnBorrarFinal = (gcnew System::Windows::Forms::Button());
            this->btnBorrarPosicion = (gcnew System::Windows::Forms::Button());
            this->btnMostrar = (gcnew System::Windows::Forms::Button());
            this->btnLimpiar = (gcnew System::Windows::Forms::Button());
            this->labelResultado = (gcnew System::Windows::Forms::Label());
            this->textBoxResultado = (gcnew System::Windows::Forms::TextBox());
            this->groupBoxVisualizacion = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxOperaciones->SuspendLayout();
            this->groupBoxVisualizacion->SuspendLayout();
            this->SuspendLayout();
            // 
            // groupBoxOperaciones
            // 
            this->groupBoxOperaciones->Controls->Add(this->labelValor);
            this->groupBoxOperaciones->Controls->Add(this->textBoxValor);
            this->groupBoxOperaciones->Controls->Add(this->labelPosicion);
            this->groupBoxOperaciones->Controls->Add(this->textBoxPosicion);
            this->groupBoxOperaciones->Controls->Add(this->btnInsertarInicio);
            this->groupBoxOperaciones->Controls->Add(this->btnInsertarFinal);
            this->groupBoxOperaciones->Controls->Add(this->btnInsertarPosicion);
            this->groupBoxOperaciones->Controls->Add(this->btnBorrarInicio);
            this->groupBoxOperaciones->Controls->Add(this->btnBorrarFinal);
            this->groupBoxOperaciones->Controls->Add(this->btnBorrarPosicion);
            this->groupBoxOperaciones->Controls->Add(this->btnMostrar);
            this->groupBoxOperaciones->Controls->Add(this->btnLimpiar);
            this->groupBoxOperaciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
            this->groupBoxOperaciones->Location = System::Drawing::Point(22, 25);
            this->groupBoxOperaciones->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxOperaciones->Name = L"groupBoxOperaciones";
            this->groupBoxOperaciones->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxOperaciones->Size = System::Drawing::Size(412, 575);
            this->groupBoxOperaciones->TabIndex = 0;
            this->groupBoxOperaciones->TabStop = false;
            this->groupBoxOperaciones->Text = L"Operaciones con Lista";
            // 
            // labelValor
            // 
            this->labelValor->AutoSize = true;
            this->labelValor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
            this->labelValor->Location = System::Drawing::Point(22, 44);
            this->labelValor->Name = L"labelValor";
            this->labelValor->Size = System::Drawing::Size(57, 22);
            this->labelValor->TabIndex = 0;
            this->labelValor->Text = L"Valor:";
            // 
            // textBoxValor
            // 
            this->textBoxValor->Location = System::Drawing::Point(90, 40);
            this->textBoxValor->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->textBoxValor->Name = L"textBoxValor";
            this->textBoxValor->Size = System::Drawing::Size(112, 30);
            this->textBoxValor->TabIndex = 1;
            // 
            // labelPosicion
            // 
            this->labelPosicion->AutoSize = true;
            this->labelPosicion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
            this->labelPosicion->Location = System::Drawing::Point(225, 44);
            this->labelPosicion->Name = L"labelPosicion";
            this->labelPosicion->Size = System::Drawing::Size(83, 22);
            this->labelPosicion->TabIndex = 2;
            this->labelPosicion->Text = L"Posición:";
            // 
            // textBoxPosicion
            // 
            this->textBoxPosicion->Location = System::Drawing::Point(309, 40);
            this->textBoxPosicion->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->textBoxPosicion->Name = L"textBoxPosicion";
            this->textBoxPosicion->Size = System::Drawing::Size(67, 30);
            this->textBoxPosicion->TabIndex = 3;
            // 
            // btnInsertarInicio
            // 
            this->btnInsertarInicio->Location = System::Drawing::Point(22, 93);
            this->btnInsertarInicio->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnInsertarInicio->Name = L"btnInsertarInicio";
            this->btnInsertarInicio->Size = System::Drawing::Size(230, 44);
            this->btnInsertarInicio->TabIndex = 4;
            this->btnInsertarInicio->Text = L"Insertar Inicio";
            this->btnInsertarInicio->UseVisualStyleBackColor = true;
            this->btnInsertarInicio->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnInsertarInicio_Click);
            // 
            // btnInsertarFinal
            // 
            this->btnInsertarFinal->Location = System::Drawing::Point(22, 145);
            this->btnInsertarFinal->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnInsertarFinal->Name = L"btnInsertarFinal";
            this->btnInsertarFinal->Size = System::Drawing::Size(230, 44);
            this->btnInsertarFinal->TabIndex = 5;
            this->btnInsertarFinal->Text = L"Insertar Final";
            this->btnInsertarFinal->UseVisualStyleBackColor = true;
            this->btnInsertarFinal->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnInsertarFinal_Click);
            // 
            // btnInsertarPosicion
            // 
            this->btnInsertarPosicion->Location = System::Drawing::Point(22, 197);
            this->btnInsertarPosicion->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnInsertarPosicion->Name = L"btnInsertarPosicion";
            this->btnInsertarPosicion->Size = System::Drawing::Size(230, 44);
            this->btnInsertarPosicion->TabIndex = 6;
            this->btnInsertarPosicion->Text = L"Insertar Posición";
            this->btnInsertarPosicion->UseVisualStyleBackColor = true;
            this->btnInsertarPosicion->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnInsertarPosicion_Click);
            // 
            // btnBorrarInicio
            // 
            this->btnBorrarInicio->Location = System::Drawing::Point(22, 364);
            this->btnBorrarInicio->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnBorrarInicio->Name = L"btnBorrarInicio";
            this->btnBorrarInicio->Size = System::Drawing::Size(230, 44);
            this->btnBorrarInicio->TabIndex = 7;
            this->btnBorrarInicio->Text = L"Borrar Inicio";
            this->btnBorrarInicio->UseVisualStyleBackColor = true;
            this->btnBorrarInicio->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnBorrarInicio_Click);
            // 
            // btnBorrarFinal
            // 
            this->btnBorrarFinal->Location = System::Drawing::Point(22, 301);
            this->btnBorrarFinal->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnBorrarFinal->Name = L"btnBorrarFinal";
            this->btnBorrarFinal->Size = System::Drawing::Size(230, 44);
            this->btnBorrarFinal->TabIndex = 8;
            this->btnBorrarFinal->Text = L"Borrar Final";
            this->btnBorrarFinal->UseVisualStyleBackColor = true;
            this->btnBorrarFinal->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnBorrarFinal_Click);
            // 
            // btnBorrarPosicion
            // 
            this->btnBorrarPosicion->Location = System::Drawing::Point(22, 249);
            this->btnBorrarPosicion->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnBorrarPosicion->Name = L"btnBorrarPosicion";
            this->btnBorrarPosicion->Size = System::Drawing::Size(230, 44);
            this->btnBorrarPosicion->TabIndex = 9;
            this->btnBorrarPosicion->Text = L"Borrar Posición";
            this->btnBorrarPosicion->UseVisualStyleBackColor = true;
            this->btnBorrarPosicion->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnBorrarPosicion_Click);
            // 
            // btnMostrar
            // 
            this->btnMostrar->Location = System::Drawing::Point(22, 494);
            this->btnMostrar->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnMostrar->Name = L"btnMostrar";
            this->btnMostrar->Size = System::Drawing::Size(230, 44);
            this->btnMostrar->TabIndex = 10;
            this->btnMostrar->Text = L"Mostrar Lista";
            this->btnMostrar->UseVisualStyleBackColor = true;
            this->btnMostrar->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnMostrar_Click);
            // 
            // btnLimpiar
            // 
            this->btnLimpiar->Location = System::Drawing::Point(22, 428);
            this->btnLimpiar->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->btnLimpiar->Name = L"btnLimpiar";
            this->btnLimpiar->Size = System::Drawing::Size(230, 44);
            this->btnLimpiar->TabIndex = 11;
            this->btnLimpiar->Text = L"Limpiar Lista";
            this->btnLimpiar->UseVisualStyleBackColor = true;
            this->btnLimpiar->Click += gcnew System::EventHandler(this, &ventanaPrincipal::btnLimpiar_Click);
            // 
            // labelResultado
            // 
            this->labelResultado->AutoSize = true;
            this->labelResultado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
            this->labelResultado->Location = System::Drawing::Point(22, 44);
            this->labelResultado->Name = L"labelResultado";
            this->labelResultado->Size = System::Drawing::Size(158, 22);
            this->labelResultado->TabIndex = 13;
            this->labelResultado->Text = L"Estado de la Lista:";
            // 
            // textBoxResultado
            // 
            this->textBoxResultado->BackColor = System::Drawing::Color::WhiteSmoke;
            this->textBoxResultado->Font = (gcnew System::Drawing::Font(L"Courier New", 10));
            this->textBoxResultado->Location = System::Drawing::Point(22, 75);
            this->textBoxResultado->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->textBoxResultado->Multiline = true;
            this->textBoxResultado->Name = L"textBoxResultado";
            this->textBoxResultado->ReadOnly = true;
            this->textBoxResultado->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
            this->textBoxResultado->Size = System::Drawing::Size(699, 389);
            this->textBoxResultado->TabIndex = 14;
            // 
            // groupBoxVisualizacion
            // 
            this->groupBoxVisualizacion->Controls->Add(this->labelResultado);
            this->groupBoxVisualizacion->Controls->Add(this->textBoxResultado);
            this->groupBoxVisualizacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
            this->groupBoxVisualizacion->Location = System::Drawing::Point(440, 13);
            this->groupBoxVisualizacion->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxVisualizacion->Name = L"groupBoxVisualizacion";
            this->groupBoxVisualizacion->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBoxVisualizacion->Size = System::Drawing::Size(735, 484);
            this->groupBoxVisualizacion->TabIndex = 12;
            this->groupBoxVisualizacion->TabStop = false;
            this->groupBoxVisualizacion->Text = L"Visualización de la Lista";
            // 
            // ventanaPrincipal
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1183, 613);
            this->Controls->Add(this->groupBoxOperaciones);
            this->Controls->Add(this->groupBoxVisualizacion);
            this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->Name = L"ventanaPrincipal";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Gestión de Lista Simple";
            this->Load += gcnew System::EventHandler(this, &ventanaPrincipal::ventanaPrincipal_Load);
            this->groupBoxOperaciones->ResumeLayout(false);
            this->groupBoxOperaciones->PerformLayout();
            this->groupBoxVisualizacion->ResumeLayout(false);
            this->groupBoxVisualizacion->PerformLayout();
            this->ResumeLayout(false);

        }

        System::Void btnInsertarInicio_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                int valor = System::Convert::ToInt32(textBoxValor->Text);
                miLista->InsertarInicio(valor);
                textBoxValor->Clear();
                ActualizarVisualizacion();
                MessageBox::Show("Valor insertado al inicio correctamente", "Éxito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (System::Exception^ ex) {
                MessageBox::Show("Por favor ingrese un número válido", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }

        System::Void btnInsertarFinal_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                int valor = System::Convert::ToInt32(textBoxValor->Text);
                miLista->InsertarFinal(valor);
                textBoxValor->Clear();
                ActualizarVisualizacion();
                MessageBox::Show("Valor insertado al final correctamente", "Éxito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (System::Exception^ ex) {
                MessageBox::Show("Por favor ingrese un número válido", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }

        System::Void btnInsertarPosicion_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                int valor = System::Convert::ToInt32(textBoxValor->Text);
                int posicion = System::Convert::ToInt32(textBoxPosicion->Text);
                miLista->InsertarPos(valor, posicion);
                textBoxValor->Clear();
                textBoxPosicion->Clear();
                ActualizarVisualizacion();
                MessageBox::Show("Valor insertado en la posición correctamente", "Éxito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (System::Exception^ ex) {
                MessageBox::Show("Por favor ingrese valores válidos", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }

        System::Void btnBorrarInicio_Click(System::Object^ sender, System::EventArgs^ e) {
            if (miLista->ListaVacia()) {
                MessageBox::Show("La lista está vacía", "Advertencia",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            miLista->BorrarInicio();
            ActualizarVisualizacion();
            MessageBox::Show("Elemento del inicio eliminado", "Éxito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void btnBorrarFinal_Click(System::Object^ sender, System::EventArgs^ e) {
            if (miLista->ListaVacia()) {
                MessageBox::Show("La lista está vacía", "Advertencia",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            miLista->BorrarFinal();
            ActualizarVisualizacion();
            MessageBox::Show("Elemento del final eliminado", "Éxito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void btnBorrarPosicion_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                if (miLista->ListaVacia()) {
                    MessageBox::Show("La lista está vacía", "Advertencia",
                        MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    return;
                }
                int posicion = System::Convert::ToInt32(textBoxPosicion->Text);
                miLista->borrarPosicion(posicion);
                textBoxPosicion->Clear();
                ActualizarVisualizacion();
                MessageBox::Show("Elemento eliminado de la posición", "Éxito",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (System::Exception^ ex) {
                MessageBox::Show("Por favor ingrese una posición válida", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }

        System::Void btnMostrar_Click(System::Object^ sender, System::EventArgs^ e) {
            ActualizarVisualizacion();
        }

        System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
            delete miLista;
            miLista = new lista();
            ActualizarVisualizacion();
            MessageBox::Show("Lista limpiada correctamente", "Éxito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void ventanaPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
            ActualizarVisualizacion();
        }

        void ActualizarVisualizacion() {
            System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();

            if (miLista->ListaVacia()) {
                sb->AppendLine("La lista está vacía");
                sb->AppendLine();
                sb->AppendLine("Representación: NULL");
            }
            else {
                sb->AppendLine("Contenido actual de la lista:");
                sb->AppendLine();
                sb->AppendLine(ObtenerRepresentacionLista());
                sb->AppendLine();
                sb->AppendLine("Longitud: " + miLista->largoLista().ToString() + " elementos");
            }

            textBoxResultado->Text = sb->ToString();
        }

        System::String^ ObtenerRepresentacionLista() {
            std::string listaStr = miLista->MostrarComoString();
            return gcnew System::String(listaStr.c_str());
        }
    };
}