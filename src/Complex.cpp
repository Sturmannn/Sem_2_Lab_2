#define _USE_MATH_DEFINES
#include "Complex.h"
#include <cmath>


TComplex::TComplex()
{
  re = 1;
  im = 1;
}

TComplex::TComplex(double _re, double _im)
{
  SetRe(_re);
  SetIm(_im);
}

TComplex::TComplex(const TComplex& p)
{
  re = p.re;
  im = p.im;
}

double TComplex::GetRe()
{
  return re;
}

double TComplex::GetIm()
{
  return im;
}

double TComplex::GetFi()
{
  if (re == 0)	return (M_PI / 2.0) * ((im > 0) ? 1 : ((im < 0) ? -1 : 0));
  if (re > 0)  return atan(im * 1.0 / re);
  if (re < 0 && im >= 0)  return atan(im * 1.0 / re) + M_PI;
  if (re < 0 && im < 0)  return atan(im * 1.0 / re) - M_PI;
}

void TComplex::SetRe(double _re)
{
  this->re = _re;
}

void TComplex::SetIm(double _im)
{
  this->im = _im;
}

TComplex TComplex::operator+(TComplex& p)
{
  TComplex A;
  A.re = re + p.re;
  A.im = im + p.im;
  return A;
}

TComplex TComplex::operator-(TComplex& p)
{
  TComplex A;
  A.re = re - p.re;
  A.im = im - p.im;
  return A;
}

TComplex TComplex::operator*(TComplex& p)
{
  TComplex A;
  A.re = (re * p.re) - (im * p.im);
  A.im = (re * p.im) + (im * p.re);
  return A;
}

TComplex TComplex::operator/(TComplex& p)
{
  TComplex A;
  A.re = (re * p.re + im * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
  A.im = (im * p.re - re * p.im) * 1.0 / (p.re * p.re + p.im * p.im);
  return A;
}

TComplex& TComplex::operator=(const TComplex& p)
{
  re = p.re;
  im = p.im;
  return *this;
}

void TComplex::Print()
{
  double r = Abs();
  double fi = GetFi();
  if (abs(re) < 0.000000001 && abs(re) > 0)  re = 0;
  if (abs(im) < 0.000000001 && abs(im) > 0)  im = 0;
  if (im < 0)
  {
	std::cout << r << " * (cos (" << fi << ") + i * sin (" << fi << ")) = "
	  << re << " - i * " << abs(im) << std::endl;
  }
  else 
  {
	std::cout << r << " * (cos (" << fi << ") + i * sin (" << fi << ")) = "
	  << re << " + i * " << im << std::endl;
  }
}

TComplex TComplex::Pow(double n)
{
  TComplex A;
  A.re = pow(Abs(), abs(n)) * cos(abs(n) * GetFi() );
  A.im = pow(Abs(), abs(n)) * sin(abs(n) * GetFi() );
  
  if (n < 0)
  {
	TComplex res(1, 0);
	return res / A;
  }
  return A;
}

TComplex TComplex::Pow(TComplex& p)
{
  TComplex A = Pow(p.re);
  double tmp_re1 = pow(M_E, ((p.im * atan(im * 1.0 / re)) * (-1))); 
  double tmp_im1 = (p.im) * log(Abs()); 
  double _re2 = tmp_re1 * cos(tmp_im1); 
  double _im2 = tmp_re1 * sin(tmp_im1); 
  double tmp_A_re = A.re;
  A.re = (A.re * _re2) - (A.im * _im2);
  A.im = (tmp_A_re * _im2) + (A.im * _re2);
  
  return A;
}

double TComplex::Abs()
{
  return sqrt(pow(re ,2) + pow(im , 2));
}

bool TComplex::operator==(TComplex& p)
{
  if ((p.re == re) && (p.im == im))  return true;
  else return false;
}

std::istream& operator>>(std::istream& B, TComplex& A)
{
  B >> A.re;
  B >> A.im;
  return B;
}

std::ostream& operator<<(std::ostream& B, TComplex& A)
{
  if (A.im < 0)	B << A.re << " - i*" << abs(A.im);
  else B << A.re << " + i*" << A.im;
  return B;
}
