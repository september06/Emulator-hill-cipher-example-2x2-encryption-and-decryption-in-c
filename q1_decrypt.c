#include "functions.h"

int main()
{
	char key[5], ctext[21],*res;
	printf("Enter 4 letters key:  ");
	scanf("%s", key);
	printf("Enter ciphet text to decript betwin 2-20 caracters:  ");
	scanf("%s", ctext);
	res = door_decryption(ctext, key);
	printf("***************************\n");
	printf("the plan text is: %s \n", res);
	printf("***************************\n");
	free(res);
	return 0;
}
