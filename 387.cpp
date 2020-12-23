//387.字符串中的第一个唯一字符
//关键词：字符串比较,字典
//author：659525
//2020年12月23日13:40:02

//构建<字符,出现次数>的字典，遍历string s的每个字符，找到只出现一次的返回

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
 
提示：你可以假定该字符串只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int firstUniqChar(string s) {
		int n = s.length();
		//特殊边界情况：
		if (n == 1) { return 0; }//只有一个字符就直接返回0
		char* A = new char[n];//如果s[i]为重复位，就置1
		memset(A,0,n);
		for (int i=0;i<n;i++)
		{
			if (A[i]==0)//如果A[i]为新字符，就开始找
			{
				for (int j = i + 1; j < n; j++)
				{
					if (s[i] == s[j])//如果找到一样的，将重复的位置标记出来
					{
						A[i] = 1;
						A[j] = 1;
					}
					if (s[i] != s[j] && A[i]==0 &&j == n - 1)//如果找到最后还没有找到，就认为找到返回值了
					{
						return i;
					}
				}
			}

		}
		//最后一位没有考虑到：
		//所以我们遍历数组A[i]，返回第一个为0的位置
		for (int i=0;i<n;i++)
		{
			if (A[i]==0)
			{
				return i;
			}
		}
		return -1;//没找到返回-1
	}
};

class Solution2 {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> frequency;//构建<字符,出现次数>的字典，遍历string s的每个字符，找到只出现一次的返回
		for (char ch : s) {
			++frequency[ch];
		}
		for (int i = 0; i < s.size(); ++i) {
			if (frequency[s[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};
