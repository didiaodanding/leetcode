import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Solution {
	List<List<Integer>> result ; 
	List<Integer> list ;
	public void pathSum1(TreeNode root,int sum ,int target){
		list.add(root.val) ;
		if(target==sum){
			if(root.left==null&&root.right==null){
				List<Integer> temp = new ArrayList() ;
				temp.addAll(list) ;
				result.add(temp) ;
			}
		}
		if(root.left!=null){
			pathSum1(root.left,sum,target+root.left.val) ;
			
		}
		if(root.right!=null){
			pathSum1(root.right,sum,target+root.right.val) ;
		}
		list.remove(list.size()-1) ;
	}
	
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
			if(root==null)
					return null ;
	        result = new ArrayList<List<Integer>>() ;
	        list = new ArrayList() ;
	        int target = root.val ;
	        pathSum1(root,sum,target) ;
	        return result ;
	}
}

