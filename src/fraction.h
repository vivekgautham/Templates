#ifndef FRAC_H
#define FRAC_H

#include "header.h"

class Fraction{
  private:
    int x=0;
    int y=0;
  public:
    Fraction (int a, int b) : x(a), y(b){
    }
    Fraction () {
    }
    bool operator> (const Fraction& k){
      if ( y == 0 && k.y != 0){
          return true;
      }
      if (k.y == 0 && y != 0 ){
          return false;
      }
      if ( ( (float)x/(float)y) > ( (float)k.x/(float)k.y) ){
        return true;
      }
      return false;
    }
    
    Fraction& operator+= (const Fraction& k){
      if (this->x == 0 && this->y == 0){
        this->x = k.x;
        this->y = k.y;
        return *this;
      }
      this->x = this->x * k.y + this->y * k.x;
      this->y = this->y * k.y;
      return *this;
    }
    Fraction& operator*= (const Fraction& k){
      this->x = this->x * k.x;
      this->y = this->y * k.y;
      return *this;
    }
};


bool betterThanExpected(std::vector <int> numerators, std::vector <int> denominators) {
  int cnt = 0;
  Fraction ans, half(1, 2);
  for (size_t i = 0; i < numerators.size(); i++) {
    Fraction cur(numerators[i], denominators[i]);
    if (cur > half) {
      ans += cur;
      cnt++;
    }
  }
  Fraction av(1, cnt), expectedAverage(3, 4);
  ans *= av;
  return ans > expectedAverage;
}

#endif