//63.不同路径Ⅱ
//关键词：类A*寻路算法(中间有)，递归
//author：659525
//2020年12月25日16:38:30


//dp[0][0]=0 

/*
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]  //1表示障碍物
输出：2
解释：
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

提示：

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		const int m = obstacleGrid.size();//保存行和列
		const int n = obstacleGrid[0].size();
		
		int **dp;
		dp = new int*[m];
		for (int i=0;i<m;i++)
		{
			dp[i] = new int[n];
		}
		
		if (obstacleGrid[0][0]==1)//如果左上角为障碍物，则直接返回0，不可能到达
		{
			return 0;
		}
		else
		{
			dp[0][0] = 1;//将初始状态设置为1
		}
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (obstacleGrid[i][j] == 1)//如果碰到障碍物了
				{
					dp[i][j] = 0;
				}
				else if(i>0&&j>0)//没碰到障碍物的情况
				{				
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else if(i==0&&j>0)//边界情况
				{
					dp[i][j] = dp[i][j - 1];
				}
				else if (j==0&&i>0)//边界情况
				{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		int res = dp[m - 1][n - 1];
		//清理指针
		for (int i = 0; i < m; i++)
		{
			delete[]dp[i];
		}
		delete[]dp;
		return res;
	}
};
int main()
{
	vector<vector<int>> obstacleGrid = { {0, 0, 0 }, {0, 1, 0},{0, 0, 0}};
	Solution A;
	int n=A.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}
