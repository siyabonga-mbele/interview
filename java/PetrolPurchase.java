
public class PetrolPurchase
{
	private String location;
	private String petrolType;
	private double price;
	private double percDiscount;
	private int quantityOfLitres;
	private double total;
	
	public void setLocation(String location)
	{
		this.location = location;
	}
	
	public void setPetrolType(String petrolType)
	{
		this.petrolType = petrolType;
	}
	
	public void setPrice(double price)
	{
		this.price = price;
	}
	
	public void setPercDiscount(double percDiscount)
	{
		this.percDiscount = percDiscount;
	}
	
	public void setQuantityOfLitres(int quantityOfLitres)
	{
		this.quantityOfLitres = quantityOfLitres;
	}
	
	//get methods
	public String getLocation()
	{
		return location;
	}
	
	public String getPetrolType()
	{
		return petrolType;
	}
	
	public double getPrice()
	{
		return price;
	}
	
	public double getPercDiscount()
	{
		return percDiscount;
	}
	
	public int getQuantityOfLitres()
	{
		return quantityOfLitres;
	}
	
	
	
	
	public double getPurchaceAmount()
	{
		
		double total = (quantityOfLitres * price) + (quantityOfLitres * price) * (percDiscount/100);
		
		return total;
	}
	
	public String toString()
	{
		return getLocation();
	}
	
	
	
}