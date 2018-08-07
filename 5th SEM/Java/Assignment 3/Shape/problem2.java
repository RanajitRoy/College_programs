import java.util.Scanner;
import java.lang.Math;

class Main2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the shape: ");
		String len=sc.next();
		Shape sh = new Shape();
		switch(len)
		{
			case "circle":		System.out.print("Enter the radius: ");
								double radius = sc.nextDouble();
								sh.area(radius);
								break;
			case "rectangle":	System.out.print("Enter the length: ");
								double length = sc.nextDouble();
								System.out.print("Enter the breadth: ");
								double breadth = sc.nextDouble();
								sh.area(length, breadth);
								break;
			case "triangle":	System.out.print("Enter the 1st side length: ");
								double tri1 = sc.nextDouble();
								System.out.print("Enter the 2nd side length: ");
								double tri2 = sc.nextDouble();
								System.out.print("Enter the 3rd side length: ");
								double tri3 = sc.nextDouble();
								sh.area(tri1, tri2, tri3);
								break;
			default: System.out.println("No such Shape!!");
		}
		System.out.println("The area is "+sh.area);
		sc.close();
	}
}

class Shape
{
	double area;
	void area(double n1) { area = Math.PI*n1*n1; }
	void area(double n1, double n2) { area = n1*n2; }
	void area(double n1, double n2, double n3)
	{
		double s = (n1+n2+n3)/2;
		area = Math.sqrt(s*(s-n1)*(s-n2)*(s-n3));
	}
}
