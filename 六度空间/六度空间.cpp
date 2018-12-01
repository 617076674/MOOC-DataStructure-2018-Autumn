#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, count;
vector<int> graph[10001];
bool visited[10001];

void bfs(int nowVisit);
 
int main(){
	scanf("%d %d", &N, &M);
	int v1, v2;
	for(int i = 0; i < M; i++){
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for(int i = 1; i <= N; i++){
		count = 0;
		fill(visited + 1, visited + N + 1, false);
		bfs(i);
		printf("%d: %.2f%\n", i, count * 100.0 / N);
	}
	return 0;
}

void bfs(int nowVisit){
	queue<int> q;
	q.push(nowVisit);
	visited[nowVisit] = true;
	int level = 0;
	while(!q.empty()){
		int qSize = q.size();
		for(int i = 0; i < qSize; i++){
			int u = q.front();
			q.pop();
			for(int j = 0; j < graph[u].size(); j++){
				int v = graph[u][j];
				if(!visited[v]){
					q.push(v);
					visited[v] = true;
				}
			}
		}
		level++;
		count += qSize;
		if(level > 6){
			break;
		}
	}
}
