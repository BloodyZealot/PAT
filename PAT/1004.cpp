#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

map<int, vector<int>> tree;
int n, m, k;
int parent, child;
int max_depth = 1;
string s_parent, s_child;
vector<int> children;
vector<int> nochild;

void DFS(int id,int depth)
{
	if (tree.at(id).size() == 0)
	{
		++nochild[depth];
		return;
	}
	++depth;
	if (max_depth < depth)
		max_depth = depth;
	for (unsigned i = 0; i < tree.at(id).size(); ++i)
		DFS(tree.at(id).at(i), depth);
}

int main()
{
	cin >> n >> m;
	nochild.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		tree.insert(pair<int, vector<int>>(i, children));
	for (int i = 1; i <= m; ++i)
	{
		cin >> parent >> k;
		for (int j = 1; j <= k; ++j)
		{
			cin >> child;
			tree.at(parent).push_back(child);
		}
	}
	DFS(1, 1);
	for (int i = 1; i < max_depth; ++i)
		cout << nochild[i] << ' ';
	cout << nochild[max_depth];
	return 0;
}