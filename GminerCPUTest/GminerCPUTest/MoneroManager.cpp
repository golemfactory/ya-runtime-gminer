#include "MoneroManager.hpp"

#include <iostream>

#include "windows.h"
MoneroManager::MoneroManager()
{
	std::cout << "Hello from Monero Manager" << std::endl;

}

MoneroManager::~MoneroManager()
{
	std::cout << "Good bye from Monero Manager" << std::endl;
}


int MoneroManager::RunMonero()
{
    //chdir("Monero\\xmrig-6.14.0");

    SetCurrentDirectoryA("..\\Monero\\xmrig-6.14.0");

    std::cout << "Running Monero command: " << moneroCommand << std::endl;


    //todo redirect output

    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    /*
    if (argc != 2)
    {
        printf("Usage: %s [cmdline]\n", argv[0]);
        return;
    }*/

    // Start the child process. 
    if (!CreateProcessA(NULL,   // No module name (use command line)
        (LPSTR)moneroCommand.c_str(),        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
        )
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return 0;
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
