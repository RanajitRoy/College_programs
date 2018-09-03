import java.util.Scanner;

interface Vehicle{
	void speedUp(double in);
	void changeGear(int gear);
	void speedDown(int dec);
}

class Car implements Vehicle{
	double speed;
	int gear;
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
	public void changeGear(int gear)
	{
		this.gear = gear;
	}
	public void speedDown(int dec)
	{
		speed -= dec;
	}
}

class Bike implements Vehicle{
	double speed;
	int gear;
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
	public void changeGear(int gear)
	{
		this.gear = gear;
	}
	public void speedDown(int dec)
	{
		speed -= dec;
	}
}

class Bicycle implements Vehicle{
	double speed;
	int gear;
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
	public void changeGear(int gear)
	{
		this.gear = gear;
	}
	public void speedDown(int dec)
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
		cr.speedDown(2); bk.speedDown(4); bc.speedDown(2);
		cr.changeGear(4); bk.changeGear(2);
		System.out.println("The value of speed & gear of\n Car: "+cr.speed+" "+cr.gear);
		System.out.println(" Bike: "+bk.speed+" "+bk.gear);
		System.out.println(" Bicycle: "+bc.speed+" "+bc.gear);
		sc.close();
	}
}

