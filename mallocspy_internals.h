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

/*
** A pointer to the printf function to use for logging, if allowed.
*/
int				(*g_printf)(const char*, ...);

void	***g_spylist;
size_t	g_spycap;

#endif
