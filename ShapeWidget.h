#pragma once
#include "Widget.h"
#include "ShapeObject.h"

using namespace UI;

class ShapeWidget : public Widget
{
protected:
	ShapeObject* shapeObject;

public:
	virtual void SetShapePosition(const Vector2f& _position)
	{
		GetDrawable()->setPosition(_position);
	}
	ShapeObject* GetObject() const
	{
		return shapeObject;
	}
	Shape* GetDrawable() const
	{
		return shapeObject->GetDrawable();
	}
	virtual Vector2f GetShapePosition()
	{
		return GetDrawable()->getPosition();
	}

public:
	ShapeWidget(const RectangleShapeData& _data, const WidgetType& _type = WT_UI);
	~ShapeWidget();
};