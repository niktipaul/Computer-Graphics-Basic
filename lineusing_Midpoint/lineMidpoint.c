#include <stdio.h>
#include <math.h>

void lineMidpoint(int, int, int, int);
char ch, pixel[200][200];

int main()
{
    FILE *fp1, *fp2;
    int xa, ya, xb, yb;
    int i, j;

    fp1 = fopen("head.txt", "rb");
    fp2 = fopen("lineMidpoint.pgm", "wb+");

    while (fread(&ch, sizeof(ch), 1, fp1))
        fwrite(&ch, sizeof(ch), 1, fp2);

    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            pixel[i][j] = 255;

    printf("Input Co-ordinate of first point: ");
    scanf("%d%d", &xa, &ya);
    printf("Input co-ordinate of end point: ");
    scanf("%d%d", &xb, &yb);

    lineMidpoint(xa, ya, xb, yb);
    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            fwrite(&pixel[i][j], sizeof(ch), 1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

void lineMidpoint(int X1, int Y1, int X2, int Y2)
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;

    if (dy <= dx)
    {
        int d = dy - (dx / 2);
        int x = X1, y = Y1;
        pixel[y][x] = 0;

        while (x < X2)
        {
            x++;
            if (d < 0)
                d = d + dy;
            else
            {
                d += (dy - dx);
                y++;
            }
            pixel[y][x] = 0;
        }
    }

    else if (dx < dy)
    {
        int d = dx - (dy / 2);
        int x = X1, y = Y1;
        pixel[y][x] = 0;

        while (y < Y2)
        {
            y++;
            if (d < 0)
                d = d + dx;
            else
            {
                d += (dx - dy);
                x++;
            }
            pixel[y][x] = 0;
        }
    }
}
