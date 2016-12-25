public OnPlayerRequestClass(playerid, classid)
{
	if (P[playerid][_p_in_game] == true) {
        SetSpawnInfo(playerid, 0, P[playerid][p_skin], 1642.4329,-2239.0205,13.4967,180.0, 0,0,0,0,0,0);
        SpawnPlayer(playerid);
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
	TogglePlayerSpectating(playerid, 1);
	GetPlayerName(playerid, P[playerid][p_name], MAX_PLAYER_NAME);
	if (Name_IsValid(P[playerid][p_name]) == 0)
        return ShowPlayerDialog(playerid, d_account_name_error, DIALOG_STYLE_MSGBOX, "Имя персонажа",SERVER_NAME"\n\n{B22222}Имя вашего персонажа несоответствует нашим условиям.\nПравильный формат:\n\n\t{FFFFFF}Имя_Фамилия (на английском)","Выход","");

	new ORM: ormid = P[playerid][_p_ormid] = orm_create("accounts");

	orm_addvar_int(ormid, P[playerid][p_uid], "UID");
	orm_addvar_string(ormid, P[playerid][p_name], MAX_PLAYER_NAME+1, "Name");
	orm_addvar_string(ormid, P[playerid][p_password], 129, "Password");
	orm_addvar_int(ormid, P[playerid][p_access], "Access");
	orm_addvar_string(ormid, P[playerid][p_unban_date], 16, "Unban_Date");
	orm_addvar_string(ormid, P[playerid][p_last_ip], 46, "Last_IP");
	orm_addvar_string(ormid, P[playerid][p_reg_ip], 46, "Reg_IP");
	orm_addvar_float(ormid, P[playerid][p_cash], "Cash");
	orm_addvar_int(ormid, P[playerid][p_sex], "Sex");
	orm_addvar_int(ormid, P[playerid][p_skin], "Skin");
	orm_addvar_int(ormid, P[playerid][p_job_team], "Job_Team");
	orm_addvar_int(ormid, P[playerid][p_level], "Level");
	orm_addvar_int(ormid, P[playerid][p_exp], "Exp");
	orm_addvar_int(ormid, P[playerid][p_health], "Health");
	orm_addvar_int(ormid, P[playerid][p_armour], "Armour");
	orm_addvar_int(ormid, P[playerid][p_weapon_1], "Weapon_1");
	orm_addvar_int(ormid, P[playerid][p_weapon_2], "Weapon_2");
	orm_addvar_int(ormid, P[playerid][p_weapon_3], "Weapon_3");
	orm_addvar_int(ormid, P[playerid][p_weapon_4], "Weapon_4");
	orm_addvar_int(ormid, P[playerid][p_ammo_2], "Ammo_2");
	orm_addvar_int(ormid, P[playerid][p_ammo_3], "Ammo_3");
	orm_addvar_int(ormid, P[playerid][p_ammo_4], "Ammo_4");
	orm_addvar_int(ormid, P[playerid][p_lic_moto], "Lic_Moto");
	orm_addvar_int(ormid, P[playerid][p_lic_car], "Lic_Car");
	orm_addvar_int(ormid, P[playerid][p_lic_freight], "Lic_Freight");
	orm_addvar_int(ormid, P[playerid][p_lic_boat], "Lic_Boat");
	orm_addvar_int(ormid, P[playerid][p_lic_helicopter], "Lic_Helicopter");
	orm_addvar_int(ormid, P[playerid][p_lic_aircraft], "Lic_Aircraft");
	orm_addvar_int(ormid, P[playerid][p_lic_business], "Lic_Business");
	orm_addvar_int(ormid, P[playerid][p_lic_weapon], "Lic_Weapon");

	orm_setkey(ormid, "Name");
	orm_select(ormid, "OnMySQL_SelectAccount", "d", playerid);

	P[playerid][_p_speedo] = CreatePlayerTextDraw(playerid, 520.0, 340.0, "~w~123.0 ~b~KM/H~n~FUEL: ~w~123~n~~g~E ~g~L ~g~D");
	PlayerTextDrawLetterSize(playerid, P[playerid][_p_speedo], 0.5, 2.0);
	PlayerTextDrawTextSize(playerid, P[playerid][_p_speedo], 80.0, 160.0);
	PlayerTextDrawAlignment(playerid, P[playerid][_p_speedo], 2);
	PlayerTextDrawColor(playerid, P[playerid][_p_speedo], 41215);
	PlayerTextDrawUseBox(playerid, P[playerid][_p_speedo], 1);
	PlayerTextDrawBoxColor(playerid, P[playerid][_p_speedo], 51);
	PlayerTextDrawSetShadow(playerid, P[playerid][_p_speedo], 0);
	PlayerTextDrawSetOutline(playerid, P[playerid][_p_speedo], 1);
	PlayerTextDrawBackgroundColor(playerid, P[playerid][_p_speedo], 255);
	PlayerTextDrawFont(playerid, P[playerid][_p_speedo], 2);
	PlayerTextDrawSetProportional(playerid, P[playerid][_p_speedo], 1);

	P[playerid][_p_cent] = CreatePlayerTextDraw(playerid, 607.0, 97.0, "12 cent");
	PlayerTextDrawLetterSize(playerid, P[playerid][_p_cent], 0.5, 2.1);
	PlayerTextDrawAlignment(playerid, P[playerid][_p_cent], 3);
	PlayerTextDrawColor(playerid, P[playerid][_p_cent], 0x33AA33AD);
	PlayerTextDrawSetShadow(playerid, P[playerid][_p_cent], 0);
	PlayerTextDrawSetOutline(playerid, P[playerid][_p_cent], 2);
	PlayerTextDrawBackgroundColor(playerid, P[playerid][_p_cent], 0x000000FF);
	PlayerTextDrawFont(playerid, P[playerid][_p_cent], 3);
	PlayerTextDrawSetProportional(playerid, P[playerid][_p_cent], 1);

	P[playerid][SpecText] = CreatePlayerTextDraw(playerid, 314.000000, 375.000000, " ");
	PlayerTextDrawAlignment(playerid, P[playerid][SpecText], 2);
	PlayerTextDrawBackgroundColor(playerid, P[playerid][SpecText], 16843038);
	PlayerTextDrawFont(playerid, P[playerid][SpecText], 1);
	PlayerTextDrawLetterSize(playerid, P[playerid][SpecText], 0.210000, 0.799999);
	PlayerTextDrawColor(playerid, P[playerid][SpecText], 16711935);
	PlayerTextDrawSetOutline(playerid, P[playerid][SpecText], 1);
	PlayerTextDrawSetProportional(playerid, P[playerid][SpecText], 1);

	ChoseSkin[0] = CreatePlayerTextDraw(playerid, 412.823516, 391.166687, "usebox");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[0], 0.000000, 1.887034);
	PlayerTextDrawTextSize(playerid, ChoseSkin[0], 253.058822, 0.000000);
	PlayerTextDrawAlignment(playerid, ChoseSkin[0], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[0], 0);
	PlayerTextDrawUseBox(playerid, ChoseSkin[0], true);
	PlayerTextDrawBoxColor(playerid, ChoseSkin[0], 0x00000030);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[0], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[0], 0);
	PlayerTextDrawFont(playerid, ChoseSkin[0], 0);

	ChoseSkin[1] = CreatePlayerTextDraw(playerid, 410.941192, 392.333312, "usebox");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[1], 0.000000, 1.627777);
	PlayerTextDrawTextSize(playerid, ChoseSkin[1], 254.941192, 0.000000);
	PlayerTextDrawAlignment(playerid, ChoseSkin[1], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[1], 0);
	PlayerTextDrawUseBox(playerid, ChoseSkin[1], true);
	PlayerTextDrawBoxColor(playerid, ChoseSkin[1], 0x00000035);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[1], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[1], 0);
	PlayerTextDrawFont(playerid, ChoseSkin[1], 0);

	ChoseSkin[2] = CreatePlayerTextDraw(playerid, 303.176483, 392.916687, "usebox");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[2], 0.000000, 1.498145);
	PlayerTextDrawTextSize(playerid, ChoseSkin[2], 255.411773, 0.000000);
	PlayerTextDrawAlignment(playerid, ChoseSkin[2], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[2], 0);
	PlayerTextDrawUseBox(playerid, ChoseSkin[2], true);
	PlayerTextDrawBoxColor(playerid, ChoseSkin[2], 0x00000040);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[2], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[2], 0);
	PlayerTextDrawFont(playerid, ChoseSkin[2], 0);

	ChoseSkin[3] = CreatePlayerTextDraw(playerid, 410.470367, 392.916687, "usebox");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[3], 0.000000, 1.498145);
	PlayerTextDrawTextSize(playerid, ChoseSkin[3], 362.705657, 0.000000);
	PlayerTextDrawAlignment(playerid, ChoseSkin[3], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[3], 0);
	PlayerTextDrawUseBox(playerid, ChoseSkin[3], true);
	PlayerTextDrawBoxColor(playerid, ChoseSkin[3], 0x00000030);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[3], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[3], 0);
	PlayerTextDrawFont(playerid, ChoseSkin[3], 0);

	ChoseSkin[4] = CreatePlayerTextDraw(playerid, 365.764617, 392.916625, "usebox");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[4], 0.000000, 1.474182);
	PlayerTextDrawTextSize(playerid, ChoseSkin[4], 300.117645, 0.000000);
	PlayerTextDrawAlignment(playerid, ChoseSkin[4], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[4], 0);
	PlayerTextDrawUseBox(playerid, ChoseSkin[4], true);
	PlayerTextDrawBoxColor(playerid, ChoseSkin[4], 0x00000030);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[4], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[4], 0);
	PlayerTextDrawFont(playerid, ChoseSkin[4], 0);

	ChoseSkin[5] = CreatePlayerTextDraw(playerid, 266.352966, 392.000030, "<<");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[5], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, ChoseSkin[5], 295.999847, 13.416666);
	PlayerTextDrawAlignment(playerid, ChoseSkin[5], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[5], -1);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[5], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[5], 1);
	PlayerTextDrawBackgroundColor(playerid, ChoseSkin[5], 51);
	PlayerTextDrawFont(playerid, ChoseSkin[5], 3);
	PlayerTextDrawSetProportional(playerid, ChoseSkin[5], 1);
	PlayerTextDrawSetSelectable(playerid, ChoseSkin[5], true);

	ChoseSkin[6] = CreatePlayerTextDraw(playerid, 314.823638, 391.416778, "Save");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[6], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, ChoseSkin[6], 367.528869, 15.166643);
	PlayerTextDrawAlignment(playerid, ChoseSkin[6], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[6], -1);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[6], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[6], 1);
	PlayerTextDrawBackgroundColor(playerid, ChoseSkin[6], 51);
	PlayerTextDrawFont(playerid, ChoseSkin[6], 1);
	PlayerTextDrawSetProportional(playerid, ChoseSkin[6], 1);
	PlayerTextDrawSetSelectable(playerid, ChoseSkin[6], true);

	ChoseSkin[7] = CreatePlayerTextDraw(playerid, 376.470550, 391.999938, ">>");
	PlayerTextDrawLetterSize(playerid, ChoseSkin[7], 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, ChoseSkin[7], 403.764556, 14.000002);
	PlayerTextDrawAlignment(playerid, ChoseSkin[7], 1);
	PlayerTextDrawColor(playerid, ChoseSkin[7], -1);
	PlayerTextDrawSetShadow(playerid, ChoseSkin[7], 0);
	PlayerTextDrawSetOutline(playerid, ChoseSkin[7], 1);
	PlayerTextDrawBackgroundColor(playerid, ChoseSkin[7], 51);
	PlayerTextDrawFont(playerid, ChoseSkin[7], 3);
	PlayerTextDrawSetProportional(playerid, ChoseSkin[7], 1);
	PlayerTextDrawSetSelectable(playerid, ChoseSkin[7], true);
	//
	TextDrawShowForPlayer(playerid, Corso);

	//PlayerPlaySound(playerid, 1097, 0.0, 0.0, 10.0);
	SetTimerEx("SetPlayerCameraPos_", 500, 0, "d", playerid);

	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if (P[playerid][_p_ormid]) {
	    if (P[playerid][_p_in_game] == true)
            orm_update(P[playerid][_p_ormid]);
	    orm_destroy(P[playerid][_p_ormid]);
	}
	for (new i = 0; i < sizeof(P[]); i++)
        P[playerid][E_PLAYER_DATA: i] = 0;

	StopAudioStreamForPlayer(playerid);
	return 1;
}
public OnPlayerSpawn(playerid)
{
	if(P[playerid][_p_in_game] == true)
	{
		SetPlayerColor(playerid, 0xFFFFFF22);
		ResetPlayerMoney(playerid);
		GivePlayerMoney(playerid, floatround(P[playerid][p_cash]));
		new string[16];
		format(string, sizeof(string), "%.0f Cent", floatmul(floatfract(P[playerid][p_cash]), 100.0));
		PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
		PlayerTextDrawShow(playerid, P[playerid][_p_cent]);
		switch(P[playerid][p_job_team]) {
			// Организаций
			case ORG_GOVERNMENT:{
				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerPos(playerid, 1128.7860,-2043.8292,69.4214);
				SetPlayerFacingAngle(playerid,273.4582);
				SetPlayerColor(playerid, 0xe6FB0122);
			}
	    	case ORG_FBI:
			{
	        	SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerPos(playerid, 1214.8512,-1675.8368,11.7969);
				SetPlayerFacingAngle(playerid, 308.0);
				SetPlayerColor(playerid, 0x1C5A8DFF);
	    	}
	    	default:
			{
	        	SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerPos(playerid, 1642.4329,-2239.0205,13.4967);
				SetPlayerFacingAngle(playerid, 180.0);
			}
		}
		TogglePlayerClock(playerid, 1);
		SetCameraBehindPlayer(playerid);
		SetPlayerSkin(playerid, P[playerid][p_skin]);
		if(P[playerid][p_health] <= 0 || P[playerid][p_health] > 100) P[playerid][p_health] = 100;
		SetPlayerHealth(playerid, P[playerid][p_health]);
		SetPlayerArmour(playerid, P[playerid][p_armour]);
		ResetPlayerWeapons(playerid);
		if(P[playerid][p_weapon_1] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_1], 1);
		if(P[playerid][p_weapon_2] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_2], P[playerid][p_ammo_2]);
		if(P[playerid][p_weapon_3] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_3], P[playerid][p_ammo_3]);
		if(P[playerid][p_weapon_4] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_4], P[playerid][p_ammo_4]);
		for(new i=0; i < sizeof(ZoneInfo); i++)
			GangZoneShowForPlayer(playerid, ZoneID[i], GetTeamZoneColor(ZoneInfo[i][zTeam]));
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	PlayerTextDrawHide(playerid, P[playerid][_p_cent]);
	P[playerid][p_health] = 0;
	P[playerid][_p_spawned] = false;
	return 1;
}

