/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocspy_internals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:42 by abaur             #+#    #+#             */
/*   Updated: 2020/01/21 15:41:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mallocspy_internals.c"

t_spyptr	*g_spylist = NULL;
size_t		g_spycap = 0;

/*
** Initialize or expands the list of pointer.
** The size of the list is then doubled.
** @return bool
** 	true  Expansion succesful
** 	false Allocation failed
*/

short 		spyexpand(void)
{
	t_spyptr	*newlist;
	size_t		newcap;
	size_t		i;

	newcap = g_spycap ? g_spycap * 2 : 32;
	if (!(newlist = malloc(newcap * sizeof(t_spyptr))))
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
		newlist[i++] = (t_spyptr){ 0 };
	g_spylist = newlist;
	g_spycap = newcap;
	return (1);
}

/*
** Removes a pointer from the list.
** @param void* The pointer to remove.
** @return bool
** 	true  The pointer was removed.
** 	false The pointer was not already registered.
*/

short		spyunreg(void *ptr)
{
	short	status;
	size_t	i;

	status = 0;
	i = 0;
	while (i < g_spycap)
	{
		if (g_spylist[i].adress == ptr)
		{
			g_spylist[i] = (t_spyptr){ 0 };
			status = 1;
		}
		i++;
	}
	return (status);
}