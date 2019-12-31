/* Larry Chiem
 * Since we have the ChocAn.h file, we can keep main short of lines 
 * by calling functions, such as:
 * 1. Welcome/Service Menu
 * 2 Provider Login
 * 3. Operator Login
 * 4. Exit

 Lee Hoang, 
 Jason Lee, 
 Bar Movshovich, 
 Joshua Lee, 
 Larry Chiem, 
 Joseph Ramirez


 CHANGELOG

 =======
 ======================================================================
 -- CHANGELOG --
 -Initial main.cpp creation
 Josh - Added Changelog 
 Lee = Added group member names and welcome message
 Added extra welcome messages.
 Larry - Created the main interface and menu's/options.

 */


#include "ChocAn.h"

// Provider object.
Provider provider;	//global provider pointer. 
Member * member;	//global member pointer.
Database database;

int chocAnMenu();
long providerLogin();
int providerMenu();
long promptMemberID();
long operatorLogin();
bool provideService();

// Main function.
int main()
{

	database.readFromFiles();
	// Option to select upon starting the program.
	//char option = '3';

	// Welcome the user to ChocAn and ask him to select an option. 
	//do 
	int choice = 0;
	while(choice != 2)
	{
        choice = chocAnMenu();

		switch(choice)
		{

			case 0:	//Proivder Login.
				{
                    //Provider login & verify  
                    long providerNumberToVerify;
                    do providerNumberToVerify = providerLogin();
                    while(database.verifyProvider(providerNumberToVerify));

					cout << "\033c" << "Login successful!\n" << endl;

					int choice_1 = 0;	//variable for switch cases.
					while(choice_1 !=3)
					{
                        choice_1 = providerMenu();
						// 0) Provide Service
						switch(choice_1)	//switch condition.
						{

							case 0:	//provide service.
								{
                                    provideService();
									//Call function that adds info into ServiceRecord
									break;
								}
							case 1:	// Request Provider Report
								{
									// Function to request provider report goes here. 
									break;
								}
							case 2: // Request Provider Directory 
								{
									// Function to request provider directory goes here.
									provider.requestProviderDirectory();
                                    break;
								}
							case 3:	//exit.
								{
									choice_1 = 3;
									break;
								}
						}
					}
					break;	//break for case 0 on line 70.
				}

			case 1:	//operator login.
				{
                    long operatorNumberToVerify;
                    do operatorNumberToVerify = operatorLogin();
                    //supposed to be verifyOperator but no such function...
                    while(database.verifyMember(operatorNumberToVerify));
                    
					//Operator Logged In Successfully
					cout << "\033c" << "Login successful!\n" << endl;

					int choice_2 = 0;	//switch variable. 
					while(choice_2 != 6)	//while user doesn't want to quit.
					{
						cout << "Operator options:\n" 
							<< "0) Add Member\n"
							<< "1) Add Provider\n"
							<< "2) Update Member Information\n"
							<< "3) Update Provider Information\n"
							<< "4) Delete Member\n"
							<< "5) Delete Provider\n"
							<< "6) Exit\n"
							<< "Please Select an Option:";

						cin >> choice_2;	//get user choice.
						cin.ignore(100,'\n');

						if (choice_2 < 0 || choice_2 > 6)	//user enters an invalid variable. 
						{
							cout << "Invalid option:" << choice_2 << "\nTry again." << string(5, '\n');;
							usleep(1000000);
						}

						switch(choice_2)	//switch condition.
						{
							//0) Add Member
							case 0:
								{
									//1) Add Provider
									break;
								}
							case 1:
								{
									//2) Update Member Information
									break;
								}
							case 2:
								{
									//3) Update Provider Information
									break;
								}
							case 3:
								{
									//4) Delete Member
									break;
								}
							case 4:
								{
									//5) Delete Provider 
									break;
								}
							case 5:
								{
									break;
								}
							case 6:
								{
									choice_2 = 6;	//exit.
									break;
								}
						}
					}
					break;	//break for line 189.
				}
			case 2:	//exit.
            {
                choice = 2;	//exit.
                break;

            }
		}
	}
	return 0;
}

