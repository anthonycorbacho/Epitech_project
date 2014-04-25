#ifndef			__LIST_BASICS__
#define			__LIST_BASICS__

t_list                  *my_insert_head(t_list *list, t_list *elt);
t_list                  *my_remove_head(t_list *list);
void			*my_remove_right(t_list *list);
t_list			*go_to_elt_nb(t_list *list, int nb);
#endif			/*__LIST_BASICS__*/
