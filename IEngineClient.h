class IEngineClient {
public:
    typedef struct player_info_s
    {
        int64_t __pad0;
        union {
            int64_t xuid;
            struct {
                int xuidlow;
                int xuidhigh;
            };
        };
        char name[128];
        int userid;
        char guid[33];
        unsigned int friendsid;
        char friendsname[128];
        bool fakeplayer;
        bool ishltv;
        unsigned int customfiles[4];
        unsigned char filesdownloaded;
    }player_info_t;

    bool GetPlayerInfo(int iIndex, player_info_t *pInfo) {
        typedef bool (* oGetPlayerInfo)(void*, int, player_info_t*);
        return getvfunc<oGetPlayerInfo>(this, 8)(this, iIndex, pInfo);
    }
    
    bool IsInGame() {
        typedef bool (* oIsInGame)(void*);
        return getvfunc<oIsInGame>(this, 26)(this);
    }
    
    bool IsConnected() {
        typedef bool (* oIsConnected)(void*);
        return getvfunc<oIsConnected>(this, 27)(this);
    }
    
    int GetLocalPlayer() {
        typedef int (* oGetLocalPlayer)(void*);
        return getvfunc<oGetLocalPlayer>(this, 12)(this);
    }

};
