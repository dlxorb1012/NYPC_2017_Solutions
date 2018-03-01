
#include <stdio.h>
#include <windows.h>

void CSgotoxy(int X, int Y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD initial = { X,Y };

	SetConsoleCursorPosition(hOut, initial);

}

int main()
{
	CONSOLE_CURSOR_INFO CurInfo;


	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo); //CurInfo에 저장된 커서모드를 표시한다


	DWORD  dw, dwmode;
	INPUT_RECORD rec;
	COORD demp;

	printf("                            _                __               _                  _                    __                  \n");
	printf("                           /  /＼             /  / ＼            /  /＼               /  /＼                 /  / ＼                \n");
	printf("                          /  /: :＼          /  /: 😐           /  /: :＼            /  / 😕                /  / : :＼              \n");
	printf("                         /__/:/＼: ＼       /  /: |:|          /  /: /＼:＼         /  / 😕                /  / : /＼:＼            \n");
	printf("                      __＼_＼:＼ ＼:＼    /  /: /|:|_       /  /:: ＼ ＼:＼      /  / ::＼________      /  / :  ＼ ＼:＼          \n");
	printf("                     /___/＼  ＼:＼ ＼:＼ /__/ 😕 |:| /＼    /__/: /＼:＼_＼:＼   /  / :/＼    :::::＼   /__/ : /＼:＼ ＼:＼        \n");
	printf("                     ＼  ＼:＼  ＼:＼_＼/ ＼_＼/  |:|/ 😕    ＼_＼/   ＼:＼/: /  /__/ :/~~| :|~~~~~~~~   ＼  ＼:＼ ＼:＼_＼/        \n");
	printf("                       ＼  ＼:＼__＼:＼       |   |:/ 😕           ＼___＼:: /   ＼_＼/   | 😐             ＼  ＼:＼ ＼:＼          \n");
	printf("                         ＼  ＼:＼ /:/        |___|: 😕             /   / : /         |   | 😐               ＼  ＼:＼_＼/          \n");
	printf("                           ＼  ＼ ::/         /__/ : /             /___/  😕          |___| 😐                 ＼  ＼:＼            \n");
	printf("                             ＼__＼/          ＼_＼_/              ＼___＼/            ＼__＼|                   ＼__＼/            \n");

	CSgotoxy(55, 15);
	printf("┌──────────────┐");
	CSgotoxy(55, 16);
	printf("│          게임시작          │");
	CSgotoxy(55, 17);
	printf("└──────────────┘");

	CSgotoxy(55, 19);
	printf("┌──────────────┐");
	CSgotoxy(55, 20);
	printf("│          환경설정          │");
	CSgotoxy(55, 21);
	printf("└──────────────┘");


	CSgotoxy(55, 23);
	printf("┌──────────────┐");
	CSgotoxy(55, 24);
	printf("│          게임종료          │");
	CSgotoxy(55, 25);
	printf("└──────────────┘");


	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &dwmode) | ENABLE_MOUSE_INPUT);

	while (1)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dw);
		if (rec.EventType == MOUSE_EVENT)
		{
			if ((rec.Event.MouseEvent.dwMousePosition.X > 55 && rec.Event.MouseEvent.dwMousePosition.X < 86) && (rec.Event.MouseEvent.dwMousePosition.Y > 14 && rec.Event.MouseEvent.dwMousePosition.Y < 18))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				CSgotoxy(55, 15);
				printf("┌──────────────┐  ");
				CSgotoxy(55, 16);
				printf("│          게임시작          │  ");
				CSgotoxy(55, 17);
				printf("└──────────────┘  ");

				CSgotoxy(55, 34);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				CSgotoxy(55, 15);
				printf("┌──────────────┐  ");
				CSgotoxy(55, 16);
				printf("│          게임시작          │  ");
				CSgotoxy(55, 17);
				printf("└──────────────┘  ");

				CSgotoxy(55, 34);

			}



			if ((rec.Event.MouseEvent.dwMousePosition.X > 55 && rec.Event.MouseEvent.dwMousePosition.X < 86) && (rec.Event.MouseEvent.dwMousePosition.Y > 18 && rec.Event.MouseEvent.dwMousePosition.Y < 22))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				CSgotoxy(55, 19);
				printf("┌──────────────┐  ");
				CSgotoxy(55, 20);
				printf("│          환경설정          │  ");
				CSgotoxy(55, 21);
				printf("└──────────────┘  ");

				CSgotoxy(55, 34);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				CSgotoxy(55, 19);
				printf("┌──────────────┐  ");
				CSgotoxy(55, 20);
				printf("│          환경설정          │  ");
				CSgotoxy(55, 21);
				printf("└──────────────┘  ");

				CSgotoxy(55, 34);

			}





			if ((rec.Event.MouseEvent.dwMousePosition.X > 55 && rec.Event.MouseEvent.dwMousePosition.X < 86) && (rec.Event.MouseEvent.dwMousePosition.Y > 22 && rec.Event.MouseEvent.dwMousePosition.Y < 26))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				CSgotoxy(55, 23);
				printf("┌──────────────┐  ");
				CSgotoxy(55, 24);
				printf("│          게임종료          │  ");
				CSgotoxy(55, 25);
				printf("└──────────────┘  ");

				CSgotoxy(55, 34);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				CSgotoxy(55, 23);
				printf("┌──────────────┐  ");
				CSgotoxy(55, 24);
				printf("│          게임종료          │  ");
				CSgotoxy(55, 25);
				printf("└──────────────┘  ");

				CSgotoxy(55, 34);

			}


		}


	}


	return 0;
}


