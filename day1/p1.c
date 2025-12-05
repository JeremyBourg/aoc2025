#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

void solve(FILE *input) {
	char s[100];
	int pos = 50;
	int count = 0;
	while(fgets(s, sizeof(s), input)) {
		int dir = RIGHT;
		char *m = s+1;

		if(s[0] == 'L')
			dir = LEFT;
		pos = (pos + (atoi(m) * dir)) % 100;
		if(pos == 0)
			count++;
	}
	printf("%d\n", count);
}

int main(int argc, char *argv[]) {
	FILE *fptr;

	fptr = fopen(argv[1], "r");

	if(argc != 2) {
		fprintf(stderr, "Usage: ./%s [filename]\n", argv[0]);
		return 0;
	}
	if(fptr == NULL) {
		perror("fopen");
		return 0;
	}

	solve(fptr);

	fclose(fptr);
	return 0;
}
