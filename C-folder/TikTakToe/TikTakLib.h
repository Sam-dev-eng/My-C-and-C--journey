#ifndef TIKTAKLIB_H
#define TIKTAKLIB_H
struct PlayersChoice {
    char *name;
    char *symbol;
};
void modifyBoard(const char* board[3][3], int row, int col, enum Player player);
void printBoard(const char*(*board)[3]);
void setPlayers(char playerOne[], char playerTwo[]);
const char *(*setBoard())[3];
struct PlayersChoice playersOneChoice(char *choiceOne);
struct PlayersChoice player2Choice(char *choiceTwo);
char ** getPlayersName(void);
void addsToPosition(int position, struct PlayersChoice player);
const char *isWinner();
#endif

