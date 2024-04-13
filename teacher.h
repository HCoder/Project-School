#pragma once


#include<string>


using namespace std;
class teacher {
private:

	string teacher_name;
	string assigned_class;

public:

	teacher(string name = "undefined", string teacher_class = "undefined")
		: teacher_name(name), assigned_class(teacher_class) {}

	~teacher() = default;

	string get_name() { return teacher_name; }
	string get_assigned_class() { return assigned_class; }


};