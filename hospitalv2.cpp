#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <sstream>
//define
#define M_PASS 30
#define ATTEMP_PASS 3
#define MAX 100
//color terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
using namespace std;

struct AuthData
{
    char user[30];
    char pw[30];
}auth;

struct Decease{
    int deceaseID;
    char deceaseName[30];
}dc;

struct Patient {    
    char patientName[30];
    char doctorName[30];
    int bildingNumber;
    int diceaseID;
    int roomNumber;
    int age;
    char sex[30];
    char contactNumber[30];
    char address[30];
} pt;


class Table {
    public:
        void PatientTable();
        void LoginTable();
        void deceaseTable();
        void deceaseMenu();
        void adminTable();
};

void Table::PatientTable() {
    cout << GREEN;
    cout.fill('-');
    cout.setf(ios::left);
    cout << endl << setw(102) << "" <<endl;
    cout.fill(' ');
    cout << "| " << setw(3) << "ID"
    	 << "| " << setw(10) << "Name"
    	 << "| " << setw(10) << "Doctor"
         << "| " << setw(9) << "Bilding"
         << "| " << setw(10) << "Dicease"
         << "| " << setw(5) << "Room"
         << "| " << setw(4) << "Age"
         << "| " << setw(6) << "Sex"
         << "| " << setw(12) << "Contact"
         << "| " << setw(12) << "Address"
         << "|"
         <<endl;
    cout.fill('-');
    cout << setw(102) << "" <<endl;
    cout << RESET;
};

void Table::LoginTable() {
    cout << GREEN;
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw((30-6)/2) << "" << "Login" << setw((30-7)/2) << "" << "|" << endl;
    cout.fill('-');
    cout << setw(30) << "" << endl;
    cout << RESET;
}

void Table::deceaseTable() {
    cout << GREEN;
    cout.fill('-');
    cout << endl << setw(44) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(8) << "ID"
         << "| " << setw(17) << "Decease" 
         << "| " << setw(12) << "CreateAt"
         << "|" 
         << endl;
    cout.fill('-');
    cout << setw(44) << "" << endl;
    cout << RESET;
}

void Table::deceaseMenu() {
    cout << GREEN;
    cout.fill('-');
    cout << endl << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout.fill(' ');
    cout << "|" << setw(13) << "" << "Decease Menu" << setw(12) << "" << " |" << endl;
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(38) << "    1. Add Decease" << "|\n"
         << "|" << setw(38) << "    2. Show Decease" << "|\n"
         << "|" << setw(38) << "    3. Find Decease" << "|\n"
         << "|" << setw(38) << "    4. Update Decease" << "|\n"
         << "|" << setw(38) << "    5. Delete Deacease" << "|\n"
         << "|" << setw(38) << "    Q. Back  (->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout << RESET;
}

void Table::adminTable() {
    cout.fill('-');
    cout << GREEN;
    cout << endl << setw(31) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(13) << "Name" 
         << "| " <<  setw(13) << "Password" 
         << "|"
         << endl;
    cout.fill('-');
    cout << GREEN;
    cout << setw(31) << "" << endl;
    cout << RESET;
}

class Hospital {
    //decease data member
    private:
        char ch;
        string line;
        bool found = false;
    public:
        void getMenu();
        void showDecease();
        void addDecease();
        void updateDecease();
        void setDataPatient();
        void findDecease();
        void deleteDecease();
        string getCurrentTime();
};

string Hospital::getCurrentTime() {
    time_t times = time(0);
    struct tm *timeinfo = localtime(&times);
    char timeFormat[30];
    strftime(timeFormat, sizeof(timeFormat), "%a/%b/%Y", timeinfo);
    return string(timeFormat);
}

void Hospital::getMenu() {
    cout.fill('-');
    cout << endl << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout.fill(' ');
    cout << "|" << setw(13) << "" << "System Menu" << setw(13) << "" << " |" << endl;
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(38) << "    a. Show Decease Menu" << "|\n"
         << "|" << setw(38) << "    b. Show Patient Menu" << "|\n"
         << "|" << setw(38) << "    c. Show Doctor Menu" << "|\n"
         << "|" << setw(38) << "    d. Show Appointment Menu" << "|\n"
         << "|" << setw(38) << "    e. Show Invoice Menu" << "|\n"
         << "|" << setw(38) << "    z. Add Admin" << "|\n"
         << "|" << setw(38) << "    s. Show Admin" << "|\n"
         << "|" << setw(38) << "    f. Find Admin" << "|\n"
         << "|" << setw(38) << "    u. Update Credentails" << "|\n"
         << "|" << setw(38) << "    r. Remove Admin" << "|\n"
         << "|" << setw(38) << "    l. Logout Account" << "|\n"
         << "|" << setw(38) << "    x,q. Exite(->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
}

