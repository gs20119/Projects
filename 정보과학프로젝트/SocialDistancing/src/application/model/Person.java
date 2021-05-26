package application.model;

import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class Person { // ���� ����Ʈ : Person�� ���� �̷���� �ִ°�?
	
	public static final int radius = 5; 
	
	private State state;
	private Position loc;
	private Moving moving;
	private Circle c;
	private Pane world;
	// ����, ��ġ, �ӵ�, ���´� ���� ���� ����!
	
	public Person(State state, Pane world) { // Ŭ������ �⺻ : Construct
		this.state = state;
		this.moving = new Moving();
		this.loc = new Position(world, radius);
		this.c = new Circle(radius, state.getColor());
		this.world = world;
		c.setStroke(Color.BLACK); // ���°� ������ �ٷ� �׷��Ƚ� ����
		world.getChildren().add(c); // ���¸� world���� �׷��ֵ��� ����!!
	}
	
	public State getState() { return this.state; } // private field - getter
	public void setState(State state) { // private field - setter
		this.state = state;
		c.setFill(state.getColor()); 
	}
	
	public void move() { loc.move(moving, world); } // ��ġ Ŭ������ ���� �ѱ��
	public void draw() { // ��ü�� ����Ǿ��ִ´�� �׸��� ��Ű��
		c.setRadius(radius);
		c.setTranslateX(loc.getX()); 
		c.setTranslateY(loc.getY());
	}
}
