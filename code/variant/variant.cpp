/*

In the code below, replace inheritance with the use of a std::variant.

*/

#include <iostream>
#include <vector>
#include <memory>

struct Particle
 {
  virtual void print() = 0 ;
  virtual ~Particle() = default ;
 } ;

struct Electron : public Particle
 { virtual void print(){ std::cout<<"E"<<std::endl ; } } ;

struct Proton : public Particle
 { virtual void print(){ std::cout<<"P"<<std::endl ; } } ;

struct Neutron : public Particle
 { virtual void print(){ std::cout<<"N"<<std::endl ; } } ;

int main()
 {
  std::vector<std::unique_ptr<Particle>> ps;
  ps.push_back(std::make_unique<Electron>());
  ps.push_back(std::make_unique<Proton>());
  ps.push_back(std::make_unique<Neutron>());

  for ( auto const & p : ps )
   { p->print() ; }
 }