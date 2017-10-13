#include <iostream>

using namespace std;

class Point {
private:
  float x, y;
  
public:

  void initialise(float x, float y) {
    this->x = x;
    this->y = y;
  }

  void deplacer(float t1, float t2) {
    this->x += t1;
    this->y += t2;
  }

  void affiche () {
    cout << this->x << " "<< this->y << endl;
  }
};


int main() {
  Point p1, p2;
  
  float x, y;
  cin >> x >> y;
  p1.initialise(x, y);
  p1.affiche();
  cin >> x >> y;
  p2.initialise(x, y);
  p2.affiche();

  cin >> x >> y;
  p1.deplacer(x, y);

  cin >> x >> y;
  p2.deplacer(x, y);

  p1.affiche();
  p2.affiche();
  
  return 0;
}
