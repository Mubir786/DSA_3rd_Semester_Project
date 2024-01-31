#include<iostream>
#include<vector>
#include<conio.h>
#include<map>
#include<fstream>
#include<string>
#include<windows.h>
#include <queue>

using namespace std;

struct air_line
{
	protected:
	    long long acc_bal = {};
		char pass[20];
    	char pin[20];
    	string acc_id, name, fath_name, cnic, ph_num, email, ho, st, se, city,acc_num;
    public:
		void login();
		void introduction();
		void menu();
		void details();
		void new_user();
    	void already_user();
	    void search();
	    void update();
	    void del_record();
	    void show_all_records();
		void Ticket_Booking();
};

struct LoginInfo {
    string email;
    string password;
    string pin;
    LoginInfo* next;

    LoginInfo(string e, string p, string pn) : email(e), password(p), pin(pn), next(nullptr) {}
};

class Airline 
{
	
private:
    LoginInfo* head;

public:
	air_line air;
    Airline() : head(nullptr) {}

    void addLoginInfo(string email, string password, string pin) 
	{
        LoginInfo* newLogin = new LoginInfo(email, password, pin);
        newLogin->next = head;
        head = newLogin;
    }

    bool login(string email, string password, string pin) 
	{
        LoginInfo* current = head;
        while (current != nullptr) 
		{
            if (current->email == email && current->password == password && current->pin == pin) 
			{
                cout<<"LOGIN SUCCESSFUL";
                return true;
            }
            current = current->next;
        }
        exit(0);
        return false;
    }
};

void air_line::login()
{
	
	cout<<"\n\n";	
	cout<<"\t ********************************************************************************* "<<"\n";
	cout<<"\t **********************************    Login    ********************************** "<<"\n";
	cout<<"\t ********************************************************************************* "<<"\n";
	cout<<"\n";
	
		Airline airline;

    // Adding login information to the linked list
    airline.addLoginInfo("mubir@gmail.com", "123456789", "123456789");
    airline.addLoginInfo("hassan@gmail.com", "123456789", "123456789");
    airline.addLoginInfo("gohar@gmail.com", "123456789", "123456789");
    // User input for login
    string email, pass, pin;
    cout << "\t\t\t Enter your email: ";
    cin >> email;
    cout<<"\n";
    cout << "\t\t\t Enter your password: ";
    cin >> pass;
    cout<<"\n";
    cout << "\t\t\t Enter your pin number: ";
    cin >> pin;
    cout<<"\n";

    // Attempting login
    airline.login(email, pass, pin);

	
	system("cls");

}

void air_line::introduction()
{
	
	cout<<"\t\t\t ============================================================= "<<"\n";
	cout<<"\t\t\t ==               AIR LINE MANAGEMENT SYSTEM                == "<<"\n";
	cout<<"\t\t\t ============================================================= "<<"\n";
	cout<<"\t\t\t ==                                                         == "<<"\n";
	cout<<"\t\t\t ==                     SUBMITTED TO:                       == "<<"\n";
	cout<<"\t\t\t ==                   SIR ZEESHAN ASLAM                     == "<<"\n";
	cout<<"\t\t\t ==                   DATED: 25-01-2024                     == "<<"\n";
	cout<<"\t\t\t ==                                                         == "<<"\n";
	cout<<"\t\t\t ============================================================= "<<"\n";
	system("pause");
	system("cls");
}

