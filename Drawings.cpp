#include "main.hpp"

HFONT testfont;

void CDrawings::DrawBox(int x, int y, int w, int h, Color color) {
    pSurface->DrawSetColor(color);
    pSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void CDrawings::FillRGBA(int x, int y, int w, int h, Color color) {
    pSurface->DrawSetColor(color);
    pSurface->DrawFilledRect(x, y, x +  w, y + h);
}

void CDrawings::DrawLine(int x, int y, int xx, int yy, Color color) {
    pSurface->DrawSetColor(color);
    pSurface->DrawLine(x, y, xx, yy);
}

std::wstring StringToWstring(std::string str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    
    try
    {
        return converter.from_bytes(str);
    }
    catch (std::range_error)
    {
        std::wostringstream s;
        s << str.c_str();
        return s.str();
    }
}

void CDrawings::DrawString(int x, int y, Color color, HFONT font, const wchar_t* szString) {
    pSurface->DrawSetTextPos(x, y);
    pSurface->DrawSetTextFont(font);
    pSurface->DrawSetTextColor(color);
    pSurface->DrawPrintText(szString, wcslen(szString));
}

void CDrawings::DrawString(int x, int y, Color color, HFONT font, const char* szString) {
    std::wstring wString = StringToWstring(szString);
    pSurface->DrawSetTextPos(x, y);
    pSurface->DrawSetTextFont(font);
    pSurface->DrawSetTextColor(color);
    pSurface->DrawPrintText(wString.c_str(), wcslen(wString.c_str()));
}

void CDrawings::DrawString(int x, int y, Color color, HFONT font, bool bCenter, const char* szString) {
    std::wstring wString = StringToWstring(szString);
    if(bCenter) {
        int wide, tall;
        pSurface->GetTextSize(font, wString.c_str(), wide, tall);
        x -= wide / 2;
        y -= tall / 2;
    }
    pSurface->DrawSetTextPos(x, y);
    pSurface->DrawSetTextFont(font);
    pSurface->DrawSetTextColor(color);
    pSurface->DrawPrintText(wString.c_str(), wcslen(wString.c_str()));
}

void CDrawings::DrawHealthbar(int x, int y, int w, int h, int health, Color color) {
    
    if(health > 100)
        health = 100; // Just a fix, tried without this on Zombie servers.. you don't wanna know what happend.
    
    int hw = h - ((h) * health) / 100;
    this->FillRGBA(x, y - 1, w, h + 2, Color(0, 0, 0, 120)); 
    this->FillRGBA(x, y + hw - 1, w, h - hw + 2, color);
    this->DrawBox(x, y - 1, w, h + 2, Color(0, 0, 0, 200));
}

CDrawings* Drawings = new CDrawings();
