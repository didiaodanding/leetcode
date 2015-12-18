
public class Solution {
	 public int lengthOfLastWord(String s) {
		String str[] = s.split(" ") ;
		if(str.length>0){
			return str[str.length-1].length() ;
		}else{
			return 0 ;
		}
	 }
	 public static void main(String args[]){
		 Solution s = new  Solution() ;
		 String str = " " ;
		 int result = s.lengthOfLastWord(str) ;
		 System.out.println(result);
	 }
}

