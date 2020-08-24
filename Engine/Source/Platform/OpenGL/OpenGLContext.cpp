#include "mepch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace MreshEngine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ME_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		ME_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ME_CORE_ASSERT(status, "Failed to initialize Glad!");

		ME_CORE_INFO("OpenGL Info:");
		ME_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ME_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ME_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	#ifdef ME_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		ME_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "MreshEngine requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		ME_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}