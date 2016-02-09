#ifndef ERROR_UTIL_H
# define ERROR_UTIL_H

# include "struct.h"
# include <libft.h>
# include <ft_printf.h>

# define COM_ERR_QUOTE	"Quote not valid"
# define INVALID_LINE	"Invalid line"

t_error		*get_error(char *description);
void		*print_error(void *data);
int			ret_error(char *description);

#endif
