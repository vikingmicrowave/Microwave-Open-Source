#include "main.hpp"

bool bOnce = false; /*https://www.unknowncheats.me/forum/1190911-post11.html */
void hkFrameStage(void* thisptr, ClientFrameStage_t curStage) {
    C_BaseEntity* pLocal = (C_BaseEntity*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    
    Vector* pPunchAngle = nullptr;
    Vector* pViewAngle = nullptr;
    
    Vector vPunchAngle;
    Vector vViewAngle;
    
    if (curStage == FRAME_RENDER_START)
    {
        
        if (pLocal)
        {
            pPunchAngle = (Vector*)((uintptr_t)pLocal + offsets.DT_BasePlayer.m_aimPunchAngle);
            pViewAngle = (Vector*)((uintptr_t)pLocal + offsets.DT_BasePlayer.m_viewPunchAngle);
            
            if (pPunchAngle && pViewAngle)
            {
                vPunchAngle = *pPunchAngle;
                vViewAngle = *pViewAngle;
                
                pPunchAngle->Init();
                pViewAngle->Init();
            }
        }
    }
    
    client_vmt->GetOriginalMethod<tFrameStage>(36)(thisptr, curStage);
    
    if (pPunchAngle && pViewAngle) {
        *pPunchAngle = vPunchAngle;
        *pViewAngle = vViewAngle;
    }
}
