
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "Login.h"
#include <stdio.h>

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    
    SetConsoleOutputCP(CPAGE_UTF8);
    
    Login();

    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}


