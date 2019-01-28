#ifndef __base_h__
#define __base_h__

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
void inversion_arr(struct Arr * pArr);//����
int input();
void clear_arr(struct Arr * pArr);//�������

#endif