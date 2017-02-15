#include "main.hpp"

void hkCreateMove(void* thisptr, int sequence_number, float input_sample_frametime, bool active)
{
    input_vmt->GetOriginalMethod<tCreateMove>(24)(thisptr, sequence_number, input_sample_frametime, active);
    CUserCmd* cmdlist = *(CUserCmd**)((uintptr_t)pInput + 0xEC);
    CUserCmd* cmd = &cmdlist[sequence_number % 150];
    //Work here
    
    
    //Stop work here
    CVerifiedUserCmd* verifiedlist = *(CVerifiedUserCmd**)((uintptr_t)pInput + 0xF0);
    CVerifiedUserCmd* verified = &verifiedlist[sequence_number % 150];
    verified->m_cmd = *cmd;
    verified->m_crc = gCRC.CRC32_ProcessSingleBuffer(cmd, sizeof(cmd));
}
