import java.util.Scanner;

class cCal
{
	public static void main(String args[])
	{
		int n1,n2;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the 1st complex number");
		n1 = sc.nextInt(); n2 = sc.nextInt();
		complex c1 = new complex(n1, n2);
		System.out.println("Enter the 2nd complex number");
		n1 = sc.nextInt(); n2 = sc.nextInt();
		complex c2 = new complex(n1, n2);
		System.out.print("Section which operation:\n 1: Addition\n 2: Multiplication\nEnter: ");
		n1 = sc.nextInt();
		sc.close();
		if(n1 == 1)
			c1.add(c2);
		else c1.mult(c2);
		if(c1.imag >= 0)
			System.out.println("The resultant complex number: "+c1.real+" + "+c1.imag+"i");
		else System.out.println("The resultant complex number: " + c1.real +" - "+ (-c1.imag)+"i");
	}
}

class complex
{
	int real, imag;
	complex(int n1, int n2)
	{
		real = n1;
		imag = n2;
	}
	void add(complex c)
	{
		real += c.real;
		imag += c.imag;
	}
	void mult(complex c)
	{
		int temp = real;
		real = real*c.real - imag*c.imag;
		imag = temp*c.imag + imag*c.real;
	}
}
