
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

out vec3 vertexColor;
out vec2 texCoord;
uniform mat4 transform; // ��ȯ��ķ� ����

void main(){
	vertexColor = aColor;
	texCoord = aTex;
	gl_Position = transform * vec4(aPos, 1.0); 
	// aPos�� transform�� ����� ��� ��ȯ��
}