#include "choice.h"


 char* getPlayerChoice(enum Player player) {
   switch(player){
         case X:
              return "X";
         case O:
              return "O";
         case EMPTY:
              return ".";
         default:
              return "UNKNOWN";
   }


}
