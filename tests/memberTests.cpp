#include "ChocAn.h"

//=================================================================
// This file contains the tests for 
// the functions of the member class.
//=================================================================



bool memberTests()
{
    //casts are to eliminate compiler warnings
    char * name[] = {(char*)"Bob", (char*)"Joe", (char*)"Sue", (char*)"Mary"};
    long id[] = {12345678, 58234914, 23559254, 69263636};
    char * address[] = {(char*)"Nowhere", (char*)"Somewhere"};
    char * city[] = {(char*)"Portland"};
    char * state[] = {(char*)"OR"};
    long zip[] = {97207, 97005, 94205, 96206};

    Member * testMember = new Member(name[0], id[0], address[0], city[0], state[0], zip[0]);
    Member * secondMember = new Member(name[1], id[1], address[1], city[0], state[0], zip[1]);
    Member * thirdMember = new Member(name[2], id[2], address[0], city[0], state[0], zip[2]);
    Member * fourthMember = new Member(name[3], id[3], address[1], city[0], state[0], zip[3]);

    cout << "\n=====Member ID Verify Test=====\n";
    
    //Checks if the verification works correctly
    if(testMember->verifyMemberID(12345678) && !testMember->verifyMemberID(-124))
    {
        cout << "\nID Verify Test Passed\n";
    }
    

    cout << "\n=====Member Tree Add Test=====\n";

    Tree<Member> testTree;
    
    //Tests if the tree for the members correctly inserts and displays members
    testTree.insert(thirdMember);
    testTree.insert(fourthMember);
    testTree.insert(testMember);
    testTree.insert(secondMember);
    testTree.displayAll();

    cout << "\n=====Member Tree Retrieve Test=====\n";

    Member * testRetrieve = 0;
    cout << "Should retrieve id: " << id[3] << endl;
    testTree.retrieve(testRetrieve, id[3]);
    cout << *testRetrieve;

    cout << "\n=====Member Tree Remove Test=====\n";

    cout << "Should remove id: " << id[2] << endl;
    testTree.remove(id[2]);
    testTree.displayAll();
    
    return true;
}
