//
// Created by segev on 2/28/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_USER_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_USER_H
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#define SPACE ' '
#define AT_SIGN '@'
#define DOT '.'
#define SLASH '\\'
#define BACKSLASH '/'
#define UNDERLINE '_'
#define NAME_LIM 20
#define ID_LIM 9
#define EMAIL_LIM 35
#define PUP_LIM 10
#define ADDRESS_LIM 30
#define PUP_LIM 10
#define PASS_MIN 6
#define MAX 100
using namespace std;


class User {

protected:
    char *ID;
    char *first_name;
    char *last_name;
    char *gender;
    char *email;
    char *phone;
    char *username;
    char *password; // checked
    char *address;  // checked
    char* birthday; // checked


public:
    static char Int_To_Char(int num) {return char((int)'0' + num);}
    static bool Check_Range(int start, int end, int num) { return ((num >= start) && (num <= end)); } // Checked
    static bool Check_Upper(char ch) { return ((ch >= 'A') && (ch <= 'Z')); } // Checked
    static bool Check_Lower(char ch) { return ((ch >= 'a') && (ch <= 'z')); } // Checked
    static char Lower_To_Upper(char ch) { return ch - 'a' + 'A'; } // Checked
    static bool Check_Number(char ch) { return ((ch >= '0') && (ch <= '9')); } // Checked
    static bool Check_Let(char ch) { return Check_Lower(ch) || Check_Upper(ch); }; // Checked
    static bool Blank_Line(int len); //Checked
    static bool Check_Name(char *); // Checked
    static char *Set_String(char *); // Checked
    static bool Check_Digits(char *);
    bool Set_Name(); //Checked
    void Set_Gender(); //Checked
    bool Set_Email(); // Checked
    bool Set_ID(); //Checked
    bool Set_Phone(); //Checked
    bool Set_Username(); //Checked
    bool Set_Password(); // Checked
    bool Set_Birthday();
    bool Set_Address();
    static void msg01() { cout << "Notice: Name can only contain letters and be up to 20 characters" << endl; }//Checked
    static void msg02() {cout << "Notice: Email must be in the format: example@company.ending and up to 35 characters" << endl;} // Checked
    static void msg03() {cout << "Notice: Phone number must start with 05, and be only digits" << endl;}
    static void msg04() {cout << "Notice: Username can be up to 10 characters and contain only letters and numbers" << endl;} // Checked
    static void msg05() {cout << "Notice: Password must be at least 6 characters and up to 10 characters and must contain at least one uppercase one lowercase letters and a number" << endl;} // Checked
    static void msg06() {cout << "Notice: Address can contain only letters, number, slash and space." << endl;}
    char* Get_ID() const {return ID;}
    char* Get_First_Name() const {return first_name;}
    char* Get_Last_Name() const {return last_name;}
    char* Get_Gender() const {return gender;}
    char* Get_Email() const {return email;}
    char* Get_Phone() const {return phone;}
    char* Get_Username() const {return username;}
    char* Get_Password() const {return password;}
    char* Get_Address() const {return address;}
    char* Get_Birthday() const{return birthday;}
    bool Check_Date(char*, int, int);



public:
    User(char * newID) {
        //while(!Set_ID());
        Set_Name();
        Set_Gender();
        while(!Set_Email());
        while(!Set_Phone());
        while(!Set_Username());
        while(!Set_Password());
        while(!Set_Address());
        while(!Set_Birthday());
        ID = Set_String(newID);}

//    User(){}

    User(char *n_ID, char *f_name, char *l_name, char* n_gender, char *n_email, char *n_phone, char *user, char *pass,
         char *add, char* birth) :
            ID(nullptr), first_name(nullptr), last_name(nullptr), gender(nullptr), email(nullptr), phone(nullptr),
            username(nullptr), password(nullptr), address(nullptr), birthday(nullptr)
    {
        // Make deep copies of the input C-strings
        ID = Set_String(n_ID);
        first_name = Set_String(f_name);
        last_name = Set_String(l_name);
        gender = Set_String(n_gender);
        email = Set_String(n_email);
        phone = Set_String(n_phone);
        username = Set_String(user);
        password = Set_String(pass);
        address = Set_String(add);
        birthday = Set_String(birth);
    }

    User(const User &copy) :
            ID(nullptr), first_name(nullptr), last_name(nullptr), gender(nullptr),
            email(nullptr), phone(nullptr), username(nullptr), password(nullptr), address(nullptr), birthday(nullptr)
    {
        // Make deep copies of the input C-strings
        ID = Set_String(copy.ID);
        first_name = Set_String(copy.first_name);
        last_name = Set_String(copy.last_name);
        gender = Set_String(copy.gender);
        email = Set_String(copy.email);
        phone = Set_String(copy.phone);
        username = Set_String(copy.username);
        password = Set_String(copy.password);
        address = Set_String(copy.address);
        birthday = Set_String(copy.birthday);
    }

    ~User(){
//        delete [] this->ID;
//        delete [] this->first_name;
//        delete [] this->last_name;
//        delete [] this->email;
//        delete [] this->gender;
//        delete [] this->phone;
//        delete [] this->username;
//        delete [] this->password;
//        delete [] this->birthday;
//        delete [] this->address;
    }


    friend ostream& operator<<(ostream& out, User& print)
    {
        out << "ID: " << print.Get_Birthday() << endl;
        out << "First Name: " << print.Get_First_Name() << endl;
        out << "Last Name: " << print.Get_Last_Name() << endl;
        out << "Gender: " << print.Get_Gender() << endl;
        out << "Email: " << print.Get_Email() << endl;
        out << "Phone: " << print.Get_Phone() << endl;
        out << "UserName: " << print.Get_Username() << endl;
        out << "Password: " << print.Get_Password() << endl;
        out << "Address: " << print.Get_Address() << endl;
        out << "Birthday: " << print.Get_Birthday() << endl;
        return out;
    }
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_USER_H
