#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct block{
	char text[10];
	int data;
	enum { penalty='P', snake='S', stair='M', boost='B', trap='T'} data_type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;

int single_player(struct block board[][10],int pos_x,int pos_y,int now_data,int move_count);
void init_board(struct block board[][10]);
void print_board(struct block board[][10]);
void two_player(struct block board[][10],int pos1_x,int pos1_y,int pos2_x,int pos2_y);


int main(){
	int move_count;
	struct block board[10][10];
	srand(time(NULL));
	init_board(board);
	print_board(board);
	move_count=single_player(board,9,9,1,0);
	printf("\nmove count:%d",move_count);
	two_player(board,9,9,9,9);
	return 0;
}


void init_board(struct block board[][10]){	
	int i,j,count=1;
	
	for(i=9;i>=0;i=i-2){
		for(j=9;j>=0;j--){
			board[i][j].data=count;
			count++;
			board[i][j].pos_x=i;
			board[i][j].pos_y=j;
			strcpy(board[i][j].text,"null");
			
		}
		count+=10;
	}
	
	count=11;
	
	for(i=8;i>=0;i=i-2){
		for(j=0;j<10;j++){
			board[i][j].data=count;
			count++;
			board[i][j].pos_x=i;
			board[i][j].pos_y=j;
			strcpy(board[i][j].text,"null");
		}
		count+=10;
	}
	
	strcpy(board[9][9].text,"1(Start)");
	
	strcpy(board[9][4].text,"S{1}");
	board[9][4].data_type=snake;
	board[9][4].jump_x=9; board[9][4].jump_y=9;
	
	strcpy(board[9][3].text,"M{11}");
	board[9][3].data_type=stair;
	board[9][3].jump_x=8; 
	board[9][3].jump_y=0;
	
	strcpy(board[8][2].text,"P");
	board[8][2].data_type=penalty;
	/*board[8][2].jump_x=8; board[8][2].jump_y=2;*/
	
	strcpy(board[8][6].text,"M{28}");
	board[8][6].data_type=stair;
	board[8][6].jump_x=7; board[8][6].jump_y=2;
	
	strcpy(board[7][5].text,"S{12}");
	board[7][5].data_type=snake;
	board[7][5].jump_x=8; board[7][5].jump_y=1;
	
	strcpy(board[7][1].text,"B");
	board[7][1].data_type=boost;
	board[7][1].jump_x=6; board[7][1].jump_y=3;
	
	strcpy(board[6][1].text,"M{52}");
	board[6][1].data_type=stair;
	board[6][1].jump_x=4; board[6][1].jump_y=1;
	
	strcpy(board[5][0].text,"B");
	board[5][0].data_type=boost;
	board[5][0].jump_x=7; board[5][0].jump_y=8;
	
	strcpy(board[5][2].text,"P");
	board[5][2].data_type=penalty;
	/*board[5][2].jump_x=5; board[5][2].jump_y=2;*/
	
	strcpy(board[5][5].text,"S{22}");
	board[5][5].data_type=snake;
	board[5][5].jump_x=7; board[5][5].jump_y=8;
	
	strcpy(board[4][9].text,"S{44}");
	board[4][9].data_type=snake;
	board[4][9].jump_x=5; board[4][9].jump_y=6;
	
	strcpy(board[4][6].text,"M{77}");
	board[4][6].data_type=stair;
	board[4][6].jump_x=2; board[4][6].jump_y=6;
	
	strcpy(board[4][3].text,"T");
	board[4][3].data_type=trap;
	board[4][3].jump_x=4; board[4][3].jump_y=8;

	strcpy(board[3][1].text,"M{77}");
	board[3][1].data_type=stair;
	board[3][1].jump_x=2; board[3][1].jump_y=6;	
	
	strcpy(board[3][4].text,"B");
	board[3][4].data_type=boost;
	board[3][4].jump_x=2; board[3][4].jump_y=0;
	
	strcpy(board[3][7].text,"S{52}");
	board[3][7].data_type=snake;
	board[3][7].jump_x=5; board[3][7].jump_y=1;
	
	strcpy(board[2][2].text,"S{68}");
	board[2][2].data_type=snake;
	board[2][2].jump_x=3; board[2][2].jump_y=2;
	
	strcpy(board[2][5].text,"M{83}");
	board[2][5].data_type=stair;
	board[2][5].jump_x=1; board[2][5].jump_y=7;
	
	strcpy(board[2][8].text,"T");
	board[2][8].data_type=trap;
	board[2][8].jump_x=2; board[2][8].jump_y=3;
	
	strcpy(board[1][8].text,"B");
	board[1][8].data_type=boost;
	board[1][8].jump_x=1; board[1][8].jump_y=3;
	
	strcpy(board[1][5].text,"P");
	board[1][5].data_type=penalty;
	/*board[1][5].jump_x=1; board[1][5].jump_y=5;*/
	
	strcpy(board[1][1].text,"M{94}");
	board[1][1].data_type=stair;
	board[1][1].jump_x=0; board[1][1].jump_y=3;
	
	strcpy(board[0][2].text,"T");
	board[0][2].data_type=trap;
	board[0][2].jump_x=1; board[0][2].jump_y=2;
	
	strcpy(board[0][7].text,"S{72}");
	board[0][7].data_type=snake;
	board[0][7].jump_x=2; board[0][7].jump_y=1;
	
	strcpy(board[0][8].text,"S{56}");
	board[0][8].data_type=snake;
	board[0][8].jump_x=4; board[0][8].jump_y=5;
	
	strcpy(board[6][9].text,"T");
	board[6][9].data_type=trap;
	board[6][9].jump_x=6; board[6][9].jump_y=4;
	
	strcpy(board[0][9].text,"100(Finish)");
}



