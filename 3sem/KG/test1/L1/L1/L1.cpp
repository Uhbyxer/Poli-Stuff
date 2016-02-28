#include <stdio.h>	
#include <stdlib.h>	
#include <dos.h>	
#include <graph.h>	
#include <conio.h>	
// this function initializes graphics mode	
// it will work only if you're using Borland C++ compiler & BGI drivers	
// if you're using another compiler you should overwrite body of this function	
void init_gr(void)	
{	
    /* request autodetection */	
    int gdriver = DETECT, gmode, errorcode;	
    /* initialize graphics mode */	
    initgraph(&gdriver, &gmode, "");	
    /* read result of initialization */	
    errorcode = graphresult();	
    if (errorcode != grOk)    /* an error occurred */	
    {	
       printf("Graphics error: %s\n", grapherrormsg(errorcode));	
       printf("Press any key to halt:");	
       getch();	
       exit(1);               /* return with error code */	
    }	
}	
// this function shuts graphics mode down	
// it will work only if you're using Borland C++ compiler & BGI drivers	
// if you're using another compiler you should overwrite body of this function	
void end_gr(void)	
{	
  closegraph();	
}	
// this function puts pixel on the screen in (x,y) position using color 'color'	
// it will work only if you're using Borland C++ compiler & BGI drivers	
// if you're using another compiler you should overwrite body of this function	
void PutPixel(int x, int y, int color)	
{	
  putpixel(x,y,color);	
}	
#define N       200000L // number of points	
float x=0, y=0; // iteration variables (are global)	
//                       a     b     c    d    e    f        probability	
float coeff[4][6] = {{ 0.00, 0.00, 0.00,0.16,0.00,0.00,},   // 01%	
                     { 0.85, 0.04,-0.04,0.85,0.00,1.60,},   // 85%	
                     { 0.05,-0.26, 0.23,0.22,0.00,1.60,},   // 07%	
                     {-0.15, 0.30, 0.26,0.24,0.00,0.44,},}; // 07%	
int colors[5]={10,11,2,3,2};	
void iterate(char i,int c)	
{	
  float x1,y1;	
  x1=x*coeff[i][0]+y*coeff[i][1]+coeff[i][4];	
  y1=x*coeff[i][2]+y*coeff[i][3]+coeff[i][5];	
  x=x1;	
  y=y1;	
  putpixel ((int)(y*64),240-(int)(x*48),c);	
}	
int main (void)	
{	
  int leaf,color;	
  // initializing graphics mode	
  init_gr();	
  // drawing leafs	
  for (long int i=0;i<N;i++)	
  {	
     color=colors[random(5)];  // random color	
     leaf=random(1000);  // selecting leaf to draw	
     if (leaf<=10) iterate(0,color);	
     else if (leaf<=860) iterate(1,color);	
     else if (leaf<=930) iterate(2,color);	
     else iterate(3,color);	
  }	
  /* clean up */	
  getch();	
  end_gr();	
  return 0;	
}