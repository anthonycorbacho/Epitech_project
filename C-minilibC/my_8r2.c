/*
** my_8r2.c for The queens problem in /home/lornac_a/work/Day5
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Fri Oct  9 10:53:54 2009 mathieu1 lornac
** Last update Mon Oct 12 23:06:48 2009 mathieu1 lornac
*/

void			pl_d(int c, int *freeplaces, int dir)
{
  int			a;
  int			raison;
  int			dest;

  dest = 7;
  raison = 7;
  if (dir)
    {
      raison = 9;
      dest = 0;
    }
  a = c;
  while (a % 8 != dest && a > 7)
      a -= raison;
  while (a < 64){
    *(freeplaces + a) = 0;
    if ((a % 8) == (7 - dest))
      a = 65;
    a += raison;
  }
}

void			pl_s(int c,  int *freeplaces)
{
  int			i;
  int			occur;
  int			j;

  occur = 0;
  i = c / 8 * 8;
  j = c % 8;
  while (occur++ < 8)
    {
      *(freeplaces + i) = 0;
      *(freeplaces + j) = 0;
      i++;
      j += 8;
    }
}

void			disp(int *free_places)
{
  int			i;

  i = 0;
  while (i < 64)
    {
      if (*(free_places + i) == 2)
        my_putchar( i % 8 + 49);
      i++;
    }
  my_putchar('\n');
}

void			backtrack(int placed, int *fp, int min)
{
  int			i;
  int			j;
  int			tab2[64];

  i = min;
  if (placed < 8){
    while (i++ < 64)
      {
	if (*(fp + i - 1) == 1)
	  {
	    j = 0;
	    while (j++ < 64)
		*(tab2 + j - 1) = *(fp + j - 1);
	    pl_s(i - 1, tab2);
	    pl_d(i - 1, tab2, 0);
	    pl_d(i - 1, tab2, 1);
	    *(tab2 + i - 1) = 2;
	    backtrack(placed + 1, tab2, i - 1);
	  }
      }
  }
  else
    disp(fp);
}

int			my_8r2()
{
  int			free_places[64];
  int			tab2[64];
  int			i;
  int			j;

  i = 0;
  while (i < 64)
    {
      free_places[i] = 1;
      i++;
    }
  i = 0;
  while (i < 8)
    {
      j = 0;
      while (j++ < 64)
	free_places[j] = 1;
      pl_s(i, free_places);
      pl_d(i, free_places, 0);
      pl_d(i, free_places, 1);
      *(free_places + i) = 2;
      backtrack(1, free_places, i);
      i++;
    }
  return (1);
}