public OnPlayerText(playerid, text[])
{
	if(!P[playerid][_p_in_game]) return 0;
	if((gettime() - P[playerid][_p_chat_time]) < 3) return 0;
	if(containsAnyIP(text)) return 0;
	if(strlen(P[playerid][_p_chat_msg]) == strlen(text)) {
		if(strcmp(P[playerid][_p_chat_msg], text, true) == 0) return 0;
	}
	strtolower(text);
	format(P[playerid][_p_chat_msg], 128, text);
	SetPlayerChatBubble(playerid, text, 0xFFFFFFFF, 35.0, 5000);
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 8.1, 0, 0, 0, 0, 2000, 1);
	new Float: x, Float: y, Float: z;
	new line1[128], line2[128];
	if(strlen(text) > 64) {
		new pos = strfind(text, " ", false, 64);
		if(pos == (-1)) pos = 64;
		strmid(line1, text, 0, pos);
		strmid(line2, text, pos, strlen(text));
	}
	GetPlayerPos(playerid, x,y,z);
	foreach(new i : Player) {
	    if(!P[i][_p_in_game]) continue;
	    if(!IsPlayerInRangeOfPoint(i, 35.0, x,y,z)) continue;
	    if(GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) continue;
	    if(GetPlayerInterior(i) != GetPlayerInterior(playerid)) continue;
	    switch(P[playerid][p_sex]) {
		    case SEX_FEMALE: switch(strlen(text)) {
				case 0..64: va_SendClientMessage(i, -1, "%s сказала: %s", IC_Name(playerid),text);
				default: {
				    va_SendClientMessage(i, -1, "%s сказала: %s", IC_Name(playerid),line1);
				    SendClientMessage(i, -1, line2);
				}
			}
		    case SEX_MALE: switch(strlen(text)) {
				case 0..64: va_SendClientMessage(i, -1, "%s сказал: %s", IC_Name(playerid),text);
				default: {
				    va_SendClientMessage(i, -1, "%s сказал: %s", IC_Name(playerid),line1);
				    SendClientMessage(i, -1, line2);
				}
			}
		}
	}
	P[playerid][_p_chat_time] = gettime();
	return 0;
}
public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags){
    if(result == -1)
		return 0;
    return 1;
}
public OnPlayerStateChange(playerid, newstate, oldstate)
{
	if(newstate == PLAYER_STATE_DRIVER) {
        PlayerTextDrawShow(playerid, P[playerid][_p_speedo]);
	    new vehicleid = GetPlayerVehicleID(playerid);
	    new engine,lights,alarm,doors,bonnet,boot,objective;
	    GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
	    if(doors == 1) RemovePlayerFromVehicle(playerid);
	    if(V[vehicleid][_v_stream_id] != 0) PlayAudioStreamForPlayer(playerid, V[vehicleid][_v_stream_url]);
	    for(new i; i < sizeof(V_TAXI); i++) {
	        if(P[playerid][p_job_team] != JOB_TAXI) break;
	        if(vehicleid != V_TAXI[i]) continue;
	        if(V_TAXI_OWNER[i] != 0) break;
	        if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
                break;
            }
            new source[128];
            format(source, sizeof(source),
				"{FFFFFF}Данный автомобиль такси сдаётся в аренду.\n\n\
				Введите время аренды. От 1 минуты ($%.2f) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_taxi, DIALOG_STYLE_INPUT, "Аренда такси",source,"Аренда","Выйти");
            break;
	    }
	    for(new i; i < sizeof(V_ENGINEER); i++) {
	        if(P[playerid][p_job_team] != JOB_ENGINEER) break;
	        if(vehicleid != V_ENGINEER[i]) continue;
	        if(V_ENGINEER_OWNER[i] != 0) break;
	        if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
                break;
            }
            new source[128];
            format(source, sizeof(source),
				"{FFFFFF}Данный автомобиль инженеров сдаётся в аренду.\n\n\
				Введите время аренды. От 1 минуты ($%.2f) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_officecar, DIALOG_STYLE_INPUT, "Аренда служебного транспорта",source,"Аренда","Выйти");
            break;
	    }
	    for(new i; i < sizeof(V_FREIGHTER); i++) {
	        if(P[playerid][p_job_team] != JOB_FREIGHTER) break;
	        if(vehicleid != V_FREIGHTER[i]) continue;
	        if(V_FREIGHTER_OWNER[i] != 0) break;
	        if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
                break;
            }
            new source[128];
            format(source, sizeof(source),
				"{FFFFFF}Данный грузовой автомобиль сдаётся в аренду.\n\n\
				Введите время аренды. От 1 минуты ($%.2f) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_truck, DIALOG_STYLE_INPUT, "Аренда грузовика",source,"Аренда","Выйти");
            break;
	    }
	    for(new i; i < sizeof(V_RENT); i++) {
	        if(vehicleid != V_RENT[i]) continue;
	        if(V_RENT_OWNER[i] != 0) break;
	        if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
                break;
            }
            new source[128];
            format(source, sizeof(source),
				"{FFFFFF}Данное транспортное средство сдаётся в аренду.\n\n\
				Введите время аренды. От 1 минуты ($%.2f) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_car, DIALOG_STYLE_INPUT, "Аренда транспорта",source,"Аренда","Выйти");
            break;
	    }
	}
	if(oldstate == PLAYER_STATE_DRIVER) {
	    PlayerTextDrawHide(playerid, P[playerid][_p_speedo]);
		StopAudioStreamForPlayer(playerid);
	}
	if(newstate == PLAYER_STATE_PASSENGER) {
		new vehicleid = GetPlayerVehicleID(playerid);
		new engine,lights,alarm,doors,bonnet,boot,objective;
		GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
	    if(doors == 1) RemovePlayerFromVehicle(playerid);
		if(V[vehicleid][_v_stream_id] != 0) PlayAudioStreamForPlayer(playerid, V[vehicleid][_v_stream_url]);
	}
	if(oldstate == PLAYER_STATE_PASSENGER) {
		StopAudioStreamForPlayer(playerid);
	}
	return 1;
}
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(P[playerid][_p_in_game] == false) return 0;

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new vehicleid = GetPlayerVehicleID(playerid);

	    // Управление автомобилем
	    if(newkeys & KEY_YES)
	    {
	    	new source[202],str_engine[36],str_lights[32],str_doors[30],str_bonnet[30],str_boot[33];
	    	new engine,lights,alarm,doors,bonnet,boot,objective;
	    	GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
	    	switch(engine) {
	    	    case -1,0: str_engine = "{00FF00}Включить {FFFFFF}двигатель";
	    	    case 1: str_engine = "{FF0000}Отключить {FFFFFF}двигатель";
	    	}
	    	switch(lights) {
	    	    case -1,0: str_lights = "{00FF00}Включить {FFFFFF}фары";
	    	    case 1: str_lights = "{FF0000}Отключить {FFFFFF}фары";
	    	}
	    	switch(doors) {
	    	    case -1,0: str_doors = "{FF0000}Закрыть {FFFFFF}двери";
	    	    case 1: str_doors = "{00FF00}Открыть {FFFFFF}двери";
	    	}
	    	switch(bonnet) {
	    	    case -1,0: str_bonnet = "{00FF00}Открыть {FFFFFF}капот";
	    	    case 1: str_bonnet = "{FF0000}Закрыть {FFFFFF}капот";
	    	}
	    	switch(boot) {
	    	    case -1,0: str_boot = "{00FF00}Открыть {FFFFFF}багажник";
	    	    case 1: str_boot = "{FF0000}Закрыть {FFFFFF}багажник";
	    	}
	    	switch(IsTrailerAttachedToVehicle(vehicleid)) {
	    		case 0: format(source, sizeof(source),
					"%s\n%s\n%s\n%s\n%s\nАвтомобильное радио",
					str_engine,str_lights,str_doors,str_bonnet,str_boot);
				case 1: format(source, sizeof(source),
					"%s\n%s\n%s\n%s\n%s\nАвтомобильное радио\nОтцепить трейлер",
					str_engine,str_lights,str_doors,str_bonnet,str_boot);
			}
	    	ShowPlayerDialog(playerid, d_vehicle_panel, DIALOG_STYLE_LIST, "Управление автомобилем",source,"Выбор","Отмена");
	    }
	    // Anti Speed Hack
	    if(newkeys & KEY_FIRE || oldkeys & KEY_FIRE)
	    {
	        if(Vehicle_Speed(vehicleid) > 270) P[playerid][_p_cheater]++;
	    }
	}
	// Меню
	if(newkeys & KEY_NO)
	{
	    ShowPlayerDialog(playerid, d_player_menu, DIALOG_STYLE_LIST, "Главное меню", "Информация о персонаже\nНастройки учётной записи\nСправка о доступных командах\nСправка о правилах сервера\nОбратная связь", "Открыть", "Выход");
	}
	// Открытие ворот и/или шлагбаумов
	if(newkeys & KEY_CROUCH)
	{
		if(IsPlayerInRangeOfPoint(playerid, 15.0, 1286.1700,-1652.1000,16.5500)) {
		    if(P[playerid][p_job_team] == ORG_FBI && obj_state_FBI == false) {
		        obj_state_FBI = true;
				MoveDynamicObject(obj_FBI, 1286.1700,-1652.1000,22.0000, MOVE_GATE_SPEED, 0.0000,0.0000,90.0000);
				defer OnGateClosed(obj_FBI);
		    }
	    }
	    if(IsPlayerInRangeOfPoint(playerid, 15.0, 1544.68994, -1629.98999, 13.22000)) {
			if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_LSPD && obj_state_LSPD == false) {
	            obj_state_LSPD = true;
	            MoveDynamicObject(obj_LSPD, 1544.68994, -1630.81995, 12.90000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 90.00000);
	            defer OnGateClosed(obj_LSPD);
	        }
	    }
	    if(IsPlayerInRangeOfPoint(playerid, 15.0, -1572.19995, 658.63000, 6.98000)) {
	        if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_SFPD && obj_state_SFPD[0] == false) {
	            obj_state_SFPD[0] = true;
	            MoveDynamicObject(obj_SFPD[0], -1572.19995, 658.79999, 6.65000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 90.00000);
	            defer OnGateClosed(obj_SFPD[0]);
	        }
	    }
	    if(IsPlayerInRangeOfPoint(playerid, 15.0, -1701.43005, 687.79498, 24.78000)) {
	        if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_SFPD && obj_state_SFPD[1] == false) {
	            obj_state_SFPD[1] = true;
	            MoveDynamicObject(obj_SFPD[1], -1701.43005, 687.63000, 24.45000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 270.00000);
	            defer OnGateClosed(obj_SFPD[1]);
	        }
	    }
	    if(IsPlayerInRangeOfPoint(playerid, 15.0, 2238.18994, 2450.21997, 10.71000)) {
	        if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_LVPD && obj_state_LVPD == false) {
	            obj_state_LVPD = true;
	            MoveDynamicObject(obj_LVPD, 2238.18994, 2450.37988, 10.37000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 90.00000);
	            defer OnGateClosed(obj_LVPD);
	        }
	    }
	    if(IsPlayerInRangeOfPoint(playerid, 15.0, 286.00000, 1822.00000, 20.03000)) {
	        if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_MILITARY && obj_state_MILITARY[0] == false) {
	            obj_state_MILITARY[0] = true;
	            MoveDynamicObject(obj_MILITARY[0], 286.00000, 1833.00000, 20.03000, MOVE_GATE_SPEED, 0.00000, 0.00000, 90.00000);
	            defer OnGateClosed(obj_MILITARY[0]);
	        }
	    }
	    if(IsPlayerInRangeOfPoint(playerid, 15.0, 134.85001, 1941.53406, 21.71000)) {
	        if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_MILITARY && obj_state_MILITARY[1] == false) {
	            obj_state_MILITARY[1] = true;
	            MoveDynamicObject(obj_MILITARY[1], 122.00000, 1941.53406, 21.71000, MOVE_GATE_SPEED, 0.00000, 0.00000, 180.00000);
	            defer OnGateClosed(obj_MILITARY[1]);
	        }
	    }
	}
	if(newkeys & KEY_ACTION)
	{
		new engine,lights,alarm,doors,bonnet,boot,objective;
		new vehicleid = GetPlayerVehicleID(playerid);
		GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
		switch(engine)
		{
			// двигатель
			case -1,0:
			{
				if(Vehicle_IsNotForPlayer(vehicleid, playerid)) return 1;
				if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0)
				{
					return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
				}
				if(Vehicle_WithoutFuel(GetVehicleModel(vehicleid)) == 0)
				{
				    if(!IsPlayerInAnyVehicle(playerid)) return true;
					if(V[vehicleid][v_fuel] <= 0) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}В автомобиле закончилось топливо!");
				}
				SetVehicleParamsEx(vehicleid, 1,lights,alarm,doors,bonnet,boot,objective);
			}
			case 1: SetVehicleParamsEx(vehicleid, 0,lights,alarm,doors,bonnet,boot,objective);
		}
	}
	if(newkeys & KEY_FIRE)
	{
		new engine,lights,alarm,doors,bonnet,boot,objective;
		new vehicleid = GetPlayerVehicleID(playerid);
		GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
		switch(lights)
		{
  			case -1,0: SetVehicleParamsEx(vehicleid, engine,1,alarm,doors,bonnet,boot,objective);
     		case 1: SetVehicleParamsEx(vehicleid, engine,0,alarm,doors,bonnet,boot,objective);
	    }
	}
	if(newkeys & KEY_SPRINT)
	{
		if(gSpectateType[playerid] == 1)
		{
			PlayerTextDrawHide(playerid, P[playerid][SpecText]);
			TogglePlayerSpectating(playerid, 0);
			gSpectateID[playerid] = INVALID_PLAYER_ID;
			gSpectateType[playerid] = 0;
		}
	}
	return 0;
}

