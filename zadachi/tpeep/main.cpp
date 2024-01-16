#include <iostream>
#include <tpeep.h>
using namespace std;

int main()
{
    string n, s, o, d;
    s = "Ivanov";
    n = "Ivan";
    o = "Ivanovich"; 
    d = "2000-11-12";
    

    fabrika dekanat;
    builder2 uchotdel;
    int k = 3, t, i;
    string tmp;
    Tpeep ** peeps = new Tpeep*[k];
    for (i = 0; i < k; i++){
        cout << "Введите фамилию: "; cin >> s;
        cout << "введите имя: "; cin >> n;
        cout << "Введите отчество: "; cin >> o;
        cout << "Введите дату рождения: "; cin >> d;
        cout << "Введите статус (0 - студент, 1 - преподаватель): "; cin >> t;
        cin >> tmp;
        
        peeps[i] = dekanat.create(n,s,o,d,t);
        if (t == 0){
            uchotdel.inputMarks((Tstudent*) peeps[i]);
        }
    }
    for (i = 0; i < k; i++){
        if(peeps[i] -> getState() == 0)
        peeps[i] -> print();
    }
    
    //Tpeep *pers1, *pers2;

    // pers1 = dekamat.create(n,s,o,d,1);
    
    // pers2 = dekanat.create("Иванов", "Иван", "Иванович", "2000-04-01",0)
    // pers1 -> print();
    // pers1 -> print();
    // delete pers1; delete pers2;
    return 0;
}