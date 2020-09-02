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

#ifndef MALLOCSPY_H
# define MALLOCSPY_H

# include <stdlib.h>

/*
** You may set these define to either 0 or 1 to change the behaviour of some fu
** nctions.
** `SPYVERBOSE` prints warning when invalid pointers are detected.
** `SPYBRAVE` causes invalid pointers to be processed like valid ones.
** `SPYPROXY` (deprecated, now only behaviour) causes mallocspy to treat pointe
** rs asbeing "second degree" instead of first degree. In other words, you regi
** ster the adress of a variable that holds a pointer instead of the pointer it
** self.
** This operating mode is a little more complex to uses, but has a handful of a
** dvantages :
**  - Pointer in registered variables can be changed without interfacing with M
** allocspy; pointers that are freed then reallocated in-place won't need to be
**  manually unregistered and re-registered.
**  - Pointers that are freed then set to NULL without interfacing with Mallocs
** py can be automatically detected and unregistered in bulk using `SpyClean`.
** You must however make sure to unregister such variables before they are them
** selves deallocated (heap) or fall out of scope (stack).
**  - Mallocspy will in most case, never end up obfuscating leaks from tools li
** ke Valgrind. (Unless the registered variable also happens to be an allocated
**  pointer itself.)
*/

# ifndef SPYVERBOSE
#  define SPYVERBOSE 1
# endif
# ifndef SPYBRAVE
#  define SPYBRAVE 0
# endif

/*
** Allocates memory, and registers the variable that will hold it at the curren
** t level.
** @param void** variable	A pointer to the variable that will hold the pointe
** r.
** @param size_t size The amount of bytes to allocate.
** @return void* A pointer to the allocated memory, or NULL if an error occured
** .
*/

void			*spymalloc(void **variable, size_t size);

/*
** Allocates memory, and registers the variable that will hold it at the given
**  level.
** @param unsigned int level	The level at which the variable will be registe
** red.
** 	It is possible, but not recommended, to register variables above the curren
** t level
** @param void** variable	A pointer to the variable that will hold the pointe
** r.
** @param size_t size The amount of bytes to allocate.
** @return void* A pointer to the allocated memory, or NULL if an error occured
** .
*/

void			*spymalloclvl(unsigned int level, void **variable, size_t size)
;

/*
** Frees a variable that was registered using either `spymalloc` or `spyreg`.
** This safely ignores NULL variables and variables to NULL pointers.
** This ignores unregistered variables, unless `SPYBRAVE` is enabled.
** `SPYVERBOSE` prints a warning if the variable is not registered or NULL.
** @param void** variable	A pointer to the variable that must be freed.
** @return bool
** 	true  OK
** 	false The variable was not registered beforehand.
*/
short			spyfree(void **variable);

/*
** Registers a variable at the current level.
** You can use this on variables that hold pointers which were not created usin
** g `spymalloc`.
** It is safe to use with NULL variables and variables that hold NULL.
** `SPYVERBOSE` prints a warning if the pointer is NULL or already registered.
** @param void* pointer The variable to register
** @return void* The variable that was registered, or NULL if an error occured.
*/

void			*spyreg(void *pointer);

/*
** Registers a variable at the given level.
** You can use this on variables that hold pointers which were not created usin
** g `spymalloc`.
** It is safe to use with NULL variables and variables that hold NULL.
** `SPYVERBOSE` prints a warning if the pointer is NULL or already registered.
** @param unsigned int level	The level at which the variable will be registe
** red.
** @param void* pointer The variable to register
** @return void* The variable that was registered, or NULL if an error occured.
*/

void			*spyreglvl(unsigned int level, void *pointer);

/*
** Unregisters a variable internally.
** Use this on variable were registered, but freed without 'spyfree'.
** It is safe to use on variables that were not already registered.
** `SPYVERBOSE` prints a warning if the pointer is NULL or not registered.
** @param void* pointer The pointer to unregister
** @return bool
** 	true  The pointer was unregistered.
** 	false The pointer was not registered to begin with.
*/

short			spyunreg(void *pointer);

/*
** Prints all currently registered variable adresses.
** @return size_t The amount of registered pointers.
*/

size_t			spylog(void);

/*
** @return unsigned int	The current spy level, used as default by methods overl
** oads that don't use a `level` argument.
*/

unsigned int	spylevel(void);

/*
** Increases the spy level by one.
** @return unsigned int	The new current spy level.
*/

unsigned int	spymount(void);

/*
** Frees and unregister all known variables at the current level and above, the
** n decrease the spy level by one.
** Flushed variables are also set to NULL.
** At level 0, the spy level doesn't go down, and Mallocspy's internal pointers
**  are freed as well. These are automatically initialized, so it doesn't preve
** nt Mallocspy from working.
** @return size_t The amount of pointers freed.
*/

size_t			spyflush(void);

/*
** Frees and unregister all known variables at the given level and above, then
** decrease the spy level to below that.
** Flushed variables are also set to NULL.
** At level 0, the spy level doesn't go down, and Mallocspy's internal pointers
**  are freed as well. These are automatically initialized, so it doesn't preve
** nt Mallocspy from working.
** @param unsigned int level	The level to be flushed.
** 	The current level won't go up if the provided level is greater, but it will
** still seek for variables to flush.
** @return size_t The amount of pointers freed.
*/

size_t			spyflushlvl(unsigned int level);

/*
** Unregisters all variables that hold NULL pointers.
** This affects all levels.
** @return size_t   The amount of unregistered variables.
*/

size_t			spyclean(void);

#endif
