import java.util.Scanner;

class InviteExcept extends Exception{
	String str;
	InviteExcept()
	{
		str = new String("Invited already!");
	}
	public String toString(){
		return str;
	}
}

class Main{
	public static void main(String args[]){
		System.out.println("Invite to party-");
		System.out.println(" 1:Anindita");
		System.out.println(" 2:Sreejita");
        System.out.println(" 3:Amit");
        Scanner sc = new Scanner(System.in);
		try{
			invite(sc);
		}
		catch(InviteExcept E){
			System.out.println(E);
        }
        finally{
            sc.close();
            System.out.println("Scanner object closed!");
        }
    }
    
    static void invite(Scanner sc) throws InviteExcept{
        if(sc.nextInt()==3){
            System.out.println("OK!");
        }
        else throw new InviteExcept();
    }
}