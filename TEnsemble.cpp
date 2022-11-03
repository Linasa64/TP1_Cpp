using namespace std;
#include "Ensemble.h"
#include <iostream>

int main()
{
    Ensemble e0;
    Ensemble e1(3);
    Ensemble e2(0);
    e0.Afficher();
    e1.Afficher();
    e2.Afficher();
}