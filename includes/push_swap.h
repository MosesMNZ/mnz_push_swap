/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:02:06 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/12 12:57:36 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef	enum		e_optype
{
	sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, nothing
}					t_optype;

typedef	enum		e_onum
{
	SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR, NOTHING
}					t_onum;

typedef	struct		s_stack
{
	int				v;
	struct s_stack	*pv;
	struct s_stack	*nx;
	int				g;
	int				maf;
	int				mar;
	int				mbf;
	int				mbr;
	int				moves;
	int				dir;
}					t_stack;

typedef	struct		s_op
{
	t_optype		op;
	void			(*call)(t_stack **stacka, t_stack **stackb);
	struct s_op		*next;
}					t_op;

typedef struct		s_out
{
	t_onum			num;
	struct s_out	*nx;
}					t_out;

typedef struct		s_tmps
{
	int				tmp1;
	int				tmp2;
	int				flag;
}					t_tmps;

void				stacks_debug(t_stack *stacka, t_stack *stackb);
int					op_debug(t_op *begin);
int					find_lagest(t_stack *sb);
int					find_smallest(t_stack *sb);
void				struct_b_move(t_stack *sa, t_stack *sb);
void				moving_around(t_stack *sa);
void				struct_a_moves(t_stack *sa);
void				rot_gen(t_out *ret, t_stack **sa,\
		t_stack **sb, int descending);
void				update_gen(t_stack *target,\
		t_stack **sa, t_stack **sb, t_out *ret);
void				process_algo(t_stack **sa, t_stack **sb, t_out *ret);
t_stack				*stack_initializer();
t_op				*get_next_op();
t_stack				*int_check(int ac, char **av, t_stack *stacka);
int					ordered(t_stack *stackb);
int					almost_ordered_1(t_stack *stackb);
int					almost_ordered_2(t_stack *stackb, int tmp, int tmp2);
t_out				*outinit();
int					find_length(t_stack *stack);
t_stack				*find_end(t_stack **stack);
void				update_op(t_out *ret, t_onum op,\
		t_stack **sa, t_stack **sb);
void				printelement(t_optype num);
void				printelement2(t_onum num);
void				perfom_op(t_onum num, t_stack **sa, t_stack **sb);
void				sa_op(t_stack **stacka, t_stack **stackb);
void				sb_op(t_stack **stacka, t_stack **stackb);
void				pa_op(t_stack **stacka, t_stack **stackb);
void				pb_op(t_stack **stacka, t_stack **stackb);
void				ss_op(t_stack **stacka, t_stack **stackb);
void				ra_op(t_stack **stacka, t_stack **stackb);
void				rb_op(t_stack **stacka, t_stack **stackb);
void				rr_op(t_stack **stacka, t_stack **stackb);
void				rra_op(t_stack **stacka, t_stack **stackb);
void				rrb_op(t_stack **stacka, t_stack **stackb);
void				rrr_op(t_stack **stacka, t_stack **stackb);
#endif
