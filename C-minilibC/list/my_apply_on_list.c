
int     my_apply_on_list(t_list *begin, int (*f)())
{
  while (begin)
    {
      f(begin->data);
      begin = begin->next;
    }
  return (0);
}
