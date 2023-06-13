#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.80



void hut(){
  setcolor(WHITE);
    rectangle(233,263,333,383);
    rectangle(333,263,503,383);
    rectangle(263,333,303,383);

    line(283,183,233,263);
    line(283,183,333,263);
    line(283,183,453,183);
    line(453,183,503,263);

    setfillstyle(SOLID_FILL, BROWN);
    floodfill(235, 265, WHITE);
    floodfill(335, 265, WHITE);

    setfillstyle(SLASH_FILL, BLUE);
    floodfill(265, 335, WHITE);

    setfillstyle(BKSLASH_FILL, LIGHTMAGENTA);
    floodfill(283, 188, WHITE);
    floodfill(293, 188, WHITE);
}


void Rain(int x)
{
int i,rx,ry;
for(i=0;i<400;i++)
{
 rx=rand() % ScreenWidth;
 ry=rand() % ScreenHeight;
 if(ry<GroundY-4)
 {
  if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))
  line(rx,ry,rx+0.5,ry+4);
 }
}

}
void cloud()
{
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
ellipse(400,50,0,180,25,20);
ellipse(425,70,260,90,20,20);
ellipse(400,90,180,360,20,20);
ellipse(380,70,90,270,20,20);
floodfill(400,80,WHITE);
}

void cloud1()
{
setcolor(LIGHTGRAY);
setfillstyle(SOLID_FILL,LIGHTGRAY);
ellipse(400,50,0,180,25,20);
ellipse(425,70,260,90,20,20);
ellipse(400,90,180,360,20,20);
ellipse(380,70,90,270,20,20);
floodfill(400,80,LIGHTGRAY);
}
void rainbow()
{
    int x, y, i;
//SUN
    circle(ScreenWidth-100,50,30);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(ScreenWidth-100, 50, WHITE);


   hut();
    x = getmaxx() / 2;
    y = getmaxy() /2;


    for (i=20; i<150; i++)
    {
	delay(100);
	setcolor(i/5);
	arc(150, 150, 0, 180, i-2);
    }
    getch();
}


void main()
{
  int gd=DETECT,gm,x=0;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  while(!kbhit())
  {
     //LINE BTW SKY AND GRASS
line(0,getmaxy()*0.80, getmaxx(),getmaxy()*0.80);
 //SKY
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 floodfill(0,0,WHITE);

 //GRASS
 setfillstyle(SOLID_FILL,GREEN);
floodfill(getmaxx(),getmaxy(),WHITE);

     circle(ScreenWidth-100,50,30);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(ScreenWidth-100, 50, WHITE);

//cloud();
  cloud1();
  hut();

   line(0,GroundY,ScreenWidth,GroundY);
   Rain(x);

 delay(500);
   cleardevice();
   x=(x+2)%ScreenWidth;
}

  cloud();
//LINE BTW SKY AND GRASS
line(0,getmaxy()*0.80, getmaxx(),getmaxy()*0.80);

 //GRASS
 setfillstyle(SOLID_FILL,GREEN);
floodfill(getmaxx(),getmaxy(),WHITE);

 //SKY
 setfillstyle(SOLID_FILL,LIGHTBLUE);
 floodfill(0,0,WHITE);
  rainbow();
  getch();
}
