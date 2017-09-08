#include "TemplateProcessReport.h"

#include "UserInterface.h"
#include "Report.h"
#include "ReportFactory.h"

void TemplateProcessReport::generateReport(Data::DataType data, UserInterface* ui)
{
   Report* report= ReportFactory::getInstance()->retrieveReport(data);
   std::string presentationMessage= getPresentationMessage();
   ui->showMessage(presentationMessage + report->getReportData() + "\n\n"); 
}
