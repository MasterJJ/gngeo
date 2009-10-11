/* Roms/Ram driver interface */
#ifndef H_ROMS
#define H_ROMS

#include "SDL.h"

#define REGION_AUDIO_CPU_BIOS        0
#define REGION_AUDIO_CPU_CARTRIDGE   1
#define REGION_AUDIO_CPU_ENCRYPTED   2
#define REGION_AUDIO_DATA_1          3
#define REGION_AUDIO_DATA_2          4
#define REGION_FIXED_LAYER_BIOS      5
#define REGION_FIXED_LAYER_CARTRIDGE 6
#define REGION_MAIN_CPU_BIOS         7
#define REGION_MAIN_CPU_CARTRIDGE    8
#define REGION_SPRITES               9
#define REGION_SPR_USAGE             10

#define HAS_CUSTOM_CPU_BIOS 0x1
#define HAS_CUSTOM_AUDIO_BIOS 0x2
#define HAS_CUSTOM_SFIX_BIOS 0x4

typedef struct ROM_DEF{
	char name[32];
	char parent[32];
	char longname[128];
	Uint32 year;
	Uint32 romsize[10];
	Uint32 nb_romfile;
	struct romfile{
		char filename[32];
		Uint8 region;
		Uint32 src;
		Uint32 dest;
		Uint32 size;
		Uint32 crc;
	}rom[32];
}ROM_DEF;

typedef struct GAME_INFO {
	char *name;
	char *longname;
	int year;
	Uint32 flags;
}GAME_INFO;

typedef struct ROM_REGION {
	Uint8* p;
	Uint32 size;
}ROM_REGION;

typedef struct GAME_ROMS {
	GAME_INFO info;
	ROM_REGION cpu_m68k;
	ROM_REGION cpu_z80;
	ROM_REGION tiles;
	ROM_REGION game_sfix;
	ROM_REGION bios_sfix;
	ROM_REGION bios_audio;
	ROM_REGION zoom_table;
	ROM_REGION bios_m68k;
	ROM_REGION adpcma;
	ROM_REGION adpcmb;
	ROM_REGION spr_usage;
	ROM_REGION cpu_z80c;
}GAME_ROMS;


int dr_load_roms(GAME_ROMS *r,char *rom_path,char *name);
void dr_free_roms(GAME_ROMS *r);
int dr_save_gno(GAME_ROMS *r,char *filename);

#endif