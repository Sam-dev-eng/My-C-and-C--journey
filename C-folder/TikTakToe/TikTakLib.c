#include "choice.h"
#include <string.h>
#include <stdio.h>
#include "TikTakLib.h"

static char players[2][100];
static char *playersNames[9];
static const char* board[3][3];

 const char *(*setBoard())[3]{
    for (int count = 0; count < 3; count++){
        for (int counter = 0; counter < 3; counter++){
            board[count][counter] = getPlayerChoice(EMPTY);
        }
    }
    return board;
}

void printBoard(const char *(*board)[3]){
    for (int count = 0; count < 3; count++){
        for (int counter = 0; counter < 3; counter++){
            printf("| %s ", board[count][counter]);
        }
        printf("|\n");
    }
}

    void modifyBoard(const char* board[3][3], int row, int col, enum Player player){
        board[row][col] = getPlayerChoice(player);
}

void setPlayers(char playerOne[], char playerTwo[]){

    strncpy(players[0], playerOne, sizeof(players[0]) - 1);
    players[0][sizeof(players[0]) - 1] = '\0';
    strncpy(players[1], playerTwo, sizeof(players[1]) - 1);
    players[1][sizeof(players[1]) - 1] = '\0';

   for (int count = 0; count < 9; count++){
    playersNames[count] = players[count % 2];

   }
 
}

char ** getPlayersName(void){
    return playersNames;
}

struct PlayersChoice playersOneChoice(char *choiceOne){
    struct PlayersChoice player1 = {players[0], choiceOne};
    return player1;
}

struct PlayersChoice player2Choice(char * choiceTwo){
    struct PlayersChoice player2 = {players[1], choiceTwo};
    return player2;   
}

    void addsToPosition(int position, struct PlayersChoice player){
        if (position < 1 || position > 9){
            printf("Invalid position! Please choose a position between 1 and 9.\n");
            return;
        }
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        board[row][col] = player.symbol;
    }

const char * isWinner(){
    for (int i = 0; i < 3; i++) {
        if (strcmp(board[i][0], board[i][1]) == 0 && strcmp(board[i][1], board[i][2]) == 0 && strcmp(board[i][0], ".") != 0) {
            return board[i][0];
        }
        if (strcmp(board[0][i], board[1][i]) == 0 && strcmp(board[1][i], board[2][i]) == 0 && strcmp(board[0][i], ".") != 0) {
            return board[0][i];
        }
    }
    if (strcmp(board[0][0], board[1][1]) == 0 && strcmp(board[1][1], board[2][2]) == 0 && strcmp(board[0][0], ".") != 0) {
        return board[0][0];
    }
    if (strcmp(board[0][2], board[1][1]) == 0 && strcmp(board[1][1], board[2][0]) == 0 && strcmp(board[0][2], ".") != 0) {
        return board[0][2];
    }
    return 0;
}