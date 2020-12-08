//842:��(�ַ���)�����ֳ�쳲�����ʽ����
//�ؼ��ʣ����ݺ���
//author��659525

/*
����һ�������ַ��� S������ S = "123456579"�����ǿ��Խ����ֳ�쳲�����ʽ������[123, 456, 579]��
��ʽ�ϣ�쳲�����ʽ������һ���Ǹ������б� F�������㣺

0 <= F[i] <= 2 ^ 31 - 1����Ҳ����˵��ÿ������������ 32 λ�з����������ͣ���
F.length >= 3��
�������е�0 <= i < F.length - 2������ F[i] + F[i + 1] = F[i + 2] ������

���⣬��ע�⣬���ַ�����ֳ�С��ʱ��ÿ���������һ����Ҫ���㿪ͷ����������������� 0 ����
���ش� S ��ֳ���������һ��쳲�����ʽ�����п飬������ܲ���򷵻�[]��

	��Դ�����ۣ�LeetCode��
	���ӣ�https ://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
/*
ʾ�� 1��

���룺"123456579"
�����[123, 456, 579]
ʾ�� 2��

���� : "11235813"
	��� : [1, 1, 2, 3, 5, 8, 13]
	ʾ�� 3��

	���� : "112358130"
	��� : []
	���� : ���������޷���ɡ�
	ʾ�� 4��

	���룺"0123"
	�����[]
	���ͣ�ÿ��������ֲ������㿪ͷ����� "01"��"2"��"3" ������Ч�𰸡�
	ʾ�� 5��

	���� : "1101111"
	��� : [110, 1, 111]
	���� : ���[11, 0, 11, 11] Ҳͬ�������ܡ�

	��Դ�����ۣ�LeetCode��
	���ӣ�https ://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


#include "windows.h"
#include "stdlib.h"

//���ݺ���-����˵����
//list:��ǰ�������б�listSize����ǰ�����鳤��S:�����ַ���S��len���ַ���S�ĳ��ȣ�����'\0'��
//index����ǰ�������λ�ã�sum��������֤F[i+2]=F[i+1]+F[i]�ĺͣ�prev��indexǰ���б�Ԫ�صĵ�ֵ
bool backTrack(int* list,int* listSize,char* S,const int len,int index,long long sum,int prev){
	//���������ʱ����������2��F.length >= 3��
	if (index == len) {
		return (*listSize) >= 3;
	}
	
	long long curr=0;//��ǰ��ֵ,��������1:F[i]Ϊlong long���͵�������
	for (int i=index;i<len;i++)
	{
		if (i>index&&S[index]=='0')
		{
			//����������������0��ͷ�������ǵ�����һ��0
			break;
		}
		curr = curr * 10 + S[i] - '0';//�������㣺'12'->1+2*10
		//��������1:F[i]Ϊlong long���͵�������
		if (curr>INT_MAX)
		{
			break;
		}
		if((*listSize)>=2)//������F[0]��F[1]ʱ���ſ�ʼ��F[2]
		{
			if (curr<sum)//��F[i+2]<F[i+1]+F[i]ʱ����������F[i+2]��ֵ
			{
				continue;
			}
			else if (curr > sum)//��F[i+2]>F[i+1]+F[i]ʱ��û�ҵ�ƥ��ֵ��ֹͣ����������ѭ��
			{
				break;
			}
		}
		//����һ���Ѿ��ҵ��˷���������F[i+2]=F[i+1]+F[i]
		//��F[i+2]��ӵ������б���
		list[(*listSize)] = curr;
		(*listSize)++;
		if (backTrack(list,listSize,S,len,i+1,prev+curr,curr))
		{
			return true;
		}
		(*listSize)--;//������ʧ�� listsize-1���˻��ݣ�������ͷ��ʼ
	}
	return false;
	
}

//������
int* splitIntoFibonacci(char * S, int* returnSize) {
	int n = strlen(S);
	int* list = (int*)malloc(sizeof(int) * n);
	memset(list, 0, sizeof(int) * n);
	*returnSize = 0;
	backTrack(list, returnSize, S, strlen(S), 0,0,0);
	return list;

}

int main()
{
	//��������
	char S[7] = "110111";
	int retsize = 0;
	int *ret = splitIntoFibonacci(S, &retsize);
	return 0;
}