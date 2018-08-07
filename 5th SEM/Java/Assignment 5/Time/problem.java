import java.util.Scanner;

class Time
{
	int hour, min, sec;
	Time()
	{
		hour=0;
		min=0;
		sec=0;
	}
	Time(int n1, int n2, int n3)
	{
		hour=n1;
		min=n2;
		sec=n3;
	}
	Time add(Time t2)
	{
		Time t3 = new Time();
		t3.sec = (sec+t2.sec);
		t3.min = (min+t2.min+t3.sec/60);
		t3.hour = (hour+t2.hour+t3.min/60);
		t3.sec=t3.sec%60;
		t3.min=t3.min%60;
		t3.hour=t3.hour%60;
		return t3;
	}
}

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter time(hour, min, sec) for 1st obj: ");
		Time t1 = new Time(sc.nextInt(),sc.nextInt(),sc.nextInt());
		System.out.println("Enter time(hour, min, sec) for 2nd obj: ");
		Time t2 = new Time(sc.nextInt(),sc.nextInt(),sc.nextInt());
		Time t3 = t1.add(t2);
		System.out.println("Resultant time: "+t3.hour+" hour, "+t3.min+" min, "+t3.sec+" sec");
		sc.close();
	}
}