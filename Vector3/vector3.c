#include <stdio.h>
#include <Windows.h>
#define X 82
#define Y 22
int left = 0, right = 0;
int up = 0, down = 0;

typedef struct pos
{
	int x;
	int y;
	int z;
}pos;

void CSgotoxy(int _X, int _Y);
int IsKeyDown(int Key);
int get_x_h(pos pos1, pos pos2, pos u_pos);
int get_y_h(pos pos1, pos pos2, pos u_pos);
void drawline(pos pos1, pos pos2);

UINT __stdcall Thread(void *arg)
{
	while (1)
	{
		if (IsKeyDown(VK_LEFT))
			left = 1;
		if (IsKeyDown(VK_RIGHT))
			right = 1;
		if (IsKeyDown(VK_UP))
			up = 1;
		if (IsKeyDown(VK_DOWN))
			down = 1;
	}
} //¶ò·¹µå

int main() {
	int x_o = 5;
	int y_o = x_o / 4;
	pos front[2] = { { X - x_o, Y + y_o },{ X + x_o, Y + y_o } };
	pos back[2] = { { X - x_o, Y - y_o },{ X + x_o, Y - y_o } };
	int u_xpos = (front[0].x + front[1].x) / 2;
	int u_ypos = (front[0].y + front[1].y) / 2;
	pos z = { u_xpos, u_ypos, 30 };
	_beginthreadex(NULL, 0, Thread, 0, 0, NULL);
	pos fro = { u_xpos, front[0].y };
	pos bac = { u_xpos, back[0].y };
	pos a = { back[0].y, back[0].x };
	pos b = { back[1].y, back[1].x };
	pos p1, p2;


	while (1) {
		if ((z.x > 147 && IsKeyDown(VK_LEFT)) || (z.x <= 19 && IsKeyDown(VK_RIGHT)) || (z.y <= 5 && IsKeyDown(VK_DOWN)) || (z.y >= 41 && IsKeyDown(VK_UP)))// || z.x < 19 || z.y > 41 || z.y < 5)
		{
			left = 0;
			right = 0;
			up = 0;
			down = 0;
			continue;
		}
		if (left != 0 || right != 0)
		{

			int move = (left != 0) ? 1 : -1;
			z.x += move;
			for (int i = 0; i < 2; i++)
			{
				front[i].x += move;
				back[i].x += move;
			}
			system("cls");
			int xh = get_x_h(fro, bac, z);
			int yh = get_y_h(a, b, z);
			
			for (int i = 0; i < 2; i++)
			{
				p1.x = front[i].x + xh;
				p1.y = front[i].y + yh - (y_o * 2);
				p2.x = back[i].x;
				p2.y = back[i].y;
				drawline(p1, p2);
				p1.y = front[i].y + x_o + yh - (y_o * 2);
				p2.y = back[i].y + x_o;
				drawline(p1, p2);
			}
			left = 0;
			right = 0;

		}
		else if (up != 0 || down != 0)
		{
			int move = (up != 0) ? 1 : -1;
			z.y += move;
			for (int i = 0; i < 2; i++)
			{
				front[i].y += move;
				back[i].y += move;
			}
			system("cls");
			int xh = get_x_h(fro, bac, z);
			int yh = get_y_h(a, b, z);
		
			for (int i = 0; i < 2; i++)
			{
				p1.x = front[i].x + xh;
				p1.y = front[i].y + yh - (y_o * 2);
				p2.x = back[i].x;
				p2.y = back[i].y;
				drawline(p1, p2);
				p1.y = front[i].y + x_o + yh - (y_o * 2);
				p2.y = back[i].y + x_o;
				drawline(p1, p2);
			}

			up = 0;
			down = 0;
		}


	}
	return 0;
}

void CSgotoxy(int _X, int _Y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD initial = { _X,_Y };
	SetConsoleCursorPosition(hOut, initial);
}

int IsKeyDown(int Key)
{
	return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}

int get_x_h(pos pos1, pos pos2, pos u_pos)
{
	double m = ((double)(pos2.y - u_pos.z) / (double)(pos2.x - u_pos.x));
	int x, y = pos1.y;
	x = ((y - pos2.y) / m) + pos2.x;//y = (m * (x - pos1.x)) + pos1.y;
	int h = x - pos1.x;
	return h;
}

int get_y_h(pos pos1, pos pos2, pos u_pos)
{
	double m = ((double)(pos2.y - u_pos.z) / (double)(pos2.x - u_pos.y));
	int x, y = pos1.y;
	x = ((y - pos2.y) / m) + pos2.x;//y = (m * (x - pos1.x)) + pos1.y;
	int h = x - pos1.x;
	return h;
}

void drawline(pos pos1, pos pos2)
{
	double m = ((double)(pos1.y - pos2.y) / (double)(pos1.x - pos2.x));
	int min = (pos1.y > pos2.y) ? pos2.y : pos1.y;
	int max = (pos1.y > pos2.y) ? pos1.y : pos2.y;
	int x, y;
	for (y = min; y <= max; y++)
	{
		x = ((y - pos1.y) / m) + pos1.x + 0.5;//y = (m * (x - pos1.x)) + pos1.y;
		if (x > 170 || x < 0 || y < 0 || y > 48)
			continue;
		CSgotoxy(x, y);
		printf("*");

	}
	if (max - min <= 3)
	{
		int min = (pos1.x > pos2.x) ? pos2.x : pos1.x;
		int max = (pos1.x > pos2.x) ? pos1.x : pos2.x;
		for (x = min; x <= max; x++)
		{
			y = (m * (x - pos1.x)) + pos1.y + 0.5;
			if (x > 170 || x < 0 || y < 0 || y > 48)
				continue;
			CSgotoxy(x, y);
			printf("*");
		}
	}
}