//Dymantic Array
public class Solution {
	
	public int countPrimes(int n) {  
        if(n <= 2) return 0;  
        ArrayList<Integer> primes = new ArrayList<Integer>();  
        primes.add(2);  
        for (int i = 3; i < n; i += 2) {  
            int sqrt_i = (int) Math.sqrt(i);  
            for (int j = 0; i % primes.get(j) != 0; j++) {  
                if (primes.get(j) > sqrt_i) {  
                    primes.add(i);  
                    break;  
                }  
            }  
        }  
        return primes.size();  
    }  
} 
