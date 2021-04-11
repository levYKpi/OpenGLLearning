#include "Shader.h"
#include <fstream>
#include <iostream>

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errMessage);
static std::string LoadShader(const std::string& fileName);
static GLuint CreatShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName){
	m_program = glCreateProgram();
	m_vshader = CreatShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	m_fshader = CreatShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);
	
	glAttachShader(m_program, m_vshader);
	glAttachShader(m_program, m_fshader);
	
	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking");
	
	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program validation");
}

Shader::~Shader(){
	glDetachShader(m_program, m_vshader);
	glDeleteShader(m_vshader);
	glDetachShader(m_program, m_fshader);
	glDeleteShader(m_fshader);
	glDeleteProgram(m_program);
}

void Shader::Bind(){
	glUseProgram(m_program);
}

static GLuint CreatShader(const std::string& text, GLenum shaderType){
	GLuint shader = glCreateShader(shaderType);
	if (shader == 0){
		std::cerr << "Error: Shader creation failed\n";
	}
	
	const GLchar* shaderSouceString[1];
	GLint shaderSouceStringLength[1];
	shaderSouceString[0] = text.c_str();
	shaderSouceStringLength[0] = text.length();
	
	glShaderSource(shader, 1, shaderSouceString, shaderSouceStringLength);
	glCompileShader(shader);
	
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation");
	
	return shader;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errMessage){
	GLint success = 0;
	GLchar err[1024] = {0};
	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);
	
	if (success == GL_FALSE){
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(err), NULL, err);
		else
			glGetShaderInfoLog(shader, sizeof(err), NULL, err);
		
		std::cerr << errMessage << ": " << err << std::endl;
	}
}

static std::string LoadShader(const std::string& fileName){
	std::ifstream file;
	file.open(fileName.c_str());
	std::string output, line;
	if (file.is_open()){
		while(getline(file, line))
			output.append(line + "\n");
	}
	else{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}
	return output;
}