void Hospital::addDecease() {
    ofstream writeDecease;
    writeDecease.open("D:\\hospital\\decease.csv" , ios::app);
    cout << "\nEnter decease ID : ";
    cin >> dc.deceaseID;
    cout << "Enter decease Name: ";
    cin.ignore();
    cin.getline(dc.deceaseName , 30);
    writeDecease << dc.deceaseID << "," << dc.deceaseName << "," << getCurrentTime() << endl;
    cout << GREEN << "\n\tDecease data add to file success!" << RESET << endl;
    writeDecease.close();
}

void Hospital::showDecease() {
    ifstream readDecease;
    readDecease.open("D:\\hospital\\decease.csv");
    if(!readDecease.is_open()) {
        cout << RED << endl << "\tError: can't open file decease.csv..." << RESET << endl;
    }
    while(!readDecease.eof()) {
       getline(readDecease , line);
       stringstream ss(line);
       string IDStr , name , time;
       getline(ss , IDStr , ',');
       getline(ss , name , ',');
       getline(ss ,time , ',');
       if(!line.empty()) {
            cout.fill(' ');
            cout.setf(ios::left);
            cout << "| " << setw(8) << IDStr
                 << "| " << setw(17) << name 
                 << "| " << setw(12) << time
                 << "|" 
                 << endl;
            cout.fill('-');
            cout << setw(44) << "" << endl;
       }
    }
}

void Hospital::findDecease() {
    int fID;
    char fName[30];
    char ch;
    string line;
    Table table;
    cout << endl << "Choose option for find decease (i , n)?\nfor 'i' find by ID, 'n' find by name: ";
    ch = getch();

    if (ch == 'i' || ch == 'I') {
        ifstream readDecease("D:\\hospital\\decease.csv");
        if (!readDecease.is_open()) {
            cout << endl << RED << "Can't open file decease.csv" << RESET << endl;
            return;
        }

        cout << endl << "Enter ID for find: ";
        cin >> fID;

        bool found = false;
        while (getline(readDecease, line)) {
            stringstream ss(line);
            string IDStr, name , time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss , time , ',');

            if (!IDStr.empty() && stoi(IDStr) == fID) { 
                table.deceaseTable();
                cout.fill(' ');
                cout.setf(ios::left);
                cout << "| " << setw(8) << IDStr
                     << "| " << setw(17) << name 
                     << "| " << setw(12) << time
                     << "|" << endl;
                cout.fill('-');
                cout << setw(44) << "" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << RED << "\nID not found!" << RESET << endl;
        }
        readDecease.close();
    }
    else if (ch == 'n' || ch == 'N') {
        ifstream readDecease("D:\\hospital\\decease.csv");
        if (!readDecease.is_open()) {
            cout << endl << RED << "Can't open file decease.csv" << RESET << endl;
            return;
        }

        cout << endl << "Enter name for find: ";
        cin.ignore();
        cin.getline(fName, 30);

        bool found = false;
        while (getline(readDecease, line)) {
            stringstream ss(line);
            string IDStr, name ,time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss ,time , ',');

            if (!IDStr.empty() && strcmp(name.c_str(), fName) == 0) {
                table.deceaseTable();
                cout.fill(' ');
                cout.setf(ios::left);
                cout << "| " << setw(8) << IDStr
                     << "| " << setw(17) << name 
                     << "| " << setw(12) << time
                     << "|" << endl;
                cout.fill('-');
                cout << setw(44) << "" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << RED << "\nName not found!" << RESET << endl;
        }
        readDecease.close();
    }
    else {
        cout << RED << "\nInvalid choose..." << RESET << endl;
    }
}

