//860.����ˮ����
//�ؼ��ʣ���̰��ģ��
//author��659525



bool lemonadeChange(int* bills, int billsSize) {
	//��Ҫһ��������ά����Ǯ�����ʾ5��10��20Ԫ������
	int list[3] = {};
	//�����˿����飬���û����Ǯ����false
	for (int i = 0; i < billsSize; i++) {
		switch (bills[i] / 5) {
		case 1://5Ԫʱ������list[0];
		{list[0]++; break;  }
		case 2://10Ԫʱ���ж�����5Ԫ(list[0]����0)
		{
			if (list[0]) {
				list[0]--;
				list[1]++;
				break;
			}
			else { return false; }
		}
		case 4://20Ԫʱ���ȿ���û��10Ԫ�ң�û���ٶ���5Ԫ��
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