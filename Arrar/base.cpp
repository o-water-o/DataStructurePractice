# include <stdio.h>
# include <malloc.h>
# include <stdlib.h> //������ exit�������� 
//������ һ���������ͣ����������͵����ֽ���  struct Arr 
struct Arr //�ṹ�����Զ������������ 
{
	int * pBase; //�洢����ĵ�һ��Ԫ�صĵ�ַ
	int len;//�����������ɵ����Ԫ�صĸ���
	int cnt; //��ǰ������ЧԪ�صĸ���
	int incretment;//�Զ��������� 
};
void init_arr(struct Arr *pArr,int length);
bool append_arr(struct Arr *pArr,int val);//׷��
bool insert_arr(struct Arr *pArr,int pos,int val);//���� pos ��ֵ��1��ʼ
bool delete_arr(struct Arr *pArr,int pos,int *pVal);
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
int get();
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr * pArr);
int input();
void clear_arr(struct Arr * pArr);//�������
  
/*int main()
{
	struct Arr arr;
	init_arr(&arr,4);
	//printf("%d",arr.len);
	show_arr(&arr);	
	for (int j;j<10;j++)
	{
		append_arr(&arr,input());
		show_arr(&arr) ;
		if (arr.cnt == arr.len)
			{
			printf("����������������׷�ӣ������˳�������\n\n");
			break;
		}
	}
	
	show_arr(&arr) ;
	return 0;
}
*/


//��ʼ������ 
void init_arr(struct Arr *pArr,int length)
{
	//(*pArr).len=90;
	pArr->pBase=(int *)malloc(sizeof(int)*length);
	if(NULL == pArr->pBase)
	{
		printf("��̬�����ڴ����ʧ�ܣ�\n");
		exit(-1);
		 
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
		/*
		pArr->pBase[0] = -1;
		pArr->pBase[1] = 3;
		pArr->pBase[2] = 5;
		pArr->pBase[3] = 7	;
		pArr->pBase[4] = 9	;
		*/
	}
	return;
}


//�ж������Ƿ�Ϊ�� 
bool is_empty(struct Arr * pArr)
{
	if(0 == pArr->cnt)
	{
		 return true;
	}
	else
	{
		return false;
	}
}


//�ж������Ƿ���Ա 
bool is_full(struct Arr * pArr)
{
	if (pArr->len==pArr->cnt)
		return true;
	else
		return false;
}


//�������ֵ 
void show_arr(struct Arr *pArr)
{
	if (is_empty(pArr))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		for(int i=0;i<pArr->cnt;i++)
			printf("%d\t",pArr->pBase[i]);
		printf("(cnt��%d\tlen: %d)",pArr->cnt,pArr->len);
		printf("\n");
	}
}


//׷��Ԫ��
bool append_arr(struct Arr *pArr,int val)
{
	if (is_full(pArr))
		{
		printf("��������Ա������������\n");
		return false;}
	else
		{
			pArr->pBase[pArr->cnt] = val;
			pArr->cnt++;
			return true;
		 } 
 } 
 
 //���ܼ�������
 int input()
 {
 	//printf("��������Ҫ���ַ��� ");
 	int x;
	scanf("%d",&x);
	return x;
  } 


//����
 bool insert_arr(struct Arr *pArr,int pos,int val)//���� pos ��ֵ��1��ʼ
 {
	 if (is_full(pArr))
		 return false;
	 if (pos<1 || pos>pArr->cnt+1)
		 return false;

	 for(int i=pArr->cnt-1;i>=pos-1;--i)
	 {
		 pArr->pBase[i+1] =pArr->pBase[i];
	 }
	 pArr->pBase[pos-1] = val;
	 pArr->cnt++;
	 //printf("\nappeng_arr() ����ɹ���\n");
	 return true;
 }

 //ɾ��Ԫ�ز�����ֵ
 bool delete_arr(struct Arr *pArr,int pos,int *pVal)
 {
	 if (is_empty(pArr))
		 return false;
	 if (pos<1 || pos>pArr->cnt)
		 return false;
	 *pVal = pArr->pBase[pos-1];
	 for (int i=pos;i<pArr->cnt;++i)
		 pArr->pBase[i-1] = pArr->pBase[i];
	 pArr->cnt--;
	 //printf("\ndelete_arr() Ԫ�أ�%d  ɾ���ɹ���\n",*pVal);
	 return true;

 
 }


 //����
 void inversion_arr(struct Arr * pArr)
 {
	 int i=0;
	 int j=pArr->cnt-1;
	 int t;
	 while (i<j)
	 {
		 t = pArr->pBase[i];
		 pArr->pBase[i] = pArr->pBase[j];
		 pArr->pBase[j] = t;
		 ++i;
		 --j;
		 //printf("i=%d j=%d\t",i,j);
		 
	 }
	 return;
 }


 //ð������
 void sort_arr(struct Arr *pArr)
 {
	 int i,j,t;
	 for(i=0;i<pArr->cnt;++i)
	 {
		 for(j=i+1;j<pArr->cnt;++j)
			 if (pArr->pBase[i] > pArr->pBase[j])
			 {
				 t=pArr->pBase[i];
				 pArr->pBase[i] = pArr->pBase[j];
				 pArr->pBase[j] = t;

			 }
			 				 				
	 }
 }


 //�������
 void clear_arr(struct Arr * pArr)
 {
	 int t= pArr->cnt;
	 int x;
	 for(int i=0;i<t;i++)
		 delete_arr(pArr,1,&x);
	 //system("cls");
 }

