#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <iostream.h>
void main()
{
    int gd, gm, x, y, r, i, j = 0, high;
    void *ptr;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    x = 20;
    y = 380;
    r = 15;
    setcolor(RED);
    circle(x, y, r);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x, y, RED);
    getimage(x - r, y - r, x + r, y + r, ptr);
    high = 300;
    while (high >= 0 && !kbhit())
    {
        for (i = 0; i <= high; i++)
        {
            cleardevice();
            setcolor(WHITE);
            line(0, 405, 639, 405);
            putimage(x, y, ptr, COPY_PUT);
            delay(3);
            if (i % 4 == 0)
                j++;
            x = 20 + j;
            y = 380 - i;
        }
        for (i = high; i > 0; i--)
        {
            cleardevice();
            setcolor(WHITE);
            line(0, 405, 639, 405);
            putimage(x, y, ptr, COPY_PUT);
            delay(3);
            if (i % 6 == 0)
                j++;
            x = 20 + j;
            y = 380 - i;
        }
        high = high - 40;
    }
    getch();
}
