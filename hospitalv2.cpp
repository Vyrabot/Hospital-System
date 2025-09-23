#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <sstream>
//settings
#define M_PASS 30
#define ATTEMP_PASS 3
#define MAX 100
#define DIR "D:\\hospital\\"
//color terminal
#define RESET   "\033[0m" //normal
#define RED     "\033[31m" //for danger
#define GREEN   "\033[32m" //for success
#define YELLOW  "\033[33m" //for worning
using namespace std; 

struct AuthData{
    char user[30];
    char pw[30];
}auth;

struct Dicease{
    int diceaseID;
    char diceaseName[30];
}dc;

struct Patient {
    int patientID;    
    char patientName[30];
    int bildingNumber;
    int diceaseID;
    int roomNumber;
    int age;
    char sex[30];
    char contactNumber[30];
    char address[30];
    char time[30];
} pt;

struct Doctor {
    int doctorID;
    char doctorName[30];
    char sex[10];
    char address[100];
    int specialistID;
    char contactNum[12];
    int experience;
    char time[30];
}doc;

struct Appointment {
    int appoinmentID;
    int patientID;
    int doctorID;
    char date[30];
    char time[30];
}apm;

struct Invoice {
    int invoiceID;
    int patientID;
    int price;
    char status[20];
    char date[30];
    char time[30];
}inv;

//about field table

class Table {
    public:
        void adminMenu();
        void PatientTable();
        void LoginTable();
        void diceaseTable();
        void diceaseMenu();
        void adminTable();
        void patientMenu();
        void updatePatientMenu();
        void doctorTable();
        void doctorMenu();
        void updateDoctorMenu();
        void AppointmentMenu();
        void appointmentTable();
        void updateAppointment();
        void invoiceMenu();
        void invoiceTable();
        void updateInvoice();
};

void Table::adminMenu() {
    cout.fill('-');
    cout << endl << setw(31) << "" << endl;
    cout.fill(' ');
    cout << "|" << setw((31-12)/2) << "" << " Admin Menu" << setw((31-12)/2) << "" << "|" << endl;
    cout.fill('-');
    cout << setw(31) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(28) << "    1. Add Admin" << " |" << endl
         << "|" << setw(28) << "    2. Show Admin" << " |" << endl
         << "|" << setw(28) << "    3. Find Admin" << " |" << endl
         << "|" << setw(28) << "    4. Update Credentails" << " |" << endl
         << "|" << setw(28) << "    5. Remove Admin" << " |" << endl
         << "|" << setw(28) << "    Q. Back  (->)" << " |" << endl;
    cout.fill('-');
    cout << setw(31) << "" << endl;
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

void Table::diceaseTable() {
    cout << GREEN;
    cout.fill('-');
    cout << endl << setw(44) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(8) << "ID"
         << "| " << setw(17) << "Dicease" 
         << "| " << setw(12) << "CreateAt"
         << "|" 
         << endl;
    cout.fill('-');
    cout << setw(44) << "" << endl;
    cout << RESET;
}

void Table::diceaseMenu() {
    cout.fill('-');
    cout << endl << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout.fill(' ');
    cout << "|" << setw(13) << "" << "Dicease Menu" << setw(12) << "" << " |" << endl;
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(38) << "    1. Add Dicease" << "|\n"
         << "|" << setw(38) << "    2. Show Dicease" << "|\n"
         << "|" << setw(38) << "    3. Find Dicease" << "|\n"
         << "|" << setw(38) << "    4. Update Dicease" << "|\n"
         << "|" << setw(38) << "    5. Delete Dicease" << "|\n"
         << "|" << setw(38) << "    b. Back  (->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout << RESET;
}

void Table::patientMenu() {
    cout.fill('-');
    cout << endl << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout.fill(' ');
    cout << "|" << setw(13) << "" << "Patient Menu" << setw(12) << "" << " |" << endl;
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(38) << "    1. Add Patient" << "|\n"
         << "|" << setw(38) << "    2. Show Patient" << "|\n"
         << "|" << setw(38) << "    3. Find Patient" << "|\n"
         << "|" << setw(38) << "    4. Update Patient" << "|\n"
         << "|" << setw(38) << "    5. Delete Patient" << "|\n"
         << "|" << setw(38) << "    Q. Back  (->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout << RESET;
}

void Table::updatePatientMenu() {
    cout << "Choose option for update patient: " << endl;
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout << "|" << setw((26-17)/2) << "" << "Update Patient Menu " << setw((26-18)/2) << "" << "|";
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(26) << "1. Update ID" << " |" << endl;
    cout << "| " << setw(26) << "2. Update Name" << " |" << endl;
    cout << "| " << setw(26) << "3. Update Bilding" << " |" << endl;
    cout << "| " << setw(26) << "4. Update Dicease" << " |" << endl;
    cout << "| " << setw(26) << "5. Update Room" << " |" << endl;
    cout << "| " << setw(26) << "6. Update Age" << " |" << endl;
    cout << "| " << setw(26) << "7. Update Sex" << " |" << endl;
    cout << "| " << setw(26) << "8. Update Contact" << " |" << endl;
    cout << "| " << setw(26) << "9. Update Address" << " |" << endl;
    cout << "| " << setw(26) << "b. Back (->)" << " |" << endl;
    cout.fill('-');
    cout << setw(30) << "" << endl;
    cout.fill(' ');
}

void Table::PatientTable() {
    cout << GREEN;
    cout.fill('-');
    cout.setf(ios::left);
    cout << endl << setw(104) << "" <<endl;
    cout.fill(' ');
    cout << "| " << setw(3) << "ID"
    	 << "| " << setw(10) << "Name"
         << "| " << setw(9) << "Bilding"
         << "| " << setw(10) << "Dicease"
         << "| " << setw(5) << "Room"
         << "| " << setw(4) << "Age"
         << "| " << setw(6) << "Sex"
         << "| " << setw(12) << "Contact"
         << "| " << setw(12) << "Address"
         << "| " << setw(12) << "CreateAt"
         << "|"
         <<endl;
    cout.fill('-');
    cout << setw(104) << "" <<endl;
    cout << RESET;
};

void Table::doctorMenu() {
    cout.fill('-');
    cout << endl << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout.fill(' ');
    cout << "|" << setw(13) << "" << "Doctor Menu" << setw(12) << "" << " |" << endl;
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(38) << "    1. Add Doctor" << "|\n"
         << "|" << setw(38) << "    2. Show Doctor" << "|\n"
         << "|" << setw(38) << "    3. Find Doctor" << "|\n"
         << "|" << setw(38) << "    4. Update Doctor" << "|\n"
         << "|" << setw(38) << "    5. Delete Doctor" << "|\n"
         << "|" << setw(38) << "    Q. Back  (->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
}

void Table::doctorTable() {
    cout << GREEN; 
    cout.fill('-');
    cout << endl << setw(99) << "" << endl;
    cout.fill(' ');
        cout.setf(ios::left);
        cout << "| " << setw(5) << "ID"
             << "| " << setw(10) << "Name"
             << "| " << setw(8) << "Sex"
             << "| " << setw(12) << "Contact"
             << "| " << setw(10) << "Address"
             << "| " << setw(14) << "Specialization"
             << "| " << setw(10) << "Exp(years)"
             << "| " << setw(12) << "CreateAt"
             << " |"
             << endl;
    cout.fill('-');
    cout << setw(99) << "" << endl;
    cout << RESET;
}

void Table::updateDoctorMenu() {
    cout << "Choose option for update doctor: " << endl;
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout << "|" << setw((26-17)/2) << "" << " Update Doctor Menu " << setw((26-17)/2) << "" << "|";
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(26) << "1. Update ID" << " |" << endl;
    cout << "| " << setw(26) << "2. Update Name" << " |" << endl;
    cout << "| " << setw(26) << "3. Update Sex" << " |" << endl;
    cout << "| " << setw(26) << "4. Update Address" << " |" << endl;
    cout << "| " << setw(26) << "5. Update Specailist" << " |" << endl;
    cout << "| " << setw(26) << "6. Update Contact Number" << " |" << endl;
    cout << "| " << setw(26) << "7. Update Exp" << " |" << endl;
    cout << "| " << setw(26) << "b. Back (->)" << " |" << endl;
    cout.fill('-');
    cout << setw(30) << "" << endl;
    cout.fill(' ');
}

void Table::AppointmentMenu() {
    cout.fill('-');
    cout << endl << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout.fill(' ');
    cout << "|" << setw(13) << "" << "Dicease Menu" << setw(12) << "" << " |" << endl;
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(38) << "    1. Add Appointment" << "|\n"
         << "|" << setw(38) << "    2. Show Appointment" << "|\n"
         << "|" << setw(38) << "    3. Find Appointment" << "|\n"
         << "|" << setw(38) << "    4. Update Appointment" << "|\n"
         << "|" << setw(38) << "    5. Delete Appointment" << "|\n"
         << "|" << setw(38) << "    b. Back  (->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout << RESET;
}

void Table::appointmentTable() {
    cout << GREEN;
    cout.fill('-');
    cout << endl << setw(64) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(8) << "ID"
         << "| " << setw(10) << "Patient"
         << "| " << setw(10) << "Doctor"
         << "| " << setw(12) << "Date"
         << "| " << setw(12) << "CreateAt"
         << " |" << endl;  
    cout.fill('-');
    cout << setw(64) << "" << endl;
    cout << RESET;
}

void Table::updateAppointment() {
    cout << "Choose option for update doctor: " << endl;
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout << "|" << setw((26-17)/2) << "" << " Update Appointment Menu " << setw((26-17)/2) << "" << "|";
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(26) << "1. Update ID" << " |" << endl;
    cout << "| " << setw(26) << "2. Update PatientID" << " |" << endl;
    cout << "| " << setw(26) << "3. Update DoctorID" << " |" << endl;
    cout << "| " << setw(26) << "4. Update Date" << " |" << endl;
    cout << "| " << setw(26) << "b. Back (->)" << " |" << endl;
    cout.fill('-');
    cout << setw(30) << "" << endl;
    cout.fill(' ');
}

void Table::invoiceMenu() {
    cout.fill('-');
    cout << endl << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout.fill(' ');
    cout << "|" << setw(13) << "" << "Dicease Menu" << setw(12) << "" << " |" << endl;
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "|" << setw(38) << "    1. Add Invoice" << "|\n"
         << "|" << setw(38) << "    2. Show Invoice" << "|\n"
         << "|" << setw(38) << "    3. Find Invoice" << "|\n"
         << "|" << setw(38) << "    4. Update Invoice" << "|\n"
         << "|" << setw(38) << "    5. Delete Invoice" << "|\n"
         << "|" << setw(38) << "    b. Back  (->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
    cout << RESET;
}

void Table::invoiceTable() {
    cout << GREEN;
    cout.fill('-');
    cout << endl << setw(78) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(8) << "ID"
         << "| " << setw(10) << "Patient"
         << "| " << setw(12) << "Price($)"
         << "| " << setw(10) << "Status"
         << "| " << setw(12) << "Date"
         << "| " << setw(12) << "CreateAt"
         << " |" << endl;  
    cout.fill('-');
    cout << setw(78) << "" << endl;
    cout << RESET;
}

void Table::updateInvoice() {
    cout << "Choose option for update doctor: " << endl;
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout << "|" << setw((26-17)/2) << "" << " Update Invoice Menu " << setw((26-17)/2) << "" << "|";
    cout.fill('-');
    cout << endl << setw(30) << "" << endl;
    cout.fill(' ');
    cout.setf(ios::left);
    cout << "| " << setw(26) << "1. Update ID" << " |" << endl;
    cout << "| " << setw(26) << "2. Update PatientID" << " |" << endl;
    cout << "| " << setw(26) << "3. Update Price" << " |" << endl;
    cout << "| " << setw(26) << "4. Update Status" << " |" << endl;
    cout << "| " << setw(26) << "5. Update Date expire" << " |" << endl;
    cout << "| " << setw(26) << "b. Back (->)" << " |" << endl;
    cout.fill('-');
    cout << setw(30) << "" << endl;
    cout.fill(' ');
}

class Hospital {
    private:
        char ch;
        int totalRec = 0;
        string line;
        bool found = false;
        bool success = false;
        bool Del = false;
        char credentialsFile[100];
        char diceaseFile[100] = "dicease.csv";
        char patientFile[100];
        char tempFile[100];
        char doctorFile[100];
        char appointmentFile[100];
        char invoiceFile[100];
    public:
        Hospital() {
            strcpy(credentialsFile , DIR);
            strcat(credentialsFile , "credentials.bin");
            strcpy(patientFile , DIR);
            strcat(patientFile , "patient.bin");
            strcpy(tempFile , DIR);
            strcat(tempFile, "temp.bin");
            strcpy(doctorFile , DIR);
            strcat(doctorFile , "doctor.bin");
            strcpy(appointmentFile , DIR);
            strcat(appointmentFile , "appointment.bin");
            strcpy(invoiceFile , DIR);
            strcat(invoiceFile , "invoice.bin");
        }
    public:
        //get file
        char* authFile() {
            return credentialsFile;
        }
        char* temp() {
            return tempFile;
        }
        //menu
        void getMenu();
        //dicease
        void showDicease();
        void addDicease();
        void updateDicease();
        void findDicease();
        void deleteDicease();
        //time
        string getCurrentTime();
        //patient
        void setDataPatient();
        void showDisplayPatient();
        void findPatient();
        void updatePatient();
        void deletePatient();
        //doctor
        void setDataDoctor();
        void showDisplayDoctor();
        void findDoctor();
        void updateDoctor();
        void deleteDoctor();
        //appointment
        void setDataAppointment();
        void showDisplayAppointment();
        void findAppointment();
        void updateAppointment();
        void deleteAppointment();
        //invoice
        void addInvoice();
        void showInvoice();
        void findInvoice();
        void updateInvoice();
        void deleteInvoice();
};

//get real time method

string Hospital::getCurrentTime() {
    time_t times = time(0);
    struct tm *timeinfo = localtime(&times);
    char timeFormat[30];
    strftime(timeFormat, sizeof(timeFormat), "%a/%b/%Y", timeinfo);
    return string(timeFormat);
}

//main menu about system

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
    cout << "|" << setw(38) << "    a. Show Dicease Menu" << "|\n"
         << "|" << setw(38) << "    b. Show Patient Menu" << "|\n"
         << "|" << setw(38) << "    c. Show Doctor Menu" << "|\n"
         << "|" << setw(38) << "    d. Show Appointment Menu" << "|\n"
         << "|" << setw(38) << "    e. Show Invoice Menu" << "|\n"
         << "|" << setw(38) << "    f. Show Admin Menu" << "|\n"
         << "|" << setw(38) << "    l. Logout Account" << "|\n"
         << "|" << setw(38) << "    q. Exite(->)" << "|\n";
    cout.fill('-');
    cout << setw(40) << "" << endl;
}

