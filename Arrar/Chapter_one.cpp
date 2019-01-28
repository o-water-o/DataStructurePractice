#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"base.h"
//王道数据结构 第一章习题

//第二大题 第一小题
int func_2_1()
{
	struct Arr L;
	init_arr(&L,10);
	if (0 == L.cnt)
	{
		printf("顺序表为空");
		return 0;
	}
	int min=L.pBase[0];
	for(int i=0;i<L.cnt;++i)
	{
		if (L.pBase[i] < L.pBase[0])
			if (L.pBase[i]<min)
				min = i;
	}
	printf("最小值为：%d\n",L.pBase[min]);
	show_arr(&L);
	printf("删除最小值并由最后一个值代替\n");
	L.pBase[min] = L.pBase[L.cnt-1];
	show_arr(&L);

}



//第二大题 第二小题
//将所有元素逆置
int func_2_2()
{
	struct Arr L;
	init_arr(&L,10);
	show_arr(&L);

	printf("\n用 if 倒置数组\n");
	for(int i=0;i<(L.cnt/2);++i)
	{
		int t;
		t = L.pBase[i];
		L.pBase[i] = L.pBase[L.cnt-i-1];
		L.pBase[L.cnt-i-1] = t;
	}

	show_arr(&L);

	printf("\n用 while 倒置数组\n");
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


//第二大题 第三小题
//删除线性表中所有值为x的的元素

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


//第二大题 第四小题
int func_2_4(int s,int t)
{
	int q;
	if (s>=t)
	{
		printf("s,t 给予的值存在问题\n");
		return 0;
	}
	struct Arr L;
	init_arr(&L,10);
	if (is_empty(&L))
	{
		printf("数组为空\n");
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

//第二大题 第五小题

int func_2_5(int s,int t)
{
	int q;
	if (s>=t)
	{
		printf("s,t 给予的值存在问题\n");
		return 0;
	}
	struct Arr L;
	init_arr(&L,10);
	if (is_empty(&L))
	{
		printf("数组为空\n");
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



//第二大题第六小题
//删除重复的值
int func_2_6()
{
	struct Arr L;
	init_arr(&L,10);
	if (is_empty(&L))
	{
		printf("数组为空\n");
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

//第二大题 第七小题
//合并两个数组,并返回结果数组

int * func_2_7()
{
	struct Arr L,M;
	init_arr(&L,20);
	init_arr(&M,10);
	if (is_empty(&L)||is_empty(&M))
	{
		printf("数组为空\n");
		return 0;	
	}
	show_arr(&L);
	show_arr(&M);
	for(int i=0;i<M.cnt;i++)
		append_arr(&L,M.pBase[i]);
	show_arr(&L);
	return L.pBase;
}



//第二大题 第八小题
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
	printf("原始L的值：\n");
	show_arr(&L);
	//清空数组M里的值
	printf("清空M之前的值：\n");
	show_arr(&M);
	for(int i=0;i<5;i++)
	{
		int x;
		delete_arr(&M,1,&x);
	}
	show_arr(&M);

	//开始
	show_arr(&L);
	for(int i=0;i<5;i++)
	{
		//实际上不需要数组M，只需要一个临时变量存放的t即可
		int t;
		t = L.pBase[i];
		L.pBase[i] = L.pBase[i+5];
		L.pBase[i+5] = t;
	}
	free(M.pBase);
	show_arr(&L);
	return 0;
}


//第二大题 第9小题

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
	//开始
	for(int i=0;i<L.cnt;i++)
	{
		if(x == L.pBase[i])
		{
			int t;
			t = L.pBase[i];
			L.pBase[i] = L.pBase[i+1];
			L.pBase[i+1] = t;
			printf("已找到相同元素，并完成替换\n");
			show_arr(&L);
			return 0;
		}

	}
	if (x <L.pBase[0])
	{
		insert_arr(&L,1,x);
		printf("未在数组中匹配到相同元素，已插入到首位\n");
		show_arr(&L);
		return 0;
	}
	
	if (x>L.pBase[L.cnt-1])
	{
		append_arr(&L,x);
		printf("未在数组中匹配到相同元素，已插入到末位\n");
		show_arr(&L);
		return 0;
	}
	for(int j=0;j<L.cnt;j++)
	{	
		if(x>L.pBase[j]&&x<L.pBase[j+1])
		{
			insert_arr(&L,j+2,x);
			printf("未在数组中匹配到相同元素，已插入到其中\n");
			show_arr(&L);
			return 0;
		}
	}

	return 0;
}

//第二大题 第10大题
 int func_2_10()
 {
	 //初始化函数准备
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
	 //开始
	 printf("请输入想要循环左移的整数位数： ");
	 int p=input();
	 for(int i=0;i<p;i++)
	 {
		 insert_arr(&M,i+1,L.pBase[i]);
	 }
	 system("cls");
	 printf("开始循环左移%d个位置\n\n",p);
	 printf("原始数组： \n");
	 show_arr(&L);
	 printf("\r\n");
	 for(int i=0;i<L.cnt-p;i++)
	 {
		 L.pBase[i] = L.pBase[p+i]; 
	 }
	 //show_arr(&L);
	 printf("变化后的数组：\n");
	 for(int i=0;i<p;i++)
	 {
		 L.pBase[L.cnt-p+i] = M.pBase[i];
	 }
	 show_arr(&L);
	 return 0;
}


//第二大题 第11小题
 int func_2_11()
 {
	 //准备工作 初始化数组S1 S2
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
	 printf("原始数据：\n");
	 show_arr(&S1);show_arr(&S2);
	 printf("\n");

	 //开始
	 //讲两个数组合并
	 for(int i=0;i<S1.cnt;i++)
		 insert_arr(&L,i+1,S1.pBase[i]);
	 for(int i=0;i<S2.cnt;i++)
		 insert_arr(&L,S1.cnt+1+i,S2.pBase[i]);
	 //show_arr(&L);
	 //冒泡排序
	 for(int i=0;i<L.cnt;i++)
		 for(int j=i;j<L.cnt;j++)
			if (L.pBase[j]<L.pBase[i])
			 {
				 int t;
				 t=L.pBase[i];
				 L.pBase[i] = L.pBase[j];
				 L.pBase[j] =t;			 
			 }
	 //取中位数
	show_arr(&L);
	int median =L.cnt/2;
	printf("中位数是：%d\n",L.pBase[median-1]);

	 return 0;
 }

 
 //第二大题 第12 小题
 int func_2_12()
 {
	 //数据准备
	 struct Arr L;
	 init_arr(&L,10);
	 int A[]={0,5,2,3,5,7,5,5,5};
	 for (int i=0;i<sizeof(A)/sizeof(A[0]);i++)
	 {
		 L.pBase[i] = A[i];
		 L.cnt++;
	 }
	 //show_arr(&L);
	 //开始
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
		 printf("相同元素个数count: %d\n",count);
		 printf("该数组的主元素为：%d\n",main_element);
		 return main_element;
	 }
	 else
		{
			printf("-1\n");
			return 0;
	     }
 }