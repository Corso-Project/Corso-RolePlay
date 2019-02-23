/*

	About: get spawn info function
	Author: ziggi

*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before getspawninfo"
#endif

#if defined _getspawninfo_included
	#endinput
#endif

#define _getspawninfo_included

/*
	Defines
*/

#define MAX_PLAYER_CLASS 320

/*
	Enums
*/

enum e_Spawn_Info {
	bool:e_sIsUsed,
	e_sTeam,
	e_sSkin,
	Float:e_sPosX,
	Float:e_sPosY,
	Float:e_sPosZ,
	Float:e_sRotation,
	e_sWeapon1,
	e_sWeapon1_Ammo,
	e_sWeapon2,
	e_sWeapon2_Ammo,
	e_sWeapon3,
	e_sWeapon3_Ammo,
}

/*
	Vars
*/

static
	gPlayerSpawn[MAX_PLAYERS][e_Spawn_Info],
	gPlayerClass[MAX_PLAYER_CLASS][e_Spawn_Info];

/*
	AddPlayerClass
*/

stock SpawnInfo_AddPlayerClass(skin,
                               Float:x, Float:y, Float:z, Float:angle,
                               weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new classid = AddPlayerClass(skin, x, y, z, angle,
	                             weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	gPlayerClass[classid][e_sIsUsed] = true;
	gPlayerClass[classid][e_sTeam] = NO_TEAM;
	gPlayerClass[classid][e_sSkin] = skin;
	gPlayerClass[classid][e_sPosX] = x;
	gPlayerClass[classid][e_sPosY] = y;
	gPlayerClass[classid][e_sPosZ] = z;
	gPlayerClass[classid][e_sRotation] = angle;
	gPlayerClass[classid][e_sWeapon1] = weapon1;
	gPlayerClass[classid][e_sWeapon1_Ammo] = weapon1_ammo;
	gPlayerClass[classid][e_sWeapon2] = weapon2;
	gPlayerClass[classid][e_sWeapon2_Ammo] = weapon2_ammo;
	gPlayerClass[classid][e_sWeapon3] = weapon3;
	gPlayerClass[classid][e_sWeapon3_Ammo] = weapon3_ammo;
	return classid;
}
#if defined _ALS_AddPlayerClass
	#undef AddPlayerClass
#else
	#define _ALS_AddPlayerClass
#endif

#define AddPlayerClass SpawnInfo_AddPlayerClass

/*
	AddPlayerClassEx
*/

stock SpawnInfo_AddPlayerClassEx(teamid, skin,
                                 Float:x, Float:y, Float:z, Float:angle,
                                 weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new classid = AddPlayerClassEx(teamid, skin, x, y, z, angle,
	                               weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	gPlayerClass[classid][e_sIsUsed] = true;
	gPlayerClass[classid][e_sTeam] = teamid;
	gPlayerClass[classid][e_sSkin] = skin;
	gPlayerClass[classid][e_sPosX] = x;
	gPlayerClass[classid][e_sPosY] = y;
	gPlayerClass[classid][e_sPosZ] = z;
	gPlayerClass[classid][e_sRotation] = angle;
	gPlayerClass[classid][e_sWeapon1] = weapon1;
	gPlayerClass[classid][e_sWeapon1_Ammo] = weapon1_ammo;
	gPlayerClass[classid][e_sWeapon2] = weapon2;
	gPlayerClass[classid][e_sWeapon2_Ammo] = weapon2_ammo;
	gPlayerClass[classid][e_sWeapon3] = weapon3;
	gPlayerClass[classid][e_sWeapon3_Ammo] = weapon3_ammo;
	return classid;
}
#if defined _ALS_AddPlayerClassEx
	#undef AddPlayerClassEx
#else
	#define _ALS_AddPlayerClassEx
#endif

#define AddPlayerClassEx SpawnInfo_AddPlayerClassEx

/*
	SetSpawnInfo
*/

stock SpawnInfo_SetSpawnInfo(playerid, team, skin,
                             Float:x, Float:y, Float:z, Float:rotation,
                             weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	gPlayerSpawn[playerid][e_sIsUsed] = true;
	gPlayerSpawn[playerid][e_sTeam] = team;
	gPlayerSpawn[playerid][e_sSkin] = skin;
	gPlayerSpawn[playerid][e_sPosX] = x;
	gPlayerSpawn[playerid][e_sPosY] = y;
	gPlayerSpawn[playerid][e_sPosZ] = z;
	gPlayerSpawn[playerid][e_sRotation] = rotation;
	gPlayerSpawn[playerid][e_sWeapon1] = weapon1;
	gPlayerSpawn[playerid][e_sWeapon1_Ammo] = weapon1_ammo;
	gPlayerSpawn[playerid][e_sWeapon2] = weapon2;
	gPlayerSpawn[playerid][e_sWeapon2_Ammo] = weapon2_ammo;
	gPlayerSpawn[playerid][e_sWeapon3] = weapon3;
	gPlayerSpawn[playerid][e_sWeapon3_Ammo] = weapon3_ammo;
	return SetSpawnInfo(playerid, team, skin, x, y, z, rotation,
	                    weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}
#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define _ALS_SetSpawnInfo
#endif

#define SetSpawnInfo SpawnInfo_SetSpawnInfo

/*
	OnPlayerConnect
*/

public OnPlayerConnect(playerid)
{
	gPlayerSpawn[playerid][e_sIsUsed] = false;

	#if defined SpawnInfo_OnPlayerConnect
		return SpawnInfo_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect SpawnInfo_OnPlayerConnect
#if defined SpawnInfo_OnPlayerConnect
	forward SpawnInfo_OnPlayerConnect(playerid);
#endif

/*
	OnPlayerRequestClass
*/

public OnPlayerRequestClass(playerid, classid)
{
	if (!gPlayerSpawn[playerid][e_sIsUsed]) {
		gPlayerSpawn[playerid] = gPlayerClass[classid];
	}

	#if defined SpawnInfo_OnPlayerRequestClass
		return SpawnInfo_OnPlayerRequestClass(playerid, classid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerRequestClass
	#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif

#define OnPlayerRequestClass SpawnInfo_OnPlayerRequestClass
#if defined SpawnInfo_OnPlayerRequestClass
	forward SpawnInfo_OnPlayerRequestClass(playerid, classid);
#endif

/*
	GetSpawnInfo
*/

stock GetSpawnInfo(playerid, &team = NO_TEAM, &skin = 0,
                   &Float:x = 0.0, &Float:y = 0.0, &Float:z = 0.0, &Float:rotation = 0.0,
                   &weapon1 = 0, &weapon1_ammo = 0, &weapon2 = 0, &weapon2_ammo = 0, &weapon3 = 0, &weapon3_ammo = 0)
{
	team = gPlayerSpawn[playerid][e_sTeam];
	skin = gPlayerSpawn[playerid][e_sSkin];
	x = gPlayerSpawn[playerid][e_sPosX];
	y = gPlayerSpawn[playerid][e_sPosY];
	z = gPlayerSpawn[playerid][e_sPosZ];
	rotation = gPlayerSpawn[playerid][e_sRotation];
	weapon1 = gPlayerSpawn[playerid][e_sWeapon1];
	weapon1_ammo = gPlayerSpawn[playerid][e_sWeapon1_Ammo];
	weapon2 = gPlayerSpawn[playerid][e_sWeapon2];
	weapon2_ammo = gPlayerSpawn[playerid][e_sWeapon2_Ammo];
	weapon3 = gPlayerSpawn[playerid][e_sWeapon3];
	weapon3_ammo = gPlayerSpawn[playerid][e_sWeapon3_Ammo];
}
