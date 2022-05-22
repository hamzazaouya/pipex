#include "../includes/pipex.h"

void ft_init(int argc, char **argv, char **env, t_pipedata *pipedata)
{
	pipedata->command_len = argc - 3;
	pipedata->files = ft_check_files(argc, argv);
	pipedata->commands = get_command(argv, pipedata->command_len);
	pipedata->paths = get_paths(env);
	ft_check_commands(pipedata);
}

int main(int argc, char **argv, char **env)
{
	t_pipedata pipedata;

	ft_init(argc, argv, env, &pipedata);
	// int i = 0;
	// int j;
	// while(pipedata.commands[i].command)
	// {
	// 	j = 0;
	// 	while(pipedata.commands[i].command[j])
	// 	{
	// 		printf("%s\n", pipedata.commands[i].command[j]);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// i = 0;
	// while(i < 2)
	// {
	// 	printf("%s\n", pipedata.files[i]);
	// 	i++;
	// }
}