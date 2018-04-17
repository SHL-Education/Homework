#include "65_shm.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
        int fd;
        int ret;
        int mid;
        char buf[1024];
        SHM_t *p;

        mid = OpenSHM(0x888);

        p = GetPtrSHM(mid);

        getchar();
        fd = open(argv[1], O_RDONLY);
        ret = read(fd, buf, sizeof(buf));
        buf[ret - 1] = 0;
        strcpy(p -> name, argv[1]);
        strcpy(p -> buf, buf);

        FreePtrSHM(p);

        return 0;
} 
