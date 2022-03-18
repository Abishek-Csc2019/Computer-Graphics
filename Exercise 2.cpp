#include <graphics.h>
#include <iostream.h>
#include <dos.h>
#include <conio.h>
void Bres_circle(double x1, double y1, double r)
{
	double x = 0, y = r;
	double p = 3 - (2 * r);
	while (x <= y)
	{
		putpixel(x1 + x, y1 + y, WHITE);
		putpixel(x1 - x, y1 + y, RED);
		putpixel(x1 + x, y1 - y, GREEN);
		putpixel(x1 - x, y1 - y, BLUE);
		putpixel(x1 + y, y1 + x, BLUE);
		putpixel(x1 + y, y1 - x, RED);
		putpixel(x1 - y, y1 + x, GREEN);
		putpixel(x1 - y, y1 - x, WHITE);

		x = x + 1;
		if (p < 0)
			p = p + 4 * (x) + 6;
		else
		{
			p = p + 4 * (x - y) + 10;
			y = y - 1;
		}
		delay(100);
	}
}
int main()
{
	double x1, y1, r;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	cout << "Enter the starting co - ordinates of a center (x, y): ";
	cin >> x1 >> y1;
	cout << "Enter the value of radius: ";
	cin >> r;
	Bres_circle(x1, y1, r);
	getch();
	closegraph();
	return 0;
}
