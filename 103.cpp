//103.二叉树的锯齿形层序遍历
//关键词：BFS广度优先遍历，queue队列
//author：659525
//2020年12月22日15:04:41

//BFS层序遍历的升级版，每次遍历的方向改变一下(这里使用双端队列控制方向)
/*
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3, 9, 20, null, null, 15, 7],
    3
   / \
  9  20
	/  \
   15   7
 返回锯齿形层序遍历如下：
[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
queue 队列操作 deque双端队列
queue 和 stack 有一些成员函数相似，但在一些情况下，工作方式有些不同：
front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
pop()：删除 queue 中的第一个元素。
size()：返回 queue 中元素的个数。
empty()：如果 queue 中没有元素的话，返回 true。
emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
swap(queue<T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。
 */

#include <queue>
#include <vector>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}

		queue<TreeNode*> nodeQueue; //用队列存放节点
		nodeQueue.push(root);
		bool isOrderLeft = true;//控制遍历方向，true:从左往右；false:从右至左

		while (!nodeQueue.empty()) { //当节点数为空时跳出循环
			deque<int> levelList;
			int size = nodeQueue.size();
			for (int i = 0; i < size; ++i) {
				auto node = nodeQueue.front();//取出队列的第一个元素
				nodeQueue.pop();//删除 queue 中的第一个元素
				if (isOrderLeft) {
					levelList.push_back(node->val); //取出节点的值存入节点存入末尾
				}
				else {
					levelList.push_front(node->val);//因为是锯齿型遍历，所以要用双端队列
				}
				if (node->left) {
					nodeQueue.push(node->left); //如果节点左边还有子节点，就把左节点传入队列
				}
				if (node->right) {
					nodeQueue.push(node->right); //如果节点右边还有子节点，就把右节点传入队列
				}
			}
			ans.emplace_back(vector<int>{levelList.begin(), levelList.end()}); //emplace_back比push_back更简洁
			isOrderLeft = !isOrderLeft;//锯齿遍历：改变遍历方向
		}

		return ans;
	}
	vector<vector<int>> BFS(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}

		queue<TreeNode*> nodeQueue; //用队列存放节点
		nodeQueue.push(root);
		while (!nodeQueue.empty()) { //当节点数为空时跳出循环
			deque<int> levelList;
			int size = nodeQueue.size();
			for (int i = 0; i < size; ++i) {
				auto node = nodeQueue.front();//取出队列的第一个元素
				nodeQueue.pop();//删除 queue 中的第一个元素
				levelList.push_back(node->val); //取出节点的值存入节点
				if (node->left) {
					nodeQueue.push(node->left); //如果节点左边还有子节点，就把左节点传入队列
				}
				if (node->right) {
					nodeQueue.push(node->right); //如果节点右边还有子节点，就把右节点传入队列
				}
			}
			ans.emplace_back(vector<int>{levelList.begin(), levelList.end()}); //emplace_back比push_back更简洁
		}

		return ans;
	}
	
};

void CreateTree(TreeNode **bt, int a[], int len, int index = 0)
{
	//从数组a中创建二叉树，len为数组a的长度-1。index初始值为0。
	if (index > len - 1) return;
	*bt = (TreeNode*)malloc(sizeof(TreeNode));
	(*bt)->val = a[index];
	(*bt)->left = nullptr;
	(*bt)->right = nullptr;
	CreateTree(&((*bt)->left), a, len, 2 * index + 1);
	CreateTree(&((*bt)->right), a, len, 2 * index + 2);
}
int main()
{
	TreeNode* root = NULL;
	int a[] = { 3,9,20,NULL,NULL,15,7 };
	CreateTree(&root, a, 7);
	Solution A;
	
	vector<vector<int>> ans=A.zigzagLevelOrder(root);//调用BFS升级版方法
	ans = A.BFS(root);//调用BFS广度优先搜索方法
}

		