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
	if(Name_IsValid(P[playerid][p_name]) == 0)
        return ShowPlayerDialog(playerid, d_account_name_error, DIALOG_STYLE_MSGBOX, "Имя персонажа",SERVER_NAME"\n\n{B22222}Имя вашего персонажа несоответствует нашим условиям.\nПравильный формат:\n\n\t{FFFFFF}Имя_Фамилия (на английском)","Выход","");

	new ORM: ormid = P[playerid][_p_ormid] = orm_create("accounts");

	orm_addvar_int(ormid, P[playerid][p_uid], "UID");
	orm_addvar_string(ormid, P[playerid][p_name], MAX_PLAYER_NAME+1, "Name");
	orm_addvar_string(ormid, P[playerid][p_password], 129, "Password");
	orm_addvar_int(ormid, P[playerid][p_access], "Access");
	orm_addvar_string(ormid, P[playerid][p_unban_date], 16, "Unban_Date");
	orm_addvar_string(ormid, P[playerid][p_last_ip], 46, "Last_IP");
	orm_addvar_string(ormid, P[playerid][p_reg_ip], 46, "Reg_IP");
	orm_addvar_int(ormid, P[playerid][p_cash], "Cash");
	orm_addvar_int(ormid, P[playerid][p_mute], "Mute");
	orm_addvar_int(ormid, P[playerid][p_sex], "Sex");
	orm_addvar_int(ormid, P[playerid][p_skin], "Skin");
	orm_addvar_int(ormid, P[playerid][p_job_team], "Job_Team");
	orm_addvar_int(ormid, P[playerid][p_rang], "Rang");
	orm_addvar_int(ormid, P[playerid][p_level], "Level");
	orm_addvar_int(ormid, P[playerid][p_exp], "Exp");
	orm_addvar_int(ormid, P[playerid][p_health], "Health");
	orm_addvar_int(ormid, P[playerid][p_armour], "Armour");
	orm_addvar_int(ormid, P[playerid][p_vehicle], "Vehicle");
	orm_addvar_int(ormid, P[playerid][p_patrons], "Patrons");
	orm_addvar_int(ormid, P[playerid][p_materials], "Materials");
	orm_addvar_int(ormid, P[playerid][p_business_ps], "Business_PS");
	orm_addvar_int(ormid, P[playerid][p_ticket], "Ticket");
	orm_addvar_int(ormid, P[playerid][p_wanted_level], "Wanted_Level");
	orm_addvar_int(ormid, P[playerid][p_weapon_1], "Weapon_1");
	orm_addvar_int(ormid, P[playerid][p_weapon_2], "Weapon_2");
	orm_addvar_int(ormid, P[playerid][p_weapon_3], "Weapon_3");
	orm_addvar_int(ormid, P[playerid][p_weapon_4], "Weapon_4");
	orm_addvar_int(ormid, P[playerid][p_weapon_5], "Weapon_5");
	orm_addvar_int(ormid, P[playerid][p_ammo_2], "Ammo_2");
	orm_addvar_int(ormid, P[playerid][p_ammo_3], "Ammo_3");
	orm_addvar_int(ormid, P[playerid][p_ammo_4], "Ammo_4");
	orm_addvar_int(ormid, P[playerid][p_ammo_5], "Ammo_5");
	orm_addvar_int(ormid, P[playerid][p_lic_moto], "Lic_Moto");
	orm_addvar_int(ormid, P[playerid][p_lic_car], "Lic_Car");
	orm_addvar_int(ormid, P[playerid][p_lic_freight], "Lic_Freight");
	orm_addvar_int(ormid, P[playerid][p_lic_boat], "Lic_Boat");
	orm_addvar_int(ormid, P[playerid][p_lic_helicopter], "Lic_Helicopter");
	orm_addvar_int(ormid, P[playerid][p_lic_aircraft], "Lic_Aircraft");
	orm_addvar_int(ormid, P[playerid][p_lic_weapon], "Lic_Weapon");
	orm_addvar_int(ormid, P[playerid][p_russifier_type],"Russifier_Type");
	orm_addvar_int(ormid, P[playerid][p_skill_pistol], "Skill_Pistol");
	orm_addvar_int(ormid, P[playerid][p_skill_pistol_silenced], "Skill_Pistol_Silenced");
	orm_addvar_int(ormid, P[playerid][p_skill_desert_eagle], "Skill_Deagle");
	orm_addvar_int(ormid, P[playerid][p_skill_shotgun], "Skill_ShotGun");
	orm_addvar_int(ormid, P[playerid][p_skill_micro_uzi], "Skill_Micro_Uzi");
	orm_addvar_int(ormid, P[playerid][p_skill_mp5], "Skill_MP5");
	orm_addvar_int(ormid, P[playerid][p_skill_ak47], "Skill_AK47");
	orm_addvar_int(ormid, P[playerid][p_skill_m4], "Skill_M4");

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
	
	Wanted_New_Cash = CreatePlayerTextDraw(playerid, 607.0, 122.0, "12 cent");
	PlayerTextDrawLetterSize(playerid, Wanted_New_Cash, 0.5, 2.1);
	PlayerTextDrawAlignment(playerid, Wanted_New_Cash, 3);
	PlayerTextDrawColor(playerid, Wanted_New_Cash, 0x33AA33AD);
	PlayerTextDrawSetShadow(playerid, Wanted_New_Cash, 0);
	PlayerTextDrawSetOutline(playerid, Wanted_New_Cash, 2);
	PlayerTextDrawBackgroundColor(playerid, Wanted_New_Cash, 0x000000FF);
	PlayerTextDrawFont(playerid, Wanted_New_Cash, 3);
	PlayerTextDrawSetProportional(playerid, Wanted_New_Cash, 1);

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
	Press_ALT[0] = CreatePlayerTextDraw(playerid, 6.235276, 173.083343, "box");
	PlayerTextDrawLetterSize(playerid, Press_ALT[0], 0.000000, 7.741176);
	PlayerTextDrawTextSize(playerid, Press_ALT[0], 120.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, Press_ALT[0], 1);
	PlayerTextDrawColor(playerid, Press_ALT[0], -1);
	PlayerTextDrawUseBox(playerid, Press_ALT[0], 1);
	PlayerTextDrawBoxColor(playerid, Press_ALT[0], -1321124438);
	PlayerTextDrawSetShadow(playerid, Press_ALT[0], 0);
	PlayerTextDrawSetOutline(playerid, Press_ALT[0], 0);
	PlayerTextDrawBackgroundColor(playerid, Press_ALT[0], 255);
	PlayerTextDrawFont(playerid, Press_ALT[0], 1);
	PlayerTextDrawSetProportional(playerid, Press_ALT[0], 0);
	PlayerTextDrawSetShadow(playerid, Press_ALT[0], 0);

	Press_ALT[1] = CreatePlayerTextDraw(playerid, 7.647071, 174.249984, "box");
	PlayerTextDrawLetterSize(playerid, Press_ALT[1], 0.000000, 7.411758);
	PlayerTextDrawTextSize(playerid, Press_ALT[1], 118.300003, 0.000000);
	PlayerTextDrawAlignment(playerid, Press_ALT[1], 1);
	PlayerTextDrawColor(playerid, Press_ALT[1], -1);
	PlayerTextDrawUseBox(playerid, Press_ALT[1], 1);
	PlayerTextDrawBoxColor(playerid, Press_ALT[1], 187);
	PlayerTextDrawBackgroundColor(playerid, Press_ALT[1], 187);
	PlayerTextDrawFont(playerid, Press_ALT[1], 1);
	PlayerTextDrawSetProportional(playerid, Press_ALT[1], 1);

	Press_ALT[2] = CreatePlayerTextDraw(playerid, 65.999992, 173.083297, "Press");
	PlayerTextDrawLetterSize(playerid, Press_ALT[2], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, Press_ALT[2], 1);
	PlayerTextDrawColor(playerid, Press_ALT[2], -1);
	PlayerTextDrawBackgroundColor(playerid, Press_ALT[2], 255);
	PlayerTextDrawFont(playerid, Press_ALT[2], 1);
	PlayerTextDrawSetProportional(playerid, Press_ALT[2], 1);

	Press_ALT[3] = CreatePlayerTextDraw(playerid, 59.882350, 204.000015, "ALT");
	PlayerTextDrawLetterSize(playerid, Press_ALT[3], 0.691293, 2.807502);
	PlayerTextDrawAlignment(playerid, Press_ALT[3], 1);
	PlayerTextDrawColor(playerid, Press_ALT[3], -1);
	PlayerTextDrawBackgroundColor(playerid, Press_ALT[3], 255);
	PlayerTextDrawFont(playerid, Press_ALT[3], 1);
	PlayerTextDrawSetProportional(playerid, Press_ALT[3], 1);

	Press_ALT[4] = CreatePlayerTextDraw(playerid, -14.058824, 159.666641, "");
	PlayerTextDrawLetterSize(playerid, Press_ALT[4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, Press_ALT[4], 80.000000, 74.000000);
	PlayerTextDrawAlignment(playerid, Press_ALT[4], 1);
	PlayerTextDrawColor(playerid, Press_ALT[4], -1);
	PlayerTextDrawSetShadow(playerid, Press_ALT[4], 0);
	PlayerTextDrawSetOutline(playerid, Press_ALT[4], 0);
	PlayerTextDrawBackgroundColor(playerid, Press_ALT[4], 0);
	PlayerTextDrawFont(playerid, Press_ALT[4], 5);
	PlayerTextDrawSetProportional(playerid, Press_ALT[4], 0);
	PlayerTextDrawSetShadow(playerid, Press_ALT[4], 0);
	PlayerTextDrawSetPreviewModel(playerid, Press_ALT[4], 19273);
	PlayerTextDrawSetPreviewRot(playerid, Press_ALT[4], 0.000000, 0.000000, 0.000000, 1.000000);
	//
	TextDrawShowForPlayer(playerid, Corso);

	SetPVarInt(playerid, "firstspawn", 1);
	SetPVarInt(playerid, "Buy_PetrolStation",-1);

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
		SetPlayerRussifierType(playerid, RussifierType:P[playerid][p_russifier_type]);
		
		SetPlayerSkillLevel(playerid,WEAPONSKILL_PISTOL,P[playerid][p_skill_pistol]);
		SetPlayerSkillLevel(playerid,WEAPONSKILL_PISTOL_SILENCED,P[playerid][p_skill_pistol_silenced]);
		SetPlayerSkillLevel(playerid,WEAPONSKILL_DESERT_EAGLE,P[playerid][p_skill_desert_eagle]);
		SetPlayerSkillLevel(playerid,WEAPONSKILL_SHOTGUN,P[playerid][p_skill_shotgun]);
		SetPlayerSkillLevel(playerid,WEAPONSKILL_MICRO_UZI,P[playerid][p_skill_micro_uzi]);
		SetPlayerSkillLevel(playerid,WEAPONSKILL_MP5,P[playerid][p_skill_mp5]);
		SetPlayerSkillLevel(playerid,WEAPONSKILL_AK47,P[playerid][p_skill_ak47]);
		SetPlayerSkillLevel(playerid,WEAPONSKILL_M4,P[playerid][p_skill_m4]);
		
		ResetPlayerMoney(playerid);
		GivePlayerMoney(playerid, P[playerid][p_cash]/100);
		if(P[playerid][p_wanted_level] == 0){
			new string[16];
			format(string, sizeof(string), "%d Cent", P[playerid][p_cash] % 100);
			PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
			PlayerTextDrawShow(playerid, P[playerid][_p_cent]);
		}
		else if(P[playerid][p_wanted_level] > 0){
			new string[16];
			format(string, sizeof(string), "%d Cent", P[playerid][p_cash] % 100);
			PlayerTextDrawSetString(playerid, Wanted_New_Cash, string);
			PlayerTextDrawShow(playerid, Wanted_New_Cash);
			
			SetPlayerWantedLevel(playerid, P[playerid][p_wanted_level]);
		}
		switch(P[playerid][p_job_team]) {
			// Организаций
			case ORG_GOVERNMENT:{
				SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerPos(playerid, 1128.7860,-2043.8292,69.4214);
				SetPlayerFacingAngle(playerid,273.4582);
			}
	    	case ORG_FBI:
			{
	        	SetPlayerInterior(playerid, 3);
				SetPlayerPos(playerid, 215.7838,182.6928,1003.0313);
				SetPlayerFacingAngle(playerid, 269.2349);
				SetPlayerColor(playerid, 0x1C5A8DFF);
	    	}
			case ORG_AUTOSCHOOL:
			{
				SetPlayerPos(playerid,-2035.0481,-114.3642,1035.1719);
				SetPlayerFacingAngle(playerid, 219.3287);
				SetPlayerInterior(playerid, 3);
				SetPlayerVirtualWorld(playerid, 1);
			}
			case ORG_GROVE:{
				SetPlayerPos(playerid, 2450.4082,-1688.8137,1013.5078);
				SetPlayerFacingAngle(playerid, 183.1466);
				SetPlayerVirtualWorld(playerid, 2);
				SetPlayerInterior(playerid, 2);
				SetPlayerColor(playerid, 0x33AA33AA);
			}
			case ORG_BALLAS:{
				SetPlayerPos(playerid, -49.8330,1399.4309,1084.4297);
				SetPlayerVirtualWorld(playerid, 2);
				SetPlayerFacingAngle(playerid, 1.5980);
				SetPlayerInterior(playerid, 8);
				SetPlayerColor(playerid, 0x800080AA);
			}
			case ORG_AZTECAS:{
				SetPlayerPos(playerid, 232.1111,1247.3945,1082.1406);
				SetPlayerVirtualWorld(playerid, 2);
				SetPlayerFacingAngle(playerid, 127.5216);
				SetPlayerInterior(playerid, 2);
				SetPlayerColor(playerid, 0x33CCFFAA);
			}
			case ORG_VAGOS:{
				SetPlayerPos(playerid, 333.2571,1125.1559,1083.8828);
				SetPlayerVirtualWorld(playerid, 2);
				SetPlayerFacingAngle(playerid, 75.3197);
				SetPlayerInterior(playerid, 5);
				SetPlayerColor(playerid, 0xFFFF00AA);
			}
			case ORG_RIFA:{
				SetPlayerPos(playerid, -59.2154,1364.5841,1080.2109);
				SetPlayerVirtualWorld(playerid, 2);
				SetPlayerFacingAngle(playerid, 90.8673);
				SetPlayerInterior(playerid, 6);
				SetPlayerColor(playerid, 0x88CCCCBB);
			}
			case ORG_CHINESE:{
				SetPlayerPos(playerid,1266.6045,-787.2869,1084.0149);
				SetPlayerFacingAngle(playerid, 144.7664);
				SetPlayerVirtualWorld(playerid, 1);
				SetPlayerInterior(playerid, 5);
				SetCameraBehindPlayer(playerid);
			}
			case ORG_RUSSIAN:{
				SetPlayerPos(playerid,1266.6045,-787.2869,1084.0149);
				SetPlayerFacingAngle(playerid, 144.7664);
				SetPlayerVirtualWorld(playerid, 2);
				SetPlayerInterior(playerid, 5);
				SetCameraBehindPlayer(playerid);
			}
			case ORG_ITALIAN:{
				SetPlayerPos(playerid,1266.6045,-787.2869,1084.0149);
				SetPlayerFacingAngle(playerid, 144.7664);
				SetPlayerVirtualWorld(playerid, 3);
				SetPlayerInterior(playerid, 5);
				SetCameraBehindPlayer(playerid);
			}
	    	default:
			{
	        	SetPlayerInterior(playerid, 0);
				SetPlayerVirtualWorld(playerid, 0);
				SetPlayerPos(playerid, 1642.4329,-2239.0205,13.4967);
				SetPlayerFacingAngle(playerid, 180.0);
				SetPlayerColor(playerid,0xFFFFFF55);
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
		if(P[playerid][p_weapon_5] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_5], P[playerid][p_ammo_5]);
		if(GetPVarInt(playerid, "firstspawn") == 1){
			for(new i=0; i < sizeof(GZ); i++)
				GangZoneShowForPlayer(playerid, GZ[i][_gz_local], Get_TeamZoneColor(GZ[i][gz_team]));
			GangZoneShowForPlayer(playerid, army, 0x000000AA);
			SetPVarInt(playerid, "firstspawn", 0);
			if(waractive == true && P[playerid][p_job_team] == gangs[0] || waractive == true && P[playerid][p_job_team] == gangs[1]){
				GangZoneFlashForPlayer(playerid, zone, 0xFF000080);
				va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Сейчас у вас проходит бой за территорию с бандой {FF8888}%s{FFFFFF}. Берите оружие и вступайте в бой.",Get_GangName(gangs[1]));
				for(new x; x < 2; x++) TextDrawShowForPlayer(playerid, Capture[x]);
			}
		}
		if(GetPVarInt(playerid,"spec") == 1){
			SetPlayerPos(playerid,GetPVarFloat(playerid,"float_pos_x"),GetPVarFloat(playerid,"float_pos_y"),GetPVarFloat(playerid,"float_pos_z"));
			SetPlayerInterior(playerid, GetPVarInt(playerid, "int_interior"));
			SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "int_virtualworld"));
			SetPlayerFacingAngle(playerid, GetPVarFloat(playerid,"float_angle"));
			DeletePVar(playerid,"spec");
			DeletePVar(playerid,"float_pos_x");
			DeletePVar(playerid,"float_pos_y");
			DeletePVar(playerid,"float_pos_z");
			DeletePVar(playerid,"int_interior");
			DeletePVar(playerid,"int_virtualworld");
			DeletePVar(playerid,"float_angle");
		}
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	PlayerTextDrawHide(playerid, P[playerid][_p_cent]);
	if(P[playerid][p_wanted_level] == 0){
		PlayerTextDrawHide(playerid, P[playerid][_p_cent]);
	}
	else if(P[playerid][p_wanted_level] > 0){
		PlayerTextDrawHide(playerid, Wanted_New_Cash);
	}
	P[playerid][p_health] = 0;
	P[playerid][_p_spawned] = false;
	if(waractive == true){ // Проверяем активно ли
		if(P[killerid][p_job_team] == gangs[0] && P[playerid][p_job_team] == gangs[1]) {
			gangskills[0]++;
		}else if(P[killerid][p_job_team] == gangs[1] && P[playerid][p_job_team] == gangs[0]) {
			gangskills[1]++;
		}
		new string[12];
		format(string, sizeof(string), "%d~n~%d", gangskills[0], gangskills[1]);
		TextDrawSetString(Capture[1],string);
		foreach(new i : Player)
			TextDrawShowForPlayer(i, Capture[1]);
	}
	return 1;
}
public OnPlayerText(playerid, text[])
{
	if(!P[playerid][_p_in_game]) return 0;
	if(P[playerid][p_mute] >= 0) return 0;
	if((gettime() - P[playerid][_p_chat_time]) < 3) return 0;
	if(containsAnyIP(text)) return 0;
	if(strlen(P[playerid][_p_chat_msg]) == strlen(text)) {
		if(strcmp(P[playerid][_p_chat_msg], text, true) == 0) return 0;
	}
	//strtolower(text);
	format(P[playerid][_p_chat_msg], 128, text);
	SetPlayerChatBubble(playerid, text, 0xFFFFFFFF, 35.0, 5000);
	ApplyAnimation(playerid,"PED","IDLE_chat",4.1,0,1,1,1,1,1);
	defer OnPlayerClearAnimation[6000](playerid);
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
		new vehicleid = GetPlayerVehicleID(playerid);
		new engine,lights,alarm,doors,bonnet,boot,objective;
		GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
		PlayerTextDrawShow(playerid, P[playerid][_p_speedo]);
		if(GetVehicleModel(vehicleid) == 481){
			SetVehicleParamsEx(vehicleid, 1,lights,alarm,doors,bonnet,boot,objective);
			PlayerTextDrawHide(playerid, P[playerid][_p_speedo]);
		}
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
				Введите время аренды. От 1 минуты ($%m) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_taxi, DIALOG_STYLE_INPUT, "Аренда такси",source,"Аренда","Выйти");
			P[playerid][_p_dialog] = true;
            break;
	    }
		for(new i; i < sizeof(V_BUS); i++) {
	        if(P[playerid][p_job_team] != JOB_BUS) break;
	        if(vehicleid != V_BUS[i]) continue;
	        if(V_BUS_OWNER[i] != 0) break;
			if(GetPVarInt(playerid,"Bus_Driver_ID") != 0){
				SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы уже взяли в аренду другой автобус.");
				return RemovePlayerFromVehicle(playerid);
			}
	        if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
                break;
            }
            new source[128];
            format(source, sizeof(source),
				"{FFFFFF}Данный автобус сдаётся в аренду.\n\n\
				Введите время аренды. От 25 минут ($%m) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_bus, DIALOG_STYLE_INPUT, "Аренда автобуса",source,"Аренда","Выйти");
			P[playerid][_p_dialog] = true;
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
				Введите время аренды. От 1 минуты ($%m) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_officecar, DIALOG_STYLE_INPUT, "Аренда служебного транспорта",source,"Аренда","Выйти");
			P[playerid][_p_dialog] = true;
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
				Введите время аренды. От 1 минуты ($%m) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_truck, DIALOG_STYLE_INPUT, "Аренда грузовика",source,"Аренда","Выйти");
			P[playerid][_p_dialog] = true;
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
				Введите время аренды. От 1 минуты ($%m) до 240 минут",
				Prices_RentCar_Econom);
            ShowPlayerDialog(playerid, d_vehicle_rent_car, DIALOG_STYLE_INPUT, "Аренда транспорта",source,"Аренда","Выйти");
			P[playerid][_p_dialog] = true;
            break;
	    }
		for(new i; i < sizeof(V_RENT_STANDART); i++) {
	        if(vehicleid != V_RENT_STANDART[i]) continue;
	        if(V_RENT_OWNER_STANDART[i] != 0) break;
	        if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
                break;
            }
            new source[128];
            format(source, sizeof(source),
				"{FFFFFF}Данное транспортное средство сдаётся в аренду.\n\n\
				Введите время аренды. От 1 минуты ($%m) до 240 минут",
				Prices_RentCar_Standart);
            ShowPlayerDialog(playerid, d_vehicle_rent_car_standart, DIALOG_STYLE_INPUT, "Аренда транспорта",source,"Аренда","Выйти");
			P[playerid][_p_dialog] = true;
            break;
	    }
		for(new i; i < sizeof(V_RENT_PREMIUM); i++) {
	        if(vehicleid != V_RENT_PREMIUM[i]) continue;
	        if(V_RENT_OWNER_PREMIUM[i] != 0) break;
	        if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
                break;
            }
            new source[128];
            format(source, sizeof(source),
				"{FFFFFF}Данное транспортное средство сдаётся в аренду.\n\n\
				Введите время аренды. От 1 минуты ($%m) до 240 минут",
				Prices_RentCar_Premium);
            ShowPlayerDialog(playerid, d_vehicle_rent_car_premium, DIALOG_STYLE_INPUT, "Аренда транспорта",source,"Аренда","Выйти");
			P[playerid][_p_dialog] = true;
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

	// Управление автомобилем
	if(newkeys & KEY_YES)
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			if(GetPVarInt(playerid,"id_repair") == 1){
				new engineer = GetPVarInt(playerid,"id_repair")-1;
				new price_offer = GetPVarInt(engineer,"price_repair");

				DeletePVar(engineer,"id_repair");
				DeletePVar(engineer,"price_repair");
				DeletePVar(playerid,"id_repair");
				RepairVehicle(GetPlayerVehicleID(playerid));
				va_SendClientMessage(engineer, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s приянял ваше предложение на починку Т.С.", Name(playerid));
				SendClientMessage(playerid,  0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы приняли предложение на починку вашего Т.С.");
				Cash_Give(playerid, -price_offer);
				Cash_Give(engineer, price_offer);
			} else{
				new vehicleid = GetPlayerVehicleID(playerid);

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
				P[playerid][_p_dialog] = true;
			}
	    }
		else if(GetPVarInt(playerid, "Show_PlayerLic") == 1){
			new licer = GetPVarInt(playerid,"Show_PlayerLic")-1;
			Show_PlayerLic(playerid,licer);
			DeletePVar(playerid, "Show_PlayerLic");
			DeletePVar(licer, "Show_PlayerLic");
		}
		else if(GetPVarInt(playerid, "Show_PlayerSkill") == 1){
			new user = GetPVarInt(playerid,"Show_PlayerSkill");
			Show_PlayerSkill(playerid,user);
			DeletePVar(playerid, "Show_PlayerSkill");
		}
		else if(GetPVarInt(playerid, "Buy_License_B") == 1){
			va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы купили водительские права.");
			new licer = GetPVarInt(playerid,"Buy_License_B");
			va_SendClientMessage(licer, 0xFFCC66FF,"[Уведомление]: {FFFFFF}%s купил у вас водительские права.",IC_Name(playerid));
			Cash_Give(playerid, -1000);
			Cash_Give(licer, 100);
			P[playerid][p_lic_car] = 1;
			DeletePVar(playerid, "Buy_License_B");
			DeletePVar(licer, "Buy_License_B");
		}
		else if(GetPVarInt(playerid, "Buy_License_A") == 1){
			va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы купили права на вождение мотоцикла.");
			new licer = GetPVarInt(playerid,"Buy_License_A");
			va_SendClientMessage(licer, 0xFFCC66FF,"[Уведомление]: {FFFFFF}%s купил у вас права на вождение мотоцикла.",IC_Name(playerid));
			Cash_Give(playerid, -2000);
			Cash_Give(licer, 200);
			P[playerid][p_lic_moto] = 1;
			DeletePVar(playerid, "Buy_License_A");
			DeletePVar(licer, "Buy_License_A");
		}
		else if(GetPVarInt(playerid, "Buy_License_DE") == 1){
			va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы купили права на вождение грузовика.");
			new licer = GetPVarInt(playerid,"Buy_License_DE");
			va_SendClientMessage(licer, 0xFFCC66FF,"[Уведомление]: {FFFFFF}%s купил у вас права на вождение грузовика.",IC_Name(playerid));
			Cash_Give(playerid, -5000);
			Cash_Give(licer, 500);
			P[playerid][p_lic_freight] = 1;
			DeletePVar(playerid, "Buy_License_DE");
			DeletePVar(licer, "Buy_License_DE");
		}
		else if(GetPVarInt(playerid, "Buy_PetrolStation") != -1){
			new seller = GetPVarInt(playerid,"Buy_PetrolStation");
			new price = GetPVarInt(playerid,"Price_PetrolStation");
			new y = GetPVarInt(playerid, "PetrolStation_ID");
			va_SendClientMessageF(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы купили у %s АЗС {FFCC66}%s{FFFFFF} за $%m.",IC_Name(seller),PS[y][ps_name],price);
			va_SendClientMessageF(seller, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s купил у вас АЗС {FFCC66}%s{FFFFFF} за $%m.",IC_Name(playerid),PS[y][ps_name],price);
			new owner[24+1];
			format(owner,sizeof(owner),"%s",Name(playerid));
			P[playerid][p_business_ps] = GetPVarInt(playerid, "PetrolStation_ID");
			P[seller][p_business_ps] = 0;
			PS[P[playerid][p_business_ps]][ps_owner] = owner;
			Cash_Give(seller, price);
			Cash_Give(playerid, -price);
			PS_Update3DInfo(P[playerid][p_business_ps]);
			SetPVarInt(playerid, "Buy_PetrolStation",-1);
			DeletePVar(playerid, "Price_PetrolStation");
			DeletePVar(seller, "Buy_PetrolStation");
			DeletePVar(seller, "Price_PetrolStation");
			orm_update(P[playerid][_p_ormid]);
			orm_update(P[seller][_p_ormid]);
			orm_update(PS[y][_ps_ormid]);
		}
		else if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
		{
			new Float:pos[3];
			GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

			if (pos[1] > (Y_ELEVATOR_POS - 1.8) && pos[1] < (Y_ELEVATOR_POS + 1.8) && pos[0] < (X_ELEVATOR_POS + 1.8) && pos[0] > (X_ELEVATOR_POS - 1.8))
			{
				ShowElevatorDialog(playerid);
			}
			else
			{
				if(pos[1] < (Y_ELEVATOR_POS - 1.81) && pos[1] > (Y_ELEVATOR_POS - 3.8) && pos[0] > (X_ELEVATOR_POS + 1.21) && pos[0] < (X_ELEVATOR_POS + 3.8))
				{
					new i = 13;
					while(pos[2] < GetDoorsZCoordForFloor(i) + 3.5 && i > 0)
						i --;
					if(i == 0 && pos[2] < GetDoorsZCoordForFloor(0) + 2.0)
						i = -1;
					if (i <= 12)
					{
						if (ElevatorState != ELEVATOR_STATE_MOVING)
						{
							if (ElevatorFloor == i + 1)
							{
								GameTextForPlayer(playerid, "~n~~n~~n~~n~~n~~n~~n~~y~~h~Лифт ~n~~y~~h~уже находится на вашем этаже!", 3500, 3);
								SendClientMessage(playerid, -1, "Лифт уже находится на данным этаже, войдите в него и нажмите'{FFCC66}~k~~CONVERSATION_YES~{FFFFFF}'");
								return 1;
							}
						}
						CallElevator(playerid, i + 1);
						GameTextForPlayer(playerid, "~n~~n~~n~~n~~n~~n~~n~~n~~g~~h~Лифт~n~~g~~h~Уже направляется к вам,~n~~w~пожалуйста, подождите...", 3000, 3);
						if (ElevatorState == ELEVATOR_STATE_MOVING)
							va_SendClientMessage(playerid,-1,"Лифт в данный момент движится в сторону {FFCC66}%s{FFFFFF}",FloorNames[ElevatorFloor]);
						else
						{
							if (ElevatorFloor == 0)
								va_SendClientMessage(playerid,-1,"Лифт в данный момент находится у {FFCC66}%s{FFFFFF}.",FloorNames[ElevatorFloor]);
							else
								va_SendClientMessage(playerid,-1,"Лифт в данный момент находится на {FFCC66}%s{FFFFFF}.",FloorNames[ElevatorFloor]);
						}
						return 1;
					}
				}
			}
		}
	}
	if(newkeys & KEY_NO){
		if(GetPVarInt(playerid, "Show_PlayerLic") == 1) {
			new licer = GetPVarInt(playerid,"Show_PlayerLic")-1;
		    va_SendClientMessage(licer, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s отказался смотреть ваш список лицензий.", IC_Name(playerid));
			va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы отказались от просмотра лицензий у %s",IC_Name(licer));
			DeletePVar(playerid, "Show_PlayerLic");
			DeletePVar(licer, "Show_PlayerLic");
		}
		if(GetPVarInt(playerid, "Show_PlayerSkill") == 1) {
			new user = GetPVarInt(playerid,"Show_PlayerSkill");
		    va_SendClientMessage(user, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s отказался смотреть вашу выписку из тира.", IC_Name(playerid));
			va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы отказались от просмотра выписки из тира у %s",IC_Name(user));
			DeletePVar(playerid, "Show_PlayerSkill");
			DeletePVar(user, "Show_PlayerSkill");
		}
		else if(GetPVarInt(playerid, "Buy_License_B") == 1) {
			new licer = GetPVarInt(playerid,"Buy_License_B")-1;
		    va_SendClientMessage(licer, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s отказался от покупки водительских прав.", IC_Name(playerid));
			SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы отказались от покупки водительских прав.");
			DeletePVar(playerid, "Buy_License_B");
			DeletePVar(licer, "Buy_License_B");
		}
		else if(GetPVarInt(playerid, "Buy_License_A") == 1) {
			new licer = GetPVarInt(playerid,"Buy_License_A")-1;
		    va_SendClientMessage(licer, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s отказался от покупки прав на вождение мотоцикла.", IC_Name(playerid));
			SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы отказались от покупки прав на вождение мотоцикла.");
			DeletePVar(playerid, "Buy_License_A");
			DeletePVar(licer, "Buy_License_A");
		}
		else if(GetPVarInt(playerid, "Buy_PetrolStation") != -1){
			new seller = GetPVarInt(playerid,"Buy_PetrolStation");
			new Float:price = GetPVarFloat(playerid,"Price_PetrolStation");
			new x = P[seller][p_business_ps];
			va_SendClientMessageF(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы отказил в покупке %s АЗС {FFCC66}%s{FFFFFF} за $%m.",IC_Name(seller),PS[x-1][ps_name],price);
			va_SendClientMessageF(seller, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s отказался покупать у вас АЗС {FFCC66}%s{FFFFFF} за $%m.",IC_Name(playerid),PS[x-1][ps_name],price);
			SetPVarInt(playerid, "Buy_PetrolStation",-1);
			DeletePVar(playerid, "Price_PetrolStation");
		}
		else if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
		{
			if(GetPVarInt(playerid, "id_repair") == 1){
				new enginer = GetPVarInt(playerid,"id_repair");
				DeletePVar(enginer,"id_repair");
				DeletePVar(enginer,"price_repair");
				DeletePVar(playerid,"id_repair");
				SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы отказались от починки вашего Т.С.");
				va_SendClientMessage(enginer, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s отказался от ваших услуг в ввиде починки авто",Name(playerid));
			}
		}
	}
	// Открытие ворот и/или шлагбаумов
	if(newkeys & KEY_CROUCH)
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
			if(IsPlayerInRangeOfPoint(playerid, 15.0, -2436.89941, 495.46875, 29.8)) {
			    if(P[playerid][p_job_team] == ORG_FBI && obj_state_FBI == false) {
			        obj_state_FBI = true;
					MoveDynamicObject(obj_FBI, -2436.89941, 495.46875, 29.8, MOVE_BARRIER_SPEED, 0.00, 0.00, 90.0);
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
			if(IsPlayerInRangeOfPoint(playerid, 7.5, -2056.885009, -93.754776, 34.157676)){
				if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_AUTOSCHOOL && obj_state_AUTOSCHOOL[0] == false){
					obj_state_AUTOSCHOOL[0] = true;
					MoveDynamicObject(obj_AUTOSCHOOL[0],-2057.275634, -94.831848+0.05, 34.890388, 0.03 ,0.000000, 0.000000, 270.000000);
					defer OnGateClosed(obj_AUTOSCHOOL[0]);
				}
			}
		}
	}
	if(newkeys & KEY_ACTION)
	{
		new vehicleid = GetPlayerVehicleID(playerid);
		if(GetVehicleModel(vehicleid) == 481){
			return 0;
		}
		else{
			new engine,lights,alarm,doors,bonnet,boot,objective;
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
		if(gSpectateType[playerid] >= 1)
			callcmd::specoff(playerid,"");
	}
	if(newkeys & KEY_WALK)
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
			if(IsPlayerInRangeOfPoint(playerid, 1.0, 1543.482788, -1631.928588, 13.461294)){
				if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_LSPD && obj_state_LSPD == false) {
		            obj_state_LSPD = true;
		            MoveDynamicObject(obj_LSPD, 1544.68994, -1630.81995, 12.90000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 90.00000);
		            defer OnGateClosed(obj_LSPD);
		        }
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.0, -1701.057495, 689.615234, 24.940631)){
				if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_SFPD && obj_state_SFPD[1] == false) {
				   obj_state_SFPD[1] = true;
				   MoveDynamicObject(obj_SFPD[1], -1701.43005, 687.63000, 24.45000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 270.00000);
				   defer OnGateClosed(obj_SFPD[1]);
			  	}
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.0, -1572.707153, 656.855529, 7.547507)){
				if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_SFPD && obj_state_SFPD[0] == false) {
		            obj_state_SFPD[0] = true;
		            MoveDynamicObject(obj_SFPD[0], -1572.19995, 658.79999, 6.65000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 90.00000);
		            defer OnGateClosed(obj_SFPD[0]);
		        }
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.0, 2237.830078, 2449.383300, 11.049514)){
				if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_LVPD && obj_state_LVPD == false) {
		            obj_state_LVPD = true;
		            MoveDynamicObject(obj_LVPD, 2238.18994, 2450.37988, 10.37000, MOVE_BARRIER_SPEED, 0.00000, 0.00000, 90.00000);
		            defer OnGateClosed(obj_LVPD);
		        }
			}
			if(IsPlayerInRangeOfPoint(playerid, 1.5, -2056.885009, -93.754776, 34.157676)){
				if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_AUTOSCHOOL && obj_state_AUTOSCHOOL[0] == false){
					obj_state_AUTOSCHOOL[0] = true;
					MoveDynamicObject(obj_AUTOSCHOOL[0],-2057.275634, -94.831848+0.05, 34.890388, 0.03 ,0.000000, 0.000000, 270.000000);
					defer OnGateClosed(obj_AUTOSCHOOL[0]);
				}
			}
		}
	}
	return 0;
}

