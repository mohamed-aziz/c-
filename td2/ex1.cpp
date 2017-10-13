#include <iostream>

using namespace std;


class rectangle {
private:
  float largeur, hauteur;
  

public:

  rectangle(float, float);

  float perimetre() ;
  float surface();
  void affichage();
  
  
};

rectangle::rectangle(float x, float y) {
  this->largeur = x;
  this->hauteur = y;
}

float rectangle::perimetre() {
  return (this->largeur + this->hauteur) / 2;
}

float rectangle::surface() {
  return this->largeur * this->hauteur;
}

void rectangle::affichage() {
  cout << this->largeur << endl;
  cout << this->hauteur << endl;
  cout << this->surface() << endl;
  cout << this->perimetre() << endl;
}


int main() {

  float x, y;
  cin >> x >> y;
  
  rectangle rect(x, y);


  rect.affichage();
    
  
  return 0;
}
