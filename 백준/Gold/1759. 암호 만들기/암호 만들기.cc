#include <stdio.h>

void dfs(int final, int level, int tlevel, int a, int b, int index);
char arr[20], arr2[20];

int main () {
	int r, t, temp;

	scanf("%d %d", &r, &t);
	for(int i = 0; i < t; i++) {
		scanf(" %c", &arr[i]);
	}
	for(int i = 0; i < t - 1; i++) {
		for(int j = 0; j < t - i - 1; j++) {
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	dfs(r, 0, t, 0, 0, 0);
}

void dfs(int final, int level, int tlevel, int a, int b, int index) {
	if(level == final) {
		if(a >= 1 && a <= final - 2) {
			for(int i = 0; i < final; i++) {
			printf("%c", arr2[i]);
		}
		printf("\n");
		}
		return;
	}
	for(int i = index; i < tlevel; i++) {
		arr2[level]=arr[i];
		if (arr2[level] == 'a' || arr2[level] == 'e' || arr2[level] == 'i' || arr2[level] == 'o' || arr2[level] == 'u') {
			dfs(final,level+1,tlevel,a+1,b,i + 1);
		}
		else {
			dfs(final,level+1,tlevel,a,b+1,i + 1);
		}
	}
}
