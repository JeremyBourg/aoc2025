#include <stdio.h>

typedef struct {
	int x, y;
} Tile;

long long maxarea(long long max, Tile tile1, Tile tile2) {
	long long w = tile1.x - tile2.x + 1;
	long long h = tile1.y - tile2.y + 1;

	if(max > w * h)
		return max;
	else
		return w * h;
}

void solve(FILE *input) {
	char str[32];
	Tile tiles[1024] = {0};
	long long area = 0;

	int c=0;
	while(fgets(str, sizeof(str), input)) {
		sscanf(str, "%d,%d", &tiles[c].x, &tiles[c].y);
		c++;
	}

	for(int i=0; i<c; i++) {
		for(int j=0; j<c; j++) {
			area = maxarea(area, tiles[i], tiles[j]);
		}
	}
	printf("%lld\n", area);
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
