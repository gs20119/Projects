
#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLFW/Shader.h>
#include <GLFW/stb_image.h> 

#include <glm/glm.hpp> // GLM ���� ���̺귯�� ���
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using namespace glm;

float vertices[] = {
	0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f, // xyz(��ǥ), rgb(��), st(�ؽ�����ǥ)
	0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
	-0.5f, 0.5f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f
};

float texCoords[] = { // 1x1 �ؽ��� �̹������� �󸶳� �߶� ����� ������
	0.0f, 0.0f, // 1����(S,T)
	1.0f, 0.0f,
	0.5f, 1.0f
};

int indices[]{
	0, 1, 3,
	1, 2, 3
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

	GLFWwindow* window = glfwCreateWindow(800, 600, "Kane Nose", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create Window" << endl;
		glfwTerminate();
		return -1;
	}glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to start GLAD" << endl;
		return -1;
	}

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
	unsigned char *data = stbi_load("Tex/New.JPG", &width, &height, &RGB, 0); 
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
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0); 
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	vec4 vec(1.0, 1.0, 1.0, 1.0); // GLM�� ��ȯ��� �����ϱ�
	mat4 trans = mat4(1.0); // ��ȯ����� ���͸� ��� ��ȯ������ ����� ���·� ����
	trans = translate(trans, vec3(1.0, 1.0, 0.0)); // (1,1,0) �����̵� ��ȯ
	trans = mat4(1.0); // trans 4x4 ������ķ� �ʱ�ȭ
	trans = rotate(trans, radians(90.0f), vec3(0.0, 0.0, 1.0)); // ��(0,0,1) 90' ȸ����ȯ
	trans = scale(trans, vec3(0.5, 0.5, 0.5)); // (0.5,0.5,0.5) Ȯ��/��Һ�ȯ
	vec = trans * vec; // ���� ���ϸ� vec�� trans�� ����� ��� ��ȯ�� 
	cout << vec.x << " " << vec.y << " " << vec.z << endl;

	glViewport(0, 0, 800, 600);
	while (!glfwWindowShouldClose(window)) {
		processEsc(window);
		processFillorNot(window);
		//----------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//----------
		glActiveTexture(GL_TEXTURE0); 
		glBindTexture(GL_TEXTURE_2D, texture); 
		//----------
		ourShader.use();
		trans = mat4(1.0);
		trans = translate(trans, vec3(0.5, -0.5, 0.0));
		trans = rotate(trans, (float)glfwGetTime(), vec3(0.0, 0.0, 1.0)); // �ð��� ���� ���ư�
		unsigned int tfLoc = glGetUniformLocation(ourShader.Program, "transform");
		glUniformMatrix4fv(tfLoc, 1, GL_FALSE, value_ptr(trans)); // ���̴� ������ ���� trans(��ȯ���) ����
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//--------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}
