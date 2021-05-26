package application.properties;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.effect.MotionBlur;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.RadialGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Rectangle;

public class RootController implements Initializable {

	@FXML Canvas canvas; // fxml ������ Canvas�� ���� �;�!
	@FXML Rectangle rect; // �ƴϸ� ���� ������ ������ ����
	GraphicsContext gc; // canvas�� �ٷ� ���� context�� �޾Ƽ� �����ؾ� �Ѵ�.
	
	@Override
	public void initialize(URL location, ResourceBundle resources) {
		gc = canvas.getGraphicsContext2D(); 
		//Image image = new Image(getClass().getResourceAsStream("up.jpg"));
		//gc.drawImage(image, 100, 100); // �̹����� ������� �ְ� ������
		draw(); drawGrad(); // context �޾Ƽ� �׸���
	}

	private void drawGrad() {
		Stop[][] stop = new Stop[2][];
		stop[0] = new Stop[] {
			new Stop(0,Color.RED),
			new Stop(1,Color.BLUE) };
		stop[1] = new Stop[] {
			new Stop(0,Color.YELLOW),
			new Stop(1,Color.RED) };
		
		LinearGradient lg = new LinearGradient(0,0,1,0, true, CycleMethod.NO_CYCLE, stop[0]);
		gc.setFill(lg); // Gradient�� ���� �ش�
		gc.fillRect(50, 50, 100, 100);
		
		RadialGradient rg = new RadialGradient(0,0,100,100,100, false, CycleMethod.NO_CYCLE, stop[1]);
		gc.setFill(rg);
		gc.fillOval(75, 75, 100, 100);
	}

	private void draw() {
		gc.setFill(Color.AQUAMARINE); // ����Ʈ ���� = setFill
		gc.setStroke(Color.rgb(123, 213, 100)); // �� ���� = setStroke
		gc.fillRect(30, 30, 150, 150); // ĥ�ϱ� = fill
		gc.strokeOval(90, 90, 50, 50); // �׸��� = stroke
		
		gc.setFill(Color.BLACK);
		gc.fillText("iPad Pro", 80, 20); 
		
		rect.setEffect(new MotionBlur(0,90));
		rect.setStroke(Color.BLUE); 
		// rect.setFill : FXML ���Ͽ��� ���� �ٷ��� - ������ ���!
	}
	
}
