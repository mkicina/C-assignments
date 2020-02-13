#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hof.h"
#include <unistd.h>
/*
struct player list[]={
    // name of the player (avoid usage of spaces in name)
    char list.name[30];
    // player's score
    int list.score;
};
*/


int load(struct player list[]){
if(access(HOF_FILE, F_OK)==-1) {
	return -1;
}
FILE *file;
file = fopen(HOF_FILE, "r");
if (file==NULL) {
	fclose(file);
	return -1;
}
char temp_name[30];
int temp_score = 0;
int count = 0;
if (file) {	
	while(fscanf(file, "%s %d",temp_name,&temp_score) > 0){
		strcpy(list[count].name, temp_name);
		(list[count].score= temp_score);
		count++;

	}
	if (count ==0){
		return -1;
	}
	int tmp=0;
	char tmp_nm[30];
	for (int i=0;i<count;i++) {
		for (int j=0;j<count-i-1;j++) {
			if (list[j].score < list[j+1].score) {
				tmp = list[j].score;
				list[j].score = list[j+1].score;
				list[j+1].score = tmp;

				strcpy(tmp_nm, list[j].name);
				strcpy(list[j].name,list[j+1].name);
				strcpy(list[j+1].name,tmp_nm);
			}
		}
	}
}

else{
	fclose(file);
	return -1;
}
fclose(file);
return count;
}

bool save(const struct player list[], const int size){
FILE *file;
file = fopen(HOF_FILE, "w");
if (file==NULL) {
	fclose(file);
	return false;
}
char temp_name[30];
int temp_score=0;
for (int i=0;i<size;i++) {
	strcpy(temp_name,list[i].name);
	temp_score= (list[i].score);
	fprintf(file,"%s %d\n",temp_name,temp_score);
//	fprintf(file,"%d\n",&list[i].score);
}
fclose(file);
return true;

}
/*
bool add_player(struct player list[], int* size, const struct player player){
	int min=list[0].score;
//	int min_index=0;
	int lenght=*size;	

	for (int i=1;i<lenght;i++){
		if (list[i].score < min) {
			min = list[i].score;
//			min_index=i;
		}
	}
	if(player.score<min){
		return false;
	}
if(access(HOF_FILE, F_OK)==-1) {
	return -1;
}
FILE *file;
file = fopen(HOF_FILE, "w");
if (file==NULL) {
	fclose(file);
	return -1;
}
	if (lenght<10) {
	char temp_name[30];
	int temp_score = 0;
	int k=0;
	while(fscanf(file, "%s %d",temp_name,&temp_score) > 0){

		strcpy(list[k].name, player.name);
		(list[k].score=player.score);
		k++;
	}	
		int tmp=0;
		char tmp_nm[30];
		for (int i=0;i<lenght;i++) {
			for (int j=0;j<lenght-i-1;j++) {
				if (list[j].score < list[j+1].score) {
					tmp = list[j].score;
					list[j].score = list[j+1].score;
					list[j+1].score = tmp;

					strcpy(tmp_nm, list[j].name);
					strcpy(list[j].name,list[j+1].name);
					strcpy(list[j+1].name,tmp_nm);
				}
			}
		}

//		char temp_name[30];
//		int temp_score=0; 
	 	for (int i=0;i<lenght+1;i++) {
			strcpy(temp_name,list[i].name);
			temp_score= (list[i].score);
			fprintf(file,"%s %d\n",temp_name,temp_score);
		}
		fprintf(file,"%s %d\n",player.name,player.score);
		int tmp=0;
		char tmp_nm[30];
	 	for (int i=0;i<lenght;i++) {
			for (int j=0;j<lenght-i-1;j++) {
				if (list[j].score < list[j+1].score) {
					tmp = list[j].score;
					list[j].score = list[j+1].score;
					list[j+1].score = tmp;

					strcpy(tmp_nm, list[j].name);
					strcpy(list[j].name,list[j+1].name);
					strcpy(list[j+1].name,tmp_nm);
				}
			}
		}
//		return true;}
	
for 
	
	strcpy(list[min_index].name,player.name);
	list[min_index].score=player.score;
//	size++;

return true;
}
*/
