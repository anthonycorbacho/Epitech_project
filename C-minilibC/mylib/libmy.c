#include <stdlib.h>

void			my_putchar(char c)
{
  write(1, &c, 1);
}

int			my_isneg(int n)
{
  if (n < 0)
      my_putchar('N');
  else
      my_putchar('P');
  return (1);
}

int			to_continuemyputnbr(int nb)
{
  long long		power;

  power = 1;
  while (nb / power != 0)
      power *= 10;
  power /= 10;
  while  (power != 0)
    {
      my_putchar(nb / power + 48);
      nb %= power;
      power /= 10;
    }
  return (1);
}

int			over_lmyputnbr(int nb)
{
  nb++;
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
  return (1);
}

int			my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
        {
          over_lmyputnbr(nb);
          return (1);
        }
      nb = - nb;
    }
  else
    {
      if (nb == 0)
	{
	  my_putchar('0');
	  return (1);
	}
    }
  to_continuemyputnbr(nb);
  return (1);
}

int			my_swap(int *a, int *b)
{
  int			t;

  t = *a;
  *a = *b;
  *b = t;
  return (1);
}

int			my_putstr(char *str)
{
  char			*s;

  s = str;
  while (*s)
    {
      my_putchar(*s);
      ++s;
    }
  return (1);
}

int			my_strlen(char *str)
{
  int			occur;
  char			*curr;

  occur = 0;
  curr = str;
  while (*curr != '\0')
    {
      occur++;
      curr++;
    }
  return (occur);
}

int			my_power(int nb, int p)
{
  int			i;
  int			ret;

  i = 0;
  ret = 1;
  while (i < p)
    {
      ret *= nb;
      i += 1;
    }
  return (ret);
}

int			get_signe(char *str)
{
  int			signe;
  char			*curr;

  curr = str;
  signe = 1;
  while (*curr == 43 | *curr == 45)
    {
      if (*curr == 45)
        {
          signe *= - 1;
        }
      curr++;
    }
  return (signe);
}

char			*get_nb_digits(char *str, int *occur)
{
  char			*ret;

  *occur = 0;
  while (*str == 43 | *str == 45)
    {
      str++;
    }
  ret = str;
  while (*str > 47 & *str < 58)
    {
      (*occur)++;
      str++;
    }
  (*occur)--;
  return (ret);
}

int			my_getnbr(char *str)
{
  int			signe;
  int			number;
  int			pm;
  char			*curr;

  signe = get_signe(str);
  str = get_nb_digits(str, &pm);
  number = 0;
  while (pm >= 0)
    {
      if (*str > 47 & *str < 58)
        {
          number += (*str - 48) * my_power(10, pm);
        }
      else
        {
          return (number * signe);
        }
      str++;
      pm--;
    }
  return (number * signe);
}

void			my_sort_int_tab(int *tab, int size)
{
  int			i;
  int			ordered;
  int			*c1;
  int			j;

  i = 0;
  ordered = 0;
  while ((i < size) & !ordered)
    {
      c1 = tab;
      j = 0;
      ordered = 1;
      while (c1 - tab < size - 1)
        {
          if (*c1 > *(c1 + 1))
            {
              ordered = 0;
              my_swap(c1, c1 + 1);
            }
          c1++;
        }
      i++;
    }
}

int			my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (nb == 1)
    return (1);
  if (nb == -1 && power % 2 == 0)
    return (1);
  if (nb == -1 && power % 2 == 1)
    return (-1);
  if (power > 1)
    return (nb * my_power_rec(nb, power - 1));
  else
    return (nb);
}

int			find_square(int nb, int bi, int bf)
{
  int			mil;

  if (bi * bi == nb)
    return (bi);
  mil = (bi + (bf - bi) / 2);
  if (bi < bf)
    {
      if (mil * mil == nb)
        return (mil);
      else
        {
          if (mil * mil > nb)
            return (find_square(nb, bi, mil - 1));
          else
            return (find_square(nb, mil + 1, bf));
        }
    }
  return (0);
}

