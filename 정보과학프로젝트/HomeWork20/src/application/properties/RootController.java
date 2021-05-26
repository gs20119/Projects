package application.properties;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;

public class RootController implements Initializable {

	@FXML Canvas canvas; // fxml ������ Canvas�� ���� �;�!
	GraphicsContext gc; // canvas�� �ٷ� ���� context�� �޾Ƽ� �����ؾ� �Ѵ�.
	
	@Override
	public void initialize(URL location, ResourceBundle resources) {
		gc = canvas.getGraphicsContext2D(); 
		gc.setFill(Color.BLUE);
		gc.fillRect(0, 0, 200, 200);
		canvas.addEventHandler(MouseEvent.MOUSE_DRAGGED, (event) -> {
			gc.clearRect(event.getX()-2, event.getY()-2, 5, 5);
		}); // �̺�Ʈ�߰��� canvas�� ���� - ���� �����ٰ� ������ �������� ����
	} // �������� �۾��� �� �� : �����̰� �⺻���� Ʋ �����ο��� �ش�
} 
