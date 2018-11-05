/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 07:54:17 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 07:54:22 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_op(t_stack **stacka, t_stack **stackb)
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
		*stacka = (*stacka)->nx;
		(tmpa->nx)->nx = NULL;
		(tmpa->nx)->pv = tmpa;
	}
	(*stacka)->pv = NULL;
}

void	rb_op(t_stack **stacka, t_stack **stackb)
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
		*stackb = (*stackb)->nx;
		(tmpb->nx)->nx = NULL;
		(tmpb->nx)->pv = tmpb;
	}
	(*stackb)->pv = NULL;
}

void	rr_op(t_stack **stacka, t_stack **stackb)
{
	ra_op(stacka, stackb);
	rb_op(stacka, stackb);
}
