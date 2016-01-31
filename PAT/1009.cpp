#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	int k;
	int exp, e;
	float coe, c;
	map<int, float>::iterator it;
	map<int, float>::reverse_iterator rit;
	map<int, float>a, result;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> exp >> coe;
		a.insert(pair<int, float>(exp, coe));
	}
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> exp >> coe;
		for (rit = a.rbegin(); rit != a.rend(); ++rit)
		{
			e = exp + rit->first;
			c = coe * rit->second;
			it = result.find(e);
			if (it == result.end())
				result.insert(pair<int, float>(e, c));
			else
			{ 
				it->second += c;
				if (it->second == 0)
					result.erase(it);
			}
				
		}
	}
	cout << result.size() << ' ';
	cout << setprecision(1) << setiosflags(ios::fixed);
	rit = result.rbegin();
	for (unsigned i = 1; i < result.size(); ++i,++rit)
		cout << rit->first << ' ' << rit->second << ' ';
	cout << rit->first << ' ' << rit->second;
	system("pause");
	return 0;
}