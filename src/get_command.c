#include "../includes/pipex.h"

t_command *get_command(char **argv, int size)
{
	t_command *commands;
	int i;
	int j;
	int len;
	char *slash;

	i = 0;
	commands = (t_command *)ft_calloc(sizeof(t_command), size + 1);
	while(i < size)
	{
		commands[i].command = ft_split(argv[i + 2], ' ');
		commands[i].command[0] = ft_strjoin_front(commands[i].command[0], "/");
		i++;
	}
	commands[i].command = NULL;
	return commands;
}

void ft_check_commands(t_pipedata *pipedata)
{
	int i;
	int j;
	int fd;
	int checker;
	char *path;

	
	i = 0;
	pipedata->commands_paths = (char **)malloc(sizeof(char*) * pipedata->command_len);
	while(i < pipedata->command_len)
	{
		j = 0;
		while(pipedata->paths[j])
		{
			path = ft_strjoin(pipedata->paths[j], pipedata->commands[i].command[0]);
			checker = access( path, F_OK);
			if(!checker)
			{
				pipedata->commands_paths[i] = path;
				break;
			}
			free (path);
			j++;
		}
		if(checker == -1)
			ft_error();
		i++;
	}
	return ;
}