void air_line::menu()
{
	system("pause");
	air_line air;
	int choice;
	
	cout<<"\t\t ========================================================================== \n";
	cout<<"\t\t ==                           CONTROL PANNEl                             == \n";
	cout<<"\t\t ========================================================================== \n";
	cout<<"\t\t ==                                                                      == \n";
	cout<<"\t\t ==                  01) DETAILS ABOUT FLIGHTS                           == \n";
	cout<<"\t\t ==                  02) ADD NEW PASSENGER                               == \n";
	cout<<"\t\t ==                  03) Already User                                    == \n";
	cout<<"\t\t ==                  04) Search User Record                              == \n";
	cout<<"\t\t ==                  05) Update User Record                              == \n";
	cout<<"\t\t ==                  06) Delete User Record                              == \n";
	cout<<"\t\t ==                  07) Show All Records                                == \n";
	cout<<"\t\t ==                  08) Ticket Booking                                  == \n";
	cout<<"\t\t ==                  09) EXIT                                            == \n";
	cout<<"\t\t ==                                                                      == \n";
	cout<<"\t\t ========================================================================== \n";
	cout<<"Enter your chice from 1 to till 5:"<<"\t";
	cin>>choice;
	switch(choice)
	{
		case 1:
	    	air.details();
		
    	case 2:
	    	air.new_user();
		
    	case 3:
	    	air.already_user();
		
        case 4:
        	air.search();
    	
        case 5:
        	air.update();
    	
    	case 6:
        	air.del_record();
        	
        case 7:
        	air.show_all_records();
        	
        case 8:
        	air.Ticket_Booking();
        default:
        	return;
	}
	
    system("cls");	
}

void addedge(vector<int> adj[], map<string, int>& airportIndex, const string& s1, const string& d) 
{
    int s = airportIndex[s1];
    int dIndex = airportIndex[d];
    adj[s].push_back(dIndex);
    adj[dIndex].push_back(s);
}

void printgraph(vector<int> adj[], int v, map<int, string>& indexAirport) 
{
    for (int d = 0; d < v; d++) 
	{
        cout << "\nFlights from " << indexAirport[d] << " to:";
        for (auto x : adj[d]) 
		{
            cout << " " << indexAirport[x];
        }
        cout << "\n";
    }
}


void air_line::details()
{
    int v, AirPorts;
    string s1, d1;

    map<string, int> airportIndex;
    map<int, string> indexAirport;
    int indexCounter = 0;

    cout << "\t\t ===================================== " << "\n";
    cout << "\t\t ==            FLIGHTS MENU         == " << "\n";
    cout << "\t\t ===================================== " << "\n";
    cout << "\t\t ==  1.Lahore --> Islamabad         == " << "\n";
    cout << "\t\t ==  2.Lahore --> Karachi           == " << "\n";
    cout << "\t\t ==  3.Lahore --> Peshawar          == " << "\n";
    cout << "\t\t ==  4.Lahore --> Swat              == " << "\n";
    cout << "\t\t ==  5.Islamabad --> Lahore         == " << "\n";
    cout << "\t\t ===================================== " << "\n";

    cout << "\t\t\t Enter how many airports you want to create: ";
    cin >> v;
    cout << "\n";

    cout << "\t\t\t How many AirPorts you want to make: ";
    cin >> AirPorts;
    cout << "\n";

    while (AirPorts--) 
	{
        cout << "\t\t\t Enter an airport: ";
        cin >> s1;
        if (airportIndex.find(s1) == airportIndex.end()) 
		{
            airportIndex[s1] = indexCounter;
            indexAirport[indexCounter++] = s1;
        }
    }

    vector<int> adj[v];

    while (true)
	{
        cout << "\nAdd a flight:\n";
        cout << "\t\t\t Enter departure airport: ";
        cin >> s1;

        cout << "\t\t\t Enter destination airport: ";
        cin >> d1;

        addedge(adj, airportIndex, s1, d1);

        cout << "\t\t\t Do you want to add another flight? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice != 'Y' && choice != 'y') 
		{
            break;
        }
    }

    printgraph(adj, v, indexAirport);

	
}

