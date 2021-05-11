package scenebuild;

import javafx.application.Application;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class Main extends Application { // �ݵ�� Application ���!
	
	public static void main(String[] args) { launch(args); }
	
	@Override
	public void start(Stage primaryStage) throws Exception {
		
		// Step #1 root (FXML�� �ѹ濡 ó��)
		Parent root = FXMLLoader.load(getClass().getResource("/scenebuild_event/Main.fxml"));
		
		// Step #2 scene (CSS ���Ϸ� �߰� ó��)
		Scene scene = new Scene(root,400,400); // Step #2 Scene
		scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
		
		primaryStage.setTitle("My title"); // Step #3 Stage
		primaryStage.setScene(scene);
		primaryStage.show();
		
	}

}

// ���� fxml�� css ���� ��θ� �ٲٸ� 
// �����Ӱ� JavaFX ���ø����̼��� ���� �� ����