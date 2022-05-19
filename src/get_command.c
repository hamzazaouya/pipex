#include "../includes/pipex.h"

t_command *get_command(char **argv, int size)
{
	t_command *commands;
	int i;

	i = 0;
	commands = (t_command *)ft_calloc(sizeof(t_command), size + 1);
	while(i < size)
	{
		commands[i].command = ft_split(argv[i + 2], ' ');
		i++;
	}
	commands[i].command = NULL;
	return commands;
}