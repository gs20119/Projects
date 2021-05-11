package application.control;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;

public class RootController implements Initializable {
	
	@FXML TextField id; // ��Ʈ�ѷ��� ���� �аų� �����ؾ� �ϴ� UI ��Ҵ�
	@FXML TextField pw; // �̷��� @FXML�� ���� �ڵ带 ������ ��� ��
	
	@Override
	public void initialize(URL location, ResourceBundle resources) { }
	
	public void confirm(ActionEvent event) { // confirm ��ư ������ �۾� ����
		System.out.println(id.getText().toString());
		System.out.println(pw.getText().toString()); // �ܼ� ��µ� ����
	}
	
	public void cancel(ActionEvent event) { // cancel ��ư ������ �۾� ����
		id.setText("");
		pw.setText(""); // UI�� ������� ���� (����)
	}
	
}

// ��Ʈ�ѷ� : UI���� ���� ������ �۾��� �޾Ƶ��̴� �Լ� ���� (�ַ� �𵨿��� ó���ϵ��� �ѱ��)
// ���� �ش� �Լ����� �𵨿��� �ǵ��� ���� ������״�� ��Ʈ�ѷ��� UI�� ���� 