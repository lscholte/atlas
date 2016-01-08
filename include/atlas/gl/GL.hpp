/**
 * \file GL.hpp
 * \brief Includes all of the necessary headers for OpenGL.
 * 
 * This header essentially encapsulates the inclusion of the headers
 * for OpenGL depending on the platform. All the user has to do is add the
 * following line:
 * \code
 * #include <atlas/gl/GL.hpp>
 * \endcode
 * and all OpenGL functionality will be available.
 * 
 * \note
 * Atlas uses GLEW to handle all of the extensions for OpenGL in Linux
 * and Windows. Please ensure that this is installed before attempting to
 * compile Atlas.
 * 
 * \warning
 * Atlas does <b> not </b> support OpenGL 2. While this may not be such a
 * hard rule on Windows and Linux, this header includes only the OpenGL 3
 * headers for OSX. Any attempt to use OpenGL 2 functions will result in
 * errors at compile time.
 */
#ifndef ATLAS_INCLUDE_ATLAS_GL_GL_HPP
#define ATLAS_INCLUDE_ATLAS_GL_GL_HPP

#pragma once

#include "atlas/Atlas.hpp"
#include "atlas/core/Platform.hpp"

#if !defined(ATLAS_PLATFORM_APPLE)
#include <GL/glew.h>
#else
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#endif

#ifdef USING_ATLAS_GL_NS
#undef USING_ATLAS_GL_NS
#endif

/**
 * \def USING_ATLAS_GL_NS
 * Shortened version for using the atlas::gl namespace.
 */
#define USING_ATLAS_GL_NS using namespace atlas::gl

namespace atlas
{
    namespace gl
    {
        class Shader;
        class Texture;
    }
}

#endif
