#include <stdio.h>
#include <string.h>

#define NUMBAT 2

unsigned int top(char* str, int start, int end) {
	int hidx=start;

	for(int i=start; i<end-1; i++) {
		int r = str[i] - '0';
		if(r > str[hidx] - '0') {
			hidx = i;
		}
	}

	return hidx;
}

void solve(FILE *input) {
	char str[1024];
	long long total=0;

	while(fgets(str, sizeof(str), input)) {;
		long long ans = 0;
		int hidx = -1;

		int t=NUMBAT;
		while(t--) {
			hidx = top(str, hidx+1, strlen(str) - t);
			ans += str[hidx] - '0';
			if(t > 0)
				ans*=10;
		}
		total += ans;

	}
	printf("total: %lld\n", total);
}

int main(int argc, char *argv[]) {
	FILE *fptr;

	fptr = fopen(argv[1], "r");

	if(argc != 2) {
		fprintf(stderr, "Usage: ./%s [filename]\n", argv[0]);
		return 0;
	}
	if(fptr == NULL) {
		fprintf(stderr, "File provided doesnt exist\n");
		return 0;
	}

	solve(fptr);

	fclose(fptr);
	return 0;
}
