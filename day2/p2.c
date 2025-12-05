#include <stdio.h>
#include <string.h>

long long find_invalid(long long min, long long max) {
	long long total = 0;
	char str[32];

	for(long long i = min; i <= max; i++) {
		memset(str, 0, sizeof(str));
		sprintf(str, "%lld", i);
		size_t len = strlen(str);

		for(int slen = 1; slen <= len/2; slen++) {
			if(len % slen != 0)
				continue;

			int r = len/slen;
			char first[32];

			strncpy(first, str, slen);
			first[slen] = '\0';

			char s[32];
			memset(s, 0, sizeof(s));

			for(int j=0; j<r; j++)
				strcat(s, first);

			if(strcmp(s, str) == 0) {
				total += i;
				printf("Repeating: %lld\n", i);
				break;
			}
		}
	}
	return total;
}

void solve(FILE *input) {
	char s[10000];
	fgets(s, sizeof(s), input);
	long long count = 0;

	char *ptr = strtok(s, ",");
	while(ptr != NULL) {
		long long a, b;
		sscanf(ptr, "%lld-%lld", &a, &b);
		count += find_invalid(a, b);
		ptr = strtok(NULL, ",");
	}
	printf("\ntotal: %lld\n", count);
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
