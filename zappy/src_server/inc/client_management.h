/*
** client_management.h for  in /home/matt/work/my_irc/my_irc
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sun Mar  7 14:01:16 2010 mathieu1 lornac
** Last update Wed Apr  7 14:53:44 2010 mathieu1 lornac
*/

#ifndef __CLIENT_MANAGEMENT__
#define __CLIENT_MANAGEMENT__

void		free_client(t_client *c);
t_client	*malloc_client();
void		new_client_connection(t_list **client_list, int server_fd);
void		remove_client(t_list **list_clients, t_client *cl, int to_free);

#endif /*__CLIENT_MANAGEMENT__*/
