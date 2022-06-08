#include "../includes/pipex.h"

char  **get_command(char *cmd)
{
	char **command;
	int i;
	int len;

	command = ft_split(cmd, ' ');
	return command;
}

char **command(t_pipedata *pipedata, char *cmd)
{
	int		i;
	int		checker;
	char	*path;
	char	**command;

	i = 0;
	command = get_command(cmd);
	while(pipedata->paths[i])
	{
		path = ft_strjoin(pipedata->paths[i], command[0]);
		checker = access(path, X_OK);
		if(!checker)
		{
			pipedata->command_path = path;
			break;
		}
		free (path);
		i++;
	}
	if(checker == -1)
		ft_error(cmd);
	return command;
}