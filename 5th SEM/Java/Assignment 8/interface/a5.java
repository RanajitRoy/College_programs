interface Inter1{
	void foo1(Main obj);
}

interface Inter2{
	void foo2(Main obj);
}

interface Inter3 extends Inter1, Inter2{
	void foo3(Main obj);
}

class Class1{
	int gem = 8;
	public void foo1(Main obj){
		System.out.println("Gem from 1st interface: "+obj.gem);
	}
	public void foo2(Main obj){
		System.out.println("Gem from 2nd interface: "+obj.gem);
	}
	public void foo3(Main obj){
		System.out.println("Gem from 3rd interface: "+obj.gem);
	}
}

class Main extends Class1 implements Inter3{
	public static void main(String args[]){
		Main obj = new Main();
		obj.foo1(obj);
		obj.foo2(obj);
		obj.foo3(obj);
	}
}