#include <stdio.h>
#include "k.h"
#include <stdbool.h>

#include "hof.h"

#define SIZE 4
int main(){ 
	struct game game = {
    .board = {
	{'F', ' ', 'F', ' '},
	{' ', 'I', ' ', 'F'},
	{'D', 'D', 'F', ' '},
	{' ', ' ', 'G', 'F'}	
           },
    .score = 4698
};

	struct player list[10];

	load(list);
	for (int i=0;i<10;i++){
//		for (int j=0;j<10;j++){
			printf("%s",list[i].name);
//		}
		printf("%d\n",list[i].score);
	}
	save(list,10);

/*	struct player player = {
	    .name = "john",
	    .score = 400
	};
	int size = load(list);
	add_player(list, &size, player);	*/
//	int load(struct player list[]);
	int dx=0;
	int dy=0;
	char answer;	
	bool right_answer=false;
	while(!is_game_won(game) || is_move_possible(game)){
		for (int i=0;i<SIZE;i++) {
			for (int j=0;j<SIZE;j++) {
				printf("|%c ",game.board[i][j]);
			}
			printf("\n");
		}
		printf("%d\n",game.score);

		right_answer=false;
		while (right_answer == false){
			scanf("%c",&answer);
			if (answer == 'a'){
				dx = -1;
				right_answer=true;
			}
			else if (answer == 's'){
				dy = 1;
				right_answer=true;
			}
			else if (answer == 'd'){
				dx = 1;
				right_answer=true;
			}
			else if (answer == 'w'){
				dy = -1;
				right_answer=true;
			}
		}
		update(&game,dy,dx);
		dx=0;
		dy=0;
//		add_random_tile(&game);
	}
	printf("\nkoniec\n");
	return 0;

}
