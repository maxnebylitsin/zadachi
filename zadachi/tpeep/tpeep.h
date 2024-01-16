#include <iostream>

using namespace std;

class Tpeep{
    protected:
    string name, surname, otch;
    string dr;
    int state;
    
    public:
    
    virtual void create(string &nm, string &snm, string &ot, string &d){
        name = nm;
        surname = snm;
        otch = ot;
        dr = d;
    }
    virtual void create(const char* nm, const char* snm, const char* ot, const char* d){
        name = nm;
        surname = snm;
        otch = ot;
        dr = d;
    }
    int getState(){return state;}
    virtual void print() = 0;
};

class Tteacher: public Tpeep{
    public:
    Tteacher(){
        state = 1;
    }
    void print(){
        cout << "Преподаватель" << endl;
    cout << surname << " " << name << " " << otch << " " << dr << endl;
    }
};
class Tstudent: public Tpeep{
    protected:
    int marks[5];
    
    public:
    Tstudent(){
        state = 0;
        for (int i = 0; i < 5; i++) marks[i] = 0;
    }
    void markSet(int i, int vl){marks[i] = vl;}
    int markGet(int i){return marks[i];}
    
    void print(){
        cout << "Студент" << endl;
        cout << surname << " " << name << " " << otch << " " << dr << endl;
        cout << "Оценки:";
        for (int i = 0; i < 5; i++) cout << " " << marks[i];
        cout << endl;
    }
    void tst(){
        cout << "***";
    }
};

class builder2{
    public:
    void inputMarks(Tstudent* person){
        int i, o;
        cout << "Введите оценки" << endl;
        for (i = 0; i < 5; i++){
            cout << "[" << i << "j"; cin >> o;
            person -> markSet(i, o);
        }
    }
};

class fabrika{
    public:
    Tpeep* create(const char* nm, const char* snm, const char* ot, const char* d, int type){
        string nm1, snm1, ot1, d1;
        nm1 = nm;
        snm1 = snm;
        ot1 = ot;
        d1 = d;
        return create(nm1, snm1, ot1, d1, type);
    }
    
    Tpeep* create(string &nm, string &snm, string &ot, string &d, int type){
        Tpeep *res = NULL;
        if (type == 0){
            res = new Tstudent;
            res -> create(nm, snm, ot, d);
        }
        else if (type = 1){
            res = new Tteacher;
            res -> create(nm, snm, ot, d);
        }
        return res;
    }
};