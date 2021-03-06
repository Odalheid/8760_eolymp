#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void dfs(const int &vertex_v, vector<pair<int, int>> &v, vector<bool> &used) {
	used[vertex_v - 1] = true;
	cout << vertex_v << ' ';
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].second == vertex_v && !used[v[i].first - 1]) dfs(v[i].first, v, used);
		else if (v[i].first == vertex_v && !used[v[i].second - 1]) dfs(v[i].second, v, used);
	}
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	vector <pair <int, int>> v(edges);
	vector<bool> used(vertices, 0);
	for (int i = 0; i < edges; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	int vertex_v;
	cin >> vertex_v;
	dfs(vertex_v, v, used);
	return 0;
}

