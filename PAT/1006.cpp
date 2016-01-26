#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct sign
{
	string id;
	string sign_in;
	string sign_out;
};

int m;
string id1, id2;
vector<sign> record;
stringstream ss;

void fun(vector<sign> record, string &id1, string &id2)
{
	int unlock, lock;
	int first, last;
	first = 23 * 60 * 60 + 59 * 60 + 59;
	last = 0;
	for (unsigned i = 0; i < record.size(); ++i)
	{
		int in, out;
		int h, m, s;
		ss << record[i].sign_in.substr(0, 2);
		ss >> h;
		ss.clear();
		ss << record[i].sign_in.substr(3, 2);
		ss >> m;
		ss.clear();
		ss << record[i].sign_in.substr(6, 2);
		ss >> s;
		ss.clear();
		ss.str("");
		in = h * 60 * 60 + m * 60 + s;
		if (in <= first)
		{
			first = in;
			unlock = i;
		}
		ss << record[i].sign_out.substr(0, 2);
		ss >> h;
		ss.clear();
		ss << record[i].sign_out.substr(3, 2);
		ss >> m;
		ss.clear();
		ss << record[i].sign_out.substr(6, 2);
		ss >> s;
		ss.clear();
		ss.str("");
		out = h * 60 * 60 + m * 60 + s;
		if (out >= last)
		{
			last = out;
			lock = i;
		}
	}
	id1 = record[unlock].id;
	id2 = record[lock].id;
}

int main()
{
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string id, sign_in, sign_out;
		sign tmp;
		cin >> id >> sign_in >> sign_out;
		tmp.id = id;
		tmp.sign_in = sign_in;
		tmp.sign_out = sign_out;
		record.push_back(tmp);
	}
	fun(record, id1, id2);
	cout << id1 << ' ' << id2;
	return 0;
}