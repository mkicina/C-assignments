#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "playfair.h"


char* playfair_encrypt(const char* key, const char* text){
	if (text==NULL) {
		return NULL;
	}	
	if (key==NULL) {
		return NULL;
	}
	if (text[0] == '\0' || text[0]== ' ' || key[0] == '\0' || key[0]== ' '){
		return NULL;
	}
	
	if ((strlen(key)==0) || (strlen(text)==0) ){
		return NULL;
	}
	if (!text || !key) {
		return NULL;
	}
	for (int i=0;i<strlen(key);i++) {
		if ((isalpha(key[i])==0 && key[i]!=32)) {
		       return NULL;	
		}
	}
	for (int i=0;i<strlen(text);i++) {
		if ((isalpha(text[i])==0 && text[i]!=32)) {
		       return NULL;	
		}
	}
	char matrix[5][5];
	char* my_key = calloc(strlen(key)+200,sizeof(char));
	strcpy(my_key,key);
	char* my_text = calloc(strlen(text)+200,sizeof(char));
	strcpy(my_text,text);
	
	int len_key=strlen(my_key);
	for(int i=0; i<len_key; i++) {
		if(my_key[i]==' '){
			for(int j=i; j<len_key; j++){
				my_key[j]=my_key[j+1];
			}
		len_key--;
		}
	}


	for (int i=0; i<strlen(my_key); i++){
		if(my_key[i]!=32) {
        		my_key[i] = toupper(my_key[i]);
		}
		else{
			i--;
		}
       	}

	int len=strlen(my_text);
	for(int i=0; i<len; i++) {
		if(my_text[i]==' '){
			for(int j=i; j<len; j++){
				my_text[j]=my_text[j+1];
			}
		len--;
		}
	}

	for (int i=0; i<strlen(my_text); i++){
		my_text[i] = toupper(my_text[i]);
       	}
 	for (int i=0; i<strlen(my_text); i++){
 		if (my_text[i]==87){
			my_text[i]='V';
		}
	}
	for (int i=0; i<strlen(my_key); i++){
 		if (my_key[i]==87){
			my_key[i]='V';
		}
	}


	

	int key_size=strlen(my_key);
	for(int i = 0; i < key_size; i++)    {
        	for(int j = i+1; j < key_size; ){
            		if(my_key[j] == my_key[i]){
                		for(int k = j; k < key_size; k++){
                    			my_key[k] = my_key[k+1];
                		}
                		key_size--;
            		}
            		else{
                		j++;
            		}
        	}
    	}
	char *key_alpha = calloc(28,sizeof(char));
//	char my_alpha[25];
	char mini_alpha[27];
	int t=0;
	for (int i=0;i<25;i++) {
		int count=0;
		for (int j=0;j<key_size;j++){
			if(my_key[j]==ALPHA[i]){
				count++;	
			}
		}
		if (count==0) {
			mini_alpha[t]=ALPHA[i];
			t++;
		}
	}
	for (int i=0;i<25;i++){
		if (i<key_size) {
			key_alpha[i]=my_key[i];
		}
		else {
			key_alpha[i]=mini_alpha[i-key_size];	 
		}
	}
	int k=0;
	for (int i=0;i<5;i++) {
		for (int j=0;j<5;j++) {
			matrix[i][j]=key_alpha[k];
			k++;
		}
	}
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++) {
//			printf ("%c ",matrix[i][j]);
		}
//		printf("\n");
	}
//	printf("%s\n",my_text);	

	char *new_text = calloc((strlen(my_text))+200,sizeof(char) );

	k=0;
	int x_count=0;
	int text_len=strlen(my_text);
	for (int i=0;i<=text_len;i=i+2){
		if ((my_text[i]==my_text[i+1]) && (my_text[i]!='X')) {
			new_text[i]=my_text[k];
			if (new_text[i+x_count]!=my_text[text_len]){
				new_text[i+1]='X';
				x_count++;
				new_text[i+2]=my_text[k+1];
				i++;
			//	text_len--;
			}
		}
		else{
			new_text[i]=my_text[k];
			new_text[i+1]=my_text[k+1];
		}
		k=k+2;
	}
	if ((strlen(new_text)) % 2 ==1) {
		new_text[strlen(new_text)] = 'X';
	}
