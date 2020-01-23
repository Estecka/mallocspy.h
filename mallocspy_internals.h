/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocspy_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:42 by abaur             #+#    #+#             */
/*   Updated: 2020/01/21 15:41:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOCSPY_INTERNALS_H
# define MALLOCSPY_INTERNALS_H

# include "mallocspy.h"

typedef s_spyptr	t_spyptr;
struct s_spyptr
{
	void	*adress;
	size_t	size;
};

t_spyptr	*g_spylist = NULL;
size_t		g_spysize = 0;

short		spyptrrm(void *pointer);
short		spyptradd(void *pointer);
short		spyexpand();

#endif
