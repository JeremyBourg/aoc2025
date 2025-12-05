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
		int mov = atoi(m);

		while(mov > 100) {
			count++;
			mov -= 100;
		}
		mov *= dir;
		if(pos + mov < 0 && pos != 0) {
			count++;
		}
		else if(pos + mov > 100) {
			count++;
		}

		pos += mov;
		pos %= 100;
		if(pos == 0) {
			count++;
		}
		if(pos < 0)
			pos += 100;
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
		fprintf(stderr, "File provided doesnt exist\n");
		return 0;
	}

	solve(fptr);

	fclose(fptr);
	return 0;
}
