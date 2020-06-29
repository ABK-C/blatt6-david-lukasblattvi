#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Zylindermantel : public Koerper {
public:
  Zylindermantel(double nr, double nl, double m);
  double masse();
  std::string name() {return "Zylindermantel";}
  Vektor punkt();

private:
  double r_, l_, m_;
};

#endif
