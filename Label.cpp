#include "Label.h"

Label::Label(const TextData& _data, const WidgetType& _type) : TextWidget(_data, _type)
{
	alignement = AT_CENTER;
}

void Label::Render(RenderWindow& _window)
{
	_window.draw(*textObject->GetDrawable());
}
