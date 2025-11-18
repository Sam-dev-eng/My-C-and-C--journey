#include <stdio.h> 
#include <string.h>


int main(void){

    char sentence[100];
    printf("Enter a sentence to reverse\n");
    fgets(sentence , sizeof(sentence) , stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    int count;
    int counter = 0;
    char reverse[100];
    for (count = strlen(sentence)-1; count >= 0; count--){
    reverse[counter++] = sentence[count];
    }
    printf("The reverse is %s\n",reverse);


}
