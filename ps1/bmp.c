#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "bmp.h"


char* reverse(const char* text) {
	if (!text){
		return NULL;
	}

	int size=strlen(text);
	char *new_text = malloc( sizeof(*text) * (size+1) );
	int k=0;
	for (int i=size;i>0;i--) {
		new_text[k]=toupper( text[i-1]);
		k++;
	}


	new_text[size]='\0';
	return new_text;
	free(new_text);
	
}

char* vigenere_encrypt(const char* key, const char* text) {
	if (!text || !key) {
		return NULL;
	}
	int key_len=strlen(key);	
	for (int i=0;i<key_len;i++) {
		if (key[i] == ' ') {
			return NULL;
		}
		if (isalpha(key[i])==0) {
		       return NULL;	
		}
	}
	char* my_key = calloc(strlen(text)+1,sizeof(char));
	char* my_text = calloc(strlen(text)+1,sizeof(char));	
	int i=0;
	while (i<strlen(key)){
		my_key[i]=key[i];
		i++;
	}
	i=0;
	while (i<strlen(text)) {
		my_text[i]=text[i]; 
		i++;
	}
	
//	strcpy(my_key,key);
//	strcpy(my_text,text);
	int j=0;
	int my_text_len=strlen(my_text);
	int my_key_len=strlen(my_key);
	for (int i=0; i<my_text_len; i++){
		if (j>= my_key_len){ 
			j=0;
		}
        	my_key[i] = toupper(my_key[j]);
		my_text[i] = toupper(my_text[i]);
		j++;
       	}

	int size=strlen(my_text);
	char *new_text = calloc(size+1, sizeof(char));
	int k=0;
	for (int i=0;i<size;i++) {
		int text_ascii=my_text[i];
		int key_ascii=my_key[k];
		if (text_ascii < 65 || text_ascii > 90) {
			new_text[i]=text_ascii;
		}
		else {
		int super_key=(text_ascii)+(key_ascii);
		if (super_key>26) {
			super_key=super_key%26;
		}	
		char let=super_key+65;
		new_text[i]=let;
		k++;
		}		
	}

//	new_text[sizeof(new_text)] = '\0';
    	free (my_key);
	my_key = NULL;
    	free (my_text);
	my_text = NULL;
	return new_text;
//	free(new_text);
}

char* vigenere_decrypt(const char* key, const char* text){
	if (!text || !key) {
		return NULL;
	}
	int key_len=strlen(key);	
	for (int i=0;i<key_len;i++) {
		if (key[i] == ' ') {
			return NULL;
		}
		if (isalpha(key[i])==0) {
		       return NULL;	
		}
	}

	
	// char *new_text = malloc( sizeof(*text) * (size+1) );
	char* my_key = calloc((strlen(text)+1),sizeof(char));
	char* my_text = calloc((strlen(text)+1),sizeof(char));
//	strcpy(my_key,key);
//	strcpy(my_text,text);
	int i=0;
	while (i<strlen(key)){
		my_key[i]=key[i];
		i++;
	}
	i=0;
	while (i<strlen(text)) {
		my_text[i]=text[i]; 
		i++;
	}
	
	int j=0;
	for (int i=0; i<strlen(my_text); i++){
		if (j>= strlen(my_key)) {
			j=0;
		}
        	my_key[i] = toupper(my_key[j]);
		my_text[i] = toupper(my_text[i]);
		j++;
       	}	
	int size=strlen(my_text);
	char *new_text = calloc((size)+1,sizeof(char) );
	int k=0;
	for (int i=0;i<size;i++) {
		int text_ascii=my_text[i];
		int key_ascii=my_key[k];
		if (text_ascii == 32 || text_ascii == '!') {
			new_text[i]=text_ascii;
		}
		else {
		int super_key=(text_ascii)-(key_ascii);
		if (super_key<0) {
			super_key=super_key+26;
		}
		if (super_key>26) {
			super_key=super_key%26;
		}	
		char let=super_key+65;
		new_text[i]=let;
		k++;
		}
	}
	free (my_key);
	my_key = NULL;
	free (my_text);
	my_text = NULL;
	return new_text;
//	free(new_text);
}

unsigned char* bit_encrypt(const char* text) {
        if (!text) {
                return NULL;
        }
//        char* my_text = calloc(strlen(text)+1,sizeof(char));
//        strcpy(my_text,text);
//        int size=strlen(my_text);
        unsigned char *new_text = calloc(strlen(text)+1,sizeof(unsigned char));
        for (int i=0;i<strlen(text);i++) {
                int binaryNum[8];
                int num=text[i];
                int k=0;
                for (int h=0;h<8;h++) {
                  if (num<=0){
                    binaryNum[k]=0;
                  }
                  else{
                  binaryNum[k] = num % 2;
                  num = num / 2;
                  }
                  k++;
                }

                for (int t=0;t<8;t++){
               //   printf("orig_binary: %d\n",binaryNum[t]);
                }
                int binar_one[4];
                int binar_two[4];
                binar_one[0]=binaryNum[6];
                binar_one[1]=binaryNum[7];
                binar_one[2]=binaryNum[4];
                binar_one[3]=binaryNum[5];
                for (int t=0;t<4;t++){
               //   printf("binar_one: %d\n",binar_one[t]);
                }
                for (int t=0;t<4;t++){
                    binar_two[t]=binaryNum[3-t];
                }
                for (int t=0;t<4;t++){
             //     printf("binar_two: %d\n",binar_two[t]);
                }
                int binar_three[4];
                for (int t=0;t<4;t++){
                  if (binar_one[t]==binar_two[t]){
                    binar_three[t]=0;
                  }
                  else if (binar_one[t]!=binar_two[t]){
                    binar_three[t]=1;
                  }
               }
               for (int t=0;t<4;t++){
              //    printf("binar_three: %d\n",binar_three[t]);
                }
                int key=0;
                key=key+((pow(2,7)*binar_one[0]));
                key=key+((pow(2,6)*binar_one[1]));
                key=key+((pow(2,5)*binar_one[2]));
                key=key+((pow(2,4)*binar_one[3]));
                key=key+((pow(2,3)*binar_three[0]));
                key=key+((pow(2,2)*binar_three[1]));
                key=key+((pow(2,1)*binar_three[2]));
                key=key+((pow(2,0)*binar_three[3]));
//                printf("key: %d\n",key);
                new_text[i]=key;

        } 
//	free(my_text);
//	my_text=NULL;
  return new_text;
}


