#include "BaseObject.h"

BaseObject::BaseObject()
	:mPosition(0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mAngle(0.0f)
{
}

BaseObject::~BaseObject()
{
}

void BaseObject::Update(float deltaTime)
{
	// オブジェクトの更新処理
	UpdateObject(deltaTime);
}

void BaseObject::UpdateObject(float deltaTime)
{
}
