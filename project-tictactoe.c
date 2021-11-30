
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions_used.h"

int main() {
	srand(time(NULL));
	int choice;
	do{
		system("cls");
		printf("\t\t\t\t\t\tTIC-TAC-TOE\n");
		printf("\nPress 1 to read instructions.\n\n");
		printf("Press 2 to play game.\n\n");
		printf("Press 0 to exit.\n");
		scanf("%d",&choice);
	
		if(choice==1){
			system("cls");
			readInstructions();
			printf("Press any key to return to the main menu.");
			getch();
		}
		else if(choice==2){
			//game initialisation -- setting up tic-tac-toe board
			system("cls");
			char gameboard[9];
			int l;
			for(l=0;l<9;l++){
				gameboard[l]=' ';	
			}
			while(checkgame(gameboard)){
				computermove(gameboard);
				int check=checkgame(gameboard);
				if(check==0){
					printf("\nBetter luck next time!!Computer has won.\n");
					printf("\n\n\n\nPress any key to return to the main menu");
					getch();
					break;
				}
				else if(check==-1) {
					printf("\nWell Played!!The game ended in a tie.\n");
					printf("\n\n\n\nPress any key to return to the main menu.");
					getch();
					break;
				}
				playermove(gameboard);
				showgame(gameboard);
				check=checkgame(gameboard);
				if(check==0){
					printf("\n\nCongratulations!!you have won.\n");
					printf("\nPress any key to return to the main menu.");
					getch();
					break;
				}
			}
		}
	} while(choice);
}

