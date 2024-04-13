#pragma once


#include<string>
#include<vector>

using namespace std;

class student {
private:
	string student_name;
	vector<float> student_marks{ 0,0,0,0,0 };
	string student_class;
	string student_class_teacher;
	size_t roll_no; 

public:

	student(string name = "undefined", string classroom = "undefined", string teacher = "undefined" , size_t roll = -1)
		: student_name(name) , student_class(classroom) , student_class_teacher(teacher), roll_no(roll){	}

	~student() = default;

	string get_student_name(){ return student_name; }
	string get_student_class_teacher() { return student_class_teacher; }
	size_t get_roll_no() { return roll_no; }
	void update_name(string name = "undefined");
	void decrease_roll();


};