
#version 330 core
out vec4 FragColor;

uniform vec3 objectColor; // �ƿ� �� ���� ��Ҹ� ���⿡�� �޾ƹ���
uniform vec3 lightColor; // �������� layout in�� ���� �����޾���

void main(){
	FragColor = vec4(objectColor * lightColor, 1.0);
	// �ݻ�Ǵ� ���� ��ü�� ���� ���� ����
}