void air_line::new_user()
{
A:

	system("cls");
	int option = {};
	
	cout << "\n\n\t ============================================================================================= " << "\n";
	cout << "\n\n\t ============================================================================================= " << "\n";
	cout << "\n\n\n ==                                   Select Account Type                                   == " << "\n";
	cout << "\n\n\t ============================================================================================= " << "\n";
	cout << "\n\n\t ============================================================================================= " << "\n";
	cout << "\n\n\t ==                        01. Current Account (Initial Amount > 1000)                      == " << "\n";
	cout << "\n\n\t ==                        02. Saving Account (Initial Amount > 500)                        == " << "\n";
	cout << "\n\n\t ==                        03. Go Back                                                      == " << "\n";
	cout << "\n\n\t ============================================================================================= " << "\n";
	cout << "\n\n\t ============================================================================================= " << "\n";
	cout << "\n\n\t ==                                Please Select the Option:                                == " << "\n";
	cout << "\n\n\t ============================================================================================= " << "\n";
	cout << "\n\n\t ============================================================================================= " << "\n";
	cin >> option;

	if (option == 1)
	{
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;
		system("cls");
		fstream file;
		//string id = {};

		long long bal = {};

		char pa[20] = {};
		char pi[20] = {};

		string id, n, fn, cn, pn, em, h, s, so, cit, /*pa, pi,*/ an;

		

		cout << "\n\n\n\n\tCurrent Account ";

		cout << "\n\n\tAccount ID: ";
		cin >> acc_id;
		cout << "\n\n\tName: ";
		cin >> name;
		cout << "\n\n\tFather Name: ";
		cin >> fath_name;
		cout << "\n\n\tCNIC (13 Digits): ";
		cin >> cnic;
		cout << "\n\n\tPhone Number (14 Digits with Country Code): ";
		cin >> ph_num;
		cout << "\n\n\tE-mail: ";
		cin >> email;
		cout << "\n\n\tAddress: ";
		cout << "\n\n\tHouse No: ";
		cin >> ho;
		cout << "\n\tStreet No: ";
		cin >> st;
		cout << "\n\tSector: ";
		cin >> se;
		cout << "\n\tCity: ";
		cin >> city;
	B:
		
		cout << "\n\n\tPassword (5 Characters Only): ";
		cin >> pass;
		if (strlen(pass) == 5)
		{
			flag = 1;
		}

		if (flag == 0)
		{
			
			cout << "\n\n\tInvalid Password Length Try Again...";
			cout << endl;
			goto B;

		}
	C:
		

		cout << "\n\n\tPin (5 Digits Only): ";
		cin >> pin;
		if (strlen(pin) == 5)
		{
			flag1 = 1;
		}

		if (flag1 == 0)
		{
			
			cout << "\n\n\tInvalid Pin Length Try Again...";
			cout << endl;
			goto C;

		}
		
		cout << "\n\n\tAccount Number: ";
		cin >> acc_num;

	M:
		
		cout << "\n\n\tAccount Balance: ";
		cin >> acc_bal;

		if (acc_bal > 1000)
		{
			flag2 = 1;
		}

		if (flag2 == 0)
		{
			
			cout << "\n\n\tInvalid Initial Amount...";
			cout << endl;
			goto M;

		}
		

		file.open("bank.txt", ios::in);

		if (!file)
		{
			file.open("bank.txt", ios::app | ios::out);

			file << " " << acc_id << " " << name << " " << fath_name << " " << cnic << " " << ph_num << " " << email << " " << ho << " " << st << " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";
			file.close();
		}

		else
		{
			file >> id >> n >> fn >> cn >> pn >> em >> h >> s >> so >> cit >> pa >> pi >> an >> bal;
			while (!file.eof())
			{
				if (id == acc_id || pn == ph_num || cn == cnic || an == acc_num || em == email)
				{
					
					cout << "\n\n\tUser Already Exist...";
					_getch();
					goto A;
				}

				file >> id >> n >> fn >> cn >> pn >> em >> h >> s >> so >> cit >> pa >> pi >> an >> bal;


			}

			file.close();
			file.open("bank.txt", ios::app | ios::out);
			file << " " << acc_id << " " << name << " " << fath_name << " " << cnic << " " << ph_num << " " << email << " " << ho << " " << st << " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

			file.close();
		}


		

		cout << "\n\n\tNew User Account Created Successfully...";


	}

	if (option == 2)
	{

		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;
		system("cls");
		fstream file;
		//string id = {};

		float bal = {};

		char pa[20] = {};
		char pi[20] = {};

		string id, n, fn, cn, pn, em, h, s, so, cit, /*pa, pi,*/ an;

		

		cout << "\n\n\n\n\tSaving Account ";

		cout << "\n\n\tAccount ID: ";
		cin >> acc_id;
		cout << "\n\n\tName: ";
		cin >> name;
		cout << "\n\n\tFather Name: ";
		cin >> fath_name;
		cout << "\n\n\tCNIC (13 Digits): ";
		cin >> cnic;
		cout << "\n\n\tPhone Number (14 Digits with Country Code): ";
		cin >> ph_num;
		cout << "\n\n\tE-mail: ";
		cin >> email;
		cout << "\n\n\tAddress: ";
		cout << "\n\n\tHouse No: ";
		cin >> ho;
		cout << "\n\tStreet No: ";
		cin >> st;
		cout << "\n\tSector: ";
		cin >> se;
		cout << "\n\tCity: ";
		cin >> city;
	K:
		
		cout << "\n\n\tPassword (5 Characters Only): ";
		cin >> pass;
		if (strlen(pass) == 5)
		{
			flag = 1;
		}

		if (flag == 0)
		{
			
			cout << "\n\n\tInvalid Password Length Try Again...";
			cout << endl;
			goto K;

		}
	L:
		
		cout << "\n\n\tPin (5 Digits Only): ";
		cin >> pin;
		if (strlen(pin) == 5)
		{
			flag1 = 1;
		}

		if (flag1 == 0)
		{
			
			cout << "\n\n\tInvalid Pin Length Try Again...";
			cout << endl;
			goto L;

		}
		cout << "\n\n\tAccount Number: ";
		cin >> acc_num;

	N:
		

		cout << "\n\n\tAccount Balance: ";
		cin >> acc_bal;

		if (acc_bal > 500)
		{
			flag2 = 1;
		}
		if (flag2 == 0)
		{
			
			cout << "\n\n\tInvalid Initial Amount...";
			cout << endl;
			goto N;
		}
	     

		file.open("bank.txt", ios::in);

		if (!file)
		{
			file.open("bank.txt", ios::app | ios::out);

			file << " " << acc_id << " " << name << " " << fath_name << " " << cnic << " " << ph_num << " " << email << " " << ho << " " << st << " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";
			file.close();
		}

		else
		{
			file >> id >> n >> fn >> cn >> pn >> em >> h >> s >> so >> cit >> pa >> pi >> an >> bal;
			while (!file.eof())
			{
				if (id == acc_id || pn == ph_num || cn == cnic || an == acc_num || em == email)
				{
					
					cout << "\n\n\tUser Already Exist...";
					_getch();
					goto A;
				}

				file >> id >> n >> fn >> cn >> pn >> em >> h >> s >> so >> cit >> pa >> pi >> an >> bal;


			}

			file.close();
			file.open("bank.txt", ios::app | ios::out);
			file << " " << acc_id << " " << name << " " << fath_name << " " << cnic << " " << ph_num << " " << email << " " << ho << " " << st << " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

			file.close();
		}


		

		cout << "\n\n\tNew User Account Created Successfully...";

	}

	if (option == 3)
	{
		system("pause");
		air_line a;
	    system("cls");
		a.menu();
	}

}

