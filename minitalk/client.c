/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:17 by marai             #+#    #+#             */
/*   Updated: 2022/12/31 13:07:59 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

pid_t	check_error(int argc, char *argv[]);
int		send_char_bit(pid_t pid, char *argv[], int index);

int	main(int argc, char *argv[])
{
	pid_t	pid;
	ssize_t	i;

	pid = check_error(argc, argv);
	if (pid < 0)
		return (-1);
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (send_char_bit(pid, argv, i) == -1)
			return (-1);
		i++;
	}
}

pid_t	check_error(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Incorrect the number of arguments\n");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		ft_printf("Invalid process id\n");
		return (-1);
	}
	return (pid);
}

int	send_char_bit(pid_t pid, char *argv[], int index)
{
	int	j;
	int	chr;
	int	result;

	j = 7;
	chr = argv[2][index];
	while (0 <= j)
	{
		if ((chr >> j) & 1)
			result = kill(pid, 17);
		else
			result = kill(pid, 16);
		if (result == -1)
		{
			ft_printf("Can't send the messege\nPlease check the pid.\n");
			return (-1);
		}
		usleep(100);
		j--;
	}
	return (1);
}
