#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void ddaline(int xa, int ya, int xb, int yb)
{
    int dx, dy, steps;
    float xincrement, yincrement, x, y;
    dx = xb - xa;
    dy = yb - ya;
    x = xa;
    y = ya;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xincrement = float(dx) / steps;
    yincrement = float(dy) / steps;
    putpixel(ceil(x), ceil(y), 1);
    for (int k = 0; k < steps; k++)
    {
        x = x + xincrement;
        y = y + yincrement;
        putpixel(ceil(x), ceil(y), 1);
    }
}

void main()
{
    int gm, gd = DETECT, x1, y1, x2, y2;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    cout << "Enter the end-points \n";
    cout << "Enter x1 :";
    cin >> x1;
    cout << "Enter y1 :";
    cin >> y1;
    cout << "Enter x2 :";
    cin >> x2;
    cout << "Enter y2 :";
    cin >> y2;
    ddaline(x1, y1, x2, y2);
    getch();
    closegraph();
}
