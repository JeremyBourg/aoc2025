#include <stdio.h>
#include <string.h>

int check_adj(char grid[][1024], int y, int x) {
	int count = 0;

	if(grid[y-1][x-1]	== '@') count++;
	if(grid[y-1][x]		== '@') count++;
	if(grid[y-1][x+1]	== '@') count++;
	if(grid[y][x-1]		== '@') count++;
	if(grid[y][x+1]		== '@') count++;
	if(grid[y+1][x-1]	== '@') count++;
	if(grid[y+1][x]		== '@') count++;
	if(grid[y+1][x+1]	== '@') count++;

	return count;
}

void solve(FILE *input) {
	int ans=0;

	char grid[1024][1024];
	int y=0;

	while(fgets(grid[y++], sizeof(grid[0]), input))
		;

	for(int r=0;;r=0) {
		for(int i=0; i<y; i++) {
			for(int j=0; j<strlen(grid[i]); j++) {
				if(grid[i][j] == '@') {
					if(check_adj(grid, i, j) < 4) {
						ans++;
						grid[i][j] = 'x';
						r++;
					}
				}
			}
		}
		if(r==0)
			break;
	}

	printf("answer: %d\n", ans);
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
