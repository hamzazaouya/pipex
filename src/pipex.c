#include "../includes/pipex.h"

void ft_init(int argc, char **argv, char **env, t_pipedata *pipedata)
{
	pipedata->files_name = get_files(argc, argv);
	pipedata->paths = get_paths(env);
	pipedata->argv = argv;
	pipedata->argc = argc;
	pipedata->env = env;
	pipedata->cmd_num = argc - 3;
	pipedata->pipe_num = argc - 4;
	pipedata->pipes = get_pipes(argc - 4);
}

void ft_pipex(t_pipedata *pipedata)
{
	int i;
	int	id;
	int j;
	int p;
	int k;
	char c;
	int fd;

	i = 2;
	while(i < pipedata->argc - 1)
	{
		p = i - 2;
		id = fork();
		if(id == 0)
		{
			if(i == 2)
			{
				j = 0;
				while(j < pipedata->pipe_num)
				{
					close(pipedata->pipes[j][0]);
					if(j != p)
						close(pipedata->pipes[j][1]);
					j++;
				}
				fd = open(pipedata->files_name[0],  O_RDWR);
				if(fd == -1)
				{
					printf("File 1 Error\n");
					exit(0);
				}
				pipedata->command = command(pipedata, pipedata->argv[i]);
				if(pipedata->command)
				{
					dup2(fd, 0);
					dup2(pipedata->pipes[p][1], 1);
					execve(pipedata->command_path, pipedata->command, pipedata->env);
				}
			}
			else if(i == pipedata->argc - 2)
			{
				j = 0;
				while(j < pipedata->pipe_num)
				{
					close(pipedata->pipes[j][1]);
					if(j != p - 1)
						close(pipedata->pipes[j][0]);
					j++;
				}
				fd = open(pipedata->files_name[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
				if(fd == -1)
				{
					printf("File 2 Error\n");
					exit(0);
				}
				dup2(fd, 1);
				dup2(pipedata->pipes[p - 1][0], 0);
				pipedata->command = command(pipedata, pipedata->argv[i]);
				execve(pipedata->command_path, pipedata->command, pipedata->env);
			}
			else {
				j = 0;
				while(j < pipedata->pipe_num)
				{
					if(j != p)
						close(pipedata->pipes[j][1]);
					if(j != p - 1)
						close(pipedata->pipes[j][0]);
					j++;
				}
				dup2(pipedata->pipes[p][1], 1);
				dup2(pipedata->pipes[p - 1][0], 0);
				pipedata->command = command(pipedata, pipedata->argv[i]);
				execve(pipedata->command_path, pipedata->command, pipedata->env);
			}
			return ;
		}
		i++;
	}
	i = 0;
	while(i < pipedata->pipe_num)
	{
		close(pipedata->pipes[i][0]);
		close(pipedata->pipes[i][1]);
		i++;
	}
	i = 0;
	while(i < pipedata->cmd_num)
	{
		wait(NULL);
		i++;
	}
}

int main(int argc, char **argv, char **env)
{
	t_pipedata pipedata;

	if(argc >= 5)
	{
		ft_init(argc, argv, env, &pipedata);
		ft_pipex(&pipedata);
	}
	else
		ft_error(1);
}