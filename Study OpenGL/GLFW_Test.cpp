
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

void processEsc(GLFWwindow *wndw) { // �Է� ó���Լ�
	if (glfwGetKey(wndw, GLFW_KEY_ESCAPE) == GLFW_PRESS) // wndw���� Esc�� �����ٸ�
		glfwSetWindowShouldClose(wndw, true); // ������� ��� ����
}

int main() {
	glfwInit(); // GLFW �ʱ�ȭ
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // GLFW�� ��������(��Ʈ) �ʱ⼳��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL); // ���â ����
	if (window == NULL) { // ���â�� �� ����������� Ȯ��
		cout << "Failed to create Window" << endl;
		glfwTerminate(); // GLFW ��������
		return -1;
	}glfwMakeContextCurrent(window); // ������ 'window'�� ������ �����̶�� �˷���

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { // GLAD�� OpenGL �Լ������� �ҷ�����
		cout << "Failed to start GLAD" << endl;
		return -1;
	}

	glViewport(0, 0, 800, 600); // ī�޶��� �þ� ����(���簢��) 
	while (!glfwWindowShouldClose(window)) {  // ������� ����� ������ ������ �ݺ�
		processEsc(window); // Esc �Է�üũ

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT); // â �ܻ����� �����(������ �� ����)		

		glfwSwapBuffers(window); // ������� â �̹��� ���
		glfwPollEvents(); // ���۰���
	}

	glfwTerminate(); // GLFW ����
	return 0;
}