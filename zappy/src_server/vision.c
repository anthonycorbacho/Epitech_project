/*
** vision.c for vision related in /home/matt/work/zappy
** 
** Made by mathieu1 lornac
** Login   <lornac_a@epitech.net>
** 
** Started on  Sat Mar 20 15:46:26 2010 mathieu1 lornac
** Last update Wed Apr 21 10:26:34 2010 damien1 coppel
*/

#include "llist.h"
#include "lstr.h"
#include "lxsys.h"

#include "definitions.h"
#include "map.h"
#include "server.h"
#include "process_clients.h"
#include "position.h"
#include "cell_listing.h"
#include "vision.h"
#include "str_utils.h"

/*
** Up view
*/
int		get_view_1(t_client *cl, char *buffer, int doit)
{
  int		cur_level;
  t_pos		cur_pos;
  int		first;
  int		ret;

  ret = 0;
  cur_level = 0;
  while (cur_level <= cl->level)
    {
      set_pos(&(cur_pos), &(cl->pos));
      cur_pos.x -= cur_level;
      cur_pos.y -= cur_level;
      first = 1;
      while (cur_pos.x <= cl->pos.x + cur_level)
	{
	  if (!first)
	    ret += cat_virgule(buffer, doit);
	  ret += get_cell_content(&cur_pos, buffer, cl->id, doit);
	  (cur_pos.x)++;
	  first = 0;
	}
      if (++cur_level <= cl->level)
	ret += cat_virgule(buffer, doit);
    }
  return (ret);
}

/*
** Down view
*/
int		get_view_3(t_client *cl, char *buffer, int doit)
{
  int		cur_level;
  t_pos		cur_pos;
  int		first;
  int		ret = 0;

  cur_level = 0;
  ret = 0;
  while (cur_level <= cl->level)
    {
      set_pos(&(cur_pos), &(cl->pos));
      cur_pos.x += cur_level;
      cur_pos.y += cur_level;
      first = 1;
      while (cur_pos.x >= cl->pos.x - cur_level)
	{
	  if (!first)
	    ret += cat_virgule(buffer, doit);
	  ret += get_cell_content(&cur_pos, buffer, cl->id, doit);
	  (cur_pos.x)--;
	  first = 0;
	}
      if (++cur_level <= cl->level)
	ret += cat_virgule(buffer, doit);
    }
  return (ret);
}

/*
** Right view
*/
int		get_view_2(t_client *cl, char *buffer, int doit)
{
  int		cur_level;
  t_pos		cur_pos;
  int		first;
  int		ret;

  ret = 0;
  cur_level = 0;
  while (cur_level <= cl->level)
    {
      set_pos(&(cur_pos), &(cl->pos));
      cur_pos.x += cur_level;
      cur_pos.y -= cur_level;
      first = 1;
      while (cur_pos.y <= cl->pos.y + cur_level)
	{
	  if (!first)
	    ret += cat_virgule(buffer, doit);
	  ret += get_cell_content(&cur_pos, buffer, cl->id, doit);
	  (cur_pos.y)++;
	  first = 0;
	}
      if (++cur_level <= cl->level)
	ret += cat_virgule(buffer, doit);
    }
  return (ret);
}

/*
** Left view
*/
int		get_view_0(t_client *cl, char *buffer, int doit)
{
  int		cur_level;
  t_pos		cur_pos;
  int		first;
  int		ret;

  ret = 0;
  cur_level = 0;
  while (cur_level <= cl->level)
    {
      set_pos(&(cur_pos), &(cl->pos));
      cur_pos.x -= cur_level;
      cur_pos.y += cur_level;
      first = 1;
      while (cur_pos.y >= cl->pos.y - cur_level)
	{
	  if (!first)
	    ret += cat_virgule(buffer, doit);
	  ret += get_cell_content(&cur_pos, buffer, cl->id, doit);
	  (cur_pos.y)--;
	  first = 0;
	}
      if (++cur_level <= cl->level)
	ret += cat_virgule(buffer, doit);
    }
  return (ret);
}

/*
** Returns the view for the specified client
** Mallocs the string containing the view
*/
char		*get_view(t_client *cl)
{
  char		*str;
  int		len;
  int		(*func_pt[4])() = {get_view_0, get_view_1,
				   get_view_2, get_view_3};

  str = NULL;
  len = func_pt[cl->orientation](cl, str, 0);
  str = xmalloc(sizeof(*str) * len + 4);
  *str = '{';
  str[1] = 0;
  func_pt[cl->orientation](cl, str, 1);
  my_strcat(str, "}\n");
  return (str);
}
