#include "../includes/pipex.h"

int ft_is_path(char *env)
{
	int i;

	char path[] = "PATH";
	i = 0;
	while(i < 4)
	{
		if(env[i] != path[i])
			return (0);
		i++;
	}
	return (1);
}

char **get_paths(char **env)
{
	int i;
	int j;
	char **paths;

	i = 0;
	while(env[i])
	{
		if(ft_is_path(env[i]))
			break ;
		i++;
	}
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while(paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

int	**get_pipes(int num)
{
	int i;
	int **pipes;

	i = 0;
	pipes = (int **)malloc(sizeof(int *) * num);
	while (i < num)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if(pipe(pipes[i]) < 0)
			ft_error("");
		i++;
	}
	return (pipes);
}