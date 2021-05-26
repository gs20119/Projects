package application.model;

import java.util.ArrayList;

import javafx.scene.layout.Pane;

public class Simulation { // Person�� ������ �����ϴ� ���
	
	private ArrayList<Person> people; // java�� vector
	
	public Simulation(Pane world, int popSize) { // �ʱ����
		people = new ArrayList<Person>();
		for(int i=0; i<popSize; i++) { people.add(new Person(State.SUSCEPTIBLE, world)); }
		people.add(new Person(State.INFECTED, world)); 
		draw();
	}
	
	public ArrayList<Person> getPeople(){ return people; }
	public void move() { for(Person p : people) { p.move(); }} // �̵��� �׸��� Person���� �ѱ��
	public void draw() { for(Person p : people) { p.draw(); }}
	
}
