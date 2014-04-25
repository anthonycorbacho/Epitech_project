//
// ex_4.hpp for ex_4 in /home/Anthony/Epitech/piscine/cpp/piscine/D08/ex_4
// 
// Made by anthony1 corbacho
// Login   <corbac_b@epitech.net>
// 
// Started on  Mon May 10 18:07:03 2010 anthony1 corbacho
// Last update Mon May 10 22:58:06 2010 anthony1 corbacho
//

#ifndef __EX_4_H__
#define __EX_4_H__

#include <iostream>

template <typename T> struct    s_list
{
  s_list(T data)
  {
    this->next = NULL;
    this->data = data;
  }
        
  T                       data;
  struct s_list<T>*       next;
};

template <typename T>
struct s_list<T>&       addInList(struct s_list<T>*& begin, const T& data)
{
  struct s_list<T>		*elem = new s_list<T>(data);

  if (begin)
    elem->next = begin;
  begin = elem;
  return (*elem);
}

template <typename T>
struct s_list<T>&       addInListAtPos(struct s_list<T>*& begin, const T& data, int pos)
{
  struct s_list<T>		*save = begin;
  struct s_list<T>		*elem = new s_list<T>(data);
  int			i = 0;

  if (begin == NULL ||  pos <= 0)
    return addInList(begin, data);
  while (i != (pos - 1) && begin->next != NULL)
    {
      begin = begin->next;
      i++;
    }
  elem->next = begin->next;
  begin->next = elem;
  begin = save;
  return *elem;
}

template <typename T>
void                    removeInListAtPos(struct s_list<T>*& begin, int pos)
{ 
  if (pos >= 0 && pos < getListSize(*begin))
    {
      if (pos == 0)
	{
	  begin = begin->next;
	  return ;
	}
      struct s_list<T>		*save = begin;
      for (int i = 1; i < pos && save->next != NULL; i++)
	save = save->next;
      save->next = save->next->next;
      
    }
}

template<typename T>
int			findPos(struct s_list<T>*& begin, const T& base)
{
  struct s_list<T>		*save = begin;
  int				i = 0;
  
  while (save != NULL)
    {
      if (save->data == base)
	return i;
      save = save->next;
      i++;
    }
  return -1;
}

template<typename T>
bool			findPoscmp(struct s_list<T>* begin,
				   bool (&cmp)(const T base, const T elem),
				   const T& base)
{
  struct s_list<T>		*save = begin;
  int				i = 0;
  
  while (save != NULL)
    {
      if (cmp(save->data, base) == 1)
	return i;
      save = save->next;
      i++;
    }
  return -1;
}

template <typename T>
void                    removeMatchFromList(struct s_list<T>*& begin,
					    bool (&cmp)(const T base, const T elem),
					    const T& base)
{
  int			find = -1;

  find = findPoscmp(begin, cmp, base);
  if (find != -1)
    {
      removeInListAtPos(begin, find);
      removeMatchFromList(begin, base);
    }
}

template <typename T>
void                    removeMatchFromList(struct s_list<T>*& begin, const T& base)
{
    int			find = -1;

  find = findPos(begin, base);
  if (find != -1)
    {
      removeInListAtPos(begin, find);
      removeMatchFromList(begin, base);
    }
}

template <typename T>
void			reverseList(struct s_list<T>*& begin)
{
  struct s_list<T>	*now;
  struct s_list<T>	*next;

  now = 0;
  while (begin)
    {
      next = begin->next;
      begin->next = now;
      now = begin;
      begin = next;
    }
  begin = now;
}

/**/


template <typename T>
void                    sortList(struct s_list<T>*& begin,
				 int (&cmp)(const T first, const T second))
{
  T			sd;
  int			again = 1;
  
  while (again == 1)
    {
      again = 0;
      struct s_list<T>	*list = begin;
      if (list == NULL || list->next == NULL)
	break ;
      while (list->next != NULL)
	{
	  if (cmp(list->data, list->next->data) < 0)
	    {
	      again = 1;
	      sd = list->data;
	      list->data = list->next->data;
	      list->next->data = sd;
	    }
	  list = list->next;
	}
    }
}

template <typename T>
T*                      getElemInList(struct s_list<T>& begin, const T& data)
{
  struct s_list<T>	*save = &begin;
  while (save)
    {
      if (save->data == data)
	return &save->data;
      save = save->next;
    }
  return NULL;
}

template <typename T>
T*			getElemInListAtPos(struct s_list<T>& begin, int pos)
{
  struct s_list<T>	*save = &begin;
  int			cpt = 0;
  

  if (pos > 0 && pos < getListSize(begin))
    {
      while (save)
	{
	  if (pos == cpt)
	    return &save->data;
	  cpt++;
	  save = save->next;
	}
    }
  return NULL;
}

template <typename T>
int                     getListSize(struct s_list<T>& begin)
{
  int			cpt = 0;
  struct s_list<T>	*save = &begin;

  while (save)
    {
      save = save->next;
      cpt++;
    }
  return (cpt);
}

template <typename T>
void                    printList(struct s_list<T>& begin)
{
  struct s_list<T>		*save = &begin;

  while (save != NULL)
    {
      std::cout << save->data << std::endl;
      save = save->next;
    }
}

template <typename T>
void			destroyList(struct s_list<T>*& begin)
{
  struct s_list<T>	*s;
  struct s_list<T>	*n;
  n = begin;
  while (n)
    {
      s = n;
      n = n->next;
      delete s;
    }
  begin = NULL;
}

#endif /*__EX_4_H__*/
