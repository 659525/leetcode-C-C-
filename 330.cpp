//330.按要求补齐数组
//关键词：
//author：659525
//2020年12月29日16:03:51

//copy的

//核心原理：
/*
对于任意 1 \le y<x1≤y<x，yy 已经被覆盖，xx 在数组中，因此 y+xy+x 也被覆盖，
区间 [x+1,2x-1][x+1,2x−1]（即区间 [1,x-1][1,x−1] 内的每个数字加上 xx 之后得到的区间）内的所有数字也被覆盖，
由此可得区间 [1,2x-1][1,2x−1] 内的所有数字都被覆盖。
 */


/*
给定一个已排序的正整数数组 nums，和一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都可以用 nums 中某几个数字的和来表示。请输出满足上述要求的最少需要补充的数字个数。

示例 1:
输入: nums = [1,3], n = 6
输出: 1
解释:
根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
现在如果我们将 2 添加到 nums 中， 组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
所以我们最少需要添加一个数字。

示例 2:
输入: nums = [1,5,10], n = 20
输出: 2
解释: 我们需要添加 [2, 4]。

示例 3:
输入: nums = [1,2,2], n = 5
输出: 0   
解释:无需添加

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/patching-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <vector>
using namespace std;
class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		//当前能满足的累加的总和
		long total = 1;
		//需要补充的数字个数
		int count = 0;
		//访问的数组下标索引
		int index = 0;
		while (total <= n) {
			if (index < nums.size() && nums[index] <= total) {
				//如果数组能组成的数字范围是[1,total)，那么加上nums[index]
				//就变成了[1,total)U[nums[index],total+nums[index])
				//结果就是[1,total+nums[index])
				total += nums[index++];
			}
			else {
				//添加一个新数字，并且count加1
				total <<= 1;
				count++;
			}
		}
		return count;
	}
};

int main()
{
	Solution A;
	vector<int> nums = { 1,5,10 }; 
	A.minPatches(nums, 20);
	return 0;
}