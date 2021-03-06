
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

float vertices[] = { // 오브젝트(Cube)의 Vertex 정보들
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

float texCoords[] = { // 1x1 텍스쳐 이미지에서 얼마나 잘라 사용할 것인지
	0.0, 0.0, // 1번점(S,T)
	1.0, 0.0,
	0.5, 1.0
};

vec3 cubePos[] = { // 오브젝트 여러개를 생성할 위치 - 적용은 Model Matrix에서
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

float Time() { return glfwGetTime(); } // 이름 길어서 이렇게 쓸 예정
float Rad(float deg) { return radians(deg); }

float DelTime = 0.0, LastFrame = 0.0, CurFrame = 0.0; // 키보드를 누르면 움직이는 시스템을 만들 것임
vec3 camPos = vec3(-8.0, -2.0, 3.0), camTarg = normalize(vec3(8.9, 2.9, -3.5)), camUp = vec3(0.0, 1.0, 0.0); // viewMat 참고
void processMove(GLFWwindow *wndw) {
	float camSpeed = 3 * DelTime; // 카메라가 이동할 속도
	if (glfwGetKey(wndw, GLFW_KEY_W) == GLFW_PRESS) camPos += camSpeed * camTarg; // -Z방향 이동
	if (glfwGetKey(wndw, GLFW_KEY_A) == GLFW_PRESS) camPos -= camSpeed * normalize(cross(camTarg, camUp)); // -X방향 이동
	if (glfwGetKey(wndw, GLFW_KEY_S) == GLFW_PRESS) camPos -= camSpeed * camTarg; // +Z방향 이동
	if (glfwGetKey(wndw, GLFW_KEY_D) == GLFW_PRESS) camPos += camSpeed * normalize(cross(camTarg, camUp)); // +X방향 이동
	//cout << camPos.x << " " << camPos.y << " " << camPos.z << endl;
	//cout << camTarg.x << " " << camTarg.y << " " << camTarg.z << endl;
}

float lastX = 400, lastY = 300, sensitivity = 0.05, Yaw, Pitch, YawRad, PitchRad;
bool firstMouse = true; // 마우스를 움직이면 화면이 돌아가는 시스템을 만들 것임
void processMouse(GLFWwindow *wndw, double curX, double curY) {
	if (firstMouse) {
		curX = lastX; curY = lastY; // 처음 사용한 것이라면 갱신만 해줌
		firstMouse = false;
	}
	float xoffset = (curX - lastX) * sensitivity; // 마우스 좌표 변화에 감도를 곱해줌
	float yoffset = (curY - lastY) * sensitivity;
	lastX = curX; lastY = curY;

	Yaw += xoffset;
	Pitch = min(89.0f, Pitch - yoffset);
	Pitch = max(-89.0f, Pitch - yoffset);
	YawRad = Rad(Yaw); PitchRad = Rad(Pitch); // Yaw=경도, Pitch=위도
	camTarg = normalize(vec3(cos(YawRad)*cos(PitchRad), sin(PitchRad), sin(YawRad)*cos(PitchRad))); // 시선방향 설정(Z)
}

float fov = 45.0f; // 스크롤을 움직이면 확대/축소시켜주는 기능
void processScroll(GLFWwindow *wndw, double xoffset, double yoffset) {
	fov = max(min(45.0,fov-yoffset), 1.0); // fov = Field of View
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
	glfwSetCursorPosCallback(window, processMouse); // 마우스 관련 입력(이동+스크롤)을 함수로 송출하도록 설정
	glfwSetScrollCallback(window, processScroll);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to start GLAD" << endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);
	Shader lightShader("Shader/vertexShader.vs", "Shader/fragmShader.fs");
	Shader CubeShader("Shader/vertexShader_c.vs", "Shader/fragmShader_c.fs");

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int cubeVAO; // 다른 색을 가지는 오브젝트를 위해 새 VAO를 만듬
	glGenVertexArrays(1, &cubeVAO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0); // 포인터는 똑같이 써도 상관없음

	glViewport(0, 0, 800, 600);
	mat4 modelMat, viewMat, projMat;
	vec3 ObjColor = vec3(1.0, 0.5, 0.31), LightColor = vec3(1.0, 1.0, 1.0);
	while (!glfwWindowShouldClose(window)) {
		CurFrame = Time(); // 반복할 때마다 시간 기록, 프레임 측정으로 움직임 결정
		DelTime = CurFrame - LastFrame; LastFrame = CurFrame;
		processEsc(window);
		processMove(window);
		//----------
		glClearColor(0.2, 0.3, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		//----------
		viewMat = projMat = mat4(1.0); // 카메라와 투영 설정 (코드는 그대로)
		viewMat = lookAt(camPos, camTarg + camPos, camUp);
		projMat = perspective(radians(fov), winWidth / winHeight, 0.1f, 100.0f);

		lightShader.use(); // 1번객체
		lightShader.setVec3("objectColor", ObjColor);
		lightShader.setVec3("lightColor", LightColor);
		lightShader.setMat4("viewMat", viewMat);
		lightShader.setMat4("projMat", projMat);
		modelMat = mat4(1.0);
		lightShader.setMat4("modelMat", modelMat);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		CubeShader.use(); // 2번객체
		CubeShader.setMat4("viewMat", viewMat);
		CubeShader.setMat4("projMat", projMat);
		modelMat = mat4(1.0);
		modelMat = translate(modelMat, vec3(1.2, 1.0, 2.0));
		modelMat = scale(modelMat, vec3(0.2));
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
