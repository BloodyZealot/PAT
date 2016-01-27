#include <iostream>
#include <vector>
using namespace std;

int k;
int first, last;
int b, e;
vector<int> sub;
int sum;
int m;
bool pos;

int main()
{
	pos = false;
	sum = 0;
	b = e = 0;
	m = INT32_MIN;
	cin >> k;
	for (int i = 0, n; i < k; ++i)
	{
		cin >> n;
		if (n >= 0)
			pos = true;
		sub.push_back(n);
		sum += n;
		if (sum > m)
		{
			m = sum;
			first = b;
			last = e;
		}
		++e;
		if (sum <= 0)
		{
			++b;
			b = e;
			sum = 0;
		}
	}
	if (pos)
		cout << m << ' ' << sub[first] << ' ' << sub[last];
	else
		cout << 0 << ' ' << sub[0] << ' ' << sub[k - 1];
	system("pause");
	return 0;
}