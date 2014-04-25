
#include <dirent.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "lstr.h"
#include "lxsys.h"

#include "my_getwd.h"

void		concat_2slash(char *p2, char *p, char *name)
{
  my_strcpy(p2, p);
  my_strcat(p2, "/");
  my_strcat(p2,name);
}

void		concat_slash(char *p2, char *name)
{
  my_strcat(p2, "/");
  my_strcat(p2, name);
}

void		get_p_to_norme(char *p, DIR **dir, struct stat *s, struct stat *s1)
{
  *dir = opendir(p);
  lstat(p, s);
  closedir(*dir);
  my_strcat(p, "/..");
  *dir = opendir(p);
  lstat(p, s1);
}

/*
**Get the current pwd
**path has to be allocated before the call and initialized to an empty string
**p has to be initialized with a dot
*/
void		my_get_pwd(char *path, char *p)
{
  struct stat	s;
  struct stat	s1;
  struct stat	s2;
  struct dirent	*rd;
  DIR		*dir;
  char		p2[255];

  get_p_to_norme(p, &dir, &s, &s1);
  if (!((s.st_ino == s1.st_ino) && (s.st_dev == s1.st_dev)))
    {
      while (((rd = readdir(dir)) != NULL))
	{
	  concat_2slash(p2, p, rd->d_name);
	  lstat(p2, &s2);
	  if ((s2.st_dev == s.st_dev) && (s2.st_ino == s.st_ino))
	    break;
	}
      if (!((s.st_ino == s1.st_ino) && (s.st_dev == s1.st_dev)))
	my_get_pwd(path, p);
      if (rd && ((s2.st_ino == s.st_ino) && (s2.st_dev == s.st_dev)))
	concat_slash(path, rd->d_name);
    }
  closedir(dir);
}

/*
**Allocates a new string and returns the absolute working directory
*/
char		*my_getwd()
{
  char		*p;
  char		*path;

  path = xmalloc(sizeof(*path) * MAXPATHLEN);
  p = xmalloc(sizeof(*p) * MAXPATHLEN * 5);
  p[0] = '.';
  p[1] = 0;
  path[0] = 0;
  my_get_pwd(path, p);
  if (path[0] == 0)
    {
      path[0] = '/';
      path[1] = 0;
    }
  free(p);
  return (path);
}
