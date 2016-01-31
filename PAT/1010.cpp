#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long long to_dec(string n, long long radix)
{
	long long dec = 0;
	long long pow = 1;
	int bit;
	for (unsigned i = 0, j = n.size() - 1; i < n.size(); ++i, --j)
	{
		if (n[j] >= '0' && n[j] <= '9')
			bit = n[j] - '0';
		else
			bit = n[j] - 'a' + 10;
		dec = dec + bit * pow;
		pow *= radix;
	}
	return dec;
}

long long get_radix(string n, long long dec1)
{
	int start = 0;
	int bit;
	long long dec2, pow;
	long long low, high, mid;
	for (unsigned i = 0; i < n.size(); ++i)
	{
		if (n[i] >= '0' && n[i] <= '9')
			bit = n[i] - '0';
		else
			bit = n[i] - 'a' + 10;
		if (bit > start)
			start = bit + 1;
	}
	low = start; 
	high = dec1 + 1;
	while (low <= high)
	{ 
		mid = (low + high) / 2;
		dec2 = 0;
		pow = 1;
		for (unsigned i = 0, j = n.size() - 1; i < n.size(); ++i, --j)
		{
			if (n[j] >= '0' && n[j] <= '9')
				bit = n[j] - '0';
			else
				bit = n[j] - 'a' + 10;
			dec2 = dec2 + bit * pow;
			if (dec2 > dec1 || dec2 < 0)
				break;
			pow *= mid;
		}
		if (dec2 == dec1)
			return mid;
		else if (dec2 > dec1 || dec2 < 0)
		{
			high = mid - 1;
			continue;
		}
		low = mid + 1;
	}
	return 0;
}

int main()
{
	string n1, n2;
	int tag;
	long long radix, result;
	long long dec;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 1)
	{
		dec = to_dec(n1, radix);
		result = get_radix(n2, dec);
	}
	else 
	{
		dec = to_dec(n2, radix);
		result = get_radix(n1, dec);
	}
	if (result == 0)
		cout << "Impossible";
	else
		cout << result;
	system("pause");
	return 0;
}