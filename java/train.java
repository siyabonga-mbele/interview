import java.util.*;
import  static java.lang.System.out;

public class train {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		out.println("WELCOME TO GUESSING GAME");
		
		int myRandom = new Random().nextInt(10) + 1;
		int count = 0;
		int num = 0;
		
		while (num != myRandom){
			
			
			if (count >= 1 && num != myRandom){
				System.out.println("try again");
			}
			out.println("enter number from 0 to 10 : ");
			num = kb.nextInt();
			count++;
			
		}
		
		out.println("congratulations, you got a good guess of : " + num + "\nAfter " + count + " times");
	}
}