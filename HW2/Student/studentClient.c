/****************************************************************************/
/* INFO: StudentClient.C                                                    */
/* IMPLEMENTED BY: Stefan Retief                                            */
/* DATE: February 24, 2016                                                  */
/****************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>  //include vector.h
using namespace std;
#include "student.h"
#include "inputCheck.h"

void showMenu();
void addStudentsFromFile(vector<Student>&);
void addOneStudent(vector<Student>&);
void printAllStudents(const vector<Student>&);
void addCourseToStudent(vector<Student>&);
void dropCourseFromStudent(vector<Student>&);

int main()
{
  cout << "\n *** TEST: the number of students at the beginning is " << Student::getNumStu() << endl;
 
    vector<Student> stuVec; //declare a vector of students
  int choice;

  do
  {
    showMenu();
    cout << "Enter your choice ----> ";
    choice = getNum(1, 6, "Invalid choice. Enter 1 through 6: ");

    switch(choice)
    {
      case 1:
	  addStudentsFromFile(stuVec);
	  break;
      case 2:
      addOneStudent(stuVec);
	  break;
      case 3:
	  printAllStudents(stuVec);
      cout << "\n *** TEST: the number of students is " << Student::getNumStu() << endl;
	  break;
      case 4:
      addCourseToStudent(stuVec);
	  break;
      case 5:
	  dropCourseFromStudent(stuVec);
	  break;
      case 6:
	  cout << "Ending the program ..............." << endl;
      }
  }while(choice != 6);


  cout << "\n *** TEST: the number of students at the end is " << Student::getNumStu() << endl;

  return 0;
}

 void showMenu()
 {
   cout << "\n*****************************************************************" << endl;
   cout << "1: Add students from a file" << endl;
   cout << "2: Add one student" << endl;
   cout << "3: Print all students" << endl;
   cout << "4: Add a course to a student" << endl;
   cout << "5: drop a course from a student" << endl;
   cout << "6: End the program" << endl;
 }

//This function adds students from an input file
//e.g. for input file (for each student, first last gen)
//  Mike Smith M
//  Kathy Ross F
void addStudentsFromFile(vector<Student>& stu)
{
  string fileName;

  cout << "Enter the file name: ";
  cin >> fileName;

  ifstream fin;
  fin.open(fileName.c_str()); //open the file

  if(!fin)
    {
      cout << fileName << " doesn't exist " << endl;
    }
  else//The file exists
    {
      string fn, ln;
      char gn;
   
      fin >> fn >> ln >> gn;//read the first student
      while(fin)//if reading was successful, enter the while
	{
	  Student readStudent(fn, ln, gn);//create a new student with the data from input
	  stu.push_back(readStudent); //add it to the vector
	  fin >> fn >> ln >> gn; //read the next student
	}
    }
}

//This function adds one student to the vector.
void addOneStudent(vector<Student>& stu)
{
      string fn, ln;
      char gn;

      cout << "Enter the student's first name: ";
      cin >> fn;
      cout << "Enter the student's last name: ";
      cin >> ln;
      cout << "Enter the student's gender: ";
      gn = getGender("Invalid input. Enter M or F: ");

      Student inputStudent(fn, ln, gn); //create a new student with the data from the user's input
    stu.push_back(inputStudent); //add the new student to the vector
}
 
//Print the information about all the students
void printAllStudents(const vector<Student>& stu)
{
  //Show the labels
  cout << left << setw(10) << "Id" <<  setw(10) << "First" << setw(10) << "Last" << right << setw(10) << "Fee" << left << setw(10) << "  Courses" << endl; 

  //Go through each student in the vector
  for(int n = 0; n < stu.size(); n++)
    {
      cout <<  setw(10) << stu[n].getId() << setw(10) << stu[n].getFirstName() << setw(10) << stu[n].getLastName() << right << setw(7) << stu[n].getDollar() << ".";

      //If the cent is less than 10, show a 0 first.
      //e.g. cent = 3, 03 will be shown.
      if(stu[n].getCent() < 10)
        cout << "0";
        cout << stu[n].getCent();
      
      //show all courses the student is enrolled in
      cout << left << "  ";
      vector<int> co = stu[n].getCourses(); //get the vector of courses for this student
      for(int c = 0; c < co.size(); c++)
        cout << setw(6) << co[c];

      cout << endl;
    }
}

//Add a new course to a student.
//Charge $50.10 per course
void addCourseToStudent(vector<Student>& stu)
{


  cout << "Enter the student id: ";
  int id = getNum(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNum(1, 99999, "Invalid CRN. Enter the CRN: ");

  //Big section
    bool found = false;
    for(int i = 0; i < stu.size(); i++)
    {
        if (id == stu[i].getId())
        {
            found = true;
            if (stu[i].addCourse(crn))
            {
                cout << "Course " << crn << " has been added to " << stu[i].getFirstName() << " " << stu[i].getLastName() << endl;
                stu[i].chargeFee(50, 10);
            }
            else
            {
                cout << stu[i].getFirstName() << " " << stu[i].getLastName() << " is already enrolled in course " << crn << endl;
            }
        }
    }
    if (!found)
    {
        cout << "The ID: " << id << " was not found.";
    }
}

//drop a course from a student
//reduct $50.10 from the student's balance
void dropCourseFromStudent(vector<Student>& stu)
{
 
  cout << "Enter the student id: ";
  int id = getNum(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNum(1, 99999, "Invalid CRN. Enter the CRN: ");

  //Big section
    bool found = false;
    for(int i = 0; i < stu.size(); i++)
    {
        if (id == stu[i].getId())
        {
            found = true;
            if (stu[i].dropCourse(crn))
            {
                cout << "Course " << crn << " has been removed from " << stu[i].getFirstName() << " " << stu[i].getLastName() << endl;
                stu[i].reduceFee(50, 10);
            }
            else
            {
                cout << stu[i].getFirstName() << " " << stu[i].getLastName() << " is not enrolled in course " << crn << endl;
            }
        }
    }
    if (!found)
    {
        cout << "The ID: " << id << " was not found.";
    }
}
