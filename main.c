#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void print_clear_text(char *string, size_t len);

int main()
{
    int c;
    int mem_i = 0;
    size_t counter = 0;

    char *buffer = (char *) calloc(0x10, sizeof(char));
    if (!buffer)
    {
        perror("[!] Error in calloc\n");
        return EXIT_FAILURE;
    }
    memset(buffer, 0, 0x10);

    while ((c = getchar()) != EOF)
    {
        buffer[mem_i % 0x10] = c;

        if (mem_i % 0x10 == 0)
        {
            printf("%08x  ", mem_i);
            counter = 0;
        }

        printf("%02x ", c);
        mem_i++;
        counter++;

        if (mem_i % 0x8 == 0 && mem_i % 0x10 != 0)
            printf("  ");
        else if (mem_i % 0x10 == 0)
        {
            print_clear_text(buffer, 0x10);
            printf("\n");
        }
    }

    if ((c == EOF) && (counter > 0) && (counter < 0x10))
    {
        //printf("COUNTER: %zu\n", counter);
        for (size_t i = 0; i < (0x10 - counter); i++)
            printf("   ");
        
        if ((0x10 - counter) > 0x8)
            printf("  ");

        print_clear_text(buffer, counter);
    }

    printf("\n");

    return EXIT_SUCCESS;
}


void print_clear_text(char *string, size_t len)
{
    printf("  [");
    for (size_t idx = 0; idx < len; idx++)
    {
        if (!isgraph(string[idx]))
            printf(" .");
        else
            printf(" %c", string[idx]);
    }
    printf(" ]");
}