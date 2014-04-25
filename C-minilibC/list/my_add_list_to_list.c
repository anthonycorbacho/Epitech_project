int			my_add_list_to_list(t_list **begin1,t_list *begin2)
{
  t_list		*cur;
  t_list		*save;

  save = begin2;
  cur = begin2;
  if (cur)
    {
      while (cur->next)
	  cur = cur->next;
      cur->next = *begin1;
      *begin1 = save;
    }
  return (0);
}
