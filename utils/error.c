#include "../so_long.h"


/* Returns NULL printing <message> in red */
void	null_error(char *message,void *param)
{
	t_program		*program;

	program = (t_program *)param;
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	ft_close(0,param);
}
