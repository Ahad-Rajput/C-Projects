#include <iostream>
#include <string>

using namespace std;

const int Max_Students = 50;

string studentName[Max_Students];
int studentRollNo[Max_Students];
int studentMarks[Max_Students];
int studentAttendance[Max_Students];

int numStudent = 0;

void addStudent()
{
    if (numStudent < Max_Students)
    {
        cout << "Enter Student name : ";
        cin.ignore();
        getline(cin , studentName[numStudent]);

        cout << "Enter Student roll no. : ";
        cin >> studentRollNo[numStudent];
        
        cout << "Enter Student marks : ";
        cin >> studentMarks[numStudent];
        
        cout << "Enter percentage of Student's attendance : ";
        cin >> studentAttendance[numStudent];

        cout << "Student added successfully.\n";
        
        numStudent++;
    }
    else
    {
        cout << "Can't add this student as we reached the maximum limit.\n";
    }
}
 void displayStudents()
{
    if (numStudent > 0 )
    {
        for (int i = 0; i < numStudent; i++)
        {
            cout << "\nList of Students : \n";
            cout << "Student name : " << studentName[i] <<"\tStudent roll no. : " << studentRollNo[i] << endl;
            cout << "Marks : " << studentMarks[i] << "\tPercentage of Attendence : " << studentAttendance[i] << endl;
        }
    }
    
  
    else
    {
        cout << "No student to display.\n";
    }        
}   

int findStudent(int rollNum)
{
    for (int i = 0; i < numStudent; i++)
    {
        if (studentRollNo[i] == rollNum)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int choice;
    int index;
    do
    {
        cout << "\n---> Student Management System <---\n\n";
        cout << "1. Add Student\n";
        cout << "2. Get the list of all Student\n";
        cout << "3. Get Attendence of Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            int rollNum;
            cout << "Enter the roll no. of Student : ";
            cin >>rollNum;

            index = findStudent(rollNum);              
            if (index != -1)
            {
                cout << "Student name : " << studentName[index] << "\tPercentage of Attendence : " << studentAttendance[index] <<"%\n";
            }
            else 
            {
                cout << "Student not found.\n";
            }
            break;
        
        case 4:
            cout << "Exiting the program...\n";
            break;
        
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 4);
    return 0;
}