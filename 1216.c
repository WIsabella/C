#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   //C���Ա�׼��
#include <graphics.h>//ͼ�ο�ͷ�ļ�
#include <string.h>  //�ַ���ͷ�ļ�
#include <windows.h> //�����ȼ��ж�ͷ�ļ�
#include<stdlib.h>
#include <math.h>
#include<stdbool.h>
//#define char TCHAR
#include<assert.h>
#include<mmsystem.h>//����������ͷ
#pragma comment(lib,"winmm.lib")//�������� 

struct Button;
struct Button* createButton(int x, int y, int w, int h, const char* str, COLORREF inColor, COLORREF outColor);
	void drawButton(struct Button* pB);
	bool isInButton(struct Button* pB, ExMessage m);
	bool isClickButton(struct Button* pB, ExMessage m);

void GameInit();
int playChess(void);
int JudgeWin(int a, int b);
int ContLimit(int n);        //�������ƶ�ά����a��b��ֵ �䷶Χ��1 - 15

int flag = 0;                //������¼�ֵ��ĸ�������
int board[15][15] = { 0 };     //0��ʾû������
HWND hwnd;
void Menu();

int main()
{
    int i = 0;               //�ж��Ƿ��˳���Ϸ��־

    while (1)                         //�����i������0ʱ�˳���Ϸ
    {
        GameInit();  
		//Menu();                  //��������Ϸ��ʼ��
        i = playChess(); //�������
		
        if (i == 0)                       //�ж��Ƿ������Ϸ
        {
            continue;
        }
        cleardevice();                 //��������
    }

    while(1);                        //��ֹ����
    return 0;
}
void GameInit()
{
	//����ͼ�οⴴ��һ������
	initgraph(520, 460);

	//��ӱ���ͼƬ,����ǰ��L����ΪҪ����ʽ�ĳɶ��ֽ��ַ���
	loadimage(NULL, "bk.jpg");


	setlinecolor(BLACK);     //������������ɫ��Ϊ��ɫ
	setlinestyle(PS_SOLID, 2);//�������Ӵ�


	//��������
	line(26, 26, 390, 26);                 //����
	for (int i = 1; i <= 15; i++)
	{
		line(i * 26, 26, i * 26, 390);           //����
		
	}
	for (int i = 1; i <= 14; i++)
	{
		line(26, 26 + i * 26, 390, 26 + i * 26);     //����
	}

	settextcolor(BLACK);   //��������������Ϊ��ɫ
	setbkmode(0);          //��������������͸��
	/*��ʾ���巽*/
	outtextxy(445, 20, "���1:");    //ͼ�ο����ֺ���(x,y,"��ʾ�ַ�")
	outtextxy(480, 40, "����");
	outtextxy(445, 70, "���2:");
	outtextxy(480, 90, "����");
	outtextxy(445, 400, "Esc:");     //
	outtextxy(445, 420, "�˳���Ϸ");
	float i = 25.2;
		outtextxy(1*i, 5, "1");outtextxy(2*i, 5, "2");outtextxy(3*i, 5, "3");outtextxy(4*i, 5, "4");//������֡�
		outtextxy(5*i, 5, "5");outtextxy(6*i, 5, "6");outtextxy(7*i, 5, "7");outtextxy(8*i, 5, "8");
        outtextxy(9*i, 5, "9");outtextxy(10*i, 5, "10");outtextxy(11*i, 5, "11");outtextxy(12*i, 5, "12");
		outtextxy(13*i, 5, "13");outtextxy(14 * i, 5, "14");outtextxy(15 * i, 5, "15");
		outtextxy(5, 1*i-4, " 1");outtextxy(5, 2*i-4, " 2");outtextxy(5, 3*i-4, " 3");outtextxy(5, 4*i-4, " 4");
		outtextxy(5, 5*i-4, " 5");outtextxy(5, 6*i-4, " 6");outtextxy(5, 7*i-4, " 7");outtextxy(5, 8*i-4, " 8");
		outtextxy(5, 9*i, " 9");outtextxy(5, 10*i, "10");outtextxy(5, 11*i, "11");outtextxy(5, 12*i, "12");
		outtextxy(5, 13*i, "13");outtextxy(5, 14*i, "14");outtextxy(5, 15*i, "15");
			MessageBox(hwnd, "�����һִ������", "��ǰģʽ�����˶�ս", MB_OK);
			mciSendString("open ./music/start.WAV", NULL, 0, NULL);
			mciSendString("play ./music/start.WAV", NULL, 0, NULL);
}


