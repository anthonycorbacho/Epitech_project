int			my_apply_on_eq_in_list(t_list *begin,
					       int (*f)(), 
					       void *data_ref,
					       int (*cmp)())
{
  while (begin)
    {
      if (!cmp(data_ref, begin->data))
	  f(begin->data);
      begin = begin->next;
    }
  return (0);
}
