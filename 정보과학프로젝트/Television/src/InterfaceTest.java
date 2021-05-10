
interface RemoteControl{ // �������̽� = Ŭ������ ����� ���� Ʋ

	static final int MAX_VOLUME = 10; // 1. ��� - ������/����Ұ�
	static final int MIN_VOLUME = 0; 
	
	// 2. ���� �޼ҵ� - ������/����Ұ�
	public static void changeBattery(){ System.out.println("���͸� ��ü"); }
	// ��������� �ܺ� Ŭ���������� implement ���� �� �� ���� 
	
	public void turnOn(); // 3. �߻�޼ҵ� - ������ (�ʼ����� Ʋ) 
	public void turnOff();
	public void setVolume(int volume);
	
	default void setMute(boolean mute) { // 4. ����Ʈ�޼ҵ� - ������ (�������̵� ����)
		if(mute) { System.out.println("����ó��"); }
		else { System.out.println("��������"); }
	} // ����Ʈ �޼ҵ带 �������� ���� ��� ���õ� �����θ� ���

}

class Television implements RemoteControl{
	
	private int volume; // �ʵ�� ��� Ŭ���� ���ο��� �����ؾ� ��
	private boolean on;
	public Television(int volume, boolean on) { this.volume=volume; this.on=on; }
	
	public void turnOn() {
		if(on) System.out.println("�̹� ���� ���ݾ�!");
		else { on=true; System.out.println("TV ON"); }
	}public void turnOff() {
		if(on) { on=false; System.out.println("TV OFF"); }
		else System.out.println("...");
	}
	
	public void setVolume(int volume) {
		if(volume > RemoteControl.MAX_VOLUME)
			this.volume = RemoteControl.MAX_VOLUME;
		else if(volume < RemoteControl.MIN_VOLUME)
			this.volume = RemoteControl.MIN_VOLUME;
		else 
			this.volume = volume;
		System.out.println("Current TV volume"+this.volume);
	}
	
}

class Audio implements RemoteControl{
	
	private int volume;
	private boolean mute;
	private boolean on;
	public Audio(int volume, boolean on, boolean mute) 
	{ this.volume=volume; this.on=on; this.mute=mute; }
	
	public void turnOn() {
		if(on) System.out.println("�̹� ���� ���ݾ�!");
		else { on=true; System.out.println("Audio ON"); }
	}public void turnOff() {
		if(on) { on=false; System.out.println("Audio OFF"); }
		else System.out.println("...");
	}
	
	public void setVolume(int volume) {
		if(volume > RemoteControl.MAX_VOLUME)
			this.volume = RemoteControl.MAX_VOLUME;
		else if(volume < RemoteControl.MIN_VOLUME)
			this.volume = RemoteControl.MIN_VOLUME;
		else 
			this.volume = volume;
		System.out.println("Current Audio volume"+this.volume);
	}
	
	@Override
	public void setMute(boolean mute) {
		if(this.mute==mute) { System.out.println("�̹� �Ǿ� ���ݾ�!"); }
		if(mute) { System.out.println("Audio ����ó��"); }
		else { System.out.println("Audio ��������"); }
		this.mute=mute;
	}
	
}


public class InterfaceTest {
	public static void main(String[] args) {
		
		RemoteControl rc = null; // ������ Abstract�� �����
		
		rc = new Television(0,false); // ��������� Polymorphism Ȱ��
		rc.turnOn();
		rc.setMute(true);
		
		rc = new Audio(0,false,false);
		rc.turnOn();
		rc.setMute(true);
		
	}
}
