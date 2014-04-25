#include <unistd.h>
#include <stdlib.h>

#include "fromlib.h"

int		pf_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      i++;
    }
  return (s1[i] - s2[i]);

}

int		pf_strlen(char *str)
{
  int		occur;
  char		*curr;

  occur = 0;
  curr = str;
  while (*curr != '\0')
    {
      occur++;
      curr++;
    }
  return (occur);
}

void		pf_putchar_e(char c)
{
  write(2, &c, 1);
}

void		pf_putstr_e(char *s)
{
  if (s != NULL)
    while (*s)
      {
	pf_putchar_e(*s);
	++s;
      }
}

t_list		*pf_insert_queue(t_list *list, t_list *elt)
{
  t_list	*save;

  save = list;
  if (list)
    {
      while (list->next)
	list = list->next;
      list->next = elt;
      elt->next = 0;
      return (save);
    }
  else
      return (pf_insert_head(list, elt));
}