public OnPlayerUpdate(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    if(P[playerid][_p_in_game] == false) return 0;

    if(P[playerid][_p_cheater] >= 10) {
        Kick(playerid);
        return 0;
    }

	new string[32];
	format(string, sizeof(string), "%.0f Cent", floatmul(floatfract(P[playerid][p_cash]), 100.0));
	PlayerTextDrawSetString(playerid,P[playerid][_p_cent], string);
	PlayerTextDrawShow(playerid, P[playerid][_p_cent]);

    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
	{
		Message_ToAdmins(0xB9C9BFFF, "[Защита]: Реактивный ранец - %s[%d]", Name(playerid),playerid);
	    Kick(playerid);
	    return 0;
	}

	Weapon_Sync(playerid);
	Health_Sync(playerid);
	Armour_Sync(playerid);

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
		Speedo_Sync(playerid);
	}

	SetPlayerTime(playerid, g_hour, g_minute);
	return 1;
}

public OnPlayerClickMap(playerid, Float: fX, Float: fY, Float: fZ)
{
	if(P[playerid][p_access] < 3) return 1;

	switch(GetPlayerState(playerid)) {
	    case 0,7..9: return 1;
	    case 1,3..6: {
	        if(GetPlayerInterior(playerid) != 0) SetPlayerInterior(playerid, 0);
	        if(GetPlayerVirtualWorld(playerid) != 0) SetPlayerVirtualWorld(playerid, 0);
	        SetPlayerPosFindZ(playerid, fX,fY,fZ+0.1);
	    }
	    case 2: SetVehiclePos(GetPlayerVehicleID(playerid), fX,fY,fZ+0.1);
	}
	return 1;
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
	if(weaponid == P[playerid][p_weapon_2])
	{
		P[playerid][p_ammo_2]--;
		if(P[playerid][p_ammo_2] <= 0)
		{
		    P[playerid][p_ammo_2] = 0;
			P[playerid][p_weapon_2] = 0;
		}
	}
	else if(weaponid == P[playerid][p_weapon_3])
	{
		P[playerid][p_ammo_3]--;
		if(P[playerid][p_ammo_3] <= 0)
		{
		    P[playerid][p_ammo_3] = 0;
			P[playerid][p_weapon_3] = 0;
		}
	}
	else if(weaponid == P[playerid][p_weapon_4])
	{
		P[playerid][p_ammo_4]--;
		if(P[playerid][p_ammo_4] <= 0)
		{
		    P[playerid][p_ammo_4] = 0;
			P[playerid][p_weapon_4] = 0;
		}
	}
    return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float: amount, weaponid, bodypart)
{
	switch(weaponid) {
	    case 37,47,49..51,53,54: {
	        P[playerid][p_health] -= floatround(amount);
            if(P[playerid][p_health] < 0) P[playerid][p_health] = 0;
            SetPlayerHealth(playerid, P[playerid][p_health]);
	    }
	    default: {
	        if(P[playerid][p_armour] > 0) {
	            P[playerid][p_armour] -= floatround(amount);
	            if(P[playerid][p_armour] < 0) {
	                P[playerid][p_health] -= P[playerid][p_armour];
	                P[playerid][p_armour] = 0;
	                SetPlayerHealth(playerid, P[playerid][p_health]);
	            }
	            SetPlayerArmour(playerid, P[playerid][p_armour]);
	        }
	        else if(P[playerid][p_armour] == 0) {
	            P[playerid][p_health] -= floatround(amount);
	            if(P[playerid][p_health] < 0) P[playerid][p_health] = 0;
	            SetPlayerHealth(playerid, P[playerid][p_health]);
	        }
	    }
	}
	return 0;
}

