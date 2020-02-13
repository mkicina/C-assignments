#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bmp.h"
#include "playfair.h"

int main() {
	char* reversed=reverse("Hello world!");
	printf ("%s\n",reversed);
	free(reversed);
 //   	reversed = NULL;
 	char*  encrypted = vigenere_encrypt("key","");
  //	char* encrypted =vigenere_encrypt("cartel","slice");
    	printf("first: %s\n", encrypted);
    	// "JSXAI PSINR!"
    	free(encrypted);
    //	encrypted = NULL;
  
   	// printf ("Fun with Flags\n");
    	
    	char * decrypted = vigenere_decrypt("overused","IIPFWCIG");
   	printf("%s\n", decrypted);
    	// "JSXAI PSINR!"
        free(decrypted);
  //  	decrypted = NULL;
    // basic test with long text
     
    	unsigned char *encrypted_bin = bit_encrypt("!NPPYA MVPCR");
    	for(int i=0; i < 12;i++) {
        	printf("%x ", encrypted_bin[i]);
        	//80 9c 95 95 96 11 bc 96 b9 95 9d 10
    	}
    	free(encrypted_bin);
	
	printf("\n");
	unsigned char chara []={128,156,149,149,150};
	unsigned char* chara_p=chara;
	char* decrypted_bin = bit_decrypt(chara_p);
        for(int i=0; i < 5 ;i++) {
        	printf("%c", decrypted_bin[i]);
        	//80 9c 95 95 96 11 bc 96 b9 95 9d 10
	}
	free(decrypted_bin);
	printf("-----------\n");
	

//	free(bmp_encrypt);
       	printf("\n");
 
//	free(bmp_decrypt);
	printf("\n");	
//encrypted_bin = NULL;
/*
	unsigned char* bmp_encrypt("ComPuTer","Hello world!");
	for (int i=0;i<10;i++){
		printf("%c",bmp_encrypt);
	}
	free(bmp_encrypt);
*/

	 char *encrypted_p;
	char *decrypted_p;


    // even length of string
    encrypted_p = playfair_encrypt(" ","sabots");
  
    // "Hello world" --> "HELXLOVORLDX"
    // IS JZ JQ XN TK JC
  //  decrypted = playfair_decrypt("SeCReT", encrypted);
  //  printf("%s", decrypted);
    // HELXLOVORLDX
    decrypted_p = playfair_decrypt("modernize", "QB VU RM AM");
    printf("%s", decrypted_p);
    // HELXLOVORLDX
    free(encrypted_p);
    free(decrypted_p);
 
}

