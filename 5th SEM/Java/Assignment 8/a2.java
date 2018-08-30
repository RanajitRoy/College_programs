import java.util.Scanner;

interface Vehicle{
	double speed;
	int gear;
	void speedUp(double in);
	void changeGear(int gear);
	void speedDown(int dec);
}

class Car implements Vehicle{
	Car()
	{
		speed = 0;
		gear = 0;
	}
	Car(double s, int g)
	{
		speed = s;
		gear = g;
	}
	public void speedUp(double in)
	{
		speed += in;
	}
	public void changeGear(double gear)
	{
		this.gear = gear;
	}
	public void speedDown(double in)
	{
		speed -= dec;
	}
}

class Bike implements Vehicle{
	Bike()
	{
		speed = 0;
		gear = 0;
	}
	Bike(double s, int g)
	{
		speed = s;
		gear = g;
	}
	public void speedUp(double in)
	{
		speed += in;
	}
	public void changeGear(double gear)
	{
		this.gear = gear;
	}
	public void speedDown(double in)
	{
		speed -= dec;
	}
}

class Bicycle implements Vehicle{
	Bicycle()
	{
		speed = 0;
		gear = 0;
	}
	Bicycle(double s, int g)
	{
		speed = s;
		gear = g;
	}
	public void speedUp(double in)
	{
		speed += in;
	}
	public void changeGear(double gear)
	{
		this.gear = gear;
	}
	public void speedDown(double in)
	{
		speed -= dec;
	}
}

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the value of speed & gear: ");
		double s = sc.nextDouble();
		int g  = sc.nextInt();
		Car cr = new Car(s,g);
		Bike bk = new Bike(s,g);
		Bicycle bc = new Bicycle(s,g);
		cr.speedUp(5); bk.speedUp(3); bc.speedUp(1);
		System.out.println("The value of speed & gear of\n Car: "+cr.speed+" "+cr.gear);
		System.out.println(" Bike: "+bk.speed+" "+bk.gear);
		System.out.println(" Bicycle: "+bc.speed+" "+bc.gear);
		sc.close();
	}
}

