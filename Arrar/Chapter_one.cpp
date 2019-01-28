#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"base.h"
//�������ݽṹ ��һ��ϰ��

//�ڶ����� ��һС��
int func_2_1()
{
	struct Arr L;
	init_arr(&L,10);
	if (0 == L.cnt)
	{
		printf("˳���Ϊ��");
		return 0;
	}
	int min=L.pBase[0];
	for(int i=0;i<L.cnt;++i)
	{
		if (L.pBase[i] < L.pBase[0])
			if (L.pBase[i]<min)
				min = i;
	}
	printf("��СֵΪ��%d\n",L.pBase[min]);
	show_arr(&L);
	printf("ɾ����Сֵ�������һ��ֵ����\n");
	L.pBase[min] = L.pBase[L.cnt-1];
	show_arr(&L);

}



//�ڶ����� �ڶ�С��
//������Ԫ������
int func_2_2()
{
	struct Arr L;
	init_arr(&L,10);
	show_arr(&L);

	printf("\n�� if ��������\n");
	for(int i=0;i<(L.cnt/2);++i)
	{
		int t;
		t = L.pBase[i];
		L.pBase[i] = L.pBase[L.cnt-i-1];
		L.pBase[L.cnt-i-1] = t;
	}

	show_arr(&L);

	printf("\n�� while ��������\n");
	int p = 0;
	int q = L.cnt-1;
	while (p<q)
	{
		int t;
		t = L.pBase[p];
		L.pBase[p] = L.pBase[q];
		L.pBase[q] = t;
		p++;
		q--;
	}
	show_arr(&L);


	return 0;

}


//�ڶ����� ����С��
//ɾ�����Ա�������ֵΪx�ĵ�Ԫ��

void func_2_3(int x)
{
	struct Arr L;
	init_arr(&L,10);
	show_arr(&L);
	int q;
	for (int i=0;i<L.cnt;++i)
		if (L.pBase[i] == x)
		{
			delete_arr(&L,i+1,&q);
			i--;
		}
	show_arr(&L);
}


//�ڶ����� ����С��
int func_2_4(int s,int t)
{
	int q;
	if (s>=t)
	{
		printf("s,t �����ֵ��������\n");
		return 0;
	}
	struct Arr L;
	init_arr(&L,10);
	if (is_empty(&L))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	show_arr(&L);
	for (int i=0;i<L.cnt;i++)
		if (L.pBase[i]>s && L.pBase[i]<t)
		{	
			delete_arr(&L,i+1,&q);
			i--;
		}
	show_arr(&L);
	return 0;
}

//�ڶ����� ����С��

int func_2_5(int s,int t)
{
	int q;
	if (s>=t)
	{
		printf("s,t �����ֵ��������\n");
		return 0;
	}
	struct Arr L;
	init_arr(&L,10);
	if (is_empty(&L))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	show_arr(&L);
	for (int i=0;i<L.cnt;i++)
		if (L.pBase[i]>=s && L.pBase[i]<=t)
		{	
			delete_arr(&L,i+1,&q);
			i--;
		}
	show_arr(&L);
	return 0;
}



//�ڶ��������С��
//ɾ���ظ���ֵ
int func_2_6()
{
	struct Arr L;
	init_arr(&L,10);
	if (is_empty(&L))
	{
		printf("����Ϊ��\n");
		return 0;	
	}
	show_arr(&L);
	for (int i=0;i<L.cnt;i++)
		for (int j=i+1;j<L.cnt;j++)
		{
			if (L.pBase[i] == L.pBase[j])
			{
				int q;
				delete_arr(&L,j+1,&q);
				j--;
			}
		}
	show_arr(&L);
	return 0;
}

//�ڶ����� ����С��
//�ϲ���������,�����ؽ������

int * func_2_7()
{
	struct Arr L,M;
	init_arr(&L,20);
	init_arr(&M,10);
	if (is_empty(&L)||is_empty(&M))
	{
		printf("����Ϊ��\n");
		return 0;	
	}
	show_arr(&L);
	show_arr(&M);
	for(int i=0;i<M.cnt;i++)
		append_arr(&L,M.pBase[i]);
	show_arr(&L);
	return L.pBase;
}



//�ڶ����� �ڰ�С��
int func_2_8()
{
	struct Arr L,M;
	init_arr(&L,10);
	init_arr(&M,10);
	L.pBase[5] = 11;
	L.pBase[6] = 12;
	L.pBase[7] = 13;
	L.pBase[8] = 14;
	L.pBase[9] = 15;
	L.cnt = 10;
	printf("ԭʼL��ֵ��\n");
	show_arr(&L);
	//�������M���ֵ
	printf("���M֮ǰ��ֵ��\n");
	show_arr(&M);
	for(int i=0;i<5;i++)
	{
		int x;
		delete_arr(&M,1,&x);
	}
	show_arr(&M);

	//��ʼ
	show_arr(&L);
	for(int i=0;i<5;i++)
	{
		//ʵ���ϲ���Ҫ����M��ֻ��Ҫһ����ʱ������ŵ�t����
		int t;
		t = L.pBase[i];
		L.pBase[i] = L.pBase[i+5];
		L.pBase[i+5] = t;
	}
	free(M.pBase);
	show_arr(&L);
	return 0;
}


//�ڶ����� ��9С��

