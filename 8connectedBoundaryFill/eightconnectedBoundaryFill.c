#include <stdio.h>
#define M 15
#define N 15


void impBoundFill(int Background[][N], int x, int y, int newColor, int boundaryColor)
{
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (Background[x][y] != boundaryColor && Background[x][y] != newColor){

        Background[x][y] = newColor;
	    impBoundFill(Background, x+1, y, newColor, boundaryColor);
	    impBoundFill(Background, x-1, y, newColor, boundaryColor);
	    impBoundFill(Background, x, y+1, newColor, boundaryColor);
	    impBoundFill(Background, x, y-1, newColor, boundaryColor);
    	impBoundFill(Background, x-1, y-1, newColor, boundaryColor);
	    impBoundFill(Background, x-1, y+1, newColor, boundaryColor);
	    impBoundFill(Background, x+1, y-1, newColor, boundaryColor);
	    impBoundFill(Background, x+1, y+1, newColor, boundaryColor);
    }
}


int main()
{
    
    int x,y,newColor,boundaryColor;
	
    int Background[15][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 0, 0, 0, 0},
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
    printf("Enter boundary color: ");
    scanf("%d",&boundaryColor);

    printf("\n");

	impBoundFill(Background, x, y, newColor, boundaryColor);
	printf("Background after 8-connected flood fill: \n");
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++)
		    printf("%d ",Background[i][j]);
        printf("\n");
    }
	
}

