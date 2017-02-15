typedef void(*tPaintTraverse)(void*, VPANEL, bool, bool);
typedef void(*tFrameStage)(void*, ClientFrameStage_t);
typedef void(*tCreateMove)(void*, int, float, bool);

extern void hkPaintTraverse(void* thisptr, VPANEL vguiPanel, bool forceRepaint, bool allowForce);
extern void hkFrameStage(void* thisptr, ClientFrameStage_t curStage);
extern bool hkCreateMove(void* thisptr, float flSampleInput, CUserCmd* pCmd);
extern void hkCreateMove(void* thisptr, int sequence_number, float input_sample_frametime, bool active);
