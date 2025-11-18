#include <stdio.h> 
#include <string.h>


int lengthOfWord(char word[]);

int main(void){
    char words[100];
    printf("Enter a sentence\n");
    fgets(words,sizeof(words),stdin);
    words[strcspn(words,"\n")] = '\0';
    char *word = strtok(words, " ");
    
    size_t highest = lengthOfWord(word);
    char *highestWord = word;

    while(word != NULL){
        if (lengthOfWord(word) > highest){
            highest = lengthOfWord(word);
            highestWord = word;
        }
        word = strtok(NULL," ");
    }
        printf("The highest word is (%s)\n",highestWord);
    
   return 0;
}

int lengthOfWord(char word[]){
    return strlen(word);

}
























