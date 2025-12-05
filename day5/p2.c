#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Range {
	long long start;
	long long end;
};

void solve(FILE *input) {
	long long ans = 0;
	char str[1024];
	struct Range ranges[1024];
	memset(ranges, 0x0, sizeof(ranges));
	int count=0;

	while(fgets(str, sizeof(str), input)) {
		if(strcmp(str, "\n") == 0)
			break;
		sscanf(str, "%lld-%lld", &ranges[count].start ,&ranges[count].end);
		count++;
	}

	for (int i=0; i<count-1; i++) {
		for (int j = i+1; j<count; j++) {
			if (ranges[i].start > ranges[j].start) {
				struct Range tmp = ranges[i];
				ranges[i] = ranges[j];
				ranges[j] = tmp;
			}
		}
	}

	struct Range merged[1024];
	int mcount=0;

	for(int i=0; i<count; i++) {
		if(mcount == 0 || merged[mcount-1].end < ranges[i].start) {
			merged[mcount++] = ranges[i];
		}
		else {
			if(merged[mcount-1].end < ranges[i].end) {
				merged[mcount-1].end = ranges[i].end;
			}
		}
	}

    for (int i=0; i<mcount; i++) {
		printf("range %lld-%lld, num ids: %lld\n",
				merged[i].start,
				merged[i].end,
				merged[i].end - merged[i].start + 1);

        ans += merged[i].end - merged[i].start + 1;
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
