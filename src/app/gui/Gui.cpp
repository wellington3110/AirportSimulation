#include "Gui.h"
#include <qgroupbox.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qplaintextedit.h>
#include <qpushbutton.h>
#include <qinputdialog.h>
#include <AppInterface.h>

Gui::~Gui()
{
   delete inputDialog;
}

Gui::Gui(AppInterface* _app) : chosenOption(0), app(_app)
{
   QVBoxLayout* mainLayout = new QVBoxLayout(this);
   
   log = new QPlainTextEdit(this);
   gridLayout= new QGroupBox(this);
   menuOptions= new QComboBox(gridLayout);

   log->setReadOnly(true);

   setUpButtons();
   setUpInputDialogPlanesOnLand();
   createOptions();
   createMenu();

   mainLayout->addWidget(log);
   mainLayout->addWidget(gridLayout);
   setLayout(mainLayout);
   setWindowTitle(QString::fromLatin1("Simulator"));
}

void Gui::createMenu()
{
   QGridLayout* layout= new QGridLayout(gridLayout);
   layout->addWidget(new QLabel(QString::fromLatin1("Opções"), gridLayout), 0, 0);
   layout->addWidget(menuOptions, 0, 1);
   layout->addWidget(buttonOk, 0, 2);
   layout->addWidget(buttonClearLog, 0, 3);
   layout->addWidget(buttonExit, 0, 4);
   gridLayout->setLayout(layout);
   
}

void Gui::createOptions()
{
   menuOptions->addItem(QString::fromLatin1( "1. Número de aviões pousados até o momento"));
   menuOptions->addItem(QString::fromLatin1( "2. Número de aviões em solo"));
   menuOptions->addItem(QString::fromLatin1( "3. Número de aviões aguardando e quanto tempo está neste estado"));
   menuOptions->addItem(QString::fromLatin1( "4. Horários das mudanças de vento"));
   menuOptions->addItem(QString::fromLatin1( "5. Horários com aviões aguardando maior que 5"));
   menuOptions->addItem(QString::fromLatin1( "6. Horários com aviões em solo maior que 70% da capacidade"));
   menuOptions->addItem(QString::fromLatin1( "7. Horários com aviões enviados a outros aerportos"));
   menuOptions->addItem(QString::fromLatin1( "8. Horários com solicitações para decolagens pendentes acima de 5"));
   menuOptions->addItem(QString::fromLatin1( "9. Listar os eventos do sistema não lidos"));
}

int Gui::getPlanesOnLand()
{
   inputDialog->exec();
   return inputDialog->intValue();
}

void Gui::setUpButtons()
{
   buttonOk= new QPushButton("Ok", gridLayout);
   connect(buttonOk, SIGNAL( pressed() ), this, SLOT (captureOption()) );

   buttonClearLog= new QPushButton("Limpar tela", gridLayout);
   connect(buttonClearLog, SIGNAL( pressed() ), this, SLOT (executeClear()) );

   buttonExit= new QPushButton("Exit", gridLayout);
   connect(buttonExit, SIGNAL( pressed() ), this, SLOT (executeExit()) );
}

void Gui::setUpInputDialogPlanesOnLand()
{
   inputDialog= new QInputDialog();
   inputDialog->resize(300, 300);
   inputDialog->setInputMode(QInputDialog::IntInput);
   inputDialog->setWindowTitle(QString::fromLatin1("Aviões em solo"));
   inputDialog->setLabelText("Quantidade:");
   inputDialog->setIntMinimum(1);
   inputDialog->setIntValue(1);
}

void Gui::showMessage(std::string message)
{
   log->clear();
   log->textCursor().insertText(QString::fromLatin1(message.c_str()));
}

void Gui::captureOption()
{
   if( !(chosenOption == exitApp) )
      chosenOption= menuOptions->currentIndex() + 1;
   app->receiveOption(chosenOption);
}

void Gui::executeClear()
{
   log->clear();
}



