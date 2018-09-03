class Class1{
	void print1(){
		System.out.println("1st Class");
	}
}

class Class2{
	void print2(){
		System.out.println("2nd Class");
	}
}

class Main extends Class1, Class2{
	public static void main(String args[])
	{
		Main obj = new Main();
		obj.print1();
		obj.print2();
	}
}
