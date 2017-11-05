#include <iostream>
#include <stdlib.h>

using namespace std;

class PileM
{

  // Implementation de Pile avec Memoire consecutive dynamique
public:
  PileM() {
    this->ple = (int *) malloc(sizeof(int));
    this->ptr = &this->ple;
  }

  bool push (int element) {
    (**this->ptr) = element;
    // need lvalue?
    int *f = (*this->ptr)+1;
    this->ptr = &f;
    f = (int *) malloc(sizeof(int));
  }

  int pop () {
    int *f = this->ple-1;
    this->ptr = &f;
    return **(this->ptr+1);
  }
  
  void affiche() {
    for (int *i = *(this->ptr); i >= this->ple; --i) cout << *i << endl; 
  }
  
  // ~PileM() ;
  
  
private:
  int *ple;
  int **ptr;
};


class Pile {
  // Implementation de Pile avec Memoire consecutive statique
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

  PileM *p1 = new PileM();
  int in;

  cout << "Entrer -1 pour arreter" << endl;
  
  do {  
    cin >> in;  
    in != -1 && p1->push(in);
  } while (in != -1);

  // p1->pop();
  p1->affiche();

  delete p1;
  
  return 0;
}
