#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#define PROCESS_NUM 200

int main(void)
{
    int id;
    int i;
    int j;
    int x;
    int pipes[PROCESS_NUM + 1][2];


    i = 0;
    for(i = 0; i < PROCESS_NUM + 1; i++)
    {
        if(pipe(pipes[i]) == -1)
        {
            printf("Error in pipe\n");
        }
    }
    for(i = 0; i < PROCESS_NUM; i++)
    {
        id = fork();
        if(id < 0)
        {
            printf("Error in fork\n");
            return (0);
        }
        if(id == 0)
        {
            j = 0;
            for(j = 0; j < PROCESS_NUM + 1; j++)
            {
                if(j != i)
                    close(pipes[j][0]);
                if(j != i + 1)
                    close(pipes[j][1]);
                j++;
            }
            if(read(pipes[i][0], &x, sizeof(int)) == -1)
            {
                printf("Error in Reading\n");
                return (0);
            }
            printf("(%d) Got %d\n", i, x);
            x++;
            if(write(pipes[i + 1][1], &x, sizeof(int)) == -1)
            {
                printf("Error in Writing\n");
                return 0;
            }
            return 0;
        }
    }
    for(i = 0; i < PROCESS_NUM + 1; i++)
    {
        if(i != 0)
            close(pipes[i][1]);
        if(i != PROCESS_NUM)
            close(pipes[i][0]);
    }
    int y = 5;
    if(write(pipes[0][1], &y, sizeof(int)) == -1)
    {
        printf("Writing Error\n");
        return 0;
    }
    if(read(pipes[PROCESS_NUM][0], &y, sizeof(int)) == -1)
    {
        printf("Reading Error\n");
        return 0;
    }
    for(i = 0; i < PROCESS_NUM; i++)
    {
        wait(NULL);
    }
    printf("The result is %d\n", y);
    printf("Hello From Parent\n");
}