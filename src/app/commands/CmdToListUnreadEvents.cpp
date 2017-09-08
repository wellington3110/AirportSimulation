#include "CmdToListUnreadEvents.h"
#include "LogManipulator.h"
#include "UserInterface.h"

void CmdToListUnreadEvents::execute(UserInterface* ui)
{
   std::string log= LogManipulator::getInstance()->getLogs();
   ui->showMessage(log + "\n");
}
