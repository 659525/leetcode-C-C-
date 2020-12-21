//389.找不同	
//关键词：回文字符串，动态规划
//author：659525

//思路：char sz[26]存放A-Z出现的次数，当俩个数组合并出现的次数为奇数时，返回该值

/*
给定两个字符串 s 和 t，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。

示例 1：
输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。

示例 2：
输入：s = "", t = "y"
输出："y"

示例 3：
输入：s = "a", t = "aa"
输出："a"

示例 4：
输入：s = "ae", t = "aea"
输出："a"

提示：

0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/find-the-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;
//0 <= s.length <= 1000
//t.length == s.length + 1
class Solution {
public:
	char findTheDifference(string s, string t) {
		char sz[26] = {};//存放A-Z;
		for (int i = 0; i < s.length(); i++) {
			sz[s[i] - 'a']++;
			sz[t[i] - 'a']++;
		}
		sz[t[t.length() - 1] - 'a']++;
		for (int i = 0; i < 26; i++) {
			if (sz[i]%2)
			{
				return i + 'a';
			}
		}
		return ' ';
		
	}
};
int main()
{
	Solution A;
	char B=A.findTheDifference("abde", "abcde");
	return 0;
}