//164.最大间距
//关键词：sort排序
//author：659525
/*
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1 :

输入: [3, 6, 9, 1]
	输出 : 3
	解释 : 排序后的数组是[1, 3, 6, 9], 其中相邻元素(3, 6) 和(6, 9) 之间都存在最大差值 3。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/maximum-gap
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
1、sort函数可以三个参数也可以两个参数，必须的头文件#include < algorithm>和using namespace std;
2、它使用的排序方法是类似于快排的方法，时间复杂度为n*log2(n)

3、Sort函数有三个参数：（第三个参数可不写）

（1）第一个是要排序的数组的起始地址。

（2）第二个是结束的地址（最后一位要排序的地址）

（3）第三个参数是排序的方法，可以是从大到小也可是从小到大，还可以不写第三个参数，此时默认的排序方法是从小到大排序。

默认升序排序

此时降序排序就是：
bool complare(int a,int b)

{
 return a>b;

}
sort(a,a+nlen*sizeof(int),complare);
*/

#include <algorithm> //sort排序函数需要
using namespace std; //sort排序函数需要

#include <vector>//vector数组要用到
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int ret = 0;//临时存放相邻位的差值
		for (vector<int>::iterator it = nums.begin();it!=nums.end()-1;it++)//找相邻大小的差值
		{
			if ((*(it+1))-((*it))> ret) {
				ret = (*(it + 1)) - ((*it));
			}
		}
		return ret;
	}
};


int maximumGap(int* nums, int numsSize) {
	if (numsSize<2)//如果数组元素个数小于 2，则返回 0。
	{
		return 0;
	}
	sort(nums, nums+numsSize);//先按从小到大排序,C语言没有sort函数，需要自己实现
	int ret=0;//临时存放相邻位的差值
	for (int i=0;i<numsSize-1;i++)//找相邻大小的差值
	{
		if (nums[i + 1] - nums[i] > ret) {
			ret =  nums[i + 1] - nums[i];
		}
	}
	
	return ret;
}

#include "windows.h"//ARRAYSIZE要用
int main() {
	int a[] = { 5,7,1,2,9 };
	int n=maximumGap(a, 5);
	printf("%d\n", n);
	Solution A;
	vector<int> nums;
	for (int i=0;i<5;i++)
	{
		nums.push_back(a[i]);
	}
	n=A.maximumGap(nums);
	printf("%d\n",n);
	return 0;
}