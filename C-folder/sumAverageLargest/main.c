#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numOne , numTwo , numThree , sum;
    printf("Enter three numbers\n");
    scanf("%d" "%d" "%d",&numOne , &numTwo, &numThree);
    sum = numOne + numTwo + numThree;
    float average = sum / 3;

    int largest = numOne;
    if (largest < numTwo){
    largest = numTwo;
    }
    if(largest < numThree){
    largest = numThree;
    }

    printf("Their sum are %d\n",sum);
    printf("Their Average is %f \n", average);
    printf("The largest is %d", largest);


    return 0;
}
