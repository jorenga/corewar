#ifndef PROCESS_OP_H
# define PROCESS_OP_H

# include "struct.h"
# include "op.h"
# include "error_util.h"
# include "define_error.h"
# include "utils.h"
# include "process_op_utils.h"
# include "safe_malloc.h"

int					process_op(char *str, t_error **err, t_list **token_op);

#endif
