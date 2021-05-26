package application.view;

import java.net.URL;
import java.util.ResourceBundle;

import application.model.Simulation;
import javafx.animation.AnimationTimer;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;

public class RootController implements Initializable{

	@FXML Pane world;
	@FXML Button startButton, stopButton, stepButton;
	Simulation sim; // GUI ��Ʈ�ѷ��� �� ��ü ����
	
	private Timer clock;
	
	private class Timer extends AnimationTimer{ // �������� �̺�Ʈ�� �Ͼ�� clock�� ���
		
		private long FRAMES_PER_SEC = 50L;
		private long INTERVAL = 1000000000L / FRAMES_PER_SEC;
		
		private long last = 0;
		
		@Override
		public void handle(long now) { // ���� �̺�Ʈ ����
			if(now-last > INTERVAL) { step(); last = now; }
		}
	}
	
	@Override
	public void initialize(URL location, ResourceBundle resources) { // ���α׷� ����
		clock = new Timer();
		world.setBackground(new Background(new BackgroundFill(Color.WHITE, null, null)));
	}
	
	public void reset() { // Reset ��ư �Լ�
		stop();
		world.getChildren().clear(); // ����� - ����!
		sim = new Simulation(world, 100);
	}
	
	public void start() { clock.start(); disableButtons(true,false,true); } 
	public void step() { sim.move(); sim.draw(); }
	public void stop() { clock.stop(); disableButtons(false,true,false); }
	
	public void disableButtons(boolean start, boolean stop, boolean step) {
		startButton.setDisable(start);
		stopButton.setDisable(stop);
		stepButton.setDisable(step);
	}
	
}
