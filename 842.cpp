//842:将(字符串)数组拆分成斐波那契式序列
//关键词：回溯函数
//author：659525

/*
给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列[123, 456, 579]。
形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2 ^ 31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i + 1] = F[i + 2] 成立。

另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回[]。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
示例 1：

输入："123456579"
输出：[123, 456, 579]
示例 2：

输入 : "11235813"
	输出 : [1, 1, 2, 3, 5, 8, 13]
	示例 3：

	输入 : "112358130"
	输出 : []
	解释 : 这项任务无法完成。
	示例 4：

	输入："0123"
	输出：[]
	解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
	示例 5：

	输入 : "1101111"
	输出 : [110, 1, 111]
	解释 : 输出[11, 0, 11, 11] 也同样被接受。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include "windows.h"
#include "stdlib.h"

//回溯函数-参数说明：
//list:当前的数组列表；listSize：当前的数组长；S:数字字符串S；len：字符串S的长度，不含'\0'；
//index：当前操作光标位置；sum：用于验证F[i+2]=F[i+1]+F[i]的和，prev：index前面列表元素的的值
bool backTrack(int* list,int* listSize,char* S,const int len,int index,long long sum,int prev){
	//当构建完成时，满足条件2：F.length >= 3；
	if (index == len) {
		return (*listSize) >= 3;
	}
	
	long long curr=0;//当前数值,满足条件1:F[i]为long long类型的正整数
	for (int i=index;i<len;i++)
	{
		if (i>index&&S[index]=='0')
		{
			//满足条件：不能以0开头，除非是单独的一个0
			break;
		}
		curr = curr * 10 + S[i] - '0';//整数运算：'12'->1+2*10
		//满足条件1:F[i]为long long类型的正整数
		if (curr>INT_MAX)
		{
			break;
		}
		if((*listSize)>=2)//当有了F[0]和F[1]时，才开始找F[2]
		{
			if (curr<sum)//当F[i+2]<F[i+1]+F[i]时，继续搜索F[i+2]的值
			{
				continue;
			}
			else if (curr > sum)//当F[i+2]>F[i+1]+F[i]时，没找到匹配值，停止搜索，跳出循环
			{
				break;
			}
		}
		//到这一步已经找到了符合条件的F[i+2]=F[i+1]+F[i]
		//将F[i+2]添加到返回列表中
		list[(*listSize)] = curr;
		(*listSize)++;
		if (backTrack(list,listSize,S,len,i+1,prev+curr,curr))
		{
			return true;
		}
		(*listSize)--;//如果添加失败 listsize-1倒退回溯，就是重头开始
	}
	return false;
	
}

//主函数
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
	//用例测试
	char S[7] = "110111";
	int retsize = 0;
	int *ret = splitIntoFibonacci(S, &retsize);
	return 0;
}