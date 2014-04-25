/*
** my_memset.c for memset in /home/anthony/Dropbox/epitech/C/my_malloc/printf
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Mon Feb  8 01:50:28 2010 anthony1 corbacho
** Last update Sat Mar  6 14:15:51 2010 anthony1 corbacho
*/

#include	"header_server.h"

int			my_memset(void *ptr, char value, int size)
{
  char			*ptr_mem;
  int			cpt;

  cpt = 0;
  ptr_mem = ptr;
  while (cpt < size)
    {
      ptr_mem[cpt] = value;
      cpt++;
    }
  return (1);
}
