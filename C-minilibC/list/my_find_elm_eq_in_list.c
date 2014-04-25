

void		*my_find_elm_eq_in_list(t_list *begin,
				void *data_ref,
				int (*cmp)())
{
  while (begin && cmp(begin->data, data_ref))
    {
      begin = begin->next;
    }
  if (begin)
    return (begin->data);
  else
    return (0);
}
