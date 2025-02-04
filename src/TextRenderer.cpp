#include <TextRenderer.hpp>


TextRenderer::TextRenderer ()
{

}


TextRenderer::~TextRenderer ()
{

}


void TextRenderer::SetFontsPath (const char* path)
{
    this->fonts = (char*)path;
}