void Hospital::updateDecease() {
    int newID, mID;
    char newName[30], mName[30];
    bool update = false;
    ifstream readDecease("D:\\hospital\\decease.csv");
    if (!readDecease.is_open()) {
        cout << endl << RED << "Can't open file decease.csv" << RESET << endl;
        return;
    }

    cout << endl << "Choose option for update (i , n)?\nfor 'i' update by ID, 'n' update by name: ";
    ch = getch();

    ofstream tempFile("D:\\hospital\\temp.csv");
    if (ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID to modify: ";
        cin >> mID;
        cout << "Enter new ID: ";
        cin >> newID;

        while (getline(readDecease, line)) {
            stringstream ss(line);
            string IDStr, name ,time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss ,time , ',');
            if (!IDStr.empty()) {
                int id = stoi(IDStr);
                if (id == mID) {
                    tempFile << newID << "," << name << "," << getCurrentTime() << endl;
                    update = true;
                } else {
                    tempFile << id << "," << name << "," << getCurrentTime() << endl;
                }
            }
        }
    }
    else if (ch == 'n' || ch == 'N') {
        cout << endl << "Enter name to modify: ";
        cin.seekg(0);
        cin.getline(mName , 30);
        cout << "Enter new name: ";
        cin.seekg(0);
        cin.getline(newName , 30);

        while (getline(readDecease, line)) {
            stringstream ss(line);
            string IDStr, name ,time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss , time , ',');

            if (!IDStr.empty()) {
                if (strcmp(mName , name.c_str()) == 0) {
                    tempFile << IDStr << "," << newName << ","  << getCurrentTime() << endl;
                    update = true;
                } else {
                    tempFile << IDStr << "," << name << "," << getCurrentTime() << endl;
                }
            }
        }
    }
    else {
        cout << endl << RED << "Invalid choice..." << RESET << endl;
    }

    readDecease.close();
    tempFile.close();

    if (update) {
        remove("D:\\hospital\\decease.csv");
        rename("D:\\hospital\\temp.csv", "D:\\hospital\\decease.csv");
        cout << GREEN << endl << "\tDecease updated successfully!" << RESET << endl;
    } else {
        remove("D:\\hospital\\temp.csv");
        cout << RED << endl << "\tNo matching record found." << RESET << endl;
    }
}

void Hospital::deleteDecease() {
    int dID;
    char dName[30];
    char confirm[20] = "confirm";
    char isConfrim[20];
    bool Del = false;
    bool comfirm = false;
    bool success = false;
    ifstream readDecease("D:\\hospital\\decease.csv");
    if (!readDecease.is_open()) {
        cout << endl << RED << "Can't open file decease.csv" << RESET << endl;
        return;
    }

    cout << endl << "Choose option for delete (i , n)?\nfor 'i' delete by ID, 'n' delete by name: ";
    ch = getch();

    ofstream tempFile("D:\\hospital\\temp.csv");
    if (ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID to delete: ";
        cin >> dID;

        while (getline(readDecease, line)) {
            stringstream ss(line);
            string IDStr, name , time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss , time , ',');
            

            if (!IDStr.empty() && stoi(IDStr) == dID) {
                    cout << endl << YELLOW << "Type [confirm] to delete." << endl << RESET;
                    cin.getline(isConfrim , 20);
                    if(strcmp(isConfrim , confirm) == 0){
                        Del = true;
                        success = true;
                    }else {
                        cout << endl << RED << "Error: Try again..." << RESET << endl;
                    }
            }else {
                tempFile << IDStr << "," << name << endl;
            }
        }
    }
    else if (ch == 'n' || ch == 'N') {
        cout << endl << "Enter name to delete: ";
        cin.seekg(0);
        cin.getline(dName, 30);

        while (getline(readDecease, line)) {
            stringstream ss(line);
            string IDStr, name , time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss , time , ',');

            if (!IDStr.empty()) {
                if (strcmp(dName , name.c_str()) == 0) {
                    cout << endl << YELLOW << "Type [confirm] to delete." << endl << RESET;
                    cin.getline(isConfrim , 20);
                    if(strcmp(isConfrim , confirm) == 0){
                        Del = true;
                        success = true;
                    }else {
                        cout << endl << RED << "Error: Try again..." << RESET << endl;
                    }
                } else {
                    tempFile << IDStr << "," << name << endl;
                }
            }
        }
    }
    else {
        cout << endl << RED << "Invalid choice..." << RESET << endl;
    }

    readDecease.close();
    tempFile.close();

    if (Del) {
        remove("D:\\hospital\\decease.csv");
        rename("D:\\hospital\\temp.csv", "D:\\hospital\\decease.csv");
        cout << GREEN << endl << "\tDecease delete successfully!" << RESET << endl;
    }
    if(!success) {
        remove("D:\\hospital\\temp.csv");
        cout << RED << endl << "\tNo matching record found." << RESET << endl;
    }
}

