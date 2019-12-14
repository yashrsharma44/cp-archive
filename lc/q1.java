import java.util.*;


class Solution {
    public static int getCount(String word, int[] score)
    {
        int scr = 0;
        for(int i=0;i<word.length();i++)
        {
            char c = word.charAt(i);
            scr += score[c-'a'];
        }
        
        return scr;
    }
    
    public static boolean isSub(String big, String small)
    {
        int c1[] = new int[26];
        int c2[] = new int[26];
        
        Arrays.fill(c1,0);
        Arrays.fill(c2,0);
        
        for(Character c : big.toCharArray())
            c1[c - 'a'] +=1;
        
        for(Character c: small.toCharArray())
            c2[c - 'a'] +=1;
        
        for(int i=0;i<26;i++)
        {
            if(c2[i] > c1[i])
                return false;
        }
        
        // for(int i=0;i<26;i++)
        //     System.out.print(c1[i] + " ");
        
        return true;
    }
    
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        
        
        int max = -1;
        String check = new String(letters);
        for(int i=0;i<words.length;i++)
        {
            if(isSub(check ,words[i]))
            {
                max = Math.max(max, getCount(words[i], score));
            }
        }
        
        return max;
    }

    public static void main(String args[])
    {
    	String words[] = new String[]{"xxxz","ax","bx","cx"};
    	char letters[] = new char[]{'z','a','b','c','x','x','x'};
    	int score[] = new int[]{4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    	Solution ob = new Solution();
    	System.out.println(ob.maxScoreWords(words, letters, score));

    }

}

    