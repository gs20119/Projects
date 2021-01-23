
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
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, // Pos(XYZ), Normal(XYZ)
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, // 6���� ���� �� ���� ���

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
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

float Time() { return glfwGetTime(); } 
float Rad(float deg) { return radians(deg); }

// ī�޶� �����۾� ������ processMove, processMouse, processScroll
float DelTime = 0.0, LastFrame = 0.0, CurFrame = 0.0;
vec3 camPos = vec3(-8.0, -2.0, 3.0), camTarg = normalize(vec3(8.9, 2.9, -3.5)), camUp = vec3(0.0, 1.0, 0.0); 
void processMove(GLFWwindow *wndw) {
	float camSpeed = 3 * DelTime; 
	if (glfwGetKey(wndw, GLFW_KEY_W) == GLFW_PRESS) camPos += camSpeed * camTarg; 
	if (glfwGetKey(wndw, GLFW_KEY_A) == GLFW_PRESS) camPos -= camSpeed * normalize(cross(camTarg, camUp)); 
	if (glfwGetKey(wndw, GLFW_KEY_S) == GLFW_PRESS) camPos -= camSpeed * camTarg; 
	if (glfwGetKey(wndw, GLFW_KEY_D) == GLFW_PRESS) camPos += camSpeed * normalize(cross(camTarg, camUp)); 
}

float lastX = 400, lastY = 300, sensitivity = 0.05, Yaw, Pitch, YawRad, PitchRad;
bool firstMouse = true;
void processMouse(GLFWwindow *wndw, double curX, double curY) {
	if (firstMouse) {
		curX = lastX; curY = lastY; 
		firstMouse = false;
	}
	float xoffset = (curX - lastX) * sensitivity; 
	float yoffset = (curY - lastY) * sensitivity;
	lastX = curX; lastY = curY;

	Yaw += xoffset;
	Pitch = min(89.0f, Pitch - yoffset);
	Pitch = max(-89.0f, Pitch - yoffset);
	YawRad = Rad(Yaw); PitchRad = Rad(Pitch); 
	camTarg = normalize(vec3(cos(YawRad)*cos(PitchRad), sin(PitchRad), sin(YawRad)*cos(PitchRad))); 
}

float fov = 45.0f; 
void processScroll(GLFWwindow *wndw, double xoffset, double yoffset) {
	fov = max(min(45.0,fov-yoffset), 1.0); 
}

void processEsc(GLFWwindow *wndw) {
	if (glfwGetKey(wndw, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(wndw, true);
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	float winWidth = 800, winHeight = 600;
	GLFWwindow* window = glfwCreateWindow(winWidth, winHeight, "Kane Sorry", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to create Window" << endl;
		glfwTerminate();
		return -1;
	}glfwMakeContextCurrent(window);
	glfwSetCursorPosCallback(window, processMouse); // ���콺 ���� �Է�(�̵�+��ũ��)�� �Լ��� �����ϵ��� ����
	glfwSetScrollCallback(window, processScroll);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to start GLAD" << endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);
	Shader lightShader("Shader/vertexShader.vs", "Shader/fragmShader.fs");
	Shader CubeShader("Shader/vertexPhong.vs", "Shader/fragmPhong.fs");

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int cubeVAO; // �ٸ� ���� ������ ������Ʈ�� ���� �� VAO�� ����
	glGenVertexArrays(1, &cubeVAO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0); // 0�� �����Ϳ��� ������ ��ǥ �ܰ� ���̴��� ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1); // 1�� �����Ϳ��� ������ �������� �ܰ� ���̴��� ����

	glViewport(0, 0, 800, 600);
	mat4 modelMat, viewMat, projMat;
	vec3 LightPos = vec3(1.2, 1.0, 2.0), LightColor;
	while (!glfwWindowShouldClose(window)) {
		CurFrame = Time(); // �ݺ��� ������ �ð� ���, ������ �������� ������ ����
		DelTime = CurFrame - LastFrame; LastFrame = CurFrame;
		processEsc(window);
		processMove(window);
		//----------
		glClearColor(0.1, 0.1, 0.1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		//----------
		viewMat = projMat = mat4(1.0); // ī�޶�� ���� ���� (�ڵ�� �״��)
		viewMat = lookAt(camPos, camTarg + camPos, camUp);
		projMat = perspective(radians(fov), winWidth / winHeight, 0.1f, 100.0f);

		lightShader.use(); // 1����ü - ��
		lightShader.setMat4("viewMat", viewMat);
		lightShader.setMat4("projMat", projMat);
		modelMat = mat4(1.0);
		modelMat = translate(modelMat, LightPos);
		modelMat = scale(modelMat, vec3(0.2));
		lightShader.setMat4("modelMat", modelMat);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		CubeShader.use(); // 2����ü - �繰
		CubeShader.setVec3("light.pos", LightPos); // ���� ��ġ
		CubeShader.setVec3("camPos", camPos); // ī�޶� ��ġ

		LightColor = vec3(sin(Time()*2.0), sin(Time()*0.7), sin(Time()*1.3));
		CubeShader.setVec3("light.ambCof", vec3(0.1)*LightColor); // �ݻ� �����
		CubeShader.setVec3("light.diffCof", vec3(0.5)*LightColor);
		CubeShader.setVec3("light.specCof", vec3(1.0));
		CubeShader.setVec3("material.ambCof", vec3(1.0, 0.5, 0.3));
		CubeShader.setVec3("material.diffCof", vec3(1.0, 0.5, 0.3));
		CubeShader.setVec3("material.specCof", vec3(0.5, 0.5, 0.5));
		CubeShader.setFloat("material.alpha", 32.0);

		CubeShader.setMat4("viewMat", viewMat);
		CubeShader.setMat4("projMat", projMat);
		modelMat = mat4(1.0);
		CubeShader.setMat4("modelMat", modelMat);
		glBindVertexArray(cubeVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//--------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glfwTerminate();
	return 0;
}
