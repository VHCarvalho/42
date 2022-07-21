/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:20:10 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/21 14:23:27 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>


int		print_arg(const char *str, int i, va_list list);
char	*ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str)
void	ft_putstr(char *s)
int		ft_putchar(char c)

#endif
