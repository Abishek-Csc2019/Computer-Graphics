#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
int sign(int x)
{
  if (x > 0)
    return 1;
  else if (x < 0)
    return -1;
  else
    return 0;
}
void bres(int x1, int y1, int x2, int y2)
{
  int x, y, dx, dy, s1, s2, swap, temp, p, i;
  x = x1;
  y = y1;
  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2 - x1);
  s2 = sign(y2 - y1);
  swap = 0;
  putpixel(x, y, WHITE);
  if (dy > dx)
  {
    temp = dx;
    dx = dy;
    dy = temp;
    swap = 1;
  }
  p = 2 * dy - dx;
  for (i = 0; i < dx; i++)
  {
    putpixel(x, y, WHITE);
    while (p >= 0)
    {
      p = p - 2 * dx;
      if (swap == 1)
        x += s1;
      else
        y += s2;
    }
    p = p + 2 * dy;
    if (swap == 1)
      y += s2;
    else
      x += s1;
  }
  putpixel(x, y, WHITE);
}

void main()
{
  int x1, y1, x2, y2;
  int gd = DETECT, gm;
  cout << "Enter x1 :";
  cin >> x1;
  cout << "Enter y1 :";
  cin >> y1;
  cout << "Enter x2 :";
  cin >> x2;
  cout << "Enter y2 :";
  cin >> y2;
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  bres(x1, y1, x2, y2);
  getch();
  closegraph();
}
