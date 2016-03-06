#include "ins_fn.h"

void			ins_lfork(t_vm *vm, t_process *proc)
{
	t_process	*n_proc;
	t_list		*list;

	n_proc = safe_malloc(sizeof(t_process));
	ft_memcpy(n_proc, proc, sizeof(t_process));
	n_proc->pc = proc->pc + P_VAL_1;
	n_proc->number_cycles = 0;
	n_proc->proc_nb = vm->nb_proc++;
	list = ft_lstnew(n_proc, sizeof(t_process));
	list->next = vm->lst_process;
	vm->lst_process = list;
	proc->pc = (proc->pc + proc->curr_ins.size) % MEM_SIZE;
}
