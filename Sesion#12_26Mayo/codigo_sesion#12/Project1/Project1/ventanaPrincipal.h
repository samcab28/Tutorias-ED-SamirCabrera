#pragma once
#include "ventanaSecundaria.h"

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
            this->ContextMenuStrip = contextMenuStrip1;
        }

    protected:
        ~ventanaPrincipal()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ button1;
        System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
        System::Windows::Forms::ToolStripMenuItem^ menuArchivo;
        System::Windows::Forms::ToolStripMenuItem^ subMenuAbrir;
        System::Windows::Forms::ToolStripMenuItem^ subMenuGuardar;
        System::Windows::Forms::ToolStripSeparator^ separador1;
        System::Windows::Forms::ToolStripMenuItem^ menuEdicion;
        System::Windows::Forms::ToolStripMenuItem^ subMenuCopiar;
        System::Windows::Forms::ToolStripMenuItem^ subMenuPegar;
        System::Windows::Forms::ToolStripSeparator^ separador2;
        System::Windows::Forms::ToolStripMenuItem^ menuNavegacion;
        System::Windows::Forms::ToolStripMenuItem^ subMenuSiguiente;
        System::Windows::Forms::ToolStripMenuItem^ subMenuSalir;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->button1 = gcnew System::Windows::Forms::Button();
            this->contextMenuStrip1 = gcnew System::Windows::Forms::ContextMenuStrip(this->components);
            this->menuArchivo = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->subMenuAbrir = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->subMenuGuardar = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->separador1 = gcnew System::Windows::Forms::ToolStripSeparator();
            this->menuEdicion = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->subMenuCopiar = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->subMenuPegar = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->separador2 = gcnew System::Windows::Forms::ToolStripSeparator();
            this->menuNavegacion = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->subMenuSiguiente = gcnew System::Windows::Forms::ToolStripMenuItem();
            this->subMenuSalir = gcnew System::Windows::Forms::ToolStripMenuItem();

            // Configurar context menu
            this->contextMenuStrip1->SuspendLayout();
            this->SuspendLayout();

            // button1
            this->button1->Location = System::Drawing::Point(300, 200);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(200, 100);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Haz clic derecho aquí para ver el menú";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->MouseDown += gcnew MouseEventHandler(this, &ventanaPrincipal::button1_MouseDown);

            // contextMenuStrip1
            array<System::Windows::Forms::ToolStripItem^>^ items = gcnew array<System::Windows::Forms::ToolStripItem^>(3);
            items[0] = this->menuArchivo;
            items[1] = this->menuEdicion;
            items[2] = this->menuNavegacion;

            this->contextMenuStrip1->Items->AddRange(items);


            // menuArchivo
            array<System::Windows::Forms::ToolStripItem^>^ archivoItems = gcnew array<System::Windows::Forms::ToolStripItem^>(3);
            archivoItems[0] = this->subMenuAbrir;
            archivoItems[1] = this->subMenuGuardar;
            archivoItems[2] = this->separador1;

            this->menuArchivo->DropDownItems->AddRange(archivoItems);

            this->menuArchivo->Text = L"Archivo";

            // subMenuAbrir
            this->subMenuAbrir->Text = L"Abrir";
            this->subMenuAbrir->Click += gcnew EventHandler(this, &ventanaPrincipal::subMenuAbrir_Click);

            // subMenuGuardar
            this->subMenuGuardar->Text = L"Guardar";
            this->subMenuGuardar->Click += gcnew EventHandler(this, &ventanaPrincipal::subMenuGuardar_Click);

            // menuEdicion
            array<System::Windows::Forms::ToolStripItem^>^ edicionItems = gcnew array<System::Windows::Forms::ToolStripItem^>(2);
            edicionItems[0] = this->subMenuCopiar;
            edicionItems[1] = this->subMenuPegar;

            this->menuEdicion->DropDownItems->AddRange(edicionItems);

            this->menuEdicion->Text = L"Edición";

            // subMenuCopiar
            this->subMenuCopiar->Text = L"Copiar";
            this->subMenuCopiar->Click += gcnew EventHandler(this, &ventanaPrincipal::subMenuCopiar_Click);

            // subMenuPegar
            this->subMenuPegar->Text = L"Pegar";
            this->subMenuPegar->Click += gcnew EventHandler(this, &ventanaPrincipal::subMenuPegar_Click);

            // menuNavegacion
            array<System::Windows::Forms::ToolStripItem^>^ navegacionItems = gcnew array<System::Windows::Forms::ToolStripItem^>(2);
            navegacionItems[0] = this->subMenuSiguiente;
            navegacionItems[1] = this->subMenuSalir;

            this->menuNavegacion->DropDownItems->AddRange(navegacionItems);

            this->menuNavegacion->Text = L"Navegación";

            // subMenuSiguiente
            this->subMenuSiguiente->Text = L"Siguiente pantalla";
            this->subMenuSiguiente->Click += gcnew EventHandler(this, &ventanaPrincipal::subMenuSiguiente_Click);

            // subMenuSalir
            this->subMenuSalir->Text = L"Salir";
            this->subMenuSalir->Click += gcnew EventHandler(this, &ventanaPrincipal::subMenuSalir_Click);

            // ventanaPrincipal
            this->ClientSize = System::Drawing::Size(800, 500);
            this->Controls->Add(this->button1);
            this->Name = L"ventanaPrincipal";
            this->Text = L"Menú Contextual Avanzado";
            this->contextMenuStrip1->ResumeLayout(false);
            this->ResumeLayout(false);
        }

        void button1_MouseDown(Object^ sender, MouseEventArgs^ e)
        {
            if (e->Button == Windows::Forms::MouseButtons::Right)
            {
                Point showPoint = button1->PointToScreen(e->Location);
                showPoint.X += 10;
                contextMenuStrip1->Show(showPoint);
            }
        }

        void subMenuAbrir_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show("Has seleccionado Abrir", "Menú Archivo",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void subMenuGuardar_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show("Has seleccionado Guardar", "Menú Archivo",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void subMenuCopiar_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show("Has seleccionado Copiar", "Menú Edición",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void subMenuPegar_Click(Object^ sender, EventArgs^ e)
        {
            MessageBox::Show("Has seleccionado Pegar", "Menú Edición",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        void subMenuSiguiente_Click(Object^ sender, EventArgs^ e)
        {
            ventanaSecundaria^ secundaria = gcnew ventanaSecundaria();
            secundaria->ShowDialog();
        }

        void subMenuSalir_Click(Object^ sender, EventArgs^ e)
        {
            Application::Exit();
        }
    };
}