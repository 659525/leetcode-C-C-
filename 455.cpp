//455:分发糖果
//关键词：贪心算法，拆分步骤
//author：659525
//2020年12月24日12:57:35

#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int findContentChildren1(vector<int>& g, vector<int>& s) {
		int res = 0;//返回值：满足孩子的目标数
		sort(g.begin(), g.end());//先将g从大到小排序，再从小到大依次满足即可
		sort(s.begin(), s.end());//将饼干盒子也从大到小排序
		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				if (g[i] <= s[j]) {
					res++;
					s.erase(s.begin() + j);//这里可以进行优化
					break;
				}
			}
		}
		return res;
	}
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int res = 0;//返回值：满足孩子的目标数
		sort(g.begin(), g.end());//先将g从大到小排序，再从小到大依次满足即可
		sort(s.begin(), s.end());//将饼干盒子也从大到小排序
		for (int i=0,j=0;i<g.size()&&j<s.size();i++,j++)
		{
			//分不到糖果时，饼干盒序号+1，这里注意要保证j是在饼干盒范围内的
			while (g[i]>s[i]&&j<s.size())
			{
				j++;
			}
			//分到糖果时，返回值加1
			if (g[i]<s[j])
			{
				res++;
			}
			
		}
		return res;
	}
};

int main()
{
	Solution A;
	vector<int> g{1,2,3};
	vector<int> s{ 1,1 };
	int n=A.findContentChildren(g, s);
	return 0;
	
}