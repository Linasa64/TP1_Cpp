/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const unsigned int CARD_MAX = 5;

//------------------------------------------------------------------ Types

enum crduEstInclus{NON_INCLUSION,INCLUSION_LARGE,INCLUSION_STRICTE};
enum crduAjouter{DEJA_PRESENT,PLEIN,AJOUTE};

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void tri();
    void Afficher();
    int Min(int tab[], unsigned int nbElements, int minPrecedent, int max);
    int Max(int tab[], unsigned int nbElements);
    bool EstEgal ( const Ensemble & unEnsemble ) const;
    bool EstInclusionStricte ( const Ensemble & unEnsemble ) const;
    crduEstInclus EstInclus(const Ensemble & unEnsemble) const;
    bool ValEstInclus(int val) const;
    crduAjouter Ajouter (int aAjouter);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Ensemble ( const Ensemble & unEnsemble );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ensemble ( unsigned int cardMax = CARD_MAX );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Ensemble ( int t [] , unsigned int nbElements);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int *t;
int cardMax;
int cardAct;

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

