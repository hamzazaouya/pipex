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

int	ft_get_path_index(char **env)
{
	return -1;
}

char **get_paths(char **env)
{
	int i;
	int j;
	char *paths;

	i = 0;
	while(env[i])
	{
		if(ft_is_path(env[i]))
			break ;
		i++;
	}
	return (ft_split(env[i] + 5, ':'));
}