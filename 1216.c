#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   //C语言标准库
#include <graphics.h>//图形库头文件
#include <string.h>  //字符串头文件
#include <windows.h> //键盘热键判断头文件
#include<stdlib.h>
#include <math.h>
#include<stdbool.h>
//#define char TCHAR
#include<assert.h>
#include<mmsystem.h>//播放音乐用头
#pragma comment(lib,"winmm.lib")//播放音乐 

struct Button;
struct Button* createButton(int x, int y, int w, int h, const char* str, COLORREF inColor, COLORREF outColor);
	void drawButton(struct Button* pB);
	bool isInButton(struct Button* pB, ExMessage m);
	bool isClickButton(struct Button* pB, ExMessage m);

void GameInit();
int playChess(void);
int JudgeWin(int a, int b);
int ContLimit(int n);        //用来限制二维数组a，b的值 其范围在1 - 15

int flag = 0;                //用来记录轮到哪个人下棋
int board[15][15] = { 0 };     //0表示没有下棋
HWND hwnd;
void Menu();

int main()
{
    int i = 0;               //判断是否退出游戏标志

    while (1)                         //当检测i不等于0时退出游戏
    {
        GameInit();  
		//Menu();                  //五子棋游戏初始化
        i = playChess(); //鼠标下棋
		
        if (i == 0)                       //判断是否继续游戏
        {
            continue;
        }
        cleardevice();                 //清屏函数
    }

    while(1);                        //防止闪退
    return 0;
}
void GameInit()
{
	//利用图形库创建一个窗口
	initgraph(520, 460);

	//添加背景图片,引号前加L是因为要将格式改成多字节字符集
	loadimage(NULL, "bk.jpg");


	setlinecolor(BLACK);     //将棋盘线条颜色改为黑色
	setlinestyle(PS_SOLID, 2);//将线条加粗


	//绘制棋盘
	line(26, 26, 390, 26);                 //横轴
	for (int i = 1; i <= 15; i++)
	{
		line(i * 26, 26, i * 26, 390);           //纵轴
		
	}
	for (int i = 1; i <= 14; i++)
	{
		line(26, 26 + i * 26, 390, 26 + i * 26);     //横轴
	}

	settextcolor(BLACK);   //将背景字体设置为黑色
	setbkmode(0);          //将背景字体设置透明
	/*显示下棋方*/
	outtextxy(445, 20, "玩家1:");    //图形库文字函数(x,y,"显示字符")
	outtextxy(480, 40, "黑棋");
	outtextxy(445, 70, "玩家2:");
	outtextxy(480, 90, "白棋");
	outtextxy(445, 400, "Esc:");     //
	outtextxy(445, 420, "退出游戏");
	float i = 25.2;
		outtextxy(1*i, 5, "1");outtextxy(2*i, 5, "2");outtextxy(3*i, 5, "3");outtextxy(4*i, 5, "4");//标记数字。
		outtextxy(5*i, 5, "5");outtextxy(6*i, 5, "6");outtextxy(7*i, 5, "7");outtextxy(8*i, 5, "8");
        outtextxy(9*i, 5, "9");outtextxy(10*i, 5, "10");outtextxy(11*i, 5, "11");outtextxy(12*i, 5, "12");
		outtextxy(13*i, 5, "13");outtextxy(14 * i, 5, "14");outtextxy(15 * i, 5, "15");
		outtextxy(5, 1*i-4, " 1");outtextxy(5, 2*i-4, " 2");outtextxy(5, 3*i-4, " 3");outtextxy(5, 4*i-4, " 4");
		outtextxy(5, 5*i-4, " 5");outtextxy(5, 6*i-4, " 6");outtextxy(5, 7*i-4, " 7");outtextxy(5, 8*i-4, " 8");
		outtextxy(5, 9*i, " 9");outtextxy(5, 10*i, "10");outtextxy(5, 11*i, "11");outtextxy(5, 12*i, "12");
		outtextxy(5, 13*i, "13");outtextxy(5, 14*i, "14");outtextxy(5, 15*i, "15");
			MessageBox(hwnd, "请玩家一执黑先行", "当前模式：人人对战", MB_OK);
			mciSendString("open ./music/start.WAV", NULL, 0, NULL);
			mciSendString("play ./music/start.WAV", NULL, 0, NULL);
}


