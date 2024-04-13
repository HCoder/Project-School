#include<iostream>
#include<string>
#include<vector>
#include"school.h"
#include<iomanip>
#include<conio.h>

using namespace std;

void school::update_name(string name ) {
	this->school_name = name;
}

void school::update_address(string address) {
	this->school_address = address;
}

void school::update_contact(string contact ) {
	this->school_contact = contact;
}



void school :: display_info() {

    line(100);

    cout << setw(20) << left << "Particulars*" << "|" << setw(79) << left << "Info*" << "|" << endl;
    line(100);

    cout << setw(20) << left << "School Name" << "|" << setw(79) << left << school_name << "|" << endl;
    cout << setw(20) << left << "School Address" << "|" << setw(79) << left << school_address << "|" << endl;
    cout << setw(20) << left << "School Contact" << "|" << setw(79) << left << school_contact << "|" << endl;

    line(100);
}

void school :: display_staff(){
    line(100);

    cout << left << setw(10)  << "ID" << setw(70) << left << "Teacher Name*" << "|" << setw(19) << left << "Assigned Class*" << "|" << endl;
    line(100);
        
    int i = 0;
    for (auto &teacher : school_staff) {

        cout << left << setw(10) << i + 1 << setw(70) << left << teacher.get_name() << "|" << setw(19) << left << teacher.get_assigned_class() << "|" << endl;
        i++;
    }

    line(100);
}


void school::add_teacher(string name , string teacher_class ) {

    for (auto& teacher : school_staff) {
        if (teacher.get_assigned_class() == teacher_class) {
            cout << "Can't Add Teacher!! Class Already Assigned" << endl;
            return;
        }
    }

    school_staff.push_back(teacher(name, teacher_class));

}

void school::remove_teacher(size_t id) {

    if (id < 1 || id > school_staff.size()) {
        cout << "Teacher Doesn't Exist !! Cannot Delete Teacher !!" << endl;
        return;
    }

    school_staff.erase(school_staff.begin() + (id - 1));

}

void school::display_classrooms() {

    line(100);

    cout << left << setw(20) << "Class Name" << "|" << setw(60) << left << "Class Teacher*" << "|" << setw(18) << left << "Capacity*" << "|" << endl;
    line(100);

    for (auto& classroom : classroom_list) {

        cout << left << setw(20) << classroom.get_name() << "|" << setw(60) << left << classroom.get_class_teacher() << "|" << setw(18) << left << classroom.get_capacity() << "|" << endl;
    }

    line(100);

}

void school::add_classroom(string name, string teacher, string pass) {


    for (auto& classroom : classroom_list) {
        if (classroom.get_name() == name) {
            cout << "Class Already Exists!! Cannot Add Class" << endl;
            return;
        }
        else if (classroom.get_class_teacher() == teacher) {
            cout << teacher << " is already assigned to another class" << endl;
            return;
        }
    }

    classroom_list.push_back(classroom(name, teacher, pass));
}

void school::remove_classroom(string name) {
    size_t i = 0;
    for (auto& classroom : classroom_list) {
        if (classroom.get_name() == name) {
            classroom_list.erase(classroom_list.begin() + i);
            return;
        }
        i++;
    }
    cout << "No such Classroom Found!! Cannot Remove Classroom" << endl;
}


void school::open(string name) {

    for (auto& classroom : classroom_list) {
        if (classroom.get_name() == name) {
            classroom.start();
            break;
        }
        cout << "No such Class Found!! Cannot Access Class" << endl;
    }

}

void school :: start() {

    // Check for correct Password

    cout << "ENTER SCHOOL ADMINISTRATION PASSWORD : ";

    string temp_pass = "";
    char ch;
    while ((ch = _getch()) != '\r') // Until user hits enter
    {
        temp_pass += ch;
        cout << '*';
    }
    cout << endl;

    if (temp_pass != password) {
        cout << "Wrong PassWord Access Denied!!" << endl;
        return;
    }

    else if (temp_pass == password) {
        cout << "Password Matched!! Logging You In....." << endl;
    }




    int choice;
    do {
        cout << "\n*** School Management System ***" << endl;
        cout << "1. Update School Name" << endl;
        cout << "2. Update School Address" << endl;
        cout << "3. Update School Contact" << endl;
        cout << "4. Display School Information" << endl;
        cout << "5. Display Staff Members" << endl;
        cout << "6. Add Teacher" << endl;
        cout << "7. Remove Teacher" << endl;
        cout << "8. Display Classrooms" << endl;
        cout << "9. Add Classroom" << endl;
        cout << "10. Remove Classroom" << endl;
        cout << "11. Enter Classroom" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  // Clear the input buffer

        switch (choice) {
        case 1: {
            string name;
            cout << "Enter School Name: ";
            getline(cin, name);
            update_name(name);
            break;
        }
        case 2: {
            string address;
            cout << "Enter School Address: ";
            getline(cin, address);
            update_address(address);
            break;
        }
        case 3: {
            string contact;
            cout << "Enter School Contact: ";
            getline(cin, contact);
            update_contact(contact);
            break;
        }
        case 4:
            display_info();
            break;
        case 5:
            display_staff();
            break;
        case 6: {
            string name, teacher_class;
            cout << "Enter Teacher Name: ";
            getline(cin, name);
            cout << "Enter Teacher Class: ";
            getline(cin, teacher_class);
            add_teacher(name, teacher_class);
            break;
        }
        case 7: {
            size_t id;
            cout << "Enter Teacher ID to Remove: ";
            cin >> id;
            remove_teacher(id);
            break;
        }
        case 8:
           display_classrooms();
            break;
        case 9: {
            string name, teacher, pass;
            cout << "Enter Classroom Name: ";
            getline(cin, name);
            cout << "Enter Teacher: ";
            getline(cin, teacher);
            cout << "Enter class Password : ";
            cin >> pass;
            add_classroom(name, teacher, pass);
            break;
        }
        case 10: {
            string name;
            cout << "Enter Name of the Classroom to Remove : ";
            getline(cin, name);
            remove_classroom(name);
            break;
        }
        case 11: {
            string name;
            cout << "Enter class name you want to access : ";
            getline(cin, name);
            open(name);
            break;
        }
        case 12:
            cout << "Exiting..." << endl;
            return;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (true);

}


