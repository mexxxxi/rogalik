#include "lib/include/character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
	#include <windows.h>
#endif

#include <locale.h>

int main() {
	#ifdef _WIN32
		setlocale(LC_ALL, ".UTF-8");
		SetConsoleOutputCP(65001);
	#endif

    srand(time(NULL)); 
    show_interface(); 
    
    return 0;
}
