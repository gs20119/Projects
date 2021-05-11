package application;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {
	
	public static void main(String[] args) { launch(args); }
	
	@Override
	public void start(Stage primaryStage) throws Exception {
		
		String dir = "view/fruitView.fxml";
		Parent root = FXMLLoader.load(getClass().getResource(dir)); 
		// FXML ���Ͽ��� ���� �ҷ��� root�� �����
		
		Scene scene = new Scene(root); // scene�� root�� ���� �����
		primaryStage.setScene(scene); // Stage(â)�� �ϳ��� Scene�� ���� �� ����
		primaryStage.setTitle("Fruit");
		primaryStage.setOnCloseRequest(event->System.out.println("����")); 
		primaryStage.show(); // Stage ���� 
		// new �Լ����������̽�(){ �޼ҵ�(�Ű�����){ ����  } }
		// (�Ű�����) -> { ����  }                        
		
	}

}
