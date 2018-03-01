#include <stdio.h>
#include <stdlib.h>

#define YES "S_OK" // 설치 완료.
#define NO  "E_FAILED" // 설치 실패.
#define FIRE_D 25 // 캠프파이어끼리의 최단거리.
#define IGNORE -1 // 설치 실패한 요청 무효화.

struct xyz // (구조체) 모닥불의 x,y 위치, 설치한 시간 저장.
{
	short Xpos; // x위치.
	short Ypos; // y위치.
	short Time; // 설치한 시간.
};

int main()
{
	int k; // (변수) 설치할 모닥불의 개수.
	int x, y, t; // (변수) 입력한 모닥불의 x,y 위치, 시간.

	scanf_s("%d", &k); // (입력) 설치할 모닥불의 개수.
	
	struct xyz * fire_xyt = (struct xyz *)malloc(sizeof(struct xyz) * k); // 설치할 모닥불의 개수만큼 struct xyz형 메모리 할당.
	
	for (int i = 0; i < k; i++) // 각각 모닥불의 x,y위치, 설치한 시간 입력.
	{
		scanf_s("%d %d %d", &t, &y, &x); // (입력) 모닥불의 x,y위치, 설치한 시간.
		fire_xyt[i].Xpos = x;
		fire_xyt[i].Ypos = y;
		fire_xyt[i].Time = t;

	}

	for (int i = 0; i < k; i++) // "설치할 모닥불 위치(i)".
	{
		for (int j = 0; j < i; j++) // "설치할 모닥불(i)"의 x,y위치, 시간을 기준으로 "이전에 설치된 모닥불들(j)" 과 시간,거리 비교.
		{
			if ( ( ((fire_xyt[i].Time) - (fire_xyt[j].Time)) < 300) && (fire_xyt[j].Time != IGNORE) ) // 시간비교.
			{
				int xD = ((fire_xyt[i].Xpos) - (fire_xyt[j].Xpos));
				int yD = ((fire_xyt[i].Ypos) - (fire_xyt[j].Ypos));
				if ( ((xD * xD) + (yD * yD)) < FIRE_D) //위치 비교.
				{
					printf("%s\n", NO); // (설치 실패) "설치할 모닥불 위치(i)" 와 "이전에 설치된 모든 모닥불들(j)" 과 위치,시간 비교조건을 통과하지 못함.
					fire_xyt[i].Time = IGNORE; // 설치 실패한 요청 값을 무효화 하기위해 시간값으로 판단.
					goto exit;                                                                                                                      // 입구 []
				}
			// 비교대상 캠프파이어와 시간 차이가 300이상 or 대상 캠프파이어가 무효화 됨.
			}
			// 비교대상 캠프파이어 교체.
		}
		printf("%s\n", YES); // (설치 성공) "설치할 모닥불 위치(i)" 와 "이전에 설치된 모든 모닥불들(j)" 과 위치,시간 비교조건을 통과함.
	
	exit:                                                                                                                                           // 출구 []
		continue; 

	}
	free(fire_xyt);

	return 0;
}