#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <string>
#include <SDL2/SDL.h>

class Display{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();
	void Update();
	bool IsClosed();
	void Clear();
private:
	SDL_Window* m_window; 
	SDL_GLContext m_glContext;
	bool m_isClosed;
protected:
};

#endif