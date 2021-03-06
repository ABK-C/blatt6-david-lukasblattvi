#include "Vollzylinder.hh"

#include <cmath>
#include <cstdlib>

Vollzylinder::Vollzylinder(double nr, double nl, double m) {
  r_ = nr;
  l_ = nl;
  m_ = m;
}

double Vollzylinder::masse() {
  double masse = m_;
  return masse;
}

Vektor Vollzylinder::punkt() {
  double P = rand() / (double)RAND_MAX;
  double R = r_*sqrt(P);
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double z = l_ * (rand() / (double)RAND_MAX - 0.5);

  double x = R*cos(phi);
  double y = R*sin(phi);
  return Vektor(x, y, z);
};
