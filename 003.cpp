/*
定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1 :

输入: "abcabcbb"
	输出 : 3
	解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
	示例 2 :

	输入 : "bbbbb"
	输出 : 1
	解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
	示例 3 :

	输入 : "pwwkew"
	输出 : 3
	解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
	请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/longest-substring-without-repeating-characters
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路：动态数组移动(C的方法一字符串用index[128]做映射，方法二用双重循环。C++方法为map)

//C头文件
//#include "stdio.h"
//#include <windows.h>
/*
//C语言方法一：来自leetcode的答案
int lengthOfLongestSubstring1(char * s) {
	int i, count = 0, max = 0, index[128] = { 0 }, start = 0;	//为什么取128呢，因为字符串的ascii码在0-127间
	for (i = 0; s[i] != '\0'; i++)
	{
		if (index[s[i]] > start)   //index[s[i]]初值肯定是为0的，不为0说明这里被赋值过
		{                       //子串起始下标应移动到的地方
			count = i - start;		//计算当前字符串长度	
			if (count > max)		//如果当前长度大于最大值，顶替掉最大值
			{
				max = count;
			}
			start = index[s[i]];	//重新设置开始的起点
		}
		index[s[i]] = i + 1;		//如果s="abc" ,i=0时,s[i]='a',index[a]=0+1,index[a]里存放的是数组下标
	}
	count = i - start;		//处理最后一串字符串，所以for循环里的i为外置的
	return count > max ? count : max;
}

//自己用双循环实现
int lengthOfLongestSubstring(char * s) {
	int max = 0;	//记录最大值
	int count = 0;	//当前位置，
	for (int i = 0; s[i] != '\0'; i++)
	{
		for (int j = count; j < i; j++)
		{
			if (s[i] == s[j])	//如果找到重复的
			{
				if (max < i - count) {	//记录当前最大长度
					max = i - count;
				}
				count = j + 1;//记录下次初始位置
			}
			//没找到重复的则继续循环
		}
	}
	return max > strlen(s) - count ? max : strlen(s) - count;
}
*/
//C++头文件
#include<iostream>
using namespace std;
#include<map>
#include<algorithm> //max用到

//我的方法：时间复杂度高
class Solution1 {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> hash;
		int max = 0;
		int count = 0;//当前字符串位置
		int start = 0;//不重复字符串的首部位置
		int ssize = s.size();
		while (count < s.size()) {
			char tempchar = s[count];//取出该字符
			//如果hashmap中没有找到该元素,将序号-值入表
			//如果找到重复的，记录当前长度并更新首串位置
			if (hash.find(tempchar)!=hash.end())
			{
				max = max > count - start ? max : count - start;
				start = start > hash.find(tempchar)->second ? start : hash.find(tempchar)->second;
			}
			hash[tempchar] = count+1;
			count++;
		}
		return max > count - start ? max : count - start;
	}
};


int main() {

	char s[] = "abcbdca";
		//C语言部分
	//int n= lengthOfLongestSubstring(s);
		//C++部分
	Solution A;
	int n2=A.lengthOfLongestSubstring(s);

	return 0;
}
