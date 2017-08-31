#include "CmdRemoveData.h"
#include "ReportFactory.h"

void CmdRemoveData::execute(Gui* gui)
{
   delete ReportFactory::getInstance();
}
