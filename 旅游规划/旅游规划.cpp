#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

struct node {
	int v, len, cost;
	node(int _v, int _len, int _cost) {
		v = _v;
		len = _len;
		cost = _cost;
	}
};

int N, M, S, D, d[500], countInq[500], INF = 1000000000, totalCost = INF;
vector<node> graph[500];
bool inq[500];
set<int> pre[500];
vector<int> tempPath; 

bool spfa(int s);
void dfs(int nowVisit);

int main() {
	scanf("%d %d %d %d", &N, &M, &S, &D);
	int v1, v2, len, cost;
	for(int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &v1, &v2, &len, &cost);
		graph[v1].push_back(node(v2, len, cost));
		graph[v2].push_back(node(v1, len, cost));
	}
	spfa(S);
	dfs(D);
	printf("%d %d\n", d[D], totalCost);
	return 0;
}

bool spfa(int s) {
	fill(d, d + N, INF);
	fill(countInq, countInq + N, 0);
	fill(inq, inq + N, false);
	queue<int> q;
	d[s] = 0;
	q.push(s);
	countInq[s]++;
	inq[s] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].v;
			int len = graph[u][i].len;
			if(len + d[u] < d[v]) {
				d[v] = len + d[u];
				pre[v].clear();
				pre[v].insert(u);
				if(!inq[v]) {
					q.push(v);
					inq[v] = true;
					countInq[v]++;
					if(countInq[v] > N - 1) {
						return false;
					}
				}
			} else if(len + d[u] == d[v]) {
				pre[v].insert(u);
				if(!inq[v]) {
					q.push(v);
					inq[v] = true;
					countInq[v]++;
					if(countInq[v] > N - 1) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
void dfs(int nowVisit){
	tempPath.push_back(nowVisit);
	if(nowVisit == S){
		int tempCost = 0;
		for(int i = tempPath.size() - 1; i > 0; i--){
			int now = tempPath[i];
			int next = tempPath[i - 1];
			for(int j = 0; j < graph[now].size(); j++){
				if(graph[now][j].v == next){
					tempCost += graph[now][j].cost;
					break;
				}
			}
		}
		if(tempCost < totalCost){
			totalCost = tempCost; 
		}
		tempPath.pop_back();
		return;
	}
	for(set<int>::iterator it = pre[nowVisit].begin(); it != pre[nowVisit].end(); it++){
		dfs(*it);
	}
	tempPath.pop_back();
}
