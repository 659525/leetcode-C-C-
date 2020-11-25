//222.完全二叉树的节点数  
//关键词：完全二叉树遍历
//author：659525
/*给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~2h 个节点。


来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//简单思路：直接深度遍历递归一句话完事
/*
如题：先找到第k层，然后从k层开始遍历它的节点,k+1层可以用二分法寻找空节点的位置,该层最多有2的k+1次方个节点
        1
      /   \
     q     w 
    / \   /  \
	   ...
   k    k   k   k    
  / \  / \ / \ / 
 a   b c d e f g 
  */


#include "stdio.h"    //printf要用到
#include "windows.h"  //system("pause");要用到
#include "math.h"     //pow(a,b)求幂函数有用到（a的b次方）
//C语言版本：
//思路：先从根节点从右找到最顶层树位置，在计算最顶层节点数目，如果找了n层到达树顶（2的n次方减一节点），再计算最后一层即可
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;	
};

//树顶二分法
int countNodes_SB2(struct TreeNode* root) {
	//左子树左遍历找到深度
	TreeNode* ptemp = root;//临时指针
	int ndepth = 1; //保存深度，从根节点算，所以是1
	int nresult = 0;//保存返回结果
	if (ptemp ==nullptr) //特殊情况，空节点
	{
		return 0;
	}
	while (ptemp->left !=nullptr)
	{
		ptemp=ptemp->left;
		ndepth++;
	}
	if (ndepth==1)
	{
		return 1;
	}

	nresult = int(pow(2, ndepth - 1)) - 1; //通过深度，先计算出除去最后一层部分的节点总数
	
	//通过二分法计算最顶层节点数。如果深度为k，那么顶层元素最多为pow(2,k-1)个，所以进行二分只需要k-1步

	ptemp = root;//初始化：还原根节点
	TreeNode* plocation = root;
	int ntemp=0;
	for (int i=ndepth-1;i>0;i--)//如果深度为k，那么顶层元素最多为pow(2,k-1)个，所以进行二分只需要k-1步,最后一步是确定俩边有没有节点
	{
		if (i==1)
		{
			if(plocation->right != nullptr) 
			{nresult+=2;}
			else if (plocation->left != nullptr)
			{nresult ++;}
			break;
		}
		else if(plocation->left != nullptr){
			ptemp = plocation->left;//此时节点已经发生变化
		}
		for (int j=1;j<i-1;j++)//从第1层到达第k-1层节点
		{
			ptemp = ptemp->right;
		}
		if (ptemp->right != nullptr)//如果k-1层的该节点右边有节点存在，说明最底层节点在右边，向右前进
		{
			plocation = plocation->right;
			nresult += int(pow(2, i - 1));
		}
		else { plocation = plocation->left; }//如果k-1层的节点右边没有节点，说明最底层节点在左边，向左前进
	}
	return nresult;
}

//暴力递归法
int countNodes(struct TreeNode* root) {
	if (!root)
	{
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}


//将数组转化为完全二叉树
void CreateTree(TreeNode **bt, int a[], int len, int index=0)
{
	//从数组a中创建二叉树，len为数组a的长度-1。index初始值为0。
	if (index > len-1) return;
	*bt = (TreeNode*)malloc(sizeof(TreeNode));
	(*bt)->val = a[index];
	(*bt)->left = nullptr;
	(*bt)->right = nullptr;
	CreateTree(&((*bt)->left), a, len, 2 * index + 1);
	CreateTree(&((*bt)->right), a, len, 2 * index + 2);
}

int main() {
	//int nNum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int nNum[] = { 1,2,3,4,5};
	int nNum[] = { 1,2,3,4,5,6,7 };
	//int nNum[] = { 1 };
	//int nNum[] = { 1,2,3 };
	TreeNode *root=nullptr;
	CreateTree(&root,nNum,7);
	//int n=countNodes(root);
	int n2=countNodes_SB2(root);
	printf("this tree has %d codes\n", n2);
	system("pause");
	return 0;

}