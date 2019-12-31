#include "ChocAn.h"
//=================================================================
// This file contains the tests for 
// the functions of the provider class.
//=================================================================



bool providerTests()
{
    long id = 12345678;

    Provider * testProvider = new Provider(id);
    Provider * secondProvider = new Provider;

    cout << *testProvider;

    cout << *secondProvider;


    //Checks to see if Provider Directory can be requested.
    cout << "\n=====Request Provider Directory Test=====\n";
    testProvider->requestProviderDirectory();


    cout << "\n=====Provider Tree Test=====\n";

    Tree<Provider> testTree;

    //Tests if the tree for the members correctly inserts and displays members
    testTree.insert(testProvider);
    testTree.insert(secondProvider);
    testTree.displayAll();



    return true;
}
