
import java.util.Scanner; // �Է��� �޴� ��ĳ�� �ҷ�����

public class Classroom {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in); // input = Scanner Ŭ���� ��ü
		Scanner st = new Scanner(System.in);
		
		int a = input.nextInt(); // ���� �Է�
		int b = input.nextInt();
		String str = st.nextLine(); // ������ ���� ���ڿ� �Է�
		String word = st.next(); // ���� or ������ ���� ���ڿ� �Է�
		
		System.out.println(a+b);
		System.out.println(str);
		System.out.println(word);
		
		input.close(); // Scanner ��ü �ݱ�
		st.close();
	}
}
