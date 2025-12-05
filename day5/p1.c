#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solve(FILE *input) {
	long long ans = 0;
	char ranges[1024][100];
	long long irange[1024][2];
	char id[1024];
	int y=0;

	while(fgets(ranges[y], sizeof(ranges[y]), input)) {
		if(strcmp(ranges[y], "\n") == 0)
			break;
		long long num1, num2;
		sscanf(ranges[y], "%lld-%lld", &num1, &num2);
		irange[y][0] = num1;
		irange[y][1] = num2;
		y++;
	}

	while(fgets(id, sizeof(id), input)) {
		char *endptr;
		long long iid = strtoll(id, &endptr, 10);
		for(int i=0; i<y; i++) {
			if(iid < irange[i][0] || iid > irange[i][1]) {
				continue;
			}
			printf("%lld: passed in range %lld-%lld\n", iid, irange[i][0], irange[i][1]);
			ans++;
			break;
		}
	}

	printf("total: %lld\n", ans);
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
