#include <stdio.h>
#include <math.h>

int main() {
    int max = 1000000;

    for (int num = 3; num < max; num += 2)
    {
        int prime = 1;
        int sqr = sqrt(num);
        
        for(int i=3;i<=sqr;i +=2){
            if(num %i ==0){
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
