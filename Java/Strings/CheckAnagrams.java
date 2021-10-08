import java.util.HashMap;
import java.util.Map;

/**
 * Two strings are anagrams if they are made of the same letters arranged differently (ignoring the
 * case).
 */
//This program checks if both the strings are anagram of each other or not.
//Prints 'Yes' if they are else print 'No'

public class anagrams {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String a=sc.nextLine();    //a is 1st String
        a=a.toLowerCase();         //converting it to lower case
        HashMap<Character,Integer> h=new HashMap<>(); // h is hashmap to store characters present in string a. 
        for(int i=0;i<a.length();i++) {
            char ch=a.charAt(i);
            if(h.containsKey(ch))
            h.put(ch, h.get(ch)+1);  //getting previous count of characters and adding 1 to it.
            else
            h.put(ch, 1);
        }
        String b=sc.nextLine();   //b is 2nd String
        b=b.toLowerCase();        //converting it to lower case
        HashMap<Character,Integer> h2=new HashMap<>();   // h2 is hashmap to store characters present in string b.
        for(int i=0;i<b.length();i++) {
            char ch=b.charAt(i);
            if(h2.containsKey(ch))
            h2.put(ch, h2.get(ch)+1);   //getting previous count of characters and adding 1 to it.
            else
            h2.put(ch, 1);
        }
        if(h.equals(h2))
        System.out.println("Yes");
        else
        System.out.println("No");
    }
}
