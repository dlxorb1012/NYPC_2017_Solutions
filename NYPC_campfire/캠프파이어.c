#include <stdio.h>
#include <stdlib.h>

#define YES "S_OK" // ��ġ �Ϸ�.
#define NO  "E_FAILED" // ��ġ ����.
#define FIRE_D 25 // ķ�����̾���� �ִܰŸ�.
#define IGNORE -1 // ��ġ ������ ��û ��ȿȭ.

struct xyz // (����ü) ��ں��� x,y ��ġ, ��ġ�� �ð� ����.
{
	short Xpos; // x��ġ.
	short Ypos; // y��ġ.
	short Time; // ��ġ�� �ð�.
};

int main()
{
	int k; // (����) ��ġ�� ��ں��� ����.
	int x, y, t; // (����) �Է��� ��ں��� x,y ��ġ, �ð�.

	scanf_s("%d", &k); // (�Է�) ��ġ�� ��ں��� ����.
	
	struct xyz * fire_xyt = (struct xyz *)malloc(sizeof(struct xyz) * k); // ��ġ�� ��ں��� ������ŭ struct xyz�� �޸� �Ҵ�.
	
	for (int i = 0; i < k; i++) // ���� ��ں��� x,y��ġ, ��ġ�� �ð� �Է�.
	{
		scanf_s("%d %d %d", &t, &y, &x); // (�Է�) ��ں��� x,y��ġ, ��ġ�� �ð�.
		fire_xyt[i].Xpos = x;
		fire_xyt[i].Ypos = y;
		fire_xyt[i].Time = t;

	}

	for (int i = 0; i < k; i++) // "��ġ�� ��ں� ��ġ(i)".
	{
		for (int j = 0; j < i; j++) // "��ġ�� ��ں�(i)"�� x,y��ġ, �ð��� �������� "������ ��ġ�� ��ںҵ�(j)" �� �ð�,�Ÿ� ��.
		{
			if ( ( ((fire_xyt[i].Time) - (fire_xyt[j].Time)) < 300) && (fire_xyt[j].Time != IGNORE) ) // �ð���.
			{
				int xD = ((fire_xyt[i].Xpos) - (fire_xyt[j].Xpos));
				int yD = ((fire_xyt[i].Ypos) - (fire_xyt[j].Ypos));
				if ( ((xD * xD) + (yD * yD)) < FIRE_D) //��ġ ��.
				{
					printf("%s\n", NO); // (��ġ ����) "��ġ�� ��ں� ��ġ(i)" �� "������ ��ġ�� ��� ��ںҵ�(j)" �� ��ġ,�ð� �������� ������� ����.
					fire_xyt[i].Time = IGNORE; // ��ġ ������ ��û ���� ��ȿȭ �ϱ����� �ð������� �Ǵ�.
					goto exit;                                                                                                                      // �Ա� []
				}
			// �񱳴�� ķ�����̾�� �ð� ���̰� 300�̻� or ��� ķ�����̾ ��ȿȭ ��.
			}
			// �񱳴�� ķ�����̾� ��ü.
		}
		printf("%s\n", YES); // (��ġ ����) "��ġ�� ��ں� ��ġ(i)" �� "������ ��ġ�� ��� ��ںҵ�(j)" �� ��ġ,�ð� �������� �����.
	
	exit:                                                                                                                                           // �ⱸ []
		continue; 

	}
	free(fire_xyt);

	return 0;
}