#include <stdio.h>
#include <math.h>

void squareBresenham(int, int, int);
void doubleQuadrants(int, int, int, int);
char ch, pixel[200][200];

int main()
{
    FILE *fp1, *fp2;
    int xa, ya, r;
    int i, j;

    fp1 = fopen("head.txt", "rb");
    fp2 = fopen("squareBresenham.pgm", "wb+");

    while (fread(&ch, sizeof(ch), 1, fp1))
        fwrite(&ch, sizeof(ch), 1, fp2);

    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            pixel[i][j] = 255;

    printf("Input co-ordinate of the centre of the square: ");
    scanf("%d%d", &xa, &ya);
    printf("Input side/2 of the square: ");
    scanf("%d", &r);

    squareBresenham(xa, ya, r);
    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            fwrite(&pixel[i][j], sizeof(ch), 1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

void squareBresenham(int xa, int ya, int r)
{

    int x = 0, y = r, d = 3 - (2 * r);
    
    do
    {
        doubleQuadrants(xa, ya, x, y);
        if (d < 0)
        {
            d = d + (2 - x) + 3;
        }
        else
        {
            d = d + 5 + (2 * (x -y));
            y = y - 1;
        }
        x = x + 1;
        doubleQuadrants(xa, ya, x, y);
    }while (x < y);
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