//To merge two files into one file, the file is appended to the third
//To run : ./a.out abc.txt xyz.txt

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int sourcefileid1=0,sourcefileid2=0,destfileid1=0, destfileid2=0;
    char buff;
    if(argc!=4)
    {
        printf("[!] Enter the correct no of arguments.\n");
        printf("[!] Format is : ./a.out [file1.txt] [file2.txt] [file3.txt]\n");
    }
    else
    {
        sourcefileid1=open(argv[1],O_RDONLY);
        sourcefileid2=open(argv[2],O_RDONLY);
        if(sourcefileid1==-1 || sourcefileid2==-1)
        {
            perror("[-] Source file error");
            exit(0);
        }

        else
        {
            destfileid1=creat(argv[3],0777);
            
            if(destfileid1==-1)
            {
                perror("[-] Destination file error");
                exit(0);
            }

            else
            {
                int n;
                while((n=read(sourcefileid1,&buff,1)) != 0)
                {
                    write( destfileid1, &buff, 1 );
                }
            }

            
            destfileid2=open(argv[3],O_WRONLY | O_APPEND);

            if(destfileid2==-1)
            {
                perror("[-] Destination file error");
                exit(0);
            }

            else
            {
                int n;
                while((n=read(sourcefileid2,&buff,1)) != 0)
                {
                    write( destfileid2, &buff, 1 );
                }

                write(STDOUT_FILENO, "FILES APPENDED\n" , 15);   
                close(sourcefileid2);
                close(sourcefileid1);
                close(destfileid1);
                close(destfileid2);
            }

            
        }
    }
    return 0;
}
