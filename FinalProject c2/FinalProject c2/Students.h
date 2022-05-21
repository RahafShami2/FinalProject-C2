#pragma once
#include <string>
#include <iostream>
using namespace std;
class Student {
private:
	long id;
	string name;
	int first;
	int second;
	int final;
public:
	Student();
	Student(const Student& obj);
	void setId(long id); 
	void setName(string name); 
	void setFirst(int first); 
	void setSeond(int second);
	void setFinal(int final);
	long getId();
	string getName();
	int getFirst();
	int getSecond();
	int getFinal();
	long getTotalGrade(); 
	virtual void print(Student student[]);//polymorphisms
	~Student();
};
