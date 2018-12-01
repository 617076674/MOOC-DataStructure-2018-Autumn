#include<iostream>
#include<vector>

using namespace std;

struct node{
	int v, price;
	node(int _v, int _price){
		v = _v;
		price = _price;
	}
};

int N, M, d[1001], INF = 1000000000;
vector<node> graph[1001];
bool visited[1001];

int prim(); 

int main(){
	scanf("%d %d", &N, &M);
	fill(visited + 1, visited + N + 1, false);
	fill(d + 1, d + N + 1, INF);
	int v1, v2, price;
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &v1, &v2, &price);
		graph[v1].push_back(node(v2, price));
		graph[v2].push_back(node(v1, price));
	}
	int result = prim();
	printf("%d\n", result);
	return 0;
}

int prim(){
	d[1] = 0;
	int ans = 0;
	for(int i = 0; i < N ; i++){
		int u = -1, min = INF;
		for(int j = 1; j <= N; j++){
			if(!visited[j] && d[j] < min){
				u = j;
				min = d[j];
			}
		}
		if(u == -1){
			return -1;
		}
		d[u] = min;
		visited[u] = true;
		ans += d[u];
		for(int j = 0; j < graph[u].size(); j++){
			int v = graph[u][j].v;
			int len = graph[u][j].price;
			if(!visited[v] && len < d[v]){
				d[v] = len;
			}
		}
	}
	return ans;
}
