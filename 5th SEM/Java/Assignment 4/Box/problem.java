import java.util.Scanner;

class Box
{
	int height, width, length;
	Box(int n1, int n2, int n3)
	{
		length = n1;
		width = n2;
		height = n3;
	}
	int volume()
	{
		return height*width*length;
	}
}

class BoxWeight extends Box
{
	int weight;
	BoxWeight(int n1, int n2, int n3, int n4)
	{
		super(n1,n2,n3);
		weight = n4;
	}
}

class BoxShipment extends BoxWeight
{
	int unit_cost;
	BoxShipment(int n1, int n2, int n3, int n4, int n5)
	{
		super(n1, n2, n3, n4);
		unit_cost = n5;
	}
	int cost()
	{
		return weight*unit_cost;
	}
}

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int ht, wdt, lt, wt, cost;
		System.out.print("Enter the length, width & height: ");
		lt = sc.nextInt();
		wdt = sc.nextInt();
		ht = sc.nextInt();
		System.out.print("Enter the weight: ");
		wt =sc.nextInt();
		System.out.print("Enter the cost per unit weight: ");
		cost=sc.nextInt();
		BoxShipment bs = new BoxShipment(lt, wdt, ht, wt, cost);
		System.out.println("The Volume is: "+bs.volume());;
		System.out.println("The cost of the shipment is: "+bs.cost());
		sc.close();
	}
}
