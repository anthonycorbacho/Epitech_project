
int			reverse_l(t_list *elt)
{
  int			m;

  m = 0;
  if (elt->next)
      m = reverse_l(elt->next);
  if (m)
    {
      elt->next->next = elt;
      elt->next = 0;
    }
  return (1);
}

int			my_rev_list(t_list **begin)
{
  t_list		**curr;
  t_list		*list;

  if (list == 0)
    return (0);
  list = *begin;
  while(list->next)
    list = list->next;
  reverse_l(*begin);
  *begin = list;
  return (1);
}
