#include "BaseObject.h"

BaseObject::BaseObject(const Tag tag)
	:mPosition(0.0f,0.0f)
	,mScale(1.0f,1.0f)
	,mAngle(0.0f)
	,mTag(tag)
{
}

BaseObject::~BaseObject()
{
}

void BaseObject::Update(float deltaTime)
{
	// �I�u�W�F�N�g�̍X�V����
	UpdateObject(deltaTime);
}

void BaseObject::UpdateObject(float deltaTime)
{
}

void BaseObject::Draw()
{
}
