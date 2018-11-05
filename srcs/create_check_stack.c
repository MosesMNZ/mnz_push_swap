/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_check_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 07:55:49 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 12:40:38 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		is_valid_num(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (ps_big_atoi(av[i]) > INT_MAX || ps_big_atoi(av[i]) < INT_MIN)
			return (0);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				;
			else if (!ft_isdigit(av[i][j]))
			{
				if (!(av[i][j] == '-' && ft_isdigit(av[i][j + 1])))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void		split_arg(t_stack **stack, char *avin)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = ft_strsplit(avin, ' ');
	while (tmp[j])
	{
		(*stack)->v = (int)ps_big_atoi(tmp[j]);
		if (!tmp[j + 1])
			break ;
		(*stack)->nx = stack_initializer();
		((*stack)->nx)->pv = (*stack);
		(*stack) = (*stack)->nx;
		j++;
	}
	j = 0;
	while (tmp[j])
	{
		free(tmp[j]);
		j++;
	}
	free(tmp);
}

static t_stack	*create_stack(char **av)
{
	int		i;
	t_stack	*stack;
	t_stack *begin;

	i = 1;
	stack = stack_initializer();
	begin = stack;
	while (av[i])
	{
		split_arg(&stack, av[i]);
		if (!av[i + 1])
			return (begin);
		stack->nx = stack_initializer();
		(stack->nx)->pv = stack;
		stack = stack->nx;
		i++;
	}
	return (begin);
}

static int		dup_check(t_stack *stacka)
{
	int		nbr;
	int		flag;
	t_stack	*tmpa;
	t_stack *tmpb;

	tmpa = stacka;
	while (stacka)
	{
		nbr = stacka->v;
		flag = 0;
		tmpb = tmpa;
		while (tmpb)
		{
			if (tmpb->v == nbr)
				flag++;
			if (flag > 1)
				return (1);
			tmpb = tmpb->nx;
		}
		stacka = stacka->nx;
	}
	return (0);
}

t_stack			*int_check(int ac, char **av, t_stack *stacka)
{
	char	**tmp;

	tmp = av;
	if (ac < 2)
		return (NULL);
	if (!(ft_strcmp("-v", tmp[1])))
		tmp++;
	if (!is_valid_num(tmp))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stacka = create_stack(tmp);
	if (dup_check(stacka))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stacka);
}