public OnPlayerEnterDynamicCP(playerid,checkpointid)
{
	if(checkpointid == Buy_Weapon){
		new source[180];
		format(source, sizeof(source),
			"Оружие\tЦена\tПатроны\n\
			Desert Eagle\t$%.2f\t100\n\
			Shotgun\t$%.2f\t100\n\
			Micro SMG/Uzi\t$%.2f\t100\n\
			MP5\t$%.2f\t100\n\
			Country Rifle\t$%.2f\t100\n",
			Prices_Deagle,Prices_ShotGun,Prices_Uzi,Prices_MP5,Prices_CRifle);
		ShowPlayerDialog(playerid, d_player_buy_gun, DIALOG_STYLE_TABLIST_HEADERS, "Покупка оружия",source,"Выбор","Выйти");
	}
	return true;
}
public OnPlayerEnterCheckpoint(playerid)
{
    DisablePlayerCheckpoint(playerid);
    return 1;
}
public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
	if(pickupid == Ammu_Nation[0])
	{
		if(P[playerid][p_lic_weapon] == 0) return SendClientMessage(playerid, -1,"{FF6600}Чтобы войти Вам нужно иметь лицензию на оружие");
		SetPlayerInterior(playerid,1);
		SetPlayerPos(playerid,286.9145,-38.6596,1001.5156);
		SetPlayerFacingAngle(playerid, 329.0564);
		SetPlayerVirtualWorld(playerid, 0);
	}
	else if(pickupid == Ammu_Nation[1])
	{
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,1366.5776,-1279.5397,13.5469);
		SetPlayerFacingAngle(playerid, 89.7301);
		SetPlayerVirtualWorld(playerid,0);
	}
	else if(pickupid == Ammu_Nation[2])
	{
		if(P[playerid][p_lic_weapon] == 0) return SendClientMessage(playerid, -1,"{FF6600}Чтобы войти Вам нужно иметь лицензию на оружие");
		SetPlayerInterior(playerid,4);
		SetPlayerPos(playerid,286.8773,-83.5809,1001.5156);
		SetPlayerFacingAngle(playerid, 334.2157);
		SetPlayerVirtualWorld(playerid, 0);
	}
	else if(pickupid == Ammu_Nation[3])
	{
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,-2626.6384,210.3960,4.5971);
		SetPlayerFacingAngle(playerid, 13.1113);
		SetPlayerVirtualWorld(playerid,0);
	}
	else if(pickupid == Ammu_Nation[4])
	{
	    if(P[playerid][p_lic_weapon] == 0) return SendClientMessage(playerid, -1,"{FF6600}Чтобы войти Вам нужно иметь лицензию на оружие");
		SetPlayerInterior(playerid,7);
		SetPlayerPos(playerid,313.7110,-140.3784,999.6016);
		SetPlayerFacingAngle(playerid, 334.2157);
		SetPlayerVirtualWorld(playerid, 0);
 	}
	else if(pickupid == Ammu_Nation[5])
	{
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,2156.1997,943.3864,10.8203);
		SetPlayerFacingAngle(playerid, 81.7582);
		SetPlayerVirtualWorld(playerid,0);
	}
	else if(pickupid == Ammu_Nation[6])
	{
	    if(P[playerid][p_lic_weapon] == 0) return SendClientMessage(playerid, -1,"{FF6600}Чтобы войти Вам нужно иметь лицензию на оружие");
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 0);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0);
 	}
 	else if(pickupid == Ammu_Nation[7])
	{
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,2400.5554,-1980.2947,13.5469);
		SetPlayerFacingAngle(playerid, 5.1592);
		SetPlayerVirtualWorld(playerid,0);

		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Casino[0]){
		SetPlayerInterior(playerid, 10);
		SetPlayerVirtualWorld(playerid, 1);
		SetPlayerPos(playerid,2016.2699,1017.7790,996.8750);
	}
	else if(pickupid == Casino[1]){
		SetPlayerInterior(playerid,0);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid,2022.6709,1007.9366,10.8203);
	}
	else if(pickupid == LSPD[0]){
		SetPlayerInterior(playerid, 6);
		SetPlayerPos(playerid,246.2850,64.8440,1003.6406);
		SetPlayerFacingAngle(playerid, 359.2673);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == LSPD[1]){
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,1552.6376,-1675.5725,16.1953);
		SetPlayerFacingAngle(playerid, 92.8291);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == CityHall[0]){
		SetPlayerInterior(playerid, 3);
		SetPlayerPos(playerid,384.808624,173.804992,1008.382812);
	}
    return 1;
}
public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	new team = P[playerid][p_job_team];
	new s_current = P[playerid][_p_skin_shop];
    if(playertextid == ChoseSkin[5])
    {
		switch(P[playerid][p_sex]) {
			case SEX_MALE: {
		 		if(s_current == 1) s_current = male_skins[team][1];
 	 			else s_current--;
				SetPlayerSkin(playerid,male_skins[team][s_current]);
			}
			case SEX_FEMALE: {
				if(s_current == 1) s_current = female_skins[team][0];
				else s_current--;
				SetPlayerSkin(playerid,female_skins[team][s_current]);
			}
		}
		P[playerid][_p_skin_shop] = s_current;
    }
	else if(playertextid == ChoseSkin[7]){

		switch(P[playerid][p_sex]) {
			case SEX_MALE:
			{
				if(s_current == male_skins[team][0]) s_current = 1;
	            else s_current++;
				SetPlayerSkin(playerid,male_skins[team][s_current]);
			}
			case SEX_FEMALE:
			{
				if(s_current == female_skins[team][0]) s_current = 1;
				else s_current++;
				SetPlayerSkin(playerid,female_skins[team][s_current]);
			}
		}
		P[playerid][_p_skin_shop] = s_current;
	}
	else if(playertextid == ChoseSkin[6]){
		switch(P[playerid][_p_in_game]) {
			case false:{
				P[playerid][_p_in_game] = true;
				SpawnPlayer(playerid);
				switch(P[playerid][p_sex]) {
					case SEX_MALE:
					{
						P[playerid][p_skin] = male_skins[team][s_current];
						SetPlayerSkin(playerid,P[playerid][p_skin]);
					}
					case SEX_FEMALE:
					{
						P[playerid][p_skin] = female_skins[team][s_current];
						SetPlayerSkin(playerid,P[playerid][p_skin]);
					}
				}
				P[playerid][p_cash] = g_Payment_Register;
				P[playerid][p_level] = 1;
				P[playerid][p_exp] = 1;
				SetPlayerScore(playerid,P[playerid][p_level]);
				GetPlayerIp(playerid, P[playerid][p_reg_ip], 46);
				orm_insert(P[playerid][_p_ormid], "OnMySQL_InsertAccount", "d", playerid);
				for(new i; i < 8; i++){
					PlayerTextDrawHide(playerid, ChoseSkin[i]);
					CancelSelectTextDraw(playerid);
				}
				printf("debug");
			}
		}
	}
    return 1;
}
public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	new x = 0;
	while(x!=MAX_PLAYERS) {
	    if( IsPlayerConnected(x) &&	GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] == playerid && gSpectateType[x] == 1 ){
   		    SetPlayerInterior(x,newinteriorid);
		}
		x++;
	}
	return true;
}
forward ShowStats(playerid,targetid);
public ShowStats(playerid,targetid){
	new string[256];
	new sex[8];
	sex = (P[playerid][p_sex] == 0) ? "Женский" : "Мужской";
	format(string,sizeof string,"{FFFFFF}Имя:\t\t\t\t\t{0099FF}%s{FFFFFF}\n\
	Уровень:\t\t\t\t%d\n\
	Очки опыта:\t\t\t\t%d из %d\n\
	Организация:\t\t\t\t%s\n\
	Пол:\t\t\t\t\t%s\n\
	Денег:\t\t\t\t\t$%.2f\n",
		Name(playerid),P[playerid][p_level],P[playerid][p_exp],P[playerid][p_level]*6,Get_TeamName(playerid),sex,P[playerid][p_cash]);
	ShowPlayerDialog(playerid,d_null,DIALOG_STYLE_MSGBOX,"Статистика",string,"Выход","");
	return true;
}
forward StartSpectate(playerid, specid);
public StartSpectate(playerid, specid)
{
	PlayerTextDrawShow(playerid, P[playerid][SpecText]);
    SpectateUpdatePlayer(playerid);
    //SpectorsShow(playerid);
    return true;
}
