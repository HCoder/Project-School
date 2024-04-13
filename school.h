#pragma once


#include<string>
#include<vector>
#include"teacher.h"
#include"classroom.h"
#include"formatting.h"

using namespace std;


class school {
private:
	string password;
	string school_name;
	string school_address;
	string school_contact;
	vector<teacher> school_staff;
	vector<classroom> classroom_list;

	void update_name(string name = "undefined");
	void update_address(string address = "undefined");
	void update_contact(string contact = "undefined");
	void display_info();
	void display_staff();
	void add_teacher(string name = "", string teacher_class = "");
	void remove_teacher(size_t id);
	void display_classrooms();
	void add_classroom(string name = "", string teacher = "", string pass = "admin");
	void remove_classroom(string name = "");
	void open(string name = "");
public:

	school(string name = "undefined", string address = "underfined", string contact = "undefined" , string pass = "admin")
		: school_name(name), school_address(address), school_contact(contact) , password(pass) {};

	~school() = default;



	void start();

};
