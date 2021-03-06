public class Solution {
	 public List<List<Integer>> fourSum(int[] num, int target) {
		Arrays.sort(num);
	 
		HashSet<ArrayList<Integer>> hashSet = new HashSet<ArrayList<Integer>>();
		List<List<Integer>> result = new ArrayList();
	 
		for (int i = 0; i < num.length; i++) {
			for (int j = i + 1; j < num.length; j++) {
				int k = j + 1;
				int l = num.length - 1;
	 
				while (k < l) {
					int sum = num[i] + num[j] + num[k] + num[l];
	 
					if (sum > target) {
						l--;
					} else if (sum < target) {
						k++;
					} else if (sum == target) {
						ArrayList<Integer> temp = new ArrayList<Integer>();
						temp.add(num[i]);
						temp.add(num[j]);
						temp.add(num[k]);
						temp.add(num[l]);
	 
						if (!hashSet.contains(temp)) {
							hashSet.add(temp);
							result.add(temp);
						}
	 
						k++;
						l--;
					}
				}
			}
		}
	 
		return result;
	}
	public static void main(String args[]){
		Solution s = new Solution() ;
		int[] candidates = {1,0,-1,0,-2,2};
		List<List<Integer>> list = s.fourSum(candidates, 0) ;
		for(List<Integer> l : list){
			for(Integer i : l){
				System.out.print(i+" ");
			}
			System.out.println();
		}
	}
}

