# Project-School
The school management software is a comprehensive solution designed to streamline administrative tasks within educational institutions. Built using C++, the software offers functionalities to manage student and teacher data across various classrooms and provides an organized interface for school administration. Features include adding and removing students, updating classroom details, and managing teachers. With password-protected access at both the school and classroom levels, it ensures data security. This software is ideal for schools looking to digitize and simplify their administrative processes.


# Key Features
# Password-Protected Access

#School-Level Security: The software requires a password for administrative access to the entire school system.
#Classroom-Level Security: Passwords are also implemented for individual classrooms to ensure data privacy and security.

# Classroom Management
Display Classroom Info: Allows administrators to view the name, teacher, and student count of each classroom.
Add and Remove Classrooms: Administrators can add new classrooms and remove existing ones.
Update Classroom Details: Enables the modification of classroom names and assigned teachers.

# Student Management
Add and Remove Students: Facilitates the addition and removal of students from a classroom.
Update Student Details: Allows for the modification of student names and other details.
Display All Students: Provides a list of all students in a classroom, including their roll numbers and class teacher.

# Teacher Management
Add and Remove Teachers: Allows the addition and removal of teachers, preventing assignment to already assigned classes.
Display Staff Members: Provides a list of all teachers along with their assigned classes.
Software Structure

The software is structured around three main classes:
School Class (school.h, school.cpp): Manages school-level information, such as the name, address, and contact details. It also handles the management of teachers and classrooms within the school.
Classroom Class (classroom.h, classroom.cpp): Manages individual classrooms, including classroom details, student management, and classroom-specific operations.
Student Class (student.h, student.cpp): Represents individual students and provides functionalities to update student details and manage roll numbers.

# User Interface and Navigation
Upon starting the software, users are presented with a menu-driven interface, offering various options to perform school and classroom management tasks:

*** School Management System ***
1. Update School Name
2. Update School Address
3. Update School Contact
4. Display School Information
5. Display Staff Members
6. Add Teacher
7. Remove Teacher
8. Display Classrooms
9. Add Classroom
10. Remove Classroom
11. Enter Classroom
12. Exit

For classroom-specific operations, after entering a classroom, users can perform tasks like displaying classroom info, managing students, and updating classroom details through a similar menu-driven interface.
