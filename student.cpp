#include"student.h"
#include<iostream>
#include<string>


using namespace std;

void student::update_name(string name) {
	student_name = name;

}

void student::decrease_roll() {
	roll_no--;
}