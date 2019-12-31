#include "ChocAn.h"

//=================================================================
// This file contains the function 
// implementations for the manager class.
//=================================================================
/*    -- CHANGELOG --
Joseph - Testing out branch
Lee - Added manager functions.
Josh - Added changelog

 */
// Manager constructor.
Manager::Manager()
{
}


// Copy constructor
// Not put in yet.
Manager::Manager(const Manager & toCopy)
{
//    serviceList = NULL;
 //   providerList = NULL;
  //  memberList = NULL;

}


// Manager destructor.
Manager::~Manager()
{
}



// This function adds a member to ChocAn. It asks for a member ID, a member name, the member's city,
// and the member's state.
int Manager::addMember(char * name,long idNumber, char * address, char * city, char * state, long zip)
{

    return 0;
}



// This function removes a member from ChocAn.
int Manager::removeMember(long memberID)
{

    return 0;
}



// This function adds a provider.
int Manager::addProvider(long providerNumber)
{

    return 0;
}



// This function removes a provider.
int Manager::removeProvider(long)
{

    return 0;
}



// This function updates the member information.
int Manager::updateMemberInfo(char * address, char * city, char * state)
{

    return 0;
}



