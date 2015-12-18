import java.util.ArrayList;
import java.util.List;


public class Solution {
	int count = 0 ;
	public void construct_candidates(int a[],int k,int n,List<Integer> solu){
		boolean legal_move ;
		for(int i=1;i<=n;i++){
			legal_move = true ;
			for(int j=1;j<k;j++){
				if(Math.abs(k-j)==Math.abs(i-a[j])){
					legal_move = false ;
				}
				if(i==a[j])
					legal_move = false ;
			}
			
			if(legal_move == true){
				solu.add(i) ;
			}
		}
	}
	public void backtrack(int a[],int k,int n){
		if(k==n){
			count++ ;
		}else{
			k++ ;
			List<Integer>  solu = new ArrayList();
			construct_candidates(a,k,n,solu) ;
			for(int i=0;i<solu.size();i++){
				a[k] = solu.get(i) ;
				backtrack(a,k,n);
			}
		}
		
	}
	 public int solveNQueens(int n) {
	        int a[] = new int[n+1] ;
	        backtrack(a,0,n) ;
	        return count ;
	 }
	 
	 public static void main(String args[]){
		 Solution s = new Solution() ;
		 int count = s.solveNQueens(4) ;
		 System.out.println(count);
	 }
	 
}

