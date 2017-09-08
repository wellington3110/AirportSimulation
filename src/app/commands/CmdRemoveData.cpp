#include "CmdRemoveData.h"
#include "ReportFactory.h"

void CmdRemoveData::execute(UserInterface* gui)
{
   delete ReportFactory::getInstance();
}
