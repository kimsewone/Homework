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
int TotalSum(int* arr) //합계 구하기
{
	int tSum = 0;
	for (int i = 0; i < 5;++i)
	{
		tSum += arr[i];
	}
	return tSum;
}
float Averrage(int value)//평균 구하기
{
	float averagy = roundf(10.f*((float)value / 5.f))/10.f;
	return averagy;
}
void Sort(int* Arr, ESort type)//오름,내림차순정렬
{
	//Ascending 오름차순
	//descending 내림차순
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
	//출력
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
		cout << "숫자 5개 입력하세요" << endl;
		cin >> Input;//int형 숫자받기.
		
		if (Input / 10000 == 0)
		{
			//망가진 cin 복구=> 하지않으면 입력대기상태로 돌아기지않고 if문에 계속 들어온다.
			//int형으로 받고 있기때문에 입력에 문자열이 들어오면 cin이 고장난당.
			// string 변수로 받으면 위의 현상 나타나지 않음.
			cin.clear();
			cin.ignore(1000, '\n'); 
			cout << "잘못입력하였습니다." << endl;
		}
		else{
			str = to_string(Input);
			
			for (int i = 0; i < str.size();++i)
			{
				InputArr[i] = str[i] - '0';
			}

			Sort(InputArr, ESort::Ascending); //정렬

			int tSum = TotalSum(InputArr);//합계
		
			float average = Averrage(tSum);//평균

			//출력
			cout << InputArr[0] << InputArr[1] << InputArr[2] << InputArr[3] << InputArr[4]<< endl;
			cout << "TotalSum : " << tSum << endl;
			cout << fixed;
			cout.precision(1);
			cout << "average : " << average << endl;

		}
	}
	return 0;
}
