/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocspy_internals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:42 by abaur             #+#    #+#             */
/*   Updated: 2020/01/23 12:00:44 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mallocspy_internals.h"

void	**g_spylist = NULL;
size_t	g_spycap = 0;

/*
** Initialize or expands the list of pointer.
** The size of the list is then doubled.
** @return bool
** 	true  Expansion succesful
** 	false Allocation failed
*/

short	spyexpand(void)
{
	void	**newlist;
	size_t	newcap;
	size_t	i;

	newcap = g_spycap ? g_spycap * 2 : 32;
	if (!(newlist = malloc(newcap * sizeof(void*))))
		return (0);
	i = 0;
	if (g_spylist)
	{
		while (i < g_spycap)
		{
			newlist[i] = g_spylist[i];
			i++;
		}
		free(g_spylist);
	}
	while (i < newcap)
		newlist[i++] = NULL;
	g_spylist = newlist;
	g_spycap = newcap;
	return (1);
}

short	spyunreg(void *ptr)
{
	short	status;
	size_t	i;

	status = 0;
	i = 0;
	while (i < g_spycap)
	{
		if (g_spylist[i] == ptr)
		{
			g_spylist[i] = NULL;
			status = 1;
		}
		i++;
	}
	if (SPYVERBOSE && !status)
		ft_printf("Tried to unregister a pointer, \
but that pointer is unknown : %#p\n", ptr);
	return (status);
}
