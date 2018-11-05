/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:15:51 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 13:07:31 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	printing(t_out *ret)
{
	int		i;

	i = 0;
	while (ret)
	{
		if (ret->num == NOTHING)
		{
			break ;
		}
		printelement2(ret->num);
		ret = ret->nx;
		i++;
	}
}

static void	cleanup(t_stack **sa, t_stack **sb, t_out **ret)
{
	t_stack	*nx;
	t_out	*nxo;

	nxo = *ret;
	nx = *sa;
	while (nx)
	{
		nx = (*sa)->nx;
		free(*sa);
		*sa = nx;
	}
	nx = *sb;
	while (nx)
	{
		nx = (*sb)->nx;
		free(*sb);
		*sb = nx;
	}
	while (nxo)
	{
		nxo = (*ret)->nx;
		free(*ret);
		*ret = nxo;
	}
}

int			main(int ac, char **av)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_out	*ret;

	stacka = NULL;
	stackb = NULL;
	if (!(stacka = int_check(ac, av, stacka)))
		return (0);
	ret = outinit();
	process_algo(&stacka, &stackb, ret);
	printing(ret);
	cleanup(&stacka, &stackb, &ret);
	return (0);
}
