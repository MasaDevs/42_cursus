/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:08 by marai             #+#    #+#             */
/*   Updated: 2022/12/31 00:24:58 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

//global variable
int	g_bitsum;

//signalhandler
void	signal_handler(int signum)
{
	static int	degit;

	g_bitsum <<= 1;
	if (signum == 17)
		g_bitsum += 1;
	if (7 <= degit)
	{
		write(1, &g_bitsum, 1);
		g_bitsum = 0;
		degit = 0;
	}
	else
		degit++;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	printf("%d\n", pid);
	sa.sa_handler = signal_handler;
	sigaction(16, &sa, NULL);
	sigaction(17, &sa, NULL);
	while (1)
		;
}
