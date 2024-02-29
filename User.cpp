//
// Created by segev on 2/28/2024.
//

#include "User.h"


bool User::Blank_Line(int len) {
    if (len == 0) {
        cout << "You entered a blank line, please try again." << endl;
        return true;
    }
    return false;
}

char *User::Set_String(char * str) {
    char *res = new char[strlen(str) + 1];
    strcpy(res, str);
    return res;
}


bool User::Check_Name(char *str) {
    for (int i = 0; i < strlen(str); ++i) {
        if (!Check_Upper(str[i]) && !Check_Lower(str[i]))
            return false;
        if ((i == 0) && (Check_Lower(str[i])))
            str[i] = Lower_To_Upper(str[i]);
    }
    return true;
}


bool User::Set_Name() {
    char f_name[MAX];
    char l_name[MAX];
    cout << "Enter your first name: " << endl;
    msg01();
    cin.getline(f_name, MAX);
    while (!Check_Name(f_name) || Blank_Line(strlen(f_name)) || !(Check_Range(1, NAME_LIM, int(strlen(f_name))))) {
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin.getline(f_name, MAX);
    }
    cout << "Enter your Last name" << endl;
    msg01();
    cin.getline(l_name, MAX);
    while (!Check_Name(l_name) || Blank_Line(strlen(l_name)) || !(Check_Range(1, NAME_LIM, int(strlen(l_name))))) {
        cout << "The name you enter was incorrect, please try again:" << endl;
        msg01();
        cin.getline(l_name, MAX);
    }
    this->first_name = Set_String(f_name);
    this->last_name = Set_String(l_name);
    return true;
}


void User::Set_Gender() {
    char gend[MAX];
    bool error = true;
    do {
        cout << "Enter Your Gender, please enter M/F" << endl;
        cin >> gend;
        if (strlen(gend) != 1) {
            cout << "You entered to many characters please enter M/F only, please try again." << endl;
            continue;
        }
        if (gend[0] == 'f' || gend[0] == 'F' || gend[0] == 'm' || gend[0] == 'M')
            error = false;
        else
            cout << "Incorrect option please try again" << endl;
    } while (error);
    if (Check_Lower(gend[0]))
        gend[0] = Lower_To_Upper(gend[0]);
    this->gender = new char[2];
    this->gender[0] = gend[0];
    this->gender[1] = '\0'; // Null terminator to mark the end of the string
}


/* Input: The function doesn't get anything.
 * Output: The function return true or false.
 * EXP: The function gets mail form the user.
 *      The function check the following rules:
 *      - The mail is not a blank line.
 *      - The mail can contain only letter, numbers, dots, underlines, and at sign.
 *      - The mail must have at sign (@).
 *      - The mail must have a dot after the at sign.
 *      The function only return true if all the rules are true, otherwise false.    */
bool User::Set_Email() { // Add Not only @.
//    getchar();
    char email_check[MAX];
    cout << "Enter an email:" << endl;
    msg02();
    cin.getline(email_check, MAX);
    int len = int(strlen(email_check));
    if (len > EMAIL_LIM) {
        cout << "The Email is to long, please try again." << endl;
        return false;
    }
    if (Blank_Line(len))
        return false;
    int index_dot = -1, index_at_sign = -1;;
    for (int i = 0; i < len; ++i) {
        if (email_check[i] == AT_SIGN)
            index_at_sign = i;
        else if (email_check[i] == DOT)
            index_dot = i;
        else if (!Check_Let(email_check[i]) && (!Check_Number(email_check[i]) && (email_check[i] != UNDERLINE))) {
            cout << "You Entered incorrect char, please try again." << endl;
            return false;
        }
    }
    if (index_at_sign == -1) {
        cout << "There isn't at sign in the email you entered, please try again." << endl;
        return false;
    }
    if (index_dot == -1) {
        cout << "There isn't dot in the email you entered, please try again." << endl;
        return false;
    }
    if (index_dot < index_at_sign) {
        cout << "A dot cannot appear before the at sign, please try again." << endl;
        return false;
    }
    if (index_dot == len - 1) {
        cout << "An email cannot end in dot, an ending must be added, please try again." << endl;
        return false;
    }
    if(index_at_sign == 0){
        cout <<"An email cannot start with an at sign, please try again." << endl;
        return false;
    }
    if (index_dot == index_at_sign + 1){
        cout << "A dot cannot appear right after the at sigh, please try again."  <<endl;
        return false;
    }
    this->email = Set_String(email_check);
    return true;
}