int			my_square_root(int nb)
{
  if (nb <= 0)
    return (0);
  return (find_square(nb, 1, 46340));
}

int			find_rounded_square(int nb, int bi, int bf)
{
  int			 mil;

  if (bi * bi == nb)
    return (bi);
  mil = bi + (bf - bi) / 2;
  if (bi <= bf)
    {
      if (mil * mil == nb)
        return (mil);
      else
        {
          if (mil * mil < nb)
            {
              if ((mil + 1.0) * (mil + 1.0) > nb)
                return (mil);
              else
                return (find_rounded_square(nb, mil + 1, bf));
            }
          else
            return (find_rounded_square(nb, bi, mil - 1));
        }
    }
  else
    return (0);
}

int			my_rounded_square_root(int nb)
{
  if (nb < 0)
    return (0);
  return (find_rounded_square(nb, 0, 46340));
}

int			eratosthene(int nb, int *primes)
{
  int			b_max;
  int			i;
  int			offset;

  i = 0;
  b_max = my_rounded_square_root(nb);
  while (*(primes + i) <= b_max)
    {
      if (*(primes + i) == 0)
        {
          offset = 1;
          while (!eratosthene(*(primes + i - 1) + offset, primes))
            ++offset;
          *(primes + i) = *(primes + i - 1) + offset;
          --i;
        }
      else
        {
          if (nb % *(primes + i) == 0)
            return (0);
        }
      ++i;
    }
  return (1);
}

int			my_is_prime(int nombre)
{
  int			i;
  int			primes[1000000];

  if (nombre < 2)
    return (0);
  i = 0;
  while (++i < 1000000)
    primes[i] = 0;
  primes[0] = 2;
  return (eratosthene(nombre, primes));
}

int			my_find_prime_sup(int nb)
{
  int			i;
  int			primes[1000000];

  if (nb < 2)
    return (2);
  i = 0;
  while (++i < 1000000)
    primes[i] = 0;
  primes[0] = 2;
  while (!eratosthene(nb, primes))
    ++nb;
  return nb;
}

char			*my_strcpy(char *dest, char *src)
{
  int			i;

  i = 0;
  while (*(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
    }
  *(dest + i) = *(src + i);
  return (dest);
}

char			*my_strncpy(char *dest, char *src, int n)
{
  int			i;

  i = 0;
  while (n > 0 && *(src + i))
    {
      *(dest + i) = *(src + i);
      ++i;
      --n;
    }
  if (n > 0)
    *(dest + i) = '\0';
  return (dest);
}

char			*my_revstr(char *str)
{
  int			i;
  int			len;
  char			c;

  len = my_strlen(str);
  i = 0;
  while (i < len / 2)
    {
      c = *(str + i);
      *(str + i) = *(str + len - i - 1);
      *(str + len - i - 1) = c;
      ++i;
    }
  return (str);
}

char			*my_strstr(char *str, char *to_find)
{
  int			len;
  int			lens;
  int			offset;
  int			i;

  if (!to_find)
    return (str);
  len = my_strlen(str);
  lens = my_strlen(to_find);
  offset = 0;
  while (offset <= len - lens)
    {
      i = 0;
      while ( i < lens && *(str + i + offset) == *(to_find + i))
        ++i;
      if (i == lens)
        return (str + offset);
      ++offset;
    }
  return (0);
}

int                     my_strcmp(char *s1, char *s2)
{
  int                   i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      i++;
    }
  return (s1[i] - s2[i]);

}

int			my_strncmp(char *s1, char *s2, int n)
{
  while (n > 0 && *s1)
    {
      if (*s1 != *s2)
        return (*s1 - *s2);
      ++s1;
      ++s2;
      --n;
    }
  return (0);
}

char			*my_strupcase(char *str)
{
  char			*ret;

  ret = str;
  while (*str)
    {
      if (*str > 96 && *str < 123)
        *str -= 32;
      ++str;
    }
  return (ret);
}

