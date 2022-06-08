#include "../includes/pipex.h"

void ft_error(char *str)
{
	perror(str);
	exit(0);
}

char **get_files(int argc, char **argv)
{
	char	**files_name;
	int i;

	i = 0;
	files_name = (char **)ft_calloc(sizeof(char *), 2);
	files_name[0] = argv[1];
	files_name[1] = argv[argc - 1];
	return (files_name);
}