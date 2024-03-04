public class Solution {
    public int removeElement(int[] A, int elem) {
        int[] tmp = new int[A.length];
        int len = 0;
        for(int i=0; i<A.length; i++){
            if(A[i] != elem){
                tmp[len] = A[i];
                len++;
            }
        }
        for(int i=0; i<=len; i++){
            A[i] = tmp[i];
        }
        
        return len+1;
    }
}