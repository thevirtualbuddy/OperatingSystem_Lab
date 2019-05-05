//To copy the content of one file to another file using system calls
//To run : ./a.out abc.txt xyz.txt
//abc.txt is the source file and xyz.txt is the destination file.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int sourcefileid=0, destfileid=0;
    char buff;
    if(argc!=3)
    {
        printf("[!] Enter the correct no of arguments.\n");
        printf("[!] Format is : ./a.out abc.txt xyz.txt\n");
    }
    else
    {
        sourcefileid=open(argv[1],O_RDONLY);
        if(sourcefileid==-1)
        {
            perror("[-] Source file error");
            exit(0);
        }

        else
        {
            destfileid=open(argv[2],O_WRONLY | O_CREAT , 0641);
            if(destfileid==-1)
            {
                perror("[-] DESTINATION FILE ERROR");
                exit(0);
            }
            else
            {
                int n;
                while((n=read(sourcefileid,&buff,1)) != 0)
                {
                    write( destfileid, &buff, 1 );
                }
                write(STDOUT_FILENO, "FILES COPIED\n" , 13);   
                close(sourcefileid);
                close(destfileid);
            }   
        }
    }
    return 0;
}