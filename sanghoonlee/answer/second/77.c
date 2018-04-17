#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int daemon_init(void)
{
    int i;
    if(fork() > 0)
        exit(0);
    setsid();
    chdir("/");
    umask(0);
    for(i = 0; i < 64; i++)
        close(i);
    signal(SIGCHLD, SIG_IGN);
    return 0;
}

int main(void)
{
    daemon_init();
    // 데몬에서 동작시키고자 하는 작업을 이곳에 작성한다.
    for(;;)
        ;
    return 0;
}
