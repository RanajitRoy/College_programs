import java.util.Scanner;

abstract class Shape{
	protected double x, y, area;
	Shape(){x=y=0;}
	Shape(double x){this.x=x;}
	Shape(double x, double y)
	{
		this.x = x;
		this.y = y;
	}
	abstract void area();
	abstract void disp();
}

class Rectangle extends Shape{
	Rectangle(double x, double y){super(x,y);}
	Rectangle(){super();}
	void area(){this.area = x*y;}
	void disp()
	{
		System.out.println("Area of Rectangle: "+area);
	}
}

class Triangle extends Shape{
	Triangle(double x, double y){super(x,y);}
	Triangle(){super();}
	void area(){this.area = 0.5*x*y;}
	void disp()
	{
		System.out.println("Area of Triangle: "+area);
	}
}

class Circle extends Shape{
	Circle(double x){super(x);}
	Circle(){super();}
	void area(){this.area = Math.PI*x*x;}
	void disp()
	{
		System.out.println("Area of Circle: "+area);
	}
}

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		Shape sp;
		System.out.print("Enter the value of x & y: ");
		double x = sc.nextDouble(), y = sc.nextDouble();
		sp = new Rectangle(x,y);
		sp.area(); sp.disp();
		sp = new Triangle(x,y);
		sp.area(); sp.disp();
		sp = new Circle(x);
		sp.area(); sp.disp();
		sc.close();
	}
}