char			*my_strlowcase(char *str)
{
  char			*ret;

  ret = str;
  while (*str)
    {
      if (*str > 64 && *str < 91)
        *str += 32;
      ++str;
    }
  return (ret);
}

char			*my_strcapitalize(char *str)
{
  int			to_cap;
  char			*s;

  s = str;
  to_cap = 1;
  while (*s)
    {
      if ((*s > 64 && *s < 91) || (*s > 96 && *s < 123) || (*s > 47 && *s < 58))
        {
          if (to_cap && (*s > 96 && *s < 123))
            *s -= 32;
          else
            if ((!to_cap) && (*s >64 && *s < 91))
              *s +=32;
          to_cap = 0;
        }
      else
        to_cap = 1;
      ++s;
    }
  return (str);
}

int                     my_char_isalpha(char s)
{
  return ((s > 64 && s < 91) || (s > 96 && s < 123));
}

int                     my_char_isnum(char s)
{
  return (s > 47 && s < 58);
}

int			my_str_isalpha(char *str)
{
  while (*str)
    {
      if (!((*str > 64 && *str < 91) || (*str > 96 && *str < 123)))
        return (0);
      ++str;
    }
  return (1);
}

int			my_str_isnum(char *str)
{
  while (*str)
    {
      if (!(*str > 47 && *str < 58))
        return (0);
      ++str;
    }
  return (1);
}

int			my_str_islower(char *str)
{
  while (*str)
    {
      if (!(*str > 96 && *str < 123))
        return (0);
      ++str;
    }
  return (1);
}

int                     my_str_isupper(char *str)
{
  while (*str)
    {
      if (!((*str > 64) && (*str < 91)))
        return (0);
      ++str;
    }
  return (1);
}

int			my_str_isprintable(char *str)
{
  while (*str)
    {
      if (*str < 32 || *str == 127)
        return (0);
      ++str;
    }
  return (1);
}

char                    *get_first_alpha_char(char *s)
{
  while (*s && !(my_char_isalpha(*s) || my_char_isnum(*s)))
    ++s;
  return s;
}

char                    *get_first_nonalpha_char(char *s)
{
  while (*s && (my_char_isalpha(*s) || my_char_isnum(*s)))
    ++s;
  return s;
}

void                    my_putnbr_basemodif(int nbr, char *base, int nbd)
{
  int                   base_v;
  int                   i;
  long long             power;
  long long             nb;

  nb = nbr;
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  power = 1;
  base_v = my_strlen(base);
  while (--nbd > 0)
    power *= base_v;
  while (power != 0){
    i = 0;
    while ((i < base_v) && (power * i <= nb))
      ++i;
    --i;
    my_putchar(base[i]);
    nb %= power;
    power /= base_v;
  }
}

void			my_char_printable (char str)
{
  if (str < 32 || str == 127)
    my_putchar('.');
  else
    my_putchar(str);
}

char                    *showline(char *line, char* orig)
{
  char                  *cursor;
  int                   i;

  i = 0;
  cursor = line;
  my_putnbr_basemodif((int)line - (int) orig, "0123456789abcdef", 8);
  my_putchar(':');
  my_putchar(' ');
  while (i++ < 16)
    {
      if (*line)
        my_putnbr_basemodif(*(line++), "0123456789abcdef", 2);
      else
        {
          my_putchar(' ');
          my_putchar(' ');
        }
      if (i % 2 == 0)
        my_putchar(' ');
    }
  while (cursor != line)
    my_char_printable(*(cursor++));
  my_putchar('\n');
  return (line);
}

int                     my_showmem(char *str)
{
  char                  *curr;

  curr = str;
  while (*curr)
    curr = showline(curr, str);
  return (0);
}

int                     my_char_isprintable(char str)
{
  if ((str < 32) || (str > 126))
    return (0);
  else
    return (1);
}