int func_2_9(int x)
{
	struct Arr L;
	init_arr(&L,15);
	show_arr(&L);
	int t = L.cnt;
	for(int i=0;i<t;i++)
	{
		int x;
		delete_arr(&L,1,&x);
	}
	show_arr(&L);
	for (int i=0;i<5;i++)
		append_arr(&L,i+3); 
	append_arr(&L,10);
	show_arr(&L);
	printf("\n\n\n\n");
	//��ʼ
	for(int i=0;i<L.cnt;i++)
	{
		if(x == L.pBase[i])
		{
			int t;
			t = L.pBase[i];
			L.pBase[i] = L.pBase[i+1];
			L.pBase[i+1] = t;
			printf("���ҵ���ͬԪ�أ�������滻\n");
			show_arr(&L);
			return 0;
		}

	}
	if (x <L.pBase[0])
	{
		insert_arr(&L,1,x);
		printf("δ��������ƥ�䵽��ͬԪ�أ��Ѳ��뵽��λ\n");
		show_arr(&L);
		return 0;
	}
	
	if (x>L.pBase[L.cnt-1])
	{
		append_arr(&L,x);
		printf("δ��������ƥ�䵽��ͬԪ�أ��Ѳ��뵽ĩλ\n");
		show_arr(&L);
		return 0;
	}
	for(int j=0;j<L.cnt;j++)
	{	
		if(x>L.pBase[j]&&x<L.pBase[j+1])
		{
			insert_arr(&L,j+2,x);
			printf("δ��������ƥ�䵽��ͬԪ�أ��Ѳ��뵽����\n");
			show_arr(&L);
			return 0;
		}
	}

	return 0;
}

//�ڶ����� ��10����
 int func_2_10()
 {
	 //��ʼ������׼��
	 struct Arr L,M;
	 init_arr(&L,10);
	 init_arr(&M,10);

	 for(int i=11;i<16;i++)
	 {
		 L.pBase[i-6] =i;
		 L.cnt++;
	 }
	 int previous = M.cnt;
	 for(int i=0;i<previous;i++)
	 {
		 int x;
		 delete_arr(&M,1,&x);
	 }
	 show_arr(&M);
	 system("cls");
	 //��ʼ
	 printf("��������Ҫѭ�����Ƶ�����λ���� ");
	 int p=input();
	 for(int i=0;i<p;i++)
	 {
		 insert_arr(&M,i+1,L.pBase[i]);
	 }
	 system("cls");
	 printf("��ʼѭ������%d��λ��\n\n",p);
	 printf("ԭʼ���飺 \n");
	 show_arr(&L);
	 printf("\r\n");
	 for(int i=0;i<L.cnt-p;i++)
	 {
		 L.pBase[i] = L.pBase[p+i]; 
	 }
	 //show_arr(&L);
	 printf("�仯������飺\n");
	 for(int i=0;i<p;i++)
	 {
		 L.pBase[L.cnt-p+i] = M.pBase[i];
	 }
	 show_arr(&L);
	 return 0;
}


//�ڶ����� ��11С��
 int func_2_11()
 {
	 //׼������ ��ʼ������S1 S2
	 struct Arr S1,S2,L;
	 init_arr(&S1,10);
	 init_arr(&S2,10);
	 init_arr(&L,10);
	 clear_arr(&S1);
	 clear_arr(&S2);
	 clear_arr(&L);
	 S1.pBase[0]=11;
	 S1.pBase[1]=13;
	 S1.pBase[2]=15;
	 S1.pBase[3]=17;
	 S1.pBase[4]=19;
	 S1.cnt = 5;
	 S2.pBase[0]=2;
	 S2.pBase[1]=4;
	 S2.pBase[2]=6;
	 S2.pBase[3]=8;
	 S2.pBase[4]=20;
	 S2.cnt = 5;
	 printf("ԭʼ���ݣ�\n");
	 show_arr(&S1);show_arr(&S2);
	 printf("\n");

	 //��ʼ
	 //����������ϲ�
	 for(int i=0;i<S1.cnt;i++)
		 insert_arr(&L,i+1,S1.pBase[i]);
	 for(int i=0;i<S2.cnt;i++)
		 insert_arr(&L,S1.cnt+1+i,S2.pBase[i]);
	 //show_arr(&L);
	 //ð������
	 for(int i=0;i<L.cnt;i++)
		 for(int j=i;j<L.cnt;j++)
			if (L.pBase[j]<L.pBase[i])
			 {
				 int t;
				 t=L.pBase[i];
				 L.pBase[i] = L.pBase[j];
				 L.pBase[j] =t;			 
			 }
	 //ȡ��λ��
	show_arr(&L);
	int median =L.cnt/2;
	printf("��λ���ǣ�%d\n",L.pBase[median-1]);

	 return 0;
 }

 
 //�ڶ����� ��12 С��
 int func_2_12()
 {
	 //����׼��
	 struct Arr L;
	 init_arr(&L,10);
	 int A[]={0,5,2,3,5,7,5,5,5};
	 for (int i=0;i<sizeof(A)/sizeof(A[0]);i++)
	 {
		 L.pBase[i] = A[i];
		 L.cnt++;
	 }
	 //show_arr(&L);
	 //��ʼ
	 int count;
	 int main_element;
	 for(int i=0;i<L.cnt;i++)
		 {
			 count =1;
			 for(int j=i+1;j<L.cnt;j++)
			{
			 
			 if (L.pBase[i]==L.pBase[j])
				 count++;
			}
			 if (count>L.cnt/2)
			 {
				 show_arr(&L);

				 main_element = L.pBase[i];
				 break;
			 }
	     }
	 
	 if(count >L.cnt/2)
	 { 
		 printf("��ͬԪ�ظ���count: %d\n",count);
		 printf("���������Ԫ��Ϊ��%d\n",main_element);
		 return main_element;
	 }
	 else
		{
			printf("-1\n");
			return 0;
	     }
 }