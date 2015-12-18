    public class Solution {  
        List<List<Integer>> result;  
        List<Integer> solu;  
        public List<List<Integer>> combinationSum(int[] candidates, int target) {  
            result = new ArrayList<>();  
            solu = new ArrayList<>();  
            Arrays.sort(candidates);  
            getCombination(candidates, target, 0, 0);  
            return result;  
        }  
        public void getCombination(int[] candidates, int target, int sum, int level){  
            if(sum>target) return;  
            if(sum==target){  
                result.add(new ArrayList<>(solu));  
                return;  
            }  
            for(int i=level;i<candidates.length;i++){  
                sum+=candidates[i];  
                solu.add(candidates[i]);  
                getCombination(candidates, target, sum, i);  
                solu.remove(solu.size()-1);  
                sum-=candidates[i];  
            }  
        }  
    }  
