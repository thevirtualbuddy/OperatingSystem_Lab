//To display the the content of a file in a reverse order
//To run : ./a.out abc.txt 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int sourcefileid=0;
    char buff;
    if(argc!=2)
    {
        printf("[!] Enter the correct no of arguments.\n");
        printf("[!] Format is : ./a.out [source.txt]\n");
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

            int n,i=0;

            int filesize = lseek(sourcefileid, (off_t) 0, SEEK_END); //filesize is lastby +offset
            
            for (i = filesize - 1; i >= 0; i--) 
            { //read byte by byte from end
                lseek(sourcefileid, (off_t) i, SEEK_SET);

                n = read(sourcefileid, &buff, 1);

                if (n != 1) 
                {
                    fprintf(stderr, "can't read 1 byte");
                    exit(-1);
                }

                printf("%c",buff);
            }
            
            close(sourcefileid);
            printf("\n");
               
        }
    }
    return 0;
}
