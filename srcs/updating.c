/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 07:53:40 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 10:50:56 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	update_op4(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbf;
	if (b > 0 & a > 0)
	{
		update_op(ret, RRA, sa, sb);
		update_op(ret, RB, sa, sb);
	}
	else if (b > 0)
		update_op(ret, RB, sa, sb);
	else if (a > 0)
		update_op(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbf -= 1;
}

static void	update_op3(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbr;
	if (b > 0 & a > 0)
	{
		update_op(ret, RA, sa, sb);
		update_op(ret, RRB, sa, sb);
	}
	else if (b > 0)
		update_op(ret, RRB, sa, sb);
	else if (a > 0)
		update_op(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbr -= 1;
}

static void	update_op2(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->mar;
	b = target->mbr;
	if (b > 0 & a > 0)
		update_op(ret, RRR, sa, sb);
	else if (b > 0)
		update_op(ret, RRB, sa, sb);
	else if (a > 0)
		update_op(ret, RRA, sa, sb);
	target->mar -= 1;
	target->mbr -= 1;
}

static void	update_op1(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int a;
	int b;

	a = target->maf;
	b = target->mbf;
	if (b > 0 & a > 0)
		update_op(ret, RR, sa, sb);
	else if (b > 0)
		update_op(ret, RB, sa, sb);
	else if (a > 0)
		update_op(ret, RA, sa, sb);
	target->maf -= 1;
	target->mbf -= 1;
}

void		update_gen(t_stack *target, t_stack **sa, t_stack **sb, t_out *ret)
{
	int		moves;

	moves = target->moves;
	while (moves)
	{
		if (target->dir == 1)
			update_op1(target, sa, sb, ret);
		else if (target->dir == 2)
			update_op2(target, sa, sb, ret);
		else if (target->dir == 3)
			update_op3(target, sa, sb, ret);
		else if (target->dir == 4)
			update_op4(target, sa, sb, ret);
		if (ordered(*sa))
			return ;
		moves--;
	}
}
