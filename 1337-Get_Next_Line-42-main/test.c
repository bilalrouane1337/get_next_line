#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);

    char buf[64]; ssize_t n;

    // --- First read ---
    n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';
    printf("First read (%ld bytes): %s\n", n, buf);

    // --- Second read (EOF expected) ---
    n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';
    printf("Second read (%ld bytes): %s\n", n, buf);

    // --- Reset file offset to the beginning ---
    lseek(fd, 0, SEEK_SET);
    printf("Offset reset using lseek().\n");

    // --- Third read (should work again) ---
    n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';
    printf("Third read (%ld bytes): %s\n", n, buf);

    close(fd);
}