char* bit_decrypt(const unsigned char* text) {
	if (!text) {
                return NULL;
        }

	int size = strlen((char*)text);
//        char* my_text = calloc(size+1,sizeof(unsigned char));
	
//        strcpy(my_text,(char*)text);
//        int size=strlen(my_text);
        char *new_text = calloc(size+1,sizeof(char));
	for (int i=0;i<size;i++) {
                int binaryNum[8];
                int num=text[i];
              // printf("num: %d\n",num);
                int k=0;
                for (int h=0;h<8;h++) {
                  if (num<=0){
                    binaryNum[k]=0;
                  }
                  else{
                  binaryNum[k] = num % 2;
                  num = num / 2;
                  }
                  k++;
                }

                for (int t=0;t<8;t++){
               //   printf("orig_binary: %d\n",binaryNum[t]);
                }
                int binar_one[4];
             //   int binar_two[4];
		int binar_three[4];
                for (int t=0;t<4;t++){
                  if (binaryNum[t]==binaryNum[t+4]){
                    binar_three[t]=0;
                  }
                  else if (binaryNum[t]!=binaryNum[t+4]){
                    binar_three[t]=1;
                  }
               }

                binar_one[0]=binaryNum[5];
                binar_one[1]=binaryNum[4];
                binar_one[2]=binaryNum[7];
                binar_one[3]=binaryNum[6];
                for (int t=0;t<4;t++){
                 // printf("binar_one %d: %d\n",t,binar_one[t]);
                }
            
	    //   	 for (int t=0;t<4;t++){
          //          binar_two[t]=binaryNum[3-t];
        //        }
		
                for (int t=0;t<4;t++){
             //     printf("binar_two: %d\n",binar_two[t]);
                }
                              for (int t=0;t<4;t++){
                 // printf("binar_three %d: %d\n",t,binar_three[t]);
                }
                int key=0;
                key=key+((pow(2,7)*binar_one[3]));
                key=key+((pow(2,6)*binar_one[2]));
                key=key+((pow(2,5)*binar_one[1]));
                key=key+((pow(2,4)*binar_one[0]));
                key=key+((pow(2,3)*binar_three[3]));
                key=key+((pow(2,2)*binar_three[2]));
                key=key+((pow(2,1)*binar_three[1]));
                key=key+((pow(2,0)*binar_three[0]));
              //  printf("key: %d\n",key);
                new_text[i]=key;

        } 
//	free(my_text);
//	my_text=NULL;
  return new_text;
}


unsigned char* bmp_encrypt(const char* key, const char* text){
	if (!text || !key) {
		return NULL;
	}
	int key_len=strlen(key);	
	for (int i=0;i<key_len;i++) {
		if (key[i] == ' ') {
			return NULL;
		}
		if (isalpha(key[i])==0) {
		       return NULL;	
		}
	}

//	char* my_key = calloc(strlen(text)+1,sizeof(char));
//	char* my_text = calloc(strlen(text)+1,sizeof(char));
//	strcpy(my_key,key);
//	strcpy(my_text,text);
	char *my_text=reverse(text);
//	char *new_text = calloc(strlen(my_text),sizeof(char));
	char *vige_bmp = vigenere_encrypt(key,my_text);
//	free(my_key);
	free(my_text);
//	unsigned  char *new_text_2 = calloc(strlen(new_text),sizeof(unsigned char));
	unsigned char *new_text_2=bit_encrypt(vige_bmp);
	free(vige_bmp);

	return new_text_2;
}

char* bmp_decrypt(const char* key, const unsigned char* text){
	if (!text || !key) {
		return NULL;
	}
	int key_len=strlen(key);	
	for (int i=0;i<key_len;i++) {
		if (key[i] == ' ') {
			return NULL;
		}
		if (isalpha(key[i])==0) {
		       return NULL;	
		}
	}

//	char* my_key = calloc(strlen(text)+1,sizeof(char));
//	unsigned char* my_text = calloc(strlen(text)+1,sizeof(unsigned char));
//	strcpy(my_key,key);
//	strcpy(my_text,text);
 	char *my_text=bit_decrypt(text);
//	char *new_text = calloc(strlen(my_text),sizeof(char));
	char *vigen_bmp=vigenere_decrypt(key,my_text);
//	free(my_key);
	free(my_text);
//	char *new_text_2 = calloc(strlen(new_text),sizeof(char));
	char *new_text_2=reverse(vigen_bmp);
	free(vigen_bmp);
	
	return new_text_2;
}

/*
char* caesar_encrypt(const char* text, const int step) {

	int len = strlen(text);
    char* result = (char*)calloc(len + 1, sizeof(char));

    for( int index = 0; index < len; index++ ){
        result[index] = (text[index] - 'A' + step) % 26 + 'A';
    } 
    result[len] = '\0';

    return result;
    
	
}
*/
