void showgame(char game[9]) {
	system("cls");
	printf("\n");
	printf("\t\t  %c | %c | %c\n",game[0],game[1],game[2]);
	printf("\t\t----+---+----\n");
	printf("\t\t  %c | %c | %c\n",game[3],game[4],game[5]);
	printf("\t\t----+---+----\n");
	printf("\t\t  %c | %c | %c\n",game[6],game[7],game[8]);
	 
}
//to check winner
int checkgame(char game[9]) {
	int i;
	if(game[0]==game[1] && game[1]==game[2] && game[0]!=' '){
		return 0;
	}
	else if(game[3]==game[4] && game[4]==game[5] && game[3]!=' '){
		return 0;
	}
	else if(game[6]==game[7] && game[7]==game[8] && game[6]!=' '){
		return 0;
	}
	else if(game[0]==game[3] && game[3]==game[6] && game[0]!=' '){
		return 0;
	}
	else if(game[1]==game[4] && game[4]==game[7] && game[1]!=' '){
		return 0;
	}
	else if(game[2]==game[5] && game[5]==game[8] && game[2]!=' '){
		return 0;
	}
	else if(game[0]==game[4] && game[4]==game[8] && game[0]!=' '){
		return 0;
	}
	else if(game[2]==game[4] && game[4]==game[6] && game[2]!=' '){
		return 0;
	}
	else if(game[1]!=' ' && game[2]!=' ' && game[3]!=' ' && game[4]!=' ' 
	&& game[5]!=' ' && game[6]!=' ' && game[7]!=' ' 
	&& game[8]!=' ' && game[9]!=' '){
		return -1;
	}
	else {
		return 1;
	}
}

void computermove(char game[9]) {
	int z=rand()%9;
	if (game[z]=='X' || game[z]=='0'){
		return computermove(game);
	}
	else{
		game[z]='X';
		printf("\n\nComputer is playing its move..");
		sleep(3);
		showgame(game);
		printf("\n\nComputer has played its move in cell %d.",z+1);
		printf("\n\n");
	}
}

void playermove (char game[9]){
	int ch;
	printf("\nEnter the cell number where you would like to play your move: ");
	scanf("%d",&ch);
	if(game[ch-1]=='X' || game[ch-1]=='0') {
		printf("\n\nInvalid Move. Press enter to play your move again.\n\n");
		getch();
		return playermove(game);
	}
	else {
		game[ch-1]='0';
	}
}
// Instructions to play
void readInstructions() {
	
	printf("\t\t\t\t\tInstructions to play Tic-Tac-Toe\n\n");
	printf("1) The cells are numbered from 1 to 9 as shown below, you just have to enter the cell \nnumber where you would like to play your move. \n\n");
	
	printf("\t\t  1 | 2 | 3\n");
	printf("\t\t----+---+----\n");
	printf("\t\t  4 | 5 | 6\n");
	printf("\t\t----+---+----\n");
	printf("\t\t  7 | 8 | 9\n");
	printf("\n2) By default: Computer plays X and player plays 0\n");
	printf("\n\n3) The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n");
	printf("\n\n4) When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n");
	printf("\n\n\n\n\n");
}
