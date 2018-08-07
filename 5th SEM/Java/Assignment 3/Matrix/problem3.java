import java.util.Scanner;

class Main3
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("For 1st Matrix,\n Enter the no. of row: ");
		int r=sc.nextInt();
		System.out.print(" Enter the no. of col: ");
		int c=sc.nextInt();
		Matrix mtx1 = new Matrix(r,c);
		mtx1.getValue();
		System.out.print("For 2nd Matrix,\n Enter the no. of row: ");
		r=sc.nextInt();
		System.out.print(" Enter the no. of col: ");
		c=sc.nextInt();
		Matrix mtx2 = new Matrix(r,c);
		mtx2.getValue();
		System.out.println("\nThe result is:");
		mtx1.add(mtx2);
		mtx1.display();
		sc.close();
	}
}

class Matrix
{
	int row, col;
	int mtx[][];
	Matrix(int m, int n)
	{
		row = m;
		col = n;
		mtx = new int[row][col];
	}
	void getValue()
	{
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				mtx[i][j] = sc.nextInt();
			}
		}
	}
	void add(Matrix mtx2)
	{
		if(row!=mtx2.row || col!=mtx2.col)
		{
			System.out.println("Not possible!!");
		}
		else
		{
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					mtx[i][j] += mtx2.mtx[i][j];
				}
			}
			System.out.println("Done!");
		}
	}
	void display()
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				System.out.print("  "+mtx[i][j]);
			}
			System.out.println();
		}
	}
}
