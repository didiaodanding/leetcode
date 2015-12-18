import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
	List<List<Integer>> result;
	List<Integer> solu;

	public List<List<Integer>> combinationSum(int[] candidates, int target) {
		result = new ArrayList();
		solu = new ArrayList();
		Arrays.sort(candidates);
		getCombination(candidates, target, 0, 0);
		return result;
	}

	public void getCombination(int[] candidates, int target, int sum, int level) {
		if (sum > target)
			return;
		if (sum == target) {
			result.add(new ArrayList(solu));
			return;
		}
		for (int i = level; i < candidates.length; i++) {
			sum += candidates[i];
			solu.add(candidates[i]);
			getCombination(candidates, target, sum, i + 1);
			solu.remove(solu.size() - 1);
			sum -= candidates[i];
			while(i+1 < candidates.length&&candidates[i]==candidates[i+1]){
				i++;
			}
			
		}
	}
	
	public static void main(String args[]){
		Solution s = new Solution() ;
		int[] candidates = {10,1,2,7,6,1,5};
		List<List<Integer>> list = s.combinationSum(candidates, 8) ;
		for(List<Integer> l : list){
			for(Integer i : l){
				System.out.print(i);
			}
			System.out.println();
		}
	}
}

