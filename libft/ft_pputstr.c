/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 01:46:21 by alao              #+#    #+#             */
/*   Updated: 2016/10/09 20:33:05 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** The ft_pputstr() function write the char const *s and char const *p on
** stdout.
**
** RETURN VALUES:
**  SUCCESS: Nothing
**  FAILURE: Nothing
*/

void	ft_pputstr(char const *s, char const *p)
{
	write(1, s, ft_strlen(s));
	write(1, p, ft_strlen(p));
}
