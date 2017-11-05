#include <iostream>

using namespace std;


class vecteur3d
{
private:
  float x, y, z;
public:
  vecteur3d(float c1=0, float c2 = 0, float c3= 0 ) {
    x = c1;
    y = c2;
    z = c3;
  }

  friend bool coincide(vecteur3d &v1, vecteur3d &v2);

  vecteur3d operator+(vecteur3d &v1) {
    return vecteur3d(v1.x + this->x, v1.y + this->y, v1.z + this->z);
  }
  
};

bool coincide(vecteur3d &v1, vecteur3d &v2) {
  return (v2.x == v1.x
	  && v2.y == v1.y
	  && v2.z == v1.z);

}

int main() {

  vecteur3d v1 = vecteur3d(1, 2, 3);
  vecteur3d v2 = vecteur3d(1, 2, 3);

  cout << coincide(v1, v2) << endl;
  
  return 0;
}
