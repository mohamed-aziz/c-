#include <iostream>
#include <math.h>


class Vecteur3D
{
private:
  float x, y, z;
public:
  Vecteur3D(float c1=0, float c2=0, float c3=0) {
    x = c1;
    y = c2;
    z = c3;
    
  }

  bool coincide1 (Vecteur3D v) {
    return (this->x == v.x
	    && this->y == v.y
	    && this->z == v.z);
  }

  bool coincide2 (Vecteur3D *v) {
    return (this->x == v->x
	    && this->y == v->y
	    && this->z == v->z);
  }

  bool coincide3 (Vecteur3D &v) {
    return (this->x == v.x
	    && this->y == v.y
	    && this->z == v.z);
  }

  float norme() {
    return sqrt(this->x * this-> x
	     + this->y * this->y
	     + this->z * this->z);
  }

  Vecteur3D normax1(Vecteur3D v) {
    return (this->norme() > v.norme()) ? *this : v;
  }

  Vecteur3D *normax2(Vecteur3D *v) {
    return (this->norme() > v->norme()) ? this : v;
  }
  
  
};


int main() {

  Vecteur3D *v1 = new Vecteur3D(1, 2, 3);
  Vecteur3D *v2 = new Vecteur3D(4, 5, 6);

  
  std::cout << v1->coincide1(*v2) << std::endl;
  std::cout << v1->coincide2(v2)  << std::endl;
  std::cout << v1->coincide3(*v2) << std::endl;
  
  return 0;
}
