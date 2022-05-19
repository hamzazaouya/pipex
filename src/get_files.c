#include "../includes/pipex.h"

void ft_error()
{
	exit(0);
}

char **get_files(int argc, char **argv)
{
	char **files;

	files = (char **)ft_calloc(sizeof(char *), 2);
	files[0] = argv[1];
	files[1] = argv[argc - 1];
	return (files);
}

char **ft_check_files(int argc, char **argv)
{
	int fd;
	int i;
	char **files;

	files = get_files(argc, argv);
	i = 0;
	while(i < 2)
	{
		fd = open(files[0], O_RDONLY);
		if(fd == -1)
			ft_error();
		close(fd);
		i++;
	}
	return (files);
}