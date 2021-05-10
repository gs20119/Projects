package application;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class FirstTest extends Application {
	
	@Override
	public void start(Stage primaryStage) throws Exception {
		
		// VBOX ����
		VBox root = new VBox(); 
		root.setPrefWidth(350);
		root.setPrefHeight(150);
		root.setAlignment(Pos.CENTER); // Pos ������
		root.setSpacing(20);
		
		// label + button = control 
		Label label = new Label(); // label ����
		label.setText("Hello Label");
		label.setFont(new Font(50));
		
		Button button = new Button(); // button ����
		button.setText("����");
		button.setOnAction(event->Platform.exit());
		
		// root�� ��� control �߰�
		root.getChildren().add(label);
		root.getChildren().add(button);
		
		Scene scene = new Scene(root); // ���� root�� scene ����
		
		primaryStage.setScene(scene); // ���� scene �����쿡 �ο� 
		primaryStage.setTitle("app main"); // ������ title �ο�
		primaryStage.show(); // ������(Stage) �����ֱ�
		
	}
	
	public static void main(String[] args) {
		launch(args); // ����
	}

}
