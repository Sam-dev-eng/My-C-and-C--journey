#include <stdio.h>
#include <string.h>

int main(void){

    char words[100];
    char openBrackets[5] = {'(','{','[','<','\0'};
    char closeBrackets[5] = {')','}',']','>','\0'};
    printf("Enter brackets\n");
    fgets(words,sizeof(words), stdin);
    words[strcspn(words,"\n")] = '\0';
    
    
    size_t countOPenBrackets = 0;
    size_t countCloseBrackets = 0;
    for (int count = 0; count < strlen(words); count++){
    
      for (int counter = 0; counter < 4; counter++){
          if (words[count] == openBrackets[counter]){
            countOPenBrackets++;
      }else if (words[count] == closeBrackets[counter]){
          countCloseBrackets++;
        }
      }
    } 
    if (countOPenBrackets == countCloseBrackets){
        printf("TRUE\n");
    }else printf("FALSE\n");
    
    return 0;
}


























