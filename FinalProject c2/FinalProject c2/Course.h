#pragma once
#include "Students.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
class course : Student
{
private:
	ifstream file;
public:
	course();
	course(string fileName);
	void loadData(Student student[]);
	void uploadData(Student student[]);
	void print(Student student[]);
	void printById(Student student[]);
	void printAvgForOneExam(Student student[]);
	void printTotalGrade(Student student[]); 
	void updateInfromation(Student student[]); 
	void updateFile(Student student[]);
	void reloadContent(Student student[]); 
	void printInDescendingOrder(Student student[]);
	~course();
};

