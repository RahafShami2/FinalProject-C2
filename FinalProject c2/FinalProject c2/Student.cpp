#include <string>
#include <iostream>
#include "Students.h"
Student::Student() {
	id = 0;
	name = "";
	first = second = final = 0;
}
Student::Student(const Student& obj) {
	id = obj.id;
	name = obj.name;
	first = obj.first;
	second = obj.second;
	final = obj.final;
}
void Student::setId(long id) { this->id = id; }
void Student::setName(string name) { this->name = name; }
void Student::setFirst(int first) { this->first = first; }
void Student::setSeond(int second) { this->second = second; }
void Student::setFinal(int final) { this->final = final; }
long Student::getId() { return id; }
string Student::getName() { return name; }
int Student::getFirst() { return first; }
int Student::getSecond() { return second; }
int Student::getFinal() { return final; }
long Student::getTotalGrade() {
	return first + second + final;
}
 void Student::print(Student student[]) { 
	cout << id << "," << name << "," << first << "," << second << "," << final << endl;
}
Student::~Student()
{
	id = final = first = 0;
	name = "";
}