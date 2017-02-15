#include "main.hpp"

/* 
 
 To mention, since we don't have SDL2 added.. YET, we are simply
 gonna do a boolean for keypress.
 
 */

bool bKeys[256];
bool bKeyPressed(int _keyCode) {
    return bKeys[_keyCode];
}

#define GetAsyncKeyState(_x) bKeyPressed(_x);

/* Some test drawings */
void DrawBox(int x, int y, int w, int h, Color color) {
    pSurface->DrawSetColor(color);
    pSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void DrawBoxOutline(int x, int y, int w, int h, Color color) {
    Drawings->DrawBox(x + 1, y + 1, w - 2, h - 2, Color(0, 0, 0, 120));
    Drawings->DrawBox(x - 1, y - 1, w + 2, h + 2, Color(0, 0, 0, 120));
    Drawings->DrawBox(x, y, w, h, color);
}
/* end */

/* test esp shit */
enum Teams {
    Terrorist = 2,
    CounterTerrorist = 3
};
bool WorldToScreen(Vector& vFrom, Vector& vTo) {
    return (pOverlay->ScreenPosition(vFrom, vTo) != 1);
}

struct bBoxStyle {
    int x, y, w, h;
};

bool DrawPlayerBox(C_BaseEntity* pEntity, bBoxStyle& boxes) {
    if (!pEntity)
        return false;
    
    Vector vOrigin = pEntity->GetVecOrigin();
    Vector min = pEntity->GetCollideable()->OBBMins() + vOrigin;
    Vector max = pEntity->GetCollideable()->OBBMaxs() + vOrigin;
    
    Vector points[] = { Vector(min.x, min.y, min.z),
        Vector(min.x, max.y, min.z),
        Vector(max.x, max.y, min.z),
        Vector(max.x, min.y, min.z),
        Vector(max.x, max.y, max.z),
        Vector(min.x, max.y, max.z),
        Vector(min.x, min.y, max.z),
        Vector(max.x, min.y, max.z) };

    Vector flb;
    Vector brt;
    Vector blb;
    Vector frt;
    Vector frb;
    Vector brb;
    Vector blt;
    Vector flt;
    
    
    if (!WorldToScreen(points[3], flb) || !WorldToScreen(points[5], brt)
        || !WorldToScreen(points[0], blb) || !WorldToScreen(points[4], frt)
        || !WorldToScreen(points[2], frb) || !WorldToScreen(points[1], brb)
        || !WorldToScreen(points[6], blt) || !WorldToScreen(points[7], flt))
        return false;
    
    Vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };
    
    float left = flb.x;        // left
    float top = flb.y;        // top
    float right = flb.x;    // right
    float bottom = flb.y;    // bottom
    
    for (int i = 1; i < 8; i++)
    {
        if (left > arr[i].x)
            left = arr[i].x;
        if (bottom < arr[i].y)
            bottom = arr[i].y;
        if (right < arr[i].x)
            right = arr[i].x;
        if (top > arr[i].y)
            top = arr[i].y;
    }
    
    boxes.x = left;
    boxes.y = top;
    boxes.w = right - left;
    boxes.h = bottom - top;
    return true;
}

auto TestTrace(C_BaseEntity* pEntity, C_BaseEntity* pLocal) -> bool { /* Just a simple visible check :^) */
    Ray_t ray;
    trace_t trace;
    CTraceFilter filter;
    filter.pSkip = pLocal;
    
    ray.Init(pLocal->GetEyePosition(), pEntity->GetEyePosition());
    pEngineTrace->TraceRay(ray, 0x4600400B, &filter, &trace);
    
    return (trace.m_pEnt == pEntity || trace.fraction > 0.99f);
}

void DrawSkeleton(C_BaseEntity* pEntity, Color color) {
    studiohdr_t* pStudioModel = pModelInfo->GetStudioModel( pEntity->GetModel() );
    if ( pStudioModel ) {
        static matrix3x4_t pBoneToWorldOut[128];
        if ( pEntity->SetupBones( pBoneToWorldOut, 128, 256, 0) )
        {
            for ( int i = 0; i < pStudioModel->numbones; i++ )
            {
                mstudiobone_t* pBone = pStudioModel->pBone( i );
                if ( !pBone || !( pBone->flags & 256 ) || pBone->parent == -1 )
                    continue;
                
                
                Vector vBone1 = pEntity->GetBonePosition(i);
                Vector vBoneOut1;
                
                Vector vBone2 = pEntity->GetBonePosition(pBone->parent);
                Vector vBoneOut2;
                
                if(WorldToScreen(vBone1, vBoneOut1) && WorldToScreen(vBone2, vBoneOut2)) {
                    Drawings->DrawLine(vBoneOut1.x, vBoneOut1.y, vBoneOut2.x, vBoneOut2.y, color);
                }
            }
        }
    }
}

/*
*/

void makeshittyesp() {
    C_BaseEntity* pLocal = (C_BaseEntity*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    for(int i = 0; i < pEntList->GetHighestEntityIndex(); i++) {
        C_BaseEntity* pEntity = (C_BaseEntity*)pEntList->GetClientEntity(i);
        
        if(!pEntity)
            continue;
        
        if(pEntity->GetHealth() < 1)
            continue;
        
        if(pEntity->GetDormant())
            continue;
        
        if(pEntity == pLocal)
            continue;
        
        if(pEntity->GetTeam() != Terrorist && pEntity->GetTeam() != CounterTerrorist)
            continue;
        
        bBoxStyle testbox;
        
        auto isVisible = TestTrace(pEntity, pLocal);
        
        IEngineClient::player_info_t pInfo;
        pEngine->GetPlayerInfo(i, &pInfo);
        
        if(DrawPlayerBox(pEntity, testbox)) {
            if(pEntity->GetTeam() == Terrorist) {
                DrawBoxOutline(testbox.x, testbox.y, testbox.w, testbox.h, isVisible ? Color::Red() : Color::Yellow());
            }
            if(pEntity->GetTeam() == CounterTerrorist) {
                DrawBoxOutline(testbox.x, testbox.y, testbox.w, testbox.h, isVisible ? Color::Green() : Color::Blue());
            }
            Drawings->DrawHealthbar(testbox.x - 5, testbox.y, 3, testbox.h, pEntity->GetHealth(), Color::Green());
            Drawings->DrawString(testbox.x + testbox.w / 2, testbox.y - 12/* 12 = the font size */, Color::White(), testfont, true, pInfo.name);
            DrawSkeleton(pEntity, Color::White());
        }
    }
}
/* end */



void hkPaintTraverse(void* thisptr, VPANEL vguiPanel, bool forceRepaint, bool allowForce) {
    testvmt->GetOriginalMethod<tPaintTraverse>(42)(thisptr, vguiPanel, forceRepaint, allowForce);
    
    static VPANEL currentPanel = 0;
    
    if(!currentPanel) {
        
        if(strstr(pPanel->GetName(vguiPanel), "FocusOverlayPanel")) {
            
            testfont = pSurface->CreateFont();
            pSurface->SetFontGlyphSet(testfont, "Tahoma", 12, 250, 0, 0, FONTFLAG_ANTIALIAS | FONTFLAG_DROPSHADOW);
            
            currentPanel = vguiPanel;
            
        }
    }
    
    if(vguiPanel == currentPanel) {
    
        /* Draw your stuff here. */
        makeshittyesp();
       // DrawBoxOutline(10, 20, 30, 40, Color::Black());
        
        /* Test with FontAwesome */
        Drawings->DrawString(10, 20, Color::White(), testfont, "MicroWave Open-Source BETA.");

    }
    
}
