import java.util.ArrayList;
import java.util.List;


public class Solution {
	private List<List<Integer>> result ;
	private List<Integer> list ;
	public List<List<Integer>> generate(int numRows) {
		result = new ArrayList() ;
		for(int i=0;i<numRows;i++){
			list = new ArrayList() ;
			if(result.size()>=1){
				List<Integer> temp = result.get(result.size()-1) ;
				list.add(1) ;
				for(int j=1;j<temp.size();j++){
					list.add(temp.get(j-1)+temp.get(j)) ;
				}
				list.add(1) ;
				result.add(list) ;
			}else{
				list.add(1) ;
				result.add(list) ;
			}
		}
		return result ;
	}
}

