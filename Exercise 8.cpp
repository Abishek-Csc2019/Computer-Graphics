#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>

void main()
{
    int i = 0;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    rectangle(0, 0, getmaxx(), getmaxy());
    int x = getmaxx() - 1, y = getmaxy() - 1;
    while (!kbhit())
    {
        i++;
        int xx = random(x);
        int yy = random(y);
        if (xx > 10 && xx < getmaxx() - 10 && yy > 10 && yy < getmaxy() - 10)
        {
            circle(xx, yy, 10);
            setfillstyle(random(i), random(30));
            floodfill(xx, yy, getmaxcolor());
            delay(100);
        }
    }
    getch();
    closegraph();
}