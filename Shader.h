#ifndef __SHADER_H__
#define __SHADER_H__

#include <GL/glew.h>
#include <string>

class Shader{
public:
	Shader(const std::string& fileName);
	void Bind();
	virtual ~Shader();
private:
	GLuint m_program;
	GLuint m_vshader;
	GLuint m_fshader;
};

#endif