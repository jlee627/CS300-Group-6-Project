#include "ChocAn.h"

//=================================================================
// This file contains the function 
// implementations for the Member class.
//=================================================================
/*    -- CHANGELOG --
- Initial member.cpp creation
- Added member.cpp functions
Josh - Added Changelog
Josh - Added getID() function
Lee - Finished the destructor and improved formatting.
Lee - Fixed merge conflicts when merging with master.
Lee - Cleaned up formatting.
Lee - Added more comments.
 */


// Default constructor.
// It initializes all private data to their default values.
Member::Member()
{
    name = "N/A"; // Member name as string
    idNumber = 0; // Member ID# as long
    address = "N/A"; // Address as string
    city = "N/A"; // City as string
    state = "N/A"; // State as string
    zip = 0; // ZIP code as long
}

// Copy constructor.
Member::Member(const Member & toCopy)
{
    name = toCopy.name; // Assign a name to a member.
    idNumber = toCopy.idNumber;
    address = toCopy.address;
    city = toCopy.city;
    state = toCopy.state;
    zip = toCopy.zip;


}



// Constructor used to create a member with associated information
// when reading in data from the text files. The data is expected
// to be checked for errors before being passed to this constructor.
Member::Member(char * nameToAdd, long IdToAdd, char * addressToAdd,
        char * cityToAdd, char * stateToAdd, long zipToAdd)
{
    name.assign(nameToAdd, 0, 25); // Assign a name to a member.
    idNumber = IdToAdd;
    address.assign(addressToAdd, 0, 25);
    city.assign(cityToAdd, 0, 14);
    state.assign(stateToAdd, 0, 2);
    zip = zipToAdd;
}



// Destructor.
// It resets all private data to their initial values.
Member::~Member()
{
    name = "N/A";
    idNumber = 0;
    address = "N/A";
    city = "N/A";
    state = "N/A";
    zip = 0;

}



// Display function for testing purposes. It displays all of the
// data for the member.
void Member::displayMemberInfo() const
{
    cout << "\nName: " << name
        << "\nID: " << idNumber
        << "\nAddress: " << address
        << "\nCity: " << city
        << "\nState: " << state
        << "\nZip: " << zip << "\n";
}



// This function checks whether the ID passed in matches the
// member's ID number. It returns true if they match and false
// if they do not.
bool Member::verifyMemberID(long toVerify)
{
    if (toVerify == idNumber) // If the IDs match, return true.
        return true;

    return false; // IDs don't match.
}



// Getter function for ID (Not needed anymore, delete soon)
long Member::getID()
{
    return idNumber;
}



// Overloaded inequality operator which returns the result
// of a comparison of the idNumbers of the two objects.
bool Member::operator <(const Member & toCompare)
{
    return idNumber < toCompare.idNumber;
}


bool operator <(long IdToCompare, const Member & toCompare)
{
    return IdToCompare < toCompare.idNumber;
}

// Overloaded extraction operator for the Member class
// which calls the display function for the class.
ostream & operator <<(ostream & o, const Member & toDisplay)
{
    toDisplay.displayMemberInfo();
    return o;
}


// Overloaded equality operator for the Member class
// which calls the equality functions for the class.
bool operator ==(long IdToCompare, const Member & toCompare)
{
    return IdToCompare == toCompare.idNumber;
}



bool operator ==(const Member & toCompare, long IdToCompare)
{
    return IdToCompare == toCompare.idNumber;
}
