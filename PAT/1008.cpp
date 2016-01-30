#include <iostream>
using namespace std;

int main()
{
	int n;
	int now, next;
	int time;
	time = 0;
	cin >> n;
	now = 0;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> next;
		if (next > now)
			time += (next - now) * 6;
		else if (next < now)
			time += (now - next) * 4;
		now = next;
	}
	time += n * 5;
	cout << time;
	system("pause");
	return 0;
}