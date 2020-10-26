#include <string.h>
#include <stdio.h>

char *hv_rgb2hex(int r, int g, int b)
{
	char hexnum[8];
	char hexbase[] = "0123456789abcdef";
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return ("Not a valid input.");
	hexnum[0] = '#';
	hexnum[1] = hexbase[r / 16];
	hexnum[2] = hexbase[r % 16];
	hexnum[3] = hexbase[g / 16];
	hexnum[4] = hexbase[g % 16];
	hexnum[5] = hexbase[b / 16];
	hexnum[6] = hexbase[b % 16];
	hexnum[7] = 0;
	return (strdup(hexnum));
}

int main ()
{
	printf("%s\n", hv_rgb2hex(30, 0, 23));
	return (0);
}
