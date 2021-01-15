
class Prime {
    public static void main(String[] args) {
        double max = 1000000;

        for (int num = 3; num < max; num += 2)
        {
            int prime = 1;
            double sqr = Math.sqrt(num);
            
            for(int i=3;i<=sqr;i +=2){
                if(num %i ==0){
                    prime = 0;
                    break;
                }
            }
            if(prime==1){
                System.out.println(num);
            }               
        }    
    }
}