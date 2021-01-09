
#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Shader { // �ܺ� ���Ͽ��� ���̴� �ܰ� ó���ϴ� Class ���� - ����ε� ���� ������ ����, main �ܼ�ȭ
public:
	unsigned int Program;
	Shader(const char* vertexPath, const char* fragmPath) { // ������, ������� ���̴� �ڵ� ����
		string vertexCode, fragmCode;
		ifstream vShaderFile, fShaderFile;
		vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
		vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
		try {
			vShaderFile.open(vertexPath); // ����
			fShaderFile.open(fragmPath);
			stringstream vShaderStream, fShaderStream;
			vShaderStream << vShaderFile.rdbuf(); // �б�
			fShaderStream << fShaderFile.rdbuf();
			vShaderFile.close(); // �ݱ�
			fShaderFile.close();
			vertexCode = vShaderStream.str(); // ���ڿ��� ��ȯ
			fragmCode = fShaderStream.str();
		}
		catch (ifstream::failure e) { cout << "SHADER FILE READING FAILED!" << endl; }
		const char* vShaderCode = vertexCode.c_str(); // ���� �ڵ�
		const char* fShaderCode = fragmCode.c_str();

		unsigned int vShader;
		vShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vShader, 1, &vShaderCode, NULL);
		glCompileShader(vShader);
		checkError(vShader, "VERTEX");

		unsigned int fShader;
		fShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fShader, 1, &fShaderCode, NULL);
		glCompileShader(fShader);
		checkError(fShader, "PIXEL");

		Program = glCreateProgram();
		glAttachShader(Program, vShader);
		glAttachShader(Program, fShader);
		glLinkProgram(Program);
		checkError(Program, "PROGRAM");

		glDeleteShader(vShader);
		glDeleteShader(fShader);
	}
	void use() { glUseProgram(Program); } // ���α׷� ���, Uniform ����� ���� ���� �Լ��� ������
	void setBool(const string &name, bool Val) { glUniform1i(glGetUniformLocation(Program, name.c_str()), (int)Val); }
	void setInt(const string &name, int Val) { glUniform1i(glGetUniformLocation(Program, name.c_str()), Val); }
	void setFloat(const string &name, float Val) { glUniform1f(glGetUniformLocation(Program, name.c_str()), Val); }

private:
	void checkError(GLuint object, string type) {
		GLint good; GLchar Log[512];
		if (type == "PROGRAM") {
			glGetProgramiv(object, GL_LINK_STATUS, &good);
			if (!good) {
				glGetProgramInfoLog(object, 512, NULL, Log);
				cout << "SHADER LINKING FAILED!\n" << Log << endl;
			}
		}else {
			glGetShaderiv(object, GL_COMPILE_STATUS, &good);
			if (!good) {
				glGetShaderInfoLog(object, 512, NULL, Log);
				cout << type << " SHADER FAILED!\n" << Log << endl;
			}
		}
	}
};

#endif