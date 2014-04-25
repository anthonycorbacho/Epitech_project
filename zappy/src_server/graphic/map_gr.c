/*
** map_gr.c for zappy in /home/damien/work_local/z/src_server/graphic/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Wed Apr  7 16:04:28 2010 damien1 coppel
** Last update Sat Apr 24 14:03:06 2010 damien1 coppel
*/

#include "lmy_printf.h"
#include "lstr.h"
#include "lxsys.h"

#include "server.h"
#include "action_gr.h"
#include "map.h"
#include "position.h"
#include "str_utils.h"
#include "map.h"
#include "str_utils.h"

void		strcat_tmp_space_if_needed(int doit, char *content, char *tmp)
{
  if (doit)
    {
      my_strcat(content, tmp);
      my_strcat(content, " ");
    }
}

/*
** List the content of a case
** doit == 0 => only returns the string length
*/
int		get_map_case_content_gr(char *content, t_map_elt *cell,
					int doit)
{
  char		*tmp;
  int		len;
  int		i;

  len = 0;
  tmp = my_sprintf(cell->food);
  strcat_tmp_space_if_needed(doit, content, tmp);
  len += my_strlen(tmp) + 1;
  free(tmp);
  i = -1;
  while (++i < NB_ROCKS)
    {
      tmp = my_sprintf(cell->rocks[i]);
      strcat_tmp_space_if_needed(doit, content, tmp);
      len += my_strlen(tmp) + 1;
      free(tmp);
    }
  return (len);
}

/*
** List the content of a case
** request: bct X Y\n
*/
char		*map_case_content_gr(char *request)
{
  char		*content;
  t_pos		*pos;
  t_map_elt	*cell;
  int		len;

  len = my_strlen(request);
  pos = extract_coordinates_from_str(request + 4);
  cell = get_cell(pos->x, pos->y);
  len += get_map_case_content_gr(NULL, cell, 0);
  content = xmalloc(sizeof(*content) * len + 2);
  my_strcpy(content, request);
  content[my_strlen(content) - 1] = ' ';
  get_map_case_content_gr(content, cell, 1);
  content[my_strlen(content) - 1] = '\n';
  content[my_strlen(content)] = 0;
  free(pos);
  return (content);
}

void		add_case(char *current, char *sx, int x, int y)
{
  t_map_elt	*cell;
  char		*sy;

  current = my_strcat_back(current, "bct ");
  sy = my_sprintf(y);
  cell = get_cell(x, y);
  current = my_strcat_back(current, sx);
  current = my_strcat_back(current, " ");
  current = my_strcat_back(current, sy);
  current = my_strcat_back(current, " ");
  get_map_case_content_gr(current, cell, 1);
  current = my_strcat_back(current, "\n");
  free(sy);
}

char		*map_all_case_content_gr()
{
  char		*content;
  char		*current;
  int		x;
  int		y;
  char		*sx;

  content = xmalloc(sizeof(*content) * map_size.x * map_size.y * 66);
  content[0] = 0;
  current = content;
  x = -1;
  while (++x < map_size.x)
    {
      y = -1;
      sx = my_sprintf(x);
      while (++y < map_size.y)
	add_case(current, sx, x, y);
      free(sx);
    }
  return (content);
}
