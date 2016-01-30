#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, l, s, e;
int ls, le, lv;

vector<int> Team;

struct adj_list
{
	int city;
	int len;
};

struct node
{
	int city;
	int dist;
	int team;
	vector<adj_list> adj;
	bool closed;
};

bool operator < (const node &p1, const node & p2)
{
	return p1.dist > p2.dist;
}

priority_queue<node> opened;

bool findresult = false;
int minlen = 0;
int path, team;
node v;
vector<node> c;
int c1, c2, d;
adj_list a, b;

void slove()
{
	while (!opened.empty())
	{
		v = opened.top();
		opened.pop();
		c1 = v.city;
		if (findresult && v.dist > minlen)
			continue;
		if (v.city == e)
		{
			if (v.dist < minlen || !findresult)
			{
				findresult = true;
				path = 1;
				minlen = v.dist;
				team = v.team;
			}
			else if (v.dist == minlen)
			{
				++path;
				if (v.team > team)
					team = v.team;
			}
			continue;
		}
		c[c1].closed = true;
		for (unsigned i = 0; i < v.adj.size(); ++i)
		{
			c2 = c[c1].adj[i].city;
			d = c[c1].adj[i].len;
			if (!c[c2].closed)
			{
				c[c2].dist = v.dist + d;
				c[c2].team = v.team + Team[c2];
				opened.push(c[c2]);
			}
		}
	}
}

int main()
{
	cin >> n >> l >> s >> e;
	for (int i = 0; i < n; ++i)
	{
		v.dist = INT32_MAX;
		v.city = i;
		v.team = 0;
		v.closed = false;
		c.push_back(v);
		cin >> team;
		Team.push_back(team);
	}
	for (int i = 0; i < l; ++i)
	{
		cin >> ls >> le >> lv;
		a.city = le;
		b.city = ls;
		a.len = b.len = lv;
		c[ls].adj.push_back(a);
		c[le].adj.push_back(b);
	}
	c[s].dist = 0;;
	c[s].team = Team[s];
	opened.push(c[s]);
	slove();
	cout << path << ' ' << team;
	return 0;
}



