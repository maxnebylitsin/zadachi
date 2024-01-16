#include <iostream>

using namespace std;

class Footballer {
protected:
    string name, position, club;
    int age, price;
    int pac, sho, pas, dri, def, phy,
    div, han, kic, ref, spe, pos;
public:
    Footballer() {
        name = "Ivanov";
        age = 25;
        club = "Zenit";
        position = "???";
        price = 0;
        pac = 1, sho = 1, pas = 1, dri = 1, def = 1, phy = 1;
        div = 1, han = 1, kic = 1, ref = 1, spe = 1, pos = 1;
    }
    virtual string getName() {
        return name;
    }
    virtual int getAge() {
        return age;
    }
    virtual string getPosition() {
        return position;
    }
    virtual string getClub() {
        return club;
    }
    virtual int getPrice() {
        return price;
    }
    virtual int getPac() {return pac;}
    virtual int getSho() {return sho;}
    virtual int getPas() {return pas;}
    virtual int getDri() {return dri;}
    virtual int getDef() {return def;}
    virtual int getPhy() {return phy;}

    virtual int getDiv() {return div;}
    virtual int getHan() {return han;}
    virtual int getKic() {return kic;}
    virtual int getRef() {return ref;}
    virtual int getSpe() {return spe;}
    virtual int getPos() {return pos;}

    void getInfo() {
        cout << "Name: " << this->getName() << endl
            << "Age: " << this->getAge() << endl
            << "Club: " << this->getClub() << endl
            << "Position: " << this->getPosition() << endl
            << "Price: " << this->getPrice() << endl
            << "----------" << endl;
    }
    void getSkills() {
        if (position == "Goalkeeper") {
            cout << this->getPosition() << " skills:" << endl
            << "Diving: " << this->getDiv() << endl
            << "Handling: " << this->getHan() << endl
            << "Kicking: " << this->getKic() << endl
            << "Reflexes: " << this->getRef() << endl
            << "Speed: " << this->getSpe() << endl
            << "Positioning: " << this->getPos() << endl
            << "----------" << endl;
        }
        else {
            cout << this->getPosition() << " skills:" << endl
            << "Pace: " << this->getPac() << endl
            << "Shooting: " << this->getSho() << endl
            << "Passing: " << this->getPas() << endl
            << "Dribbling: " << this->getDri() << endl
            << "Defending: " << this->getDef() << endl
            << "Physical: " << this->getPhy() << endl
            << "----------" << endl;
        }
    }
};

class Goalkeeper: public Footballer {
protected:
    Footballer* f;
public:
    Goalkeeper(Footballer* f) {
        this->f = f;
        position = "Goalkeeper";
        price = 5000000;
        div = 90, han = 95, kic = 85,
        ref = 92, spe = 56, pos = 87;
    }
};

class Defender: public Footballer {
protected:
    Footballer* f;
public:
    Defender(Footballer* f) {
        this->f = f;
        position = "Defender";
        price = 10000000;
        pac = 70, sho = 45, pas = 61,
        dri = 65, def = 90, phy = 81;
    }
};

class Midfielder: public Footballer {
protected:
    Footballer* f;
public:
    Midfielder(Footballer* f) {
        this->f = f;
        position = "Midfielder";
        price = 15000000;
        pac = 75, sho = 80, pas = 92,
        dri = 84, def = 68, phy = 78;
    }
};

class Striker: public Footballer {
protected:
    Footballer* f;
public:
    Striker(Footballer* f) {
        this->f = f;
        position = "Striker";
        price = 30000000;
        pac = 90, sho = 87, pas = 80,
        dri = 87, def = 56, phy = 82;
    }
};