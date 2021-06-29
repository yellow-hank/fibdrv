#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <time.h>

#define FIB_DEV "/dev/fibonacci"



int main()
{

    char write_buf[] = "testing writing";
    int offset = 184; /* TODO: try test something bigger than the limit */

    int fd = open(FIB_DEV, O_RDWR);
    if (fd < 0) {
        perror("Failed to open character device");
        exit(1);
    }

    for (int i = 0; i <= offset; i++) {
        long long kernel_time, user_time;
        struct timespec t1, t2;
        lseek(fd, i, SEEK_SET);
        clock_gettime(CLOCK_MONOTONIC, &t1);
        kernel_time = write(fd, write_buf, strlen(write_buf));
        clock_gettime(CLOCK_MONOTONIC, &t2);
        user_time = (ssize_t) t2.tv_nsec - t1.tv_nsec;
        printf("%d %lld %ld %lld\n", i, kernel_time, t2.tv_nsec - t1.tv_nsec,
               user_time - kernel_time);
    }


    close(fd);
    return 0;
}
