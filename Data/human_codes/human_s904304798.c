import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			String word = sc.next();
			int n = word.length();
			
			//System.out.println("n=" + n);
			
			if(word.charAt(n-1) == ',' || word.charAt(n-1) == '.') {
				n--;
			}
		
			if(n>=3 && n<=6) {
				System.out.print(word.substring(0,n) + " ");
			}
				
		}
	
		System.out.println();
	
	}
}