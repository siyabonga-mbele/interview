

import static java.lang.System.out;

public class UseAccounts {
	
	public static void main(String[] args) {
		
		
		
		Accounts milk = new Accounts();
		milk.setLocation("Sandton");
		System.out.println(milk.getLocation() + "\n\n");
		
		
		Accounts myAccount = new Accounts();
		Accounts yourAccount = new Accounts();
		//Account milk = new Account();
		
		myAccount.setName("Siyabonga");
		myAccount.setAddress("1133 Soshanguve");
		myAccount.setBalance(30.00);
		//milk.setLocation("Sandton");
		
		yourAccount.setName("Buhle smith");
		yourAccount.setAddress("222 Sandton Drive");
		yourAccount.setBalance(800.42);
		
		//System.out.println(milk.getLocation() + "\n\n\n\n");
		out.print(myAccount.getName());
		out.print(" (");
		out.print(myAccount.getAddress());
		out.print(") has $");
		out.print(myAccount.getBalance());
		
		
		
		out.print(yourAccount.getName());
		out.print(" (");
		out.print(yourAccount.getAddress());
		out.print(") has $");
		out.print(yourAccount.getBalance());
		
	}
}