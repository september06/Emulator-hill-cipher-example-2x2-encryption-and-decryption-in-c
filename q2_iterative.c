#include "functions.h";
int main() {
	char key[5], planeTest[21] ,*res,p[21];
	int i = 0;
	printf("Enter 4 letters key:");
	scanf("%s", key);
	printf("Enter plane text betwin 2-20 caracters:");
	scanf("%s", planeTest);
	res = door_encryption(planeTest, key);
	strcpy(p, planeTest);

	do {
		res = door_encryption(p, key);
		strcpy(p,res);
		printf("the encripted word is: ");
		printf("%s\n", p);
		i++;
	} while (strcmp(p, planeTest) != 0);
		printf(" \n ==> num of iterations:  %d  \n", i);
		printf(" -----------------------------------------  \n", i);
	free(res);
	return 0;
}

