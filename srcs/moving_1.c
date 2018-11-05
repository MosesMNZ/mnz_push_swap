/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:52:05 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 09:52:08 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	int_position(t_stack *sb, int j)
{
	int		goal;
	t_stack	*tmp;
	int		loc;
	int		i;

	tmp = sb;
	goal = j;
	loc = 0;
	i = 0;
	while (tmp)
	{
		if (goal == tmp->v)
		{
			loc = i;
		}
		tmp = tmp->nx;
		i++;
	}
	return (loc <= (i / 2) ? 1 : -1);
}

void		rot_gen(t_out *ret, t_stack **sa, t_stack **sb, int descending)
{
	int		tmp;

	tmp = 0;
	if (descending)
	{
		tmp = find_lagest(*sb);
		if (int_position(*sb, tmp) >= 0)
			while ((*sb)->v != tmp)
				update_op(ret, RB, sa, sb);
		else
			while ((*sb)->v != tmp)
				update_op(ret, RRB, sa, sb);
	}
	else
	{
		tmp = find_smallest(*sa);
		if (int_position(*sa, tmp) >= 0)
			while ((*sa)->v != tmp)
				update_op(ret, RA, sa, sb);
		else
			while ((*sa)->v != tmp)
				update_op(ret, RRA, sa, sb);
	}
}

void		struct_a_moves(t_stack *sa)
{
	int		i;
	t_stack	*tmpa2;

	i = 0;
	tmpa2 = sa;
	while (sa)
	{
		sa->maf = i;
		sa = sa->nx;
		i++;
	}
	tmpa2->mar = 0;
	tmpa2 = tmpa2->nx;
	i--;
	while (tmpa2)
	{
		tmpa2->mar = i;
		tmpa2 = tmpa2->nx;
		i--;
	}
}

static void	moving_around_sub(t_stack *sa, int *ar)
{
	if (ar[0] <= ar[1] && ar[0] <= ar[2] && ar[0] <= ar[3])
	{
		sa->moves = ar[0];
		sa->dir = 1;
	}
	else if (ar[1] <= ar[0] && ar[1] <= ar[2] && ar[1] <= ar[3])
	{
		sa->moves = ar[1];
		sa->dir = 2;
	}
	else if (ar[2] <= ar[0] && ar[2] <= ar[1] && ar[2] <= ar[3])
	{
		sa->moves = ar[2];
		sa->dir = 3;
	}
	else if (ar[3] <= ar[1] && ar[3] <= ar[0] && ar[3] <= ar[2])
	{
		sa->moves = ar[3];
		sa->dir = 4;
	}
}

void		moving_around(t_stack *sa)
{
	int		*ar;

	ar = (int *)malloc(sizeof(int) * 4);
	while (sa)
	{
		ar[0] = ((sa->maf > sa->mbf) ? sa->maf : sa->mbf);
		ar[1] = ((sa->mar > sa->mbr) ? sa->mar : sa->mbr);
		ar[2] = sa->maf + sa->mbr;
		ar[3] = sa->mar + sa->mbf;
		moving_around_sub(sa, ar);
		sa = sa->nx;
	}
	free(ar);
}
