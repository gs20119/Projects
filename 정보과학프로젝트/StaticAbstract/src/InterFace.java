
interface Global{ // interface�� �߻�Ŭ������ ����� Ư���� ����
	public static int grade = 2;
	public abstract void global();
}

interface Local{
	public static int grade = 2;
	public abstract void local();
}

interface Global_21 extends Global, Local{ // �̰� ���� - �������̽����� Ư��
	public abstract void zR();
}

class Gshs2 implements Global_21{ // Ŭ����-�������̽��� implements ���
	// Global, Local, Global21�� �޼ҵ带 ��� �ϼ�
	public void zR() { }
	public void local() { }
	public void global() { }
}

class A{ } class B{ }
// class C extends A,B{ } - �̰� �Ұ���

public class InterFace {
	public static void main(String args[]) { }
}
