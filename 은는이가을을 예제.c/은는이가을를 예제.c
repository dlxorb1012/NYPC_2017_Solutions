


#include <stdio.h>
#include <locale.h> 
#include <string.h>
#include <wchar.h>

int a = 0; //���� ����

typedef struct namev
{
	wchar_t name[100][21];
	wchar_t value[100][101];
} NAV;

NAV nv;

//�Լ� ����
int PorS(char * a);
void givenjosa(wchar_t * a, wchar_t * b);

int main()
{
	int trash;
	int printnum = 0;
	int printcount[100];
	int printv;
	wchar_t bname[21];
	char fnctype[30];
	int fnc = 0;
	int n = 0;
	wchar_t str[500];
	wchar_t p_wd[30][30];
	wchar_t  p_snt[500];
	//wchar_t * token;
	_wsetlocale(LC_ALL, L"Korean");

	while (1)
	{
		// set player ���ؼ� set wand ������ print {player}�� {wand}�� ���ϰ� �մ� 
		//set player ������ set wand �ٳ��� print {player}�� {wand}�� �԰� �ִ�
		scanf_s("%s", fnctype, 10);


		fnc = PorS(fnctype);
		printv = n;
		if (fnc == 1)
		{
			_getws(p_snt);
			
			wchar_t * token = 1, ptr1[30], ptr2[30];
			wcscpy_s(str, 100, p_snt);

			while (token != NULL)
			{
				token = wcstok_s(str, L" ", &ptr1);
				while (token)
				{
					wcscpy_s(p_wd[n++], 30, token);
					token = wcstok_s(NULL, L" ", &ptr1);
					
				}

			}
			printcount[printnum] = n;
			printnum++;

			for (printv; printv <= n; printv++)
			{
				if (p_wd[printv][0] == L'{')
				{
					for (int j = 0; j < a; j++)
					{
						int same = 0;
						wchar_t * a;

						a = &p_wd[printv][1];

						int qw = wcslen(nv.name[j]);

						same = _wcsnicmp(a, nv.name[j], qw); //set �����̸���� { ���� ���� ��
						
						if (same == 0)
						{
							givenjosa(&p_wd[printv][0], nv.value[j]);

						}
					
					}

				}
			}
		}
	
		else if (fnc == 0)
		{

			wscanf_s(L"%s", bname, 21);

			for (int i = 0; i < a; i++)
			{
				if (_wcsicmp(bname, nv.name[i]) == 0)
				{
					wscanf_s(L"%s", nv.value[i], 101);
					goto X;
				}
			}
			wcscpy_s(nv.name[a], 25, bname);
			wscanf_s(L"%s", nv.value[a], 101);
			a++;
		X:
			trash = 0;
		
		}
		else if (fnc == 2)
		{
			break;
		}
	}

	
    int s = 0;

	for (int i = 0; i < printv; i++)
	{
		
		if (i == printcount[s])
			printf("\n");

		wprintf(L"%s ", p_wd[i]);
	}
	printf("\n");

	return 0;
}
	/* int j = wcslen(str);
	int a = (((str[j - 1] - 0xAC00) % 28) > 0) ? 0 : 1;
	if (a == 0)
		printf("��ħ ����\n");
	else
		printf("��ħ ����\n"); */
int PorS(char * a)
{
	if (*a == 's')
		return 0;
	else if (*a == 'p')
		return 1;
	else if (*a == 'e')
		return 2;
}

void givenjosa(wchar_t  * a ,wchar_t b[] ) // ���峻 �����̸� / �����̸��� �´� ������
{
	int dis = wcslen( a );
	
	int batchim = (((a[dis - 1] - 0xAC00) % 28) > 0) ? 0 : 1;
	
	if (a[dis - 1] == L'��' || a[dis - 1] == L'��')
	{
		wcscpy_s(a, wcslen(a), b);
		
		if (batchim == 0)
		{
			wcscat_s(a, wcslen(a) +3, L"��");
			return 0;
		}
		else
		{
			wcscat_s(a, wcslen(a)+3, L"��");
			return 0;
		}
	}
	else if (a[dis - 1] == L'��' || a[dis - 1] == L'��')
	{
		wcscpy_s(a, wcslen(a), b);

		if (batchim == 0)
		{
			wcscat_s(a, wcslen(a)+3, L"��");
			return 0;
		}
		else
		{
			wcscat_s(a, wcslen(a)+3, L"��");
			return 0;
		}
	}
	else if (a[dis - 1] == L'��' || a[dis - 1] == L'��')
	{
		wcscpy_s(a, wcslen(a), b);

		if (batchim == 0)
		{
			wcscat_s(a, wcslen(a)+3, L"��");
			return 0;
		}
		else
		{
			wcscat_s(a, wcslen(a)+3, L"��");
			return 0;
		}
	}
	
	
}