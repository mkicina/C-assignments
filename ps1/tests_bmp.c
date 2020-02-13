#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

#include <assert.h>

const char words[10][10] = {"SEPTEMBER","THOUSAND","CASSOVIA","NEPAL","EVEREST","CAESAR","ZONE","YES","ANDERSON","KEY"};
const char en_words[10][10] = {"XJUYJRGJW","YMTZXFSI","HFXXTANF","SJUFQ","JAJWJXY","HFJXFW","ETSJ","DJX","FSIJWXTS","PJD"};

void test_caesar_encrypt() {
	char* result;
	printf("Encrypting set of strings..\n");
//	free(result);
	for (int idx = 0;idx<10;idx++){
		result = caesar_encrypt(words[idx], 5);
		assert (strcmp(en_words[idx],result) ==0);
	}
	printf("Passed\n");
//	free(result);
}

void test_simple_encrypt() {
	printf("Encrypting constant string...\n");
	char *result = caesar_encrypt("AHOJ",5);
	assert (strcmp ("FMTO", result) == 0);
	printf("Passed\n");
//	free(result);
}


int main() {
	printf("Tests started...\n");
	test_simple_encrypt();
	test_caesar_encrypt();
	printf("All tests passed\n");
}