int playChess(void)      //鼠标下棋函数
{
	//鼠标右键点击
	MOUSEMSG Mouse;  //鼠标结构体变量


	/*a,b为二维数组号,x,y为当前鼠标点击的坐标*/
	int a = 0;
	int b = 0;
	int x = 550;
	int y = 500;
	HWND hwnd;       //窗口句柄
	hwnd = GetHWnd();//窗口置前
	int ret = 0;     //判断游戏是否结束标志0
	int KeyRet = 0;  //键盘判断是否退出游戏
	int Key = 0;     //用作键盘热键判断的变量
	while (1)
	{
		Mouse = GetMouseMsg();  //获取一个鼠标消息

		Key = GetAsyncKeyState(VK_ESCAPE);//获取Esc键状态,若按下返回-127或-128


		if (Key < 0)               //判断获取键盘的信息,若键盘按下Esc,Key值小于0,则退出游戏
		{
			KeyRet = MessageBox(hwnd, "是否想退出游戏？", "提示", MB_YESNO | MB_ICONINFORMATION);  //MB_YESNO显示选项,MB_ICONINFORMATION为提示字前方图标
			if (KeyRet == IDYES)   //判断是否想重新开始一局游戏
			{
				exit(0);       //退出程序
			}
		}

		//下棋时鼠标点击横纵轴交点，用绝对值将点击的x,y坐标值取整，使鼠标点击规定的棋盘位置(向右向下偏移1格)
		for (int i = 1; i < 16; i++)
		{
			for (int j = 1; j < 16; j++)
			{
				if (abs(Mouse.x - i * 26) < 11 && abs(Mouse.y - j * 26) < 11)  //将点击的范围内的值取整
				{
					a = i;    //行列号
					b = j;
					x = i * 26; //坐标
					y = j * 26;
				}
			}
		}



		if (Mouse.uMsg == WM_LBUTTONDOWN) //判断当前鼠标左键是否按下
		{
			
			if (board[a][b] != 0)      //有棋子
			{
				MessageBox(hwnd, "无效落子地点,请重新选择下棋点", "五子棋", MB_OK);  //MB_OK为确定键
				//退出循环
				continue;
			}
			
			if (flag % 2 == 0)         //取余
			{
				setfillcolor(BLACK); //棋子颜色设置黑色
				solidcircle(x, y, 11); //画黑色棋子
				board[a][b] = 1;     //给数组赋值黑棋色号
			}
			else
			{
				setfillcolor(WHITE); //棋子颜色设置白色
				solidcircle(x, y, 11); //画白色棋子
				board[a][b] = 2;     //给数组赋值白棋色号
			}
			flag++;                 //下棋手判断

			if (flag >= 400)           //当棋盘下满时,平局。(0 - 399)
			{
				MessageBox(hwnd, "本局平局", "游戏结束", MB_OK);  //MB_OK为确定键
				if (ret == IDYES)   //判断是否想重新开始一局游戏
				{
					flag = 0;                      //用来记录轮到哪个人下棋
					memset(board, 0, sizeof(board)); //清空数组
					break;
				}
				else              //不重新开始，退出程序
				{
					exit(0);       //退出程序
				}
			}
		}
		if (JudgeWin(a, b))        //找到了五子连成一条线
		{
			if (flag % 2 == 1)
			{
				MessageBox(hwnd, "玩家1(黑棋)胜利", "游戏结束", MB_OK);  //MB_OK为确定键
			}
			else
			{
				MessageBox(hwnd, "玩家2(白棋)胜利", "游戏结束", MB_OK);  //MB_OK为确定键
			}

			ret = MessageBox(hwnd, "是否想重新开始一局游戏？", "提示", MB_YESNO | MB_ICONINFORMATION);  //MB_YESNO显示选项,MB_ICONINFORMATION为提示字前方图标

			if (ret == IDYES)   //判断是否想重新开始一局游戏
			{
				flag = 0;                      //用来记录轮到哪个人下棋
				memset(board, 0, sizeof(board)); //清空数组
				break;
			}
			else            //不重新开始，退出程序
			{
				exit(0);   //退出程序
			}
		}
	}

	return 0;
}

