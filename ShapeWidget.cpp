#include "ShapeWidget.h"
#include "Macro.h"

ShapeWidget::ShapeWidget(const RectangleShapeData& _data, const WidgetType& _type) : Widget(_type)
{
	shapeObject = new ShapeObject(_data);
	SetOrigin(shapeObject->GetDrawable()->getGeometricCenter());
}

ShapeWidget::~ShapeWidget()
{
	delete shapeObject;
}