#include "ins_fn.h"

void	ins_st(t_vm *vm, t_process *proc)
{
	int		src;

	src = proc->reg[P_VAL_1 - 1];
	if (proc->curr_ins.param_type[1] & T_IND)
	{
		write_n_bytes(4, vm->mem_space, proc->pc + (P_VAL_2 % IDX_MOD), src);
		proc->pc = (proc->pc + proc->curr_ins.size) % MEM_SIZE;
		return ;
	}
	proc->reg[P_VAL_2 - 1] = src;
	proc->pc = (proc->pc + proc->curr_ins.size) % MEM_SIZE;
}
