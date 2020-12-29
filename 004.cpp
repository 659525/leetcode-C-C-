/* 
4. 寻找两个正序数组的中位数		难度-困难
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）	
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路：要达到 所需的时间复杂度，需要使用二分查找

//C++部分
#include<iostream>
using namespace std;
#include<vector>
#include <algorithm> //max min宏需要
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int sum = m + n;//当sum奇数时，只有一个中位数，sum为偶数时有俩个中位数
		if (sum%2)//奇数情况，找到合并数组后的第sum/2位元素即可
		{
			return findKeyvalue(nums1,nums2, sum/2);
		}
		else//偶数情况
		{
			return (findKeyvalue(nums1, nums2, sum / 2 - 1) + findKeyvalue(nums1, nums2, sum / 2)) / 2;
		}
	}	
	double findKeyvalue(vector<int> nums1, vector<int> nums2,int k)
	{
		for (int i=0;i<nums2.size();i++)
		{
			nums1.emplace_back(nums2[i]);//合并
		}
		sort(nums1.begin(), nums1.end());//排序
		return nums1[k];
	}

	
	
};

//官方解法
class Solution2
{
public:
	double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
		int length1 = nums1.size(), length2 = nums2.size();
		int totalLength = length1 + length2;
		if (totalLength % 2 == 1) {
			int midIndex = totalLength / 2;
			double median = getKthElement(nums1, nums2, midIndex + 1);
			return median;
		}
		else {
			int midIndex1 = totalLength / 2 - 1, midIndex2 = totalLength / 2;
			double median = (getKthElement(nums1, nums2, midIndex1 + 1) + getKthElement(nums1, nums2, midIndex2 + 1)) / 2.0;
			return median;
		}
	}

	int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
		/* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
		 * 这里的 "/" 表示整除
		 * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
		 * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
		 * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
		 * 这样 pivot 本身最大也只能是第 k-1 小的元素
		 * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
		 * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
		 * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
		 */

		int m = nums1.size();
		int n = nums2.size();
		int index1 = 0, index2 = 0;

		while (true) {
			// 边界情况
			if (index1 == m) {
				return nums2[index2 + k - 1];
			}
			if (index2 == n) {
				return nums1[index1 + k - 1];
			}
			if (k == 1) {
				return min(nums1[index1], nums2[index2]);
			}

			// 正常情况
			int newIndex1 = min(index1 + k / 2 - 1, m - 1);
			int newIndex2 = min(index2 + k / 2 - 1, n - 1);
			int pivot1 = nums1[newIndex1];
			int pivot2 = nums2[newIndex2];
			if (pivot1 <= pivot2) {
				k -= newIndex1 - index1 + 1;
				index1 = newIndex1 + 1;
			}
			else {
				k -= newIndex2 - index2 + 1;
				index2 = newIndex2 + 1;
			}
		}
	}
}; 
int main() {
	vector<int> nums1 = { 1,3 };
	vector<int> nums2 = { 2 };
	Solution2 A;
	double res=A.findMedianSortedArrays(nums1, nums2);
	return 0;
}