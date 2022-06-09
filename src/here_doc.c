#include "../includes/pipex.h"

void    ft_read_doc(t_pipedata *pipedata, int p)
{
    int	j;
    char *limiter;

	j = 0;
	while (j < pipedata->pipe_num)
	{
		close(pipedata->pipes[j][0]);
		if (j != p)
			close(pipedata->pipes[j][1]);
		j++;
	}
    dup2(pipedata->pipes[p][1], 1);
    while(1)
    {
        limiter = get_next_line(0);
        j = ft_strncmp(limiter, pipedata->limiter, ft_strlen(pipedata->limiter));
        if(j)
        {
            write(1, limiter, ft_strlen(limiter));
        }
        else
            break;
    }
    close(pipedata->pipes[p][1]);
}

void ft_here_doc(t_pipedata *pipedata)
{
    int	i;
	int	id;
	int	p;

	i = 2;
	while (i < pipedata->argc - 1)
	{
		p = i - 2;
		id = fork();
		if (id == 0)
		{
			if (i == 2)
            {
				ft_read_doc(pipedata, p);
            }
			else if (i == pipedata->argc - 2)
            {
				ft_last_cmd(pipedata, p);
            }
			else
            {
				ft_between_cmd(pipedata, p);
            }
			return ;
		}
		i++;
	}
	ft_close_pipes(pipedata);
	ft_wait(pipedata);
}