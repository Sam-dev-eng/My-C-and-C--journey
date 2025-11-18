#include <stdio.h>
#include <string.h>
#include "choice.h"
#include "TikTakLib.h"

int main(){
    char players[2][100];
    char player1Choice[2];
    char playerTwoChoice[2];
    printf("Welcome to the Tik Tak Toe Game\n\nEnter Player 1 name\n");
    fgets(players[0], sizeof(players[0]), stdin);
    players[0][strcspn(players[0], "\n")] = '\0';  
    printf("Enter Player 2 name\n");
    fgets(players[1], sizeof(players[1]), stdin);
    players[1][strcspn(players[1],"\n")] = '\0';  
    setPlayers(players[0], players[1]);
    const char *(*board)[3] = setBoard();

    printf("\n\nWelcome %s and %s to Tik Tak Toe game\n\n", players[0], players[1]);
    printf("Here is the initial game board:\n");
    printBoard(board);


    printf("player %s choose any symbol eg.(X or O):\n", players[0]);
    fgets(player1Choice,sizeof(player1Choice), stdin);
    player1Choice[strcspn(player1Choice,"\n")] = '\0';

    printf("player %s choose any symbol eg.(X or O):\n", players[1]);
    fgets(playerTwoChoice,sizeof(playerTwoChoice),stdin);
    playerTwoChoice[strcspn(playerTwoChoice,"\n")] = '\0';
    fgets(playerTwoChoice,sizeof(playerTwoChoice),stdin);
    playerTwoChoice[strcspn(playerTwoChoice,"\n")] = '\0';  
    struct PlayersChoice player1 = playersOneChoice(player1Choice);
    struct PlayersChoice player2 = player2Choice(playerTwoChoice);
    
    int count = 0;
    int position = 0;
    while(count != 10){
        if (isWinner() != 0){
            printBoard(board);
            printf("Player with symbol %s wins!\n", isWinner());
            printf("We have a winner! Congratulations %s\n", getPlayersName()[count - 1]);
            break;
        }
      if(count == 9){
        printBoard(board);
        printf("It's a draw!\n");
        break;
      }
      
      printf("it's %s's turn now\n\n", getPlayersName()[count]);
      if(player1.name == getPlayersName()[count]){
        printf("Choose a position to place (%s) (1-9): \n", player1.symbol);
        printBoard(board);
      scanf("%d", &position);
      addsToPosition(position, player1);
      count++;
      } else {
        printf("Choose a position to place (%s)(1-9): \n", player2.symbol);
        printBoard(board);
      scanf("%d", &position);
      addsToPosition(position, player2);
      count++;
      }
      
    }
   return 0; 
}



    