void print_board(struct block board[][10]){
	int i,j;
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(strcmp(board[i][j].text,"null")==0){
				printf("%d	",board[i][j].data);
			}
			else printf("%s	",board[i][j].text);
		}
		printf("\n\n");
		
	}
}



int single_player(struct block board[][10],int pos_x,int pos_y,int now_data,int move_count){
	
	int dice,temp_x=pos_x,temp_y=pos_y,temp2_x,temp2_y;
	
	dice=rand()%6+1;
	temp_x=pos_x;
	temp_y=pos_y;
	if(pos_x%2==1 && pos_y-dice<0 ){
		pos_x--;
		pos_y=dice-pos_y-1;
	}
	
	else if(pos_x%2==1 && pos_y-dice>=0){
		pos_y=pos_y-dice;
	}
	
	else if(pos_x%2==0 && pos_y+dice>9){
		pos_x--;
		pos_y=19-dice-pos_y;
	}
	else if(pos_x%2==0 && pos_y+dice<=9){
		pos_y=pos_y+dice;
	}
	
	if(pos_x<0 || pos_y>9){
		pos_x=temp_x;
		pos_y=temp_y;
	}
	temp2_x=pos_x;
	temp2_y=pos_y;
	
	printf("\ndice:%d,pos_x:%d,pos_y:%d",dice,pos_x,pos_y);
	
	if(board[pos_x][pos_y].data_type==penalty){
		pos_x=temp_x;
		pos_y=temp_y;
	}
	
	else if(board[pos_x][pos_y].data_type==snake){
		pos_x=board[temp2_x][temp2_y].jump_x;
		pos_y=board[temp2_x][temp2_y].jump_y;
	}
	
	else if(board[pos_x][pos_y].data_type==stair){
		pos_x=board[temp2_x][temp2_y].jump_x;
		pos_y=board[temp2_x][temp2_y].jump_y;
	}
	
	else if(board[pos_x][pos_y].data_type==boost){		
		pos_x=board[temp2_x][temp2_y].jump_x;
		pos_y=board[temp2_x][temp2_y].jump_y;
	}
	
	else if(board[pos_x][pos_y].data_type==trap){
		pos_x=board[temp2_x][temp2_y].jump_x;
		pos_y=board[temp2_x][temp2_y].jump_y;		
	}
	printf("	after	dice:%d,pos_x:%d,pos_y:%d\n ",dice,pos_x,pos_y);
	move_count++;
	
	
	
	if(pos_x!=0 || pos_y!=9){
		single_player(board,pos_x,pos_y,now_data,move_count);		
	}
	else{
		return move_count;
	}		
}

