import java.util.Scanner;

class Account
{
	String name;
	int acc_no, balance=0, type;
	Account(String st, int acc, int t)
	{
		name = st; acc_no = acc; type = t;
	}
	void deposit(int sum)
	{
		balance += sum;
		System.out.println("New Balance = "+balance);
	}
	void display()
	{
		System.out.println("Balance = "+balance);
	}
	void withdrawal(int sum)
	{
		if(balance-sum<0)
			System.out.println("Not enough Balance!");
		else balance -= sum;
		System.out.println("New Balance = "+balance);
	}
}

class CurAcc extends Account
{
	int min_bal = 2000, charge = 20;
	CurAcc(String st, int acc)
	{
		super(st,acc,1);
	}
	void checkMin()
	{
		if(balance<min_bal)
		{
			balance -= charge;
			System.out.println("Balance is below minimum & service charge is deducted");
		}
		else System.out.println("Balance is above minimum");
	}
}

class SavAcc extends Account
{
	private int interest_rate = 4;
	SavAcc(String st, int acc)
	{
		super(st,acc,2);
	}
	void interest(int month)
	{
		balance += month*interest_rate*balance/100;
		System.out.println("New Balance = "+balance);
	}
}

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		CurAcc acc1;
		SavAcc acc2;
		String name;
		int acc_no, com, flag=1, type;
		System.out.print("Enter name: ");
		name = sc.nextLine();
		System.out.print("Enter type of account: ");
		type = sc.nextInt();
		System.out.print("Enter acc no.: ");
		acc_no = sc.nextInt();
		if(type == 1)
		{
			acc1 = new CurAcc(name, acc_no);
			System.out.println("Enter the following comands:");
			System.out.println(" 1: deposit");
			System.out.println(" 2: withdrawal");
			System.out.println(" 3: check if balance is minimum");
			System.out.println(" 4: check balance");
			System.out.println(" Any other key to exit");
			do{
				System.out.print("Enter command: ");
				com = sc.nextInt();
				switch(com)
				{
					case 1:	System.out.print("Enter the amount: ");
							acc1.deposit(sc.nextInt()); break;
					case 2:	System.out.print("Enter the amount: ");
							acc1.withdrawal(sc.nextInt()); break;
					case 3:	acc1.checkMin(); break;
					case 4:	acc1.display(); break;
					default: System.out.println("Bye!");
							 flag--;
				}
			}while(flag==1);
		}
		else if(type == 2)
		{
			acc2 = new SavAcc(name, acc_no);
			System.out.println("Enter the following comands:");
			System.out.println(" 1: deposit");
			System.out.println(" 2: withdrawal");
			System.out.println(" 3: claim interest");
			System.out.println(" 4: check balance");
			System.out.println(" Any other key to exit");
			do{
				System.out.print("Enter command: ");
				com = sc.nextInt();
				switch(com)
				{
					case 1:	System.out.print("Enter the amount: ");
							acc2.deposit(sc.nextInt()); break;
					case 2:	System.out.print("Enter the amount: ");
							acc2.withdrawal(sc.nextInt()); break;
					case 3:	System.out.print("Enter no. of year: ");
							acc2.interest(sc.nextInt()); break;
					case 4:	acc2.display(); break;
					default: System.out.println("Bye!");
							 flag--;
				}
			}while(flag==1);
		}
		else return;
		sc.close();
	}
}
