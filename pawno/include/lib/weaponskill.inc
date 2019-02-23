/*

	About: weapon skill functions
	Author: ziggi

*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before weaponskill"
#endif

#if defined _weaponskill_included
	#endinput
#endif

#define _weaponskill_included

/*
	Defines
*/

#if !defined MAX_WEAPON_SKILL_LEVEL
	#define MAX_WEAPON_SKILL_LEVEL 1000
#endif

#if !defined MIN_WEAPON_SKILL_LEVEL
	#define MIN_WEAPON_SKILL_LEVEL 0
#endif

#define MAX_WEAPON_SKILLS 10
#define INVALID_WEAPON_SKILL_ID -1

/*
	Vars
*/

static const
	gWeaponSkills[] = {
		WEAPONSKILL_PISTOL, // 22
		WEAPONSKILL_PISTOL_SILENCED, // 23
		WEAPONSKILL_DESERT_EAGLE, // 24
		WEAPONSKILL_SHOTGUN, // 25
		WEAPONSKILL_SAWNOFF_SHOTGUN, // 26
		WEAPONSKILL_SPAS12_SHOTGUN, // 27
		WEAPONSKILL_MICRO_UZI, // 28
		WEAPONSKILL_MP5, // 29
		WEAPONSKILL_AK47, // 30
		WEAPONSKILL_M4, // 31
		WEAPONSKILL_MICRO_UZI // 32
	};

static const
	gSkillNames[MAX_WEAPON_SKILLS][15 char] = {
		!"Pistol", // WEAPONSKILL_PISTOL
		!"Pistol Silenced", // WEAPONSKILL_PISTOL_SILENCED
		!"Desert Eagle", // WEAPONSKILL_DESERT_EAGLE
		!"Shotgun", // WEAPONSKILL_SHOTGUN
		!"Sawnoff Shotgun", // WEAPONSKILL_SAWNOFF_SHOTGUN
		!"SPAS12 Shotgun", // WEAPONSKILL_SPAS12_SHOTGUN
		!"Micro-UZI", // WEAPONSKILL_MICRO_UZI
		!"MP5", // WEAPONSKILL_MP5
		!"AK47", // WEAPONSKILL_AK47
		!"M4" // WEAPONSKILL_M4
	};

static
	gPlayerWeaponSkill[MAX_PLAYERS][MAX_WEAPON_SKILLS];

/*
	SetPlayerSkillLevel
*/

stock WS_SetPlayerSkillLevel(playerid, skill, level)
{
	if (!(0 <= skill < MAX_WEAPON_SKILLS)) {
		return 0;
	}

	if (level > MAX_WEAPON_SKILL_LEVEL) {
		level = MAX_WEAPON_SKILL_LEVEL;
	} else if (level < MIN_WEAPON_SKILL_LEVEL) {
		level = MIN_WEAPON_SKILL_LEVEL;
	}

	gPlayerWeaponSkill[playerid][skill] = level;

	return
		SetPlayerSkillLevel(playerid, skill, level);
}
#if defined _ALS_SetPlayerSkillLevel
	#undef SetPlayerSkillLevel
#else
	#define _ALS_SetPlayerSkillLevel
#endif

#define SetPlayerSkillLevel WS_SetPlayerSkillLevel

/*
	GetPlayerSkillLevel
*/

stock GetPlayerSkillLevel(playerid, skill)
{
	if (!(0 <= skill < MAX_WEAPON_SKILLS)) {
		return INVALID_WEAPON_SKILL_ID;
	}
	return gPlayerWeaponSkill[playerid][skill];
}

/*
	GivePlayerSkillLevel
*/

stock GivePlayerSkillLevel(playerid, skill, amount)
{
	if (!(0 <= skill < MAX_WEAPON_SKILLS)) {
		return 0;
	}

	amount += GetPlayerSkillLevel(playerid, skill);

	return
		SetPlayerSkillLevel(playerid, skill, amount);
}

/*
	GetPlayerSkillLevelArray
*/

stock GetPlayerSkillLevelArray(playerid, array[MAX_WEAPON_SKILLS])
{
	array = gPlayerWeaponSkill[playerid];
}

/*
	SetPlayerSkillLevelArray
*/

stock SetPlayerSkillLevelArray(playerid, array[MAX_WEAPON_SKILLS])
{
	gPlayerWeaponSkill[playerid] = array;

	for (new skill = 0; skill < MAX_WEAPON_SKILLS; skill++) {
		SetPlayerSkillLevel(playerid, skill, array[skill]);
	}
}

/*
	ResetPlayerSkillLevel
*/

stock ResetPlayerSkillLevel(playerid)
{
	for (new skill = 0; skill < MAX_WEAPON_SKILLS; skill++) {
		SetPlayerSkillLevel(playerid, skill, 0);
	}
}

/*
	GetWeaponSkillName
*/

stock GetWeaponSkillName(skill, name[], const size = sizeof(name))
{
	if (!(0 <= skill < MAX_WEAPON_SKILLS)) {
		return 0;
	}
	return strunpack(name, gSkillNames[skill], size);
}

/*
	GetWeaponSkillID
*/

stock GetWeaponSkillID(weaponid)
{
	new index = weaponid - 22;
	if (!(0 <= index < sizeof(gWeaponSkills))) {
		return INVALID_WEAPON_SKILL_ID;
	}
	return gWeaponSkills[index];
}
