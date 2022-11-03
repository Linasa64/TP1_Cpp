/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Ensemble::Afficher ( void )
{
#ifdef MAP
    cout << "Appel à la méthode Afficher de <Ensemble>" << "\r\n";
#endif
    if (t==NULL){
        cout << "0\r\n0\r\n{}\r\n";
    }else{
        cout << cardAct << "\r\n"; //n
        cout << cardMax << "\r\n"; //m
        cout << "{";
        int i;
        for(i = 0; i<cardAct ; i++){
            cout << t[i];
            if(i+1<cardAct){
                cout << ",";
            }
        }
        cout << "}\r\n";
    }
}

int Ensemble::Min(int tab[], unsigned int nbElements, int minPrecedent, int max)
{
#ifdef MAP
    cout << "Appel à la méthode Min de <Ensemble>" << "\r\n";
#endif
    unsigned int i;
    int min = max;
    for(i=1 ; i<nbElements ; i++)
    {
        if(tab[i]<min && tab[i]>minPrecedent)
        {
            min = tab[i];
        }
    }
    return min;
}

int Ensemble::Max(int tab[], unsigned int nbElements)
{
#ifdef MAP
    cout << "Appel à la méthode Max de <Ensemble>" << "\r\n";
#endif

    unsigned int i;
    int max = tab[0];
    for(i=1 ; i<nbElements ; i++)
    {
        if(tab[i]>max){
            max = tab[i];
        }
    }
    return max;
}

bool Ensemble::EstEgal ( const Ensemble & unEnsemble ) const
{
    if (cardAct != unEnsemble.cardAct)
        return false;
    bool trouve;
    int objet;
    unsigned int i=0, j;
    do{
        trouve = false;
        objet = t[i];
        j=0;
        while(objet != unEnsemble.t[j] && j<cardAct){
            j++;
        }
        if(j < cardAct)
            trouve = true;
        i++;
    }while(trouve && i<cardAct);
    return trouve;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble ( const Ensemble & unEnsemble )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << "\r\n";
#endif
} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble (unsigned int aCardMax)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << "\r\n";
#endif

cardMax = aCardMax;
cardAct = 0;

if(cardMax == 0){
    t = NULL;
}else{
    t = new int[cardMax];
}

} //----- Fin de Ensemble

Ensemble::Ensemble (int tab [ ], unsigned int nbElements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << "\r\n";
#endif

cardMax = nbElements;

if(cardMax == 0){
    t = NULL;
}else{
    t = new int[cardMax];
    int max = Max(tab, nbElements);
    int min = tab[0];
    unsigned int parcours;
    for (parcours = 1; parcours < nbElements ; parcours ++){
        if (tab[parcours] < min)
            min = tab[parcours];
    }
    t[0] = min;
    int i = 0;
    while(min != max){
        i ++;
        min = Min(tab, nbElements, min, max);

        t[i] = min;
   /*     cout << "indice : " << i<< "\r\n";
        cout << "min : " << min << "\r\n";
        cout << "max : " << max << "\r\n";
        cout << "t[i] : " << t[i] << "\r\n";*/
    }

    cardAct = i+1;
}

} //----- Fin de Ensemble

Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << "\r\n";
#endif
delete [] t;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