//	printf("%s\n",new_text);
	int row_1=0;
	int row_2=0;
	int col_1=0;
	int col_2=0;
//	int p=0;
	char *result_text = calloc (strlen(new_text)+200,sizeof(char));
	for (int k=0;k<strlen(new_text);k=k+2){
		for (int i=0;i<5;i++) {
			for (int j=0;j<5;j++) {
				if (new_text[k]==matrix[i][j]) {
					row_1=i;
					col_1=j;
				}
				if (new_text[k+1] == matrix[i][j]) {
					row_2=i;
					col_2=j;
				}
			}
		}
	
		if(col_1==col_2) {	
			if(row_1==4){
				row_1=-1;
			}
			if(row_2==4){
				row_2=-1;
			}

			result_text[k]=matrix[row_1+1][col_1];
			result_text[k+1]=matrix[row_2+1][col_1];

		}
		else if (row_1==row_2){
			if(col_1==4){
				col_1=-1;
			}
			if(col_2==4){
				col_2=-1;
			}
			result_text[k]=matrix[row_1][col_1+1];
			result_text[k+1]=matrix[row_1][col_2+1];
		}
		
		else{
			result_text[k]=matrix[row_1][col_2];
			result_text[k+1]=matrix[row_2][col_1];
		}
	//	result_text[k+2]=' ';
		//k++;
	//	p++;
	}
//	printf("|%s|\n",result_text);


//	int size=strlen(my_text);
	char *new_text_2 = calloc(strlen(result_text)+200,sizeof(char));
	int big=strlen(result_text);
	int lenght=(big/2)-1;
	int u=0;
	for (int i=0;i<strlen(result_text)+lenght;i=i+3){
		new_text_2[i]=result_text[u];
		new_text_2[i+1]=result_text[u+1];
		if (i+2<(strlen(result_text)+lenght)){
			new_text_2[i+2]=' ';
			u=u+2;
		}	
	}
	free(key_alpha);	
	free(my_text);
	free(my_key);
	free(result_text);
	free(new_text);
	return new_text_2;
}


char* playfair_decrypt(const char* key, const char* text){
		
	if (text==NULL) {
		return NULL;
	}	
	if (key==NULL) {
		return NULL;
	}
	if (text[0] == '\0' || text[0]== ' ' ){
		return NULL;
	}

	if ((strlen(key)==0) || (strlen(text)==0) ){
		return NULL;
	}



	if ((strlen(key)==0) || (strlen(text)==0) ){
		return NULL;
	}
	if (!text || !key) {
		return NULL;
	}
	for (int i=0;i<strlen(key);i++) {
		if ((isalpha(key[i])==0 && key[i]!=32)) {
		       return NULL;	
		}
	}
	for (int i=0;i<strlen(text);i++) {
		if ((isalpha(text[i])==0 && text[i]!=32)) {
		       return NULL;	
		}
	}
	char matrix[5][5];
	char* my_key = calloc(strlen(key)+200,sizeof(char));
	strcpy(my_key,key);
	char* my_text = calloc(strlen(text)+200,sizeof(char));
	strcpy(my_text,text);
	
	int len_key=strlen(my_key);
	for(int i=0; i<len_key; i++) {
		if(my_key[i]==' '){
			for(int j=i; j<len_key; j++){
				my_key[j]=my_key[j+1];
			}
		len_key--;
		}
	}


	for (int i=0; i<strlen(my_key); i++){
		if(my_key[i]!=32) {
        		my_key[i] = toupper(my_key[i]);
		}
		else{
			i--;
		}
       	}

	int len=strlen(my_text);
	for(int i=0; i<len; i++) {
		if(my_text[i]==' '){
			for(int j=i; j<len; j++){
				my_text[j]=my_text[j+1];
			}
		len--;
		}
	}

	for (int i=0; i<strlen(my_text); i++){
		my_text[i] = toupper(my_text[i]);
       	}
 	for (int i=0; i<strlen(my_text); i++){
 		if (my_text[i]==87){
			my_text[i]='V';
		}
	}



	for (int i=0; i<strlen(my_key); i++){
 		if (my_key[i]==87){
			my_key[i]='V';
		}
	}


	

	int key_size=strlen(my_key);
	for(int i = 0; i < key_size; i++)    {
        	for(int j = i+1; j < key_size; ){
            		if(my_key[j] == my_key[i]){
                		for(int k = j; k < key_size; k++){
                    			my_key[k] = my_key[k+1];
                		}
                		key_size--;
            		}
            		else{
                		j++;
            		}
        	}
    	}
	char *key_alpha = calloc(28,sizeof(char));
//	char my_alpha[25];
	char mini_alpha[27];
	int t=0;
	for (int i=0;i<25;i++) {
		int count=0;
		for (int j=0;j<key_size;j++){
			if(my_key[j]==ALPHA[i]){
				count++;	
			}
		}
		if (count==0) {
			mini_alpha[t]=ALPHA[i];
			t++;
		}
	}
	for (int i=0;i<25;i++){
		if (i<key_size) {
			key_alpha[i]=my_key[i];
		}
		else {
			key_alpha[i]=mini_alpha[i-key_size];	 
		}
	}
	int k=0;
	printf("--------\n");
	for (int i=0;i<5;i++) {
		for (int j=0;j<5;j++) {
			matrix[i][j]=key_alpha[k];
			k++;
		}
	}
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++) {
//			printf ("%c ",matrix[i][j]);
		}