int chocAnMenu()
{
    int choice = 0;
    do
    {
        cout << "\033c" << "\033[1;32mWelcome to ChocAn\033[0m\n" << string(5, '\n');
        cout << "ChocAn Service Menu: \n"
            << "0. Provider Login \n"
            << "1. Operator Login \n"
            << "2. Exit \n\n"
            << "Select an option (0-2):" << endl;
        cin >> choice;
        cin.ignore(100, '\n');

        // This triggers when the user selects an invalid option.
        if (choice < 0 || choice > 2)
        {
            cout << "Invalid option:" << choice << "\nTry again." << string(5, '\n');;
            usleep(1000000);
        }
    }while(choice < 0 || choice > 2);
    return choice;
}

//Prompts and returns provider ID (long)
long providerLogin() 
{
    long providerNumber;
    do
    {
        cout << "\033c" << "Provider Login Selected.\n"
            << "Please enter your Provider ID:";
        cin >> providerNumber;
        cin.ignore(100, '\n');
    } while (providerNumber < 100000 || providerNumber > 999999);
    return providerNumber; //Returns only if 6 digits.
}

int providerMenu()
{
    int choice;
    while(choice < 0 || choice > 3)
    {
        cout << "Provider options:\n" 
            << "0) Provide Service\n"
            << "1) Request Provider Report\n"
            << "2) Request Provider Directory\n"
            << "3) Exit\n"
            << "Please Select an Option:";

        cin >> choice;	//get user choice. 
        cin.ignore(100, '\n');

        if (choice < 0 || choice > 3)	//use enters an invalid variable.
        {
            cout << "Invalid option:" << choice << "\nTry again." << string(5, '\n');;
            usleep(1000000);
        }
    }
    return choice;
}

//Prompts and returns Member ID (long)
long promptMemberID()
{
    long memberNumber;
        cout << "\033c" << "Provide Service Selected.\n\n"
            << "Please enter the Member ID:";
        cin >> memberNumber;
        cin.ignore(100, '\n');

    return memberNumber;
}

//Prompts and returns Operator ID (long)
long operatorLogin() 
{
    long operatorNumber;
    do
    {
        cout << "\033c" << "Operator Login Selected.\n"
            << "Please enter your Operator ID:";
        cin >> operatorNumber;
        cin.ignore(100, '\n');
    } while (operatorNumber < 100000 || operatorNumber > 999999);
    return operatorNumber; //Returns only if 6 digits.
}

//This asks the user (provider) to input the member number
//and will say if validated or not. (entering again might be necessary)

//Then the provider inputs data for service provided, and will give this
//data to the serviceRecord class. The user  will then be prompted
//again to double check (this isn't necessary according to the project paper)
bool provideService()
{
    cout << "\033c" << "Provide Service Selected.\n\n";

    //Check Member ID
    long memberNumberToVerify;
	while(!database.verifyMember(memberNumberToVerify, member))
	{
		memberNumberToVerify = promptMemberID();
	}
    string dateProvided;
    long serviceCode;
    char comments[100];

    // The provider will enter the date of service along with
    // the six digit service code and additional comments.
    cout << "\n\nPlease enter date of service(MM-DD-YYYY):";
    getline(cin, dateProvided);
    cout << "\nEnter 6-digit service code:";
    cin >> serviceCode;
    cin.ignore(100, '\n');
    cout << "Enter session comments (100 character limit):";
    cin >> comments;
    cin.ignore(100, '\n');

    //ServiceRecord.fillInformation(char *, char *, long providerNumber, long memberNumber);
    cout << "Service Recorded.\n\n"
        << "Based on service code " << serviceCode
        << ", fee to be paid is $"; // << Service.cost;

/*
    string currentDate, reconfirmDateProvided, name;
    long memberNumber2, serviceCode2;
    double cost;
*/

    //Reconfirm info
    //The project paper doesn't say the provider needs to list this all
    //out again.
/*
    cout << "\n\nPlease enter current date(MM-DD-YYYY):";
    getline(cin, currentDate);
    cout << "\n\nPlease re-enter date of service(MM-DD-YYYY):";
    getline(cin, reconfirmDateProvided);
    cout << "\nPlease enter the Member name:";
    getline(cin, name);
    cout << "\nPlease enter Member ID number:";
    cin >> memberNumber2;
    cin.ignore(100, '\n');
    cout << "\nEnter the 6-digit service code:";
    cin >> serviceCode2;
    cin.ignore(100, '\n');
    cout << "\nPlease enter the fee to be paid:";
    cin >> cost;
    cin.ignore(100, '\n');
*/

    return false;
}