void Hospital::setDataPatient() {
    cin.ignore();
    cout << "Enter Patient Name: ";
    cin.getline(pt.patientName, 30);
    cout << "Enter Doctor Name: ";
    cin.getline(pt.doctorName, 30);
    cout << "Enter Building Number: ";
    cin >> pt.bildingNumber;
    cin.ignore();
    cout << "Enter Disease: ";
    cin >> pt.diceaseID;
    cout << "Enter Room Number: ";
    cin >> pt.roomNumber;
    cout << "Enter Age: ";
    cin >> pt.age;
    cin.ignore();
    cout << "Enter sex: ";
    cin.getline(pt.sex ,30);
    cout << "Enter Contact Number (+885): ";
    cin.getline(pt.contactNumber , 30);
    cin.ignore();
    cout << "Enter Address: ";
    cin.getline(pt.address, 100);
};

class Auth: public Hospital {
    private:
        bool success = false;
        char ch;
    public:
        int checkAdmin();
        void createPw();
        void changecredentials();
        void logoutAcc();
        void addAdmin();
        void findAdmin();
        void removeAdmin();
        void showAdmin();
        string displayHidePass(int length);
        char* inputPass();
};

char* Auth::inputPass() {
    static char password[M_PASS];
    int i = 0;
    char ch;

    cout << "Enter your password: ";

    while (true) {
        ch = getch();

        if (ch == '\r') {
            password[i] = '\0';
            break;
        }

        if (ch == '\b') {
            if (i > 0) {
                i--;
                cout << "\b \b";
            }
        }

        else {
            if (i < M_PASS - 1) {
                password[i++] = ch;
                cout << "*";
            }
        }
    }

    return password;
}

string Auth::displayHidePass(int length) {
    int i;
    string password;
    for(i =0; i <= length ; i++) {
        password.append("*");
    }
    return password;
}

int Auth::checkAdmin() {
    char oldUser[30];
    char* oldPass;
    int countPass = 0 , attempt = ATTEMP_PASS;
    //ofstream writePw;
    ifstream readPw;
    readPw.open("D:\\hospital\\password.bin" , ios::in | ios::binary);
    if(!readPw.is_open()) {
        cout << endl << RED << "\tCan't open file password.bin" << RESET << endl;
    }
    
    cout << GREEN;
    cout.fill('-');
    cout << endl << setw(53) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw((53-29)/2) << " " << "Veryfi Password and Username" << setw((53-30)/2) << " " << "|" << endl;
    cout.fill('-');
    cout << setw(53) << "" << endl;
    cout << RESET;

    for(int i = 0 ; i < attempt ; i++) {
        cout << endl << "Enter username: ";
        cin.seekg(0);
        cin.getline(oldUser , 30);
        oldPass = inputPass();

        readPw.clear();
        readPw.seekg(0, ios::beg);

        while(readPw.read((char*)&auth , sizeof(auth))) {
            if(strcmp(oldPass, auth.pw) == 0 && strcmp(auth.user, oldUser) == 0) {
                success = true;
                break;
            }
        }
        if (success) {
            cout << GREEN << endl << "\tVerify user and password success!" << RESET << endl;
            return 1;
        } else {
            cout << endl << RED << "\t\tInvalid credentials! Attempts left:" << (attempt - i -1 ) << RESET << endl;
        }
    }
    readPw.close();
    cout << RED << endl << "\tToo many attemps!" << RESET << endl;
}

void Auth::createPw() {
    ofstream writePw;
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw((30-17)/2) << "" << "First Time Login" << setw((30-17)/2) << "" << "|" << endl;
    cout.fill('-');
    cout << setw(30) << "" << endl;
    cout << "Enter username: ";
    cin.seekg(0);
    cin.getline(auth.user , 30);
    writePw.open("D:\\hospital\\password.bin" , ios::out | ios::app | ios::binary);
    if(!writePw.is_open()) {
        cout << endl << RED << "can't open file password.bin" << RESET << endl;
    }
    char* password = inputPass();
    strcpy(auth.pw , password);
    writePw.write((char*)&auth, sizeof(auth));
    writePw.close();
}

