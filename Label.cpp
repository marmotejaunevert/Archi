#include "Label.h"

UI::Label::Label(const TextData& _data, const AligmentText& _aligement)	: TextWidget(_data)
{
	textObject = new TextObject(_data);
}


void UI::Label::Render(RenderWindow& _window)
{
	if (visibility == Hidden) return;
	_window.draw(*textObject->GetDrawable());
}