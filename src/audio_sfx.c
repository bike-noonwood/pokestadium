#include "audio_sfx.h"
#include "src/libnumus/player.h"
#include "src/audio_sfx.h"
#include "src/audio_commands_category2.h"
#include "src/audio_commands.h"
#include "src/audio_data.h"

static s32 D_80078A30 = 0;
static s32 scroll_sfx = 0;
static s32 back_sfx = 0;
static s32 confirm_sfx = 0;
static s32 D_80078A40 = 0;
static s32 D_80078A44 = 0;
static s32 D_80078A48 = 0;
static s32 D_80078A4C = 0;
static u8 D_80078A50 = 0;

s32 Audio_PlaySoundEffectById(u32 sfx) {
    u32 temp_v0_3;
    s32 sp28;
    f32 sp24;

    temp_v0_3 = sfx & 0xFFFF0000;
    sp28 = 0x80;
    sp24 = 0.0f;

    if (temp_v0_3 == 0x01200000) {
        return Audio_PlayCategory12SoundCommand(sfx, 0, 0);
    }

    if (temp_v0_3 == 0x01100000) {
        return Audio_PlayCategory11SoundCommand(sfx, 0, 0);
    }

    if (sfx == 0xF) {
        if (!(D_800FC820 & 0x80000000)) {
            return 0;
        }
        D_80078A30 = Audio_PlaySoundEffect(D_800FF9C0, D_800FC688, 0xF, 0x70, 0x80, -1);
        Audio_QueueFadeSoundCommand(D_80078E70, 0x28);
        return D_80078A30;
    }

    if (sfx == 0x30) {
        sfx = 0x26;
    }

    if (sfx == 0x3C) {
        if (D_80078A50 != 0) {
            D_80078A50++;
            if (D_80078A50 > 0) {
                D_80078A50 = 0;
            }
            return 0;
        }
        D_80078A50++;
        if (1) {}
        sfx = 5;
        sp24 = -12.0f;
        sp28 = 0x38;
    }

    switch (sfx) {
        case 0x1:
            Audio_QueueFadeSoundCommand(scroll_sfx, 1);
            break;

        case 0x5:
        case 0x6:
        case 0x7:
        case 0x9:
        case 0xD:
        case 0xE:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2F:
            break;

        case 0x2:
            Audio_QueueFadeSoundCommand(confirm_sfx, 1);
            break;

        case 0x3:
            Audio_QueueFadeSoundCommand(back_sfx, 1);
            break;

        case 0x4:
            Audio_QueueFadeSoundCommand(D_80078A40, 0x14);
            break;

        case 0x8:
            Audio_QueueFadeSoundCommand(D_80078A44, 2);
            break;

        case 0x2C:
            Audio_QueueFadeSoundCommand(D_80078A48, 2);
            sp28 = 0xA0;
            break;

        case 0x2D:
            Audio_QueueFadeSoundCommand(D_80078A48, 2);
            break;

        case 0x2E:
            Audio_QueueFadeSoundCommand(D_80078A4C, 2);
            break;

        case 0xA:
            sp28 = 0xE0;
            break;

        case 0x31:
            sfx -= 1;
            break;

        case 0xB:
        case 0xC:
            sp28 = 0xD0;
            break;

        case 0x2A:
        case 0x2B:
            Audio_PlaySoundEffectById(0x1B);
            break;

        case 0x32:
            D_80078A30 = Audio_PlayDirectSoundCommand(0x01000001, 0, 0);
            return D_80078A30;

        case 0x33:
            D_80078A30 = Audio_PlayDirectSoundCommand(0x01000002, 0, 0);
            return D_80078A30;

        default:
            return 0;
    }

    D_80078A30 = Audio_PlaySoundEffect(D_800FC68C, D_800FC688, sfx, sp28, 0x80, -1);
    if (sp24 != 0.0f) {
        Audio_QueueVoiceDetune(D_80078A30, sp24);
    }

    switch (sfx) {
        case 1:
            scroll_sfx = D_80078A30;
            break;

        case 2:
            confirm_sfx = D_80078A30;
            break;

        case 3:
            back_sfx = D_80078A30;
            break;

        case 4:
            D_80078A40 = D_80078A30;
            break;

        case 8:
            D_80078A44 = D_80078A30;
            break;

        case 44:
            D_80078A48 = D_80078A30;
            break;

        case 45:
            D_80078A4C = D_80078A30;
            break;
    }

    return D_80078A30;
}
