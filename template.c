#include <stdio.h>

void solve() {

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

	solve();

	fclose(fptr);
	return 0;
}