//about dicease method

void Hospital::addDicease() {
    int totalRec = 0 , i;
    ofstream writeDicease;
    writeDicease.open(diceaseFile , ios::app);  
    cout << endl << "How many records you want to add? ";
    cin >> totalRec;
    for(i = 0 ; i < totalRec ; i++) {
        cout << endl << "Record: " << (i+1) << endl;
        cout << "Enter dicease ID : ";
        cin >> dc.diceaseID;
        cout << "Enter dicease Name: ";
        cin.seekg(0);
        cin.getline(dc.diceaseName , 30);
        writeDicease << dc.diceaseID << "," << dc.diceaseName << "," << getCurrentTime() << endl;
    }
    cout << GREEN << "\n\tDicease data add to file success!" << RESET << endl;
    writeDicease.close();
}

void Hospital::showDicease() {
    ifstream readDicease;
    readDicease.open(diceaseFile);
    if(!readDicease.is_open()) {
        cout << RED << endl << "\tError: can't open file dicease.csv..." << RESET << endl;
    }
    while(!readDicease.eof()) {
       getline(readDicease , line);
       stringstream ss(line);
       string IDStr , name , time;
       getline(ss , IDStr , ',');
       getline(ss , name , ',');
       getline(ss ,time , ',');
       if(!line.empty()) {
            cout << GREEN;
            cout.fill(' ');
            cout.setf(ios::left);
            cout << "| " << setw(8) << IDStr
                 << "| " << setw(17) << name 
                 << "| " << setw(12) << time
                 << "|" 
                 << endl;
            cout.fill('-');
            cout << setw(44) << "" << endl;
            cout << RESET;
       }
    }
}

void Hospital::findDicease() {
    int fID;
    char fName[30];
    Table table;
    cout << endl << "Choose option for find dicease (i , n)?\nfor 'i' find by ID, 'n' find by name: ";
    ch = getch();

    if (ch == 'i' || ch == 'I') {
        ifstream readDicease(diceaseFile);
        if (!readDicease.is_open()) {
            cout << endl << RED << "Can't open file dicease.csv" << RESET << endl;
            return;
        }

        cout << endl << "Enter ID for find: ";
        cin >> fID;

        bool found = false;
        while (getline(readDicease, line)) {
            stringstream ss(line);
            string IDStr, name , time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss , time , ',');

            if (!IDStr.empty() && stoi(IDStr) == fID) { 
                table.diceaseTable();
                cout << GREEN;
                cout.fill(' ');
                cout.setf(ios::left);
                cout << "| " << setw(8) << IDStr
                     << "| " << setw(17) << name 
                     << "| " << setw(12) << time
                     << "|" << endl;
                cout.fill('-');
                cout << setw(44) << "" << endl;
                cout << RESET;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << RED << "\nID not found!" << RESET << endl;
        }
        readDicease.close();
    }
    else if (ch == 'n' || ch == 'N') {
        ifstream readDicease(diceaseFile);
        if (!readDicease.is_open()) {
            cout << endl << RED << "Can't open file dicease.csv" << RESET << endl;
            return;
        }

        cout << endl << "Enter name for find: ";
        cin.ignore();
        cin.getline(fName, 30);

        bool found = false;
        while (getline(readDicease, line)) {
            stringstream ss(line);
            string IDStr, name ,time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss ,time , ',');

            if (!IDStr.empty() && strcmp(name.c_str(), fName) == 0) {
                table.diceaseTable();
                cout << GREEN;
                cout.fill(' ');
                cout.setf(ios::left);
                cout << "| " << setw(8) << IDStr
                     << "| " << setw(17) << name 
                     << "| " << setw(12) << time
                     << "|" << endl;
                cout.fill('-');
                cout << setw(44) << "" << endl;
                cout << RESET;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << RED << "\nName not found!" << RESET << endl;
        }
        readDicease.close();
    }
    else {
        cout << RED << "\nInvalid choose..." << RESET << endl;
    }
}

