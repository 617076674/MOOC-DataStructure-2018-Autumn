#include<iostream>
#include<cstring>

char input[1000001], pattern[100001];
int N, next[100001];

void getNext(char s[], int len);
int KMP(char input[], char pattern[]); 

int main() {
	scanf("%s", input);
	scanf("%d", &N);
	for(int k = 0; k < N; k++) {
		scanf("%s", pattern);
		int index = KMP(input, pattern);
		if(index == -1){
			printf("Not Found\n");
		}else{
			printf("%s\n", input + index);
		}
	}
	return 0;
}

void getNext(char s[], int len){
	int j = -1;
	next[0] = -1;
	for(int i = 1; i < len; i++){
		while(j != -1 && s[j + 1] != s[i]){
			j = next[j];
		}
		if(s[i] == s[j + 1]){
			j++;
		}
		next[i] = j;
	} 
}

int KMP(char input[], char pattern[]){
	int inputLen = strlen(input);
	int patternLen = strlen(pattern);
	getNext(pattern, patternLen);
	int j = -1;
	for(int i = 0; i < inputLen; i++){
		while(j != -1 && input[i] != pattern[j + 1]){
			j = next[j];
		}
		if(input[i] == pattern[j + 1]){
			j++;
		}
		if(j == patternLen - 1){
			return i - patternLen + 1;
		}
	}
	return -1;
}
