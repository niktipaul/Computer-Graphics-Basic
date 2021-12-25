#include <stdio.h>
#include <math.h>

void dda(int,int,int,int);
char ch,pixel[200][200];


int main()
{
	FILE *fp1,*fp2;
	int xa,ya,xb,yb;
	int i,j;
	fp1=fopen("head.txt","rb");
        fp2=fopen("dda1.pgm","wb+");
        while(fread(&ch,sizeof(ch),1,fp1))
                fwrite(&ch,sizeof(ch),1,fp2);
	for(i=0;i<200;i++)
		for(j=0;j<200;j++)
			pixel[i][j] = 255;
	printf("Input Co-ordinate of first point\n");
	scanf("%d%d",&xa,&ya);
	printf("Input co-ordinate of end point\n");
	scanf("%d%d",&xb,&yb);
	dda(xa,ya,xb,yb);
	for(i=0;i<200;i++)
                for(j=0;j<200;j++)
                        fwrite(&pixel[i][j],sizeof(ch),1,fp2);
        fclose(fp1);
        fclose(fp2);
	return 0;
}


void dda(int x1,int y1,int x2,int y2)
{
	int dx,dy,x,y;
	int step,temp,i;
	if(x1>x2)
	{
		temp=x1;
		x1=x2;
		x2=temp;
		temp=y1;
		y1=y2;
		y2=temp;
	}
	dx=x2-x1;
	dy=y2-y1;
	x=x1;
	y=y1;
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	pixel[y][x] = 0;
	for(i=0;i<step;i++)
	{
		x=x+dx/step;
		if(y1<y2)
			y=y+abs(dy)/step;
		else
			y=y-abs(dy)/step;
		pixel[y][x] = 0;
	}
}

