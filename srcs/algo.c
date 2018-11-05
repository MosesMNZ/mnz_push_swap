/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:45:52 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 11:01:17 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insertbest(t_stack **sa, t_stack **sb, t_out *ret)
{
	t_stack		*tmp;
	t_stack		*target;
	int			moves;

	tmp = *sa;
	target = tmp;
	moves = tmp->moves;
	while (tmp)
	{
		if (tmp->moves < moves)
		{
			moves = tmp->moves;
			target = tmp;
		}
		tmp = tmp->nx;
	}
	update_gen(target, sa, sb, ret);
	update_op(ret, PB, sa, sb);
}

static void	merging(t_stack **sa, t_stack **sb, t_out *ret)
{
	while (*sb)
	{
		if ((*sb)->v > find_lagest(*sa))
		{
			rot_gen(ret, sa, sb, 0);
			update_op(ret, PA, sa, sb);
		}
		else if ((*sb)->v < find_smallest(*sa))
		{
			rot_gen(ret, sa, sb, 0);
			update_op(ret, PA, sa, sb);
		}
		else if ((*sb)->v > (*sa)->v)
			update_op(ret, RA, sa, sb);
		else if ((*sb)->v < (*sa)->v && (*sb)->v > (find_end(sa))->v)
			update_op(ret, PA, sa, sb);
		else
			update_op(ret, RRA, sa, sb);
	}
}

static int	sorting_three(t_stack **sa, t_stack **sb, t_out *ret)
{
	if (find_length(*sa) != 3)
		return (0);
	if ((*sa)->v == find_lagest(*sa) && ((*sa)->nx)->v < (find_end(sa))->v)
		return (1);
	else if ((*sa)->v > ((*sa)->nx)->v)
		update_op(ret, SA, sa, sb);
	else if ((*sa)->v == find_smallest(*sa) &&
			((*sa)->nx)->v == find_lagest(*sa))
		update_op(ret, SA, sa, sb);
	return (1);
}

static int	sorting_stuffs(t_stack **sa, t_stack **sb, t_out *ret, int size)
{
	int		i;
	int		num;

	i = 0;
	num = size;
	if (find_length(*sa) != num)
		return (0);
	while (i < (num - 3))
	{
		rot_gen(ret, sa, sb, 0);
		update_op(ret, PB, sa, sb);
		i++;
	}
	sorting_three(sa, sb, ret);
	i = 0;
	while (i < (num - 3))
	{
		rot_gen(ret, sa, sb, 0);
		update_op(ret, PA, sa, sb);
		i++;
	}
	return (1);
}

void		process_algo(t_stack **sa, t_stack **sb, t_out *ret)
{
	int		i;
	int		length;

	if (ordered(*sa) == 1)
		return ;
	i = 0;
	length = 3;
	if (find_length(*sa) > 101)
		length = 7;
	while (*sa)
	{
		if (almost_ordered_1(*sa) || sorting_stuffs(sa, sb, ret, length))
		{
			rot_gen(ret, sa, sb, 0);
			merging(sa, sb, ret);
			rot_gen(ret, sa, sb, 0);
			break ;
		}
		struct_a_moves(*sa);
		struct_b_move(*sa, *sb);
		moving_around(*sa);
		insertbest(sa, sb, ret);
	}
}
