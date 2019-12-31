#include "ChocAn.h"

//=================================================================
// This file contains the function 
// implementations for the provider class.
//=================================================================
/*     -- CHANGELOG --
-Initial provider.h creation
Josh Lee - Added simple return values to all functions that required them
Josh Lee - Added changelog	
Josh - Added requestProviderDirectory possible code
Josh - Fixed conflict merges
Josh - Removed getID() function 
Lee H - Cleaned up formatting and added more comments.
Josh - Removed checkServiceCode() and verify memberID from provider class
Josh - Created overloaded provider constructor
 */

// Constructor.
Provider::Provider()
{
    providerNumber = 0;
}

Provider::Provider(long toID){
    providerNumber = toID;
    //Need to add service list functionality?
}



// Destructor
Provider::~Provider()
{
    //list = NULL; // List of services.
    //providerNumber = 0; // Provider ID.

}

// Copy constructor.
// Currently copies the provider number correctly.
// Will do the list later.
Provider::Provider(const Provider & toCopy)
{
    //list = toCopy.list; // Copy the List of services.
    providerNumber = toCopy.providerNumber; // Copy the Provider ID.

}

// Request a provider directory.
// Right now, it is hardcoded.
void Provider::requestProviderDirectory()
{
	cout << "\nProvider Directory" << endl;
	cout << "Service\t\t\tService Code\t\t\tFee" << endl;
	

    //Read provider directory to terminal from file?
    //Read file line by line and display to terminal
    //File Format <Service Name><tab><tab><tab><Service Code><tab><tab><tab><Fee>
	
	//Possible File Reading Code
	/*
	ifstream inFile;
	char temp[300];

	inFile.open("providerDirectory.txt");
	
	if(!inFile){
		cout << "Unable to open file" << endl; 
		return 0;
	}

	inFile.getLine(temp,300);

	while(!inFile.eof()){
		cout << temp << endl;
		inFile.getLine(temp,300);
	}

	inFile.close();
	*/
    
    //return 0;

	//Example Directory format
    //cout << "\n______Provider Directory______\n\n";
    //cout << "\n598470 Dietitian\n"
     //   << "883948 Aeroobics Exercise Session\n\n";
	
}




// Display function which outputs the providerNumber.
void Provider::display() const
{
    cout << '\n' << providerNumber << '\n';
}



// Overloaded inequality operator which returns the result
// of a comparison of the providerNumbers of the two objects.
bool Provider::operator<(const Provider & toCompare)
{
    return providerNumber < toCompare.providerNumber;
}



// Overloaded extraction operator for the Provider class
// which calls the display function for the class.
ostream& operator<<(ostream & o, const Provider & toDisplay)
{
    toDisplay.display();
    return o;
}



// Overloaded extraction operator for the Provider class
// which checks if the id is equal to a value
bool operator ==(long IdToCompare, const Provider & toCompare)
{
    return IdToCompare == toCompare.providerNumber;
}



bool operator ==(const Provider & toCompare, long IdToCompare)
{
    return IdToCompare == toCompare.providerNumber;
}



//Placeholder functions to allow program to run for now,
//remove when main is updated
bool Provider::checkMemberID(long memberNumber)
{
    return true;
}

bool Provider::checkServiceCode(long serviceCode)
{
    return true;
}
