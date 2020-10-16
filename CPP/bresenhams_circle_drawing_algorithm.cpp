// C++ Implementation for drawing line
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>

void plotCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}
void circle()
{
    int Xc, Yc, R, D, X, Y;
    cout << "Enter Coordinates of centre of circle : ";
    cin >> Xc >> Yc;
    cout << "Enter the Radius of Circle : ";
    cin >> R;
    D = 3 - 2 * R;
    X = 0;
    Y = R;
    plotCircle(Xc, Yc, X, Y);
    while (X < Y)
    {
	if (D < 0)
	{
	    D = D + 4 * X + 6;
	    X = X + 1;
	    Y = Y;
	}
	else
	{
	    D = D + 4 * X - 4 * Y + 10;
	    X = X + 1;
	    Y = Y - 1;
	};

	plotCircle(Xc, Yc, X, Y);
    }
}
int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    circle();
    getch();
    closegraph();
    return 0;
}
