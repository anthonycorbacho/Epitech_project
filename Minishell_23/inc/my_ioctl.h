

#ifndef __MY_IOCTL_H__
#define __MY_IOCTL_H__

struct termios		get_conf(int fd);
struct winsize		get_dimensions(int x, int y);
void			sigwinch();
void			modify_conf();
void			set_conf(struct termios st, int fd);
#endif
