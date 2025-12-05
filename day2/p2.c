#include <stdio.h>
#include <string.h>

long long find_invalid(long long min, long long max) {
	long long total = 0;
	char str[32];

	#pragma omp parallel for reduction(+:total) private(str)
	for (long long i = min; i <= max; i++) {
		sprintf(str, "%lld", i);
		size_t len = strlen(str);

		for (size_t sz = len/2; sz >= 1; sz--) {
			if (len % sz != 0)
				continue;

			char first[32];
			strncpy(first, str, sz);
			first[sz] = '\0';

			int yes=1;

			for (size_t j=sz; j<len; j += sz) {
				char new[32];
				strncpy(new, str + j, sz);
				new[sz] = '\0';

				if (strcmp(first, new) != 0) {
					yes=0;
					break;
				}
			}
			if(!yes) continue;

			total += i;
			break;
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
