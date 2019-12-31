#include "ChocAn.h"

//=================================================================
// This file contains the tests for 
// the functions of the service class
// and the derived serviceRecord class.
//=================================================================



bool serviceTests()
{
    char name[] = "Counseling";
	char tname[] = "Massage";

	Service * testService = new Service(name, 88.88, 123456);
	Service * secondService = new Service(tname, 25.22, 123999);



    cout << "\n=====Service Display Test=====\n";



	Tree<Service> testTrees;

	testTrees.insert(testService);
	testTrees.insert(secondService);
	testTrees.displayAll();

    //testService.displayServiceInfo();

    return true;
}