int playChess(void)      //������庯��
{
	//����Ҽ����
	MOUSEMSG Mouse;  //���ṹ�����


	/*a,bΪ��ά�����,x,yΪ��ǰ�����������*/
	int a = 0;
	int b = 0;
	int x = 550;
	int y = 500;
	HWND hwnd;       //���ھ��
	hwnd = GetHWnd();//������ǰ
	int ret = 0;     //�ж���Ϸ�Ƿ������־0
	int KeyRet = 0;  //�����ж��Ƿ��˳���Ϸ
	int Key = 0;     //���������ȼ��жϵı���
	while (1)
	{
		Mouse = GetMouseMsg();  //��ȡһ�������Ϣ

		Key = GetAsyncKeyState(VK_ESCAPE);//��ȡEsc��״̬,�����·���-127��-128


		if (Key < 0)               //�жϻ�ȡ���̵���Ϣ,�����̰���Esc,KeyֵС��0,���˳���Ϸ
		{
			KeyRet = MessageBox(hwnd, "�Ƿ����˳���Ϸ��", "��ʾ", MB_YESNO | MB_ICONINFORMATION);  //MB_YESNO��ʾѡ��,MB_ICONINFORMATIONΪ��ʾ��ǰ��ͼ��
			if (KeyRet == IDYES)   //�ж��Ƿ������¿�ʼһ����Ϸ
			{
				exit(0);       //�˳�����
			}
		}

		//����ʱ����������ύ�㣬�þ���ֵ�������x,y����ֵȡ����ʹ������涨������λ��(��������ƫ��1��)
		for (int i = 1; i < 16; i++)
		{
			for (int j = 1; j < 16; j++)
			{
				if (abs(Mouse.x - i * 26) < 11 && abs(Mouse.y - j * 26) < 11)  //������ķ�Χ�ڵ�ֵȡ��
				{
					a = i;    //���к�
					b = j;
					x = i * 26; //����
					y = j * 26;
				}
			}
		}



		if (Mouse.uMsg == WM_LBUTTONDOWN) //�жϵ�ǰ�������Ƿ���
		{
			
			if (board[a][b] != 0)      //������
			{
				MessageBox(hwnd, "��Ч���ӵص�,������ѡ�������", "������", MB_OK);  //MB_OKΪȷ����
				//�˳�ѭ��
				continue;
			}
			
			if (flag % 2 == 0)         //ȡ��
			{
				setfillcolor(BLACK); //������ɫ���ú�ɫ
				solidcircle(x, y, 11); //����ɫ����
				board[a][b] = 1;     //�����鸳ֵ����ɫ��
			}
			else
			{
				setfillcolor(WHITE); //������ɫ���ð�ɫ
				solidcircle(x, y, 11); //����ɫ����
				board[a][b] = 2;     //�����鸳ֵ����ɫ��
			}
			flag++;                 //�������ж�

			if (flag >= 400)           //����������ʱ,ƽ�֡�(0 - 399)
			{
				MessageBox(hwnd, "����ƽ��", "��Ϸ����", MB_OK);  //MB_OKΪȷ����
				if (ret == IDYES)   //�ж��Ƿ������¿�ʼһ����Ϸ
				{
					flag = 0;                      //������¼�ֵ��ĸ�������
					memset(board, 0, sizeof(board)); //�������
					break;
				}
				else              //�����¿�ʼ���˳�����
				{
					exit(0);       //�˳�����
				}
			}
		}
		if (JudgeWin(a, b))        //�ҵ�����������һ����
		{
			if (flag % 2 == 1)
			{
				MessageBox(hwnd, "���1(����)ʤ��", "��Ϸ����", MB_OK);  //MB_OKΪȷ����
			}
			else
			{
				MessageBox(hwnd, "���2(����)ʤ��", "��Ϸ����", MB_OK);  //MB_OKΪȷ����
			}

			ret = MessageBox(hwnd, "�Ƿ������¿�ʼһ����Ϸ��", "��ʾ", MB_YESNO | MB_ICONINFORMATION);  //MB_YESNO��ʾѡ��,MB_ICONINFORMATIONΪ��ʾ��ǰ��ͼ��

			if (ret == IDYES)   //�ж��Ƿ������¿�ʼһ����Ϸ
			{
				flag = 0;                      //������¼�ֵ��ĸ�������
				memset(board, 0, sizeof(board)); //�������
				break;
			}
			else            //�����¿�ʼ���˳�����
			{
				exit(0);   //�˳�����
			}
		}
	}

	return 0;
}

