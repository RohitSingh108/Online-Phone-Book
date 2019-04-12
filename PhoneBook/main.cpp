#include <iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>


using namespace std;

// Global Variables
string fname,lname,phone_num;
int q,w;
char k,l;

//Functions
void addContact();
void searchContact();
void help();
void SelfExit();
bool check_digits(string);
bool check_numbers(string);
COORD coord = {0, 0};


// For changing cursor position on the screen
void gotoxy (int x, int y) // Ggotoxy fn. does not exist in Code::Blocks. So, here gotoxy() fn. is userdefined in this case.
            {coord.X = x; coord.Y = y; // X and Y coordinates
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            }


int main()
{
    short int choice;
    system("cls");

    system("color 4F"); //Color codes: 4-Red   F- Bright White
    gotoxy(10,4);
    for (q=1;q<37;q++)
        {
            cout<<"\xB2";
        };

    gotoxy(10,5);
    cout<<"\xB2            PHONE-BOOK            \xB2";
    gotoxy(10,6);
    cout<<"\xB2                                  \xB2";
    gotoxy(10,7);
    cout<<"\xB2                                  \xB2";
    gotoxy(10,8);
    cout<< "\xB2 1. Add Number to Contact         \xB2";
    gotoxy(10,9);
    cout<< "\xB2 2. Search from Directory         \xB2";
    gotoxy(10,10);
    cout<< "\xB2 3. Help Desk                     \xB2";
    gotoxy(10,11);
    cout<< "\xB2 4. Exit                          \xB2";
    gotoxy(10,12);
    cout<<"\xB2                                  \xB2";
    gotoxy(10,13);
    cout<<"\xB2 Choose any option:               \xB2";
    gotoxy(30,13);
    cin >> choice;



    switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                searchContact();
                break;

            case 3:
                help();
                break;

            case 4:
                SelfExit();

            default:
                cout<<"\n\n\t Invalid Input !";
                cout<<"\n\t Press any key to continue..";
                getch();
                main();
        }

        return 0;
}

void SelfExit()
{
    system("cls");
    gotoxy(10,3);
    cout << "\xB2\xB2  Thank You For Using !\n\n";
    exit(1);
}


void help()
{
    system("cls");
     gotoxy(10,2);
    for (q=1;q<50;q++)
        {
            cout<<"\xB2";
        };
    gotoxy(10,3);
    cout << "\xB2 We are ready to help at all time              \xB2";
     gotoxy(10,4);
    cout << "\xB2                                               \xB2";
     gotoxy(10,5);
    cout << "\xB2 Just get in touch with our technical support: \xB2";
     gotoxy(10,6);
    cout << "\xB2 +91-9980493526                                \xB2";
     gotoxy(10,7);
    cout << "\xB2                                               \xB2";
     gotoxy(10,8);
    cout << "\xB2                                               \xB2";
     gotoxy(10,9);
    cout << "\xB2 Email us at:                                  \xB2";
     gotoxy(10,10);
    cout << "\xB2 techsupport@gmail.com                         \xB2\n\n";
     gotoxy(10,11);
    cout << "\xB2                                               \xB2";
     gotoxy(10,12);
    cout << "\xB2                                               \xB2";
     gotoxy(10,13);
    cout << "\xB2 Press any key to go back to main menu ->      \xB2";
     gotoxy(10,14);
    cout << "\xB2                                               \xB2\n";
     gotoxy(10,15);
    for (q=1;q<50;q++)
        {
            cout<<"\xB2";
        };
     gotoxy(55,13);
    getch();

    main();
}




