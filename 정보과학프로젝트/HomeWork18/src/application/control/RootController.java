package application.control;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.fxml.Initializable;

public class RootController implements Initializable {

	@Override
	public void initialize(URL location, ResourceBundle resources) { }
	
	public void appleBtn(ActionEvent event) { System.out.println("APPLE"); }
	
	public void pearBtn(ActionEvent event) { System.out.println("PEAR"); }
	
}

// ��Ʈ�ѷ� : UI���� ���� ������ �۾��� �޾Ƶ��̴� �Լ� ���� (�ַ� �𵨿��� ó���ϵ��� �ѱ��)
// ���� �ش� �Լ����� �𵨿��� �ǵ��� ���� ������״�� ��Ʈ�ѷ��� UI�� ���� 