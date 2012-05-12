// .OBJ loader.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <glfw.h>

static unsigned int Width = 800;
static unsigned int Height = 600;


int main()
{
		if (!glfwInit())
   {
      std::cout << "GLFW failed to initialize!\n";
      return 1;
   }
   glfwOpenWindow(Width,Height,0,0,0,0,0,0,GLFW_WINDOW);
   glfwSetWindowTitle(".OBJ Loader");
   glViewport(0,0,Width, Height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0,Width,0,Height,0,1);
   glMatrixMode(GL_MODELVIEW);
   glClearColor(0,0,0,1);

   while (true)
   {



		// Updates above clear.
		glClear(GL_COLOR_BUFFER_BIT);
		// Draws under clear.



		glfwSwapBuffers();

   }
	return 0;
}

