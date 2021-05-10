
final class Hi { }
// class Hi2 extends Hi{ } - final�̹Ƿ� X

abstract class Paper { // �̿ϼ� Ŭ���� 
	abstract void wri(); // �̿ϼ� �޼ҵ� wri - ������ �ۼ��� �� ����
	void asdf(int a) { System.out.println(a); }
} 

class GradPaper extends Paper{ // �̿ϼ� Ŭ������ �̿ϼ� �޼ҵ�� �ڽ��� �����޾� �ϼ�
	@Override
	void wri() { System.out.println("GradPaper"); } // �ϼ� �ڽ� Ŭ������� �ʼ�!!
	int go(int a) { return a*a; }  // ���� ���� ����, asdf�� �ٽ� ���� �ʾƵ� ��
	// abstract void wri(); X - �ϼ� Ŭ������ �̿ϼ� �޼ҵ带 ���� �� ����
	// void wri(); X - �����α��� �ۼ��ؾ� �ϼ��� �޼ҵ�
}

class BasicPaper extends Paper{ 
	@Override
	void wri() { System.out.println("BasicPaper"); } 
}

abstract class FPaper extends Paper{ }
// ���� �θ��� �̿ϼ� Ŭ������ �ϼ���Ű�� ���� ��� ���⿡�� abstract�� �ٿ��� ��

public class Hello {
	
	final static int a=10; // static final = constant
	static int width=200;
	static int height=100; // static field (Hello.height)
	static int max(int a, int b) { return a>b?a:b; } // static method (Hello.max)
	
	void write(int a, int b) { System.out.println(max(a,b)); }
	// static method�� �����Ӱ� ��� ����
	
	public static void main(String args[]) {
		
		max(1,2); // write(1,2); X - static���� nonstatic ȣ�� �Ұ���
		Hello test = new Hello();
		test.write(1,2);
		
		// Paper P = new Paper(); X - abstract�� constructor ��� �Ұ���
		GradPaper P1 = new GradPaper();
		BasicPaper P2 = new BasicPaper();
		Paper[] P = {P1,P2}; // polymorphism Ȱ��
		for(Paper p : P) { p.wri(); }
		
	}
}

