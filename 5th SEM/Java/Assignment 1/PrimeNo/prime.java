class prime
{
	public static void main(String[] args)
	{
		int i, j, n = Integer.parseInt(args[0]);
		System.out.print("Prime Nos.: ");
		for(i=2; i<=n; i++)
		{
			for(j=2; j<i && i%j!=0; j++)
			{
				continue;
			}
			if(i == j)
			{
				System.out.print(i+", ");
			}
		}
		System.out.println();
	}
}
