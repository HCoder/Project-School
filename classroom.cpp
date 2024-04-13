#include"classroom.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>


using namespace std;


void classroom::update_name(string name) {
	class_name = name;
}

void classroom::update_class_teacher(string teacher_name) {
	class_teacher = teacher_name;
}

void classroom::display_info() {


    line(100);

    cout << setw(20) << left << "Particulars*" << "|" << setw(79) << left << "Info*" << "|" << endl;
    line(100);

    cout << setw(20) << left << "Class Name" << "|" << setw(79) << left << class_name << "|" << endl;
    cout << setw(20) << left << "Class Teacher" << "|" << setw(79) << left << class_teacher << "|" << endl;
    cout << setw(20) << left << "No. Of Students" << "|" << setw(79) << left << get_capacity() << "|" << endl;

    line(100);
	
}

void classroom::display_students() {
    line(100);

    cout << left << setw(10) << "Roll no." << setw(60) << left << "Student Name*" << "|" << setw(29) << left << "Class Teacher*" << "|" << endl;
    line(100);

    int i = 0;
    for (auto& student : class_students) {

        cout << left << setw(10) << student.get_roll_no()  << setw(60) << left << student.get_student_name()  << "|" << setw(29) << left << student.get_student_class_teacher() << "|" << endl;
        i++;
    }

    line(100);
}


void classroom::add_student(string name, string classroom, string teacher, size_t roll) {
   

    class_students.push_back(student(name, classroom, teacher, roll));

}

#include <iostream>
#include <string>
using namespace std;

void classroom::start() {
    // Check for correct Password

    cout << "ENTER CLASS ADMINISTRATION PASSWORD : ";

    string temp_pass = "";
    char ch;
    while ((ch = _getch()) != '\r') // Until user hits enter
    {
        temp_pass += ch;
        cout << '*';
    }
    cout << endl;

    if (temp_pass != this->password) {
        cout << "Wrong PassWord Access Denied!!" << endl;
        return;
    }

    else if (temp_pass == this->password) {
        cout << "Password Matched!! Logging You In....." << endl;
    }


    int choice;

    do {
        cout << "\n================================\n";
        cout << "Classroom Management System\n";
        cout << "1. Display Classroom Info\n";
        cout << "2. Display All Students\n";
        cout << "3. Add Student\n";
        cout << "4. Update Student Details\n";
        cout << "5. Remove Student\n";
        cout << "6. Update Classroom Name\n";
        cout << "7. Update Classroom Teacher\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            display_info();
            break;
        }
        case 2: {
            display_students();
            break;
        }
        case 3: {
            string name;
            size_t roll;
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Roll Number: ";
            cin >> roll;
            cin.ignore();

            if (roll == 0) {
                roll = get_capacity() + 1; // Auto increment roll
            }

            add_student(name, get_name(), get_class_teacher(), roll);
            break;
        }
        case 4: {
            string name;
            size_t roll;
            cout << "Enter Roll Number to Update: ";
            cin >> roll;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);
            update_student_details(roll, name);
            break;
        }
        case 5: {
            size_t roll;
            cout << "Enter Roll Number to Remove: ";
            cin >> roll;
            cin.ignore();
            remove_student(roll);
            break;
        }
        case 6: {
            string newClassName;
            cout << "Enter New Classroom Name: ";
            getline(cin, newClassName);
            update_name(newClassName);
            break;
        }
        case 7: {
            string newTeacherName;
            cout << "Enter New Classroom Teacher: ";
            getline(cin, newTeacherName);
            update_class_teacher(newTeacherName);
            break;
        }
        case 8: {
            cout << "Exiting program...\n";
            return;
            break;
        }
        default: {
            cout << "Invalid choice! Please try again.\n";
            break;
        }
        }
    } while (true);
}


    




void classroom::update_student_details(size_t roll, string name) {
    for (auto& student : class_students) {
        if (student.get_roll_no() == roll) {
            student.update_name(name);
            return;
        }
    }
    cout << "Can't Update Details !! No Such Student found!!" << endl;

}

void classroom::remove_student(size_t roll) {

    size_t i = 0;
    for (auto& student : class_students) {
        if (student.get_roll_no() == roll) {
            class_students.erase(class_students.begin() + i);

            for (auto& student : class_students) {
                student.decrease_roll();
          }

            return;
        }
        i++;
    }
    cout << "Can't Remove Student !! No Such Student found!!" << endl;
    

}