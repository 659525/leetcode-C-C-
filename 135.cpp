//135:分发糖果
//关键词：贪心算法，拆分步骤
//author：659525
//2020年12月24日12:57:35

//如果s[i]比s[i+i]和s[i-1]大，那么就多分1个苹果，[1,2,3,4,5,6,7,8] dp[n]表示第n个孩子应该分到的苹果 dp[n]=max(dp[n-1],dp[n+1])+1
//但是用不到动态规划，因为不是前者推后者


//思路2：从左往右遍历，如果s[i+1]比s[i]大，则设置c[i+1]=c[i]+1；
//第二轮，从右往左遍历，如果s[i]比s[i+1]，则设置为max(c[i],c[i+1]+1)
//遍历c[i]的sum和就是总需求苹果result

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1 :

输入: [1, 0, 2]
	输出 : 5
	解释 : 你可以分别给这三个孩子分发 2、1、2 颗糖果。
	示例 2 :

输入: [1, 2, 2]
	输出 : 4
	解释 : 你可以分别给这三个孩子分发 1、2、1 颗糖果。
	第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/candy
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include "windows.h"
using namespace std;
class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candyVec(ratings.size(), 1);
		// 从前向后
		for (int i = 1; i < ratings.size(); i++) {
			if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
		}
		// 从后向前
		for (int i = ratings.size() - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) {
				candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
			}
		}
		// 统计结果
		int result = 0;
		for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
		return result;
	}
};

int main()
{
	return 0;
}