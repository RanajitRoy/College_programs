class Main{
	public static void main(String arg[]){
		int a,b;
		try{
			a = Integer.parseInt(arg[0]);
			try{
				b = Integer.parseInt(arg[1]);
				System.out.println(a/b);
			}
			catch(NumberFormatException E)
			{
				System.out.println("only integer");
			}
			catch(ArrayIndexOutOfBoundsException E)
			{
				System.out.println("error!");
			}
		}
		catch(ArithmeticException E)
		{
			System.out.println("divided by zero!");			
		}
	}
}