class Account { // already user
public:
    string acc_id;
    string name;
    string fath_name;
    string cnic;
    string ph_num;
    string email;
    string ho;
    string st;
    string se;
    string city;
    string pass;
    string pin;
    string acc_num;
    long long acc_bal;
    Account* next;

    Account() {
        next = nullptr;
    }
};

class LinkedList { // already user
	
	
private:
    Account* head;
public:
	Account a;
    LinkedList() {
        head = nullptr;
    }

   void displayAccountDetails(string t_id) 
   {
        ifstream file("bank.txt"); // Open file within the function

        if (!file) {
            cout << "\n\n\n\tNo Database Found ";
        } else {
            Account a;
            int found = 0;

            while (file >> a.acc_id >> a.name >> a.fath_name >> a.cnic >> a.ph_num >> a.email >> a.ho >> a.st >> a.se >> a.city >> a.pass >> a.pin >> a.acc_num >> a.acc_bal) {
                if (t_id == a.acc_id) {
                    cout << "\n\n\tPassword            :  " << a.pass << endl;
                    cout << "\n\n\tPin                 :  " << a.pin << endl;
                    cout << "\n\n\tBalance             :  " << a.acc_bal << endl;
                    found++;
                }
            }
            file.close();

            if (found == 0) {
                cout << "\n\n\tUser ID not Found...";
            }
        }
    }

