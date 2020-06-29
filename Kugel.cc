#include "Kugel.hh"

#include <cmath>
#include <math.h>
#include <cstdlib>

Kugel::Kugel(double nr, double m) {
  r_ = nr;
  m_ = m;
}

double Kugel::masse() {
  return m_;
}

Vektor Kugel::punkt() {
  double P = rand() / (double)RAND_MAX;
  double R = r_* std::cbrt(P);
  double phi = 2 * M_PI * rand() / (double)RAND_MAX;
  double theta = M_PI * rand() / (double)RAND_MAX;

  double x = R*sin(theta)*cos(phi);
  double y = R*sin(theta)*sin(phi);
  double z = R*cos(theta);
  return Vektor(x, y, z);
};