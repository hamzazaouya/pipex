// CPP program to illustrate dup2() 
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
    char arr[6];
    int file_desc1 = open("tricky.txt",O_WRONLY | O_APPEND);
    int file_desc2 = open("read.txt",O_WRONLY | O_APPEND);
    dup2(file_desc2, 0);
    read(0, );
    // here the newfd is the file descriptor of stdout (i.e. 1)
    dup2(file_desc1, 1) ; 
          
    // All the printf statements will be written in the file
    // "tricky.txt"
    printf("I will be printed in the file tricky.txt\n");
      
return 0;
}