int                     my_showstr(char *str)
{
  while (*str)
    {
      if (my_char_isprintable(*str) != 0)
        my_putchar(*str);
      else
        {
          my_putchar('\\');
          my_putnbr_basemodif(*str, "0123456789abcdef", 2);
        }
      ++str;
    }
  return (0);
}

char			*my_strcat(char *str1, char *str2)
{
  char			*curr;

  curr = str1;
  while (*curr)
    ++curr;
  while (*str2)
    *(curr++) = *(str2++);
  *(curr) = *(str2);
  return (str1);
}

char			*my_strncat(char *str1, char *str2, int n)
{
  char			*curr;

  curr = str1;
  while (*curr)
    ++curr;
  while (n-- > 0 && *str2)
    *(curr++) = *(str2++);
  if (n == 0)
    ++curr;
  *(curr) = 0;
  return (str1);
}

int            my_strlcat(char *str1, char *str2, int l)
{
  int           i;
  int           s1;
  int           s2;

  s1 = my_strlen(str1);
  s2 = my_strlen(str2);
  i = s1;
  if (s1 > l)
    return (s2 + l);
  while (*str2 && i < l - 1)
    {
      *(str1 + i) = *str2;
      str2++;
      i++;
    }
  *(str1 + i) = '\0';
  return (s1 + s2);
}

int                     my_strchar(char *str, char to_find)
{
  int                   len;
  int                   i;

  if (!to_find)
    return (0);
  i = 0;
  len = my_strlen(str);
  while (i < len)
    {
      if (*(str + i) == to_find)
        return (i);
      ++i;
    }
  return (0);
}

long long               determine_power(char* str, int base)
{
  long long             power;
  int                   j;

  power = 1;
  j = 1;
  while (j++ < my_strlen(str))
    power *= base;
  return (power);
}

int                     my_getnbr_base(char *str, char *base)
{
  long long             power;
  int                   j;
  long long             ret;
  int                   minus;

  minus = 0;
  ret = 0;
  if (!str)
    return (0);
  if (*str == '-')
    {
      minus = - 1;
      str++;
    }
  power = determine_power(str, my_strlen(base));
  j = 0;
  while (j++ < my_strlen(str))
    {
      ret += my_strchar(base, *(str + j - 1)) * power;
      power /= my_strlen(base);
    }
  if (minus == - 1)
    return (- ret);
  return (ret);
}

int                     my_putnbr_base(int nbr, char *base){

  int                   base_v;
  int                   i;
  long long             power;
  long long             nb;

  nb = nbr;
  if (nb < 0)
    {
      nb = - nb;
      my_putchar('-');
    }
  power = 1;
  base_v = my_strlen(base);
  while (nb / power != 0)
    power *= base_v;
  power /= base_v;
  while (power != 0){
    i = 0;
    while ((i < base_v) && (power * i <= nb))
      ++i;
    --i;
    my_putchar(base[i]);
    nb %= power;
    power /= base_v;
  }
  return (1);
}

int			nbr_base_tocharp_tonorme(long long *nb , int *j, char *r)
{
  *j = 0;
  if (*nb < 0)
    {
      *nb = -(*nb);
      r[*j] = '-';
      ++(*j);
    }
  r[*j] = '0';
}

char			*nbr_base_tocharp(long long nb ,char *base)
{
  int			i;
  long long             power;
  char                  *r;
  int                   j;
 
  power = 1;
  i = 0;
  while (nb / power != 0)
    {
      power *= my_strlen(base);
      i++;
    }
  r = malloc(sizeof(*r) * (i + 1 + (r < 0)));
  if (r == NULL)
    return r;
  nbr_base_tocharp_tonorme(&nb, &j, r);
  power /= my_strlen(base);
  while (power != 0){
    i = 0;
    while ((i < my_strlen(base)) && (power * i <= nb))
      ++i;
    r[j] = base[i - 1];
    nb %= power;
    power /= my_strlen(base);
    ++j;
  }
  return (r);
}
