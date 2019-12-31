#include "ChocAn.h"

//=================================================================
// This file contains the function 
// implementations for the database class.
//=================================================================



// Default Constructor
Database::Database()
{ 

}

// Copy constructor.
Database::Database(const Database & toCopy)
{


}

// Destructor
Database::~Database()
{



}

// Member verification function temporary until the one below is 
// clarified on how memberList is supposed to be passed in.
bool Database::verifyMember(long toVerify)
{
    return false;
}


// Member verification function, retrieves the member from the 
// database if there is one which matches the member id.
bool Database::verifyMember(long toVerify, Member *& toRetrieve)
{
    return memberList.retrieve(toRetrieve, toVerify);
}



// Service code verification function, retrieves the service from  
// the database if there is one which matches the service code.
bool Database::verifyServiceCode(long toVerify, Service *& toRetrieve)
{
    // Will add back in once operators are added to class
    // return serviceList.retrieve(toRetrieve, toVerify);
    return false;
}



// Provider verification function, retrieves the provider from the
// database if there is one which matches the provider id.
bool Database::verifyProvider(long toVerify, Provider *& toRetrieve)
{
    // Will add back in once operators are added to class
    // return providerList.retrieve(toRetrieve, toVerify);
    return false;
}

// Provider verification function, retrieves the provider from the
// database if there is one which matches the provider id.
bool Database::verifyProvider(long toVerify)
{
    // Will add back in once operators are added to class
    // return providerList.retrieve(toRetrieve, toVerify);
    return toVerify == 100000;
}

// Write info to files.
void Database::writeToFiles()
{

}


// Read info from files.
void Database::readFromFiles()
{
   	// File variable definitions for reading.
	ifstream read_m; // For members.txt
	ifstream read_p; // For providers.txt
	ifstream read_s; // For services.txt
	//int i = 0; // Loop counter.
	//int j = 0;
	//int k = 0;
	char buffer1[100];
    char buffer2[100];
    char buffer3[100];
    char buffer4[100];
	long tempNum1;
    long tempNum2;
    double cost;
	Member * temp_member = NULL;
    Service * temp_service = NULL;


	// Attempt to open the file.
	// If successful, read it.
	read_m.open("src/members.txt");
	if (read_m)
	{
		cout << "Accessed members.txt." << endl;
		read_m.get(buffer1, 100, ':');
		read_m.ignore(100, ':');

		// Read until the end of the file.
		while (!read_m.eof())
		{
			read_m >> tempNum1;
			read_m.ignore(100, ':');
            
            read_m.get(buffer2, 100, ':');
            read_m.ignore(100, ':');

            read_m.get(buffer3, 100, ':');
            read_m.ignore(100, ':');
            
            read_m.get(buffer4, 100, ':');
            read_m.ignore(100, ':');

			read_m >> tempNum2;
			read_m.ignore(100, '\n');

            temp_member = new Member(buffer1, tempNum1, buffer2, 
                                     buffer3, buffer4, tempNum2);

            memberList.insert(temp_member);

            read_m.get(buffer1, 100, ':');
            read_m.ignore(100, ':');
		}
		read_m.close();
	}
    /*
	// Attempt to open the file.
	// If successful, read it.
	read_p.open("providers.txt");
	if (read_p)
	{
		cout << "Accessed providers.txt." << endl;

		// Read until the end of the file.
		while (!read_p.eof())
		{


		}
		read_p.close();
	}
    */

	
	// Attempt to open the file.
	// If successful, read it.
	read_s.open("src/services.txt");
	if (read_s)
	{
		cout << "Accessed services.txt." << endl;
		read_s.get(buffer1, 100, ':');
		read_s.ignore(100, ':');

		// Read until the end of the file.
		while (!read_s.eof())
		{
			read_s >> cost;
			read_s.ignore(100, ':');
            
			read_s >> tempNum1;
			read_s.ignore(100, '\n');

            temp_service = new Service(buffer1, cost, tempNum1);

            serviceList.insert(temp_service);

            read_s.get(buffer1, 100, ':');
            read_s.ignore(100, ':');
		// Read until the end of the file.
        }
		read_s.close();
	}
	return;	
}



void Database::displayMembers()
{
    memberList.displayAll();
}



void Database::displayServices()
{
    serviceList.displayAll();
}