//判断输赢
int JudgeWin(int a, int b)
{
	/*
	   算法逻辑:以当前下棋点为原点,
	   1.以x轴（a - 4） - （a + 4）,开始检测连续点,若连续点>=5，则判定赢
	   2.以y轴a不变，（b - 4） - （b + 4），开始检测连续点，若连续点>=5,则判定win
	   3.以y = x轴，(a - 4) - （a + 4）,（b - 4） - （b + 4），开始检测连续点，若连续点>=5,则判定win
	   4.以y = -x轴，(a - 4) - （a + 4）,（b + 4） - （b - 4），开始检测连续点，若连续点>=5,则判定win

	*/
	int i = 0;
	int j = 0;
	int Cont_i = 0;          //连续棋子数

	int t = 2 - flag % 2;    //判定此次所下棋子色号
	//x轴判断
	for (i = ContLimit(a - 4); i <= ContLimit(a + 4); i++) //i值范围：（a - 4）至（a + 4）
	{
		j = b;
		if (board[i][j] != t) //若不是当前下的棋子色号
		{
			Cont_i = 0;      //连续棋子数清零
		}
		else if (board[i][j] == t) //若是当前下的棋子色号
		{
			Cont_i += 1;
		}

		if (Cont_i >= 5)        //若连续棋子数大于等于5
		{
			return 1;        //返回1,判定胜利
		}
	}

	Cont_i = 0;              //x轴判定未胜利,连续棋子数清零,进行y轴判定

	//y轴判断
	for (j = ContLimit(b - 4); j <= ContLimit(b + 4); j++) //j值范围：（b - 4）至（b + 4）
	{
		i = a;

		if (board[i][j] != t) //若不是当前下的棋子色号
		{
			Cont_i = 0;      //连续棋子数清零
		}
		else if (board[i][j] == t) //若是当前下的棋子色号
		{
			Cont_i += 1;
		}
		if (Cont_i >= 5)        //若连续棋子数大于等于5
		{
			return 1;        //返回1,判定胜利
		}
	}

	Cont_i = 0;              //x轴判定未胜利,连续棋子数清零,进行y轴判定

	//y = x判断
	for (i = ContLimit(a - 4), j = ContLimit(b - 4); i <= ContLimit(a + 4) && j <= (b + 4); i++, j++) //i值范围：（a - 4）至（a + 4）,j值范围：（b - 4）至（b + 4）
	{
		//i = a;

		if (board[i][j] != t) //若不是当前下的棋子色号
		{
			Cont_i = 0;      //连续棋子数清零
		}
		else if (board[i][j] == t) //若是当前下的棋子色号
		{
			Cont_i += 1;
		}

		if (Cont_i >= 5)        //若连续棋子数大于等于5
		{
			return 1;        //返回1,判定胜利
		}
	}

	Cont_i = 0;              //x轴判定未胜利,连续棋子数清零,进行y轴判定

	//y = -x判断
	for (i = ContLimit(a - 4), j = ContLimit(b + 4); i <= ContLimit(a + 4) && j >= ContLimit(b - 4); i++, j--) //i值范围：（a - 4）至（a + 4）,j值范围：（b + 4）至（b - 4）
	{
		//i = a;

		if (board[i][j] != t) //若不是当前下的棋子色号
		{
			Cont_i = 0;      //连续棋子数清零
		}
		else if (board[i][j] == t) //若是当前下的棋子色号
		{
			Cont_i += 1;
		}

		if (Cont_i >= 5)        //若连续棋子数大于等于5
		{
			return 1;        //返回1,判定胜利
		}
	}

	return 0;

}
int ContLimit(int n)       //用来限制二维数组a，b的值 其范围在1-15
{
	if (n > 16)               //若输入数据大于15
	{
		return 15;         //返回15
	}
	else if (n < 0)           //若输入数据小于0
	{
		return 0;          //返回0
	}
	else                   //若不满足以上条件,返回原值
	{
		return n;
	}

	return n;
}
void Menu()
{
	//利用图形库创建一个窗口
	initgraph(520, 460);

	//添加背景图片,引号前加L是因为要将格式改成多字节字符集
	loadimage(NULL, "bk2.jpg",520,460);
	settextcolor(BLACK);   //将背景字体设置为黑色
	setbkmode(0);
	settextstyle(50,30, "楷体");
	outtextxy(50, 50, "五子棋");
	settextstyle(40, 25, "FRSCRIPT.TTF");
	outtextxy(40, 160, "PVP");
	outtextxy(40,240, "PVE");
	outtextxy(40, 320, "EVE");

	//settextstyle(12, 12, "mingliub.ttc");
	//settextcolor(RGB(255,0,0));
	//outtextxy(240, 150, "好好学习");
	//outtextxy(320, 150, "不怕牺牲");
	//outtextxy(240, 180, "天天向上");
	//outtextxy(320, 180, "争取胜利");

	
	struct Button* PVP = createButton(40, 160, 90,50, "PVP", RGB(236, 244, 255), RGB(192, 224, 245));
	struct Button* PVE = createButton(40, 240, 90, 50, "PVE", RGB(236, 244, 255), RGB(228, 238, 247));
	struct Button* EVE = createButton(40, 320, 90, 50, "EVE", RGB(236, 244, 255), RGB(231, 238, 246));
	BeginBatchDraw();
	ExMessage m;
	while (1)
	{
		//cleardevice();
		drawButton(PVP);
		drawButton(PVE);
		drawButton(EVE);
		peekmessage(&m, EM_MOUSE);

			if (isClickButton(PVP, m))
			{
				mciSendString("open ./music/select.mp3", NULL, 0, NULL);
				mciSendString("play ./music/select.mp3", NULL, 0, NULL);
			}
			if (isClickButton(PVE, m))
			{
				mciSendString("open ./music/select.mp3", NULL, 0, NULL);
				mciSendString("play ./music/select.mp3", NULL, 0, NULL);
			}
			if (isClickButton(EVE, m))
			{
				mciSendString("open ./music/select.mp3", NULL, 0, NULL);
				mciSendString("play ./music/select.mp3", NULL, 0, NULL);
			}
		FlushBatchDraw();
	}
	EndBatchDraw();
	
	
}
struct Button
{
	int x;
	int y;
	int w;
	int h;
	COLORREF curColor;
	COLORREF inColor;
	COLORREF outColor;
	char* text;
};
struct Button* createButton(int x, int y, int w, int h, const char* str, COLORREF inColor,COLORREF outColor)
{
	struct Button* pB = (struct Button*)malloc(sizeof(struct Button));
	assert(pB);
	pB->x = x;
	pB->y = y;
	pB->w = w;

