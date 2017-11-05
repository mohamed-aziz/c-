#include <iostream>

using namespace std;

class Date
{
private:
  int jj, mm;
public:

  Date() {

  }
  Date(int jj, int mm) {
    this->jj = jj;
    this->mm = mm;
  }

  int daysM(int mmm) {
    int days;
    switch (mmm) {
    case 9:
    case 11:
    case 6:
    case 4:
      {
	return 30;
	
      }

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      {
	return 31;
      }
    case 2:
      {
	return 28;
      }
     
    }
  }


  Date operator++() {
    if (this->jj ++ > daysM(this->mm)) {
      this->mm ++;
      this->jj = 1;
    }
  }


  
  Date operator--() {
    if (this->jj -- <= 0) {
      this->mm --;
      this->jj = daysM(this->mm);
    }
  }


  friend bool operator== (Date &d1, Date &d2);
  
  
  
  Date operator-(Date& d) {
    int i;
    int jjm = this->jj;
    int mmm = this->mm;
    
    for (i = 1; i <= d.mm; ++i) {
      jjm += daysM(i);
    }

    
    jjm += d.jj;
    while (1) {
      int days = daysM(mmm);
      if (jjm > days) {
	jjm -= days;
	mmm --;
      } else {
	break;
      }
      
    }
    
    return Date(jjm, mmm);

  }
  
  
  Date operator+(Date& d) {
    int i;
    int jjm = this->jj;
    int mmm = this->mm;
    
    for (i = 1; i <= d.mm; ++i) {
      jjm += daysM(i);
    }

    
    jjm += d.jj;
    while (1) {
      int days = daysM(mmm);
      if (jjm > days) {
	jjm -= days;
	mmm ++;
      } else {
	break;
      }

      
    }
    
    return Date(jjm, mmm);

  }
  void __repr__() {
    cout << this->jj<< "/" << this->mm<< endl;
  }


  friend ostream& operator<<(ostream& f, Date &d);
  friend istream& operator>>(istream& f, Date &d);
  
  
};


ostream& operator<<(ostream& f, Date &d) {
   f<< d.jj << "/" << d.mm<< endl;
}


istream& operator>>(istream& f, Date &d) {
  cout << "Entrer La date :" << endl;
  f >> d.jj >> d.mm;
}


bool operator== (Date &d1, Date &d2) {
    return (d1.jj == d2.jj && d2.mm == d1.mm);
}


int main()  {

  Date d = Date(3, 1);
  Date d1 = Date(29, 1);
  
  (d + d1).__repr__();

  cout << d1;

  Date d2;
  cin >> d2;

  cout << d2;
  
  return 0;
}
