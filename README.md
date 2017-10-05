# Microwave-Open-Source
Macintosh hack for Counter-Strike: Global Offensive. Open source.
## Get the injector here:
https://github.com/scen/osxinj

Any issues with the injector? See this:
https://github.com/vikingmicrowave/Microwave-Open-Source/issues/2
<hr>
#### Signatures:

SDL_GL_PollEvent

Normal: \x55\x48\x89\xE5\x48\x83\xEC\x00\x48\x89\x7D\xF8\xE8\x2F\x6A\x00\x00\x48\x8B\x3D\x00\x00\x00\x00 xxxxxxx?xxxxxxxxxxxx????
Start: 0x14
End: 0x4
Module: libSDL2-2.0.0.dylib
IDA Style: 55 48 89 E5 48 83 EC ? 48 89 7D F8 E8 2F 6A ? ? 48 8B 3D ? ? ? ? 

SDL_GL_SwapWindow

Normal: \x55\x48\x89\xE5\x48\x83\xEC\x00\x48\x89\x7D\xF8\xE8\xBF\x06\x00\x00\x48\x8B\x3D\x00\x00\x00\x00 xxxxxxx?xxxxxxxxxxxx????
Start: 0x14
End: 0x4
Module: libSDL2-2.0.0.dylib
IDA Style: 55 48 89 E5 48 83 EC ? 48 89 7D F8 E8 BF 06 ? ? 48 8B 3D ? ? ? ? 


CGlobalVarsBase:

Normal: \x48\x8D\x05\x00\x00\x00\x00\x48\x8B\x00\xF3\x0F\x10\x00\x00\xF3\x0F\x11\x83\x00\x00\x00\x00   xxx????xxxxxx??xxxx????
Start: 0x3
End: 0x4
Module: client.dylib
IDA Style: 48 8D 05 ? ? ? ? 48 8B ? F3 0F 10 ? ? F3 0F 11 83 ? ? ? ? 

IClientMode:

Normal: \x55\x48\x89\xE5\x48\x8D\x05\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\xE8\xB9\xFB\x3D\x00\x48\x8B\x08\x48\x8B\x09 xxxxxxx????xxx????xxxxxxxxxxx
Start: 0x7
End: 0x4

IDA Style: 55 48 89 E5 48 8D 05 ? ? ? ? 48 89 05 ? ? ? ? E8 B9 FB 3D ? 48 8B 08 48 8B 09

https://mac.barbossa.pro (This is the site where i will post updates).

#### Gitter
https://gitter.im/Microwave-macOS/Lobby

# Update: 1.0.1
+ Added Drawings
+ Added FrameStage
+ Fixed PaintTraverse
+ Added more functions to the SDK.

# No more updates.
*** There won't be anymore updates. ***

##Credits are mentioned on the thread.

# Note 2:
This is only a csgo cheat, and not a backdoor.

I am not part of the vlone backdoor.

I was going to buy vlone subscription just to test it out, but now i won't.
