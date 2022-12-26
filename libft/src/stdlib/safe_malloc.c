#include <stdio.h>
#include <stdlib.h>

void *safe_malloc(size_t size)
{
    void    *ptr;

    ptr = malloc(size);
    if (!ptr)
    {
        perror("Error\ncub3D: ");
        exit(1);
    }
    return (ptr);
}
