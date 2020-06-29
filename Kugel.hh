#ifndef KUGEL_HH
#define KUGEL_HH

#include "Vektor.hh"
#include "Koerper.hh"

class Kugel : public Koerper {
public:
  Kugel(double nr, double m);
  double masse();
  std::string name() {return "Kugel";}
  Vektor punkt();

private:
  double r_, m_;
};

#endif