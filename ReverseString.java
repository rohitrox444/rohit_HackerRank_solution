151. Reverse Words in a String

Pasted from <https://leetcode.com/problems/reverse-words-in-a-string/> 






public class Solution {
    public String reverseWords(String s) {
        String [] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        int end = words.length - 1;
        for(int i = 0; i<= end; i++){
            if(!words[i].isEmpty()) {
                sb.insert(0, words[i]);
                if(i < end) sb.insert(0, " ");
            }
        }
        return sb.toString();
    }