void Hospital::updateDicease() {
    int newID, mID;
    char newName[30], mName[30];
    bool update = false;
    ifstream readDicease(diceaseFile);
    if (!readDicease.is_open()) {
        cout << endl << RED << "Can't open file dicease.csv" << RESET << endl;
        return;
    }

    cout << endl << "Choose option for update (i , n)?\nfor 'i' update by ID, 'n' update by name: ";
    ch = getch();

    ofstream tempFile(temp());
    if (ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID to modify: ";
        cin >> mID;
        cout << "Enter new ID: ";
        cin >> newID;

        while (getline(readDicease, line)) {
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

        while (getline(readDicease, line)) {
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

    readDicease.close();
    tempFile.close();

    if (update) {
        remove(diceaseFile);
        rename(temp(), diceaseFile);
        cout << GREEN << endl << "\tDicease updated successfully!" << RESET << endl;
    } else {
        remove(temp());
        cout << RED << endl << "\tNo matching record found." << RESET << endl;
    }
}

void Hospital::deleteDicease() {
    int dID;
    char dName[30];
    char confirm[20] = "confirm";
    char isConfrim[20];
    ifstream readDicease(diceaseFile);
    if (!readDicease.is_open()) {
        cout << endl << RED << "Can't open file dicease.csv" << RESET << endl;
        return;
    }

    cout << "Choose option for delete (i , n)?\nfor 'i' delete by ID, 'n' delete by name: ";
    ch = getch();

    ofstream tempData;
    tempData.open(tempFile);
    if(!tempData.is_open()) {
        cout << RED << endl << "\tFile can't open!" << RESET << endl;
    }
    if (ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID to delete: ";
        cin >> dID;

        while (getline(readDicease, line)) {
            stringstream ss(line);
            int ID;
            string IDStr, name , time;
            getline(ss, IDStr, ',');
            ID = stoi(IDStr);
            getline(ss, name, ',');
            getline(ss, time , ',');
            

            if (!IDStr.empty() && ID != dID) {
                tempData << IDStr << "," << name << "," << time << endl;
            }else {
                cout << endl << YELLOW << "Type [confirm] to delete." << endl << RESET;
                cin.seekg(0);
                cin.getline(isConfrim , 20);
                if(strcmp(isConfrim , confirm) == 0){
                    Del = true;
                    success = true;
                }else {
                    cout << endl << RED << "Error: Try again..." << RESET << endl;
                    Del = false;
                    success = false;
                    break;
                }
            }
        }
    }
    else if (ch == 'n' || ch == 'N') {
        cout << endl << "Enter name to delete: ";
        cin.seekg(0);
        cin.getline(dName, 30);

        while (getline(readDicease, line)) {
            stringstream ss(line);
            string IDStr, name , time;
            getline(ss, IDStr, ',');
            getline(ss, name, ',');
            getline(ss , time , ',');

            if (!IDStr.empty()) {
                if (strcmp(dName , name.c_str()) == 0) {
                    cout << endl << YELLOW << "Type [confirm] to delete." << endl << RESET;
                    cin.seekg(0);
                    cin.getline(isConfrim , 20);
                    if(strcmp(isConfrim , confirm) == 0){
                        Del = true;
                        success = true;
                    }else {
                        Del = false;
                        success = false;
                        cout << endl << RED << "Error: Try again..." << RESET << endl;
                    }
                } else {
                    tempData << IDStr << "," << name << "," << time << endl;
                }
            }
        }
    }
    else {
        cout << endl << RED << "Invalid choice..." << RESET << endl;
    }

    readDicease.close();
    tempData.close();

    if (Del) {
        remove(diceaseFile);
        rename(tempFile, diceaseFile);
        cout << GREEN << endl << "\tDicease delete successfully!" << RESET << endl;
    }
    if(!success) {
        remove(tempFile);
        cout << RED << endl << "\tNo matching record found." << RESET << endl;
    }
}

//about patient method

void Hospital::setDataPatient() {
    int i;
    Patient pt[MAX];
    ofstream writeData;
    cout << endl << "How many records you want to add? ";
    cin >> totalRec;
    writeData.open(patientFile , ios::out | ios::app | ios::binary);
    if(!writeData.is_open()) {
        cout << RED << endl << "Can't open file patient.bin" << RESET;
    }
    for(i = 0 ; i < totalRec ; i++) {
        cout << endl << "Record: " << (i+1) << endl;
        cout << "Enter Patient ID : ";
        cin >> pt[i].patientID;
        cout << "Enter Patient Name: ";
        cin.seekg(0);
        cin.getline(pt[i].patientName, 30);
        cout << "Enter Building Number: ";
        cin >> pt[i].bildingNumber;
        cout << "Enter Disease ID: ";
        cin >> pt[i].diceaseID;
        cout << "Enter Room Number: ";
        cin >> pt[i].roomNumber;
        cout << "Enter Age: ";
        cin >> pt[i].age;
        cout << "Enter sex: ";
        cin.seekg(0);
        cin.getline(pt[i].sex ,30);
        cout << "Enter Contact Number (+884): ";
        cin.seekg(0);
        cin.getline(pt[i].contactNumber , 30);
        cout << "Enter Address: ";
        cin.seekg(0);
        cin.getline(pt[i].address, 100);
        strcpy(pt[i].time , getCurrentTime().c_str());
        writeData.write((char*)&pt[i] , sizeof(pt[i]));
    }
    cout << GREEN << "\n\tPatient data add to file success!" << RESET << endl;
    writeData.close();
};

void Hospital::showDisplayPatient() {
    ifstream readData(patientFile, ios::in | ios::binary);
    ifstream readDicease(diceaseFile);
    int deceaseIDs[MAX];
    string deceaseNames[MAX];
    int count = 0 , i;

    if(!readData.is_open() || !readDicease.is_open()) {
        cout << RED << endl << "\tError: can't open file!" << RESET << endl;
    }

    while(getline(readDicease , line)) {
        stringstream ss(line);
        string temp;

        getline(ss , temp, ',');
        deceaseIDs[count] = stoi(temp);

        getline(ss , temp, ',');
        deceaseNames[count] = temp;
        count++;
    }
    readDicease.close();

    Table table;
    table.PatientTable();
    string decease;
    while(readData.read((char*)&pt , sizeof(pt))) {
        cout << GREEN;
        cout.setf(ios::left);
        for(i = 0 ; i <= count ; i++) {
            if(deceaseIDs[i] == pt.diceaseID) {
                decease = deceaseNames[i];
                break;
            }else {
                decease = "N/A";
            }
        }
        cout.fill(' ');
        cout << "| " << setw(3) << pt.patientID
            << "| " << setw(10) << pt.patientName
            << "| " << setw(9) << pt.bildingNumber
            << "| " << setw(10) << decease
            << "| " << setw(5) << pt.roomNumber
            << "| " << setw(4) << pt.age
            << "| " << setw(6) << pt.sex
            << "| " << setw(12) << pt.sex
            << "| " << setw(12) << pt.address
            << "| " << setw(12) << pt.time
            << "|"
            <<endl;
        cout.fill('-');
        cout << setw(104) << "" <<endl;
        cout << RESET;
    }

    readData.close();
}

void Hospital::findPatient() {
    ifstream readData;
    ifstream readDicease(diceaseFile);
    Table table;
    int fID;
    int i;
    char fName[30];
    int deceaseIDs[MAX];
    string deceaseNames[MAX] , decease;
    int count = 0;
    readData.open(patientFile , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "\tCan't open file patient.bin" << RESET << endl;
    }
    cout << endl << "Choose option for find patient (i , n)?\nfor 'i' find by ID, 'n' find by name: ";
    ch = getch();
    string line;
    while(getline(readDicease , line)) {
        stringstream ss(line);
        string temp;

        getline(ss , temp, ',');
        deceaseIDs[count] = stoi(temp);

        getline(ss , temp, ',');
        deceaseNames[count] = temp;
        count++;
    }
    readDicease.close();

    if(ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID for find: ";
        cin >> fID;
        found = false;
        while(readData.read((char*)&pt , sizeof(pt))) {
            if(fID == pt.patientID) {
                found = true;
                for(i = 0 ; i <= count ; i++) {
                    if(deceaseIDs[i] == pt.diceaseID) {
                        decease = deceaseNames[i];
                        break;
                    }else {
                        decease = "N/A";
                    }
                }
                table.PatientTable();
                cout << GREEN;
                cout.setf(ios::left);
                cout.fill(' ');
                cout << "| " << setw(3) << pt.patientID
                     << "| " << setw(10) << pt.patientName
                     << "| " << setw(9) << pt.bildingNumber
                     << "| " << setw(10) << decease
                     << "| " << setw(5) << pt.roomNumber
                     << "| " << setw(4) << pt.age
                     << "| " << setw(6) << pt.sex
                     << "| " << setw(12) << pt.contactNumber
                     << "| " << setw(12) << pt.address
                     << "| " << setw(12) << pt.time
                     << "|"
                     << endl;
                    cout.fill('-');
                    cout << setw(104) << "" <<endl;
                    cout << RESET;
                    break;
            }
        }
    }else if(ch == 'n' || ch == 'N') {
        cout << endl << "Enter patient name for find: ";
        cin.seekg(0);
        cin.getline(fName , 30);
        found = false;
        while(readData.read((char*)&pt , sizeof(pt))) {
            if(strcmp(fName , pt.patientName) == 0) {
                found = true;
                    for(i = 0 ; i <= count ; i++) {
                    if(deceaseIDs[i] == pt.diceaseID) {
                        decease = deceaseNames[i];
                        break;
                        }else {
                            decease = "N/A";
                        }
                    }
                    table.PatientTable();
                    cout << GREEN;
                    cout.setf(ios::left);
                    cout.fill(' ');
                    cout << "| " << setw(3) << pt.patientID
                        << "| " << setw(10) << pt.patientName
                        << "| " << setw(9) << pt.bildingNumber
                        << "| " << setw(10) << decease
                        << "| " << setw(5) << pt.roomNumber
                        << "| " << setw(4) << pt.age
                        << "| " << setw(6) << pt.sex
                        << "| " << setw(12) << pt.contactNumber
                        << "| " << setw(12) << pt.address
                        << "| " << setw(12) << pt.time
                        << "|"
                        <<endl;
                    cout.fill('-');
                    cout << setw(104) << "" <<endl;
                    cout << RESET;
                    break;
            }
        }
    }
    readData.close();
    if(!found) {
        cout << endl << RED << "\tRecord not found!" << RESET << endl;
    }
}

void Hospital::updatePatient() {
    int mID , newID , i;
    char newName[30], mName[30];
    char newDoctor[30];
    int newBilding ,newDicease ,newRoom, newAge , mBuilding;
    char newSex[30] ,newContact[30] ,newAddress[30];
    Patient pts[MAX];
    int index = 0;
    Table table;
    fstream readData;
    readData.open(patientFile , ios::in | ios::out | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "\tCan't open file patient.bin" << RESET << endl;
        return;
    }
    do {
        table.updatePatientMenu();
        cout << "Enter choice: "; 
        ch = getch();
        switch(ch) {
            case '1':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                readData.clear();
                readData.seekg(0, ios::beg);
                index = 0;
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new ID: ";
                        cin.seekg(0);
                        cin.getline(newSex , 30);
                        pts[index].patientID = newID;
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '2':
                cout << endl << "Enter name dicease for modify: ";
                cin.seekg(0);
                cin.getline(mName , 30);
                cin.clear();
                cin.seekg(0, ios::beg);
                index = 0;
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(strcmp(mName , pts[index].patientName) == 0) {
                        found = true;
                        success = true;
                        cout << "Enter new name: ";
                        cin.seekg(0);
                        cin.getline(newName , 30);
                        strcpy(pts[index].patientName , newName);
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '3':
                cout << endl << "Enter ID for modify bilding numbe: ";
                cin >> mID;
                index = 0;
                cin.clear();
                cin.seekg(0 , ios::beg);
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new bilding number: ";
                        cin >> newBilding;
                        pts[index].bildingNumber = newBilding;
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '4':
                cout << endl << "Enter ID for monify dicease ID: ";
                cin >> mID;
                cin.clear();
                cin.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new dicease ID: ";
                        cin >> newDicease;
                        pts[index].diceaseID = newDicease;
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                        break;
                    } else {
                        found = false;
                        success = false;                    
                    }
                    index++;
                }
                break;
            case '5':
                cout << endl << "Enter ID for modify room number: ";
                cin >> mID;
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new room number: ";
                        cin >> newRoom;
                        pts[index].roomNumber = newRoom;
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                        break;
                    } else {
                        found = false;
                        success = false;                    
                    }
                    index++;
                }
                break;
            case '6':
                cout << endl << "Enter ID for modify age: ";
                cin >> mID;
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new age: ";
                        cin >> newAge;
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                        break;
                    } else {
                        found = false;
                        success = false;                    
                    }
                    index++;
                }
                break;
            case '7':
                cout << endl << "Enter ID for modify sex: ";
                cin >> mID;
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new sex: ";
                        cin.seekg(0);
                        cin.getline(newSex , 30);
                        strcpy(pts[index].sex , newSex);
                        readData.seekp(index * sizeof(Patient) , ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                        break;
                    } else { 
                        found = false;
                        success = false;                    
                    }
                    index++;
                }
                break;
            case '8':
                cout << endl << "Enter ID for modify contact number: ";
                cin >> mID;
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                readData.clear();
                readData.seekg(0 , ios::beg);
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new contact number: ";
                        cin.seekg(0);
                        cin.getline(newContact , 30);
                        strcpy(pts[index].contactNumber , newContact);
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                    } else {
                        found = false;
                        success = false;                    
                    }
                    index++;
                }
                break;
            case '9':
                cout << endl << "Enter ID for modify address: ";
                cin >> mID;
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&pts[index] , sizeof(pts[index]))) {
                    if(mID == pts[index].patientID) {
                        found = true;
                        success = true;
                        cout << "Enter new address: ";
                        cin.seekg(0);
                        cin.getline(newAddress , 100);
                        strcpy(pts[index].address , newAddress);
                        readData.seekp(index * sizeof(Patient), ios::beg);
                        readData.write((char*)&pts[index] , sizeof(pts[index]));
                    } else {
                        found = false;
                        success = false;                    
                    }
                    index++;
                }
                break;
            case 'q': case 'Q':
                break;
            default: 
                cout << RED << "\nInvalid choice..." << RESET << endl;
                break;
        }
        if(success) {
            cout << GREEN << endl << "\tPatient updated successfully!" << RESET << endl;
        }
        if(!found) {
            cout << endl << RED << "\tRecord not found!" << RESET << endl;
        }
    }while(ch != 'q' && ch != 'Q');
    readData.close();
}

