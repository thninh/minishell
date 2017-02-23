/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprouveu <cprouveu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:34:58 by cprouveu          #+#    #+#             */
/*   Updated: 2017/02/23 17:35:02 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#ifndef READ_SIZE
#ifndef BUF_SIZE
# define GET_NEXT_LINE_H
# define BUF_SIZE 4096
# define READ_SIZE 1

char	*get_next_line(const int fd);

#endif /* !READ_SIZE */
#endif /* !BUF_SIZE */
#endif /* !GET_NEXT_LINE */