void Auth::changecredentials() {
    char newUser[30], mUser[30];
    bool success = false;
    fstream credentials("D:\\hospital\\password.bin", ios::in | ios::out | ios::binary);

    if (!credentials.is_open()) {
        cout << RED << "\n\tCan't open file password.bin" << RESET << endl;
        return;
    }

    if (checkAdmin() == 1) {
        cout << "\nEnter 'n' to change username?\n'p' to change password?";
        ch = getch();

        if (ch == 'n' || ch == 'N') {
            cout << "\nEnter current username: ";
            cin.seekg(0);
            cin.getline(mUser, 30);

            int index = 0;
            while (credentials.read((char*)&auth, sizeof(auth))) {
                if (strcmp(mUser, auth.user) == 0) {
                    cout << "\nEnter new Username: ";
                    cin.seekg(0);
                    cin.getline(newUser, 30);
                    strcpy(auth.user, newUser);
                    credentials.seekp(index * sizeof(auth), ios::beg);
                    credentials.write((char*)&auth, sizeof(auth));

                    success = true;
                    break;
                }
                index++;
            }
        } else if(ch == 'p' || ch == 'P') {
            char* newPass;
            cout << "\nEnter current username: ";
            cin.seekg(0);
            cin.getline(mUser, 30);

            int index = 0;
            while (credentials.read((char*)&auth, sizeof(auth))) {
                if (strcmp(mUser, auth.user) == 0) {
                    newPass = inputPass();
                    strcpy(auth.pw, newPass);
                    credentials.seekp(index * sizeof(auth), ios::beg);
                    credentials.write((char*)&auth, sizeof(auth));
                    success = true;
                    break;
                }
                index++;
            }
        } else {
            cout << RED << "\n\tInvalid choice!" << RESET << endl;
        }    
    } else {
        cout << RED << "\n\tCredentials incorrect!" << RESET << endl;
    }

    if (!success) {
        cout << RED << "\n\tRecord not found!" << RESET << endl;
    } else {
        cout << GREEN << "\n\tCredentials updated successfully!" << RESET << endl;
    }

    credentials.close();
}

void Auth::logoutAcc() {
    cout << endl << GREEN << "\nLogout suceess!" << RESET << endl;
}

void Auth::addAdmin() {
    ofstream writePw;
    if(checkAdmin() == 1){
        success = true;
        cout << endl << "Enter username: ";
        cin.seekg(0);
        cin.getline(auth.user , 30);
        char* password = inputPass();
        strcpy(auth.pw , password);
        writePw.open("D:\\hospital\\password.bin" ,ios::app | ios::binary);
        if(!writePw.is_open()) {
            cout << RED << endl << "Error: can't open file password" << RESET << endl;
        }
        writePw.write((char*)&auth , sizeof(auth));
    }else {
        cout << RED << endl << "Invalit password..." << RESET << endl;
    }
    writePw.close();
    if (success) cout << GREEN << endl << "\tAdmin add success!" << RESET << endl;
}

void Auth::showAdmin() {
    Table table;
    ifstream readData;
    readData.open("D:\\hospital\\password.bin" , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << RED << endl << "\tCan't open file password" << RESET << endl;
    }
    table.adminTable();
    while(readData.read((char*)&auth , sizeof(auth))) {
        cout << GREEN;
        cout.fill(' ');
        cout.setf(ios::left);
        cout << "| " << setw(13) << auth.user
             << "| " <<  setw(13) << displayHidePass(strlen(auth.pw)) 
             << "|"
             << endl;
        cout.fill('-');
        cout << GREEN;
        cout << setw(31) << "" << endl;
        cout << RESET;
    }

}

void Auth::findAdmin() {
    Table table;
    ifstream readData;
    char fName[30];
    bool found = false;
    readData.open("D:\\hospital\\password.bin" , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << RED << endl << "\tCan't open file password" << RESET << endl;
    }
    if(checkAdmin() == 1) {
        cout << endl << "Enter name for find: ";
        cin.seekg(0);
        cin.getline(fName , 30);
        while(readData.read((char*)&auth , sizeof(auth))) {
            if(strcmp(fName , auth.user) == 0) {
                found = true;
                table.adminTable();
                cout << GREEN;
                cout.fill(' ');
                cout.setf(ios::left);
                cout << "| " << setw(13) << auth.user
                    << "| " <<  setw(13) << displayHidePass(strlen(auth.pw)) 
                    << "|"
                    << endl;
                cout.fill('-');
                cout << GREEN;
                cout << setw(31) << "" << endl;
                cout << RESET;
                break;
            }
        }
        if(!found) {
            cout << RED << endl << "\tAdmin not found!" << RESET << endl;
        }
    }
    readData.close();
}

