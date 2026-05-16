#include <algorithm>
#include <vector>

#include "hook/Call.hpp"
#include "hook/hook.hpp"
#include "types.hpp"


using namespace hook;

const struct S
{
    S()
    {
        // no more dpnhpast.dll loading (DirectPlay)
        Write<u8>(0x74754A, 0xB8);
        Write<u32>(0x74754B, 0x900);

        // Unlocked widescreen resolutions
        Write<u32>(0x745B81, 0x9090587D);
        Write<u32>(0x74596C, 0x9090127D);
        MakeNop(0x745970, 2);

        MakeNop(0x745B85, 2);
        MakeNop(0x7459E1, 2);

        // at least default to 1080p
        Write<u32>(0x746363, 1920);
        Write<u32>(0x746368, 1080);

        // Disable re-initialization of DirectInput mouse device by the game
        Write<u8>(0x576CCC, 0xEB);
        Write<u8>(0x576EBA, 0xEB);
        Write<u8>(0x576F8A, 0xEB);

        // No framedelay
        Write<u16>(0x53E923, 0x43EB);
        Write<u8>(0x53E99F, 0x10);
        MakeNop(0x53E9A5, 1);

        // make the game pick the best refresh rate instead of 60
        MakeRet0(0x7460A0);
    }
} s;
