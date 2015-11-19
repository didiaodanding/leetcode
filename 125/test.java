
public class Solution {
	 public boolean isPalindrome(String s) {
		 	s = s.replaceAll("\\W","") ;
		 	s = s.toLowerCase() ;
		 	if(s!=null){
		 		int upper = s.length() - 1 ;
		 		int lower = 0 ;
		 		while(lower<upper){
		 			if(s.charAt(lower)==s.charAt(upper)){
		 				lower++ ;
		 				upper-- ;
		 			}else{
		 				break ;
		 			}
		 		}
		 		if(lower<upper){
		 			return false ;
		 		}else{
		 			return true ;
		 		}
		 	}else{
		 		return false ;
		 	}
	 }
	 public static void main(String args[]){
		 String s = "ab" ;
		 Solution solution = new Solution() ;
		 if(solution.isPalindrome(s)){
			 System.out.println("success");
		 }else{
			 System.out.println("failed");
		 }
	 }
}

