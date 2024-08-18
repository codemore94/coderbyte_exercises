#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    void *initial_brk = sbrk(0); // Get current end of heap
    printf("Initial break: %p\n", initial_brk);

    // Increase heap size by 1 MB
    size_t increment = 1024 * 1024; // 1 MB
    if (brk((char *)initial_brk + increment) == -1) {
        perror("brk");
        exit(EXIT_FAILURE);
    }

    void *new_brk = sbrk(0); // Get new end of heap
    printf("New break: %p\n", new_brk);

    // Decrease heap size by 1 MB
    if (brk(initial_brk) == -1) {
        perror("brk");
        exit(EXIT_FAILURE);
    }

    printf("Heap size restored.\n");
    return 0;
}
