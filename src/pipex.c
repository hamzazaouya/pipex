#include "../includes/pipex.h"

void ft_init(int argc, char **argv, char **env, t_pipedata *pipedata)
{
	pipedata->files_ds = get_files(argc, argv);
	dup2(pipedata->files_ds[0], 1);
	printf("Hello mother fucker ksdfjosodifsdf\n");
	// pipedata->paths = get_paths(env);
	// pipedata->argv = argv;
	// pipedata->argc = argc;
	// pipedata->env = env;
	// pipedata->cmd_num = argc - 3;
	// pipedata->pipe_num = argc - 4;
	// pipedata->pipes = get_pipes(argc - 4);
}

// void ft_pipex(t_pipedata *pipedata)
// {
// 	int i;
// 	int	id;
// 	int j;
// 	int p;
// 	int k;
// 	char c;

// 	i = 2;
// 	while(i < pipedata->argc - 1)
// 	{
// 		p = i - 2;
// 		id = fork();
// 		if(id == 0)
// 		{
// 			pipedata->command = command(pipedata, pipedata->argv[i]);
// 			if(pipedata->command != NULL)
// 			{
// 				if(i == 2)
// 				{
// 					//read from infile and right in firest pipe;
// 					j = 0;
// 					close(pipedata->files_ds[1]);
// 					while(j < pipedata->pipe_num)
// 					{
// 						close(pipedata->pipes[j][0]);
// 						if(j != p)
// 							close(pipedata->pipes[j][1]);
// 						j++;
// 						p++;
// 					}
// 					dup2(pipedata->files_ds[0], 0);
// 					dup2(pipedata->pipes[p][1], 1);
// 					execve(pipedata->command_path, pipedata->command, pipedata->env);
// 				}
// 				else if(i == pipedata->argc - 2)
// 				{
// 					j = 0;
// 					close(pipedata->files_ds[0]);
// 					while(j < pipedata->pipe_num)
// 					{
// 						close(pipedata->pipes[j][1]);
// 						if(j != p - 1)
// 							close(pipedata->pipes[j][0]);
// 						j++;
// 						p++;
// 					}
// 					dup2(pipedata->files_ds[1], 1);
// 					printf("Hello\n");
// 					dup2(pipedata->pipes[p - 1][0], 0);
// 					k = 0;
// 					while(read(0, &c, 1))
// 					{
// 						printf("%c\n", c);
// 					}
// 					execve(pipedata->command_path, pipedata->command, pipedata->env);
// 				}	
// 			}
// 			return ;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while(i < pipedata->cmd_num)
// 	{
// 		wait(NULL);
// 		i++;
// 	}
// }

int main(int argc, char **argv, char **env)
{
	t_pipedata pipedata;

	if(argc >= 5)
	{
		ft_init(argc, argv, env, &pipedata);
		// ft_pipex(&pipedata);
	}
	else
		ft_error(1);
}