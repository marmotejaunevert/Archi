#include "TextObject.h"
#include "FontManager.h"

TextObject::TextObject(const string& _text, const string& _path, const FontExtensionType& _fontType)
{
	text = new Text(font, _text);
	M_FONT.Load(this, _path, _fontType);
}

TextObject::TextObject(const TextData& _data)
{
	text = new Text(font, _data._text);
	M_FONT.Load(this, _data._path, _data._fontType);
}

TextObject::~TextObject()
{
	delete text;
}