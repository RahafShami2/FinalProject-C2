#include "Students.h"
#include <iostream>
#include <string>
#include"Course.h"
#include<fstream>
using namespace std;
course::course() { file.open(""); }
course::course(string fileName) { file.open("course.csv"); }
void course::loadData(Student student[]) {
	int n = 0;
	string str;
	string data;
	while (file.good()) {
		int loc;
		getline(file, str);
		data = "";
		for (loc = 0; str[loc] != ','; loc++)
		{
			data += str[loc];
		}
		loc++;
		student[n].setId(stoi(data));
		data = "";
		for (; str[loc] != ','; loc++)
		{
			data += str[loc];
		}
		loc++;
		student[n].setName(data);
		data = "";
		for (; str[loc] != ','; loc++)
		{
			data += str[loc];
		}
		loc++;
		student[n].setFirst(stoi(data));
		data = "";
		for (; str[loc] != ','; loc++)
		{
			data += str[loc];
		}
		loc++;
		student[n].setSeond(stoi(data));
		data = "";
		for (int i = 0; i < 2; loc++, i++)
		{
			data += str[loc];
		}
		student[n].setFinal(stoi(data));
		data = "";
		n++;
	}
}
void course::uploadData(Student student[]) {
	ofstream file("course.csv");
	int i;
	for (i = 0; i < 19; i++) {
		string line;
		string data = to_string(student[i].getId());
		line += data + ',';
		data = student[i].getName();
		line += data + ',';
		data = to_string(student[i].getFirst());
		line += data + ',';
		data = to_string(student[i].getSecond());
		line += data + ',';
		data = to_string(student[i].getFinal());
		line += data + ',';
		file << line << endl;
	}
	string line;
	string data = to_string(student[i].getId());
	line += data + ',';
	data = student[i].getName();
	line += data + ',';
	data = to_string(student[i].getFirst());
	line += data + ',';
	data = to_string(student[i].getSecond());
	line += data + ',';
	data = to_string(student[i].getFinal());
	line += data + ',';
	file << line;
}
void course::print(Student student[]) {
	for (int i = 0; i < 20; i++)
	{
		student[i].print(student);
	}
}
void course::printById(Student student[]) {
	long id;
	cout << "Please enter the student id: "; cin >> id;
	for (int i = 0; i < 20; i++)
	{
		if (student[i].getId() == id) {
			cout << "the sum of " << student[i].getName() << " grade in the 3 exams is: " << student[i].getFirst() + student[i].getSecond() + student[i].getFinal() << "%" << endl;
			return;
		}
	}
	cout << "invalid ID" << endl;
}
void course::printAvgForOneExam(Student student[]) {
	float sum = 0;
	int examNumber;
	cout << "Please enter the exam number: "; cin >> examNumber;
	if (examNumber == 1) {
		for (int i = 0; i < 20; i++)
		{
			sum += student[i].getFirst();
		}
		cout << "The average grade in the first exam is: " << sum / 20.0 << endl;
		return;
	}
	if (examNumber == 2) {
		for (int i = 0; i < 20; i++)
		{
			sum += student[i].getSecond();
		}
		cout << "The average grade in the Second exam is: " << sum / 20.0 << endl;
		return;
	}
	if (examNumber == 3) {
		for (int i = 0; i < 20; i++)
		{
			sum += student[i].getFinal();
		}
		cout << "The average grade in the final exam is: " << sum / 20.0 << endl;
		return;
	}
}
void course::printTotalGrade(Student student[]) {
	float sum = 0;
	for (int i = 0; i < 20; i++)
	{
		sum += student[i].getFirst() + student[i].getSecond() + student[i].getFinal();
	}
	cout << "The average of total grade for all students is: " << sum / 20.0 << endl;
}
void course::updateInfromation(Student student[]) {
	long id;
	cout << "please enter the student id: "; cin >> id;
	for (int i = 0; i < 20; i++)
	{
		if (student[i].getId() == id) {
			cout << "id: " << student[i].getId() << endl;
			cout << "name: " << student[i].getName() << endl;
			cout << "mark1: " << student[i].getFirst() << endl;
			cout << "mark2: " << student[i].getSecond() << endl;
			cout << "mark3: " << student[i].getFinal() << endl;
			long id;
			string name;
			int first;
			int second;
			int final;
			cout << "Please enter a new id: "; cin >> id;
			cin.ignore();
			cout << "Please enter a new name: "; getline(cin, name);
			cout << "Please enter a new grade for for first exam: "; cin >> first;
			cout << "Please enter a new grade for for second exam: "; cin >> second;
			cout << "Please enter a new grade for for final exam: "; cin >> final;
			student[i].setId(id);
			student[i].setName(name);
			if (first <= 30)
				student[i].setFirst(first);
			if (second <= 30)
				student[i].setSeond(second);
			if (final <= 40)
				student[i].setFinal(final);
			return;
		}
	}
	cout << "invalid ID" << endl;
}
void course::updateFile(Student student[]) {
	uploadData(student);
	cout << "file updated!" << endl;
}
void course::reloadContent(Student student[]) {
	loadData(student);
	cout << "data reloaded successfully " << endl;
}
void course::printInDescendingOrder(Student student[]) {
	long idTemp;
	string nameTemp;
	int firstTemp;
	int secondTemp;
	int finalTemp;
	for (int i = 0; i < 20; i++) {
		for (int j = i + 1; j < 20; j++) {
			if (student[j].getTotalGrade() > student[i].getTotalGrade())
			{
				idTemp = student[j].getId();
				nameTemp = student[j].getName();
				firstTemp = student[j].getFirst();
				secondTemp = student[j].getSecond();
				finalTemp = student[j].getFinal();
				student[j].setId(student[i].getId());
				student[j].setName(student[i].getName());
				student[j].setFirst(student[i].getFirst());
				student[j].setSeond(student[i].getSecond());
				student[j].setFinal(student[i].getFinal());
				student[i].setId(idTemp);
				student[i].setName(nameTemp);
				student[i].setFirst(firstTemp);
				student[i].setSeond(secondTemp);
				student[i].setFinal(finalTemp);
			}
		}
	}
	print(student);
}
course::~course() {
	cout << "course has been deleted";
}