    // Additional functions for handling linked list operations can be added here
};


void air_line::already_user()
{
	system("cls");
	air_line a;

	LinkedList accountsList;
    string t_id;

    cout << "\n\n\t\t\tAlready User Account";
    cout << "\n\n\n\n\tUser Account ID: ";
    cin >> t_id;

    accountsList.displayAccountDetails(t_id); // Call function to display account details
    system("pause");
    system("cls");
    
    a.menu();
}

struct UserAccount  // search user 
{  
    string acc_id;
    string name;
    string fath_name;
    string cnic;
    string ph_num;
    string email;
    string ho;
    string st;
    string se;
    string city;
    string pass;
    string pin;
    string acc_num;
    string acc_bal;
    UserAccount* next;
};

class UserAccountList {
private:
    UserAccount* head;

public:
    UserAccountList() {
        head = nullptr;
    }

    void insertUser(const UserAccount& user) 
	{
        UserAccount* newUser = new UserAccount(user); // Create a new user dynamically
        newUser->next = head;
        head = newUser;
    }

   void searchUser(const string& t_id) {
    UserAccount* current = head; // Initialize current as the head of the linked list
    int found = 0;

    while (current != nullptr) {
        if (current->acc_id == t_id) {
            displayUserDetails(*current);
            found++;
        }
        current = current->next;
    }

    if (found == 0) {
        cout << "\n\n\tUser ID not Found...";
    }
}

    void displayUserDetails(const UserAccount& user)  // search user
	{
        // Display user details here, similar to your previous code
        // You can use the cout statements as you did before
    }

    void loadFromFile(const string& filename) 
	{
        ifstream file(filename); // Open the file
        if (!file.is_open()) {
            cout << "\n\n\n\t\t\tNo Database Found";
            return;
        }

        UserAccount tempUser;
        while (file >> tempUser.acc_id >> tempUser.name >> tempUser.fath_name >> tempUser.cnic >> tempUser.ph_num >> tempUser.email >> tempUser.ho >> tempUser.st >> tempUser.se >> tempUser.city >> tempUser.pass >> tempUser.pin >> tempUser.acc_num >> tempUser.acc_bal) {
            insertUser(tempUser);
        }
        file.close();
    }

    ~UserAccountList()   // search user
	{
        UserAccount* current = head;
        while (current != nullptr) {
            UserAccount* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

void air_line::search()
{
	system("cls");
	fstream file;
	string t_id;
	int found = 0;
	cout << "\n\n\t\t\t\tSearch User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		
		cout << "\n\n\n\t""User Account ID: ";
		cin >> t_id;
		file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;
		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				system("cls");
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t==                            User Account Details                                 ==   " << "\n";
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t==                                   Account ID                                    ==   " << acc_id;
				cout << "\t==                                   Name                                          ==   " << name << endl << endl;
				cout << "\t==                                   Father Name                                   ==   " << fath_name << endl << endl;
				cout << "\t==                                   CNIC (13 Digits)                              ==   " << cnic << endl << endl;
				cout << "\t==                                   Phone Number (14 Digits with Country Code)    ==   " << ph_num << endl << endl;
				cout << "\t==                                   E-mail                                        ==   " << email << endl << endl;
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t==                                   Address                                       ==   " << endl << endl;
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t==                                   House No                                      ==   " << ho << endl << endl;
				cout << "\t==                                   Street No                                     ==   " << st << endl << endl;
				cout << "\t==                                   Sector                                        ==   " << se << endl << endl;
				cout << "\t==                                   City                                          ==   " << city << endl << endl;
				cout << "\t==                                   Password (5 Characters Only)                  ==   " << pass << endl << endl;
				cout << "\t==                                   Pin (5 Digits Only)                           ==   " << pin << endl << endl;
				cout << "\t==                                   Account Number                                ==   " << acc_num << endl << endl;
				cout << "\t==                                   Account Balance                               ==   " << acc_bal << endl << endl;
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t=====================================================================================   " << "\n";
				cout << "\t=====================================================================================   " << "\n";



				found++;
			}
			file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;
		}
		file.close();
		if (found == 0)
		{
			
			cout << "\n\n\tUser ID not Found...";
		}
	}
	
}

