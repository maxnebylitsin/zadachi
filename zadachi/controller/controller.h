#include <iostream>
#include <algorithm>
#include "student&group.h"

using namespace std;

class controller{
    private:
    group group1;
    int run;
    string v;

    public:
    controller(){}
    void defaultStudents(){
        student s1 = student("Ivanov", "Ivan", 3);
        s1.setMark(0, 4);
        s1.setMark(1, 5);
        s1.setMark(2, 3);
        group1.addStudent(s1);

        student s2 = student("Petrov", "Petr", 2);
        s2.setMark(0, 3);
        s2.setMark(1, 2);
        group1.addStudent(s2);

        student s3 = student("Sidorov", "Sidor", 4);
        s3.setMark(0, 5);
        s3.setMark(1, 4);
        s3.setMark(2, 5);
        s3.setMark(3, 4);
        group1.addStudent(s3);
    }
    void pressEnterToContinue(){
        cout << "Press Enter to continue...";
        cin.ignore();
        getchar();
    }
    void inputNewItem(){
        cout << "Enter surname: ";
        string newSurname;
        cin >> newSurname;
        cout << "Enter name: ";
        string newName;
        cin >> newName;
        cout << "Enter number of marks: ";
        int newN;
        cin >> newN;
        student newStudent = student(newSurname, newName, newN);
        int mark;
        for(int i = 0; i < newN; i++){
            cout << "Enter mark: ";
            cin >> mark;
            newStudent.setMark(i, mark);
        }
        group1.addStudent(newStudent);
        pressEnterToContinue();
    }
    void printAllItem(){
        group1.printAllStudents();
        pressEnterToContinue();
    }
    void deleteItem(){
        int index;
        cout << "Enter index: ";
        cin >> index;
        group1.removeStudent(index);
        pressEnterToContinue();
    }
    void printSorted(){
        group1.printStudentsBySurname();
        pressEnterToContinue();
    }
    void printSuccesful(){
        student bestStudent = group1.getBestStudent();
        bestStudent.printStudent();
        pressEnterToContinue();
    }
    void printUnsuccesful(){
        student worstStudent = group1.getWorstStudent();
        worstStudent.printStudent();
        pressEnterToContinue();
    }
    void printTwosStudents(){
        group1.printTwoMarksStudents();
        pressEnterToContinue();
    }
    void execute(){
        int var;
        defaultStudents();
        while (true){
            menu(); 
            cin >> var;
            if (var == 0){
                break;
            }
            switch(var){
                case 1:
                    cout << "input new item:\n";
                    inputNewItem();
                    break;
                case 2:
                    cout << "print all item:\n";
                    printAllItem();
                    break;
                case 3:
                    cout << "delete item:\n";
                    deleteItem();
                    break;
                case 4:
                    cout << "print students by alphabet:\n";
                    printSorted();
                    break;
                case 5:
                    cout << "print the most successful:\n";
                    printSuccesful();
                    break;
                case 6:
                    cout << "print the most unsuccessful:\n";
                    printUnsuccesful();
                    break;
                case 7:
                    cout << "print twos students:\n";
                    printTwosStudents();
                    break;
                default:
                    cout << "Invalid input\n";
            }
        } 
    }
    
    void menu(){
        cout << "Commands:\n";
        cout << "[1] input new item\n";
        cout << "[2] print all item\n";
        cout << "[3] delete item\n";
        cout << "[4] print students by alphabet\n"; 
        cout << "[5] print the most successful\n";
        cout << "[6] print the most unsuccessful\n"; 
        cout << "[7] print twos students\n";
        cout << "[0] exit\n";
    }
};