#ifndef ATLAS_INCLUDE_ATLAS_GL_TEXTURE_HPP
#define ATLAS_INCLUDE_ATLAS_GL_TEXTURE_HPP

#pragma once

#include "GL.hpp"

#include <memory>

namespace atlas
{
    namespace gl
    {
        class Texture : public Object
        {
        public:
            Texture();
            Texture(GLenum target);
            Texture(Texture const& tex);
            ~Texture();

            void genTexture(GLenum target);

            void bindTexture();
            void unBindTexture();

            void texStorage1D(GLsizei levels, GLenum internalFormat, 
                GLsizei width);
            void texStorage2D(GLsizei levels, GLenum internalFormat,
                GLsizei width, GLsizei height);
            void texStorage3D(GLsizei levels, GLenum internalFormat,
                GLsizei width, GLsizei height, GLsizei depth);

            void texBuffer(GLenum internalFormat, Buffer const& buffer);

            GLuint getHandle() const override;

        private:
            struct TextureImpl;
            std::unique_ptr<TextureImpl> mImpl;
        };
    }
}

#endif