#include "App.h"
#include <clocale>
#include <crtdbg.h>
#include <Windows.h>
#include <iostream>

int main()
{
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


//DWORD WINAPI myThread(LPVOID lpParameter)
//{
//	int myCounter = *((int*)lpParameter);
//	while(myCounter < 0xFFFFFFFF) ++myCounter;
//	return 0;
//}
//
//int main(int argc, char* argv[])
//{
//	using namespace std;
//
//	int myCounter = 1;
//	DWORD myThreadID;
//	HANDLE myHandle = CreateThread(0, 0, myThread, &myCounter, 0, &myThreadID);
//	char myChar = ' ';
//	while(myChar != 'q') {
//		cout << myCounter << endl;
//		myChar = getchar();
//	}
//	
//	CloseHandle(myHandle);
//	return 0;
//}