#include "../includes/pipex.h"

int main(void)
{
    int fd = open("infile", O_RDONLY);
    printf("%d\n", fd);
    close(fd);
}