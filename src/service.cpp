#include "ChocAn.h"

//=================================================================
// This file contains the function 
// implementations for the service class.
//=================================================================
/*    -- CHANGELOG --
- Initial service.cpp creation
- Added functions to service.cpp
Josh - Added changelog
Lee - Added copy constructor
 */

// Default Constructor
Service::Service()
{
    name = "N/A";
    cost = 0;
    serviceCode = 0;
}

// Copy Constructor
Service::Service(const Service & toCopy)
{
    name = toCopy.name;
    cost = toCopy.cost;
    serviceCode = toCopy.serviceCode;
}

//Constructor used to create a service with associated information
//when reading in data from the text files. The data is expected
//to be checked for errors before being passed to this constructor.
Service::Service(char * nameToAdd, double costToAdd, 
        long serviceCodeToAdd)
{
    name.assign(nameToAdd, 0, 20);
    cost = costToAdd;
    serviceCode = serviceCodeToAdd;
}



//Destructor

//This isn't needed, since there is no dynamic memory (new isn't used)
//Leaving some intact, since commenting it out completely causes errors
Service::~Service()
{
/*
    name = "N/A";
    cost = 0;
    serviceCode = 0;
*/
}




//Display function for testing purposes. It displays all of the 
//data for the service.
void Service::displayServiceInfo() const
{
    cout << "\nService Name: " << name
        << "\nCost: $" << cost
        << "\nService Code: " << serviceCode << '\n';
}



// Overloaded inequality operator which returns the result
// of a comparison of the service numbers of the two objects.
bool Service::operator <(const Service & toCompare)
{
    return serviceCode < toCompare.serviceCode;
}


bool operator <(long number, const Service & toCompare)
{
    return number < toCompare.serviceCode;
}

// Overloaded extraction operator for the Service class
// which calls the display function for the class.
ostream & operator <<(ostream & o, const Service & toDisplay)
{
    toDisplay.displayServiceInfo();
    return o;
}


// Overloaded equality operator for the Service class
// which calls the equality functions for the class.
bool operator ==(long number, const Service & toCompare)
{
    return number == toCompare.serviceCode;
}



bool operator ==(const Service & toCompare, long number)
{
    return number == toCompare.serviceCode;
}



//=================================================================
// Service Record Class
//=================================================================



//Constructor
ServiceRecord::ServiceRecord()
{
    dateProvided = "N/A";
    currentDateTime = "N/A";
    comments = "N/A";
    providerNumber = 0;
    memberNumber = 0;
}

// Copy Constructor
ServiceRecord::ServiceRecord(const ServiceRecord & toCopy)
{
    // Assigns the values of the other class.
    dateProvided = toCopy.dateProvided;
    currentDateTime = toCopy.currentDateTime;
    comments = toCopy.comments;
    providerNumber = toCopy.providerNumber;
    memberNumber = toCopy.memberNumber;
}

//Destructor
ServiceRecord::~ServiceRecord()
{
    dateProvided = "N/A";
    currentDateTime = "N/A";
    comments = "N/A";
    providerNumber = 0;
    memberNumber = 0;



}



//Display function for testing purposes. It displays all of the 
//data for the service.
void ServiceRecord::displayServiceInfo()
{
    Service::displayServiceInfo();
    cout << "\nDate Provided: " << dateProvided 
        << "\nCurrent Date and Time: " << currentDateTime
        << "\nComments: " << comments
        << "\nProvider Number: " << providerNumber
        << "\nMember Number: " <<  memberNumber << "\n";
}



// Function for filling in the information for the service record.
// It adds a date, comments, 
int ServiceRecord::fillInformation(char * dateToAdd, char * commentsToAdd,
        long providerNumberToAdd, 
        long memberNumberToAdd)
{
    providerNumber = providerNumberToAdd;
    memberNumber = memberNumberToAdd;
    return 0;
}
