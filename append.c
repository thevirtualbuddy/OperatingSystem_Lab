//To merge the content of two files into one file, the file is appended to the second file
//To run : ./a.out abc.txt xyz.txt

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int sourcefileid=0,destfileid=0;
    char buff;
    if(argc!=3)
    {
        printf("[!] Enter the correct no of arguments.\n");
        printf("[!] Format is : ./a.out [file1.txt] [file2.txt]\n");
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
            destfileid=open(argv[2],O_WRONLY | O_APPEND);
            if(destfileid==-1)
            {
                perror("[-] Destination file error");
                exit(0);
            }

            else
            {
                int n;
                while((n=read(sourcefileid,&buff,1)) != 0)
                {
                    write( destfileid, &buff, 1 );
                }
                write(STDOUT_FILENO, "FILES APPENDED\n" , 15);   
                close(sourcefileid);
                close(destfileid);
            }               
        }
    }
    return 0;
}