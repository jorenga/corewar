#ifndef GET_PLAYERS_H
# define GET_PLAYERS_H

# include "corewar_struct.h"
# include "corewar_define.h"
# include "read_utils.h"
# include "swap_bytes.h"
# include "safe_malloc.h"

# include <unistd.h>
# include <fcntl.h>
# include <ft_printf.h>

int		get_players(t_vm *vm);
int		test_size(off_t off, char *name);
off_t	get_size(int fd);

#endif
