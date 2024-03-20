public class Solution {
    public String strStr(String haystack, String needle) {
        
        
        
        if(haystack==null||needle==null)
        {
            return null;
        }
        
        if(needle==""&&haystack!="")
        {
            return String.valueOf(haystack.charAt(0));
        }
        
        if(needle==""&&haystack=="")
        return "";
        
        
        if(haystack.length()<needle.length()){
            return null;
        }
        
        
        
        int pointer=0;
        for(int i=0;i<haystack.length()-needle.length()+1;i++){
            
            int begin=0;
            pointer=i;
            while(haystack.charAt(i+begin)==needle.charAt(begin)&&begin<needle.length()-1)
            {
                begin++;
            }
            
            if(begin==needle.length()-1){
                return String.valueOf(haystack.charAt(pointer));
            }
            
        }
        
        
        return null;
        
        
    }
}