/* #include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <process.h>
#include <math.h>
#include <time.h>

typedef struct snake
{
	int x;
	int y;

}snake_struct;

snake_struct body[150] = { { 50,15 },{ 50,14 },{ 50,23 } };
snake_struct item = { 0,0 };
enum { UP, DOWN, LEFT, RIGHT };
int way = 0, score = 0, snake_tail = 2, speed = 100, sp = 1, speed_g = 1;
double result = 0;
int IsKeyDown(int Key);
void CSgotoxy(int X, int Y);

void  draw_background(); // 배경그리기.
void changeItem_pos(); // 아이템 위치갱신. 
void get_tail(); // 꼬리 위치갱신.
void moveSnake(); // 뱀 이동.
void draw_snake_item(); // 뱀,아이템 출력
void draw_scoreboard();
void change_speed();
void change_score();
void draw_title();
void game_end();

UINT __stdcall Thread(void *arg)
{
	while (1)
	{
		clock_t before;
		before = clock();
		if (way == UP || way == DOWN)
		{
			if (IsKeyDown(VK_LEFT))
				way = LEFT;
			if (IsKeyDown(VK_RIGHT))
				way = RIGHT;
		}
		else if (way == RIGHT || way == LEFT)
		{
			if (IsKeyDown(VK_UP))
				way = UP;
			if (IsKeyDown(VK_DOWN))
				way = DOWN;
		}
		result += (double)(clock() - before) / CLOCKS_PER_SEC;
	}
}

int main(void)
{

	draw_background();
	Sleep(500);
	draw_scoreboard();
	Sleep(500);
    changeItem_pos();
	Sleep(500);
	draw_title();
	_beginthreadex(NULL, 0, Thread, 0, 0, NULL);

	while (1)
	{
		change_speed();
		change_score();
		get_tail();
		moveSnake();
		
		if (body[0].x == 0 || body[0].x == 98 || body[0].y == 0 || body[0].y == 29) // 벽에 부딫혓을때.
			game_end();

		for (int i = 1; i < snake_tail; i++) // 몸과몸
			if (body[0].x == body[i].x && body[0].y == body[i].y)
				game_end();

		if (body[0].x == item.x && body[0].y == item.y) // 아이템 먹엇을때.
		{
			body[snake_tail + 1].x = body[snake_tail].x;
			body[snake_tail + 1].y = body[snake_tail].y;
			score += (int)result / 10 * 100 + 100;
			changeItem_pos();
		}

		draw_snake_item();
		Sleep(speed);
	}



	return 0;
}

void  draw_background()
{
	system("color 0F");
	system("mode con: cols=163 lines=37");
	system("title 뱀 게임^^^^7");
	_beginthreadex(NULL, 0, Thread, 0, 0, NULL);



	CONSOLE_CURSOR_INFO CurInfo;


	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 << 4);
	CSgotoxy(0, 0);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	for (int i = 1; i < 29; i++)
	{
		CSgotoxy(0, i);
		printf("■                                                                                                ■");
	}
	CSgotoxy(0, 29);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}

void draw_scoreboard()
{
	CSgotoxy(105, 10);
	printf("┌──────────ScoreBoard──────────┐");
	CSgotoxy(105, 29);
	printf("└─────────────────────────┘");
	for (int i = 11; i < 29; i++)
	{
		CSgotoxy(105, i);
		printf("│                                                  │");
	} 
	CSgotoxy(105, 17);
	printf("├─────────────────────────┤");
	CSgotoxy(109, 13);
	printf("TIME  : ");
	CSgotoxy(109, 15);
	printf("SCORE : ");
	CSgotoxy(109, 19);
	printf("SPEED : ");
}

void change_score()
{
	CSgotoxy(116, 13);
	printf("%f", result);
	CSgotoxy(116, 15);
	printf("%d", score);
	CSgotoxy(116, 19);
	printf("%d", (100 - speed) + 10);
	for (int i = 0; i <= speed_g; i+=2)
	{
		CSgotoxy(i + 109, 21);
		printf("◆");
	}
}

void draw_title()
{
		CSgotoxy(108, 2);
		printf(" ######   ##    ##     ###     ##    ##  ########  ");
		CSgotoxy(108, 3);
		printf("##    ##  ###   ##    ## ##    ##   ##   ##        ");
		CSgotoxy(108, 4);
		printf("##        ####  ##   ##   ##   ##  ##    ##        ");
		CSgotoxy(108, 5);
		printf(" ######   ## ## ##  ##     ##  #####     ######    ");
		CSgotoxy(108, 6);
		printf("      ##  ##  ####  #########  ##  ##    ##        ");
		CSgotoxy(108, 7);
		printf("##    ##  ##   ###  ##     ##  ##   ##   ##        ");
		CSgotoxy(108, 8);
		printf(" ######   ##    ##  ##     ##  ##    ##  ########  ");
}
void changeItem_pos()
{

	item.x = ((rand() % 48) + 1) * 2;
	item.y = ((rand() % 12) + 1) * 2;
}

int IsKeyDown(int Key)
{
	return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}

void CSgotoxy(int X, int Y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD initial = { X,Y };

	SetConsoleCursorPosition(hOut, initial);

}

void get_tail()
{
	for(snake_tail = 0; snake_tail < 150; snake_tail++)
	{
		if (body[snake_tail].x == '\0')
		{
			snake_tail--;
			break;
		}
	}
}

void draw_snake_item()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 << 4);

	CSgotoxy(body[0].x, body[0].y);
	printf("●");

	for (int i = 1; i <= snake_tail; i++)
	{
		CSgotoxy(body[i].x, body[i].y);
		printf("○");
	}
	CSgotoxy(item.x, item.y);
	printf("★");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void moveSnake()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 << 4);

	CSgotoxy(body[snake_tail].x, body[snake_tail].y);
	printf(" ");

	for (int i = snake_tail; i > 0; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}

	switch (way)
	{
	case UP:
		body[0].y--;
		break;

	case DOWN:
		body[0].y++;
		break;

	case LEFT:
		body[0].x -= 2;
		break;

	case RIGHT:
		body[0].x += 2;
		break;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void change_speed ()
{
	if ((int)result % 10 == 0)
	{
		if (sp == 0)
		{
			if (speed > 10)
			{
				speed -= 7;
				speed_g+=2;
				sp = 1;
			}
		}
	}
	else
	{
		sp = 0;
	}
}

void game_end()
{

	CSgotoxy(1, 31);
	exit(0);
}
*/