public OnPlayerUpdate(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    if(P[playerid][_p_in_game] == false) return 0;

	if(P[playerid][p_wanted_level] == 0){		
		new string[16];
		format(string, sizeof(string), "%d Cent", P[playerid][p_cash] % 100);
		PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
		PlayerTextDrawShow(playerid, P[playerid][_p_cent]);
	}
	else if(P[playerid][p_wanted_level] > 0){
		new string[16];
		format(string, sizeof(string), "%d Cent", P[playerid][p_cash] % 100);
		PlayerTextDrawSetString(playerid, Wanted_New_Cash, string);
		PlayerTextDrawShow(playerid, Wanted_New_Cash);
	}
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
	else if(weaponid == P[playerid][p_weapon_5])
	{
		P[playerid][p_ammo_5]--;
		if(P[playerid][p_ammo_5] <= 0)
		{
		    P[playerid][p_ammo_5] = 0;
			P[playerid][p_ammo_5] = 0;
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
		if(!IsValidDynamicCP(Buy_Weapon)) return true;
		if(P[playerid][p_lic_weapon] == 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете купить оружие без лицензий.");
		new x = GetPVarInt(playerid,"Ammu_Nation");
		new string[298];
		format(string,sizeof(string),"{FFFFFF}Оружие\t{FFFFFF}Цена\t{FFFFFF}Количество патронов\n\
			Пистолет\t$%m\t30\n\
			Пистолет с глушителем\t$%m\t30\n\
			Desert Deagle\t$%m\t15\n\
			Tec-9\t$%m\t60\n\
			Micro-Uzi\t$%m\t60\n\
			Помповый дробовик\t$%m\t15\n\
			MP5\t$%m\t90\n\
			AK47\t$%m\t120\n\
			M4\t$%m\t150",AN[x][an_price_colt45],AN[x][an_price_silenced],AN[x][an_price_deagle],AN[x][an_price_shotgun],AN[x][an_price_tec9],
						  AN[x][an_price_micro_uzi],AN[x][an_price_mp5],AN[x][an_price_ak47],AN[x][an_price_m4]);
		ShowPlayerDialog(playerid, d_player_buy_gun, DIALOG_STYLE_TABLIST_HEADERS, "Покупка оружия",string,"Выбор","Выйти");
		P[playerid][_p_dialog] = true;
	}
	if(checkpointid == Gang_Storage[0] || checkpointid == Gang_Storage[1] || checkpointid == Gang_Storage[2] || checkpointid == Gang_Storage[3] || checkpointid == Gang_Storage[4] || checkpointid == Mafia_Storage[0] || checkpointid == Mafia_Storage[1] || checkpointid == Mafia_Storage[2])
	{
		if((checkpointid == Gang_Storage[0] && P[playerid][p_job_team] != 10) || 
		   (checkpointid == Gang_Storage[1] && P[playerid][p_job_team] != 11) || 
		   (checkpointid == Gang_Storage[2] && P[playerid][p_job_team] != 12) || 
		   (checkpointid == Gang_Storage[3] && P[playerid][p_job_team] != 13) || 
		   (checkpointid == Gang_Storage[4] && P[playerid][p_job_team] != 14) ||
		   (checkpointid == Mafia_Storage[0] && P[playerid][p_job_team] != 15) || 
		   (checkpointid == Mafia_Storage[1] && P[playerid][p_job_team] != 16) || 
		   (checkpointid == Mafia_Storage[2] && P[playerid][p_job_team] != 17)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У вас нет доступа к этому складу.");
		   
		new x = P[playerid][p_job_team]-10;
		new text[159+31+1],
			name[8+22+1];
		format(name,sizeof(name),"{FFCC66}%s",Get_GangName(P[playerid][p_job_team]));
		format(text,sizeof(text),
			"Взять деньги {FF8888}($%m)\n\
			Взять патроны {FF8888}(%d)\n\
			Взять материалы {FF8888}(%d)\n\
			Положить деньги\n\
			Положить патроны\n\
			Положить материалы",
				GS[x][g_cash],GS[x][g_ammo],GS[x][g_materials]);
		if(P[playerid][p_job_team] >= 10 && P[playerid][p_job_team] <= 14){
			new zones[31];
			format(zones,sizeof(zones),"\n \nТерриторий захваченно: %i",Captured_Zones[x+1]);
			strcat(text, zones);
		}
		ShowPlayerDialog(playerid, d_gang_storage, DIALOG_STYLE_LIST, name, text, "Выбрать", "Закрыть");
		P[playerid][_p_dialog] = true;
	}
	if(checkpointid == p_gps){
		SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы прибыли на точку назначения.");
		if(IsValidDynamicCP(p_gps)) DestroyDynamicCP(p_gps);
	}
	if(checkpointid == Freighter_Job){
		new vehicleid = GetPlayerVehicleID(playerid);
		if(IsTrailerAttachedToVehicle(vehicleid) == 0) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Что бы купить топливо к вашей машине должен быть прикреплена цистерна.");
		ShowPlayerDialog(playerid, d_job_add_fuell_trailer, DIALOG_STYLE_INPUT, "Купить топливо","{FFFFFF}Введите количество топлива которое хотите купить\n  -За 1 литр 5.45$","Ок","Назад");
		P[playerid][_p_dialog] = true;
	}
	return true;
}
public OnPlayerPickUpDynamicPickup(playerid, pickupid)
{
	if(PickupGetTime[playerid] > gettime()) return true;
	PickupGetTime[playerid] = gettime() + 2;
	if(pickupid == Ammu_Nation[0])
	{
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,1);
		SetPlayerPos(playerid,286.9145,-38.6596,1001.5156);
		SetPlayerFacingAngle(playerid, 329.0564);
		SetPlayerVirtualWorld(playerid, 1);
		SetPVarInt(playerid, "Ammu_Nation",0); // 0 = Ammu-Nation ID in Datebase
		
		Buy_Weapon = CreateDynamicCP(296.9160,-38.5113,1001.5156,1.0,1,1);
	}
	else if(pickupid == Ammu_Nation[1])
	{
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,1366.5776,-1279.5397,13.5469);
		SetPlayerFacingAngle(playerid, 89.7301);
		SetPlayerVirtualWorld(playerid,0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[2])
	{
	    SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 2);
		SetPVarInt(playerid, "Ammu_Nation",1);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0,2,6);
 	}
 	else if(pickupid == Ammu_Nation[3])
	{
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,2400.5554,-1980.2947,13.5469);
		SetPlayerFacingAngle(playerid, 5.1592);
		SetPlayerVirtualWorld(playerid,0);
		DeletePVar(playerid, "Ammu_Nation");

		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[4])
	{
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,4);
		SetPlayerPos(playerid,286.8773,-83.5809,1001.5156);
		SetPlayerFacingAngle(playerid, 334.2157);
		SetPlayerVirtualWorld(playerid, 3);
		SetPVarInt(playerid, "Ammu_Nation",2);
		
		Buy_Weapon = CreateDynamicCP(293.5498,-80.8238,1001.5156,1.0,3,4);
	}
	else if(pickupid == Ammu_Nation[5])
	{
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,-2626.6384,210.3960,4.5971);
		SetPlayerFacingAngle(playerid, 13.1113);
		SetPlayerVirtualWorld(playerid,0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	// 3 ammu
	else if(pickupid == Ammu_Nation[6]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,316.524993,-167.706985,999.593750);
		SetPlayerFacingAngle(playerid,0);
		SetPlayerVirtualWorld(playerid, 4);
		SetPVarInt(playerid, "Ammu_Nation",3);
		
		Buy_Weapon = CreateDynamicCP(312.7118,-166.1295,999.6010,1.0,4,6);
	}
	else if(pickupid == Ammu_Nation[7]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, 2537.5703,2083.9082,10.8203);
		SetPlayerFacingAngle(playerid, 87.8557);
		SetPlayerVirtualWorld(playerid, 0);
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[8])
	{
	    SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,7);
		SetPlayerPos(playerid,313.7110,-140.3784,999.6016);
		SetPlayerFacingAngle(playerid, 334.2157);
		SetPlayerVirtualWorld(playerid, 5);
		SetPVarInt(playerid, "Ammu_Nation",4);
		
		Buy_Weapon = CreateDynamicCP(308.1070,-141.4640,999.6016,1.0,5,7);
 	}
	else if(pickupid == Ammu_Nation[9])
	{
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,2156.1997,943.3864,10.8203);
		SetPlayerFacingAngle(playerid, 81.7582);
		SetPlayerVirtualWorld(playerid,0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[10]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 6);
		SetPVarInt(playerid, "Ammu_Nation",5);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0,6,6);
	}
	else if(pickupid == Ammu_Nation[11]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, 241.3318,-178.5530,1.5781);
		SetPlayerFacingAngle(playerid, 87.2704);
		SetPlayerVirtualWorld(playerid, 0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[12]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 7);
		SetPVarInt(playerid, "Ammu_Nation",6);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0,7,6);
	}
	else if(pickupid == Ammu_Nation[13]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, 2335.9712,61.5492,26.4819);
		SetPlayerFacingAngle(playerid, 273.6243);
		SetPlayerVirtualWorld(playerid, 0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[14]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 8);
		SetPVarInt(playerid, "Ammu_Nation",7);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0,8,6);
	}
	else if(pickupid == Ammu_Nation[15]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, -2091.9421,-2462.7903,30.6250);
		SetPlayerFacingAngle(playerid, 324.5531);
		SetPlayerVirtualWorld(playerid, 0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[16]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 9);
		SetPVarInt(playerid, "Ammu_Nation",8);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0,9,6);
	}
	else if(pickupid == Ammu_Nation[17]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, -1508.8813,2608.4429,55.8359);
		SetPlayerFacingAngle(playerid, 179.6469);
		SetPlayerVirtualWorld(playerid, 0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation[18]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 10);
		SetPVarInt(playerid, "Ammu_Nation",9);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0,10,6);
	}
	else if(pickupid == Ammu_Nation[19]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, -313.7351,830.0300,14.2422);
		SetPlayerFacingAngle(playerid, 280.8498);
		SetPlayerVirtualWorld(playerid, 0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	//
	else if(pickupid == Ammu_Nation[20]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid,6);
		SetPlayerPos(playerid,297.1230,-110.0104,1001.5156);
		SetPlayerFacingAngle(playerid, 1.2438);
		SetPlayerVirtualWorld(playerid, 11);
		SetPVarInt(playerid, "Ammu_Nation",10);

		Buy_Weapon = CreateDynamicCP(287.8425,-105.9843,1001.5156,1.0,11,6);
	}
	else if(pickupid == Ammu_Nation[21]){
		SetCameraBehindPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, 778.7020,1871.3378,4.9062);
		SetPlayerFacingAngle(playerid, 266.9396);
		SetPlayerVirtualWorld(playerid, 0);
		DeletePVar(playerid, "Ammu_Nation");
		
		DestroyDynamicCP(playerid);
	}
	else if(pickupid == Ammu_Nation_Range[0]){
		SetCameraBehindPlayer(playerid);
		SetPlayerPos(playerid,286.2136,-27.8047,1001.5156);
		SetPlayerFacingAngle(playerid, 2.5021);
	}
	else if(pickupid == Ammu_Nation_Range[1]){
		SetCameraBehindPlayer(playerid);
		SetPlayerPos(playerid,286.1425,-31.2853,1001.5156);
		SetPlayerFacingAngle(playerid, 177.9238);
	}
	else if(pickupid == Ammu_Nation_Range[2]){
		SetCameraBehindPlayer(playerid);
		SetPlayerPos(playerid,303.0007,-141.9237,1004.0625);
		SetPlayerFacingAngle(playerid, 90.2811);
	}
	else if(pickupid == Ammu_Nation_Range[3]){
		SetCameraBehindPlayer(playerid);
		SetPlayerPos(playerid,307.5168,-141.9299,1004.0625);
		SetPlayerFacingAngle(playerid, 270.1295);
	}
	else if(pickupid == Ammu_Nation_Range[4]){
		SetCameraBehindPlayer(playerid);
		SetPlayerPos(playerid,301.6869,-74.0318,1001.5156);
		SetPlayerFacingAngle(playerid, 2.4303);
	}
	else if(pickupid == Ammu_Nation_Range[5]){
		SetCameraBehindPlayer(playerid);
		SetPlayerPos(playerid,301.4428,-78.5331,1001.5156);
		SetPlayerFacingAngle(playerid, 180.6889);	
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
		SetPlayerVirtualWorld(playerid, 1);
		SetPlayerInterior(playerid, 6);
		SetPlayerPos(playerid,246.2850,64.8440,1003.6406);
		SetPlayerFacingAngle(playerid, 359.2673);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == LSPD[1]){
		SetPlayerInterior(playerid,0);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid,1552.6376,-1675.5725,16.1953);
		SetPlayerFacingAngle(playerid, 92.8291);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == CityHall[0]){
		SetPlayerInterior(playerid, 3);
		SetPlayerPos(playerid,384.808624,173.804992,1008.382812);
	}
	else if(pickupid == FBI[0]){
		SetPlayerInterior(playerid,3);
		SetPlayerPos(playerid,238.5226,140.8495,1003.0234);
		SetPlayerFacingAngle(playerid, 357.8347);
	}
	else if(pickupid == FBI[1]){
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,-2453.6399,503.9580,30.0800);
		SetPlayerFacingAngle(playerid, 266.5858);
	}
	else if(pickupid == FBI[2]){
		SetPlayerInterior(playerid,3);
		SetPlayerPos(playerid,288.5756,169.5392,1007.1719);
		SetPlayerFacingAngle(playerid, 3.8765);
	}
	else if(pickupid == FBI[3]){
		SetPlayerInterior(playerid,0);
		SetPlayerPos(playerid,-2483.6584,514.0369,51.0638);
		SetPlayerFacingAngle(playerid, 270.0022);
	}
	else if(pickupid == AutoSchool[0]){
		SetPlayerInterior(playerid, 3);
		SetPlayerPos(playerid, -2027.1796,-104.8761,1035.1719);
		SetPlayerFacingAngle(playerid, 180.2123);
		SetPlayerVirtualWorld(playerid, 1);
	}
	else if(pickupid == AutoSchool[1]){
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, -2026.5153,-100.1560,35.1641);
		SetPlayerFacingAngle(playerid, 0.7751);
		SetPlayerVirtualWorld(playerid, 0);
	}
	else if(pickupid == AutoSchool[2]){
		SetPlayerInterior(playerid, 3);
		SetPlayerPos(playerid, -2029.6047,-118.0004,1035.1719);
		SetPlayerFacingAngle(playerid, 0.2220);
		SetPlayerVirtualWorld(playerid, 1);
	}
	else if(pickupid == AutoSchool[3]){
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, -2029.7190,-122.5634,35.1931);
		SetPlayerFacingAngle(playerid, 174.4220);
		SetPlayerVirtualWorld(playerid, 0);
	}
	else if(pickupid == AutoSchool_Exam[0]){
		if(P[playerid][p_lic_car] == 1) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас уже есть водительские права.");
		new lawstring[256];
		format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[0],Traffic_Laws_ExamAnswers[0][0],Traffic_Laws_ExamAnswers[0][1],Traffic_Laws_ExamAnswers[0][2],Traffic_Laws_ExamAnswers[0][3]);
		ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Открыть");
		P[playerid][_p_dialog] = true;
	}
	else if(pickupid == AutoSchool_Exam[1]){
		ShowPlayerDialog(playerid, d_null,DIALOG_STYLE_MSGBOX,"Информация",
			"{5A5FED}•{FFFFFF} Для информирования водителей о предстоящей смене зеленого сигнала светофора на желтый,\n\
			\tпредусмотрена возможность мигания зеленого сигнала.\n\
			\tЭтот сигнал разрешает движение транспортных средств. Его длительность должна составлять 3 секунды.\n\
			{5A5FED}•{FFFFFF} Неработающий стеклоподъемник не может быть причиной запрещения эксплуатации транспортного средства.\n\
			{5A5FED}•{FFFFFF} Буксировка на гибкой сцепке запрещена только в гололедицу из-за высокой вероятности заноса при торможении или трогании.\n\
			{5A5FED}•{FFFFFF} Подача сигнала указателями поворота должна производиться заблаговременно до начала выполнения маневра и прекращаться немедленно после его завершения.\n\
			\tПри этом сигнал не должен вводить в заблуждение других участников движения.\n\
			{5A5FED}•{FFFFFF} Разметка в виде надписи {B22222}\"СТОП\"{FFFFFF} на проезжей части предупреждает о приближении к линии поперечной разметки (стоп-линия),\n\
			\tуказывающей место,где Вы должны остановиться, выполняя требование знака {B22222}\"Движение без остановки запрещено\"{FFFFFF}. Без знакa данная разметка не применяется.\n\
			{5A5FED}•{FFFFFF} В населенных пунктах звуковой сигнал разрешается применять только для предотвращения дорожно-транспортного происшествия.\n\
			\tПри этом важно подать его своевременно, а не в последний момент, и он не должен быть излишне продолжительным.\n\
			{5A5FED}•{FFFFFF} Произвести остановку на автомагистрали можно только на специальных площадках для стоянки, обозначенных соответствующими знаками.\n\
			{5A5FED}•{FFFFFF} Водители мопедов должны двигаться по полосе для велосипедистов, выделенной знаками или разметкой,\n\
			\tа в случае ее отсутствия - в один ряд по правому краю проезжей части или обочине, не создавая помех пешеходам.\n\
			{5A5FED}•{FFFFFF} Обгон запрещён на равнозначных перекрёстках. Допускается производить обгон на неравнозначных перекрёстках при движении по главной дороге.\n\
			{5A5FED}•{FFFFFF} Дорога включает в себя не только проезжие части, но также тротуары и обочины.\n\
			{5A5FED}•{FFFFFF} В полотном потоке ТС движение со скоростью, большей или меньшей скорости потока,\n\
			\tопасно и может способствовать возникновению аварийной ситуации. Скорость потока, как правило, не совпадает с предельно допустимой для Вас скоростью,\n\
			\tи поэтому при движении в потоке именно интенсивность движения имеет решающее значение при выборе скорости.\n\
			{5A5FED}•{FFFFFF} Перевозить людей в буксируемом легковом автомобиле разрешено только при буксировке на гибкой или жесткой сцепке.\n\
			{5A5FED}•{FFFFFF} Движение ТС задним ходом запрещено на перекрестках, пешеходных переходах, в местах остановок маршрутных ТС.\n\
			\tНа дорогах с односторонним движением двигаться задним ходом разрешается.\n\
			{5A5FED}•{FFFFFF} Конец подъёма - это место перелома продольного профиля дороги. При подъезде к этому месту видимость отсутствует.\n\
			\tПоэтому, Правилами обгон в конце подъёма, на опасных поворотах и на других участках с ограниченной видимостью запрещён.\n\
			\tНе забываем главное условие обгона - {B22222}\"Путь, необходимый для обгона, никогда не должен превышать половины видимого отрезка пути\"{FFFFFF}.\n\
			{5A5FED}•{FFFFFF} При вознекновении ДТП в первую очередь нужно оставаться на месте и вызвать сотрудников ПО.\n\
			{5A5FED}•{FFFFFF} В жилых зонах и приравненных к ним дворовых территориях пешеходам движение разрешено как по тротуарам, так и по всей ширине проезжей части дорог\n\
			{5A5FED}•{FFFFFF} Чем ниже и симметричнее расположен центр тяжести автомобиля, тем более он устойчив.\n\
			\tПорожний автомобиль без пассажиров и груза всегда более устойчив против опрокидывания, чем при их наличии.","Закрыть","");
	}
	else if(pickupid == Grove[0]){
		SetPlayerPos(playerid, 2466.4688,-1698.4783,1013.5078);
		SetPlayerFacingAngle(playerid, 86.2566);
		SetPlayerVirtualWorld(playerid, 2);
		SetPlayerInterior(playerid, 2);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Grove[1]){
		SetPlayerPos(playerid, 2512.6711,-1689.3822,13.5508);
		SetPlayerFacingAngle(playerid, 43.5251);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Ballas[0]){
		SetPlayerPos(playerid, -42.6860,1408.4878,1084.4297);
		SetPlayerFacingAngle(playerid, 0);
		SetPlayerVirtualWorld(playerid, 2);
		SetPlayerInterior(playerid, 8);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Ballas[1]){
		SetPlayerPos(playerid, 2022.9169,-1122.8164,26.2401);
		SetPlayerFacingAngle(playerid, 179.8987);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Aztecas[0]){
		SetPlayerPos(playerid, 222.9479,1240.1484,1082.1406);
		SetPlayerFacingAngle(playerid, 84.5630);
		SetPlayerVirtualWorld(playerid, 2);
		SetPlayerInterior(playerid, 2);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Aztecas[1]){
		SetPlayerPos(playerid, 2185.6555,-1812.5112,13.5650);
	    SetPlayerFacingAngle(playerid, 0);
	    SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Vagos[0]){
		SetPlayerPos(playerid, 318.564971,1118.209960,1083.882812);
		SetPlayerFacingAngle(playerid, 0);
		SetPlayerVirtualWorld(playerid, 2);
		SetPlayerInterior(playerid, 5);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Vagos[1]){
		SetPlayerPos(playerid, 2756.1492,-1180.2386,69.3978);
		SetPlayerFacingAngle(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Rifa[0]){
		SetPlayerPos(playerid, -68.9146,1353.8420,1080.2109);
		SetPlayerFacingAngle(playerid, 0);
		SetPlayerVirtualWorld(playerid, 2);
		SetPlayerInterior(playerid, 6);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Rifa[1]){
		SetPlayerPos(playerid, 2784.4846,-1926.1527,13.5469);
		SetPlayerFacingAngle(playerid, 87.2075);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Chinese[0]){
		SetPlayerPos(playerid, 1299.0084,-794.9550,1084.0078);
		SetPlayerFacingAngle(playerid, 359.8387);
		SetPlayerVirtualWorld(playerid, 1);
		SetPlayerInterior(playerid,5);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Chinese[1]){
		SetPlayerPos(playerid, 2597.6270,1898.6757,11.0312);
		SetPlayerFacingAngle(playerid, 178.7144);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid,0);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Russian[0])
	{
		SetPlayerPos(playerid, 1299.6984,-792.1796,1084.0078);
		SetPlayerFacingAngle(playerid, 348.2180);
		SetPlayerVirtualWorld(playerid, 2);
		SetPlayerInterior(playerid, 5);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Russian[1])
	{
		SetPlayerPos(playerid, 941.6406,1733.1003,8.8516);
		SetPlayerFacingAngle(playerid, 271.6147);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Italian[0])
	{
		SetPlayerPos(playerid, 1299.6984,-792.1796,1084.0078);
		SetPlayerFacingAngle(playerid, 348.2180);
		SetPlayerVirtualWorld(playerid, 3);
		SetPlayerInterior(playerid, 5);
		SetCameraBehindPlayer(playerid);
	}
	else if(pickupid == Italian[1])
	{
		SetPlayerPos(playerid, 1462.3103,2773.2043,10.8203);
		SetPlayerFacingAngle(playerid, 267.9370);
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
    return true;
}
public OnPlayerEnterDynamicRaceCP(playerid, checkpointid){
	new vehicleid = GetPlayerVehicleID(playerid);
	if(checkpointid == Bus_Route_CheckPoint && GetVehicleModel(vehicleid) == 431){
		new x = GetPVarInt(playerid, "Bus_Route_CP"),
			y = GetPVarInt(playerid, "Bus_Route_To_Go"),
			cash = GetPVarInt(playerid, "Bus_Route_Cash");

		SetPVarInt(playerid, "Bus_Route_Cash",cash+728);
			
		if(x == 93)
			SetPVarInt(playerid, "Bus_Route_CP", 2);
		else
			SetPVarInt(playerid,"Bus_Route_CP", x+1);			
		x = GetPVarInt(playerid, "Bus_Route_CP");
	
		TogglePlayerDynamicRaceCP(playerid, Bus_Route_CheckPoint,0);
		Bus_Route_CheckPoint = CreateDynamicRaceCP(0,Bus_Route[y][x][0],Bus_Route[y][x][1],Bus_Route[y][x][2],Bus_Route[y][x+1][0],Bus_Route[y][x+1][1],Bus_Route[y][x+1][2],4,0,0,playerid);
		TogglePlayerDynamicRaceCP(playerid, Bus_Route_CheckPoint,1);
		
		Streamer_Update(playerid, 3);
	}
	return true;
}
public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	new s_current = P[playerid][_p_skin_shop];
    if(playertextid == ChoseSkin[5])
    {
		switch(P[playerid][p_sex]) {
			case SEX_MALE: {
		 		s_current--;
				if(s_current == -1) s_current = 9;
				SetPlayerSkin(playerid,male_skins[s_current]);
			}
			case SEX_FEMALE: {
				s_current--;
				if(s_current == -1) s_current = 4;
				SetPlayerSkin(playerid,female_skins[s_current]);
			}
		}
		P[playerid][_p_skin_shop] = s_current;
    }
	else if(playertextid == ChoseSkin[7]){

		switch(P[playerid][p_sex]) {
			case SEX_MALE:
			{
				s_current++;
				if(s_current == 10) s_current = 0;
 				SetPlayerSkin(playerid,male_skins[s_current]);
			}
			case SEX_FEMALE:
			{
				s_current++;
				if(s_current == 5) s_current = 0;
				SetPlayerSkin(playerid,female_skins[s_current]);
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
						P[playerid][p_skin] = male_skins[s_current];
						SetPlayerSkin(playerid,P[playerid][p_skin]);
					}
					case SEX_FEMALE:
					{
						P[playerid][p_skin] = female_skins[s_current];
						SetPlayerSkin(playerid,P[playerid][p_skin]);
					}
				}
				P[playerid][p_cash] = g_Payment_Register;
				P[playerid][p_level] = 1;
				P[playerid][p_exp] = 1;
				P[playerid][p_mute] = -1;
				P[playerid][p_business_ps] = -1;
				P[playerid][p_health] = 100;
				SetPlayerScore(playerid,P[playerid][p_level]);
				GetPlayerIp(playerid, P[playerid][p_reg_ip], 46);
				orm_insert(P[playerid][_p_ormid], "OnMySQL_InsertAccount", "d", playerid);
				for(new i; i < 8; i++){
					PlayerTextDrawHide(playerid, ChoseSkin[i]);
					CancelSelectTextDraw(playerid);
				}
			}
		}
	}
    return 1;
}
public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	new x = 0;
	while(x!=MAX_PLAYERS) {
	    if( IsPlayerConnected(x) &&	GetPlayerState(x) == PLAYER_STATE_SPECTATING && gSpectateID[x] == playerid && gSpectateType[x] == ADMIN_SPEC_TYPE_PLAYER)
   		{
   		    SetPlayerInterior(x,newinteriorid);
		}
		x++;
	}
}
public OnPlayerClickTextDraw(playerid, Text:clickedid) 
{ 
	for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) { 
        if (TextRusTD[RussifierType:i] == _:clickedid) { 
			SendClientMessage(playerid, -1,"Вы успешно сменили русификатор.");
            SetPlayerRussifierType(playerid, RussifierType:i); 
			P[playerid][p_russifier_type] = i;
            CancelSelectTextDraw(playerid); 
        } 
        TextDrawHideForPlayer(playerid, Text:TextRusTD[RussifierType:i]); 
    } 
	return false;
}
public OnPlayerEnterDynamicArea(playerid, areaid){
	if(areaid == auto_school_press_alt[0] || areaid == auto_school_press_alt[1] || areaid == auto_school_press_alt[2] || areaid == auto_school_press_alt[3] || areaid == auto_school_press_alt[4]){
		if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_AUTOSCHOOL){
			for(new i; i < 5; i++)
		   		PlayerTextDrawShow(playerid, Press_ALT[i]);
		}
	}
	if(areaid == police_press_alt[0] || areaid == police_press_alt[1] || areaid == police_press_alt[2] || areaid == police_press_alt[3]){
		if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_LSPD || P[playerid][p_job_team] == ORG_SFPD || P[playerid][p_job_team] == ORG_LVPD){
			for(new i; i < 5; i++)
		   		PlayerTextDrawShow(playerid, Press_ALT[i]);
		}
	}
	return true;
}
public OnPlayerLeaveDynamicArea(playerid, areaid){
	if(areaid == auto_school_press_alt[0] || areaid == auto_school_press_alt[1] || areaid == auto_school_press_alt[2] || areaid == auto_school_press_alt[3] || areaid == auto_school_press_alt[4]){
		if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_AUTOSCHOOL){
		for(new i; i < 5; i++)
			PlayerTextDrawHide(playerid, Press_ALT[i]);
		}
	}
	if(areaid == police_press_alt[0] || areaid == police_press_alt[1] || areaid == police_press_alt[2] || areaid == police_press_alt[3]){
		if(P[playerid][p_job_team] == ORG_FBI || P[playerid][p_job_team] == ORG_LSPD || P[playerid][p_job_team] == ORG_SFPD || P[playerid][p_job_team] == ORG_LVPD){
			for(new i; i < 5; i++)
		   		PlayerTextDrawHide(playerid, Press_ALT[i]);
		}
	}
	return true;
}
public OnPlayerShootDynamicObject(playerid, weaponid, objectid, Float:x, Float:y, Float:z)
{
	for(new i;i<sizeof(target_lv_1);i++){
	    if(objectid == target_lv_1[i]){
			DestroyDynamicObject(target_lv_1[i]); 
			PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);
			target_count_lv++;
			target_shot[playerid]++;
			foreach(new p : Player){
				if(IsPlayerInRangeOfPoint(p, 30.0, 288.00000, -130.85989, 1007.165412) && GetPlayerInterior(p) == 7)
					Streamer_Update(p,-1);
			}
		}
	}
	for(new i;i<sizeof(target_lv_2);i++){
	    if(objectid == target_lv_2[i]){
			DestroyDynamicObject(target_lv_2[i]); 
			PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);
			target_count_lv++;
			target_shot[playerid]++;
			foreach(new p : Player){
				if(IsPlayerInRangeOfPoint(p, 30.0, 288.00000, -130.85989, 1007.165412) && GetPlayerInterior(p) == 7)
					Streamer_Update(p,-1);
			}
		}
	}
	for(new i;i<sizeof(target_lv_3);i++){
	    if(objectid == target_lv_3[i]){
			DestroyDynamicObject(target_lv_3[i]); 
			PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);
			target_count_lv++;
			target_shot[playerid]++;
			foreach(new p : Player){
				if(IsPlayerInRangeOfPoint(p, 30.0, 288.00000, -130.85989, 1007.165412) && GetPlayerInterior(p) == 7)
					Streamer_Update(p,-1);
			}
		}
	}
	for(new i;i<sizeof(target_ls_1);i++){
	    if(objectid == target_ls_1[i]){
			DestroyDynamicObject(target_ls_1[i]); 
			PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);
			target_count_ls++;
			target_shot[playerid]++;
			foreach(new p : Player){
				if(IsPlayerInRangeOfPoint(p, 30.0, 292.35,-24.62,1001.52) && GetPlayerInterior(p) == 1)
					Streamer_Update(p,-1);
			}
		}
	}
	for(new i;i<sizeof(target_ls_2);i++){
	    if(objectid == target_ls_2[i]){
			DestroyDynamicObject(target_ls_2[i]); 
			PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);
			target_count_ls++;
			target_shot[playerid]++;
			foreach(new p : Player){
				if(IsPlayerInRangeOfPoint(p, 30.0, 292.35,-24.62,1001.52) && GetPlayerInterior(p) == 1)
					Streamer_Update(p,-1);
			}
		}
	}
	for(new i;i<sizeof(target_ls_3);i++){
	    if(objectid == target_ls_3[i]){
			DestroyDynamicObject(target_ls_3[i]); 
			PlayerPlaySound(playerid, 17802, 0.0, 0.0, 0.0);
			target_count_ls++;
			target_shot[playerid]++;
			foreach(new p : Player){
				if(IsPlayerInRangeOfPoint(p, 30.0, 292.35,-24.62,1001.52) && GetPlayerInterior(p) == 1)
					Streamer_Update(p,-1);
			}
		}
	}
	if(target_shot[playerid] == 10){
		target_shot[playerid] = 0;
		Update_Skill(playerid, weaponid);
	}
	if(target_count_lv == 21){
		Update_Target(1);
		target_count_lv = 0;
		foreach(new p : Player){
			if(IsPlayerInRangeOfPoint(p, 30.0, 288.00000, -130.85989, 1007.165412) && GetPlayerInterior(p) == 7)
				Streamer_Update(p,-1);
		}
	}  
	if(target_count_ls == 21){
		Update_Target(2);
		target_count_ls = 0;
		foreach(new p : Player){
			if(IsPlayerInRangeOfPoint(p, 30.0, 292.35,-24.62,1001.52) && GetPlayerInterior(p) == 1)
				Streamer_Update(p,-1);
		}
	}
    return 1;
}
stock Show_PlayerStats(playerid,targetid){
	new string[292];

	new sex[7+1];
	sex = (P[playerid][p_sex] == 0) ? "Женский" : "Мужской";

	new name[30+1];
	new x = P[playerid][p_business_ps];

	if(P[playerid][p_business_ps] == -1){
		format(name,sizeof(name),"Не имеется.");
	}else{
		format(name,sizeof(name),"%s",PS[x][ps_name]);
	}

	format(string,sizeof(string),"{FFFFFF}Имя:\t\t\t\t\t\t{0099FF}%s{FFFFFF}\n\
	Уровень:\t\t\t\t\t%d\n\
	Очки опыта:\t\t\t\t\t%d из %d\n\
	Работа/Организация:\t\t\t\t%s\n\
	Должность:\t\t\t\t\t%s\n\
	Пол:\t\t\t\t\t\t%s\n\
	Денег:\t\t\t\t\t\t$%m\n\
	Патронов:\t\t\t\t\t%d\n\
	Материалов:\t\t\t\t\t%d\n\n\
	АЗС:\t\t\t\t\t\t%s",
		Name(playerid),P[playerid][p_level],P[playerid][p_exp],P[playerid][p_level]*6,Get_TeamName(playerid),Get_RangName(playerid),sex,P[playerid][p_cash],P[playerid][p_patrons],P[playerid][p_materials],name);
	ShowPlayerDialog(targetid,d_null,DIALOG_STYLE_MSGBOX,"Статистика",string,"Выход","");
	P[playerid][_p_dialog] = true;
}
stock Show_PlayerLic(playerid,targetid){
	new output[482+1],lic_car[26],lic_aircraft[26],lic_boat[26],lic_moto[26],lic_weapon[26],lic_freight[26],lic_helicopter[26];
	lic_car = (P[playerid][p_lic_car] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
	lic_aircraft = (P[playerid][p_lic_aircraft] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
	lic_boat = (P[playerid][p_lic_boat] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
	lic_moto = (P[playerid][p_lic_moto] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
	lic_weapon = (P[playerid][p_lic_weapon] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
	lic_freight = (P[playerid][p_lic_freight] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
	lic_helicopter = (P[playerid][p_lic_helicopter] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
	format(output, sizeof(output),
		"{FFFFFF}Водительские права:\t\t\t\t\t%s\n\
		Лицензия пилотирования самолётом:\t\t%s\n\
		Лицензия на водный транспорт:\t\t\t%s\n\
		Лицензия на вождения спорт байка:\t\t%s\n\
		Лицензия на оружие:\t\t\t\t\t%s\n\
		Лицензия на грузо-перевозку:\t\t\t%s\n\
		Лицензия на пилотирования вертолётом:\t\t%s",
		lic_car,lic_aircraft,lic_boat,lic_moto,lic_weapon,lic_freight,lic_helicopter);
	ShowPlayerDialog(targetid, d_null, DIALOG_STYLE_MSGBOX, "Лицензии", output, "Ок","");
	P[playerid][_p_dialog] = true;
}
stock Show_PlayerSkill(playerid, targetid){
	new skillname[32],amount;
	new string[186],skill_list[32];
	for (new skill = 0; skill < MAX_WEAPON_SKILLS; skill++) {
		if(skill == 4 || skill == 5) continue;
		amount = GetPlayerSkillLevel(playerid, skill);
		GetWeaponSkillName(skill, skillname);
		format(skill_list,sizeof(skill_list),"{FFFFFF}%s - %d%%\n",skillname, amount/10);
		strcat(string,skill_list);
	}
	ShowPlayerDialog(targetid, d_null, DIALOG_STYLE_MSGBOX,"Владение оружием",string,"Закрыть","");
}
