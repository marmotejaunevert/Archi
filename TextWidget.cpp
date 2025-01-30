#include "TextWidget.h"
#include "FontManager.h"

TextWidget::TextWidget(const TextData& _data, const WidgetType& _type) : Widget("test")
{
	textObject = new TextObject(_data);
}