void two_player(struct block board[][10],int pos1_x,int pos1_y,int pos2_x,int pos2_y){
	
	int dice1,dice2,temp1_x,temp1_y,temp2_x,temp2_y,last1_x,last1_y,last2_x,last2_y,move1_count=0,move2_count=0;
	
	printf("\n--------------------------------------------------------");
	
	while((pos1_x!=0 || pos1_y!=9) ){
		
		dice1=rand()%6+1;
		temp1_x=pos1_x; temp1_y=pos1_y;
		
		if(pos1_x%2==1 && pos1_y-dice1<0 ){
			pos1_x--;
			pos1_y=dice1-pos1_y-1;
		}
	
		else if(pos1_x%2==1 && pos1_y-dice1>=0){
			pos1_y=pos1_y-dice1;
		}
	
		else if(pos1_x%2==0 && pos1_y+dice1>9){
			pos1_x--;
			pos1_y=19-dice1-pos1_y;
		}
		else if(pos1_x%2==0 && pos1_y+dice1<=9){
			pos1_y=pos1_y+dice1;
		}
	
		if(pos1_x<0 || pos1_y>9){
			pos1_x=temp1_x;
			pos1_y=temp1_y;
			printf("\nLimit excess!! dice1:%d, data:%d",dice1,board[pos1_x][pos1_y].data);			
		}
		last1_x=pos1_x;
		last1_y=pos1_y;
	
			
		if(board[pos1_x][pos1_y].data_type==penalty){
			pos1_x=temp1_x;
			pos1_y=temp1_y;
		}
	
		else if(board[pos1_x][pos1_y].data_type==snake){
			pos1_x=board[last1_x][last1_y].jump_x;
			pos1_y=board[last1_x][last1_y].jump_y;
		}
	
		else if(board[pos1_x][pos1_y].data_type==stair){
			pos1_x=board[last1_x][last1_y].jump_x;
			pos1_y=board[last1_x][last1_y].jump_y;
		}
	
		else if(board[pos1_x][pos1_y].data_type==boost){		
			pos1_x=board[last1_x][last1_y].jump_x;
			pos1_y=board[last1_x][last1_y].jump_y;
		}
	
		else if(board[pos1_x][pos1_y].data_type==trap){
			pos1_x=board[last1_x][last1_y].jump_x;
			pos1_y=board[last1_x][last1_y].jump_y;		
		}
				
		move1_count++;

		printf("\ndice1:%d, data:%d",dice1,board[pos1_x][pos1_y].data);

	}
	
	printf("\n--------------------------------------------------------");
	while(pos2_x!=0 || pos2_y!=9){
		dice2=rand()%6+1;
		temp2_x=pos2_x; temp2_y=pos2_y;
		
		if(pos2_x%2==1 && pos2_y-dice2<0 ){
			pos2_x--;
			pos2_y=dice2-pos2_y-1;
		}
	
		else if(pos2_x%2==1 && pos2_y-dice2>=0){
			pos2_y=pos2_y-dice2;
		}
	
		else if(pos2_x%2==0 && pos2_y+dice2>9){
			pos2_x--;
			pos2_y=19-dice2-pos2_y;
		}
		else if(pos2_x%2==0 && pos2_y+dice2<=9){
			pos2_y=pos2_y+dice2;
		}
	
		if(pos2_x<0 || pos2_y>9){
			pos2_x=temp2_x;
			pos2_y=temp2_y;
			printf("\nLimit excess!! dice2:%d, data:%d",dice2,board[pos2_x][pos2_y].data);			
		}
		last2_x=pos2_x;
		last2_y=pos2_y;
		
		if(board[pos2_x][pos2_y].data_type==penalty){
			pos2_x=temp2_x;
			pos2_y=temp2_y;
		}
	
		else if(board[pos2_x][pos2_y].data_type==snake){
			pos2_x=board[last2_x][last2_y].jump_x;
			pos2_y=board[last2_x][last2_y].jump_y;
		}
	
		else if(board[pos2_x][pos2_y].data_type==stair){
			pos2_x=board[last2_x][last2_y].jump_x;
			pos2_y=board[last2_x][last2_y].jump_y;
		}
	
		else if(board[pos2_x][pos2_y].data_type==boost){		
			pos2_x=board[last2_x][last2_y].jump_x;
			pos2_y=board[last2_x][last2_y].jump_y;
		}
	
		else if(board[pos2_x][pos2_y].data_type==trap){
			pos2_x=board[last2_x][last2_y].jump_x;
			pos2_y=board[last2_x][last2_y].jump_y;		
		}
		
		move2_count++;
		printf("\ndice2:%d, data:%d",dice2,board[pos2_x][pos2_y].data);	
	}
	printf("\n--------------------------------------------------------");
	
	if(move1_count<move2_count){
		printf("\nPlayer 1 Win!!\n Move count player 1:%d\n Move count player 2:%d\n",move1_count,move2_count);
	}
	
	else if(move1_count>move2_count){
		printf("\nPlayer 2 Win!!\n Move count player 1:%d\n Move count player 2:%d\n",move1_count,move2_count);
	}
	
	else{
		printf("\nTied Game!!\n Move count player 1:%d\n Move count player 2:%d\n",move1_count,move2_count);		
	}		
}			 		
