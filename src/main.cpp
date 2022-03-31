#include "Complex.h"

inline void line()
{
  std::cout << std::endl;
}

int main() 
{
  TComplex z1;
  TComplex z2(3, 4);
  TComplex z3 = z2;
  TComplex res;

  std::cout << "z1 = " << z1 << "\t\t" << "z2 = " << z2 << "\t\t" << "z3 = " << z3 << std::endl;
  line();

  if (z2 == z3) std::cout << "z2 == z3" << std::endl;
  line();

  z1.SetRe(2);
  z1.SetIm(6);
  std::cout << "z1 = " << z1 << std::endl;
  line();

  z3 = z1 + z2;
  std::cout << "z3 = z1 + z2 = " << z1 << " + " << z2 << " = " << z3 << std::endl;
  line();

  z2 = z3 - z1;
  std::cout << "z2 = z3 - z1 = " << z3 << " - (" << z1 << ") = " << z2 << std::endl;
  line();

  z1 = z3 / z2;
  std::cout << "z1 = z3 / z2 = (" << z3 << ") / (" << z2 << ") = " << z1 << std::endl;
  line();

  std::cout << "z3 = a + i*b; Input a and b:" << std::endl;
  line();

  std::cin >> z3;
  line();

  z2 = z1 * z3;
  std::cout << "z2 = z1 * z3 = (" << z1 << ") * (" << z3 << ") = " << z2 << "\n\n";
  line();
  
  res = z3.Pow(2);
  std::cout << "z3^2 = (" << z3 << ")^2 = ";
  res.Print();
  line();

  res = z3.Pow(0.4);
  std::cout << "z3^0.4 = (" << z3 << ")^0.4 = ";
  res.Print();
  line();

  res = z3.Pow(-2);
  std::cout << "z3^(-2) = (" << z3 << ")^(-2) = ";
  res.Print();
  line();

  res = z3.Pow(-0.4);
  std::cout << "z3^(-0.4) = (" << z3 << ")^(-0.4) = ";
  res.Print();
  line();
  
  res = z3.Pow(z2);
  std::cout << "z3^(z2) = (" << (z3) << ")^(" << (z2) << ") = ";
  res.Print();
  line();

  return 0;
}