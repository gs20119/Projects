
#version 330 core
in vec3 vertexColor;
in vec2 texCoord;
out vec4 FragColor;
uniform sampler2D ourTexture; // ��ü���� �ڵ����� �Ҵ����
void main(){
	//FragColor = vec4(vertexColor, 1.0);
	FragColor = texture(ourTexture, texCoord) * vec4(vertexColor, 1.0);
	//ourTexture���� �ؽ��� �ް�, TexCoord ����� �ڸ���
}