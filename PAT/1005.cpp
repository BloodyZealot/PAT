#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

string num;
int result;
stack<int> bit;

int sum(string num)
{
	int result = 0;
	int number;
	for (unsigned i = 0; i < num.size(); ++i)
	{
		stringstream ss;
		ss << num[i];
		ss >> number;
		result += number;
	}
	return result;
}

void print(int num)
{
	if (num == 0)
	{
		cout << "zero";
		return;
	}
	while (num)
	{
		bit.push(num % 10);
		num /= 10;
	}
	unsigned size = bit.size();
	for (unsigned i = 0; i < size; ++i)
	{
		num = bit.top();
		bit.pop();
		switch (num)
		{
		case 0:cout << "zero"; break;
		case 1:cout << "one"; break;
		case 2:cout << "two"; break;
		case 3:cout << "three"; break;
		case 4:cout << "four"; break;
		case 5:cout << "five"; break;
		case 6:cout << "six"; break;
		case 7:cout << "seven"; break;
		case 8:cout << "eight"; break;
		case 9:cout << "nine"; break;
		}
		if (i + 1 != size)
			cout << " ";
	}
}

int main()
{
	cin >> num;
	result = sum(num);
	print(result);
	return 0;
}