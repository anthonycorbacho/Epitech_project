/*
N'oublions pas le header chers amis !
*/

#include	<time.h>
#include	<stdlib.h>

int		my_rand(int min, int max)
{
  static int	first = 1;

  if (first == 1)
    {
      srand(time(NULL));
      first = 0;
    }
  return (rand() % (max - min) + min);
}
