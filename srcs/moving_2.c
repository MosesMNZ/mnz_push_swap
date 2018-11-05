/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:52:20 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 09:52:26 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	b_move_help_1(t_stack *sa, t_stack *tmpb)
{
	int		i;

	i = 0;
	while (sa->v > tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	while (sa->v < tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

static int	b_move_smallest(t_stack *tmpb, t_stack *sb)
{
	int		i;

	i = 1;
	while (tmpb->v != find_smallest(sb))
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

static int	b_move_largest(t_stack *tmpb, t_stack *sb)
{
	int		i;

	i = 0;
	while (tmpb->v != find_lagest(sb))
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

static int	b_move_help_2(t_stack *tmpb, t_stack *sa)
{
	int		i;

	i = 0;
	while (sa->v < tmpb->v)
	{
		i++;
		tmpb = tmpb->nx;
	}
	return (i);
}

void		struct_b_move(t_stack *sa, t_stack *sb)
{
	int		i;
	t_stack	*tmpb;

	if (!(sb))
		return ;
	while (sa)
	{
		i = 0;
		tmpb = sb;
		if (sa->v < (find_end(&tmpb)->v) && sa->v > tmpb->v)
			;
		else if (sa->v > find_lagest(sb))
			i = b_move_largest(tmpb, sb);
		else if (sa->v < find_smallest(sb))
			i = b_move_smallest(tmpb, sb);
		else if (sa->v > (find_end(&tmpb)->v) && sa->v > tmpb->v)
			i = b_move_help_1(sa, tmpb);
		else
			i = b_move_help_2(tmpb, sa);
		sa->mbf = i;
		sa->mbr = (find_length(sb)) - i;
		sa = sa->nx;
	}
}
