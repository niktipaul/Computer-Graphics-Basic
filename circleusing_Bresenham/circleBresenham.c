#include <stdio.h>
#include <math.h>

void circleBresenham(int, int, int);
void doubleQuadrants(int, int, int, int);
char ch, pixel[200][200];

int main()
{
    FILE *fp1, *fp2;
    int xa, ya, r;
    int i, j;

    fp1 = fopen("head.txt", "rb");
    fp2 = fopen("circleBresenham.pgm", "wb+");

    while (fread(&ch, sizeof(ch), 1, fp1))
        fwrite(&ch, sizeof(ch), 1, fp2);

    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            pixel[i][j] = 255;

    printf("Input Co-ordinate of the centre of the circle: ");
    scanf("%d%d", &xa, &ya);
    printf("Input radius of the circle: ");
    scanf("%d", &r);

    circleBresenham(xa, ya, r);
    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            fwrite(&pixel[i][j], sizeof(ch), 1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

void circleBresenham(int xa, int ya, int r)
{

    int x = 0, y = r, d = 3 - (2 * r);
    doubleQuadrants(xa, ya, x, y);

    while (x <= y)
    {
        if (d <= 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + (4 * x) - (4 * y) + 10;
            y = y - 1;
        }
        x = x + 1;
        doubleQuadrants(xa, ya, x, y);
    }
}

void doubleQuadrants(int xc, int yc, int x, int y)
{
    pixel[x+xc][y+yc] = 0;
    pixel[x+xc][-y+yc] = 0;
    pixel[-x+xc][y+yc] = 0;
    pixel[-x+xc][-y+yc] = 0;

    pixel[-y+xc][-x+yc] = 0;
    pixel[-y+xc][x+yc] = 0;
    pixel[y+xc][-x+yc] = 0;
    pixel[y+xc][x+yc] = 0;
}