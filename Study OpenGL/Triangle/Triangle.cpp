
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

float vertices[] = { // ���������� (��ǥ -1~1)
	0.5f, 0.5f, 0.0f, // 0������ 
	0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f // 5������
};

unsigned int indices[] = { // ���������� (���� ��ȣ��� ����)
	0, 1, 2, // 0������
	1, 4, 2  // 1������
};

const char* VertexShaderSource = // �������̴� �ڵ� (GLSL) .vs
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main(){\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n\0";

const char* FragmShaderSource = // �ȼ����̴� �ڵ� (GLSL) .fs
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main(){\n"
"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
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

	GLFWwindow* window = glfwCreateWindow(800, 600, "TRIANGLE + TRIANGLE = RECTANGLE", NULL, NULL);
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
	vertexShader = glCreateShader(GL_VERTEX_SHADER); // ���̴� ���� ����(�������̴�)
	glShaderSource(vertexShader, 1, &VertexShaderSource, NULL); // �������̴� �ҽ� ��������
	glCompileShader(vertexShader); // �ҽ� ��ü ������
	int good; char Log[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &good); // ������ �ߵƴ��� Ȯ��
	if (!good) {
		glGetShaderInfoLog(vertexShader, 512, NULL, Log);
		cout << "VERTEX SHADER FAILED!\n" << Log << endl;  // �����޽��� ���
	}

	unsigned int fragmShader;
	fragmShader = glCreateShader(GL_FRAGMENT_SHADER); // ���̴� ���� ����(�ȼ����̴�)
	glShaderSource(fragmShader, 1, &FragmShaderSource, NULL); // �ȼ����̴� �ҽ� ��������
	glCompileShader(fragmShader); // �ҽ� ��ü ������
	glGetShaderiv(fragmShader, GL_COMPILE_STATUS, &good); // ������ �ߵƴ��� Ȯ��
	if (!good) {
		glGetShaderInfoLog(vertexShader, 512, NULL, Log);
		cout << "FRAGMENT SHADER FAILED!\n" << Log << endl;  // �����޽��� ���
	}

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram(); // ���̴����� ���ļ� ���α׷� ���·� �ϼ��Ұ���
	glAttachShader(shaderProgram, vertexShader); // ���̴��� ���α׷��� �ϳ��� ���̱�
	glAttachShader(shaderProgram, fragmShader);
	glLinkProgram(shaderProgram); // ���� ���̴��� �����ϱ�(����?)
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &good); // ���� �ߵƴ��� Ȯ�� 
	if (!good) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, Log);
		cout << "SHADER LINKING FAILED!\n" << Log << endl;  // �����޽��� ���
	}
	glDeleteShader(vertexShader); // ���α׷� ����� ���� ���̴����� ���
	glDeleteShader(fragmShader);

	unsigned int VBO, VAO, EBO; // VBO�� �����������, VAO�� ��������迭, EBO�� �����������
	glGenVertexArrays(1, &VAO); // ���Ҽ���
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO); // VAO ���ε�(�Լ��� ����)
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // VBO ����(GAB)�� ����
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // EBO ����(GEAB)�� ����
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// VAO�� 0�� �����Ͱ� VBO���� ���� �о���� ( Float 3���� ��� 0��°���� 3���� ������ )
	glEnableVertexAttribArray(0); // 0�� ������ Ȱ��ȭ (���̴����� ����)

	glViewport(0, 0, 800, 600);
	while (!glfwWindowShouldClose(window)) {
		processEsc(window);
		processFillorNot(window);
		//--------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//--------
		glUseProgram(shaderProgram); // ���̴� ���α׷� ��� (ù��)
		glBindVertexArray(VAO); // VAO ���ε�
		//glDrawArrays(GL_TRIANGLES, 0, 6); // VBO�� 0��°���� 6���� ������ ���� �ﰢ�� �׸��� or
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); // EBO�� ,, �ε����� ���� �ﰢ�� �׸���
		//--------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
