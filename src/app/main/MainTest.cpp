#include "App.h"
#include <clocale>
#include <crtdbg.h>
#include <Windows.h>
#include <QApplication>


int main(int argc, char *argv[])
{              
   QApplication app(argc, argv);
   _CrtMemState s1, s2;
   
   _CrtMemCheckpoint(&s1);
   _CrtMemDumpStatistics( &s1);

   setlocale(LC_ALL, "Portuguese");

   App* a= new App;
   a->run();
   delete a;

   _CrtMemCheckpoint(&s2);
   _CrtMemDumpStatistics( &s2);
}



