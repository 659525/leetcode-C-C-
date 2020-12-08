//767.重构字符串
//关键词：map转vector排序，pair用法，插入重构
//author：659525

//map排序:一般转化为vector再排序,map可以按key排序，value排序只能转vector
//pair用法：pair<>将两个数据结构整合到一起

/*
给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

若可行，输出任意可行的结果。若不可行，返回空字符串。
示例 1 :

输入: S = "aab"
	输出 : "aba"
	示例 2 :

	输入 : S = "aaab"
	输出 : ""
	注意 :

	S 只包含小写字母并且长度在[1, 500]区间内。

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/reorganize-string
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/




#include<string>	//string
#include<algorithm> //sort
#include<map>       //map
#include<vector>    //vector
#include<iostream>
using namespace std;

//typedef pair<const char, int> PAIR;
class Solution {
public:
	static bool cmp(const pair< char, int> &P1, const pair< char, int> &P2) //必须要加static关键字，不然会报错C3867
	{
		return P1.second > P2.second;
	}
	struct myclass {
		bool operator() (pair< char, int> P1, pair< char, int> P2)
		{
			return P1.second > P2.second;//按second降序排序，注意是PAIR类型，需要.firt和.second。这个和map类似
		}
	} mycmp;
	string reorganizeString(string S ,int level=2) {
		string ret = "";//返回的string类型
		//检验是否能重构该字符串
		int nlen = S.size();
		if (nlen<level+1)
		{
			return ret;//先看长度符不符合要求，总不能长度为2的字符串ab让我重构成间隔3的字符串吧
		}
		map<const char, int>maptable;//存储信息于map<字符，出现次数>中
		for (int i=0;i< nlen;i++)
		{
			if (maptable[S[i]])
			{
				maptable[S[i]]++;
			}else
			{
				maptable[S[i]]= 1;
			}		
			if (maptable[S[i]] >(nlen+1)/level)
			{
				return ret;
			}
		}
		vector<pair< char, int>>sortvector;//将map按存如vector用于排序（按出现字符的降序排序）
		for (map< char, int>::iterator it=maptable.begin();it!= maptable.end();it++)
		{
			sortvector.push_back(*it);//map存入vector，不能用*it.first访问，只能用sortvector[i].first
		}
		sort(sortvector.begin(), sortvector.end(),cmp);//调用自己实现的静态方法cmp开始排序
		//sort(sortvector.begin(), sortvector.end(), mycmp);//排序方法2
		//遍历排序好的vector
		/*
		//打印输出测试排序是否成功
		for (int i=0;i<sortvector.size();i++)
		{
			printf("%c %d\n",sortvector[i].first,sortvector[i].second);
		}
		*/
		
		//开始重构字符串,重构次数为S.size();
		ret = S;//ret长度肯定是和S一样的，这里赋值方便重构替换
		int j = 0;//j=0表示次数最高的字符，当该字符的value取尽，j+1，取次数第二高的字符，以此类推
		//level是几就分成几组插入，每轮是S.size()/level,比如level=3,8个，每轮就是 3 3 2
		for (int i=0;i<level;i++)
		{
			for (int t=0; i + level * t < S.size();t++)//超过S长度就不插入了
			{
				ret[i + level * t] = sortvector[j].first;
				sortvector[j].second--;//开始排序
				if (!sortvector[j].second)
				{
					j++;
				}
			}
		}
		return ret;		
	}
};

int main() {
	//测试用例
	Solution A;
	string s1 = "xxyyyzzzz";
	string s2 = "xxxyyz";
	string s3 = "aaazxxyy";

	string Teststring;
	Teststring=A.reorganizeString(s1);
	printf(Teststring.c_str());
	Teststring=A.reorganizeString(s3,3);
	printf(Teststring.c_str());

	return 0;

}

/*
1，pair的应用

pair是将2个数据组合成一组数据，当需要这样的需求时就可以使用pair，如stl中的map就是将key和value放在一起来保存。
另一个应用是，当一个函数需要返回2个数据的时候，可以选择pair。
pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量。


pair<T1, T2> p1;            //创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
pair<T1, T2> p1(v1, v2);    //创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
make_pair(v1, v2);          // 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
p1 < p2;                    // 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
p1 == p2；                  // 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
p1.first;                   // 返回对象p1中名为first的公有数据成员
p1.second;                 // 返回对象p1中名为second的公有数据成员

2，pair的创建和初始化
pair包含两个数值，与容器一样，pair也是一种模板类型。但是又与之前介绍的容器不同；
在创建pair对象时，必须提供两个类型名，两个对应的类型名的类型不必相同

pair<string, string> anon;        // 创建一个空对象anon，两个元素类型都是string
pair<string, int> word_count;     // 创建一个空对象 word_count, 两个元素类型分别是string和int类型
pair<string, vector<int> > line;  // 创建一个空对象line，两个元素类型分别是string和vector类型
当然也可以在定义时进行成员初始化：

pair<string, string> author("James", "Joy");    // 创建一个author对象，两个元素类型分别为string类型，并默认初始值为James和Joy。
pair<string, int> name_age("Tom", 18);
pair<string, int> name_age2(name_age);    // 拷贝构造初始化
pair类型的使用相当的繁琐，如果定义多个相同的pair类型对象，可以使用typedef简化声明：

typedef pair<string, string> Author;
Author proust("March", "Proust");
Author Joy("James", "Joy");
变量间赋值：

pair<int, double> p1(1, 1.2);
pair<int, double> p2 = p1;     // copy construction to initialize object
pair<int, double> p3；
p3 = p1;    // operator =
3，pair对象的操作

访问两个元素操作可以通过first和sencond访问：

pair<int, double> p1;

p1.first = 1;

p1.second = 2.5;

cout << p1.first << ' ' << p1.second << endl;

//输出结果：1 2.5

*/