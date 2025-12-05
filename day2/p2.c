#include <stdio.h>
#include <string.h>

long long find_invalid(long long min, long long max) {
	long long total = 0;
	char str[32];

	#pragma omp parallel for reduction(+:total) private(str)
	for (long long i = min; i <= max; i++) {
		memset(str, 0, sizeof(str));
		sprintf(str, "%lld", i);
		size_t len = strlen(str);

		char d[len*2+1];
		memset(d, 0, sizeof(d));

		strcat(d, str);
		strcat(d, str);
		char *new = d + 1;
		new[strlen(new)-1] = '\0';

		if(strstr(new, str) != NULL)
			total += i;
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
