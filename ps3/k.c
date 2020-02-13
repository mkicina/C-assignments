#include <stdlib.h>
#include <math.h>
#include "k.h"
#include <stdio.h>
/*
void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}
*/
bool is_game_won(const struct game game){
	for (int i=0;i<SIZE;i++) {
	       for (int j=0;j<SIZE;j++) {
		       if(game.board[i][j]=='K') {
			      return true;
			} 
			
		}
	}	
	return false;	
}

bool is_move_possible(const struct game game) {
	for (int i=0;i<SIZE;i++) {
	       for (int j=0;j<SIZE;j++) {
		       if(game.board[i][j]==' ') {
			      return true;
			} 
			
		}
	}	
     	for (int i=0;i<SIZE;i++) {
	       for (int j=0;j<SIZE;j++) {
		       if((game.board[i][j] == game.board[i+1][j]) || (game.board[i][j] == game.board[i][j+1])) {
			      return true;
			} 
			
		}
	}	

	return false;
}

bool update(struct game *game, int dy, int dx){
	//vsetko 2x prejst
	int score=game->score;
if ((dy==0 && dx==0) || ((dy==1 || dy==-1) && (dx==1 || dx==-1))) {
	return false;
}
int move=0;
int posun=0;
for (int p=0;p<SIZE;p++){
	if (p==0){
		posun=0;
	}
	if (dy==-1) {
		for(int i=0; i<SIZE ;i++){       
   			for(int j=0; j<SIZE ;j++){
   				if(game->board[j][i]==' '){
         				for(int k=j+1; k<SIZE ;k++){ 
            					if(game->board[k][i]){
               						game->board[j][i]=game->board[k][i]; 
               						game->board[k][i]=' ';
							move=1;
						     	break;	
						}
            				}
					
				}
				
  			}
		}
		if(posun==0){
		for(int i=0; i<SIZE ;i++){       
   			for(int j=0; j<SIZE ;j++){
   				if((game->board[j][i]!=' ') && (game->board[j][i]==game->board[j+1][i])){ 
					game->board[j][i]=(char)(game->board[j][i]+1);
					int temp_score= ((int)(game->board[j][i]));
					double add_1=pow((temp_score-64),2);
					int add = (int) add_1;
					if (add%2==1) {
						add=add-1;
					}
//					printf("\nadd: %d\n",add);
					game->score = score + add;
				//	double add_1=pow(((int)(game->board[j][i])-64),2);
				//	int add = (int)add_1;
			     	//	game->score=score+add;		
   					game->board[j+1][i]=' ';
					posun=1;
				}
			}
		}
		}
	}	
	if (dy==1) {
		for(int i=SIZE-1; i>-1 ;i--){       
   			for(int j=SIZE-1; j>-1 ;j--){
   				if(game->board[j][i] == ' '){
         				for(int k=j-1; k>-1;k--){ 
            					if(game->board[k][i]){
               						game->board[j][i]=game->board[k][i]; 
               						game->board[k][i]=' ';
							move=1;
						     	break;	
						}
            				}	
      				}
				
  			}
		}
		if (posun==0) {
		for(int i=SIZE-1; i>-1 ;i--){       
   			for(int j=SIZE-1; j>-1 ;j--){
   				if((game->board[j][i]!=' ') && (game->board[j][i]==game->board[j-1][i])){ 
					game->board[j][i]=(char)(game->board[j][i]+1);  
				        int temp_score= ((int)(game->board[j][i]));
					double add_1=pow((temp_score-64),2);
					int add = (int) add_1;
					if (add%2==1) {
						add=add-1;
					} 
//					printf("\nadd: %d\n",add);
					game->score = score + add;
				//	double add_1=pow(((int)(game->board[j][i])-64),2);
				//	int add = (int)add_1;
			     	//	game->score=score+add;		
   					game->board[j-1][i]=' ';
					posun=1;
				}
			}
		}
		}	
	}

	if (dx==-1) {
		for(int i=0; i<SIZE;i++){       
   			for(int j=0; j<SIZE ;j++){
   				if(game->board[i][j]==' '){
         				for(int k=j+1; k<SIZE ;k++){ 
            					if(game->board[i][k]){
               						game->board[i][j]=game->board[i][k]; 
               						game->board[i][k]=' ';
							move=1;
						     	break;	
						}
            				}	
      				}
				
  			}
		}
		if(posun==0) {
		for(int i=0; i<SIZE ;i++){       
   			for(int j=0; j<SIZE-1 ;j++){
   				if((game->board[i][j]!=' ') && (game->board[i][j]==game->board[i][j+1])){ 
					game->board[i][j]=(char)(game->board[i][j]+1);
					int temp_score= ((int)(game->board[i][j]));
					double add_1=pow((temp_score-64),2);
					int add = (int) add_1;
					if (add%2==1) {
						add=add-1;
					}
//					printf("\nadd: %d\n",add);
					game->score = score + add;	
//					double add_1=pow(((int)(game->board[i][j])-64),2);
//					int add = (int)add_1;
//			     		game->score=score+add;	
   					game->board[i][j+1]=' ';
					posun=1;
				}
			}
		}	
		}
	}


	if (dx==1) {
		for(int i=SIZE-1; i>-1 ;i--){       
   			for(int j=SIZE-1; j>-1 ;j--){
   				if(game->board[i][j] == ' '){
         				for(int k=j-1; k>-1;k--){ 
            					if(game->board[i][k]){
               						game->board[i][j]=game->board[i][k]; 
               						game->board[i][k]=' ';
							move=1;
						     	break;	
						}
            				}	
      				}
				
  			}
		}
		if (posun==0){
		for(int i=SIZE-1; i>-1 ;i--){       
   			for(int j=SIZE-1; j>-1 ;j--){
   				if((game->board[i][j]!=' ') && (game->board[i][j]==game->board[i][j-1])){
//				       	int temp_score= ((int)(game->board[i][j])+2);
	
					game->board[i][j]=(char)(game->board[i][j]+1);   
					int temp_score= ((int)(game->board[i][j]));
					double add_1=pow((temp_score-64),2);
					int add = (int) add_1;
					if (add%2==1) {
						add=add-1;
					}
//					printf("\nadd: %d\n",add);
					game->score = score + add;
   					game->board[i][j-1]=' ';
					posun=1;
				}
			}
		}	
		}
	}
}
	/*		
		int x=0;
		int y=0;
		for (int i=0;i<SIZE-1;i++) {
			for (int j=0;j<SIZE;j++){
				x=i;
				y=j+1;
				if((game.board[j][i] == game.board[y][x]) && game.board[j][i] != " "){
					game.board[j][i] = (game.board[j][i])+1; 	
					//	x--;
				}
				
			}
		}
	
*/

if (move==1){
	return true;
}
return false;
}




