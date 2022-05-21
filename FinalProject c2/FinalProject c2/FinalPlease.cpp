
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "Students.h"
#include "course.h"
#include "Student.cpp"
#include "Course.cpp"
using namespace std;
int main()
{
	course crs;
	course file("course.csv");
	Student* student;
	student = new Student[20];
	file.loadData(student);
	int choice = 1;
	
	while (choice != 0) {
		cout << "---------------------------------------------------------------------------------"<<endl;
		cout << "1. print the content of the file on screen" << endl;
		cout << "2. print the total grade of a student in an exam" << endl;
		cout << "3. Print the average grade in a certain exam" << endl;
		cout << "4. Print the average of total grade for all students" << endl;
		cout << "5. Update student information" << endl;
		cout << "6. Store the updated content of the array into the file" << endl;
		cout << "7. Reload the content of the file" << endl;
		cout << "8. display records according to the total grade in descending order" << endl;
		cout << "9. Exit" << endl<<endl;
		cout << "Please choose one of the above: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			crs.print(student);
			break;
		case 2:
			crs.printById(student);
			break;
		case 3:
			crs.printAvgForOneExam(student);
			break;
		case 4:
			crs.printTotalGrade(student);
			break;
		case 5:
			crs.updateInfromation(student);
			break;
		case 6:
			crs.updateFile(student);
			break;
		case 7:
			crs.reloadContent(student);
			break;
		case 8:
			crs.printInDescendingOrder(student);
			break;
		case 9:
			choice = 0;
			break;
		default:
			cout << "invalid choice" << endl;
			break;
		}
	}
	delete[]student;
}