/* #include <stdio.h>
#define ANSWER 1974
//숫자야구
int main()
{
	int strike, ball;
	int num = 1;
	int playerA;
	while (1)
	{
		
		printf("%d번쨰 입력 : ",num);
		scanf("%d", &playerA);
		if (playerA < 1000)
		{
			printf("4자리 숫자를 입력해주세요");
			continue;
		}
		if (ANSWER / 1000 == playerA / 1000)
		{

		}
			


	}
}


*/





































/* #include <stdio.h>

int monthCal(int mon, int dayday, int zmon, int zday);

int main()
{
	int clean = 0;
	int zday = 1;
	int mon = 0, day = 0, yol = 0;
	int tm = 0, td = 0, ty = 0;
	int sum = 0;
	int timeP = 0;
	int Tz = 0, Tn = 0;
	
	//한번 걸리면 500원 
	//2일후에 100원씩 추가
	//1주일 지나면 청소
	
		printf("오늘 날짜를 입력하세요\n");
		while(1)
		{

		scanf_s("%d %d", &tm, &td);
		if (tm < 1 || tm >12 || td < 1 || td > 31)
			printf("잘못 입력. 다시 입력 해 주세요\n");
		else
			break;
	    }
		printf("\n");
	printf("1.월, 2.화, 3.수, 4.목, 5.금\n");
	printf("지각한 날짜와 요일을 입력하세요 ex)7월 30일 월요일 = 7 30 1 \n");
	printf("\n");

	while (1)
	{
		int a = 6;	
		printf("%d번째 지각한 날짜 (종료하려면 0을 입력하세요)\n", zday);
		scanf_s("%d", &mon);
		if (mon == 0)
		break;

		scanf_s("%d %d",&day, &yol);

		if (day > 31 || day < 1 || yol > 5 || yol < 1)
		{
			printf("잘못 입력. 다시 입력 해 주세요.");
			continue;
		}
		
		else
		{
			int weekend = 0;
			sum += 500;
			if (mon == tm)
				timeP = (td - day);
			else
				timeP = monthCal(mon, day, tm, td);
			for (int i = 0; i <= timeP; i++)
			{
				if (i + yol == a)
				{
					weekend++;
				}
				else if (i + yol == a + 1)
				{
					weekend++;
					a = a * 2;

				}
				else if ( (i - weekend) >= 2)
				{
					sum += 100;

				}

			}
		}
		zday++;
		if (timeP >= 7)
			clean = 1;
	}
		printf("지각비: %d\n", sum);
		if (clean == 1)
			printf("1주일 지남!! 청소입니다.\n");
	return 0;
}

int monthCal(int mon, int dayday, int zmon, int zday )
{
	if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
		return ((zmon * 31 + zday) - (mon * 31 + dayday));

	else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
		return ((zmon * 30 + zday) - (mon * 30 + dayday));
	else if (mon == 2)
		return ((zmon * 28 + zday) - (mon * 28 + dayday));

	
}


*/

