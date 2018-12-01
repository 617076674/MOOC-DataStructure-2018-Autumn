#include<iostream>
#include<cstring>

char input[1000001], pattern[100001];
int N;

int main() {
	scanf("%s", input);
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s", pattern);
		char* index = strstr(input, pattern);
		if(index == NULL) {
			printf("Not Found\n");
		} else {
			printf("%s\n", index);
		}
	}
	return 0;
}

