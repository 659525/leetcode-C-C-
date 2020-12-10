//860.柠檬水找零
//关键词：简单贪心模拟
//author：659525



bool lemonadeChange(int* bills, int billsSize) {
	//需要一个数组来维护零钱数组表示5，10，20元的数量
	int list[3] = {};
	//遍历顾客数组，如果没有零钱返回false
	for (int i = 0; i < billsSize; i++) {
		switch (bills[i] / 5) {
		case 1://5元时，存入list[0];
		{list[0]++; break;  }
		case 2://10元时，判断有无5元(list[0]大于0)
		{
			if (list[0]) {
				list[0]--;
				list[1]++;
				break;
			}
			else { return false; }
		}
		case 4://20元时，先看有没有10元找，没有再都用5元找
		{
			if (list[0] && list[1]) {
				list[0]--;
				list[1]--;
				list[2]++;

			}else if (list[0]>=3)
			{
				list[0] -= 3;
				list[2]++;
			}	
			else {
				return false;
			}
			break;
		}
		}
	}
	return true;
}

int main()
{
	int a[] = {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};//20
	lemonadeChange(a, (sizeof(a))/sizeof(int));
	return 0;

	
	
}