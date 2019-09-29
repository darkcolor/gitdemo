#include "hw1.h"
int main(int argc,char *argv[])
{
	int accmode,val;
	          if(argc !=2)
                    perror("usage: a.out <descriptor#>");
            if((val= fcntl(atoi(argv[1]),F_GETFL,0))<0)
                    perror("fcntl error for fd sd",atoi(argv[1]));
        accmode = val & O_ACCMODE;
        if      (accmode ==O_RDONLY)    printf("read only");
        else if (accmode == O_WRONLY)    printf("write only");
        else if (accmode ==O_RDWR)      printf("read write");
        else perror("unknown access mode");
            if(val & O_APPEND)          printf(",append");
            if(val & O_NONBLOCK)        printf(",nonblocking");
#if !defined(_POSIX_SOURCE)&& defined(O_SYNC)
        if(val & O_SYNc)              printf(",synchronous writes");
#endif
        putchar('\n');
            exit(0);
	
}
