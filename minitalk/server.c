/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:43:08 by marai             #+#    #+#             */
/*   Updated: 2022/12/27 00:00:09 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

//
void bitzero()
{
    
}

void bitone()
{
    
}


int main()
{
    pid_t pid;

    pid = getpid();
    signal(16, bitzero);
    signal(17, bitone);
    printf("%d\n",pid);
    while(1)
        ;
}