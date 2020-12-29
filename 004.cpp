/* 
4. Ѱ�����������������λ��		�Ѷ�-����
����������СΪ m �� n �����򣨴�С�������� nums1 �� nums2��

�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��

����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�
ʾ�� 1:

nums1 = [1, 3]
nums2 = [2]

����λ���� 2.0
ʾ�� 2:

nums1 = [1, 2]
nums2 = [3, 4]

����λ���� (2 + 3)/2 = 2.5

��Դ�����ۣ�LeetCode��	
���ӣ�https://leetcode-cn.com/problems/median-of-two-sorted-arrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˼·��Ҫ�ﵽ �����ʱ�临�Ӷȣ���Ҫʹ�ö��ֲ���

//C++����
#include<iostream>
using namespace std;
#include<vector>
#include <algorithm> //max min����Ҫ
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int sum = m + n;//��sum����ʱ��ֻ��һ����λ����sumΪż��ʱ��������λ��
		if (sum%2)//����������ҵ��ϲ������ĵ�sum/2λԪ�ؼ���
		{
			return findKeyvalue(nums1,nums2, sum/2);
		}
		else//ż�����
		{
			return (findKeyvalue(nums1, nums2, sum / 2 - 1) + findKeyvalue(nums1, nums2, sum / 2)) / 2;
		}
	}	
	double findKeyvalue(vector<int> nums1, vector<int> nums2,int k)
	{
		for (int i=0;i<nums2.size();i++)
		{
			nums1.emplace_back(nums2[i]);//�ϲ�
		}
		sort(nums1.begin(), nums1.end());//����
		return nums1[k];
	}

	
	
};

//�ٷ��ⷨ
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
		/* ��Ҫ˼·��Ҫ�ҵ��� k (k>1) С��Ԫ�أ���ô��ȡ pivot1 = nums1[k/2-1] �� pivot2 = nums2[k/2-1] ���бȽ�
		 * ����� "/" ��ʾ����
		 * nums1 ��С�ڵ��� pivot1 ��Ԫ���� nums1[0 .. k/2-2] ���� k/2-1 ��
		 * nums2 ��С�ڵ��� pivot2 ��Ԫ���� nums2[0 .. k/2-2] ���� k/2-1 ��
		 * ȡ pivot = min(pivot1, pivot2)������������С�ڵ��� pivot ��Ԫ�ع��Ʋ��ᳬ�� (k/2-1) + (k/2-1) <= k-2 ��
		 * ���� pivot �������Ҳֻ���ǵ� k-1 С��Ԫ��
		 * ��� pivot = pivot1����ô nums1[0 .. k/2-1] ���������ǵ� k С��Ԫ�ء�����ЩԪ��ȫ�� "ɾ��"��ʣ�µ���Ϊ�µ� nums1 ����
		 * ��� pivot = pivot2����ô nums2[0 .. k/2-1] ���������ǵ� k С��Ԫ�ء�����ЩԪ��ȫ�� "ɾ��"��ʣ�µ���Ϊ�µ� nums2 ����
		 * �������� "ɾ��" ��һЩԪ�أ���ЩԪ�ض��ȵ� k С��Ԫ��ҪС���������Ҫ�޸� k ��ֵ����ȥɾ�������ĸ���
		 */

		int m = nums1.size();
		int n = nums2.size();
		int index1 = 0, index2 = 0;

		while (true) {
			// �߽����
			if (index1 == m) {
				return nums2[index2 + k - 1];
			}
			if (index2 == n) {
				return nums1[index1 + k - 1];
			}
			if (k == 1) {
				return min(nums1[index1], nums2[index2]);
			}

			// �������
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