	pB->h = h;
	pB->inColor = inColor;
	pB->outColor = outColor;
	//pB->curColor = curColor;
	int textLength = strlen(str) + 1;
	pB->text = (char*)malloc(sizeof(char) * textLength);
	assert(pB->text);
	strcpy_s(pB->text, textLength, str);
	return pB;
}   
void drawButton(struct Button* pB)
{
	//1.画一个矩形
	setlinecolor(BLACK);
	setfillcolor(pB->curColor);
	fillrectangle(pB->x, pB->y, pB->x + pB->w, pB->y + pB->h);
	//2.画文字
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "楷体");
	//3.自动居中
	int textw = textwidth(pB->text);
	int texth = textwidth(pB->text);
	int xx = pB->x + (pB->w - textw) / 2;
	int yy = pB->y + (pB->h - texth) / 2;
	outtextxy(xx, yy, pB->text);
}
bool isInButton(struct Button* pB, ExMessage m)
{
	if (m.x > pB->x && m.x<pB->x + pB->w && m.y>pB->y && m.y < pB->y + pB->h)
	{
		pB->curColor = pB->inColor;
		return true;
	}
	pB->curColor = pB->outColor;
	return false;
}
bool isClickButton(struct Button* pB, ExMessage m)
{
	if (isInButton(pB, m) && m.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}