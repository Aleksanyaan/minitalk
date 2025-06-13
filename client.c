/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:42:46 by zaleksan          #+#    #+#             */
/*   Updated: 2025/06/13 20:42:47 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int		g_response;

void	get_response(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		g_response = 1;
	if (sig == SIGUSR2)
		ft_printf("Message received\n");
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_response = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		while (g_response == 0)
			pause();
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	saction;
	char				*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		saction.sa_sigaction = get_response;
		saction.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &saction, 0);
		sigaction(SIGUSR2, &saction, 0);
		while (*message)
			send_char(pid, *message++);
		send_char(pid, '\0');
	}
	return (0);
}
