package test.exam.access01.package01;

public class B {
	public B() {
		A a = new A(); // A() �����ڴ� Field03�� ���ٰ���������
		
		a.Field01 = 3;
		a.Field02 = 2; 
		
		a.method01();
		a.method02();

		// a2.Field03=1; // ������� a2�� Field03�� ������ �� ����  
		// A a1 = new A("Hello"); // private�̶� ���� �Ұ��� 
	}
}
