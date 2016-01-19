#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct adj_city
{
	int name;
	int length;
};

struct city
{
	vector<adj_city> adj;
	int dist;
	int name;
	int team;
	bool known;
	bool operator < (city const& _A) const
	{
		if (dist > _A.dist) 
			return true;
		else return false;
	}
};

vector<city> c;
priority_queue<city> q;
vector<int>n_team;
int n, l, s, e;
int c1, c2, w12;
int team, path, minl;
bool findresult = false;
city v;


int main()
{
	cin >> n >> l >> s >> e;
	n_team.resize(n);
	c.resize(n);
	for (int i = 0; i < n; ++i)
	{
		v.dist = INT32_MAX;
		v.name = i;
		v.team = 0;
		v.known = false;
		c[i] = v;
		cin >> n_team[i];
	}
	for (int i = 0; i < l; ++i)
	{
		cin >> c1 >> c2 >> w12;
		adj_city a, b;
		a.name = c2;
		a.length = w12;
		b.name = c1;
		b.length = w12;
		c[c1].adj.push_back(a);
		c[c2].adj.push_back(b);
	}
	minl = 0;
	c[s].dist = 0;
	c[s].team = n_team[s];
	q.push(c[s]);
	while (!q.empty())
	{
		v = q.top();
		q.pop();
		c1 = v.name;
		if (findresult && v.dist > minl)
			continue;
		if (v.name == e)
		{
			if (!findresult || v.dist < minl)
			{
				findresult = true;
				path = 1;
				minl = v.dist;
				team = v.team;
			}
			else if (v.dist == minl)
			{
				++path;
				if (v.team > team)
					team = v.team;
			}
			continue;
		}
		c[c1].known = true;
		for (int i = 0; i < (int)v.adj.size(); ++i)
		{
			c2 = v.adj[i].name;
			w12 = v.adj[i].length;
			if (!c[c2].known)
			{
				c[c2].dist = c[c1].dist + w12;
				c[c2].team = c[c1].team + n_team[c2];
				q.push(c[c2]);
			}
		}
	}
	cout << path << " " << team;
	return 0;
}
