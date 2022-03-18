#include <iostream.h>
#include<conio.h>
#include <math.h>
#include <dos.h>
#include <graphics.h>

int gd = DETECT, gm;
int theta, n, x[100], y[100], rx[100], ry[100], i, xp, yp;
float rad;

void DrawFn(int a[], int b[])
{
    for (int i = 0; i < n; i++)
	line(a[i], b[i], a[(i + 1) % n], b[(i + 1) % n]);
}

void Rotate()
{
    for(int i=0;i<n;i++)
    {
	rx[i] = xp +( (x[i] - xp) * cos(rad) - (y[i] - yp) * sin(rad) );
	ry[i] = yp +( (x[i] - xp) * sin(rad) + (y[i] - yp) * cos(rad) );
    }
}

void main()
{
    cout << "Enter the number of sides: ";
    cin >> n;
    cout << "Enter the co-ordinates : x,y for each point: ";
    for (int i = 0; i < n; i++)
	cin >> x[i] >> y[i];
    cout << "Enter the pivotal point (point of rotation): ";
    cin >> xp >> yp;
    cout << "Enter the angle to rotate (theta): ";
    cin >> theta;

    rad=3.1419*theta/180;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(4);
    cout << "Original RED Color and After Rotation WHITE in Color";
    DrawFn(x,y);
    Rotate();
    setcolor(15);
    DrawFn(rx,ry);
    getch();
}

