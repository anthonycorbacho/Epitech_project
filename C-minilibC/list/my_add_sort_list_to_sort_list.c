int		my_add_sort_list_to_sort_list(t_list **begin1,
					      t_list *begin2,
					      int (*cmp)())
{
  my_add_list_to_list(begin1, begin2);
  my_sort_list(begin1, cmp);
}
