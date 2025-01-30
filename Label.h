#pragma once
#include "TextWidget.h"
#include "Actor.h"

namespace UI
{
	enum AligmentText
	{
		AT_LEFT,
		AT_CENTER,
		AT_RIGHT,
	};

	class Label : public TextWidget
	{
		AligmentText alignement;

	public:
		FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
		{
			Super::SetPosition(_position);
			textObject->SetPosition(_position);
		}
		FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
		{
			Super::SetRotation(_rotation);
			textObject->SetRotation(_rotation);
		}
		FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
		{
			Super::SetScale(_scale);
			textObject->SetScale(_scale);
		}
		FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
		{
			Super::SetOrigin(_origin);
			textObject->SetOrigin(_origin);
		}
		FORCEINLINE virtual void Move(const Vector2f& _offset) override
		{
			Super::Move(_offset);
			textObject->Move(_offset);
		}
		FORCEINLINE virtual void Rotate(const Angle& _angle) override
		{
			Super::Rotate(_angle);
			textObject->Rotate(_angle);
		}
		FORCEINLINE virtual void Scale(const Vector2f& _factor) override
		{
			Super::Scale(_factor);
			textObject->Scale(_factor);
		}

		virtual void SetString(const string& _text)
		{
			textObject->GetDrawable()->setString(_text);
			SetAlignement(alignement);
		}
		void SetAlignement(const AligmentText& _aligement)
		{
			alignement = _aligement;
			const FloatRect& _bounds = textObject->GetDrawable()->getLocalBounds();
			const float _originX = _aligement == AT_LEFT ? 0.0f
				: _aligement == AT_CENTER ? _bounds.size.x / 2.0f
				: _bounds.size.x;
			textObject->GetDrawable()->setOrigin(Vector2f(_originX, _bounds.size.y / 2.0f)); // alignement Y
		}

	public:
		Label(const TextData& _data, const AligmentText& _aligement = AT_CENTER);

	public:
		virtual void Render(RenderWindow& _window) override;
	};
}