void air_line::update()
{
	int flag = 0;
	int flag1 = 0;
	system("cls");
	fstream file, file1;
	char pa[20] = {};
	char pi[20] = {};
	string t_id, n, fn, cn, pn, em, ad, h, s, so, cit,/* pa, pi,*/ an;
	float ba = {};
	int found = 0;
	cout << "\n\n\t\t\tUpdate User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		
		cout << "\n\n\n\tUser Account ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;

		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				

				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				cout << "\t ==                                            Previous User Account Data                                          ==  " << "=========" << "\n";
				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				cout << "\t ==                                                    Account ID :                                                ==  " << acc_id << "\n";
				cout << "\t ==                                                    Name :                                                      ==  " << name << "\n";
				cout << "\t ==                                                    Father Name :                                               ==  " << fath_name << "\n";
				cout << "\t ==                                                    CNIC (13 Digits) :                                          ==  " << cnic << "\n";
				cout << "\t ==                                                    Phone Number (14 Digits with Country Code) :                ==  " << ph_num << "\n";
				cout << "\t ==                                                    E-mail :                                                    ==  " << email << "\n";
				cout << "\t ==                                                    Address :                                                   ==  " << endl << "\n";
				cout << "\t ==                                                    House No :                                                  ==  " << ho << "\n";
				cout << "\t ==                                                    Street No :                                                 ==  " << st << "\n";
				cout << "\t ==                                                    Sector :                                                    ==  " << se << "\n";
				cout << "\t ==                                                    City :                                                      ==  " << city << "\n";
				cout << "\t ==                                                    Password (5 Characters Only) :                              ==  " << pass << "\n";
				cout << "\t ==                                                    Pin (5 Digits Only) :                                       ==  " << pin << "\n";
				cout << "\t ==                                                    Account Numbe :                                             ==  " << acc_num << "\n";
				cout << "\t ==                                                    Account Balance :                                           ==  " << acc_bal << "\n";
				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				cout << "\t ====================================================================================================================  " << "=========" << "\n";
				
				cout << "\n\n\n\tEnter New User Account Data";
				cout << "\n\n\tName: ";
				cin >> n;
				cout << "\n\n\tFather Name: ";
				cin >> fn;
				//cout << "\n\n\tCNIC (13 Digits): ";
				//cin >> cn;
				cout << "\n\n\tPhone Number (14 Digits with Country Code): ";
				cin >> pn;
				cout << "\n\n\tE-mail: ";
				cin >> em;
				cout << "\n\n\tAddress: ";
				cout << "\n\n\tHouse No: ";
				cin >> h;
				cout << "\n\tStreet No: ";
				cin >> s;
				cout << "\n\tSector: ";
				cin >> so;
				cout << "\n\tCity: ";
				cin >> cit;
			B:
				
				cout << "\n\n\tPassword (5 Characters Only): ";
				cin >> pa;
				if (strlen(pa) == 5)
				{
					flag = 1;
				}

				if (flag == 0)
				{
					
					cout << "\n\n\tInvalid Password Length Try Again...";
					cout << endl;
					goto B;

				}
			F:
				
				cout << "\n\n\tPin (5 Digits Only): ";
				cin >> pi;
				if (strlen(pi) == 5)
				{
					flag1 = 1;
				}

				if (flag1 == 0)
				{
					
					cout << "\n\n\tInvalid Pin Length Try Again...";
					cout << endl;
					goto F;

				}
				//cout << "\n\n\tAccount Number: ";
				//cin >> an;

				file1 << " " << acc_id << " " << n << " " << fn << " " << cnic << " " << pn << " " << em << " " << h << " " << s << " " << so << " " << cit << " " << pa << " " << pi << " " << acc_num << " " << acc_bal << "\n";


				

				cout << "\n\n\tUser Account Successfully Edit...";

				found++;
			}
			else
			{
				file1 << " " << acc_id << " " << name << " " << fath_name << " " << cnic << " " << ph_num << " " << email << " " << ho << " " << st << " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";


			}
			file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;

		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt", "bank.txt");
		if (found == 0)
		{
			
			cout << "\n\n\tUser ID not Found...";
		}

	}
	
}


