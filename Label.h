#pragma once
#include "TextWidget.h"
#include "CameraActor.h"

enum AligmentText
{
	AT_TOP_LEFT,
	AT_TOP_CENTER,
	AT_TOP_RIGHT,
	AT_LEFT,
	AT_CENTER,
	AT_RIGHT,
	AT_BOTTOM_LEFT,
	AT_BOTTOM_CENTER,
	AT_BOTTOM_RIGHT,
};

class Label : public TextWidget
{
	AligmentText alignement;

public:
	virtual void SetString(const string& _text)
	{
		textObject->GetDrawable()->setString(_text);
		//SetAlignement(alignement);
	}
	void SetAlignement(const AligmentText& _alignement, const CameraActor& _camera)
	{
		alignement = _alignement;
		View* _view = _camera.GetView();
		const FloatRect& _textRect = textObject->GetDrawable()->getGlobalBounds();

		Vector2f _value[] = {

			Vector2f(0.0f,0.0f),
			Vector2f(_view->getCenter().x - _textRect.size.x / 2.0f, 0.0f),
			Vector2f(_view->getSize().x - _textRect.size.x, 0.0f),

			Vector2f(0.0f, _view->getCenter().y - _textRect.size.y / 2.0f),
			Vector2f(_view->getCenter().x - _textRect.size.x / 2, _view->getCenter().y - _textRect.size.y / 2.0f),
			Vector2f(_view->getSize().x - _textRect.size.x, _view->getCenter().y - _textRect.size.y / 2.0f),

			Vector2f(0.0f, _view->getSize().y - _textRect.size.y),
			Vector2f(_view->getCenter().x - _textRect.size.x / 2, _view->getSize().y - _textRect.size.y),
			Vector2f(_view->getSize().x - _textRect.size.x, _view->getSize().y - _textRect.size.y),
		};

		textObject->SetOrigin(_value[_alignement]);
		textObject->SetPosition(_value[_alignement]);
	}

public:
	Label(const TextData& _data, const WidgetType& _type = WT_UI);

	virtual void Render(RenderWindow& _window) override;

};