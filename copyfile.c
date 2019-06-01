//To copy a file 
//To run : ./a.out abc.txt xyz.txt
//abc.txt is the source file and xyz.txt is the copy of the file

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
        printf("[!] Format is : ./a.out [source file] [path where it should be copied with file name]\n");
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
            destfileid=creat(argv[2],0777);
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