/* #include <stdio.h>
#include <math.h>
int Fsp, Asp, Bsp, j, i = 1;
double Thit, Thtime, Fmove, ATpos, BTpos, Fpos = 0;
void Fly_Train(double Tpos, int Tsp);
void FFlyhit(void);

int main()
{
	int T, c[10] = { 0 };
	double t[10] = { 0 };
	scanf_s("%d", &T);
	for (int a = 0; a < T; a++)
	{
		scanf_s("%lf %lf", &ATpos, &BTpos);
		scanf_s("%d %d %d", &Asp, &Bsp, &Fsp);
		FFlyhit();
		t[a] = Fmove;
		c[a] = j;
		Fmove = 0;
		j = 0;
		Fpos = 0;

	}
	for (int a = 0; a < T; a++)
	{
		printf("%d\n", c[a]);
		printf("%f\n", t[a]);
	}
	return 0;
}

void Fly_Train(double Tpos, int Tsp)
{
	double time, FTpos, FtoT;
	int  FTsp;
	FtoT = fabs(Tpos) + fabs(Fpos);
	FTsp = (i == 1 || i == 2) ? Fsp + Tsp : Tsp - Fsp;
	time = FtoT / FTsp;
	Fmove += (time * Fsp);

	if (Tsp < Fsp)
		if (i == 2)
		{
			Fmove = Thtime * Fsp;
			j = 3;
		}
		else
		{
			i = 2;
			FTpos = ATpos + Asp * time;
			Fpos = Fpos + (time * Fsp);
			Fly_Train(FTpos, Asp);
		}
	else if (i == 0)
	{
		Fpos = ATpos + (time * Asp);
		Fmove += Thit < Fpos ? fabs(Fpos - Thit) : fabs(Thit - Fpos);
	}
	else
		j = 3;

}

void FFlyhit(void)
{

	Thtime = (BTpos - ATpos) / (Asp + Bsp);
	Thit = (Thtime * Asp) + ATpos;
	double Fhit = (Thtime * Fsp);

	if (Thit < Fhit)
	{
		j = 2;
		Fly_Train(BTpos, Bsp);

	}
	else if (Thit > Fhit)
	{
		i = 0;
		j = 1;
		Fly_Train(ATpos, Asp);
	}
	else
	{
		Fmove = Thtime * Fsp;
		j = 3;
	}

} */