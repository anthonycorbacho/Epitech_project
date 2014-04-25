
t_list		*my_find_node_eq_in_list(t_list *begin,
				void *data_ref,
				int (*cmp)())
{
  while (begin && cmp(begin->data, data_ref))
    {
      begin = begin->next;
    }
  if (begin)
    return (begin);
  else
    return (0);
}
