
import java.util.Scanner;

class Car {
	
	Tire[] T = new Tire[4];
	static Scanner input = new Scanner(System.in);
	static String[] tireName = { "FrontLeftTire", "FrontRightTire", 
			"BackLeftTire", "BackRightTire" };
	
	public Car() {
		int mRot; 
		for(int i=0; i<4; i++) {
			System.out.printf(tireName[i]+"�� ���� ���� �Է� : ");
			mRot = input.nextInt();
			T[i] = new Tire(tireName[i],mRot);
		}System.out.println("���ο� ���� ���� �Ϸ�!");
		System.out.println("++++++++++++++++++++");
	}
	
	public int run() { 
		System.out.println("�ڵ��� ������");
		for(int i=0; i<4; i++) { 
			if(!T[i].roll()){ stop(i); break; } 
		}System.out.println("+++++++++++++++++++++");
		return 0;
	}
	
	void stop(int i) { 
		System.out.println("�ڵ��� ����!!");
		System.out.printf("� Ÿ�̾�� ��ü�ϰ� �����Ű���? [A:1|B:2|�⺻:Else] : ");
		int X = input.nextInt();
		switch(X) {
		case 1: 
			System.out.println(tireName[i]+" A�� Ÿ�̾�� ��ü");
			T[i] = new ATire(tireName[i], ATire.maxRotation);
			break;
		case 2:
			System.out.println(tireName[i]+" B�� Ÿ�̾�� ��ü");
			T[i] = new BTire(tireName[i], BTire.maxRotation);
			break;
		default:
			System.out.println(tireName[i]+" �⺻�� Ÿ�̾�� ��ü");
			T[i] = new Tire(tireName[i], Tire.maxRotation);
			break;
		}
	}
}

class Tire {
	public static int maxRotation = 10;
	int Rotationleft;
	String location;
	
	public Tire(String loc, int mRot) { 
		location = loc; Rotationleft = mRot;
	}
	
	public boolean roll() { 
		Rotationleft--;
		if(Rotationleft>0) { callRotationLeft(); return true; }
		else { callWarning(); return false; }
	}
	
	void callRotationLeft() {
		System.out.println(location+" - Ÿ�̾� ���� ���� : "+Rotationleft);
	}
	
	void callWarning() {
		System.out.println(location+" ** Ÿ�̾� ��ü �ʿ� **");
	}
}

class ATire extends Tire {
	public static int maxRotation = 12;
	public ATire(String loc, int Rotation) { super(loc,Rotation); }
	@Override
	void callRotationLeft() {
		System.out.println(location+" - A Ÿ�̾� ���� ���� : "+Rotationleft);
	}
}

class BTire extends Tire {
	public static int maxRotation = 13;
	public BTire(String loc, int Rotation) { super(loc,Rotation); }
	@Override
	void callRotationLeft() {
		System.out.println(location+" - B Ÿ�̾� ���� ���� : "+Rotationleft);
	}
}

public class CarTest {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) {
		Car Benz = new Car();
		System.out.printf("������ �󸶳� �����ұ��? : ");
		int N = input.nextInt();
		for(int i=0; i<N; i++) Benz.run();
	}
}