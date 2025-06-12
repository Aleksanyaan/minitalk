#include "includes/minitalk.h"

int	main(void)
{
	pid_t pid = getpid();

	ft_printf("PID: %d\n", pid);
}