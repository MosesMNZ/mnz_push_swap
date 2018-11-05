/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 07:54:34 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 07:54:37 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpb;
	t_stack *tmpa;

	tmpb = *stackb;
	tmpa = *stacka;
	if (*stacka && (*stacka)->nx)
	{
		while (tmpa->nx)
		{
			tmpa = tmpa->nx;
		}
		tmpa->nx = *stacka;
		(tmpa->pv)->nx = NULL;
		(*stacka)->pv = tmpa;
		(*stacka) = tmpa;
		(*stacka)->pv = NULL;
	}
}

void	rrb_op(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmpb;
	t_stack *tmpa;

	tmpb = *stackb;
	tmpa = *stacka;
	if (*stackb && (*stackb)->nx)
	{
		while (tmpb->nx)
			tmpb = tmpb->nx;
		tmpb->nx = *stackb;
		(tmpb->pv)->nx = NULL;
		(*stackb)->pv = tmpb;
		(*stackb) = tmpb;
		(*stackb)->pv = NULL;
	}
}

void	rrr_op(t_stack **stacka, t_stack **stackb)
{
	rra_op(stacka, stackb);
	rrb_op(stacka, stackb);
}
