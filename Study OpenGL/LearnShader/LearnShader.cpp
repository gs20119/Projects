
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

float vertices[] = { 
	0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // xyz rgb (Attrib 2����)
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   
	0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
};

const char* VertexShaderSource = // �������̴� = ����&�ʱ��Է´��
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n" // VAO 0�������Ϳ��� �ִ� ������ �ޱ� 
"layout (location = 1) in vec3 aColor;\n" // VAO 1�������Ϳ��� �ִ� ������ �ޱ�
"uniform float xoffset;\n"
"out vec3 vertexColor;\n" // �̰� FragmShader�� ����������
"void main(){\n"
"	vertexColor = aColor;\n"
"	gl_Position = vec4(aPos.x+xoffset, aPos.yz, 1.0);\n"
"}\n\0";

const char* FragmShaderSource = // �ȼ����̴� = ��ĥ���
"#version 330 core\n"
"in vec3 vertexColor;\n" // VertexShader���� ��������
"out vec4 FragColor;\n"
"void main(){\n"
"	FragColor = vec4(vertexColor, 1.0);\n" 
"}\n\0";

void processEsc(GLFWwindow *wndw) {
	if (glfwGetKey(wndw, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(wndw, true);
}

void processFillorNot(GLFWwindow *wndw) {
	if (glfwGetKey(wndw, GLFW_KEY_ENTER) == GLFW_PRESS) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Glowing Something", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create Window" << endl;
		glfwTerminate();
		return -1;
	}glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to start GLAD" << endl;
		return -1;
	}

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER); 
	glShaderSource(vertexShader, 1, &VertexShaderSource, NULL); 
	glCompileShader(vertexShader); 
	int good; char Log[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &good);
	if (!good) {
		glGetShaderInfoLog(vertexShader, 512, NULL, Log);
		cout << "VERTEX SHADER FAILED!\n" << Log << endl;
	}

	unsigned int fragmShader;
	fragmShader = glCreateShader(GL_FRAGMENT_SHADER); 
	glShaderSource(fragmShader, 1, &FragmShaderSource, NULL); 
	glCompileShader(fragmShader); 
	glGetShaderiv(fragmShader, GL_COMPILE_STATUS, &good); 
	if (!good) {
		glGetShaderInfoLog(vertexShader, 512, NULL, Log);
		cout << "FRAGMENT SHADER FAILED!\n" << Log << endl;
	}

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram(); 
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &good); 
	if (!good) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, Log);
		cout << "SHADER LINKING FAILED!\n" << Log << endl;  
	}
	glDeleteShader(vertexShader); 
	glDeleteShader(fragmShader);

	unsigned int VBO, VAO; 
	glGenVertexArrays(1, &VAO); 
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO); 
	glBindBuffer(GL_ARRAY_BUFFER, VBO); 
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0); // �� 0�� ������ VBO���� ����(��ǥ) �ܱ� ( Float 6�������� 0��°���� 3���� ������ )
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1); // �� 1�� ������ VBO���� ����(�÷�) �ܱ� ( Float 6�������� 3��°���� 3���� ������ )

	glViewport(0, 0, 800, 600);
	while (!glfwWindowShouldClose(window)) {
		processEsc(window);
		processFillorNot(window);
		//--------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//--------
		glUseProgram(shaderProgram); // ���̴� ���α׷� ON
		glBindVertexArray(VAO);
		float time = glfwGetTime();
		int uLocation = glGetUniformLocation(shaderProgram, "xoffset"); // ���̴����� xoffset ��ġ �˾Ƴ���
		glUniform1f(uLocation, sin(time)/2.0); // xoffset ��ġ�� Ư���� �Ѱ��� (���̴� ���ο��� �����޵�)
		glDrawArrays(GL_TRIANGLES, 0, 6); 
		//--------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	glfwTerminate();
	return 0;
}