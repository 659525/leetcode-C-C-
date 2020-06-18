//1. 两数之和 
//关键词：vector
//author：659525
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
示例 :
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回[0, 1]
*/
//思路：暴力破解，遍历数组nums，用target-nums[i]，将该结果与循环的数组nums[j]对比，i!=j且两数相等则成功返回

/*C++要点：

使用vector迭代器eg：
	
	int nNum[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
	vector<int> nVec(nNum, nNum + 10);	//使用数组初始化迭代器
	vector<int>::iterator iter;			//迭代器指针，相当于for循环的i，需要加*取引用
	vector<int>::iterator begin = nVec.begin();	//迭代器首尾用.begin()和.end()方法遍历
	vector<int>::iterator end = nVec.end();
	for (iter = begin; iter != end; iter++)
	{
		cout << *iter << ",";
	}
	//其他常用用法：
基本操作

(1)头文件#include<vector>.

(2)创建vector对象，vector<int> vec;

(3)尾部插入数字：vec.push_back(a);

(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。

(5)使用迭代器访问元素.

(6)插入元素：    vec.insert(vec.begin()+i,a);在第i个元素后面插入a;

(7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素

　　　　　　　 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始

(8)向量大小:vec.size();

(9)清空:vec.clear()　　　//清空之后，vec.size()为０

*/

#include "stdio.h"	//io输出流所需文件
#include <vector>	//vector所需头文件
#include <iostream>		//C++
using namespace std;	//C++
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>::iterator iter;
		vector<int>::iterator Newiter;
		vector<int>::iterator begin = nums.begin();
		vector<int>::iterator end = nums.end();
		vector<int>vReturn;
		int temp = 0;
		for (iter = begin;iter!=end;iter++) {
			temp = target - *iter;
			for (Newiter=iter; Newiter != end; Newiter++) {
				if (temp==*Newiter&&Newiter!=iter)
				{
					vReturn.push_back(distance(begin,iter));	//push_back()方法，将元素传入迭代器尾部
					vReturn.push_back(distance(begin, Newiter));//distance(a,b)方法，求b-a的距离，当a为.begin()时，表示b在vector的位置
					return vReturn;
				}
			}
		}
		return vReturn;
	}
};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int temp = 0;
	int *Funcreturn = (int*)malloc(sizeof(int)*2);
	memset(Funcreturn, 0, sizeof(int) * 2);
	for (int i=0;i<numsSize;i++){
		temp = target - nums[i];
		for (int j = i;j<numsSize;j++) {
			if (temp==nums[j]&&j!=i){
				Funcreturn[0] = i;
				Funcreturn[1] = j;
				*returnSize = 2;
				return Funcreturn;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}

int main() {
	//C++部分：
	int nNum[] = { 3,2,4 };
	vector<int> nVec(nNum, nNum + 3);
	Solution A;
	vector<int> New=A.twoSum(nVec, 6);
	//C语言部分
	/* 
	int nNum[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
	int* returnSize = NULL;
	int* pNum = twoSum(nNum,10,20, returnSize);
	for (int i=0;i<*returnSize;i++)
	{
		printf("%d\t", pNum[i]);
	}
	free(pNum);
	pNum = NULL;
	*/
	return 0;
}