//		printf("\n");
	}
//	printf("%s\n",my_text);	

	char *new_text = malloc( sizeof(char) * (strlen(my_text))+1 );

	k=0;
	
	int x_count=0;
	int text_len=strlen(my_text);
	for (int i=0;i<=text_len;i=i+2){
		if ((my_text[i]==my_text[i+1])) {
			new_text[i]=my_text[k];
			if (new_text[i+x_count]!=my_text[text_len]){
				new_text[i+1]='X';
				x_count++;
				new_text[i+2]=my_text[k+1];
				i++;
			//	text_len--;
			}
		}
		else{
			new_text[i]=my_text[k];
			new_text[i+1]=my_text[k+1];
		}
		k=k+2;
	}
	if ((strlen(new_text)) % 2 ==1) {
		new_text[strlen(new_text)] = 'X';
	}
	printf("%s\n",new_text);
	
	int big=strlen(my_text);
	int lenght=(big/2)-1;
	char *new_text_2 = calloc(strlen(my_text)+lenght+200,sizeof(char));
	int u=0;
	for (int i=0;i<strlen(my_text);i=i+2){
		new_text_2[i]=my_text[u];
		new_text_2[i+1]=my_text[u+1];
//		if (i+2<(strlen(my_text)-lenght)){
			u=u+3;
//		}	
	}
//	printf("|%s|\n",new_text_2);
//	printf("teraz ide odkodovanie\n");
	int row_1=0;
	int row_2=0;
	int col_1=0;
	int col_2=0;
	char *result_text = calloc(strlen(new_text_2)+200,sizeof(char));
	for (int k=0;k<strlen(new_text_2);k=k+2){
		for (int i=0;i<5;i++) {
			for (int j=0;j<5;j++) {
				if (new_text_2[k]==matrix[i][j]) {
					row_1=i;
					col_1=j;
				}
				if (new_text_2[k+1] == matrix[i][j]) {
					row_2=i;
					col_2=j;
				}
			}
		}
	
		if(col_1==col_2) {	
			if(row_1==0){
				row_1=5;
			}
			if(row_2==0){
				row_2=5;
			}

			result_text[k]=matrix[row_1-1][col_1];
			result_text[k+1]=matrix[row_2-1][col_1];

		}
		else if (row_1==row_2){
			if(col_1==0){
				col_1=5;
			}
			if(col_2==0){
				col_2=5;
			}
			result_text[k]=matrix[row_1][col_1-1];
			result_text[k+1]=matrix[row_1][col_2-1];
		}
		
		else{
			result_text[k]=matrix[row_1][col_2];
			result_text[k+1]=matrix[row_2][col_1];
		}
	}
//	printf("|%s|\n",result_text);


//	int size=strlen(my_text);
//	char *new_text = malloc( sizeof(char) * (size)+1 );
	free(key_alpha);	
	free(my_text);
	free(my_key);
	free(new_text_2);
	return result_text;
	
}

