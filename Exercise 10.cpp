#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
void main()
{
    int gd, gm, x1 = 200, y1 = 200, x2 = 400, y2 = 400, r = (x2 - x1) / 2, i, j = 0;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    for (i = 0; i < (x2 - x1) / 2 && !kbhit(); i++)
    {
        outtextxy(50, 50, "REDUCING AN IMAGE :");
        rectangle(x1 + i, y1 + i, x2 - i, y2 - i);
        circle((x1 + x2) / 2, (y1 + y2) / 2, r - i);
        if (i % 2 == 0)
        {
            setcolor(RED);
            setfillstyle(SOLID_FILL, RED);
            circle((x1 + x2) / 2, (y1 + y2) / 2, r / 2 - j);
            floodfill((x1 + x2) / 2, (y1 + y2) / 2, RED);
            j++;
            setcolor(WHITE);
        }
        delay(100);
        cleardevice();
    }
    outtextxy(50, 50, "IMAGE DISAPPEAR");
    getch();
    closegraph();
}
