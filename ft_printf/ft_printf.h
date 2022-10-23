/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 03:18:17 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 06:32:57 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *argv, ...);
ssize_t	ft_ajust(long long nbr, char *base, char c);
ssize_t	ft_ajust_str(va_list *ap, char c);
int		prefix(const char *str, va_list *ap);
ssize_t	ft_putnbr_base(long long nbr, char *base,
			ssize_t sign, ssize_t baselen);
ssize_t	ft_putnbr_ptr(uintptr_t nbr, char *base, ssize_t sign, ssize_t baselen);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
#endif
