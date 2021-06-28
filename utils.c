/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:47:20 by yujung            #+#    #+#             */
/*   Updated: 2021/06/28 16:00:51 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			error(t_stack *s1, t_stack *s2)
{
	ft_putstr_fd("Error\n", 2);
	del_stack(s1, s2);
	exit(1);
}

int				check_av(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '-' && ('0' <= str[i + 1] && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && !('0' <= str[i + 1] && str[i + 1] <= '9'))
		return (0);
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void			check_buf(t_stack *s1, t_stack *s2)
{
	int			i;
	int			*buf;

	buf = malloc(sizeof(int) * (s1->size + 1));
	set_buf(buf, s1, s1->size);
	sort_buf(buf, s1->size);
	i = 0;
	while (++i < s1->size)
	{
		if (buf[i] == buf[i - 1])
			error(s1, s2);
	}
}