void air_line::del_record()
{
	system("cls");
	fstream file, file1;
	string t_id;
	int found = 0;
	int a = {};
	cout << "\n\n\t\t\t\tDelete User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		
		system("cls");
		cout << "\n\n\t\t\t\tDelete User Record";
		//changeColor(10);
		cout << "\n\n\n\tUser Account ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;

		while (!file.eof())
		{
			if (t_id == acc_id)
			{
				
				cout << "\n\n\n\tYour Required User Account Data is Deleted...";
				found++;
			}
			else
			{
				file1 << " " << acc_id << " " << name << " " << fath_name << " " << cnic << " " << ph_num << " " << email << " " << ho << " " << st << " " << se << " " << city << " " << pass << " " << pin << " " << acc_num << " " << acc_bal << "\n";

			}
			file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;

		}

		file.close();
		file1.close();


		remove("bank.txt");
		rename("bank1.txt", "bank.txt");



		if (found == 0)
		{
			
			cout << "\n\n\tUser ID not Found...";
		}



	}

	
}

void air_line::show_all_records()
{
	system("cls");
	int found = 0;
	ifstream file;
	ifstream file1;
	cout << "\n\n\t\t\tShow All User's Records";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		
		cout << "\n\n\n\t\t\tNo Database Found";
	}
	else
	{
		file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;

		while (!file.eof())
		{
			
			cout << "\t=================================================================================  " << "\n";
			cout << "\t=================================================================================  " << "\n";
			cout << "\t==                              Account ID                                     ==  " << acc_id << "\n";
			cout << "\t==                            CNIC (13 Digits)                                 ==  " << cnic << "\n";
			cout << "\t==                            Phone Number (14 Digits with Country Code)       ==  " << ph_num << "\n";
			cout << "\t==                            E-mail                                           ==  " << email << "\n";
			cout << "\t==                            Address                                          ==  " << "\n";
			cout << "\t==                            House No                                         ==  " << ho << "\n";
			cout << "\t==                            Street No                                        ==  " << st << "\n";
			cout << "\t==                            Sector                                           ==  " << se << "\n";
			cout << "\t==                            City                                             ==  " << city << "\n";
			cout << "\t==                            Password (5 Characters Only)                     ==  " << pass << "\n";
			cout << "\t==                            Pin (5 Digits Only)                              ==  " << pin << "\n";
			cout << "\t==                            Account Number                                   ==  " << acc_num << "\n";
			cout << "\t==                            Account Balance                                  ==  " << acc_bal << "\n";
			cout << "\t=================================================================================  " << "\n";
			cout << "\t=================================================================================  " << "\n";



			file >> acc_id >> name >> fath_name >> cnic >> ph_num >> email >> ho >> st >> se >> city >> pass >> pin >> acc_num >> acc_bal;
			found++;
		}
		file.close();
		if (found == 0)
		{
			
			cout << "\n\n\tDatabase is Empty...";
		}

	}
	
}

struct Ticket {
    string fromCity;
    string toCity;
    double price;
    int seatNumber;
};

class TicketBookingSystem {
private:
    queue<Ticket> ticketQueue;
    map<pair<string, string>, double> ticketPrices; // M to store ticket prices for city pairs //

public:
    // Constructor to initialize ticket prices
    TicketBookingSystem() {
        ticketPrices[{"Karachi", "Lahore"}] = 2500;
        ticketPrices[{"Karachi", "Islamabad"}] = 2800;
        ticketPrices[{"Karachi", "Swat"}] = 3000;
        ticketPrices[{"Swat", "Lahore"}] = 1800;
        ticketPrices[{"Swat", "Islamabad"}] = 1600;
        ticketPrices[{"Swat", "Karachi"}] = 3000;
        ticketPrices[{"Lahore", "Islamabad"}] = 2200;
        ticketPrices[{"Lahore", "Karachi"}] = 2500;
        ticketPrices[{"Lahore", "Swat"}] = 1800;
    }

