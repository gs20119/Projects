package scenebuild_event;

import java.util.Random;
import javafx.event.ActionEvent;
import javafx.fxml.FXML; // @FXML ���
import javafx.scene.control.Label;
import javafx.scene.control.Button;

public class MainController { 
	
	@FXML // �ݵ�� �߰�
	private Label redMessage; // FXML���� ����� fx:id�� ��ġ�ؾ� ��
	
	@FXML
	private Label greenMessage;
	
	@FXML
	private Label pinkMessage;
	
	public void generateRandom(ActionEvent event) { // ��ư�� OnAction�� ��
		String value = ((Button)event.getSource()).getText();
		Random rand = new Random();
		int myrand = rand.nextInt(50)+1;
		if(value.equals("��")) redMessage.setText(Integer.toString(myrand));
		else if(value.equals("��")) greenMessage.setText(Integer.toString(myrand));
		else if(value.equals("�Ӷ�")) pinkMessage.setText(Integer.toString(myrand));
	}
	
}
