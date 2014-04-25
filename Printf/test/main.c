/*
** TEST
*/

#include "limits.h"
#include "lmy_printf.h"

#define my_printf my_printf

int		main()
{
  char		str[] = "jd jd ksj dkj djk djk djk";
  
  my_printf("%d\n", my_printf("chaine de test"));
  
  my_printf("%d\n",my_printf("%00-0.-004d\n", 42));
  my_printf("%d\n",my_printf("%.0x\n", 42));
  my_printf("%i\n",my_printf("%#0-134.-2X\n", 42));
  my_printf("%d\n",my_printf("%#0-134.-135X\n", 42));
  my_printf("%i\n",my_printf("%-+#00d\n", -42));

  my_printf("%d\n",my_printf("%00-0.004u\n", -42));
  my_printf("A\n");
  
  my_printf("%d\n",my_printf("%u\n", -0));
  my_printf("A\n");
  my_printf("%d\n",my_printf("%#5x\npouet\n", 42));
  my_printf("A\n");
  my_printf("%i\n",my_printf("%%%%%d\n", 42));
  my_printf("A\n");
  my_printf("%d\n",my_printf("%%%%%d\n", 42));
  my_printf("A\n");
  my_printf("%d\n",my_printf("%#5x\npouet\n", 42));
  my_printf("A\n");
  my_printf("%i\n",my_printf("%%%%%d\n", 42));
  my_printf("A\n");
  my_printf("%d\n",my_printf("0.0o\n", 42));
  my_printf("A\n");

  my_printf("%d\n",my_printf("%%d\n", 42));
  my_printf("%d\n",my_printf("%.0llhd\n", -42));
  my_printf("%d\n",my_printf("%d\n", str));
  my_printf("%d\n", my_printf("te:%.5s:%-32.14s$\n", "chaine de test", "terwe"));
  my_printf("%d\n", my_printf("te:%#.5s:%0#-32.14s$\n", "ch", "terwe"));
  my_printf("%d\n", my_printf("%#.5s:%0#-32.14s$\n", "ch", "terwe"));
   
  my_printf("%d\n", my_printf("%045s:%#032.1s$\n", "ch", "terwe"));
  my_printf("%d\n", my_printf("%045s:%#0-32.1s$\n", "ch", "terwe"));
  my_printf("%d\n", my_printf("%c$\n", 'h'));
  
  
  my_printf("%d\n", my_printf("%#.1d:%0#-32.0d$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%#-56.1d:%0#-3.14d$\n", UINT_MAX, UINT_MAX));
  
  my_printf("%d\n", my_printf("% +.16d:%0# +32.0d$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%-.1d:%0#-32.0d$\n", UINT_MAX, UINT_MAX));
  my_printf("%d\n", my_printf("%#.1d:%0#-32.0d$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%#.1d:%0#-32.0d$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%#-56.1x:%0#-3.14x$\n", UINT_MAX, UINT_MAX));
  
  my_printf("%d\n", my_printf("% +.16X:%0# +32.0X$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%-.1X:%0#-32.0X$\n", UINT_MAX, UINT_MAX));
  my_printf("%d\n", my_printf("%#.1X:%0#-32.0X$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%#.1u:%0#-32.0u$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%#-56.1o:%0#-3.14o$\n", UINT_MAX, UINT_MAX));
  my_printf("%d\n", my_printf("% +.16o:%0# +32.0o$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%#-.1o:%0#-32.0o$\n", UINT_MAX, UINT_MAX));
  my_printf("%d\n", my_printf("%#23.31u:%0#-32.0u$\n", INT_MIN, INT_MAX));
  my_printf("%d\n", my_printf("%#23.31u:%0# -13.0u$\n",0, 0));
  my_printf("%d\n", my_printf("%#44.1X:%0#-32.0X$\n", 0, 0));
  my_printf("%d\n", my_printf("%1d:%0-2.6d$\n", 0, 0));

  my_printf("%d\n", my_printf("% +.16llX:%0# +32.0llX%s$\n", LLONG_MIN, LLONG_MAX,"hsjkdfh"));
  my_printf("%d\n", my_printf("%-.1llX:%0#-32.0llX$\n", LLONG_MIN, ULLONG_MAX));
  my_printf("%d\n", my_printf("%#.1lld:%0#-32.0lld$\n", LLONG_MIN, ULLONG_MAX));
  my_printf("%d\n", my_printf("%#.1llu:%0#-32.0llu$\n", LLONG_MIN, ULLONG_MAX));
  my_printf("%d\n", my_printf("%#-56.1llo:%0#-3.14llo$\n", LLONG_MIN, LLONG_MAX));
  my_printf("%d\n", my_printf("% +.1ll6o:%0# +32.0llo$\n", LLONG_MIN, LLONG_MAX));
  my_printf("%d\n", my_printf("%#-.1llo:%0#-3ll2.0llo$\n", LLONG_MIN, LLONG_MAX));
  my_printf("%d\n", my_printf("%#23.31u:%0#-32.0u$\n", LLONG_MIN, LLONG_MAX));
  my_printf("%d\n", my_printf("%#23.31llu:%0# -13.0llu$\n",0, 0));
  my_printf("%d\n", my_printf("%#44.1llX:%0#-32.0llX$\n", 0, 0));
  my_printf("%d\n", my_printf("%1lld:%0-2.6lld$\n", 0, 0));
  
  char *a = 0;
  my_printf("%d\n", my_printf("%s", a));
  a = malloc(sizeof(*a));
  my_printf("%d\n", my_printf("%p", a));
  my_printf("%d\n", my_printf("%p", a));
  my_printf("NEW TEST\n");
  my_printf("%d\n", my_printf(""));
  my_printf("%d\n", my_printf(0));
  my_printf("%d\n", my_printf("%-+1~sdf$"));	    
  char c;

  c = '$';
  free(a);
  my_printf("%d\n", my_printf("%-+#.3c&", c));
  my_printf("%d\n", my_printf("%-#6.2c", c));
  my_printf("%d\n", my_printf("%-4.5c", c));
  my_printf("%d\n", my_printf("%3.4c", c));
  my_printf("%d\n", my_printf("%.4c", c));
  my_printf("%d\n", my_printf("%45c", c));
  my_printf("%d\n", my_printf("%-+#.3p&", a));
  my_printf("%d\n", my_printf("%-#6.2p&", a));
  my_printf("%d\n", my_printf("%-42.52p&", a));
  my_printf("%d\n", my_printf("%32.24p&", a));

  my_printf("[%.0c]\n", c);
  my_printf("[%-010c]\n", c);
  my_printf("[%-0.3c]\n", c);
  my_printf("[%-010.3c]\n", c);
  my_printf("[%.0c]\n", c);

  my_printf("[%s]\n", str);
  my_printf("[%.0s]\n", str);
  my_printf("[%10.4s]\n", str);
  my_printf("[%0.0s]\n", str);
  my_printf("[%.1s]\n", str);

  my_printf("%d\n", my_printf("%-+#.6hhd|%s\n&", c, str));
  my_printf("%d\n", my_printf("%-#6.2hhd|%s\n&", c), str);
  my_printf("%d\n", my_printf("%-4.5hhd|%s", c, str));

  my_printf("\nShort and long strings tests\n");
  my_printf("%d\n", my_printf("%-+#.6hhs|%s\n&", str, str));
  my_printf("%d\n", my_printf("%-#6.2lls|%hs\n&", str), str);
  my_printf("%d\n", my_printf("%-4.5lls|%ls", str, str));

  char *str2;
  str2 = pf_strdup("jdfhjkh");
  str2[2] = 12;
  my_printf("%d\n", my_printf("%-+#.6hhS|%S\n", str2, str2));
  my_printf("%d\n", my_printf("%-#6.2hhS|%S\n", str2, str2));
  my_printf("%d\n", my_printf("%-4.5hhS|%S", str2, str2));

  my_printf("%d\n", my_printf("%-+#.0hhS|%S\n", str2, str2));
  my_printf("%d\n", my_printf("%-#6.0hhS|%S\n", str2, str2));
  my_printf("%d\n", my_printf("%-0.0hhS|%S", str2, str2));

  my_printf("CHAR ATACK\n");
  c = 0;
  my_printf("[%.0c]\n", c);
  c = 127;
  my_printf("[%-010c]\n", c);
  my_printf("[%-0.3c]\n", c);
  c = '@';
  my_printf("[%-010.3c]\n", c);
  my_printf("[%.0c]\n", c);
  free(str2);
  return (1);
}
