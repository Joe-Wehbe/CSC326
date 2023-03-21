 #include <stdio.h>

int main(){
    
    float weight;
    int height;
    float BMI;
    
    printf("Enter the weight in kg: ");
    scanf("%f", &weight);
    
    printf("Enter the height in cm: ");
    scanf("%d", &height);
    
    if(weight <= 0 || height<=0 ){
        printf("Error: The weight and height should not be negative or equal to 0.");
        
    }else{
        BMI = weight/(height*height)*10000;
        
        if(BMI < 18.5){
            printf("BMI= %f ==> Underweight.", BMI);
            
        }else if(BMI>= 18.5 && BMI<= 24.9){
        printf("BMI= %f ==> Normal weight.", BMI);
        
        }else{
            printf("BMI= %f ==> Overweight.", BMI);
        }
    }

    return 0;
}

 