#include "../includes/pipex.h"

void ft_error(int num)
{
	if(num == 1)
		write(1, "Argument less than 4\n", ft_strlen("Argument less than 4\n"));
	else if (num == 2)
		write(1, "Command not found\n", ft_strlen("command not found\n"));
	else if (num == 3)
		write(1, "No such file or directory\n", ft_strlen("No such file or directory\n"));
	else if(num == 4)
		write(1, "Broken pipe\n", ft_strlen("Broken pipe\n"));
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