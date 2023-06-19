#include <iostream>
#include <SDL.h>

int main(int argc, char *argv[]){
	
	int width(1600);
	int height(900);

	SDL_GLContext m_glContext;
	SDL_Window * m_window;
	
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	m_window = SDL_CreateWindow(  "Minha Janela",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								width,
								height,
								SDL_WINDOW_OPENGL );
	
    if (m_window == NULL) {
		std::cerr << "Could not create window: " << SDL_GetError();
        return 1;
    }
	
	m_glContext = SDL_GL_CreateContext(m_window);
	
	
	// EXIT STUFF
	SDL_Delay(4000);
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	
	return 0;
}
