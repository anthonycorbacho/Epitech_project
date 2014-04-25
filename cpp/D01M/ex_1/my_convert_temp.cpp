//
// my_convert_temp.cpp for  my_convert_temp in /home/corbac_b/work/piscine/cpp/D01M/ex_1
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May  3 11:16:02 2010 anthony1 corbacho
// Last update Mon May  3 12:12:34 2010 anthony1 corbacho
//
#include	<iomanip>
#include	<iostream>
using	namespace	std;

void		calcul_temp_cel(float tmp)
{
  float		calcul;

  calcul = 9.0 / 5.0 * tmp + 32;
  cout.precision(3);
  cout << setw(16) << fixed << calcul << setw(16) << "Fahrenheit" << endl;
}

void		calcul_temp_fah(float tmp)
{
  float		calcul;

  calcul = 5.0 / 9.0 * (tmp - 32);
  cout.precision(3);
  cout << setw(16) << fixed << calcul << setw(16) << "Celsius" << endl;
}

int		main()
{
  char		buffer[300];
  float		temp;

  temp = 0;
  cin >> temp >> buffer;
  if (strncmp(buffer, "Celsius", 7) == 0)
    calcul_temp_cel(temp);
  if (strncmp(buffer, "Fahrenheit", 10) == 0)
    calcul_temp_fah(temp);
  return (1);
}
