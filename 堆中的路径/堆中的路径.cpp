#include<iostream>
#include<vector>

using namespace std;

int N, M, heap[1000], index = 0;

void insert(int num);
void upAdjust(int low, int high);
void printFather(int num);

int main() {
	scanf("%d %d", &N, &M);
	int num;
	for(int i = 0; i < N; i++) {
		scanf("%d", &num);
		insert(num);
	}
	for(int i = 0; i < N; i++) {
		printf("%d ", heap[i]);
	}
	for(int i = 0; i < M; i++) {
		scanf("%d", &num);
		printFather(num - 1);
	}
	return 0;
}

void insert(int num) {
	heap[index] = num;
	upAdjust(0, index);
	index++;
}

void upAdjust(int low, int high) {
	int i = high, j = (high - 1) / 2;
	while(j >= low) {
		if(heap[j] > heap[i]) {
			swap(heap[i], heap[j]);
			i = j;
			j = (i - 1) / 2;
		} else {
			break;
		}
	}
}

void printFather(int num) {
	vector<int> fathers;
	while(num >= 0) {
		fathers.push_back(heap[num]);
		if(num == 0) {
			break;
		}
		num = (num - 1) / 2;
	}
	for(int i = 0; i < fathers.size(); i++) {
		printf("%d", fathers[i]);
		if(i != fathers.size() - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
}
