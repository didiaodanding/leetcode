int max(int a,int b){
    if(a>b)
        return a ;
    return b ;
    
}
int lengthOfLongestSubstring(char* s) {
       int n = strlen(s) ;
  int i = 0, j = 0;
  int maxLen = 0;
  bool exist[256] = { false };
  while (j < n) {
    if (exist[s[j]]) {
      maxLen = max(maxLen, j-i);
      while (s[i] != s[j]) {
        exist[s[i]] = false;
        i++;
      }
      i++;
      j++;
    } else {
      exist[s[j]] = true;
      j++;
    }
  }
  maxLen = max(maxLen, n-i);
  return maxLen;
}
int main(){
	char s[10000] ; //10000个字符
	scanf("%s",s) ;
	int number = lengthOfLongestSubstring(s) ;
	printf("%d\n",number) ;
	return 0 ;
}
