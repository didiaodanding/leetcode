import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class Solution {
	public List<List<Integer>> fourSum(int[] num, int target) {
		Arrays.sort(num);
		List<List<Integer>> result = new ArrayList();
	 
		for (int i = 0; i < num.length; i++) {
			for (int j = i + 1; j < num.length; j++) {
				for(int k=j+1;k<num.length;k++){
					if(k+1<num.length&&Arrays.binarySearch(num,k+1,num.length,(target-num[i]-num[j]-num[k]))>=0){
						ArrayList<Integer> temp = new ArrayList<Integer>();
						temp.add(num[i]);
						temp.add(num[j]);
						temp.add(num[k]);
						temp.add(target-num[i]-num[j]-num[k]);
						result.add(temp) ;
					}
					while(k+1 < num.length&&num[k]==num[k+1]){
						k++;
					}
				}
				while(j+1 < num.length&&num[j]==num[j+1]){
					j++;
				}
			}
			while(i+1 < num.length&&num[i]==num[i+1]){
				i++;
			}
		}
	 
		return result;
	}
	
	public static void main(String args[]){
		Solution s = new Solution() ;
		int[] candidates = {-3,-2,-1,0,0,1,2,3};
		List<List<Integer>> list = s.fourSum(candidates, 0) ;
		for(List<Integer> l : list){
			for(Integer i : l){
				System.out.print(i+" ");
			}
			System.out.println();
		}
	}
}

