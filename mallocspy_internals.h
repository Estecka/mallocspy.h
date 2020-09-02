/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocspy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:42 by abaur             #+#    #+#             */
/*   Updated: 2020/01/23 13:39:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOCSPY_INTERNALS_H
# define MALLOCSPY_INTERNALS_H

# include "mallocspy.h"
# include "ft_printf.h"

/*
** Metadatas about registered variables.
** @var unsigned int lvl	The depth at which the variable was registered.
** @var void** ptr	The pointer to the variable that was registered.
*/

typedef struct s_spyvar	t_spyvar;
struct			s_spyvar
{
	unsigned int	lvl;
	void			**ptr;
};

t_spyvar		*g_spylist;
size_t			g_spycap;

unsigned int	g_spylevel;

#endif
