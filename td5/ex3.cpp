#include <iostream>

using namespace std;

class Date
{
private:
  int jj, mm;
public:
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
  
  void __repr__() {
    cout << this->jj<< "/" << this->mm<< endl;
  }

  
  
};




int main()  {

  Date d = Date(3, 1);
  Date d1 = Date(29, 1);
  
  (d + d1).__repr__();
  (d + d1 - d).__repr__();
  return 0;
}
