/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:17 by marai             #+#    #+#             */
/*   Updated: 2022/12/31 12:37:29 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		chr;
	ssize_t	i;
	ssize_t	j;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (-1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		j = 7;
		chr = argv[2][i];
		while (0 <= j)
		{
			if ((chr >> j) & 1)
				kill(pid, 17);
			else
				kill(pid, 16);
			usleep(100);
			j--;
		}
		i++;
	}
}
