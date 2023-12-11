#include<stdio.h>
#include<easyx.h>

void Draw()
{
	initgraph(850, 650, 1);
	setbkcolor(RGB(255, 200, 89));
	setlinecolor(BLACK);
	cleardevice();
	IMAGE img1;
	loadimage(&img1, "./Res/1.jpg", 750, 550);
	putimage(100, 100, &img1);
	while (1);
	closegraph();
}
int main()
{
	Draw();

}