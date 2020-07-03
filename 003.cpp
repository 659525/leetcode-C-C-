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

//思路：动态数组移动

#include "stdio.h"
#include <windows.h>
#include< map >  //映射，键值对容器。


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

int lengthOfLongestSubstring(char * s) {
	int max = 0;
	int count = 0;//当前位置，
	for (int i =0;s[i]!='\0';i++)
	{
		for (int j= count;j<i;j++)
		{
			if (s[i]==s[j])	//如果找到重复的
			{
				if (max < i - count) {	//记录当前最大长度
					max = i - count;
				}
				count = j+1;//记录下次初始位置
			}
			//没找到重复的则继续循环
		}
	}
	return max>strlen(s)-count?max:strlen(s) - count;
}
int main() {

	char s[]= "aabacbd";
	int n= lengthOfLongestSubstring(s);
	return 0;
}