    // Function to display available ticket prices
    void displayTicketPrices() {
        cout << "Available Ticket Prices:" << endl;
        for (const auto& entry : ticketPrices) {
            cout << entry.first.first << " to " << entry.first.second << ": " << entry.second << endl;
        }
    }

    // Function to book a ticket
    void bookTicket(const string& fromCity, const string& toCity) {
        pair<string, string> cityPair = {fromCity, toCity};
        auto it = ticketPrices.find(cityPair);
        if (it == ticketPrices.end()) {
            cout << "--->> Ticket not available for the selected route.\n";
            return;
        }

        double price = it->second;

        static int seatNumber = 1; // Unique seat numbers for each booking
        Ticket newTicket = {fromCity, toCity, price, seatNumber++};
        ticketQueue.push(newTicket);

        cout << "--->> Ticket booked successfully from " << fromCity << " to " << toCity << ".\n";
        cout << "Ticket Price: " << price << ", Seat Number: " << newTicket.seatNumber << endl;
    }

    // Function to display ticket details for all bookings
    void displayTicketDetails() {
        if (ticketQueue.empty()) {
            cout << "--->> No tickets booked yet." << endl;
            return;
        }

        cout << "--->> Ticket Details for all bookings:" << endl;
        int count = 1;
        queue<Ticket> tempQueue = ticketQueue; // Create a copy for display without modifying the original
        while (!tempQueue.empty()) {
            Ticket currentTicket = tempQueue.front();
            cout << count++ << ". From " << currentTicket.fromCity << " to " << currentTicket.toCity
                 << ", Price: " << currentTicket.price << ", Seat Number: " << currentTicket.seatNumber << endl;
            tempQueue.pop();
        }
    }

    // Function to return ticket //
    void returnTicket() {
        if (ticketQueue.empty()) {
            cout << "--->> No tickets to return." << endl;
            return;
        }

        Ticket returnedTicket = ticketQueue.front();
        cout << "--->> Ticket returned from " << returnedTicket.fromCity << " to " << returnedTicket.toCity
             << ", Seat Number: " << returnedTicket.seatNumber << endl;
        ticketQueue.pop();
    }
};

void air_line::Ticket_Booking() 
{
	cout << "===========-->> Ticket Booking <<--===========" << endl;
    TicketBookingSystem ticketSystem;

    int option;
    do {
    	cout << "-----------------------------------------";
        cout << "\n===::!! >> Select Options << !!::===\n" << "-----------------------" << "\n1.-->> Book a Ticket\n2.-->> Display Ticket Prices\n3.-->> Display Ticket Details\n4.-->> Return a Ticket\n5.-->> Exit\n\n";
        cout << "-----------------------------------------\n";
		cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                string fromCity, toCity;
                cout << "Enter the source city :-> ";
                cin >> fromCity;
                cout << "Enter the destination city :-> ";
                cin >> toCity;
                ticketSystem.bookTicket(fromCity, toCity);
                break;
            }
            case 2:
                ticketSystem.displayTicketPrices();
                break;
            case 3:
                ticketSystem.displayTicketDetails();
                break;
            case 4:
                ticketSystem.returnTicket();
                break;
            case 5:
                cout << "--->> Exiting the ticket booking system.\n";
                break;
            default:
                cout << "--->> Invalid choice. Please enter a valid option.\n";
        }
    } while (option != 5);
}

int main()
{
	system("COLOR 9e");
	air_line air;
	air.login();
	air.introduction();
	air.menu();
	air.details();
	air.new_user();
	air.already_user();
	air.search();
	air.update();
	air.del_record();
	air.show_all_records();
	air.Ticket_Booking();
	
}
