#include <iostream.h>
#include<conio.h>
#include<stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <graphics.h>

int gd = DETECT, gm;
int n, x[100], y[100], i;
int tx, ty;

void DrawFn()
{
    for (int i = 0; i < n; i++)
    line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
}

void Translate(int tx, int ty)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = x[i] + tx;
        y[i] = y[i] + ty;
    }
}

void main()
{
    cout << "Enter the number of sides: ";
    cin >> n;
    cout << "Enter the co-ordinates : x,y for each point: ";
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    cout << "Enter the value for translation on x,y axis (tx,ty): ";
    cin >> tx >> ty;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setcolor(4);
    cout << "Original RED Color and After Translation BLUE in Color";
    DrawFn();
    Translate(tx, ty);
    setcolor(15);
    DrawFn();
    getch();
}



