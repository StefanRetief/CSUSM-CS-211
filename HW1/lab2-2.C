/****************************************************************************/
/* INFO: Lab1-struct.C                                                      */
/* IMPLEMENTED BY: Stefan Retief                                            */
/* DATE: February 9, 2016                                                   */
/****************************************************************************/

#include <iostream>
#include <iomanip>
#include "inputCheck.h"
//#include <cctype>
using namespace std;

//######### DO NOT forget about the prototypes. You should know where to place them.  ############

//Declare a struct called "student" with id, name, gender, major and age
struct student {
    int id;
    string name;
    char gender;
    string major;
    int age;
};

int getStuData(student []);
int findID(int, const student [], int);
void displayStu(student);
void findYoungOld(const student [], int, int&, int&);
void displayAllStu(const student [], int);
//If you want to change the maximum number of students, change the number in one place.
const int MAX = 5;

int main()
{
    //delare an array of students with size MAX.
    student data[MAX];
    
    int numOfStu = getStuData(data); //the number of students
    
    //call the getStuData function to fill the array with students' information
    if (numOfStu != 0)
    {
        int look; //The id the user is looking for
        cout << "Enter the ID you are looking for: ";
        cin >> look;
    
        //Find a student with that id and display the information about that student. If no student has the id, show an appropriate message.
        int index =  findID(look, data, numOfStu);
    
        if(index != -1)
            displayStu(data[index]);
        else
            cout << "\nNo student with ID " << look << " was found" << endl;
    
        //find the youngest and oldest ages by calling findYoungOld and output those ages
        int young;
        int old;
        findYoungOld(data, numOfStu, young, old);
        cout << "\nThe oldest student is " << old << " years old." << endl;
        cout << "The Youngest student is " << young << " years old." << endl;
    
        displayAllStu(data, numOfStu);
    }
    
    return 0;
}

//This function loads students' data into the array and returns the number of students.
int getStuData(student array[])
{
    
    //fill the array with students' information entered from the keyboard - use the while loop
    char cont;
    string msg = "Invalid Response. Enter Y or N: ";
    string genderMsg = "Invalid Response. Enter M or F: ";
    string numMsg = "Inavlid Response. Enter a number: ";
    string alphaMsg = "Invalid Response. Enter alphabetic characters: ";
    int i = 0;
    cout << "Enter data for a student? Y or N: ";
    cont = getResponse(msg);
    if (cont == 'N' && i == 0)
    {
        cout << "No students were entered." << endl;
    }
    
    while (cont == 'Y') {
        cout << "Enter ID: ";
        array[i].id = getNum(1, 9999, numMsg);
        cin.ignore();
        cout << "Enter name: ";
        array[i].name = getAlpha(alphaMsg);
        cout << "Enter gender: ";
        array[i].gender = getGenderResponse(genderMsg);
        cin.ignore();
        cout << "Enter major: ";
        array[i].major = getAlpha(alphaMsg);
        cout << "Enter age: ";
        array[i].age = getNum(0, 150, numMsg);
        i++;
        cout << "\nEnter data for another student? Y or N: ";
        cont = getResponse(msg);
        if (cont =='Y' && i >= MAX)
        {
            cout << "Array is full." << endl;
            cont = 'N';
        }
    }
    //fill the unused slots with the default values
    student Default = {0, " ", ' ', " ", 999}; //defalut values
    
    for(int count = i; count < MAX; count++ )
    {
        array[count] = Default;
    }
    
    //return the number of students
    return i;
}

/* This function searches through the array to find the student with the id the user is looking for.
 The user is asked to enter the id she is looking for in the main.
 Return the index or -1 if not found. */
int findID(int lookfor, const student array[], int i)
{
    bool found = false;
    int index = 0;
    
    while (!found && index < i)
    {
        if (array[index].id == lookfor)
            found = true;
        else
            index++;
    }
    if (found)
        return index;
    else
        return -1;
}

/*This function will be passed one student struct and display all the information (name, gender, major and age) about that student.*/
void displayStu(student display)
{
    cout << setw(15) << left << display.id << setw(25) << display.name << setw(15) << display.gender << setw(25) << display.major << setw(15) << display.age << endl;
}

/*This function will return the youngest and oldest ages */
void findYoungOld(const student stu[], int num, int& young, int& old)
{
    old = 0;
    young = 999;
    for (int k = 0; k < num; k++)
    {
        if (stu[k].age < young)
            young = stu[k].age;
        if (stu[k].age > old)
            old = stu[k].age;
    }
}

void displayAllStu(const student stu[], int numOfStu)
{
    cout << setw(15) << left << "ID" << setw(25) << "Name" << setw(15) << "Gender" << setw(25) << "Major" << setw(15) << "Age" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < numOfStu; i++)
    {
        displayStu(stu[i]);
    }
}
