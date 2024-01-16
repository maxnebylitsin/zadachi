#include <iostream>

using namespace std;

class student{
    private:
    string name, surname;
    int n;
    int *marks;

    public:
    student(){
        surname = " ";
        name = " ";
        n = 0;
        marks = nullptr;
    }

    student(string snm, string nm, int nn){
        surname = snm;
        name = nm;
        n = nn;
        marks = new int[n];
    }
    student(student &st){
        surname = st.getSurname();
        name = st.getName();
        n = st.getSize();
        marks = st.marks;
    }

    string getName(){
        return name;
    }

    string getSurname(){
        return surname;
    }

    int getMark(int index){
        return marks[index];
    }

    void setMark(int index, int value){
        marks[index] = value;
    }

    void setMarks(int *arr){
        for(int i = 0; i < n; i++){
            marks[i] = arr[i];
        }
    }

    int getSize(){
        return n;
    }

    double getAverageMark(){
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += marks[i];
        }
        return sum / n;
    }

    void printStudent(){
        cout << name << endl;
        cout << surname << endl;
        for(int i = 0; i < n; i++){
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class group{
    private:
    student *studentsList;
    int size;

    public:
    group(){
        size = 0;
        studentsList = nullptr;
    }
    group(const group &gr){
        size = gr.size;
        studentsList = gr.studentsList;
    }
    int getSize(){
        return size;
    }
    student *getStudentsList(){
        return studentsList;
    }
    void printAllStudents(){
        for(int i = 0; i < size; i++){
            cout << i << " " << studentsList[i].getSurname() << " " << studentsList[i].getName() << ": ";
            for(int j = 0; j < studentsList[i].getSize(); j++){
                cout << studentsList[i].getMark(j) << " ";
            }
            cout << endl;
        }
    }
    void addStudent(student st){
        student *tempList = new student[size + 1];
        for(int i = 0; i < size; i++){
            tempList[i] = studentsList[i];
        }
        tempList[size] = st;
        delete[] studentsList;
        studentsList = tempList;
        size++;
    }

    void removeStudent(int index){
        student *tempList = new student[size - 1];
        for(int i = 0; i < index; i++){
            tempList[i] = studentsList[i];
        }
        for(int i = index + 1; i < size; i++){
            tempList[i - 1] = studentsList[i];
        }
        delete[] studentsList;
        studentsList = tempList;
        size--;
    }

    student getStudent(int index){
        return studentsList[index];
    }

    void setStudent(student newSt, int index){
        studentsList[index] = newSt;
    }

    student getBestStudent(){
        double maxAverageMark = -1;
        student bestStudent;
        for(int i = 0; i < size; i++){
            double averageMark = studentsList[i].getAverageMark();
            if(averageMark > maxAverageMark){
                maxAverageMark = averageMark;
                bestStudent = studentsList[i];
            }
        }
        return bestStudent;
    }

    student getWorstStudent(){
        double minAverageMark = 11;
        student worstStudent;
        for(int i = 0; i < size; i++){
            double averageMark = studentsList[i].getAverageMark();
            if(averageMark < minAverageMark){
                minAverageMark = averageMark;
                worstStudent = studentsList[i];
            }
        }
        return worstStudent;
    }

    void printTwoMarksStudents(){ 
        bool found = false; 
        for(int i = 0; i < size; i++){ 
            bool hasTwoMark = false;
            for (int j = 0; j < studentsList[i].getSize(); j++){
                if (studentsList[i].getMark(j) == 2){
                    hasTwoMark = true;
                    break;
                }
            }
            if (hasTwoMark){
                found = true;
                cout << studentsList[i].getSurname() << " " << studentsList[i].getName() << endl; 
            } 
        } 
        if(found){ 
            cout << "Есть студенты с двойками" << endl; 
        } else { 
            cout << "Нет студентов с двойками" << endl; 
        } 
    }
    void printStudentsBySurname(){
        student **tempList = new student*[size];
        for(int i = 0; i < size; i++){
            tempList[i] = &studentsList[i];
        }
        for(int i = 0; i < size - 1; i++){
            for(int j = 0; j < size - i - 1; j++){
                if(tempList[j]->getSurname() > tempList[j+1]->getSurname()) {
                    student *temp = tempList[j];
                    tempList[j] = tempList[j+1];
                    tempList[j+1] = temp;
                }
            }
        }
        for(int i = 0; i < size; i++){
            cout << tempList[i]->getSurname() << " " << tempList[i]->getName() << endl;
        }
        delete[] tempList;
    }
};