//455:�ַ��ǹ�
//�ؼ��ʣ�̰���㷨����ֲ���
//author��659525
//2020��12��24��12:57:35

#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int findContentChildren1(vector<int>& g, vector<int>& s) {
		int res = 0;//����ֵ�����㺢�ӵ�Ŀ����
		sort(g.begin(), g.end());//�Ƚ�g�Ӵ�С�����ٴ�С�����������㼴��
		sort(s.begin(), s.end());//�����ɺ���Ҳ�Ӵ�С����
		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				if (g[i] <= s[j]) {
					res++;
					s.erase(s.begin() + j);//������Խ����Ż�
					break;
				}
			}
		}
		return res;
	}
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int res = 0;//����ֵ�����㺢�ӵ�Ŀ����
		sort(g.begin(), g.end());//�Ƚ�g�Ӵ�С�����ٴ�С�����������㼴��
		sort(s.begin(), s.end());//�����ɺ���Ҳ�Ӵ�С����
		for (int i=0,j=0;i<g.size()&&j<s.size();i++,j++)
		{
			//�ֲ����ǹ�ʱ�����ɺ����+1������ע��Ҫ��֤j���ڱ��ɺз�Χ�ڵ�
			while (g[i]>s[i]&&j<s.size())
			{
				j++;
			}
			//�ֵ��ǹ�ʱ������ֵ��1
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