bool User::Set_ID() { // Maybe add an option to checked valid ID.
//    getchar();
    char ID_check[MAX];
    cout << "Enter an ID, must be only 9 digits" << endl;
    cin.getline(ID_check, MAX);
    int len = int(strlen(ID_check));
    if (Blank_Line(len))
        return false;
    if (len != ID_LIM) {
        cout << "You enter incorrect number of digits, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (!Check_Number(ID_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    }
    this->ID = Set_String(ID_check);
    return true;
}


bool User::Set_Phone() {
    char phone_check[MAX];
    cout << "Enter your phone number:" << endl;
    msg03();
    cin.getline(phone_check, MAX);
    int len = int(strlen(phone_check));
    if (Blank_Line(len))
        return false;
    if (len != PUP_LIM) {
        cout << "You enter incorrect number of digits, please try again." << endl;
        return false;
    }
    for (int i = 0; i <len; ++i){
        if (!Check_Number(phone_check[i])) {
            cout << "You entered incorrect character, please try again." <<endl;
            return false;
        }
    }
    if (phone_check[0] != '0') {
        cout << "Your number doesn't start with 0, please try again." << endl;
        return false;
    }
    if (phone_check[1] != '5') {
        cout << "Your number doesn't start with 05, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (!Check_Number(phone_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    }
    this->phone = Set_String(phone_check);
    return true;
}


bool User::Set_Username() {
    char username_check[MAX];
    cout << "Select username:" << endl;
    msg04();
    cin.ignore();
    cin.getline(username_check, MAX);
    int len = int(strlen(username_check));
    if (Blank_Line(len))
        return false;
    if (len > PUP_LIM) {
        cout << "The username you chose is to long, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i)
        if (!Check_Let(username_check[i]) && !Check_Number(username_check[i])) {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    this->username = Set_String(username_check);
    return true;
}


bool User::Set_Password() {
    char pass_check[MAX];
    cout << "Select password:" << endl;
    msg05();
    cin.getline(pass_check, MAX);
    int len = int(strlen(pass_check));
    int upper = 0, lower = 0, num = 0;
    if (Blank_Line(len))
        return false;
    if (len > PUP_LIM || len < PASS_MIN) {
        cout << "You entered incorrect number of chars, please try again." << endl;
        return false;
    }
    for (int i = 0; i < len; ++i) {
        if (Check_Number(pass_check[i]))
            ++num;
        else if(Check_Upper(pass_check[i]))
            ++upper;
        else if (Check_Lower(pass_check[i]))
            ++lower;
        else {
            cout << "You entered incorrect char, please try again." << endl;
            return false;
        }
    }
    if (!upper || !lower || !num) {
        cout << "The password doesn't meet the requirements, please try again" << endl;
        return false;
    }
    this->password = Set_String(pass_check);
    return true;
}



bool User::Check_Date(char* str, int max, int min) {
    int len = int(strlen(str));
    if (Blank_Line(strlen(str)))
        return false;
    for (int i = 0; i < len; ++i)
        if (!Check_Number(str[i])) {
            cout << "incorrect char was entered, please try again." << endl;
            return false;
        }
    int check = stoi(str);
    if (check > max|| check <= min) {
        cout << "The number is impossible for a date, please try again." << endl;
        return false;
    }
    return true;
}


bool User::Set_Birthday() {
    char year[MAX], month[MAX], day[MAX];
    bool check;
    do {
        check = true;
        cout << "Enter the year, 1900 is the minimum and 2015 is the maximum." << endl;
        cin.getline(year, MAX);
    } while (!Check_Date(year, 2015,1899) || !check);
    do {
        cout << "Enter the number of the month:" << endl;
        cin.getline(month, MAX);
    } while (!Check_Date(month, 12, 0));
    do {
        cout << "Enter the number of the day:" << endl;
        cin.getline(day, MAX);
    } while (!Check_Date(day, 31, 0));
    int check_day = stoi(day);
    int check_month = stoi(month);
    int check_year = stoi(year);
    if (check_month != 1 && check_month != 3 && check_month != 5 && check_month != 7 && check_month != 8 &&
        check_month != 10 && check_month != 12) {
        if (check_day == 31) {
            cout << "The month doesn't have 31 days, please try again." << endl;
            return false;
        } else if (check_month == 2) {
            if (check_day > 29) {
                cout << "The month doesn't have more than 29 days, please try again." << endl;
                return false;
            }
        }
    }
    char temp[11]; // Increase array size to accommodate the null terminator
    temp[0] = Int_To_Char(check_day / 10);
    temp[1] = Int_To_Char(check_day % 10);
    temp[2] = '\\';
    temp[3] = Int_To_Char(check_month / 10);
    temp[4] = Int_To_Char(check_month % 10);
    temp[5] = '\\';
    temp[6] = Int_To_Char(check_year / 1000);
    temp[7] = Int_To_Char((check_year / 100) % 10);
    temp[8] = Int_To_Char((check_year / 10) % 10);
    temp[9] = Int_To_Char(check_year % 10);
    temp[10] = '\0'; // Null terminator to mark the end of the string
    this->birthday = new char[11];
    for (int i = 0; i < 11; ++i)
        this->birthday[i] = temp[i];
    return true;
}


bool User::Set_Address() {
    char addr[MAX];
    cout << "Enter your address, up to 30 characters:" << endl;
    msg06();
    cin.getline(addr, MAX);
    int len = int(strlen(addr));
    if (Blank_Line(len))
        return false;
    if (len > ADDRESS_LIM){
        cout << "The address is to long, please try again" << endl;
        return false;
    }
    for (int i = 0; i < len; ++i){
        if (!Check_Number(addr[i]) && !Check_Let(addr[i]) && addr[i] != SLASH && addr[i] != SPACE && addr[i] != BACKSLASH){
            cout << "Incorrect char was entered, please try again." << endl;
            return false;
        }
    }
    this->address = Set_String(addr);
    return true;
}