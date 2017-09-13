#pragma once
#ifndef INCLUDED_GUI_H
#define INCLUDED_GUI_H

#include "UserInterface.h"
#include <qdialog.h>

#define exitApp 99

class QGroupBox;
class QComboBox;
class QPushButton;
class QPlainTextEdit;
class QInputDialog;
class AppInterface;

class Gui : public QDialog, public UserInterface
{
   Q_OBJECT

public:
   Gui(AppInterface* app);
   ~Gui();

   int getPlanesOnLand();
   int getMenuOption() { return exec(); }
   void clearDisplay() {}
   void showMessage(std::string message);

private:
   void createMenu();
   void setUpButtons();
   void setUpInputDialogPlanesOnLand();
   void createOptions();

   AppInterface* app;

   QGroupBox* gridLayout;

   QPlainTextEdit* log;

   QPushButton* buttonOk;
   QPushButton* buttonExit;
   QPushButton* buttonClearLog;
   
   QComboBox* menuOptions;

   QInputDialog* inputDialog;

   int chosenOption;

private slots:
   void executeClear();
   void captureOption();
   void executeExit() {done(0); chosenOption= exitApp; captureOption();}

protected:
   void closeEvent(QCloseEvent*) { executeExit(); }

};

#endif // INCLUDED_GUI_H
