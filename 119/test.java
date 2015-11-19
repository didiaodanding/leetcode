import java.util.ArrayList;
import java.util.List;


public class Solution {
	private List<List<Integer>> result ;
	private List<Integer> list ;
	public List<Integer> getRow(int rowIndex) {
		 result = new ArrayList() ;
			for(int i=0;i<rowIndex+1;i++){
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
			return result.get(rowIndex) ;
    }
}