void Hospital::deletePatient() {
    int dID;
    char dName[30];
    char confirm[20] = "confirm" , isConfirm[20];
    ifstream readData;
    ofstream tempData;
    found = false;
    cout << "\tChoose option for delete patient (i , n)?\nfor 'i' delete by ID, 'n' delete by name: ";
    ch = getch();
    readData.open(patientFile , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "\tCan't open file patient.bin" << RESET << endl;
        return;
    }
    tempData.open(tempFile , ios::out | ios::binary);
        if(!tempData.is_open()) {
            cout << endl << RED << "\tCan't open file temp.bin" << RESET << endl;
            return;
        }
    if(ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID to delete: ";
        cin >> dID;
        while(readData.read((char*)&pt , sizeof(pt))) {
            if(dID == pt.patientID) {
                found = true;
                cout << YELLOW << "Type [confirm] to delete." << RESET << endl;
                cin.seekg(0);
                cin.getline(isConfirm , 20);
                if(strcmp(isConfirm , confirm) == 0) {
                    Del = true;
                } else {
                    cout << endl << RED << "\tError: Try again..." << RESET << endl;
                    tempData.write((char*)&pt , sizeof(pt));
                }
            } else {
                tempData.write((char*)&pt , sizeof(pt));
            }
        }
    } else if(ch == 'n' || ch == 'N') {
        cout << endl << "Enter name to delete: ";
        cin.seekg(0);
        cin.getline(dName , 30);
        while(readData.read((char*)&pt , sizeof(pt))) {
            if(strcmp(dName , pt.patientName) == 0) {
                found = true;
                cout << YELLOW << "Type [confirm] to delete." << RESET << endl;
                cin.seekg(0);
                cin.getline(isConfirm , 20);
                if(strcmp(isConfirm , confirm) == 0) {
                    Del = true;
                } else {
                    cout << endl << RED << "\tError: Try again..." << RESET << endl;
                    tempData.write((char*)&pt , sizeof(pt));
                }
            } else {
                tempData.write((char*)&pt , sizeof(pt));
            }
        }
    } else {
        cout << endl << RED << "\tInvalid choice..." << RESET << endl;
    }

    readData.close();
    tempData.close();

    if(Del) {
        remove(patientFile);
        rename(tempFile , patientFile);
        cout << GREEN << endl << "\tPatient delete successfully!" << RESET << endl;
    }else {
        remove(tempFile);
        if(!found) {
            cout << endl << RED << "\tNo matching record found." << RESET << endl;
        }
    }

}

//about doctor method

void Hospital::setDataDoctor() {
    int i;
    Doctor docs[MAX];
    ofstream writeData;
    cout << endl << "How many records you want to add? ";
    cin >> totalRec;
    writeData.open(doctorFile , ios::out | ios::app | ios::binary);
    if(!writeData.is_open()) {
        cout << RED << endl << "Can't open file patient.bin" << RESET;
    }
    for(i = 0 ; i < totalRec ; i++) {
        cout << endl << "Record: " << (i+1) << endl;
        cout << "Enter doctor ID: ";
        cin >> docs[i].doctorID;
        cout << "Enter doctor Name: ";
        cin.seekg(0);
        cin.getline(docs[i].doctorName, 30);
        cout << "Enter doctor sex: ";
        cin.seekg(0);
        cin.getline(docs[i].sex , 10);
        cout << "Enter doctor contact number (+884): ";
        cin.seekg(0);
        cin.getline(docs[i].contactNum , 12);
        cout << "Enter doctor address: ";
        cin.seekg(0);
        cin.getline(docs[i].address, 100);
        cout << "Enter specialist ID: ";
        cin >> docs[i].specialistID;
        cout << "Enter experience year: ";
        cin >> docs[i].experience;
        strcpy(docs[i].time , getCurrentTime().c_str());
        writeData.write((char*)&docs[i] , sizeof(docs[i]));
    }
    cout << GREEN << "\n\tDoctor data add to file success!" << RESET << endl;
    writeData.close();
}

void Hospital::showDisplayDoctor() {
    ifstream readData;
    readData.open(doctorFile , ios::in | ios::binary);
    ifstream readDecease;
    readDecease.open(diceaseFile);
    int deceaseIDs[MAX];
    string deceaseNames[MAX];
    int count = 0 ,i;
    if(!readData.is_open()) {
        cout << RED << endl << "\tError: can't open file doctor.bin..." << RESET << endl;
    }
    
    string line;
    while(getline(readDecease , line)) {
        stringstream ss(line);
        string temp;

        getline(ss , temp, ',');
        deceaseIDs[count] = stoi(temp);

        getline(ss , temp, ',');
        deceaseNames[count] = temp;
        count++;
    }
    readDecease.close(); 
    Table table;
    table.doctorTable();
    string decease;
    while(readData.read((char*)&doc , sizeof(doc))) {
        cout << GREEN;
        cout.fill(' ');
        cout.setf(ios::left);
        for(i = 0 ; i <= count ; i++) {
            if(deceaseIDs[i] == doc.specialistID) {
                decease = deceaseNames[i];
                break;
            }else {
                decease = "N/A";
            }
        }
        cout << "| " << setw(5) << doc.doctorID
            << "| " << setw(10) << doc.doctorName
            << "| " << setw(8) << doc.sex
            << "| " << setw(12) << doc.contactNum
            << "| " << setw(10) << doc.address
            << "| " << setw(14) << decease
            << "| " << setw(10) << doc.experience
            << "| " << setw(10) << doc.time
            << " |"
            << endl;
        cout.fill('-');
        cout << setw(99) << "" << endl;
        cout << RESET;
    }
    readData.close();
}

