#include "stdafx.h"

void ObjectBullet_OnApply(S_ObjectBullet *pThis, double fDelta)
{
	pThis->m_flifeTime += fDelta;

	switch (pThis->m_nFSM)
	{
	case 0: // ready
		pThis->m_nFSM = 10;
		break;
	case 10: //go
	{
		pThis->m_vPosition += pThis->m_vDirection*pThis->m_fVelocity*fDelta;

		irr::f64 fDist = (pThis->m_vPosition - g_objPlayer.m_vPosition).getLength();

		//총알크기 + 비행기 크기
		if (fDist < (pThis->m_fSize + 12)) {
			AddEffectBulletDie(pThis->m_vPosition);
			pThis->m_nFSM = 999;
		}
		//라이프타임 검사 
		if (pThis->m_flifeTime > 3) {	// 총알 죽이기

			pThis->m_nFSM = 999;
		}
	}
	break;
	default:
		break;
	}



}
void ObjectBullet_OnRender(S_ObjectBullet *pThis, Graphics *pGrp)
{
	Pen pen(Color(255, 255, 255));
	pGrp->DrawEllipse(&pen,
		(int)(pThis->m_vPosition.X - pThis->m_fSize / 2.0),
		(int)(pThis->m_vPosition.Y - pThis->m_fSize / 2.0),
		pThis->m_fSize, pThis->m_fSize
	);

}
void ObjectBullet_Setup(S_ObjectBullet *pThis, irr::core::vector2df &vStartPos,
	irr::core::vector2df &vTaegetPos,
	irr::f64 fVolumeSize,
	irr::f64 fVelocity
)
{
	pThis->m_fSize = fVolumeSize;
	pThis->m_fVelocity = fVelocity;
	pThis->m_nFSM = 0; //ready
	pThis->m_vPosition = vStartPos;
	pThis->m_vDirection = vTaegetPos - vStartPos;
	pThis->m_vDirection.normalize();
	pThis->m_flifeTime = 0;
}