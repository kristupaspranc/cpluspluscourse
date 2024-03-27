#include <iomanip>
#include <iostream>
#include <numeric>

class Fraction {
 public:
  // TODO: constructors and operators
  Fraction(unsigned int n, unsigned int m = 1): m_num(n), m_denom(m){}

  Fraction& operator*=(const float a){
    m_num *= a;
    normalize();
    return *this;
  }

  void operator*=(const Fraction & a){
    m_num *= a.m_num;
    m_denom *= a.m_denom;
    normalize();
  }

 private:
  void normalize() {
    const int gcd = std::gcd(m_num, m_denom);
    m_num /= gcd;
    m_denom /= gcd;
  }

  friend std::ostream& operator<<(std::ostream&, const Fraction&);
  friend bool operator==(Fraction, Fraction);
  friend Fraction operator*(const Fraction, const float);
  friend Fraction operator*(const float, const Fraction);
  friend Fraction operator*(const Fraction&, const Fraction&);
  friend bool operator!=(Fraction a, Fraction b){return !(a==b);}
  friend bool operator<(const Fraction& a, const Fraction& b){return a.m_num*b.m_denom < b.m_num * a.m_denom;}
  friend bool operator<=(const Fraction a, const Fraction b){return (a==b)||(a<b);}
  friend bool operator>(const Fraction& a, const Fraction& b){return a.m_num*b.m_denom > b.m_num * a.m_denom;}
  friend bool operator>=(const Fraction a, const Fraction b){return (a==b)||(a>b);}
  unsigned int m_num, m_denom;
};

// TODO: operators
std::ostream& operator<<(std::ostream& os, const Fraction& obj){
  return os << obj.m_num << "/" << obj.m_denom;
}

bool operator==(Fraction a, Fraction b){
  a.normalize();
  b.normalize();
  return a.m_num == b.m_num && a.m_denom == b.m_denom;
}

Fraction operator*(Fraction a, const float b){
  a *= b;
  a.normalize();
  return a;
}

Fraction operator*(const float b, Fraction a){
  a *= b;
  a.normalize();
  return a;
}

Fraction operator*(const Fraction& a, const Fraction& b){
  Fraction c{a.m_num * b.m_num, a.m_denom * b.m_denom};
  c.normalize();
  return c;
}

void printAndCheck(std::string const & what, Fraction const & result, Fraction const & expected) {
  const bool passed = result == expected;
  std::cout << std::left << std::setw(40) << what << ": " << (passed ? "PASS" : "** FAIL **") << "    " << result << "\n";
}

void printAndCheck(std::string const & what, bool result, bool expected) {
  const bool passed = result == expected;
  std::cout << std::left << std::setw(40) << what << ": " << (passed ? "PASS" : "** FAIL **") << "    " << result << "\n";
}

int main() {
  // create a fraction with values 3 (which is 3/1) and 1/3
  const Fraction three{3};
  const Fraction six{6,2};
  const Fraction athird{1, 3};

  // print the fractions
  std::cout << "Three: " << three << '\n';
  std::cout << "One third: " << athird << '\n';
  
  // multiply fraction with an int
  // the printAndCheck function requires operator<< and operator==:
  printAndCheck("One third times two", athird * 2, Fraction{2, 3});
  // ensure symmetry
  printAndCheck("Two times one third", 2 * athird, Fraction{2, 3});

  // multiply two fractions
  printAndCheck("Three times one third", three * athird, Fraction{1, 1});
  // normalize the fraction after multiplication so the above statement
  // prints 1/1 instead of e.g. 3/3
  printAndCheck("Three times one third", 3 * athird, Fraction{1, 1});

  // multiply in place
  Fraction f = athird;
  f *= 2;
  printAndCheck("One third times two", f, Fraction{2, 3});

  std::cout << f << '\n';

  f *= athird;
  printAndCheck("Two third times one third", f, Fraction{2, 9});

  std::cout << f << '\n';

  

//   // you might have some redundancy between the implementation of operator* and
//   // operator*=. Can you refactor your code and implement operator* in terms of
//   // operator*=?

  std::cout << std::boolalpha;  // print bools as 'true' or 'false' from now on

//   // more equality comparisons
  printAndCheck("One third == one third", (athird == Fraction{1, 3}), true);
  printAndCheck("One third != one forth", (athird != Fraction{1, 4}), true);
  printAndCheck("One third == two sixth", (athird == Fraction{2, 6}), true);
  printAndCheck("One third != three sixth", (athird != Fraction{3, 6}), true);
//   // try to implement operator!= in terms of operator==

//   // more comparisons
  const Fraction afourth{1, 4};
  printAndCheck("athird < athird", (athird < athird), false);
  printAndCheck("afourth < athird", (afourth < athird), true);
  printAndCheck("athird  <= athird", (athird <= athird), true);
  printAndCheck("athird  <= afourth", (athird <= afourth), false);
  printAndCheck("athird  > athird", (athird > athird), false);
  printAndCheck("afourth > athird", (afourth > athird), false);
  printAndCheck("athird >= athird", (athird >= athird), true);
  printAndCheck("athird >= afourth", (athird >= afourth), true);
//   // the operators <=, >= and > can typically be implemented just in terms of
//   // operator<. Can you do this as well? ;)

//   // take aways on operators:
//   // * we can very often implement an arithemtic operator@ in terms of
//   // operator@=
//   // * it usually suffices to implement operator< and operator== and derive the
//   // other relational operators from them. C++20 will do part of this automatically.

return 0;
}
