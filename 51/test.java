import java.util.ArrayList;
import java.util.List;


public class Solution {
	List<List<String>> result;
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
			List<String> list = new ArrayList() ;
			for(int i=1;i<a.length;i++){
				StringBuilder sb = new StringBuilder() ;
				for(int j=1;j<a.length;j++){
					if(j!=a[i]){
						sb.append(".") ;
					}else{
						sb.append("Q") ;
					}
				}
				list.add(sb.toString()) ;
			}
			result.add(list) ;
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
	 public List<List<String>> solveNQueens(int n) {
			result = new ArrayList();
	        int a[] = new int[n+1] ;
	        backtrack(a,0,n) ;
	        return result ;
	 }
	 
	 public static void main(String args[]){
		 Solution s = new Solution() ;
		 List<List<String>> resu = s.solveNQueens(4) ;
		 for(List<String> list : resu){
			 for(String str : list){
				 System.out.println(str);
			 }
			 System.out.println();
		 }
	 }
	 
}

