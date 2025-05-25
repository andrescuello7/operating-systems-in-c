#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RGB
{
    int r;
    int g;
    int b;
};

void rgb_set(struct RGB *rgb, int r, int g, int b)
{
    if (r + g + b <= 255 * 3 && (r >= 0 && g >= 0 && b >= 0))
    {
        rgb->r = r;
        rgb->g = g;
        rgb->b = b;
    }
}

void rgb_invert(struct RGB *rgb)
{
    rgb_set(rgb, 255 - rgb->r, 255 - rgb->g, 255 - rgb->b);
}

char *rgb_str(struct RGB *rgb)
{
    char *str = malloc(sizeof(20) * 64);
    sprintf(
        str, "RGB: (%i, %i, %i)\nHEX: 0x%02x%02x%02x",
        rgb->r, rgb->g, rgb->b,
        rgb->r, rgb->g, rgb->b);

    return str;
}

struct RGB *get_inverted_colors(char *file, int limit)
{
    struct RGB *inverted = malloc(sizeof(struct RGB));

    int line_size = 16;
    char *line = malloc(sizeof(char) * line_size);
   
    FILE *f = fopen(file, "r");

    int i = 0;
    while (fgets(line, line_size, f))
    {
        if (i >= limit)
        {
            printf("Error, el fichero llego al limite de lineas");
        }

        int values[3];
        char *split = strdup(line);

        for (size_t i = 0; i < 3; i++)
        {
            values[i] = atoi(strsep(&split, " "));
        }
        free(split);
        rgb_set(&inverted[i], values[0], values[1], values[2]);
        rgb_invert(&inverted[i++]);
    }
    free(line);
    fclose(f);

    return inverted;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error: No enviaste el archivo");
        exit(-1);
    }
    int limit = 4;
    struct RGB *inverted = get_inverted_colors(argv[1], limit);
    for (int i = 0; i < limit; i++)
    {
        char *s = rgb_str(&inverted[i]);
        printf("%s\n\n", s);
        free(s);
    }
    
    free(inverted);
}