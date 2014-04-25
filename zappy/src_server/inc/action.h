/*
** action.h for zappy in /home/damien/work_local/my_zappy/src_server
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:35:01 2010 damien1 coppel
** Last update Sat Apr 10 15:36:39 2010 damien1 coppel
*/

#ifndef __ACTION_H__
#define __ACTION_H__

#include "server.h"

char	*avance(t_client *cl, t_request *req);
char	*broadcast(t_client *cl, t_request *req);
char	*connect_nbr(t_client *cl, t_request *req);
char	*droite(t_client *cl, t_request *req);
char	*expulse(t_client *cl, t_request *req);
char	*forky(t_client *cl, t_request *req);
char	*gauche(t_client *cl, t_request *req);
char	*incantation(t_client *cl, t_request *req);
char	*inventaire(t_client *cl, t_request *req);
char	*pose(t_client *cl, t_request *req);
char	*prend(t_client *cl, t_request *req);
char	*voir(t_client *cl, t_request *req);

/*
** send_graph.c
** Send information to the graphic client if there is one
*/
void	send_to_graph(char *to_send);


#endif /* __ACTION_H__ */
