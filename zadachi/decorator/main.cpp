#include <iostream>
#include "decorator.h"

using namespace std;

int main()
{
    Footballer* f = new Footballer;
    f->getInfo();
    f = new Defender(f);
    f->getInfo();
    f->getSkills();
    f = new Midfielder(f);
    f->getSkills();
    f = new Striker(f);
    f->getSkills();
    return 0;
}