
#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLFW/Shader.h>
#include <GLFW/stb_image.h> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using namespace glm;

float vertices[] = { // ������Ʈ(Cube)�� Vertex ������
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Vertex(XYZ), TexCoord(ST)
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

float texCoords[] = { // 1x1 �ؽ��� �̹������� �󸶳� �߶� ����� ������
	0.0, 0.0, // 1����(S,T)
	1.0, 0.0,
	0.5, 1.0
};

vec3 cubePos[] = { // ������Ʈ �������� ������ ��ġ - ������ Model Matrix����
	vec3(0.0f,  0.0f,  0.0f),
	vec3(2.0f,  5.0f, -15.0f),
	vec3(-1.5f, -2.2f, -2.5f),
	vec3(-3.8f, -2.0f, -12.3f),
	vec3(2.4f, -0.4f, -3.5f),
	vec3(-1.7f,  3.0f, -7.5f),
	vec3(1.3f, -2.0f, -2.5f),
	vec3(1.5f,  2.0f, -2.5f),
	vec3(1.5f,  0.2f, -1.5f),
	vec3(-1.3f,  1.0f, -1.5f)
};

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

	float winWidth = 800, winHeight = 600;
	GLFWwindow* window = glfwCreateWindow(winWidth, winHeight, "Kane Nose", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create Window" << endl;
		glfwTerminate();
		return -1;
	}glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to start GLAD" << endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST); // ���α׷��� �ڵ����� "����"(=z)���۸� ����ϵ��� ���
	Shader ourShader("Shader/vertexShader.vs", "Shader/fragmShader.fs");

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height, RGB;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load("Tex/NEWw.JPG", &width, &height, &RGB, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else cout << "Failed to load texture" << endl;
	stbi_image_free(data);

	ourShader.use();
	ourShader.setInt("Tex1", 0);

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glViewport(0, 0, 800, 600);
	mat4 modelMat, viewMat, projMat; // ������Ʈ ���� ��ǥ�踦 ���� �ܰ迡 ���� ��ȯ(=����� ��)�� ����
	unsigned int modelLoc, viewLoc, projLoc;
	while (!glfwWindowShouldClose(window)) {
		processEsc(window);
		processFillorNot(window);
		//----------
		glClearColor(0.2, 0.3, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // �÷��� �Բ� ���� ���۵� �Ź� û������
		//----------
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		//----------
		ourShader.use();
		viewMat = projMat = mat4(1.0); // �׻� �ʱ�ȭ�� ������ ��
		viewMat = translate(viewMat, vec3(0.0, 0.0, -3.0)); // ���� ��ǥ�踦 ī�޶��� ��� ��ǥ��� ��ȯ
		projMat = perspective(radians(45.0f), winWidth / winHeight, 0.1f, 100.0f); // ���ٹ� ���� (�Ÿ��� ���� �����ϸ�)
		modelLoc = glGetUniformLocation(ourShader.Program, "modelMat"); // ���̴��� ������� �� �Ѱ��ֱ�
		viewLoc = glGetUniformLocation(ourShader.Program, "viewMat");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &viewMat[0][0]);
		projLoc = glGetUniformLocation(ourShader.Program, "projMat");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, &projMat[0][0]);
		glBindVertexArray(VAO);
		for (int i = 0; i < 10; i++) { // ���� - ť�� 10�� �׸���
			modelMat = mat4(1.0); // ������Ʈ(vertices)�� ���� ��ǥ�迡 ���ϴ� ��ġ&�������� ��ġ
			modelMat = rotate(modelMat, (float)glfwGetTime()*radians(i*20.0f), vec3(1.0, 0.3, 0.5)); // ����(ȸ��)
			modelMat = translate(modelMat, cubePos[i]); // ��ġ(�����̵�)
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &modelMat[0][0]);
			glDrawArrays(GL_TRIANGLES, 0, 36); // ť�����
		}
		//--------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}
