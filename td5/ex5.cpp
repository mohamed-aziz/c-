
#include <iostream>

using namespace std;


class Vecteur3D {
private:
  float x, y, z;
public:
  const char * nom ;
  Vecteur3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }
  
  void affiche() {
    cout << "<" << this->x << "," << this->y << "," << this->z << ">"  << endl;
  }

  Vecteur3D operator+(Vecteur3D f) {
    Vecteur3D;
  }

  Vecteur3D operator*(Vecteur3D s) {
    s.y *= this->x;
    s.y *= this->y;
    s.z *= this->z;

    return s;
  }

  Vecteur3D operator=(Vecteur3D s) {
    return Vecteur3D();
    
  }
  
};


int main( ) {

  Vecteur3D* vec1 = new Vecteur3D("vec1");
  Vecteur3D* vec2 = new Vecteur3D("vec2");

  vec1->affiche();
  vec1->x = 1;
  vec1->y = 2;
  vec1->z = 3;
  vec1->affiche();

  vec2->affiche();
  vec2->x = 4;
  vec2->y = 5;
  vec2->z = 7;
  vec2->affiche();
  
  Vecteur3D* vec3 = new Vecteur3D("vec3");

  *vec3 = *vec1 + *vec2;
  vec3->nom = "vec3";
  
  vec3->affiche();

  *vec3 = *vec1 * *vec2;
  vec3->nom = "vec3";
  vec3->affiche();
  
  return 0;
}
