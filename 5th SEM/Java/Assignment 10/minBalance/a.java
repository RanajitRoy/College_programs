class Acc{
	int balance;
	Acc(){
		balance = 1000;
	}
	Acc(int deposit){
		balance = deposit;
	}
	void withdrawal(int sum) throws LowBalance{
		if(balance-sum>1000){
			balance -= sum;
			System.out.println("Updated balance: "+balance);
		}
		else{
			balance -= sum;
			throw new LowBalance(balance);
		}
	}
}

class LowBalance extends Exception{
	String s;
	LowBalance(int bal)
	{
		System.out.println("Updated Balance: "+bal);
		if(bal<1000)
			s = "Low Balance!";
	}

	public String toString(){
		return s;
	}
}

class Main{
	public static void main(String args[]){
		Acc myac = new Acc(5000);
		try{
			myac.withdrawal(3000);
			myac.withdrawal(1500);
		}
		catch(LowBalance E){
			System.out.println(E);
		}
	}
}