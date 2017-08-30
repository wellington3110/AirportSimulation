#include "TemplateProcessReport.h"

#include "Report.h"
#include "Gui.h"
#include "ReportFactory.h"

void TemplateProcessReport::generateReport(Data::DataType data, Gui* gui)
{
   Report* report= ReportFactory::getInstance()->retrieveReport(data);
   std::string presentationMessage= getPresentationMessage();
   gui->showMessage(presentationMessage + report->getReportData() + "\n\n"); 
}
