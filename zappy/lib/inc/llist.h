/*
** my_list.h for header in /home/coppel_a
**
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
**
** Started on  Mon Oct 29 17:12:47 2007 damien1 coppel
** Last update Thu Apr 22 15:04:51 2010 mathieu1 lornac
*/

#ifndef			__MY_LIST_H__
# define		__MY_LIST_H__

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

/*
** my_add_list_to_list.c
*/
int			my_add_list_to_list(t_list **begin1, t_list *begin2);

/*
** my_add_sort_list_to_sort_list.c
*/
int			my_add_sort_list_to_sort_list(t_list **begin1,
						      t_list *begin2,
						      int (*cmp)());

/*
** my_apply_on_eq_in_list.c
*/
int			my_apply_on_eq_in_list(t_list *begin, int (*f)(),
					       void *data_ref, int (*cmp)());

/*
** my_apply_on_list.c
*/
int			my_apply_on_list(t_list *begin, int (*f)());

/*
** my_find_elm_eq_in_list.c
*/
void			*my_find_elm_eq_in_list(t_list *begin, void *data_ref,
					        int (*cmp)());

/*
** my_free_all_list.c
*/
int			my_free_all_list(t_list *begin);
int			my_free_all_list_struct(t_list *begin);

/*
** my_find_node_eq_in_list.c
*/
t_list			*my_find_node_eq_in_list(t_list *begin, void *data_ref,
						 int (*cmp)());

/*
** my_list_size.c
*/
int			my_list_size(t_list *begin);

/*
** my_params_in_list.c
*/
int			add_begin_list(t_list **liste, void *data);
t_list			*my_params_in_list(int ac, char **av);

/*
** my_put_elem_in_list.c
*/
int			my_put_elem_in_list(t_list **liste, void *data);

/*
** my_put_elem_in_sort_list.c
*/
int			my_put_elem_in_sort_list(t_list **begin, void *data,
						 int (*cmp)());

/*
** my_rev_list.c
*/
t_list			*goto_elem(t_list *list, int elem);
int			my_rev_list(t_list **begin);

/*
** my_rm_all_eq_from_list.c
*/
int			my_rm_all_eq_from_list(t_list **begin, void *data_ref,
					       int (*cmp)());

/*
** my_sort_list.c
*/
t_list			*got_s(t_list *list, int elem);
int			my_sort_list(t_list **begin, int (*cmp)());

#endif			/* __MY_LIST_H__ */
