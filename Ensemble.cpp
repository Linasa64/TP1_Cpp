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

void Ensemble::tri()
{
	bool estTrie = false;
	int tmp = 0;
	while(!estTrie){
        estTrie = true;
		for (unsigned int i = 0 ;cardAct!=0 && i<cardAct-1 ; i++){
			if (t[i]>t[i+1]){
				tmp = t[i];
				t[i] = t[i+1];
				t[i+1] = tmp;
				estTrie = false;
			}
		}
	}
}

void Ensemble::Afficher ( void )
{
#ifdef MAP
    cout << "Appel à la méthode Afficher de <Ensemble>" << "\r\n";
#endif
    tri();
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
    
    int i, j;
    bool found;
    for(i=0; i<this->cardAct; i++){
        found = false;
        for(j=0; j<this->cardAct; j++){
            if(this->t[i]==unEnsemble.t[j]){
                found = true;
            }
        }
        if(!found){
            return false;
        }
    }
    return found;
} 

bool Ensemble::EstInclusionStricte ( const Ensemble & unEnsemble ) const
{
    if(this->cardAct>=unEnsemble.cardAct){
        return false;
    }
    int i, j;
    bool found;
    for(i=0; i<this->cardAct; i++){
        found=false;
        for(j=0; j<unEnsemble.cardAct; j++){
            if(this->t[i]==unEnsemble.t[j]){
                found = true;
            }
        }
        if(!found){
            return false;
        }
    }
    return found;
} 


crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const
{
    if(this->EstEgal(unEnsemble)){
        return INCLUSION_LARGE;
    }
    else if(this->EstInclusionStricte(unEnsemble)){
        return INCLUSION_STRICTE;
    }
    return NON_INCLUSION;
}

bool Ensemble::ValEstInclus(int val) const
{
    for(unsigned int i = 0; i<cardAct ; i++){
		if(t[i]==val){
			return true;
		}
	}
	return false;
}

crduAjouter Ensemble::Ajouter (int aAjouter)
{
	if(ValEstInclus(aAjouter))
	{
		return DEJA_PRESENT;
	}
	else if(cardAct==cardMax)
	{
		return PLEIN;
	}
	t[cardAct]=aAjouter;
	cardAct++;
	tri();
	return AJOUTE;
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
	cardAct = 0;
	t = new int[cardMax];
    bool exists;
	for(unsigned int i=0; i<nbElements ; i++)
	{
        exists = false;
        for(unsigned int cur=0; cur<cardAct; cur++){
            if(t[cur]==tab[i]){
                exists=true;
            }
        }
        if(!exists){
            t[cardAct]=tab[i];
            cardAct+=1;
        }
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
