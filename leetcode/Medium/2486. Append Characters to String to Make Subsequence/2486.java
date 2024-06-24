class Solution {
    public int appendCharacters(String s, String t) {
        int tIdx = 0;

        for(char c:s.toCharArray()){
            if(c == t.charAt(tIdx))
                tIdx++;
            if(tIdx == t.length()) break;
        }


        return t.length() - tIdx;
        
    }
}

// TC: O(S)
// SC: O(1)
