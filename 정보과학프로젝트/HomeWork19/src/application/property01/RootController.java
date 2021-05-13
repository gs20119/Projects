package application.property01;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.text.Font;

public class RootController implements Initializable {

	@FXML private Label label;
	@FXML private Slider slider; // �����̴��� �� ���� �б�/����
	
	@Override
	public void initialize(URL location, ResourceBundle resources) {
		slider.valueProperty().addListener((observable, oldValue, newValue) -> { 
			label.setFont(new Font(newValue.doubleValue()));
		}); // Slider�� ��ġ�� ��Ÿ���� Value --����ȭ-> Label�� ũ�⸦ ��Ÿ���� Font  
	}

}
