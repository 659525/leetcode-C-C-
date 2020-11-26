//1370.上升下降字符串
//关键词：完全二叉树遍历
//author：659525
/*
给你一个字符串 s ，请你根据下面的算法重新构造字符串：

1.从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
2.从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
3.重复步骤 2 ，直到你没法从 s 中选择字符。
4.从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
5.从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。
6.重复步骤 5 ，直到你没法从 s 中选择字符。
7.重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。

请你返回将 s 中字符重新排序后的 结果字符串 。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/increasing-decreasing-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
示例：
输入：s = "aaaabbbbcccc"
输出："abccbaabccba"
解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/increasing-decreasing-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路，桶原理，建立个数组num[26]存放a-z，然后依次顺序-逆序遍历+循环即可
#include "windows.h"//memset/malloc/strlen需要
#include "stdio.h" //printf需要
char * sortString(char * s) {
	int num[26];
	memset(num, 0, sizeof(num));
	int nlen = strlen(s);
	for (int i=0; i<nlen;i++)
	{
		num[(s[i] - 'a')]++;
	}
	char *ret = (char*)malloc(nlen + 1);
	memset(ret, 0, nlen + 1);
	//依次正-反-正...取桶内非空元素
	for (int i=0;i<nlen;)
	{
		for (int j=0;j<26;j++)
		{
			if (num[j]>0)
			{
				ret[i] = j + 'a';
				num[j]--;
				i++;
			}
		}
		for (int j=25;j>=0;j--)
		{
			if (num[j] > 0)
			{
				ret[i] = j + 'a';
				num[j]--;
				i++;
			}
		}
	}
	return ret;
}

int main() {
	char szA[] = "aaaabbbbcccc";
	char*s = NULL;
	s = sortString(szA);
	printf("%s\n", s);
	return 0;
}