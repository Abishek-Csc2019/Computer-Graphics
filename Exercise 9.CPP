#include <conio.h>
#include <dos.h>
#include <alloc.h>
#include <graphics.h>
#include <iostream.h>
void main()
{

    int gd = DETECT, gm, ch, x = 300, y = 100, r = 40;
    void *ptr;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(YELLOW);

    circle(x, y, r);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(x, y, BLACK);
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, BLACK);

    circle(310, 85, 3);
    circle(290, 85, 3);

    ellipse(300, 100, 205, 335, 20, 9);
    ellipse(300, 100, 205, 335, 20, 10);
    ellipse(300, 100, 205, 335, 20, 11);
    rectangle(x - r, y - r, x + r, y + r);
    ptr = (void *)malloc(imagesize(x - r, y - r, x + r, y + r));
    getimage(x - r, y - r, x + r, y + r, ptr);
    cleardevice();
    do
    {
        cout << "Tile and Cascading an Object";
        cout << "1.Tile \n 2.Cascade \n 3.Exit \nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            outtextxy(200, 50, "Tile an Image");
            putimage(200, 100, ptr, COPY_PUT);
            putimage(300, 100, ptr, COPY_PUT);
            putimage(200, 200, ptr, COPY_PUT);
            putimage(300, 200, ptr, COPY_PUT);
            break;
        case 2:
            outtextxy(200, 50, "Cascade an Image");
            putimage(200, 100, ptr, COPY_PUT);
            putimage(220, 120, ptr, COPY_PUT);
            putimage(240, 140, ptr, COPY_PUT);
            putimage(260, 160, ptr, COPY_PUT);
            break;
        }
        getch();
    } while (ch < 3);
    closegraph();
}