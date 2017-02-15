extern HFONT testfont;

class CDrawings {
public:
    void DrawBox(int x, int y, int w, int h, Color color);
    void FillRGBA(int x, int y, int w, int h, Color color);
    void DrawLine(int x, int y, int xx, int yy, Color color);
    void DrawString(int x, int y, Color color, HFONT font, const wchar_t* szString);
    void DrawString(int x, int y, Color color, HFONT font, const char* szString);
    void DrawHealthbar(int x, int y, int w, int h, int health, Color color);
    void DrawString(int x, int y, Color color, HFONT font, bool bCenter, const char* szString);
};

extern CDrawings* Drawings;
