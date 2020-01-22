/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocspy.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:42 by abaur             #+#    #+#             */
/*   Updated: 2020/01/21 15:41:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOCSPY_H
# define MALLOCSPY_H

# include <stdlib.h>

#define SPYVERBOSE
#define SPYBRAVE

/*
** Allocates memory, and registers internally.
** You should use this instead of malloc on pointers
** @param size_t size The amount of bytes to allocate.
** @return void* A pointer to the memory, or NULL if an error occured.
*/

void	*spymalloc(size_t size);

/*
** Frees a pointer that was registered using either `spymalloc` or `spyreg`.
**
** This safely ignores NULL pointers.
** `SPYVERBOSE` prints a warning if the pointer is not registered or NULL.
** `SPYBRAVE` attempts to free even such pointers.
** @param void* pointer
*/

void	spyfree(void *pointer);

/*
** Registers a pointer internally.
** You can use this on pointer that were created without using `spymalloc`.
** In the end, `spymalloc(size)` is short for `spyreg(malloc(size))`.
**
** This safely ignores NULL pointers.
** `SPYVERBOSE` prints a warning if the pointer is NULL or already registered.
** @param void* pointer The pointer to register
** @return void* The same pointer, or NULL if an error occured. 
*/

void	*spyreg(void *pointer);

/*
** Unregisters a pointer internally.
** Use this on pointers that were registered, but freed without 'spyfree'.
** This has no effect if the pointer is not already registered.
** `SPYVERBOSE` prints a warning if the pointer is NULL or not registered.
** @param void* pointer The pointer to unregister
*/

void	spyunreg(void *pointer);

/*
** Prints all currently registered adresses.
*/

void	spylog(void);

/*
** Frees and unregister all known pointers.
*/

void	spyflush(void);

#endif
