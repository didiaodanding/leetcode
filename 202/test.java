import java.util.HashSet;
import java.util.Set;


public class HappyNumber {
	Set<Integer> sets = new HashSet<Integer>();
	public boolean isHappy(int n){
		while(n>1){
			if(sets.contains(n)){
					break ;
			}
			sets.add(n) ;
			String str = String.valueOf(n) ;
			int sum = 0 ;
			for(int i=0;i<str.length();i++){
				sum = sum + (str.charAt(i)-'0')*(str.charAt(i)-'0') ;
			}
			n = sum ;
		}
		if(n==1){
			return true ;
		}else{
			return false ;
		}
	}
	public static void main(String[] args) {
		HappyNumber hn = new HappyNumber() ;
		boolean result = hn.isHappy(2) ;
		if(result==true){
			System.out.println("is a happy number");
		}else{
			System.out.println("is not a happy number");
		}
	}

}

