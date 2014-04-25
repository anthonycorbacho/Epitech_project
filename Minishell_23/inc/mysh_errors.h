
#ifndef __MYSH_ERRORS_H__
#define __MYSH_ERRORS_H__

#define COMMAND_NOT_FOUND_ERROR(s) command_not_found(s)
#define PERMISSION_DENIED_ERROR(s) permission_denied(s)
#define SEGMENTATION_FAULT_ERROR "My Segmentation fault\n"
#define FPE_ERROR "My Floating point exception\n"
#define BUS_ERROR "My Bus error\n"
#define ILL_INSTR_ERROR "Illegal instruction error\n"
#define OTHER_SIGNAL_ERROR(s) other_signal_e(s)

void		command_not_found(char *s);
void		permission_denied(char *s);
void		other_signal_e(char *s);
#endif
