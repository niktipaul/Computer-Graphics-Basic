#include <stdio.h>
#include <math.h>

void lineBresenham(int, int, int, int);
char ch, pixel[200][200];

int main()
{
    FILE *fp1, *fp2;
    int xa, ya, xb, yb;
    int i, j;

    fp1 = fopen("head.txt", "rb");
    fp2 = fopen("lineBresenham.pgm", "wb+");

    while (fread(&ch, sizeof(ch), 1, fp1))
        fwrite(&ch, sizeof(ch), 1, fp2);

    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            pixel[i][j] = 255;

    printf("Input Co-ordinate of first point: ");
    scanf("%d%d", &xa, &ya);
    printf("Input co-ordinate of end point: ");
    scanf("%d%d", &xb, &yb);

    lineBresenham(xa, ya, xb, yb);
    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            fwrite(&pixel[i][j], sizeof(ch), 1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

void lineBresenham(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;
    while (x < x1)
    {
        if (p >= 0)
        {
            pixel[y][x] = 0;
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            pixel[y][x] = 0;
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}