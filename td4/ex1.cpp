

#include <iostream>

using namespace std;

class Point
{
private:
  int x, y;
  
public:
  Point(int abs=0, int ord=0) {
    x = abs;
    y = ord;  
  }
  
  friend void affiche(Point& p);
};




void affiche(Point& p) {
  cout << p.x << ", " << p.y << endl;
}

int main() {
  Point p = Point(1, 2);
  affiche(p);
  return 0;
}
