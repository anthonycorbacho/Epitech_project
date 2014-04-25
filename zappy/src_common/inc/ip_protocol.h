/*
** ip_protocol.h for ip prot in /work/Dropbox/Epitech/Tek2/zappy_2012s_coppel_a/src_common
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Mon Mar 15 19:41:20 2010 mathieu1 lornac
** Last update Sat Mar 20 15:39:16 2010 mathieu1 lornac
*/

#ifndef __IP_PROTOCOL__
#define __IP_PROTOCOL__

/*
** Sends the string to the specified fd
** returns 0 in succes
** 1 if an error occurs
*/
int		my_send(int fd, char *s);
char		*hasbnoz(char *, char *);

/*
** Reads fron the specified file descriptor
** Mallocs the necessary space
** returns (char *) -1 if an error occurs
*/
char		*my_receive(int fd);
int		my_ip_receive(int socket, char **buf, int len);
#endif /*__IP_PROTOCOL__*/
