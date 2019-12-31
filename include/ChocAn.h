#include <iostream>
#include <cctype>
#include <cstring> 
#include <string> 
#include <cassert>
#include <unistd.h>
#include <bst.h>
#include <fstream> // For reading and writing from files.

using namespace std;

// **********************************************************
// Lee Hoang // 17 November 2017 // CS 300
//
// This is the header file for all of the classes involved
// in the ChocAn Data Processing program.  //
// **********************************************************
//         --    CHANGE LOG    --
//
// Joseph      - Initial testing
// Lee         - Fixed some capitalization issues that caused compile errors.
// Josh        - Added comment to line 111 and 112 regarding data structure of lists
// Josh        - Added getID() functions to member and provide
// Josh	       - Added overloaded constructor for provider class, changed Service * list to Service * recordList
// Josh        - Added getID() functions to member and provider
// Lee	       - Cleaned up comments and added more of them.
// Lee	       - Added copy constructor to the Database class.
// **********************************************************

// Class for a Member of ChocAn.
class Member
{
    public:
        Member();           // constructor.     
        Member(const Member &); // Copy constructor.
        Member(char*, long, char*, char*, char*, long);    // constructor. 
        ~Member();          // destructor. 
        void displayMemberInfo() const;   // Display's everything in private. 
        bool verifyMemberID(long);  // long compare.
        long getID();

	// Overloaded operators
	// <, <<, ==
        bool operator<(const Member & toCompare);
        friend bool operator <(long IdToCompare, const Member & toCompare);
        friend ostream& operator<<(ostream & o, const Member & toDisplay); 
        friend bool operator==(long IdToCompare, const Member & toCompare);
        friend bool operator==(const Member & toCompare, long IdToCompare);
    private:                 // Member information.
        string name;         // Member name.
        long idNumber;       // Member's ID #, at least 32 bits
        string address;      // Member address.
        string city;         // Member city.
        string state;        // Member state. 
        long zip;            // Member zip code.
};



// This class is all about the services that a provider can offer to a Member.
class Service
{
    public:
        Service();                      //constructor
		Service(const Service&);				//copy constructor. 
        Service(char *, double, long);  //name of service, cost of service, service Code
        ~Service();                     //destructor
        void displayServiceInfo() const;      //Display info related to a particular service.
	    bool operator<(const Service & toCompare);
        friend bool operator <(long number, const Service & toCompare);
        friend ostream& operator<<(ostream & o, const Service & toDisplay); 
        friend bool operator==(long number, const Service & toCompare);
        friend bool operator==(const Service & toCompare, long number);
 
	//bool operator<( 		//Overloaded compare operator to insert service code
    private:                            // Info about services.
        string name;                    // service name.
        double cost;                    // serivce cost. 
        long serviceCode;               // service ID code. 
};



class ServiceRecord: public Service
{
    public:
        ServiceRecord();                // Constructor
        ServiceRecord(const ServiceRecord &); // Copy constructor.
        ~ServiceRecord();               // Destructor
        void displayServiceInfo();      // read external data file.     
        int fillInformation(char *, char *, long, long);    // export to external data file. 
    private:                            // Info about services.
        string dateProvided;            // Date service was provided. 
        string currentDateTime;         // Current Date and Time
        string comments;                // Comments entered by provider
        long providerNumber;		// Provider ID #
        long memberNumber;		// Member ID #
};



// This class defines everything a provider has and should do.
class Provider
{
    public:
        Provider();                     // constructor.
        Provider(long toID);
        Provider(const Provider &);	// Copy constructor.
        ~Provider();                    // destructor. 
        bool checkServiceCode(long serviceCode); //function to check service code entered.
        bool checkMemberID(long memberNumber);  //check member id.
        void requestProviderDirectory();// Request the provider directory.
        long getID();			// Get the provider ID (not needed)
        void display() const;		// Constant display function
        bool operator<(const Provider & toCompare); // Overloaded < operator.
        friend ostream& operator<<(ostream & o, const Provider & toDisplay);
        friend bool operator ==(long IdToCompare, const Provider & toCompare);
        friend bool operator ==(const Provider & toCompare, long IdToCompare);
    private:
	string providerName;
        long providerNumber;
	string streetAddress;
	string city;
	string state;
	long zip;

        Service ** recordList;
	long totalFee;
};



// Class for the ChocAn operator.
class Manager
{
    public:
        Manager();                       //constructor. 
		Manager(const Manager&);						//copy constructor. 
        ~Manager();                      //destructor. 
        int addMember(char *, long, char *, char *, char *, long);//add a member. 
        int removeMember(long);          //remove a member. 
        int addProvider(long);           //add a provider. 
        int removeProvider(long);        //remove a provider. 
        int updateMemberInfo(char *, char *, char *);    //update member data. 
        bool verifyServiceCode();        //verify service code. 
    protected: 
};


// Class for holding the data for the ChocAn software. Jason added this.
class Database
{
    public:
        Database();                            // constructor
	Database(const Database &);	       // Copy constructor.
        ~Database();                           // destructor
        bool verifyMember(long);
        bool verifyMember(long, Member * &);           // verifies a memberID
        bool verifyServiceCode(long, Service * &);     // verify service code. 
        bool verifyProvider(long, Provider * &); // verify provider;
        bool verifyProvider(long); // verify provider;
        void writeToFiles();                   // write data to files
        void readFromFiles();                  // read data from files
        void displayMembers();
        void displayServices();
    private:
        Tree<Service> serviceList;             // List of services.
        Tree<Provider> providerList;           // List of providers.
        Tree<Member> memberList;               // List of members.
};
