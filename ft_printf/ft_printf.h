/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcarvalh <vcarvalh@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:20:10 by vcarvalh          #+#    #+#             */
/*   Updated: 2022/07/25 12:55:03 by vcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		print_arg(const char *str, int i, va_list list);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
int		log_ten(long nbr);
char	*ft_itoa(int n);
int		ft_putnbr(int nbr);
char	*ft_utoa(unsigned int n);
int		ft_putuns(unsigned int nbr);
int		log_hex(unsigned long nbr);
char	*ft_hextoa(unsigned int n, char *str);
int		ft_puthex(unsigned int nbr, char *str);
char	*ft_ptrtoa(unsigned long n, char *str);
int		ft_putptr(unsigned long n, char *str);

#endif