void Hospital::findDoctor() {
    ifstream readData;
    Table table;
    int i , fID;
    char fName[30];
    readData.open(doctorFile , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "\tCan't open file doctor.bin" << RESET << endl;
    }
    cout << endl << "Choose option for find doctor (i , n)?\nfor 'i' find by ID, 'n' find by name: ";
    ch = getch();
    if(ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID for find: ";
        cin >> fID;
        found = false;
        while(readData.read((char*)&doc , sizeof(doc))) {
            if(fID == doc.doctorID) {
                found = true;
                table.doctorTable();
                cout << GREEN;
                cout.fill(' ');
                cout.setf(ios::left);
                cout << "| " << setw(5) << doc.doctorID
                    << "| " << setw(10) << doc.doctorName
                    << "| " << setw(8) << doc.sex
                    << "| " << setw(12) << doc.contactNum
                    << "| " << setw(10) << doc.address
                    << "| " << setw(14) << doc.specialistID
                    << "| " << setw(10) << doc.experience
                    << "| " << setw(10) << doc.time
                    << " |"
                    << endl;
                cout.fill('-');
                cout << setw(99) << "" << endl;
                cout << RESET;
                break;
            }
        }
    }else if(ch == 'n' || ch == 'N') {
        cout << endl << "Enter doctor name for find: ";
        cin.seekg(0);
        cin.getline(fName , 30);
        found = false;
        while(readData.read((char*)&doc , sizeof(doc))) {
            if(strcmp(fName , doc.doctorName) == 0) {
                found = true;
                table.doctorTable();
                cout << GREEN;
                cout.fill(' ');
                cout.setf(ios::left);
                cout << "| " << setw(5) << doc.doctorID
                    << "| " << setw(10) << doc.doctorName
                    << "| " << setw(8) << doc.sex
                    << "| " << setw(12) << doc.contactNum
                    << "| " << setw(10) << doc.address
                    << "| " << setw(14) << doc.specialistID
                    << "| " << setw(10) << doc.experience
                    << "| " << setw(10) << doc.time
                    << " |"
                    << endl;
                cout.fill('-');
                cout << setw(99) << "" << endl;
                cout << RESET;
                break;
            }
        }
    }
    readData.close();
    if(!found) {
        cout << endl << RED << "\tRecord not found!" << RESET << endl;
    }
}

