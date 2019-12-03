#include "functions.h"
int main(){

	char key[5], planeTest[21],*res;
	printf("Enter 4 letters key:");
	scanf("%s", key);
	printf("Enter plane text betwin 2-20 caracters:");
	scanf("%s", planeTest);
	res = door_encryption(planeTest, key);
	printf("the encripted word is: ");
	printf("%s\n", res);
	free(res);
	return 0;
}
