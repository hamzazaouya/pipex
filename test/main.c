// C program to demonstrate waitpid()
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> 
#include<sys/wait.h>
#include<unistd.h>
#define PROCESS_NUM 300

int **ft_init_pipe(int arr_size)
{
    int i;
    int **fd;

    i = 0;
    fd = (int **)malloc(sizeof(int *) * arr_size);
    while(i < arr_size)
    {
        fd[i] = (int *)malloc(sizeof(int) * 2);
        i++;
    }
    i = 0;
    while(i < arr_size)
    {
        if(pipe(fd[i]) == -1)
            printf("Pipe Error\n");
        i++;
    }
    return fd;
}

void    ft_child(int arr_size, int p, int **fd, int arrp)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    while(i < arr_size)
    {
        if(i != p - 1)
            close(fd[i][0]);
        if(i != p)
            close(fd[i][1]);
        i++;
    }
    if(p)
        read(fd[p - 1][0], &sum, sizeof(int));
    sum += arrp;
    write(fd[p][1], &sum, sizeof(int));
    close(fd[p - 1][0]);
    close(fd[p][1]);
    printf("%d\n", sum);
}

void ft_parent(int arr_size, int **fd)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    while(i < arr_size)
    {
        close(fd[i][1]);
        if(i != arr_size - 1)
            close(fd[i][0]);
        i++;
    }
    read(fd[arr_size - 1][0], &sum, sizeof(int));
    close(fd[arr_size - 1][0]);
    printf("Hello Final sum = %d\n", sum);
}

void ft_wait(int arr_size)
{
    int i;

    i = 0;
    while(i < arr_size)
    {
        wait(0);
        i++;
    }
}

int main(void)
{
    int **fd;
    int id;
    int arr[] = {10, 10, 10, 10, 10, 10};
    int arr_size = sizeof(arr) / sizeof(int);
    int p = 0;
    fd = ft_init_pipe(arr_size);
    while(p < arr_size)
    {
        id = fork();
        if(id == -1)
        {
            printf("Frok Error");
            return 1;
        }
        if(id == 0)
        {
            ft_child(arr_size, p, fd, arr[p]);
            return (1);
        }
        p++;
    }
    ft_wait(arr_size);
    ft_parent(arr_size, fd);
}
