
import  static java.lang.System.out;

public class Accounts {
	
	private String name;
	private String address;
	private double balance;
	private String location;
	
	public void setName(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public String toString()
	{
		return getName();
	}
	
	
	public void setAddress(String address) {
		
		this.address = address;
	}
	public String getAddress()
	{
		return address;
	}
	
	
	
	
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public double getBalance() {
		return balance;
	}
	
	
	
	public void setLocation(String location)
	{
		this.location = location;
	}
	public String getLocation()
	{
		return location;
	}
	
	

}