#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
   for (int i = 0; i < 10; ++i)
   {
      std::cout<< i << std::endl;
   }
   return 0;
}

int main(void)
{
   DWORD dwThreadId, dwThrdParam = 1;
   HANDLE hThread;

   hThread = CreateThread(
      NULL, // default security attributes
      0, // use default stack size
      MyThreadFunction, // thread function
      &dwThrdParam, // argument to thread function
      0, // use default creation flags
      &dwThreadId); // returns the thread identifier

   printf("The thread ID: %d.\n", dwThreadId);

   // Check the return value for success. If something wrong...
   //if (hThread == NULL)
   //   printf("CreateThread() failed, error: %d.\n", GetLastError());
   ////else, gives some prompt...
   //else
   //   printf("It seems the CreateThread() is OK lol!\n");
   if (CloseHandle(hThread) != 0)
      printf("Handle to thread closed successfully.\n");
   return 0;
}
