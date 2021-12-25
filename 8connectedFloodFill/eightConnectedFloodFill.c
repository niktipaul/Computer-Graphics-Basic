#include <stdio.h>
#define M 15
#define N 15


void impFloodFill(int Background[][N], int x, int y, int prevColor, int newColor)
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (Background[x][y] == prevColor){
        Background[x][y] = newColor;

	impFloodFill(Background, x+1, y, prevColor, newColor);
	impFloodFill(Background, x-1, y, prevColor, newColor);
	impFloodFill(Background, x, y+1, prevColor, newColor);
	impFloodFill(Background, x, y-1, prevColor, newColor);
	impFloodFill(Background, x-1, y-1, prevColor, newColor);
	impFloodFill(Background, x-1, y+1, prevColor, newColor);
	impFloodFill(Background, x+1, y-1, prevColor, newColor);
	impFloodFill(Background, x+1, y+1, prevColor, newColor);
    }
}


void floodFill(int Background[][N], int x, int y, int newColor)
{
	int prevColor = Background[x][y];
	if(prevColor == newColor) 
        return;
	impFloodFill(Background, x, y, prevColor, newColor);
}


int main()
{
    
    int x,y,newColor;
	
    int Background[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    printf("Background before 8-connected flood fill: \n");
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++)
		    printf("%d ",Background[i][j]);
        printf("\n");
    }

    printf("Enter x and y seed point coordinate: ");
    scanf("%d%d",&x,&y);
    printf("Enter new color: ");
    scanf("%d",&newColor);


    

    printf("\n");

	floodFill(Background, x, y, newColor);
	printf("Background after 8-connected flood fill: \n");
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++)
		    printf("%d ",Background[i][j]);
        printf("\n");
    }
	
}

