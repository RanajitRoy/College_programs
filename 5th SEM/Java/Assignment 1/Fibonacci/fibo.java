class fibo
{
	public static void main(String[] args)
	{
		int f1=0, f2=1, temp, count = Integer.parseInt(args[0]);
		System.out.print("Fibonacci numbers are : ");
		for(int i=0;i<count;i++)
		{
			System.out.print(f1+", ");
			temp = f1;
			f1 = f2;
			f2 = temp + f2;
		}
		System.out.println();
	}
}
