#include "ChocAn.h"

//=================================================================
// This file contains menu function for running the various
// tests for the classes implemented in the ChocAn software
//=================================================================


// Test Prototypes
bool memberTests();
bool serviceTests();
bool providerTests();
bool managerTests();
bool databaseTests();


//Define for outputting test results
#define dotest(A) {                      \
    if(A)                                \
        cout << "\nTEST COMPLETED\n";    \
    else                                 \
        cout << "\nTEST FAILED\n";       \
}


int main()
{
    char choice;
    bool again = true;

    do{
        // Testing menu
        cout << "\n0) Exit\n"
             << "1) Member\n"
             << "2) Service\n"
             << "3) Provider\n"
             << "4) Manager\n"
             << "5) Database\n"
             << "\nWhich test would you like to run?\n";
        cin >> choice;
        cin.ignore(100,'\n');

        switch(choice)
        {
            case '0':
                again = false;
                break;
            case '1':
                dotest(memberTests());
                break;
            case '2':
                dotest(serviceTests());
                break;
            case '3':
                dotest(providerTests());
                break;
            case '4':
                dotest(managerTests());
                break;
            case '5':
                dotest(databaseTests());
                break;
            default:
                cout << "\nInvalid test\n";
                break;
        } 
    } while (again);
        
    return 0;
}
