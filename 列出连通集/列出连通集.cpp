#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, E;
vector<int> graph[10], oneTimeTravel;
bool visited[10];

void dfs(int nowVisit);
void bfs(int nowVisit);

int main() {
	scanf("%d %d", &N, &E);
	int v1, v2;
	for(int i = 0; i < E; i++) {
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for(int i = 0; i < N; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	fill(visited, visited + N, false);
	for(int i = 0; i < N; i++) {
		if(!visited[i]) {
			oneTimeTravel.clear();
			dfs(i);
			printf("{ ");
			for(int i = 0; i < oneTimeTravel.size(); i++) {
				printf("%d ", oneTimeTravel[i]);
			}
			printf("}\n");
		}
	}
	fill(visited, visited + N, false);
	for(int i = 0; i < N; i++) {
		if(!visited[i]) {
			oneTimeTravel.clear();
			bfs(i);
			printf("{ ");
			for(int i = 0; i < oneTimeTravel.size(); i++) {
				printf("%d ", oneTimeTravel[i]);
			}
			printf("}\n");
		}
	}
}

void dfs(int nowVisit){
	visited[nowVisit] = true;
	oneTimeTravel.push_back(nowVisit);
	for(int i = 0; i < graph[nowVisit].size(); i++){
		int v = graph[nowVisit][i];
		if(!visited[v]){
			dfs(v);
		}
	}
}

void bfs(int nowVisit){
	queue<int> q;
	q.push(nowVisit);
	visited[nowVisit] = true;
	while(!q.empty()){
		int u = q.front();
		oneTimeTravel.push_back(u);
		q.pop();
		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i];
			if(!visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
}
