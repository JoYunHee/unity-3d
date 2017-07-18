#pragma once

struct S_ObjectBullet
{
	irr::core::vector2df m_vPosition;
	irr::core::vector2df m_vDirection;
	irr::f64 m_fVelocity;
	irr::f64 m_fSize;
	int m_nFSM;
	double m_flifeTime;
};

extern void ObjectBullet_Setup(S_ObjectBullet *pThis, irr::core::vector2df &vStartPos,
	irr::core::vector2df &vTaegetPos,
	irr::f64 fVolumeSize,
	irr::f64 fVelocity
);
extern void ObjectBullet_OnRender(S_ObjectBullet *pThis, Graphics *pGrp);
extern void ObjectBullet_OnApply(S_ObjectBullet *pThis, double fDelta);