#include <stdio.h>
#include <string.h>

long long find_invalid(long long min, long long max) {
	long long total = 0;

	char t1[32];
	char t2[32];
	sprintf(t1, "%lld", min);
	sprintf(t2, "%lld", max);
	if(strlen(t1) & 1 && strlen(t2) & 1)
		return 0;

	char str[32];
	for(long long i = min; i <= max; i++) {
		sprintf(str, "%lld", i);
		if(strlen(str) & 1)
			continue;
		size_t hlen = strlen(str)/2;
		char first[32];
		char *second = str + hlen;

		strncpy(first, str, hlen);
		first[hlen] = '\0';
		if(strcmp(first, second) == 0) {
			total += i;
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
