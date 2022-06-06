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

int *get_files(int argc, char **argv)
{
	char **files;
	int	*file_ds;
	int i;

	i = 0;
	files = (char **)ft_calloc(sizeof(char *), 2);
	file_ds = (int *)ft_calloc(sizeof(int), 2);
	files[0] = argv[1];
	files[1] = argv[argc - 1];
	while(i < 2)
	{
		file_ds[i] = check_file(files[i], i);
		i++;
	}
	return (file_ds);
}

int check_file(char *file_name, int num)
{
	int i;
	int fd;
	
	if(num == 0)
		fd = open(file_name, O_RDONLY);
	else
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(fd == -1 && num == 0)
		ft_error(3);
	return (fd);
}