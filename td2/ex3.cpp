#include <iostream>

using namespace std;

class Pile {

private:
  int ple[50];
  int ptr = -1;
  
public:

  void push (int element) {
    this->ple[++this->ptr] = element;
  }

  int pop () {
    return this->ple[this->ptr--];
  }
  
  void affiche() {
    for (int i = this->ptr; i >= 0; --i) cout << this->ple[i] << endl; 
  }
};


int main() {

  Pile p1;
  int in ;

  cout << "Entrer -1 pour arreter" << endl;
  
  do {  
    cin >> in;  
    in != -1 && p1.push(in);
  } while (in != -1);

  p1.pop();
  p1.affiche();
  
  return 0;
}