void Hospital::updateDoctor() {
    int  i, mID , newID , newSID , newExp;
    int index = 0;
    char newDName[30] , mDName[30] , newSex[30] , newAddress[30] , newContactNum[30];
    Doctor docs[MAX];
    Table table;
    fstream readData;
     readData.open(doctorFile , ios::in | ios::out | ios::binary);
    if(!readData.is_open()) {
        cout << RED << endl << "\tCan't open file doctor.bin" << RESET << endl;
    }
    do {
        table.updateDoctorMenu();
        cout << endl << "Enter choice: ";
        ch = getch();
        switch(ch) {
            case '1':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                readData.clear();
                readData.seekg(0, ios::beg);
                index = 0;
                while(readData.read((char*)&docs[index] , sizeof(docs[index]))) {
                    if(mID == docs[index].doctorID) {
                        found = true;
                        success = true;
                        cout << "Enter new ID: ";
                        cin >> newID;
                        docs[index].doctorID = newID;
                        readData.seekp(index * sizeof(Doctor), ios::beg);
                        readData.write((char*)&docs[index] , sizeof(docs[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '2':
                cout << endl << "Enter name doctor for modify: ";
                cin.seekg(0);
                cin.getline(mDName , 30);
                index = 0;
                readData.clear();
                readData.seekg(0 , ios::beg);
                while(readData.read((char*)&docs[index] , sizeof(docs[index]))) {
                    if(strcmp(docs[index].doctorName , mDName) == 0) {
                        found = true;
                        success = true;
                        cout << "Enter new doctor name: ";
                        cin.seekg(0);
                        cin.getline(newDName , 30);
                        strcpy(docs[index].doctorName , newDName);
                        readData.seekp(index * sizeof(Doctor) , ios::beg);
                        readData.write((char*)&docs[index] , sizeof(docs[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '3':
                cout << endl << "Enter name doctor for modify: ";
                cin.seekg(0);
                cin.getline(mDName , 30);
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&docs[index] , sizeof(docs[index]))) {
                    if(strcmp(docs[index].doctorName , mDName) == 0) {
                        found = true;
                        success = true;
                        cout << "Enter new sex: ";
                        cin.seekg(0);
                        cin.getline(newSex , 30);
                        strcpy(docs[index].sex , newSex);
                        readData.seekp(index * sizeof(Doctor) ,ios::beg);
                        readData.write((char*)&docs[index] , sizeof(docs[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '4':
                cout << endl << "Enter name doctor for modify: ";
                cin.seekg(0);
                cin.getline(mDName , 30);
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&docs[index] , sizeof(docs[index]))) {
                    if(strcmp(docs[index].doctorName , mDName) == 0) {
                        found = true;
                        success = true;
                        cout << "Enter new addresss: ";
                        cin.seekg(0);
                        cin.getline(newAddress, 30);
                        strcpy(docs[index].address , newAddress);
                        readData.seekp(index * sizeof(Doctor) , ios::beg);
                        readData.write((char*)&docs[index] , sizeof(docs[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '5':
               cout << endl << "Enter name doctor for modify: ";
                cin.seekg(0);
                cin.getline(mDName , 30);
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&docs[index] , sizeof(docs[index]))) {
                    if(strcmp(docs[index].doctorName , mDName) == 0) {
                        found = true;
                        success = true;
                        cout << "Enter new specialist ID: ";
                        cin >> newSID;
                        docs[index].specialistID = newSID;
                        readData.seekp(index * sizeof(Doctor) , ios::beg);
                        readData.write((char*)&docs[index] , sizeof(docs[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '6': 
                cout << endl << "Enter name doctor for modify: ";
                cin.seekg(0);
                cin.getline(mDName , 30);
                readData.clear();
                readData.seekg(0  , ios::beg);
                index = 0;
                while(readData.read((char*)&docs[index] , sizeof(docs[index]))) {
                    if(strcmp(docs[index].doctorName , mDName) == 0) {
                        found = true;
                        success = true;
                        cout << "Enter new contact number: ";
                        cin.seekg(0);
                        cin.getline(newContactNum , 30);
                        strcpy(docs[index].contactNum , newContactNum);
                        readData.seekp(index * sizeof(Doctor) , ios::beg);
                        readData.write((char*)&docs[index] , sizeof(docs[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '7':
                cout << endl << "Enter name doctor for modify: ";
                cin.seekg(0);
                cin.getline(mDName , 30);
                readData.clear();
                readData.seekg(0 , ios::beg);
                index = 0;
                while(readData.read((char*)&docs[index] , sizeof(docs[index]))) {
                    if(strcmp(docs[index].doctorName , mDName) == 0) {
                        found = true;
                        success = true;
                        cout << "Enter new experience: ";
                        cin >> newExp;
                        docs[index].experience = newExp;
                        readData.seekp(index * sizeof(Doctor) , ios::beg);
                        readData.write((char*)&docs[index] , sizeof(docs[index]));
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case 'q':
                break;
            default:
                cout << RED << "\nInvalid choice..." << RESET << endl;  
                break;
        }
        if(success) {
            cout << GREEN << endl << "\tDoctor updated successfully!" << RESET << endl;
        }
        if(!found) {
            cout << endl << RED << "\tRecord not found!" << RESET << endl;
        }
    }while(ch != 'q' && ch != 'Q');
    readData.close();
}

void Hospital::deleteDoctor() {
    int dID;
    char dName[30];
    char confirm[20] = "confirm" , isConfirm[20];
    ifstream readData;
    ofstream tempData;
    cout << endl << "Choose option for delete doctor (i , n)?\nfor 'i' delete by ID, 'n' delete by name: ";
    ch = getch();
    readData.open(doctorFile , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "\tCan't open file patient.bin" << RESET << endl;
        return;
    }
    tempData.open(tempFile , ios::out | ios::binary);
        if(!tempData.is_open()) {
            cout << endl << RED << "\tCan't open file temp.bin" << RESET << endl;
            return;
        }
    if(ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID to delete: ";
        cin >> dID;
        while(readData.read((char*)&doc , sizeof(doc))) {
            if(dID == doc.doctorID) {
                found = true;
                cout << YELLOW << "Type [confirm] to delete." << RESET << endl;
                cin.seekg(0);
                cin.getline(isConfirm , 20);
                if(strcmp(isConfirm , confirm) == 0) {
                    Del = true;
                } else {
                    cout << endl << RED << "\tError: Try again..." << RESET << endl;
                    tempData.write((char*)&doc , sizeof(doc));
                }
            } else {
                tempData.write((char*)&doc , sizeof(doc));
            }
        }
    } else if(ch == 'n' || ch == 'N') {
        cout << endl << "Enter name to delete: ";
        cin.seekg(0);
        cin.getline(dName , 30);
        while(readData.read((char*)&doc , sizeof(doc))) {
            if(strcmp(dName , doc.doctorName) == 0) {
                found = true;
                cout << YELLOW << "Type [confirm] to delete." << RESET << endl;
                cin.seekg(0);
                cin.getline(isConfirm , 20);
                if(strcmp(isConfirm , confirm) == 0) {
                    Del = true;
                } else {
                    cout << endl << RED << "\tError: Try again..." << RESET << endl;
                    tempData.write((char*)&doc , sizeof(doc));
                }
            } else {
                tempData.write((char*)&doc , sizeof(doc));
            }
        }
    } else {
        cout << endl << RED << "\tInvalid choice..." << RESET << endl;
    }

    readData.close();
    tempData.close();

    if(Del) {
        remove(doctorFile);
        rename(tempFile , doctorFile);
        cout << GREEN << endl << "\tPatient delete successfully!" << RESET << endl;
    }else {
        remove(tempFile);
        if(!found) {
            cout << endl << RED << "\tNo matching record found." << RESET << endl;
        }
    } 
}

//about appointment method

void Hospital::setDataAppointment() {
    int i;
    ofstream writeData;
    writeData.open(appointmentFile , ios::out | ios::app | ios::binary);
    if(!writeData.is_open()) {
        cout << RED << endl << "\tCan't open file appointment.bin" << RESET << endl;
    }
    totalRec = 0;
    cout << endl << "How many records you want to add? ";
    cin >> totalRec;
    for(i = 0; i < totalRec ; i++) {
        cout << "Enter appointment ID: ";
        cin >> apm.appoinmentID;
        cout << "Enter patient ID: ";
        cin >> apm.patientID;
        cout << "Enter doctor ID: ";
        cin >> apm.doctorID;
        cout << "Enter date with patient: ";
        cin.seekg(0);
        cin.getline(apm.date , 30);
        strcpy(apm.time , getCurrentTime().c_str());
        writeData.write((char*)&apm , sizeof(apm));
    }
    cout << GREEN << endl << "Appointment data add to file success!" << RESET << endl;
}

void Hospital::findAppointment() {
    ifstream readData;
    Table table;
    int fID;
    char fName[30];
    readData.open(appointmentFile , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "\tCan't open file doctor.bin" << RESET << endl;
    }
    cout << endl << "Enter ID for find: ";
    cin >> fID;
    found = false;
    while(readData.read((char*)&apm , sizeof(apm))) {
        if(fID == apm.appoinmentID) {
            found = true;
            table.appointmentTable();
            cout << GREEN;
            cout.fill(' ');
            cout.setf(ios::left);
            cout << "| " << setw(8) << apm.appoinmentID
                 << "| " << setw(10) << apm.patientID
                 << "| " << setw(10) << apm.doctorID
                 << "| " << setw(12) << apm.date
                 << "| " << setw(12) << apm.time
                 << " |" << endl;  
            cout.fill('-');
            cout << setw(64) << "" << endl;
            cout << RESET;
        }
    }
    readData.close();
    if(!found) {
        cout << endl << RED << "\tRecord not found!" << RESET << endl;
    }
}

void Hospital::showDisplayAppointment() {
    Table table;
    int patientID[MAX], doctorID[MAX], pCount = 0, dCount = 0;
    string patientNames[MAX], doctorNames[MAX];
    string patientName, doctorName;

    // --- Read Patients ---
    ifstream readPatient(patientFile, ios::in | ios::binary);
    if(!readPatient.is_open()) {
        cout << RED << "\tCan't open patient file !" << RESET << endl;
        return;
    }
    while(readPatient.read((char*)&pt, sizeof(pt))) {
        patientID[pCount] = pt.patientID;
        patientNames[pCount] = pt.patientName;
        pCount++;
    }
    readPatient.close();
    ifstream readDoctor(doctorFile, ios::in | ios::binary);
    if(!readDoctor.is_open()) {
        cout << RED << "\tCan't open doctor file !" << RESET << endl;
        return;
    }
    while(readDoctor.read((char*)&doc, sizeof(doc))) {
        doctorID[dCount] = doc.doctorID;
        doctorNames[dCount] = doc.doctorName;
        dCount++;
    }
    readDoctor.close();
    ifstream readAppointment(appointmentFile, ios::in | ios::binary);
    if(!readAppointment.is_open()) {
        cout << RED << "\tCan't open appointment file !" << RESET << endl;
        return;
    }

    table.appointmentTable();

    while(readAppointment.read((char*)&apm, sizeof(apm))) {
        cout << GREEN;
        cout.fill(' ');
        cout.setf(ios::left);
        patientName = "N/A";
        for(int i = 0; i < pCount; i++) {
            if(apm.patientID == patientID[i]) {
                patientName = patientNames[i];
                break;
            }
        }
        doctorName = "N/A";
        for(int i = 0; i < dCount; i++) {
            if(apm.doctorID == doctorID[i]) {
                doctorName = doctorNames[i];
                break;
            }
        }
        cout << "| " << setw(8) << apm.appoinmentID
             << "| " << setw(10) << patientName
             << "| " << setw(10) << doctorName
             << "| " << setw(12) << apm.date
             << "| " << setw(12) << apm.time
             << " |" << endl;

        cout.fill('-');
        cout << setw(64) << "" << endl;
        cout << RESET;
    }
    readAppointment.close();
}

void Hospital::updateAppointment() {
    int  i, mID , newID , newSID , newExp;
    int index = 0;
    char newDate[30];
    Appointment apms[MAX];
    Table table;
    fstream fileData;
     fileData.open(appointmentFile , ios::in | ios::out | ios::binary);
    if(!fileData.is_open()) {
        cout << RED << endl << "\tCan't open file doctor.bin" << RESET << endl;
    }
    do {
        table.updateAppointment();
        cout << endl << "Enter choice: ";
        ch = getch();
        switch(ch) {
            case '1':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0, ios::beg);
                index = 0;
                while(fileData.read((char*)&apms[index] , sizeof(apms[index]))) {
                    if(mID == apms[index].appoinmentID) {
                        found = true;
                        cout << "Enter new appointment ID: ";
                        cin >> newID;
                        apms[index].appoinmentID = newID;
                        fileData.seekp(index * sizeof(Appointment), ios::beg);
                        fileData.write((char*)&apms[index] , sizeof(apms[index]));
                        success = true;
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '2':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0 , ios::beg);
                index = 0;
                while(fileData.read((char*)&apms[index] , sizeof(apms[index]))) {
                    if(mID == apms[index].appoinmentID) {
                        found = true;
                        cout << "Enter new patient ID for modify: ";
                        cin >> newID;
                        apms[index].patientID = newID;
                        fileData.seekp(index * sizeof(Appointment) , ios::beg);
                        fileData.write((char*)&apms[index] , sizeof(apms[index]));
                        success = true;
                        break;
                    }
                    index++;
                }
                break;
            case '3':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0 , ios::beg);
                index = 0;
                while(fileData.read((char*)&apms[index] , sizeof(apms[index]))) {
                    if(mID == apms[index].appoinmentID) {
                        found = true;
                        cout << "Enter new doctor ID for modify: ";
                        cin >> newID;
                        apms[index].doctorID = newID;
                        fileData.seekp(index * sizeof(Appointment) , ios::beg);
                        fileData.write((char*)&apms[index] , sizeof(apms[index]));
                        success = true;
                        break;
                    }else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '4':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0 , ios::beg);
                index = 0;
                while(fileData.read((char*)&apms[index] , sizeof(apms[index]))) {
                    if(mID == apms[index].appoinmentID) {
                        found = true;
                        cout << "Enter new date time for modify: ";
                        cin.seekg(0);
                        cin.getline(newDate , 30);
                        strcpy(apms[index].date , newDate);
                        fileData.seekp(index * sizeof(Appointment) , ios::beg);
                        fileData.write((char*)&apms[index] , sizeof(apms[index]));
                        success = true;
                        break;
                    }
                    index++;
                }
                break;
            case 'q':
                break;
            default:
                cout << RED << "\nInvalid choice..." << RESET << endl;  
                break;
        }
        if(success) {
            cout << GREEN << endl << "\tDoctor updated successfully!" << RESET << endl;
        }
        if(!found) {
            cout << endl << RED << "\tRecord not found!" << RESET << endl;
        }
    }while(ch != 'q' && ch != 'Q');
    fileData.close();
}

void Hospital::deleteAppointment() {
    int dID;
    char confirm[20] = "confirm" , isConfirm[20];
    ifstream readData;
    ofstream tempData;
    cout << "\nChoose option for delete appointment (i)\nfor delete by ID? ";
    ch = getch();
    readData.open(appointmentFile , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "\tCan't open file patient.bin" << RESET << endl;
    }
    tempData.open(tempFile , ios::out | ios::binary);
    if(!tempData.is_open()) {
        cout << endl << RED << "\tCan't open file temp.bin" << RESET << endl;
    }
    if(ch == 'i' || ch == 'I') {
        cout << endl << "Enter ID to delete: ";
        cin >> dID;
        while(readData.read((char*)&apm , sizeof(apm))) {
            if(dID == apm.appoinmentID) {
                found = true;
                cout << YELLOW << "Type [confirm] to delete." << RESET << endl;
                cin.seekg(0);
                cin.getline(isConfirm , 20);
                if(strcmp(isConfirm , confirm) == 0) {
                    Del = true;
                } else {
                    cout << endl << RED << "\tError: Try again..." << RESET << endl;
                    tempData.write((char*)&apm , sizeof(apm));
                }
            } else {
                tempData.write((char*)&apm , sizeof(apm));
            }
        }
    } else {
        cout << endl << RED << "\tInvalid choice..." << RESET << endl;
    }

    readData.close();
    tempData.close();

    if(Del) {
        remove(appointmentFile);
        rename(tempFile , appointmentFile);
        cout << GREEN << endl << "\tPatient delete successfully!" << RESET << endl;
    }else {
        remove(tempFile);
        if(!found) {
            cout << endl << RED << "\tNo matching record found." << RESET << endl;
        }
    }
}

//about invoice method

void Hospital::addInvoice() {
    int i ,totalInvoice , iStatus;
    string status;
    ofstream readData;
    readData.open(invoiceFile, ios::out | ios::app | ios::binary);
    if(!readData.is_open()) {
        cout << endl << RED << "Can't open file invoice.bin" << RESET << endl;
    }
    cout << endl << "How many invoice you want to add? ";
    cin >> totalInvoice;
    for(i = 0 ; i < totalInvoice ; i++) {
        cout << endl << "Enter invoice ID: ";
        cin >> inv.invoiceID;
        cout << "Enter patient ID: ";
        cin >> inv.patientID;
        cout << "Enter price: ";
        cin >> inv.price;
        cout << "Enter status (1/0)? \n '1' for paid , '0' for unpaid: ";
        cin >> iStatus;
        if(iStatus == 0) {
            status = "unpaid";
            strcpy(inv.status , status.c_str());
        }else if(iStatus == 1) {
            status = "paid";
            strcpy(inv.status , status.c_str());
        }else {
            cout << RED << endl << "Error: please try again..." << RESET << endl;
            continue;
        }
        cout << "Enter invoice date time expire: ";
        cin.seekg(0);
        cin.getline(inv.date , 30);
        strcpy(inv.time , getCurrentTime().c_str());
        readData.write((char*)&inv , sizeof(inv));
    }
    cout << GREEN << endl << "\tInvoice add to file success!" << RESET << endl;
    readData.close();
}

void Hospital::showInvoice() {
    ifstream readData;
    ifstream readPatient;
    Table table;
    int i , count = 0 , patientID[MAX];
    string patientNames[MAX] , patient;
    readData.open(invoiceFile , ios::in | ios::binary);
    readPatient.open(patientFile , ios::in | ios::binary);
    if(!readData.is_open() || !readPatient.is_open()) {
        cout << RED << endl << "Can't open file invoice.bin" << RESET << endl;
    }
    while(readPatient.read((char*)&pt , sizeof(pt))) {
        patientNames[count] = pt.patientName;
        patientID[count] = pt.patientID;
        count++;
    }
    table.invoiceTable();
    while(readData.read((char*)&inv , sizeof(inv))) {
        for(i = 0 ; i <= count ; i++) {
            if(patientID[i] == inv.patientID) {
                patient = patientNames[i];
                break;
            }else {
                patient = "N/A";
            }
        }
        cout << GREEN;
        cout.fill(' ');
        cout.setf(ios::left);
        cout << "| " << setw(8) << inv.invoiceID
            << "| " << setw(10) << patient
            << "| " << setw(12) << inv.price
            << "| " << setw(10) << inv.status
            << "| " << setw(12) << inv.date
            << "| " << setw(12) << inv.time
            << " |" << endl;  
        cout.fill('-');
        cout << setw(78) << "" << endl;
        cout << RESET;
    }
    readData.close();
}

void Hospital::findInvoice() {
    ifstream readData;
    ifstream readPatient;
    Table table;
    int i , count = 0 , patientID[MAX] , fInvoice;
    string patientNames[MAX] , patient;
    readData.open(invoiceFile , ios::in | ios::binary);
    readPatient.open(patientFile , ios::in | ios::binary);
    if(!readData.is_open() || !readPatient.is_open()) {
        cout << RED << endl << "Can't open file invoice.bin" << RESET << endl;
    }
    while(readPatient.read((char*)&pt , sizeof(pt))) {
        patientNames[count] = pt.patientName;
        patientID[count] = pt.patientID;
        count++;
    }
    found = false;
    cout << endl << "Enter ID for find Invoice: ";
    cin >> fInvoice;
    table.invoiceTable();
    while(readData.read((char*)&inv , sizeof(inv))) {
            if(fInvoice == inv.invoiceID) {
                for(i = 0 ; i <= count ; i++) {
                if(patientID[i] == inv.patientID) {
                    patient = patientNames[i];
                    break;
                }else {
                    patient = "N/A";
                }
            }
            cout << GREEN;
            cout.fill(' ');
            cout.setf(ios::left);
            cout << "| " << setw(8) << inv.invoiceID
                << "| " << setw(10) << patient
                << "| " << setw(12) << inv.price
                << "| " << setw(10) << inv.status
                << "| " << setw(12) << inv.date
                << "| " << setw(12) << inv.time
                << " |" << endl;  
            cout.fill('-');
            cout << setw(78) << "" << endl;
            cout << RESET;
            found = true;
        break;
        }
    }
    if(!found) cout << RED << endl << "\tRecord not found!" << RESET << endl;
    readData.close();
}

void Hospital::updateInvoice() {
    int  i, mID , newID , newPrice , checkStatus;
    string status;
    int index = 0;
    char newDate[30];
    Invoice inv[MAX];
    Table table;
    fstream fileData;
     fileData.open(invoiceFile , ios::in | ios::out | ios::binary);
    if(!fileData.is_open()) {
        cout << RED << endl << "\tCan't open file doctor.bin" << RESET << endl;
    }
    do {
        table.updateInvoice();
        cout << endl << "Enter choice: ";
        ch = getch();
        switch(ch) {
            case '1':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0, ios::beg);
                index = 0;
                while(fileData.read((char*)&inv[index] , sizeof(inv[index]))) {
                    if(mID == inv[index].invoiceID) {
                        found = true;
                        cout << "Enter new invoice ID: ";
                        cin >> newID;
                        inv[index].invoiceID = newID;
                        fileData.seekp(index * sizeof(Invoice), ios::beg);
                        fileData.write((char*)&inv[index] , sizeof(inv[index]));
                        success = true;
                        break;
                    } else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '2':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0 , ios::beg);
                index = 0;
                while(fileData.read((char*)&inv[index] , sizeof(inv[index]))) {
                    if(mID == inv[index].invoiceID) {
                        found = true;
                        cout << "Enter new patient ID for modify: ";
                        cin >> newID;
                        inv[index].patientID = newID;
                        fileData.seekp(index * sizeof(Invoice) , ios::beg);
                        fileData.write((char*)&inv[index] , sizeof(inv[index]));
                        success = true;
                        break;
                    }else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '3':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0 , ios::beg);
                index = 0;
                while(fileData.read((char*)&inv[index] , sizeof(inv[index]))) {
                    if(mID == inv[index].invoiceID) {
                        found = true;
                        cout << "Enter new price for modify: ";
                        cin >> newPrice;
                        inv[index].price = newPrice;
                        fileData.seekp(index * sizeof(Invoice) , ios::beg);
                        fileData.write((char*)&inv[index] , sizeof(inv[index]));
                        success = true;
                        break;
                    }else {
                        found = false;
                        success = false;
                    }
                    index++;
                }
                break;
            case '4':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0 , ios::beg);
                index = 0;
                while(fileData.read((char*)&inv[index] , sizeof(inv[index]))) {
                    if(mID == inv[index].invoiceID) {
                        found = true;
                        cout << "Enter new status for modify (1/0)?\n'1' for paid, '0' unpaid?";
                        cin >> checkStatus;
                        if(checkStatus == 1) {
                            status = "paid";
                        }else if(checkStatus == 0) {
                            status = "unpaid";
                        }else {
                            cout << RED << endl << "\tError: try again...." << RESET << endl;
                        }
                        strcpy(inv[index].status , status.c_str());
                        fileData.seekp(index * sizeof(Invoice) , ios::beg);
                        fileData.write((char*)&inv[index] , sizeof(inv[index]));
                        success = true;
                        break;
                    }
                    index++;
                }
                break;
            case '5':
                cout << endl << "Enter ID for modify: ";
                cin >> mID;
                fileData.clear();
                fileData.seekg(0 , ios::beg);
                index = 0;
                while(fileData.read((char*)&inv[index] , sizeof(inv[index]))) {
                    if(mID == inv[index].invoiceID) {
                        found = true;
                        cout << "Enter new date time expire for modify: ";
                        cin.seekg(0);
                        cin.getline(newDate , 30);
                        strcpy(inv[index].date , newDate);
                        fileData.seekp(index * sizeof(Invoice) , ios::beg);
                        fileData.write((char*)&inv[index] , sizeof(inv[index]));
                        success = true;
                        break;
                    }
                    index++;
                }
                break;
            case 'q':
                break;
            default:
                cout << RED << "\nInvalid choice..." << RESET << endl;  
                break;
        }
        if(success) {
            cout << GREEN << endl << "\tDoctor updated successfully!" << RESET << endl;
        }
        if(!found) {
            cout << endl << RED << "\tRecord not found!" << RESET << endl;
        }
    }while(ch != 'q' && ch != 'Q');
    fileData.close();
}

void Hospital::deleteInvoice() {
    int dInvoice;
    char confirm[20] = "confirm" , isConfirm[20];
    ifstream readData;
    ofstream temp;
    temp.open(tempFile , ios::out | ios::binary);
    readData.open(invoiceFile , ios::in | ios::binary);
    if(!readData.is_open() || !temp.is_open()) {
        cout << RED << endl << "Can't open file invoice.bin" << endl << RESET;
    }
    cout << endl << "Enter ID for delete invoice: ";
    cin >> dInvoice;
    while(readData.read((char*)&inv , sizeof(inv))) {
        if(dInvoice == inv.invoiceID) {
            found = true;
            cout << YELLOW << "Type [confirm] to delete." << RESET << endl;
            cin.seekg(0);
            cin.getline(isConfirm , 20);
            if(strcmp(isConfirm , confirm) == 0) {
                Del = true;
            } else {
                cout << endl << RED << "\tError: Try again..." << RESET << endl;
                temp.write((char*)&inv , sizeof(inv));
            }
        }else {
            temp.write((char*)&inv , sizeof(inv));
        }
    }
    if(Del) {
        remove(invoiceFile);
        rename(tempFile , invoiceFile);
        cout << GREEN << endl << "\tPatient delete successfully!" << RESET << endl;
    }else {
        remove(tempFile);
        if(!found) {
            cout << endl << RED << "\tNo matching record found." << RESET << endl;
        }
    }
}

//about authentication system

class Auth: public Hospital {
    private:
        bool success = false;
        char ch;
        int totalAcc = 0;
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
    for(i =0; i < length ; i++) {
        password.append("*");
    }
    return password;
}

int Auth::checkAdmin() {
    char oldUser[30];
    char* oldPass;
    int countPass = 0 , attempt = ATTEMP_PASS;
    ifstream readPw;
    readPw.open(authFile() , ios::in | ios::binary);
    if(!readPw.is_open()) {
        cout << endl << RED << "\tCan't open file credentails.bin" << RESET << endl;
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
        bool match = false;
        cout << endl << "Enter username: ";
        cin.seekg(0);
        cin.getline(oldUser , 30);
        oldPass = inputPass();

        readPw.clear();
        readPw.seekg(0 , ios::beg);

        while(readPw.read((char*)&auth , sizeof(auth))) {
            if(strcmp(oldPass, auth.pw) == 0 && strcmp(auth.user, oldUser) == 0) {
                match = true;
                break;
            }
        }
        if (match) {
            cout << GREEN << endl << "\tVerify user and password success!" << RESET << endl;
            readPw.close();
            return 1;
        } else {
            int left = attempt - i - 1;
            cout << endl << RED << "\t\tInvalid credentials! Attempts left:" << left << RESET << endl;
            if(left == 0) break;
        }
    }
    readPw.close();
    cout << RED << endl << "\tToo many attemps!" << RESET << endl;
    return 0;
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
    writePw.open(authFile() , ios::out | ios::app | ios::binary);
    if(!writePw.is_open()) {
        cout << endl << RED << "can't open file credentials.bin" << RESET << endl;
    }
    char* password = inputPass();
    strcpy(auth.pw , password);
    writePw.write((char*)&auth, sizeof(auth));
    writePw.close();
}

void Auth::changecredentials() {
    char newUser[30], mUser[30];
    success = false;
    fstream credentials(authFile() , ios::in | ios::out | ios::binary);

    if (!credentials.is_open()) {
        cout << RED << "\n\tCan't open file credentials.bin" << RESET << endl;
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
        writePw.open(authFile() ,ios::app | ios::binary);
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
    int i;
    if(checkAdmin() == 1) {
        readData.open(authFile() , ios::in | ios::binary);
        if(!readData.is_open()) {
            cout << RED << endl << "\tCan't open file password" << RESET << endl;
        }
        table.adminTable();
        while(readData.read((char*)&auth , sizeof(auth))) {
            totalAcc++;
            cout << GREEN;
            cout.fill(' ');
            cout.setf(ios::left);
            cout << "| " << setw(13) << auth.user
                 << "| " << setw(13) << displayHidePass(strlen(auth.pw)) 
                 << "|"
                 << endl;
            cout.fill('-');
            cout << GREEN;
            cout << setw(31) << "" << endl;
            cout << RESET;
        }
        cout << endl << "\tTotal account: " << GREEN << totalAcc << RESET << endl;
        totalAcc = 0;
        readData.close();
    }

}

void Auth::findAdmin() {
    Table table;
    ifstream readData;
    char fName[30];
    bool found = false;
    readData.open(authFile() , ios::in | ios::binary);
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
    success = false;
    readData.open(authFile() , ios::in | ios::binary);
    if(!readData.is_open()) {
        cout << RED << endl << "\tCan't open file password" << RESET << endl;
    }
    if(checkAdmin() == 1) {
        cout << endl << "Enter name for delete: ";
        cin.seekg(0);
        cin.getline(rName , 30);
        tempFile.open(temp() , ios::out | ios::binary);
        while(readData.read((char*)&auth , sizeof(auth))) {
            if(strcmp(rName , auth.user) == 0) {
                success = true;
                cout << endl << YELLOW << "Type [confirm] to delete." << endl << RESET;
                cin.getline(isConfrim , 20);
                if(strcmp(isConfrim , confirm) == 0){
                    Del = true;
                }else {
                    cout << endl << RED << "Error: Try again..." << RESET << endl;
                    tempFile.write((char*)&auth , sizeof(auth));
                } 
            }else {
                tempFile.write((char*)&auth , sizeof(auth));
            }
        }
        readData.close();
        tempFile.close();
        if(Del) {
            remove(authFile());
            rename(temp() , authFile());
            cout << GREEN << endl << "\tAdmin delete success!" << RESET << endl;
        }
        if(!success) {
            remove(temp());
            cout << RED << endl << "\tAdmin not found!" << RESET << endl;
        }
    }
}

int main() {
    ifstream readPw;
    Hospital hospital;
    Auth credentials;
    Table table;
    int attemptPass = 0;
    char* userPass;
    char choice ,choice2 , choice3 ,choice4 , choice5 , choice6 , choice7 , userName[30];
    char shutdown[4];
    char isShutdown[4] = "yes"; 
    bool loggedIn = false;
    bool isRunning = true;
    bool found = false;
    char dirFile[100];
    //system runing
    while(isRunning) {
        strcpy(dirFile , DIR);
        strcat(dirFile , "credentials.bin");
        readPw.open(dirFile , ios::in | ios::binary);
        if(readPw.fail()) {
            credentials.createPw();
        }else {
            table.LoginTable();
            cout << "Enter username: ";
            cin.seekg(0);
            cin.getline(userName , 30);

            userPass = credentials.inputPass();

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
                        table.diceaseMenu();
                        cout << "Enter choice: ";
                        choice2 = getch();
                        switch(choice2) {
                            case '1':
                                hospital.addDicease();
                                break;
                                case '2':
                                table.diceaseTable();
                                hospital.showDicease();
                                break;
                            case '3':
                                hospital.findDicease();
                                break;
                            case '4':
                                hospital.updateDicease();
                                break;
                            case '5':
                                hospital.deleteDicease();
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
                    do {
                        table.patientMenu();
                        cout << "Enter choice: ";
                        choice3 = getch(); 
                        switch(choice3) {
                            case '1':
                                hospital.setDataPatient();
                                break;
                            case '2':
                                hospital.showDisplayPatient();
                                break;
                            case '3':
                                hospital.findPatient();
                                break;
                            case '4':
                                hospital.updatePatient();
                                break;
                            case '5':
                                hospital.deletePatient();
                                break;
                            case 'q':
                                break;
                            default:
                                cout << RED << endl << "\tError choice please try again!" << RESET << endl;
                                break;
                        }
                    }while(choice3 != 'q' && choice3 != 'Q');
                    break;
                case 'c':
                    do {
                        table.doctorMenu();
                        cout << "Enter choice: ";
                        choice4 = getch();
                        switch(choice4) {
                            case '1':
                                hospital.setDataDoctor();
                                break;
                            case '2':
                                hospital.showDisplayDoctor();
                                break;
                            case '3':
                                hospital.findDoctor();
                                break;
                            case '4':
                                hospital.updateDoctor();
                                break;
                            case '5':
                                hospital.deleteDoctor();
                                break;
                            case 'q':
                                break;
                            default:
                                cout << RED << endl << "\tError choice please try again!" << RESET << endl;
                                break;
                        }
                    }while(choice4 != 'q' && choice4 != 'Q');
                    break;
                case 'd':
                    do {
                        table.AppointmentMenu();
                        cout << "Enter choice: ";
                        choice5 = getch();
                        switch(choice5) {
                            case '1':
                                hospital.setDataAppointment();
                                break;
                            case '2':
                                hospital.showDisplayAppointment();
                                break;
                            case '3':
                                hospital.findAppointment();
                                break;
                            case '4':
                                hospital.updateAppointment();
                                break;
                            case '5':
                                hospital.deleteAppointment();
                                break;
                            case 'q':
                                break;
                            default:
                                cout << RED << endl << "\tError choice please try again!" << RESET << endl;
                        }
                    }while(choice5 != 'q' && choice5 != 'Q');
                    break;
                case 'e':
                    do {
                        table.invoiceMenu();
                        cout << "Enter choice: ";
                        choice6 = getch();
                        switch(choice6) {
                            case '1':
                                hospital.addInvoice();
                                break;
                            case '2':
                                hospital.showInvoice();
                                break;
                            case '3':
                                hospital.findInvoice();
                                break;
                            case '4':
                                hospital.updateInvoice();
                                break;
                            case '5':
                                hospital.deleteInvoice();
                                break;
                            case 'q': case 'Q':
                                break;
                            default:
                                cout << RED << endl << "Invlid choice!" << endl << RESET;
                                break;
                        }
                    }while(choice6 != 'q' && choice6 != 'Q');
                    break;
                case 'f':
                    do {
                        table.adminMenu();
                        cout << "Enter choice: ";
                        choice7 = getch();
                        switch(choice7) {
                            case '1':
                                credentials.addAdmin();
                                break;
                            case '2':
                                credentials.showAdmin();
                                break;
                            case '3':
                                credentials.findAdmin();
                                break;
                            case '4':
                                credentials.changecredentials();
                                break;
                            case '5':
                                credentials.removeAdmin();
                                break;
                            case 'q': case 'Q':
                                break;
                            default:
                                cout << RED << endl << "\tInvalid choice please try again!" << RESET << endl;
                                break;
                        }
                    }while(choice7 != 'q' && choice7 != 'Q');
                    break;
                case 'l':
                    credentials.logoutAcc();
                    loggedIn = false;
                    break;
                case 'q':
                    cout << YELLOW << endl << "\tAre you sure to shutdown?\nType [yes] for shutdown....." << RESET << endl;
                    cin.seekg(0 , ios::beg);
                    cin.getline(shutdown , 4);
                    if(strcmp(shutdown , isShutdown) == 0) {
                        exit(0);
                    }else {
                        cout << RED << endl << "\tYou didn't shutdown!" << RESET << endl;
                    }
                    break;
                default:
                    cout << RED << endl << "\tError choice please try again!" << RESET << endl;
                    break;
                }
            }
        }
    return 0;
}
