package application;
	
import javafx.application.Application;

import javafx.scene.control.Button;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;

public class HelloAdvanced extends Application { // �ݵ�� Application ���!
	
	public static void main(String[] args) { launch(args); }
	
	@Override
	public void start(Stage primaryStage) throws Exception {
		
		// root�� ���빰 ���� (FXML�� Ŀ���� �� �ִ� �κ�)
		Button btn = new Button("Click me");
		Button exit = new Button("Exit");
		
		btn.setOnAction( event -> {   
			System.out.println("hello world"); });
		
		exit.setOnAction( event -> { 
			System.out.println("exit this app");
			System.exit(0); });
	
		VBox root = new VBox(); // Step #1 root 
		root.getChildren().addAll(btn, exit); // root�� ��ư �߰� (�Ѳ����� : addAll)
		
		Scene scene = new Scene(root, 500, 300); // Step #2 Scene 
		primaryStage.setScene(scene); // Step #3 Stage 
		primaryStage.setTitle("My title"); 
		primaryStage.show(); // Stage = Window
	
	}

}

//�Լ��� �������̽� (������ �޼ҵ尡 ���� �ϳ��� �������̽�)�� ���ٽ� ����

// new EventHandler<ActionEvent>(){ 
// 		public void handle(Actionevent event){ ���� } } 

// event -> { ���� } 
// ���� ǥ�����̴�. �����ϸ� �ξ� ���ϰ� © �� �ִ�.