//�ж���Ӯ
int JudgeWin(int a, int b)
{
	/*
	   �㷨�߼�:�Ե�ǰ�����Ϊԭ��,
	   1.��x�ᣨa - 4�� - ��a + 4��,��ʼ���������,��������>=5�����ж�Ӯ
	   2.��y��a���䣬��b - 4�� - ��b + 4������ʼ��������㣬��������>=5,���ж�win
	   3.��y = x�ᣬ(a - 4) - ��a + 4��,��b - 4�� - ��b + 4������ʼ��������㣬��������>=5,���ж�win
	   4.��y = -x�ᣬ(a - 4) - ��a + 4��,��b + 4�� - ��b - 4������ʼ��������㣬��������>=5,���ж�win

	*/
	int i = 0;
	int j = 0;
	int Cont_i = 0;          //����������

	int t = 2 - flag % 2;    //�ж��˴���������ɫ��
	//x���ж�
	for (i = ContLimit(a - 4); i <= ContLimit(a + 4); i++) //iֵ��Χ����a - 4������a + 4��
	{
		j = b;
		if (board[i][j] != t) //�����ǵ�ǰ�µ�����ɫ��
		{
			Cont_i = 0;      //��������������
		}
		else if (board[i][j] == t) //���ǵ�ǰ�µ�����ɫ��
		{
			Cont_i += 1;
		}

		if (Cont_i >= 5)        //���������������ڵ���5
		{
			return 1;        //����1,�ж�ʤ��
		}
	}

	Cont_i = 0;              //x���ж�δʤ��,��������������,����y���ж�

	//y���ж�
	for (j = ContLimit(b - 4); j <= ContLimit(b + 4); j++) //jֵ��Χ����b - 4������b + 4��
	{
		i = a;

		if (board[i][j] != t) //�����ǵ�ǰ�µ�����ɫ��
		{
			Cont_i = 0;      //��������������
		}
		else if (board[i][j] == t) //���ǵ�ǰ�µ�����ɫ��
		{
			Cont_i += 1;
		}
		if (Cont_i >= 5)        //���������������ڵ���5
		{
			return 1;        //����1,�ж�ʤ��
		}
	}

	Cont_i = 0;              //x���ж�δʤ��,��������������,����y���ж�

	//y = x�ж�
	for (i = ContLimit(a - 4), j = ContLimit(b - 4); i <= ContLimit(a + 4) && j <= (b + 4); i++, j++) //iֵ��Χ����a - 4������a + 4��,jֵ��Χ����b - 4������b + 4��
	{
		//i = a;

		if (board[i][j] != t) //�����ǵ�ǰ�µ�����ɫ��
		{
			Cont_i = 0;      //��������������
		}
		else if (board[i][j] == t) //���ǵ�ǰ�µ�����ɫ��
		{
			Cont_i += 1;
		}

		if (Cont_i >= 5)        //���������������ڵ���5
		{
			return 1;        //����1,�ж�ʤ��
		}
	}

	Cont_i = 0;              //x���ж�δʤ��,��������������,����y���ж�

	//y = -x�ж�
	for (i = ContLimit(a - 4), j = ContLimit(b + 4); i <= ContLimit(a + 4) && j >= ContLimit(b - 4); i++, j--) //iֵ��Χ����a - 4������a + 4��,jֵ��Χ����b + 4������b - 4��
	{
		//i = a;

		if (board[i][j] != t) //�����ǵ�ǰ�µ�����ɫ��
		{
			Cont_i = 0;      //��������������
		}
		else if (board[i][j] == t) //���ǵ�ǰ�µ�����ɫ��
		{
			Cont_i += 1;
		}

		if (Cont_i >= 5)        //���������������ڵ���5
		{
			return 1;        //����1,�ж�ʤ��
		}
	}

	return 0;

}
int ContLimit(int n)       //�������ƶ�ά����a��b��ֵ �䷶Χ��1-15
{
	if (n > 16)               //���������ݴ���15
	{
		return 15;         //����15
	}
	else if (n < 0)           //����������С��0
	{
		return 0;          //����0
	}
	else                   //����������������,����ԭֵ
	{
		return n;
	}

	return n;
}
void Menu()
{
	//����ͼ�οⴴ��һ������
	initgraph(520, 460);

	//��ӱ���ͼƬ,����ǰ��L����ΪҪ����ʽ�ĳɶ��ֽ��ַ���
	loadimage(NULL, "bk2.jpg",520,460);
	settextcolor(BLACK);   //��������������Ϊ��ɫ
	setbkmode(0);
	settextstyle(50,30, "����");
	outtextxy(50, 50, "������");
	settextstyle(40, 25, "FRSCRIPT.TTF");
	outtextxy(40, 160, "PVP");
	outtextxy(40,240, "PVE");
	outtextxy(40, 320, "EVE");

	//settextstyle(12, 12, "mingliub.ttc");
	//settextcolor(RGB(255,0,0));
	//outtextxy(240, 150, "�ú�ѧϰ");
	//outtextxy(320, 150, "��������");
	//outtextxy(240, 180, "��������");
	//outtextxy(320, 180, "��ȡʤ��");

	
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
	//1.��һ������
	setlinecolor(BLACK);
	setfillcolor(pB->curColor);
	fillrectangle(pB->x, pB->y, pB->x + pB->w, pB->y + pB->h);
	//2.������
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	settextstyle(15, 0, "����");
	//3.�Զ�����
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