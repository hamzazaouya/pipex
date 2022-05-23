#include "../includes/pipex.h"

void ft_init(int argc, char **argv, char **env, t_pipedata *pipedata)
{
	pipedata->command_len = argc - 3;
	pipedata->files = ft_check_files(argc, argv);
	pipedata->commands = get_command(argv, pipedata->command_len);
	pipedata->paths = get_paths(env);
	ft_check_commands(pipedata);
}

void ft_pipex(t_pipedata *pipedata, char **env)
{
	int fd[2];
	int fp[2];

	fd[0] = open(pipedata->paths[0], O_RDWR);
	fd[1] = open(pipedata->paths[1], O_RDWR);
	if(pipe(fp) < 0)
		ft_error();
	if(fork() == 0)
	{
		dup2(fd[0], 0);
		dup2(fp[1], 1);
		execve(pipedata->commands_paths[0],pipedata->commands[0].command, env);
	}
	else
	{
		dup2(fp[0], 0);
		dup2(fd[1], 1);
		execve(pipedata->commands_paths[1],pipedata->commands[1].command, env);
	}
}

int main(int argc, char **argv, char **env)
{
	t_pipedata pipedata;

	ft_init(argc, argv, env, &pipedata);
	ft_pipex(&pipedata, env);
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
	// i = 0;
	// while(i < 2)
	// {
	// 	printf("%s\n", pipedata.commands_paths[i]);
	// 	i++;
	// }
}