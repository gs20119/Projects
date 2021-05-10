package application;
	
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;


public class Main extends Application {
	public Main() { // App Thread ���
		System.out.println(Thread.currentThread().getName() + ": Main() call"); 
	} 
	
	@Override
	public void init() throws Exception { // Launcher ����
		System.out.println(Thread.currentThread().getName() + ": init() call");
	}
	
	@Override
	public void start(Stage primaryStage) throws Exception { // Stage = ������ 
		
		System.out.println(Thread.currentThread().getName() + ": start() call");
		BorderPane root = new BorderPane();
		Scene scene = new Scene(root,400,400); // scene ��ü ����
		
		primaryStage.setTitle("hello JavaFX"); // Stage�� title ����
		primaryStage.setScene(scene); // Stage�� scene ����
		primaryStage.show(); // ������(Stage) �����ֱ�
		
	}
	
	@Override
	public void stop() throws Exception {
		System.out.println(Thread.currentThread().getName() + ": stop() call");
	}
	
	public static void main(String[] args) {
		launch(args); // App Thread + Launcher ����
	}
}

//JAVAFX�� lifecycle - �ֿ� ���� �޼ҵ�
	// launch() - ��ü�� App Thread + Launcher ����
	// init() - ��ü ���� �� ȣ��, Launcher ����
	// start() - App Thread���� �⺻ ������â�� UI ȣ��
	// stop() - App Thread���� ������ Stage ������ ȣ��

