#include "functions.h"
int modulo(int num,int modNum)
{
	return (num % modNum + modNum) % modNum;
}

char* door_encryption(char* ptext, char* key)
{
	int key_mateix[2][2], temp1[2][2], temp2[2][2], endMat[10][2], encripted[10][2];
	int k = 0;
	char* p = ptext, * ptr;
	int ptLen, index, i, j, flag = 0;
	//int **endMat, **encripted;
	tern_string_text_in_matrix(key, key_mateix, 2, 2);
	multiplay_any_2_matrix(key_mateix, key_mateix, 2, 2, 2, 2, temp1);
	multiplay_any_2_matrix(temp1, key_mateix, 2, 2, 2, 2, temp2);
	matrix_scalar_mul(key_mateix, 2, temp1, 2, 2);
	add_matrixes(temp1, temp2, key_mateix, 2, 2);
	ptLen = strlen(ptext);

	if (ptLen % 2 != 0)
	{
		flag = 1;
		ptLen += 1;
		ptr = (char*)malloc(ptLen);
		if (ptr == NULL) {
			printf("allocation Error");
			exit(1);
		}
		strcpy_s(ptr,ptLen, ptext);
		ptLen /= 2;
	}
	else
	{		
		ptr = (char*)malloc(strlen(ptext)+1);
		strcpy(ptr, ptext);
		ptLen /= 2;
;
	}
	tern_string_text_in_matrix(ptr, endMat, (ptLen), 2);
	if (flag) endMat[ptLen-1][1] = 'a'-'a';
	multiplay_any_2_matrix(endMat, key_mateix, ptLen, 2, 2, 2, encripted);
	applay_modolo(encripted, 26, ptLen, 2);

	for (i = 0; i < ptLen; i++)
	{
		for (j = 0; j < 2; j++)
		{
			ptr[k] = (char)(encripted[i][j] + 'a');
			k++;
		}
	}
	if (flag == 1) {
		ptr[(ptLen * 2 - 1)] = '\0';
	}
	else {
		ptr[(ptLen * 2 +1)] = '\0';
	}
	

	return ptr;
}


void matrix_scalar_mul(int mat[][2], int scalar, int res[][2], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			res[i][j] = scalar * mat[i][j];
		}
	}
}

void tern_string_text_in_matrix(char* text, int mat[][2], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mat[i][j] = *text - 'a';
			text++;
		}
	}
}

void multiplay_any_2_matrix(int mat1[][2], int mat2[][2], int m1, int n1, int m2, int n2, int res[][2])
{
	int i, j, k;
	if (n1 != m2)
	{
		printf("not possibal to multypaly if n1!=m2\n");
		return;
	}

	for (i = 0; i < m1; i++)
	{
		for (j = 0; j < n2; j++) {
			res[i][j] = 0;
		}

	}

	for (i = 0; i < m1; ++i)
	{
		for (j = 0; j < n2; ++j)
		{
			for (k = 0; k < n1; ++k)
			{
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

}


void print_matrix(int m, int n, int mat[][2])
{
	int i, j;
	printf("\nOutput Matrix:\n");
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			printf("%d  ", mat[i][j]);
			if (j == n - 1)
				printf("\n\n");
		}
	}
}

void add_matrixes(int mat1[][2], int mat2[][2], int res[][2], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			res[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

void applay_modolo(int a[][2], int num, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			a[i][j] = modulo(a[i][j],num) ;
		}
	}
}


void calc_invertible_matrix(int mat[][2], int rows, int cols,int res[][2])
{
	int i, j;
	int det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]), A_op[2][2];
	A_op[0][0] = modulo(mat[1][1],26);
	A_op[0][1] = modulo((-1)*mat[0][1],26);
	A_op[1][0] = modulo((-1)*mat[1][0],26);
	A_op[1][1] = modulo(mat[0][0],26);
	int num = inverse_number(det);

	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			res[i][j] = (num*A_op[i][j]);
		}
	}
}
int inverse_number(int num)
{
	int i;
	num = modulo(num,26);
	for (i = 1; i < 26; ++i)
	{
		if (modulo(num*i,26) == 1)
			return i;
	}
	return -1;		// if inverse number not exist.
}
char* door_decryption(char*ctext,char*key)
{
	int key_mateix[2][2], temp1[2][2], temp2[2][2], endMat[10][2], encripted[10][2];
	char *p = ctext, *ptr;
	int ptLen, index, i, j, flag = 0,k=0;
	float res[2][2];
	tern_string_text_in_matrix(key, key_mateix, 2, 2);
	multiplay_any_2_matrix(key_mateix, key_mateix, 2, 2, 2, 2, temp1);
	multiplay_any_2_matrix(temp1, key_mateix, 2, 2, 2, 2, temp2);
	matrix_scalar_mul(key_mateix, 2, temp1, 2, 2);
	add_matrixes(temp1, temp2, key_mateix, 2, 2);
	calc_invertible_matrix(key_mateix, 2, 2, res);
	
	ptLen = strlen(ctext);
	
	if (ptLen % 2 != 0)
	{
		flag = 1;
		ptLen += 1;
		ptr = (char*)malloc(ptLen);
		if (ptr == NULL) {
			printf("allocation Error");
			exit(1);
		}
		strcpy_s(ptr, ptLen, ctext);
		ptLen /= 2;
	}
	else
	{
		ptr = (char*)malloc(strlen(ctext) + 1);
		strcpy(ptr, ctext);
		ptLen /= 2;
	}
	tern_string_text_in_matrix(ptr, endMat, (ptLen), 2);
	if (flag) endMat[ptLen - 1][1] = 'a' - 'a';
	multiplay_any_2_matrix(endMat, res, ptLen, 2, 2, 2, encripted);
	applay_modolo(encripted, 26, ptLen, 2);

	printf("\n");
	for (i = 0; i < ptLen; i++)
	{
		for (j = 0; j < 2; j++)
		{
			ptr[k] = (char)(encripted[i][j] + 'a');
			k++;
		}
	}
	if (flag == 1) {
		ptr[(ptLen * 2 - 1)] = '\0';
	}
	else {
		ptr[(ptLen * 2 + 1)] = '\0';
	}
	return ptr;

}