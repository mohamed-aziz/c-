#include <iostream>
#include <strings.h>

using namespace std;

class set_char {
private:
  // char self[100];
  char sz;
  string a;

public:
  
  set_char() {

    // sz = 0;
  }
  
  
  void ajouter(char f) {
    
    // self[sz++] = f;
    // self[sz] = 0;
  }

  bool appartient(char f, int s=0) {
    for (int i = 0; i < s || this->a.length(); ++i) {
      if (this->a[i] == f) return true;
    }
    return false;
  }

  int cardinal () {
    int card = 0;
    for (int i = 0; i < this->a.length(); ++i) {
      appartient(this->a[i], i) && card++;
    }

    return card;

  }

  void lire() {
    cin >> this->a;
    for (int i = 0; i < this->a.length(); ++i) {
      this->ajouter(this->a[i]);
    }
  }
  
};


int main()
{
  set_char * s = new set_char();

  s->lire();
  
  cout << s->cardinal() << endl;
  
  return 0;
  
}