void addContact()
{
    ofstream phone("number.txt", ios::app);  // ofstream object is used to open a file for writing. In this case the file is number.txt
    system("cls");
     gotoxy(10,3);

    cout << "\xB2  Enter your First Name: ";
    cin>>fname;
    gotoxy(10,4);
    cout << "\xB2  Enter your Last Name:  ";
    cin >> lname;
    gotoxy(10,5);
    cout << "\xB2  Enter 10-Digit Phone Number: ";
    cin >> phone_num;

// check for 10 digit and then if every digit is a number or not

    if(check_digits(phone_num)==true)  // Check digit functions allows to check if 10 digits entered for phone number
          {
                if(check_numbers(phone_num)==true)
                        {
                            if(phone.is_open())  //is_open checks if the required file is open
                                    {
                                            phone << fname << " " << lname << " " << phone_num << endl;
                                            gotoxy(10,7);
                                            cout << "\xB2 Contact Saved Successfully !!!";
                                    }
                            else
                                    {
                                            gotoxy(10,7);
                                            cout << "\xB2 Error Opening File !";
                                    }
                        }
                else
                        {
                              gotoxy(10,7);
                              cout << "\xB2 A Phone Number Must Contain Numbers Only !";
                        }
        }

    else
                {
                        gotoxy(10,7);
                        cout<<"\xB2 A Phone number must contain 10 digits";
                }
    phone.close();

    gotoxy(10,10);
    cout<<"\xB2 Do you want to again insert another phone number?";
    cin>>k;
            if(k=='n')
                    {
                        main();
                    }
            else if(k=='y')
                    {
                        system("clr");
                        addContact();
                    }
            else
                    {
                            gotoxy(10,11);
                            cout<<"\xB2 Wrong value input";
                            gotoxy(10,15);
                            cout<<"\xB2 Press key to return to Main Menu";
                            getch();
                            main();
                    }
}





void searchContact()
{
    system("cls");
    bool found = false;
    ifstream myfile("number.txt"); // ifstream allows us to read the file
    string keyword;
    gotoxy(10,4);
    cout << "\xB2 Enter Name To Search : ";
    cin >> keyword;
    while(myfile >> fname >> lname >> phone_num)
    {
        if(keyword == fname || keyword == lname)
        {
            system("cls");
            gotoxy(10,4);
            cout << "\t\t\t CONTACT DETAILS AS PER THE QUERY";

            gotoxy(10,6);
            cout << "\xB2 First Name : " << fname;
            gotoxy(10,7);
            cout << "\xB2 Last Name : " << lname;
            gotoxy(10,8);
            cout << "\xB2 Phone Number : " << phone_num;
            found = true;
            gotoxy(10,10);
            cout << "\xB2 Do you want to re-search another contact?(y/n)";
            cin>>l;
                if(l=='n')
                    {
                        main();
                    }
                else if(l=='y')
                    {
                        system("clr");
                        searchContact();
                    }
                else
                    {
                            gotoxy(10,11);
                            cout<<"\xB2 Wrong value input";
                            gotoxy(10,15);
                            cout<<"\xB2 Press key to return to Main Menu";
                            getch();
                            main();
                    }
            break;


        }
    }
    if(found == false)
            gotoxy(10,5);
            cout << "\xB2 No Such Contact Found";
            gotoxy(10,6);
            cout<<"\xB2 Do you want to re-search another contact?(y/n)";
            cin>>l;
                if(l=='n')
                    {
                        main();
                    }
                else if(l=='y')
                    {
                        system("clr");
                        searchContact();
                    }
                else
                    {
                            gotoxy(10,8);
                            cout<<"\xB2 Wrong value input";
                            gotoxy(10,15);
                            cout<<"\xB2 Press key to return to Main Menu";
                            getch();
                            main();
                    }


}


bool check_digits(string x) // Function for checking if the phone number entered is having 10 digits
{
    if(x.length()== 10)
    return true;
        else
    return false;
}


bool check_numbers(string x)
{
    bool check = true;

    for(int i=0; i<x.length(); i++)
    { // We are converting each character into a integer. Integer of string ith character
        if(!(int(x[i]) >= 48 && int(x[i]) <=57)) // We are considering ASCII values
        {
            check = false;
            break;
        }

    }

    if(check == true)
        return true;
    if(check == false)
        return false;

}

