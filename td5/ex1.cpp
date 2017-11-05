#include <iostream>
using namespace std;

class Fraction
{
private:
  int num, den;

  int inner(int a, int b) {
      if (a*b == 0) return a+b;
      return inner(b, a % b);
  }

  
  int pgcd(int a, int b) {
    inner(abs(a), abs(b));
  }
  
public:
  Fraction(int num, int den) {
    this->num = num;
    this->den = den;
  }

  Fraction operator+(Fraction &v) {
    return Fraction((v.den* this->num + v.num * this->den) / pgcd(v.den, this->den) ,
		    pgcd(v.den, this->den) != 1? pgcd(v.den, this->den): v.den * this->den);
  }

  Fraction operator*(Fraction &v) {
    int d = pgcd(this->num * v.num, this->den * v.den);
    return Fraction(v.num * this->num /d, v.den * this->den/d);
  }
  ;
  Fraction operator-(Fraction &v) {
    return Fraction(v.den * this->num - v.num * this->den ,v.den * this->den);
  }

  Fraction operator-() {
    return Fraction(- this->num, this->den);
  }

  Fraction operator/(Fraction &v) {
    int d = pgcd(this->num * v.den, this->den * v.num);
    return Fraction(this->num * v.den / d, this->den * v.num / d);
  }
  
  void __repr__() {
    cout << this->num<< "/" << this->den<< endl;
  }
  
};


int main() {

  Fraction f1 = Fraction(6, 2);
  Fraction f2 = Fraction(5, 3);

  Fraction f3 = -(f1 + f2);
  f3.__repr__();
  (f3 + f1).__repr__();
  
  return 0;
}
