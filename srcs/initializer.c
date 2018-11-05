/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:04:29 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/04 17:04:35 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_initializer(void)
{
	t_stack *stack;

	stack = (t_stack *)(malloc(sizeof(t_stack)));
	stack->pv = NULL;
	stack->nx = NULL;
	stack->g = 0;
	stack->maf = 0;
	stack->mar = 0;
	stack->mbf = 0;
	stack->mbr = 0;
	stack->moves = 0;
	stack->dir = 0;
	return (stack);
}

t_out	*outinit(void)
{
	t_out	*outlist;

	outlist = (t_out *)(malloc(sizeof(t_out)));
	outlist->nx = NULL;
	outlist->num = NOTHING;
	return (outlist);
}

void	update_op(t_out *ret, t_onum op, t_stack **sa, t_stack **sb)
{
	t_out	*tmp;

	tmp = ret;
	while (tmp->nx)
		tmp = tmp->nx;
	tmp->num = op;
	tmp->nx = outinit();
	perfom_op(op, sa, sb);
}

int		find_length(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->nx;
		i++;
	}
	return (i);
}

t_stack	*find_end(t_stack **stack)
{
	t_stack *end;

	if (!(*stack))
		return (NULL);
	end = *stack;
	while (end->nx)
		end = end->nx;
	return (end);
}
