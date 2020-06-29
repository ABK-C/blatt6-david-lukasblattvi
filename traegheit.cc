#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include "Kugel.hh"
#include "Koerper.hh"
#include <iostream>
#include <memory>

double traegheit (Koerper* k, Vektor a, Vektor u) {
  std::cout << "berechne fuer  " << k->name() << '\n';
  const int N = 10000;      // Anzahl Integrationspunkte
  double M = k->masse();
  double J = 0; 
  double m = M / N;         // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();  //Vektor für Zylindermantel
    double r = (u.kreuz(x - a)).betrag()/u.betrag(); //Abstand zur Rotationsachse
    J += m * r * r;
  }
  return J;
}

int main() {
  const double M = 1;      // Masse 
  const double R = 1.0;    // Radius 
  const double L = 1.0;    // Laenge 

  Vektor a;                // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u;                // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr<Koerper> k(new Zylindermantel(R, L, M));
  std::cout<<traegheit(k.get(), a, u)<<'\n';
  std::unique_ptr<Koerper> v(new Vollzylinder(R, L, M));
  std::cout<<traegheit(v.get(), a, u)<<'\n';
  std::unique_ptr<Koerper> w(new Kugel(R, M));
  std::cout<<traegheit(w.get(), a, u)<<'\n';
            
  return 0;
}