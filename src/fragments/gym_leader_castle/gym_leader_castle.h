#ifndef _FRAGMENT65_H_
#define _FRAGMENT65_H_

#include "global.h"

typedef struct Glc_Trainer {
    /* 0x00 */ u8 loaded;
    /* 0x02 */ s16 portrait_x;
    /* 0x04 */ s32 portrait;
    /* 0x08 */ char* name_length;
} unk_D_84A03138; // size = 0xC

typedef struct unk_D_84A02F00 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 node_state;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 node_x;
    /* 0x0C */ s16 node_y;
    /* 0x0E */ s16 node_width;
    /* 0x10 */ s16 node_height;
    /* 0x12 */ s16 plusing;
    /* 0x14 */ s8 up_neighbour;
    /* 0x15 */ s8 down_neighbour;
    /* 0x16 */ s8 left_neighbour;
    /* 0x17 */ s8 right_neighbour;
    /* 0x18 */ Color_RGBA8 node_color;
    /* 0x1C */ u8* node_texture;
    /* 0x20 */ s16 boss_title;
    /* 0x22 */ s16 file_number;
    /* 0x24 */ u8* alpha;
} CastleMapNode; // size = 0x28

void Glc_DrawBackgroundCrossfade(u8* texture, u8* multiblock_texture, u8 alpha);
void Glc_DrawScaledTextureRgba(s16 x_start, s16 y_start, s16 draw_width, s16 height, s16 load_width, u8* texture, f32 scale);
void func_84A00630(void);
void Glc_DrawScaledTextureIa8(s16 x_start, s16 y_start, s16 width, s16 height, u8* texture, f32 scale);
void Glc_DrawRoomDescription(void);
void Glc_DrawTrainerIntroPanels(void);
void Glc_DrawMapBorder(void);
void Glc_DrawRoomMarkers(void);
void Glc_DrawRoomLabels(void);
void Glc_DrawGymLeaderInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2);
void Glc_DrawEliteFourRoomInfoPanel(CastleMapNode* node, u8 alpha1, u8 alpha2);
void Glc_UpdateRoomInfoPanelFade(void);
void Glc_UpdateMapCursor(void);
void Glc_Draw(void);
s32 func_84A02074(void);
s32 Glc_SelectRoom(void);
void Glc_LoadTrainerPanels(void);
void Glc_ClearTrainerPanels(void);
void Glc_AnimateTrainerPanelsIn(s16 panels_start, s16 panels_end, s16 timer, s16 x_delta);
s32 GymLeaderCastle_ShowIntro(void);
s32 Glc_AdvanceRoom(void);
s16 Glc_RunMenu(s16 action);
s16 Glc_InitMenu(s16 arg0);
s32 GymLeaderCastle_Main(s32 arg0, UNUSED s32 arg1);

#endif // _FRAGMENT65_H_
