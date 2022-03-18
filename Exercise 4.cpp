#include <iostream.h>
#include<conio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>

int gd = DETECT, gm;
int n, x[100], y[100], i;
float sx, sy;

void DrawFn()
{
    for (int i = 0; i < n; i++)
    line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
}

void Scale()
{
    for (int i = 0; i < n; i++)
    {
	x[i] = x[i] * sx;
	y[i] = y[i] * sy;
    }
}

void main()
{
    cout << "Enter the number of sides: ";
    cin >> n;
    cout << "Enter the co-ordinates : x,y for each point: \n ";
    for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];
    cout << "Enter the scale factor (sx,sy): ";
    cin >> sx >> sy;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(4);
    cout << "Original RED Color and After Scaling WHITE in Color";
    DrawFn();
    Scale();
    setcolor(15);
    DrawFn();
    getch();
}

