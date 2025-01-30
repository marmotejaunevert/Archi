#pragma once
#include "Widget.h"
#include "TextObject.h"

using namespace UI;




class TextWidget : public Widget
{
protected:
	TextObject* textObject;

public:
	TextObject* GetObject() const
	{
		return textObject;
	}
	Text* GetDrawable() const
	{
		return textObject->GetDrawable();
	}

public:
	TextWidget(const TextData& _data, const WidgetType& _type = WT_UI);
};