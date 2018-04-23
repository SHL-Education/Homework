#include "65_shm.h"

int main(void)
{
        int mid;
        SHM_t *p;

        mid = CreateSHM(0x888);

        p = GetPtrSHM(mid);

        getchar();
        printf("name : %s\nbuf : %s\n", p -> name, p -> buf);

        FreePtrSHM(p);

        return 0;
}
