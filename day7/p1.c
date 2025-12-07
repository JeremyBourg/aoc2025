#include <stdio.h>
#include <string.h>

void solve(FILE *input) {
	char str[1024];
	int rays[1024];
	int pos = -1;
	int count = 0;
	while(fgets(str, sizeof(str), input)) {
		for(int i=0; i<strlen(str); i++) {
			if(str[i] == 'S')
				rays[i] = 1;
			if(str[i] == '^' && rays[i] == 1) {
				rays[i] = 0;
				count++;

				if(i < strlen(str) - 1)
					rays[i+1] = 1;
				if(i > 0)
					rays[i-1] = 1;
			}
		}
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
