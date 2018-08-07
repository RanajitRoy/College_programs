import java.util.Scanner;

class Person
{
	String name, hobby="Reading";
	Person(String n)
	{
		name=n;
	}
}

class Student extends Person
{
	Student(String n)
	{
		super(n);
		super.hobby="Facebook";
	}
}

class CSE_student extends Student
{
	CSE_student(String n)
	{
		super(n);
		super.hobby="Hacking";
	}
}

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the following command:");
		System.out.println(" 1. In Birthday party");
		System.out.println(" 2. get-together");
		System.out.println(" 3. In closed doors");
		int p=sc.nextInt();
		System.out.println("Enter Name: ");
		switch(p)
		{
			case 1:	Person ob1 = new Person(sc.next());
					System.out.println("Hello, my name is "+ob1.name+" and my hobby is "+ob1.hobby+"."); break;
			case 2: Student ob2 = new Student(sc.next());
					System.out.println("Hello, my name is "+ob2.name+" and my hobby is "+ob2.hobby+"."); break;
			case 3: CSE_student ob3 = new CSE_student(sc.next());
					System.out.println("Hello, my name is "+ob3.name+" and my hobby is "+ob3.hobby+"."); break;
			default:System.out.println("Invalid input!");
		}
		sc.close();
	}
}