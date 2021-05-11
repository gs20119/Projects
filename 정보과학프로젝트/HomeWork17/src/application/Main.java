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
		
		String dir = "view/anchorTest.fxml";
		Parent root = FXMLLoader.load(getClass().getResource(dir)); 
		// FXML ���Ͽ��� ���� �ҷ��� root�� �����
		
		Scene scene = new Scene(root); // scene�� root�� ���� �����
		primaryStage.setTitle("LOGIN");
		primaryStage.setScene(scene); // Stage(â)�� �ϳ��� Scene�� ���� �� ����
		primaryStage.show(); // Stage ���� 
		
	}

}
