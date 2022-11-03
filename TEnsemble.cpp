using namespace std;
#include "Ensemble.h"
#include <iostream>

int main()
{
    int tab0[] = {-22, 0, 4, 99};
    unsigned int t0 = 7;

    int tab1[] = {-22, 0, 4, 77};
    unsigned int t1 = 3;

    Ensemble e0(tab0, t0);
    Ensemble e1(tab1, t1);

    e0.Afficher();
    e1.Afficher();

    
}