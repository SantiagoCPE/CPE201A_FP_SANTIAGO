#include <iostream>
#include "login.h"
#include "ricketyticket.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    loadAdminsFromFile();
    loadStudentsFromFile();

    mainMenu();
    return 0;
}

