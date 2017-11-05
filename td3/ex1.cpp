#include <iostream>

class Vecteur3D
{
private:
  float x, y, z;
  
public:
  Vecteur3D(float x=0, float y=0, float z=0) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void affichage() {
    std::cout << "Vect<("<< this->x << "," << this->y << ","<< this->z << ")>" << std::endl;
  }

  void somme1(Vecteur3D *vec) {
    this->x += vec->x;
    this->y += vec->y;
    this->z += vec->z;
  }
  
  void prodscalaire1(Vecteur3D *vec) {
    this->x *= vec->x;
    this->y *= vec->y;
    this->z *= vec->z;
  }

  
  Vecteur3D *somme2(Vecteur3D *vec) {
    Vecteur3D *v = new Vecteur3D();
    v->x = this->x + vec->x;
    v->y = this->y + vec->y;
    v->z = this->z + vec->z;
    return v;
  }
  
  Vecteur3D* prodscalaire2(Vecteur3D *vec) {
    Vecteur3D *v = new Vecteur3D();
    v->x = this->x * vec->x;
    v->y = this->y * vec->y;
    v->z = this->z * vec->z;
    return v;
  }
  
};


int main() {

  Vecteur3D *v1 = new Vecteur3D(1, 2, 3);
  Vecteur3D *v2 = new Vecteur3D(4, 5, 6);
  int f;
  std::cin >> f;

  v1->somme1(v2);
  
  v1->affichage();

  v1->prodscalaire1(v2);
  v1->affichage();

  Vecteur3D *v3 = new Vecteur3D(1, 2, 3);
  Vecteur3D *v4 = new Vecteur3D(4, 5, 6);
  Vecteur3D *v5 = v3->somme2(v4);
  v5->affichage();
  
  return 0;
}
