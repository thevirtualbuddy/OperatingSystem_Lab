#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd;
    char buff[20];

    write(1,"Input : ", 8);
    fd = read (0, buff, sizeof(buff));
    
    write(1,"Output : ", 9);
    write(1,buff,fd);

    printf("\n");
    return 0;
}