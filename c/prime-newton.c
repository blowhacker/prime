#include <stdio.h>
#include <math.h>


float absolute(float num)
{
    if(num < 0){
        num = -num;
    }
    return num;
}
// Function to calculate square root of the number using Newton-Raphson method
float square_root(int x)
{
    const float difference = 0.00001;
    float guess = 1.0;
    while  ( absolute((guess * guess) / x  - 1.0) >= 0.0001 ) {
        guess = (x/guess + guess)/2.0;
    }
    return guess;
}


int main() {
    int max = 1000000;

    for (int num = 3; num < max; num += 2)
    {
        int prime = 1;
        // int sqr = sqrt(num);
        int sqr = (int) square_root(num);
        for(int i=3;i<=sqr;i +=2){
            if(num %i == 0){
                prime = 0;
                break;
            }
        }
        if(prime==1){
           printf("%d\n", num);

        }
           
    }

   return 0;
   
}


