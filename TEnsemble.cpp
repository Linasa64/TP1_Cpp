using namespace std;
#include "Ensemble.h"
#include <iostream>

int main()
{
    int tab0[] = {-13,1,9,33,42};
    unsigned int t0 = 5;

    int tab1[] = {-19,0,5,10,15,37};
    unsigned int t1 = 6;

    Ensemble e0(tab0, t0);
    Ensemble e1(tab1, t1);

    e0.Afficher();
    e1.Afficher();

    
}