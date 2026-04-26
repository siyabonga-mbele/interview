
public class Petrol
{
	public static void main(String[] args)
	{
		
		PetrolPurchase petroli = new PetrolPurchase();
		PetrolPurchase milk = new PetrolPurchase();
		
		petroli.setLocation("Soshanguve");
		petroli.setPetrolType("Unleaded");
		petroli.setPrice(15.99);
		petroli.setPercDiscount(2);
		petroli.setQuantityOfLitres(20);
		
		milk.setLocation("Sandton");
		milk.setPetrolType("Unleaded");
		milk.setPrice(15.90);
		milk.setPercDiscount(1);
		milk.setQuantityOfLitres(100);
		
		//double num = petroli.getPurchaceAmount();
		
	    System.out.println(petroli.getLocation() + " ,  " + petroli.getPurchaceAmount());
		System.out.println("\n\n" + milk.getLocation() + " ,  " + milk.getPurchaceAmount());
		
	}
}
