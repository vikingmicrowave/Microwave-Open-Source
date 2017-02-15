#ifndef main_hpp
#define main_hpp

#include <stdio.h>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <sys/mman.h>
#include <dlfcn.h>
#include <fstream>
#include <mach/mach_traps.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach.h>
#include <mach-o/dyld_images.h>
#include <mach-o/loader.h>
#include <libproc.h>
#include <sys/stat.h>
#include <cstddef>
#include <codecvt>
#include <cstring>
#include <sstream>
#include <vector>
#include <string>
#include <vector>
#include <strings.h>
#include <string>
#include <ios>
#include <iomanip>
#include <pwd.h>
#include <zconf.h>
#include <fstream>
#include <cstdio>

using namespace std;

#include "Vector.h"
#include "Others.h"
#include "common.h"
#include "Color.h"
#include "IBaseClientDLL.h"
#include "ISurface.h"
#include "IPanel.h"
#include "ICvar.h"
#include "netvarmanager.h"
#include "offsets.h"
#include "C_BaseEntity.h"
#include "IClientEntityList.h"
#include "IVDebugOverlay.h"
#include "IEngineClient.h"
#include "IEngineTrace.h"
#include "IMaterial.h"
#include "IVModelInfo.h"
#include "CUserCmd.h"

/* Hack Related. */
#include "hacks.hpp"

/* Drawings */
#include "Drawings.hpp"

/* VMT */
#include "VMT.h"

/* Hooks */
#include "Hooks.hpp"

/* Interfaces */
#include "interfaces.hpp"

#endif /* main_hpp */
