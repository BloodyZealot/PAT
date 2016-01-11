#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
	map<int, float> result;
	map<int, float>::reverse_iterator it;
	int k, i, exp;
	float coe;

	cin >> k;
	for (i = 0; i < k; i++)
	{
		cin >> exp >> coe;
		result[exp] = coe;
	}
	cin >> k;
	for (i = 0; i < k; i++)
	{
		cin >> exp >> coe;
		result[exp] += coe;
		if (result.find(exp)->second == 0)
			result.erase(exp);
	}
	cout << result.size();
	for (it = result.rbegin(); it != result.rend(); ++it)
	{
		cout << fixed << setprecision(1);
		cout << " " << it->first << " " << it->second;
	}
	return 0;
}