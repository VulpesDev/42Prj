#include "philo.h"

int	print_error(void)
{
	write(STD_ERROR, "Error\n", 6);
	write(1, STR_INSTRUCTIONS, STR_INSTRUCTIONS_I);
	return (1);
}

int	handle_errors(int argc)
{
	if (argc != 5 && argc != 6)
		return print_error();
	return (0);
}