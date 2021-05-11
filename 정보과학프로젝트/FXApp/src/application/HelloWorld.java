package application;
	
import javafx.application.Application;

import javafx.scene.control.Button;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;

public class HelloWorld extends Application { // �ݵ�� Application ���!
	
	public static void main(String[] args) { launch(args); }
	
	@Override
	public void start(Stage primaryStage) throws Exception {
		
		// root�� ���빰 ���� (FXML�� Ŀ���� �� �ִ� �κ�)
		Button btn = new Button("Click me");
		
		EventHandler<ActionEvent> hello = new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent event) {
				System.out.println("hello world"); }
		}; // EventHandler<ActionEvent>�� �������̽�, ������ �������Ѱ�
		
		btn.setOnAction( hello ); // ��ư�� ������ �߰��ϱ� ���� 
		
		StackPane root = new StackPane(); // Step #1 root ���� 
		root.getChildren().add(btn); // root�� ��ư �߰� 
		
		Scene scene = new Scene(root, 500, 300); // Step #2 Scene ����
		primaryStage.setScene(scene); // Step #3 Stage�� Scene �߰�
		primaryStage.show(); // Stage = Window
	
	}
	
}
