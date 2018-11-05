/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:09:05 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 14:07:02 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	perfectly_ordered(t_stack *stacka, t_stack *stackb)
{
	int		tmp;

	if (stackb)
		return (0);
	else if (!(stacka))
		return (0);
	tmp = stacka->v;
	while (stacka->nx)
	{
		if ((stacka->nx)->v > tmp)
			tmp = (stacka->nx)->v;
		else if ((stacka->nx)->v == tmp)
			return (2);
		else
			return (0);
		stacka = stacka->nx;
	}
	return (1);
}

static void	printing(t_stack **sa, t_stack **sb, t_op *oplist, int debug)
{
	t_op	*begin;

	begin = oplist;
	if (!(begin->call))
		return ;
	if (debug > 0)
	{
		ft_putstr_fd("YOU ARE IN DEBUG MODE\n", 2);
		op_debug(oplist);
		stacks_debug(*sa, *sb);
	}
	while (begin)
	{
		begin->call(sa, sb);
		if (debug > 0)
		{
			printelement(begin->op);
			stacks_debug(*sa, *sb);
		}
		begin = begin->next;
	}
}

int			main(int ac, char **av)
{
	t_op	*oplist;
	t_stack	*stacka;
	t_stack *stackb;
	int		tmp;

	tmp = 0;
	stacka = NULL;
	stackb = NULL;
	if (!(stacka = int_check(ac, av, stacka)))
		return (0);
	oplist = get_next_op();
	if (!(ft_strcmp("-v", av[1])))
		tmp = 1;
	printing(&stacka, &stackb, oplist, tmp);
	if ((tmp = perfectly_ordered(stacka, stackb)))
	{
		if (tmp == 1)
			ft_putstr("OK\n");
		else
			write(2, "Error\n", 6);
	}
	else
		ft_putstr("KO\n");
	return (0);
}
