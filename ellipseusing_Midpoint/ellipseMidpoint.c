#include <stdio.h>
#include <math.h>

void ellipseMidpoint(int, int, int, int);
void Quadrants(int, int, int, int);
char ch, pixel[200][200];

int main()
{
    FILE *fp1, *fp2;
    int h, k, a, b;
    int i, j;

    fp1 = fopen("head.txt", "rb");
    fp2 = fopen("ellipseMidpoint.pgm", "wb+");

    while (fread(&ch, sizeof(ch), 1, fp1))
        fwrite(&ch, sizeof(ch), 1, fp2);

    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            pixel[i][j] = 255;

    printf("Input co-ordinate of the centre of the ellipse: ");
    scanf("%d%d", &h, &k);
    printf("Input major and minor axis of the ellipse: ");
    scanf("%d%d", &a, &b);

    ellipseMidpoint(h, k, a, b);
    for (i = 0; i < 200; i++)
        for (j = 0; j < 200; j++)
            fwrite(&pixel[i][j], sizeof(ch), 1, fp2);
    fclose(fp1);
    fclose(fp2);
    return 0;
}

void ellipseMidpoint(int h, int k, int a, int b)
{

    float x = 0, y = b, p1, p2, dx, dy;

    // For Region 1
    p1 = (b * b) - (a * a * b) + (a * a) / 4;
    dx = 2 * b * b * x;
    dy = 2 * a * a * y;

    while (dx < dy)
    {
        Quadrants(h, k, x, y);
        if (p1 < 0)
        {
            x++;
            dx = dx + (2 * b * b);
            p1 = p1 + dx + (b * b);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            p1 = p1 + dx - dy + (b * b);
        }
    }

    // For Region 2
    p2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) - (a * a * b * b);

    while (y >= 0)
    {
        Quadrants(h, k, x, y);
        if (p2 > 0)
        {
            y--;
            dy = dy - (2 * a * a);
            p2 = p2 + (a * a) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            p2 = p2 + dx - dy + (a * a);
        }
    }
}

void Quadrants(int h, int k, int x, int y)
{
    pixel[x + h][y + k] = 0;
    pixel[x + h][-y + k] = 0;
    pixel[-x + h][y + k] = 0;
    pixel[-x + h][-y + k] = 0;
}