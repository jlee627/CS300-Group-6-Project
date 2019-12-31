#include "ChocAn.h"

//=================================================================
// This file contains the tests for 
// the functions of the database class.
//=================================================================




bool databaseTests()
{
    Database myDatabase;

    myDatabase.readFromFiles();
    myDatabase.displayMembers();
    myDatabase.displayServices();
    return true;
}
