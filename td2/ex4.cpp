#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


class Fichier
{
private:
  char *v;
  char **ptr;
  int taille;
  
public:  

  // ~Fichier();
  
  void Creation () {
    // pour '\0'
    taille = 1;

    this->v = (char * ) malloc(sizeof(char));

    this->v[0] = 0;

    this->ptr = &v;
  }
  
  void Remplit () {
    int rspace = random () % 100 ;
    this->v = (char *) realloc(this->v, taille + rspace);
    for (int i = 0; i < rspace; ++i) {
      this->v[taille + i -1] = 65 + random() % 26;
      
    }
    this->taille += rspace;
    this->v[this->taille] = 0;
  };

  void Affiche() {
    cout << *ptr << endl;
  }

  
};


int main() {


  // srand(121212);
  Fichier *a  = new Fichier();
  
  a->Creation();
  a->Remplit();

  a->Affiche();

  delete a;
  
  return 0;
}
