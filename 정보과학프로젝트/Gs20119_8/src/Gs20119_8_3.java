
class Mp3{
	String comp = "������";
	String size = "2GB";
	
	Mp3(String comp, String size){
		this.comp=comp; this.size=size;
	}Mp3(String comp){ this.comp=comp; }
	Mp3(){ }
	
	String getComp() { return comp; }
	String getSize() { return size; }
	
	void setComp(String comp) { this.comp=comp; }
	void setSize(String size) { this.size=size; }
	void print() { 
		System.out.println("����ȸ��� : "+comp+"  �޸𸮿뷮 : "+size);
	}
}

class Mp3Test{
	static int N = 0;
	static void Add(int n) { N += n; }
	static void Set(int n) { N = n; }
	static void main(String[] args) {
		for(int i=0; i<N; i++) {
			Mp3 m = Gs20119_8_3.M[i];
			m.print();
		}
	}
}

public class Gs20119_8_3 {
	static Mp3[] M = new Mp3[10];
	public static void main(String[] args) {
		M[0] = new Mp3("���̸���","4GB");
		M[1] = new Mp3("�Ｚ yepp","2GB");
		M[2] = new Mp3("2GB");
		Mp3Test.Set(3);
		Mp3Test.main(args);
	}
}
