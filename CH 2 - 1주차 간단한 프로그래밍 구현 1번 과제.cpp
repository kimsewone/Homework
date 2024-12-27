#include <iostream>
#include <string>
#include <list>
#include <cmath>
using namespace std;

enum ESort
{
	Ascending,
	descending
};
int TotalSum(int* arr) //�հ� ���ϱ�
{
	int tSum = 0;
	for (int i = 0; i < 5;++i)
	{
		tSum += arr[i];
	}
	return tSum;
}
float Averrage(int value)//��� ���ϱ�
{
	float averagy = roundf(10.f*((float)value / 5.f))/10.f;
	return averagy;
}
void Sort(int* Arr, ESort type)//����,������������
{
	//Ascending ��������
	//descending ��������
	//int aa[] = { 2,4,1,8,6 };
	int temp = 0;
	if (type == ESort::Ascending) {
		for (int j = 0; j < 5;++j)
		{
			for (int i = 0; i < 5;++i)
			{
				if (Arr[j] > Arr[i]) {
					temp = Arr[j];
					Arr[j] = Arr[i];
					Arr[i] = temp;
				}
			}
		}
	}else{
		for (int j = 0; j < 5;++j)
		{
			for (int i = 0; i < 5;++i)
			{
				if (Arr[j] < Arr[i]) {
					temp = Arr[j];
					Arr[j] = Arr[i];
					Arr[i] = temp;
				}
			}
		}
	}
	//���
	for (int j = 0; j < 5;++j) {
		cout << Arr[j] << '\n';
	}
}
int main()
{
	int Input = 0;
	string str = "";
	int randCharacter = 0;
	int randArr[3] = { 0,1,2 };

	int InputArr[5] = { 0 };

	while (true) {
		cout << "���� 5�� �Է��ϼ���" << endl;
		cin >> Input;//int�� ���ڹޱ�.
		
		if (Input / 10000 == 0)
		{
			//������ cin ����=> ���������� �Է´����·� ���Ʊ����ʰ� if���� ��� ���´�.
			//int������ �ް� �ֱ⶧���� �Է¿� ���ڿ��� ������ cin�� ���峭��.
			// string ������ ������ ���� ���� ��Ÿ���� ����.
			cin.clear();
			cin.ignore(1000, '\n'); 
			cout << "�߸��Է��Ͽ����ϴ�." << endl;
		}
		else{
			str = to_string(Input);
			
			for (int i = 0; i < str.size();++i)
			{
				InputArr[i] = str[i] - '0';
			}

			Sort(InputArr, ESort::Ascending); //����

			int tSum = TotalSum(InputArr);//�հ�
		
			float average = Averrage(tSum);//���

			//���
			cout << InputArr[0] << InputArr[1] << InputArr[2] << InputArr[3] << InputArr[4]<< endl;
			cout << "TotalSum : " << tSum << endl;
			cout << fixed;
			cout.precision(1);
			cout << "average : " << average << endl;

		}
	}
	return 0;
}