void Auth::removeAdmin() {
    ifstream readData;
    ofstream tempFile;
    char rName[30] , isConfrim[20];
    char confirm[20] = "confirm";
    bool Del = false;
    bool success = false;
    readData.open("D:\\hospital\\password.bin" , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << RED << endl << "\tCan't open file password" << RESET << endl;
    }
    if(checkAdmin() == 1) {
        cout << endl << "Enter name for delete: ";
        cin.seekg(0);
        cin.getline(rName , 30);
        tempFile.open("D:\\hospital\\temp.bin" , ios::out | ios::binary);
        while(readData.read((char*)&auth , sizeof(auth))) {
            if(strcmp(rName , auth.user) == 0) {
                cout << endl << YELLOW << "Type [confirm] to delete." << endl << RESET;
                    cin.getline(isConfrim , 20);
                    if(strcmp(isConfrim , confirm) == 0){
                        Del = true;
                        success = true;
                    }else {
                        cout << endl << RED << "Error: Try again..." << RESET << endl;
                    } 
            }else {
                tempFile.write((char*)&auth , sizeof(auth));
            }
        }
        readData.close();
        tempFile.close();
        if(Del) {
            remove("D:\\hospital\\password.bin");
            rename("D:\\hospital\\temp.bin" , "D:\\hospital\\password.bin");
            cout << GREEN << endl << "\tAdmin delete success!" << RESET << endl;
        }
        if(!success) {
            remove("D:\\hospital\\temp.bin");
            cout << RED << endl << "\tAdmin not found!" << RESET << endl;
        }
    }
}

int main() {
    //file
    ifstream readPw;
    //object
    Hospital hospital;
    Auth password;
    Table table;
    //varaible
    int attemptPass = 0;
    char* userPass;
    char choice ,choice2 , choice3 ,choice4 , userName[30];
    bool loggedIn = false;
    bool isRunning = true;
    bool found = false;
    //system runing
    while(isRunning) {
        readPw.open("D:\\hospital\\password.bin" , ios::in | ios::binary);
        if(readPw.fail()) {
            password.createPw();
        }else {
            table.LoginTable();
            cout << "Enter username: ";
            cin.seekg(0);
            cin.getline(userName , 30);

            userPass = password.inputPass();

            found = false;
            
            while (readPw.read((char*)&auth, sizeof(auth))) {
                if (strcmp(userPass , auth.pw) == 0 && strcmp(auth.user , userName) == 0) {
                    cout << GREEN << endl << "\tLogin success!" << RESET << endl;
                    cout << "\nPress any key to continue....";
                    getch();
                    loggedIn = true;
                    attemptPass = 0;
                    found = true;
                    break;
                }
            }

            if (!found) {
                attemptPass++; 
                cout << endl << endl << RED << "\tPassword incorrect!\n\tAttempts left" <<(ATTEMP_PASS - attemptPass) << RESET << endl;
                if (attemptPass >= ATTEMP_PASS) {
                    cout << RED << "\nMaximum login attempts! Exiting program." << RESET << endl;
                    return 0;
                }
            }
        }
        readPw.close();
        while(loggedIn) {
            hospital.getMenu();
            cout << endl << "Enter choice: ";
            choice = getch();
            switch(tolower(choice)) {
                case 'a':
                    do {
                        table.deceaseMenu();
                        cout << "Enter choice: ";
                        choice2 = getch();
                        switch(choice2) {
                            case '1':
                                hospital.addDecease();
                                break;
                                case '2':
                                table.deceaseTable();
                                hospital.showDecease();
                                break;
                            case '3':
                                hospital.findDecease();
                                break;
                            case '4':
                                hospital.updateDecease();
                                break;
                            case '5':
                                hospital.deleteDecease();
                                break;
                            case 'q':
                                break;
                            default: 
                                cout << RED << endl << "\n\tInvalid choice...." << RESET << endl;
                                break;
                        }
                    }while(choice2 != 'q' && choice2 != 'Q');
                    break;
                case 'b':
                    break;
                case 'c':
                    break;
                case 'd':
                    break;
                case 'e':
                    break;
                case 'z':
                    password.addAdmin();
                    break;
                case 's':
                    password.showAdmin();
                    break;
                case 'f':
                    password.findAdmin();
                    break;
                case 'u':
                    password.changecredentials();
                    break;
                case 'r':
                    password.removeAdmin();
                    break;
                case 'l':
                    password.logoutAcc();
                    loggedIn = false;
                    break;
                case 'q': case 'x':
                    exit(0);
                    break;
                default:
                    cout << RED << endl << "\tError choice please try again!" << RESET << endl;
                    break;
                }
            }
        }
    return 0;
}
