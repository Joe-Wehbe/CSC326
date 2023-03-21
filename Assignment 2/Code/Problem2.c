#include <stdio.h>

int main (){
    

    int evenCount = 0;
    int oddCount = 0;
    int evenSum = 0;
    int oddSum = 0;
    
    int i;
    int numbers = 6;
    int num[numbers];
    
    int total = 0;
    int count =0;

    for (i = 0; i < numbers; ++i){
        printf ("%d. Enter a number: ", i + 1);
        scanf ("%d", &num[i]);
    }

    for (int i = 0; i < numbers; i++){
        if (num[i] >= 10 && num[i] % 2 == 0){
	        evenCount++;
	        evenSum += num[i];
	        count++;
	        total+= num[i];
	    }
        else if (num[i] >= 10 && num[i] % 2 != 0){
	        oddCount++;
	        oddSum += num[i];
	        count++;
	        total+= num[i];
	    } 
    }
    
    float oddAverage = (float) oddSum / (float) oddCount;
    float evenAverage = (float) evenSum /  (float) evenCount;
    float average = (float) total /  (float) count;
    
    printf ("The number of the odd integers >= 10 is : %d \n", oddCount);
    printf ("The average of the odd integers >= 10 is : %f \n", oddAverage);
    printf ("The number of the even integers >= 10 is : %d \n", evenCount);
    printf ("The average of the even integers >= 10 is : %f \n", evenAverage);
    printf ("The average of all integers >= 10 is : %f \n", average);
}
