#include <iostream>
#include <stdlib.h>

using namespace std;

class matrice;

class vect
{
private:
  double x, y, z;
public:
  vect(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void affiche() {
    cout << this->x << " " << this->y << " "<< this->z << endl;
  }

  friend vect prod(vect &v, matrice &m);
};

class matrice
{
private:
  int **arr;
public:
  matrice(int **arr) {
    this->arr = arr;
  }

  void affiche() {
    for (int i  = 0; i < 9; ++i) {
      cout << this->arr[i/3][i %3] << " " ;
      if (!((i+1) % 3)) {
	cout << endl;
      }
    }

  }
  
  friend vect prod(vect &v, matrice &m);

  ~matrice() {
    free(this->arr);
  }
};


vect prod(vect &v, matrice &m) {
  return vect(
	  v.x * m.arr[0][0] + v.y * m.arr[0][1] + v.z * m.arr[0][2],
	  v.x * m.arr[1][0] + v.y * m.arr[1][1] + v.z * m.arr[1][2],
	  v.x * m.arr[2][0] + v.y * m.arr[2][1] + v.z * m.arr[2][2]);
}



int main() {
  
  vect v = vect(1, 2, 3);
  int **arr = (int **) malloc(sizeof(int *) * 3);
  arr[0] =( int *) malloc(sizeof(int) * 3);
  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[0][2] = 3;
  arr[1] =( int *) malloc(sizeof(int) * 3);
  arr[1][0] = 4;
  arr[1][1] = 5;
  arr[1][2] = 6;
  arr[2] =( int *) malloc(sizeof(int) * 3);
  arr[2][0] = 7;
  arr[2][1] = 8;
  arr[2][2] = 9;
  
  
  matrice m = matrice(arr);
  vect v2 = prod(v, m);
  m.affiche();
  v2.affiche();
  
  return 0;
}
