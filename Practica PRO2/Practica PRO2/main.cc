/**
 * @mainpage Disseny modular: Experiments genètics en un laboratori.

S'ofereix un menú d'opcions per gestionar les classes que formen part de l'experiment genètic. S'introdueixen les classes <em>Especie</em> i <em>Poblacio</em>.

Nomès es documenten elements públics.
*/

/** @file main.cc
    @brief Programa principal de la pràctica <em><b>Experiments genètics en un laboratori</b></em>.
*/


#include "Especie.hh"
#include "Poblacio.hh"
#include "Individu.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif



/** @brief Programa principal de la pràctica <em>Experiments genètics en un laboratori</em>.
*/
int main(){

    Especie esp;

    esp.establir_genetica();

    Poblacio poble;
    
    int ninicials;
    
    
    cerr << "Introdueix el número d'individus inicials" << endl;
    cin >> ninicials;
    
    for (int i = 0; i < ninicials; i++) {
        poble.llegir_individu(esp);
    }
    
    string accio;

    while (cin >> accio and accio != "acabar"){
        
        if (accio == "anadir_individuo"){
            poble.llegir_individu(esp);
        }

        else if (accio == "reproduccion_sexual"){
            cerr << "Introdueix nom de la mare, pare i fill" << endl;
            string nmare, npare, nfill;
            cin >> nmare >> npare >> nfill;
            
            Individu pare, mare, fill;
            
            bool trobat = true;
            
            mare = poble.buscar_individu(nmare, trobat);
            pare = poble.buscar_individu(npare, trobat);
            
            if (trobat) {
                
            fill.reproduir(pare, mare, npare, nmare, nfill, esp);
            

            poble.afegir_individu(nfill, fill);
            }
            
            else cout << "no es posible reproduccion" << endl;
        }

        else if (accio == "escribir_arbol_genealogico"){
            poble.escriure_arbre();
        }

        else if (accio == "completar_arbol_genealogico"){
            string nom;
            cin >> nom;
            poble.completar_arbre(nom);
        }

        else if (accio == "escribir_poblacion"){
            poble.escriure_poblacio();
        }

        else if (accio == "escribir_genotipo"){
            Individu ind;
            string nom;
            cin >> nom;
            
            bool trobat = true;
            
            ind = poble.buscar_individu(nom, trobat);
            
            if (trobat) ind.escriure_genotip(esp);
        }
    }

}
