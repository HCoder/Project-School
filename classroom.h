#pragma once

#include"student.h"
#include"formatting.h"
#include<vector>
#include<string>


using namespace std;

class classroom {

private:


	string class_name;
	string class_teacher;
	vector<student> class_students;
	string password;



	void update_name(string name = "");
	void update_class_teacher(string teacher_name);
	void display_info();
	void display_students();
	void add_student(string name = "", string classroom = "", string teacher = "", size_t roll = 0);
	void remove_student(size_t roll);
	void update_student_details(size_t roll = 0, string name ="");

public:

	classroom(string name = "undefined",  string teacher = "undefined", string pass = "admin")
	: class_name(name), class_teacher(teacher), password(pass) {

	}

	~classroom() = default;

	string get_name() { return class_name; }
	string get_class_teacher() { return class_teacher; }
	size_t get_capacity() { return class_students.size(); }



	void start();


};