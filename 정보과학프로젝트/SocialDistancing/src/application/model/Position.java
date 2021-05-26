package application.model;

import javafx.scene.layout.Pane;

public class Position {
	
	private double x;
	private double y;
	
	public Position(double x, double y) { this.x = x; this.y = y; }
	public Position(Pane world, int radius) {
		this(Math.random()*(world.getWidth()-2*radius), 
				Math.random()*(world.getHeight()-2*radius));
	} // �̷��� �������� : world�� ũ�Ⱑ �ǽð����� �ٲ�� ����
	
	public double getX() { return this.x; } 
	public double getY() { return this.y; }
	
	public double distance(Position other) {
		double Dx = this.x-other.x;
		double Dy = this.y-other.y;
		return Math.sqrt(Math.pow(Dx,2) + Math.pow(Dy,2));
	}
	
	public void move(Moving moving, Pane world) {
		
		x += moving.getDx();
		y += moving.getDy();
		
		if(x < 0 || x > world.getWidth()) {
			moving.bounceX();
			x += moving.getDx(); 
		}
		if(y < 0 || y > world.getHeight()) {
			moving.bounceY();
			y += moving.getDy(); 
		}

	}
	
}
