package test.exam.access01.package01;

public class A { // ������ ù ������ public�̳� default�� ����
	// ���� ������ public���� ����, ���࿡�� ���� �ٸ� Ŭ������ default�� ���
	
	A a1 = new A(true); // public ������ ����� a1
	A a2 = new A(); // default ������ �� a2
	A a3 = new A("Hello"); // private �� a3
	
	public int Field01;
	int Field02;
	private int Field03;
	
	A() { // ������ - Constructor
		Field01 = 1;
		Field02 = 1;
		Field03 = 1; // �ڱ� Ŭ���������� private���� ���ٰ���
		
		method01();
		method02();
		method03();
	}
	
	public void method01() { } // �޼ҵ� - Method
	void method02() { }
	private void method03() { }
	
	private A(String str) { }
	public A(boolean b) { }
	
}
