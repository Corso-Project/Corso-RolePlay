stock Get_AccessName(playerid)
{
	new dests[17];
	switch(P[playerid][p_access])
	{
	    case 0: dests = "���������";
		case 1: dests = "Helper";
	    case 2: dests = "���������";
	    case 3: dests = "��������������";
	    case 4: dests = "�������������";
	    case 5: dests = "��.�������������";
		case 6: dests = "����������";
	}
	return dests;
}

stock Get_TeamName(playerid)
{
	new dests[32];
	switch(P[playerid][p_job_team]){
		case ORG_UNKNOWN: dests = "���������";
		case ORG_GOVERNMENT: dests = "������������� �����";
		case ORG_FBI: dests = "����������� ���� �������������";
		case ORG_LSPD: dests = "������� ��� ������";
		case ORG_SFPD: dests = "������� ��� ������";
		case ORG_LVPD: dests = "������� ��� ��������";
		case ORG_MILITARY: dests = "������������ �������";
		case ORG_EMERGENCY: dests = "������ ���������� ������";
		case ORG_SANNEWS: dests = "������� ��� �������";
		case ORG_AUTOSCHOOL: dests = "����� ����������";
		case ORG_GROVE: dests = "����� Grove Street";
		case ORG_BALLAS: dests = "����� Ballas";
		case ORG_AZTECAS: dests = "����� Aztecas";
		case ORG_VAGOS: dests = "����� Vagos";
		case ORG_RIFA: dests = "����� Rifa";
		case ORG_CHINESE: dests = "����� '������'";
		case ORG_RUSSIAN: dests = "����� '���� � ������'";
		case ORG_ITALIAN: dests = "����� '�� ���� ������'";
		case JOB_TAXI: dests = "�������";
		case JOB_BUS: dests = "����������";
		case JOB_ENGINEER: dests = "�������";
		case JOB_FREIGHTER: dests = "���������������";
	}
	return dests;
}
stock Get_RangName(playerid)
{
	new dests[41+1];
	switch(P[playerid][p_job_team]){
		case ORG_UNKNOWN, JOB_TAXI, JOB_ENGINEER, JOB_FREIGHTER,JOB_BUS : dests = "-";
		case ORG_GOVERNMENT:{
			switch(P[playerid][p_rang]){
				case 1: dests = "��������";
				case 2: dests = "��������";
				case 3: dests = "���. ������";
				case 4: dests = "�����-���������";
				case 5: dests = "�������� �� ������";
				case 6: dests = "�������� �� ������";
				case 7: dests = "�������� �� ������� ���������� ���";
				case 8: dests = "��������� ������� ���������������";
				case 9: dests = "�������� �� ��������� �������� ����������";
				case 10: dests = "����-���������";
				case 11: dests = "���������";

			}
		}
		case ORG_FBI:{
			switch(P[playerid][p_rang]){
				case 1: dests = "������";
				case 2: dests = "������� �����";
				case 3: dests = "����� ������ ���";
				case 4: dests = "����� ������ ���";
				case 5: dests = "������� �����";
				case 6: dests = "����� ������ ���";
				case 7: dests = "����� ������ ���";
				case 8: dests = "��������� ���";
				case 9: dests = "����������� ��������� ���";
				case 10: dests = "�������� ���";
			}
		}
		case ORG_LSPD, ORG_SFPD, ORG_LVPD:{
			switch(P[playerid][p_rang]){
				case 1: dests = "�����";
				case 2: dests = "����������";
				case 3: dests = "������";
				case 4: dests = "��������";
				case 5: dests = "�������";
				case 6: dests = "���������";
				case 7: dests = "�������";
				case 8: dests = "���������";
				case 9: dests = "��������";
				case 10: dests = "�������";
			}
		}
		case ORG_EMERGENCY:{
			switch(P[playerid][p_rang]){
				case 1: dests = "������";
				case 2: dests = "������� �����������";
				case 3: dests = "������� �����������";
				case 4: dests = "����-����������";
				case 5: dests = "����-��������";
				case 6: dests = "����-������";
				case 7: dests = "������� ����������";
				case 8: dests = "������� ����������";
				case 9: dests = "���������� ����������";
				case 10: dests = "������� ����";
			}
		}
		case ORG_AUTOSCHOOL:{
			switch(P[playerid][p_rang]){
				case 1: dests = "������";
				case 2: dests = "�����������";
				case 3: dests = "�����������";
				case 4: dests = "������� ����������";
				case 5: dests = "����������";
				case 6: dests = "�����������";
				case 7: dests = "������� ��������";
				case 8: dests = "��������";
				case 9: dests = "���. ���������";
				case 10: dests = "��������";
			}
		}
		case ORG_GROVE:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Newman";
				case 2: dests = "Hustla";
				case 3: dests = "Huckster";
				case 4: dests = "True";
				case 5: dests = "Warrior";
				case 6: dests = "Gangsta";
				case 7: dests = "O.G";
				case 8: dests = "Big Bro";
				case 9: dests = "Legend";
				case 10: dests = "Daddy";

			}
		}
		case ORG_BALLAS:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Stranger";
				case 2: dests = "Newman";
				case 3: dests = "Campbell";
				case 4: dests = "Nigga";
				case 5: dests = "Dre Papo";
				case 6: dests = "Gangsta";
				case 7: dests = "Shooter";
				case 8: dests = "Warrior";
				case 9: dests = "De King";
				case 10: dests = "Big Daddy";
			}
		}
		case ORG_AZTECAS:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Macho";
				case 2: dests = "Muchachos";
				case 3: dests = "El Mundo";
				case 4: dests = "De Mucho";
				case 5: dests = "El Papo";
				case 6: dests = "Amigos";
				case 7: dests = "Comproma";
				case 8: dests = "Aproximado";
				case 9: dests = "Sientes";
				case 10: dests = "Sientes";
			}
		}
		case ORG_VAGOS:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Papo";
				case 2: dests = "El Mundo";
				case 3: dests = "De Mucho";
				case 4: dests = "Amigos";
				case 5: dests = "Muchachos";
				case 6: dests = "Eltodor";
				case 7: dests = "Luchador";
				case 8: dests = "Comproma";
				case 9: dests = "Loco";
				case 10: dests = "Padre";
			}
		}
		case ORG_RIFA:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Macho";
				case 2: dests = "Muchachos";
				case 3: dests = "Amigo";
				case 4: dests = "Mirame";
				case 5: dests = "Matangos";
				case 6: dests = "El Pachino";
				case 7: dests = "Latin Dema";
				case 8: dests = "Vercificado";
				case 9: dests = "Del Sombra";
				case 10: dests = "Sie Padre";
			}
		}
		case ORG_CHINESE:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Cumite";
				case 2: dests = "Blue Lantern";
				case 3: dests = "49'er";
				case 4: dests = "Straw Sandal";
				case 5: dests = "White Paper Fan";
				case 6: dests = "Red Poles";
				case 7: dests = "Vanguard";
				case 8: dests = "Incense Master";
				case 9: dests = "Assistant Mountain Lord";
				case 10: dests = "Dragon";
			}
		}
		case ORG_RUSSIAN:{
			switch(P[playerid][p_rang]){
				case 1: dests = "������";
				case 2: dests = "��������";
				case 3: dests = "���������";
				case 4: dests = "����������";
				case 5: dests = "�����";
				case 6: dests = "�����";
				case 7: dests = "�������";
				case 8: dests = "�������� �����";
				case 9: dests = "���������";
				case 10: dests = "��� � ������";
			}
		}
		case ORG_ITALIAN:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Picciotti";
				case 2: dests = "Associato";
				case 3: dests = "Controllato";
				case 4: dests = "Razionate";
				case 5: dests = "Combatento";
				case 6: dests = "Soldato";
				case 7: dests = "Sottocapo";
				case 8: dests = "Cappo of Caporagimes";
				case 9: dests = "Consigliere";
				case 10: dests = "Don";
			}
		}
	}
	return dests;
}
stock SkinShop_Show(playerid, team)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING) TogglePlayerSpectating(playerid, 0);
	P[playerid][_p_in_game] = false;

    switch(P[playerid][p_sex])
    {
        case SEX_FEMALE:
            SetSpawnInfo(playerid, team, female_skins[0], 199.5363,-127.6896,1003.5152,175.2766, 0,0,0,0,0,0);
        case SEX_MALE:
            SetSpawnInfo(playerid, team, male_skins[0], 199.5363,-127.6896,1003.5152,175.2766, 0,0,0,0,0,0);
    }
	SetPlayerInterior(playerid,3);
	SetPlayerVirtualWorld(playerid,playerid+1);
	SetPlayerCameraPos(playerid,199.525466, -130.204528, 1003.751770);
	SetPlayerCameraLookAt(playerid,199.512817, -125.204986, 1003.685363);

	SpawnPlayer(playerid);
    for(new i; i < 8; i++)
        PlayerTextDrawShow(playerid, ChoseSkin[i]);
    SelectTextDraw(playerid, 0x3DA2B1FF);
}

stock Cash_Give(playerid, dollars = 0, cents = 0)   
{  
    P[playerid][p_cash] += dollars + cents;  
    ResetPlayerMoney(playerid);  
    GivePlayerMoney(playerid, P[playerid][p_cash] / 100);   
}  

stock Name(playerid)
{
    new dest[MAX_PLAYER_NAME+1];
	GetPlayerName(playerid, dest, MAX_PLAYER_NAME);
	return dest;
}

stock IC_Name(playerid)
{
	new dest[MAX_PLAYER_NAME+1];
	GetPlayerName(playerid, dest, MAX_PLAYER_NAME);
	for(new i; i < strlen(dest); i++) {
		if(dest[i] == '_') {
			dest[i] = ' ';
			break;
		}
	}
	return dest;
}

stock IC_Me(playerid, action[])
{
	new Float: x, Float: y, Float: z;
	GetPlayerPos(playerid, x,y,z);
	SetPlayerChatBubble(playerid, action, 0xDDA0DDFF, 35.0, 5000);
	foreach(new i : Player) {
	    if(!P[i][_p_in_game]) continue;
	    if(!IsPlayerInRangeOfPoint(i, 35.0, x,y,z)) continue;
	    if(GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) continue;
	    if(GetPlayerInterior(i) != GetPlayerInterior(playerid)) continue;
	    va_SendClientMessage(i, 0xDDA0DDFF, "%s %s", IC_Name(playerid),action);
	}
	return 1;
}
/*
stock Weapon_Sync(playerid)
{
    if(P[playerid][_p_spawned] == false) return 1;
	switch(GetPlayerState(playerid)) {
	    case 0,7..9: return 1;
	}
    new weapon[13], ammo[13];
	for(new i; i < 13; i++) {
	    GetPlayerWeaponData(playerid, i, weapon[i], ammo[i]);
	    if(ammo[i] <= 0) continue;
	    switch(weapon[i])
		{
	        case 0,46: continue;
	        case 1,10..18,24..25,35..42,44,45:
			{
				ResetPlayerWeapons(playerid);
				P[playerid][p_weapon_1] = 0;
				P[playerid][p_weapon_2] = 0;
				P[playerid][p_weapon_3] = 0;
				P[playerid][p_weapon_4] = 0;
				P[playerid][p_weapon_5] = 0;
				P[playerid][p_ammo_2] = 0;
				P[playerid][p_ammo_3] = 0;
				P[playerid][p_ammo_4] = 0;
				P[playerid][p_ammo_5] = 0;
				Message_ToAdmins(0xB9C9BFFF, "[������]: ׸���� ������ ������ - %s[%d] | W: %d / A: %d", Name(playerid),playerid,weapon[i],ammo[i]);
				printf("[������]: ׸���� ������ ������ - %s[%d] | W: %d / A: %d", Name(playerid),playerid,weapon[i],ammo[i]);
				P[playerid][_p_cheater]++;
			}
			default:
			{
			    if(weapon[i] == P[playerid][p_weapon_1]) continue;
			    else if(weapon[i] == P[playerid][p_weapon_2])
				{
			        if(ammo[i] > P[playerid][p_ammo_2]+1 && ammo[i] > P[playerid][p_ammo_2]+2)
					{
						Message_ToAdmins(0xB9C9BFFF, "[������]: �������������� �������� - %s[%d] | %d | C: %d / S: %d",Name(playerid),playerid,weapon[i],ammo[i],P[playerid][p_ammo_2]);
						SetPlayerAmmo(playerid, P[playerid][p_weapon_2], P[playerid][p_ammo_2]);
						P[playerid][_p_cheater]++;
			        }
			    }
			    else if(weapon[i] == P[playerid][p_weapon_3])
				{
			        if(ammo[i] > P[playerid][p_ammo_3]+1 && ammo[i] > P[playerid][p_ammo_3]+2) {
						Message_ToAdmins(0xB9C9BFFF, "[������]: �������������� �������� - %s[%d] | %d | C: %d / S: %d",Name(playerid),playerid,weapon[i],ammo[i],P[playerid][p_ammo_3]);
						SetPlayerAmmo(playerid, P[playerid][p_weapon_3], P[playerid][p_ammo_3]);
						P[playerid][_p_cheater]++;
			        }
			    }
			    else if(weapon[i] == P[playerid][p_weapon_4])
				{
			        if(ammo[i] > P[playerid][p_ammo_4]+1 && ammo[i] > P[playerid][p_ammo_4]+2) {
						Message_ToAdmins(0xB9C9BFFF, "[������]: �������������� �������� - %s[%d] | %d | C: %d / S: %d",Name(playerid),playerid,weapon[i],ammo[i],P[playerid][p_ammo_4]);
						SetPlayerAmmo(playerid, P[playerid][p_weapon_4], P[playerid][p_ammo_4]);
						P[playerid][_p_cheater]++;
			        }
			    }
				else if(weapon[i] == P[playerid][p_weapon_5])
				{
			        if(ammo[i] > P[playerid][p_ammo_5]+1 && ammo[i] > P[playerid][p_ammo_5]+2) {
						Message_ToAdmins(0xB9C9BFFF, "[������]: �������������� �������� - %s[%d] | %d | C: %d / S: %d",Name(playerid),playerid,weapon[i],ammo[i],P[playerid][p_ammo_5]);
						SetPlayerAmmo(playerid, P[playerid][p_weapon_5], P[playerid][p_ammo_5]);
						P[playerid][_p_cheater]++;
			        }
			    }
				else
				{
					Message_ToAdmins(0xB9C9BFFF, "[������]: �������������� �������� - %s[%d] | %d / %d",Name(playerid),playerid,weapon[i],ammo[i]);
			        ResetPlayerWeapons(playerid);
			        if(P[playerid][p_weapon_1] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_1],1);
					if(P[playerid][p_weapon_2] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_2],P[playerid][p_ammo_2]);
					if(P[playerid][p_weapon_3] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_3],P[playerid][p_ammo_3]);
					if(P[playerid][p_weapon_4] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_4],P[playerid][p_ammo_4]);
					if(P[playerid][p_weapon_5] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_5],P[playerid][p_ammo_5]);
					P[playerid][_p_cheater]++;
			    }
			} // default
	    } // switch
	} // for
	return 1;
}*/
stock Speedo_Sync(playerid)
{
    new engine,lights,alarm,doors,bonnet,boot,objective;
	new string[102],str_E[5],str_L[5],str_D[5];
	new vehicleid = GetPlayerVehicleID(playerid);
	new KMH = Vehicle_Speed(vehicleid);
	GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
	switch(engine) {
	    case -1,0: {
			str_E = "~r~E";
			KMH = 0;
		}
	    case 1: str_E = "~g~E";
	}
	switch(lights) {
	    case -1,0: str_L = "~r~L";
	    case 1: str_L = "~g~L";
	}
	switch(doors) {
	    case -1,0: str_D = "~g~D";
	    case 1: str_D = "~r~D";
	}
	switch(Vehicle_WithoutFuel(GetVehicleModel(vehicleid))) {
		case 0: format(string, sizeof(string), "~w~%d ~b~KM/H~n~FUEL: ~w~%.0f~n~%s %s %s", KMH,V[vehicleid][v_fuel],str_E,str_L,str_D);
		case 1: format(string, sizeof(string), "~w~%d ~b~KM/H~n~%s %s %s", KMH,str_E,str_L,str_D);
	}
	PlayerTextDrawSetString(playerid, P[playerid][_p_speedo], string);
}

stock Weapon_Give(playerid, weaponid, ammo)
{
    switch(weaponid) {
        case 1, 43, 46:
		{
            GivePlayerWeapon(playerid, weaponid, 1);
        }
        case 2..9:
		{
            P[playerid][p_weapon_1] = weaponid;
            GivePlayerWeapon(playerid, weaponid, 1);
        }
        case 22,23,24:
		{
            P[playerid][p_weapon_2] = weaponid;
            P[playerid][p_ammo_2] += ammo;
            GivePlayerWeapon(playerid, weaponid, ammo);
        }
		case 25,26,27:
		{
			P[playerid][p_weapon_3] = weaponid;
            P[playerid][p_ammo_3] += ammo;
			GivePlayerWeapon(playerid, weaponid, ammo);
		}
        case 28, 29, 32:
        {
            P[playerid][p_weapon_4] = weaponid;
            P[playerid][p_ammo_4] += ammo;
            GivePlayerWeapon(playerid, weaponid, ammo);
        }
        case 30, 31, 33:
		{
            P[playerid][p_weapon_5] = weaponid;
            P[playerid][p_ammo_5] += ammo;
            GivePlayerWeapon(playerid, weaponid, ammo);
        }
    }
}
stock ReturnPlayerWeaponsString(playerid)
{
	new string[128];
	new WeaponID, Ammo;
	for(new i = 0; i < 13; i++)
	{
	    if(i == 0 || i == 1)
		{
	   		GetPlayerWeaponData(playerid,i,WeaponID,Ammo);
	   		if(Ammo > 1) Ammo = 1;
	    }
		else GetPlayerWeaponData(playerid,i,WeaponID,Ammo);
		if(WeaponID > 0 && Ammo > 0)
		{
		    if(Ammo > 60000) Ammo = 1;

		    if(strlen(string) > 4) format(string,256,"%s, %s(~y~%w~r~)", string, WeaponID, Ammo);
			else format(string,256,"%w(~y~%d~r~)", WeaponID, Ammo);
		}
	}
	if(strlen(string) < 3) string = "N~w~/~r~A";
	return string;
}
stock Get_PlayerRegCountry(playerid)
{
    new dest[128];
    GetIPCountry(P[playerid][p_reg_ip], dest);
    return dest;
}
stock Get_PlayerLastIpCountry(playerid){
	new dest[128];
	GetIPCountry(P[playerid][p_last_ip], dest);
	return dest;
}
stock TeleportPlayerToPos(playerid, Float:x, Float:y, Float:z, interiorid, worldid){
	SetPlayerPos(playerid, x, y, z);
	SetPlayerInterior(playerid, interiorid);
	SetPlayerVirtualWorld(playerid, worldid);
}
stock Get_PlayerFPS(playerid)
{
	SetPVarInt(playerid, "DrunkL", GetPlayerDrunkLevel(playerid));
	if(GetPVarInt(playerid, "DrunkL") < 100) SetPlayerDrunkLevel(playerid, 2000);
	else
	{
		if(GetPVarInt(playerid, "LDrunkL") != GetPVarInt(playerid, "DrunkL"))
		{
			SetPVarInt(playerid, "FPS", (GetPVarInt(playerid, "LDrunkL") - GetPVarInt(playerid, "DrunkL")));
			SetPVarInt(playerid, "LDrunkL", GetPVarInt(playerid, "DrunkL"));
			if((GetPVarInt(playerid, "FPS") > 0) && (GetPVarInt(playerid, "FPS") < 256)) return GetPVarInt(playerid, "FPS") - 1;
		}
	}
	return 0;
}
stock Update_Skill(playerid,weaponid){
	switch(weaponid){
		case 22:{
			if(P[playerid][p_skill_pistol] == 1000) return true;
			P[playerid][p_skill_pistol] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_PISTOL,P[playerid][p_skill_pistol]);
		}
		case 23:{
			if(P[playerid][p_skill_pistol_silenced] == 1000) return true;
			P[playerid][p_skill_pistol_silenced] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_PISTOL_SILENCED,P[playerid][p_skill_pistol_silenced]);
		}
		case 24:{
			if(P[playerid][p_skill_desert_eagle] == 1000) return true;
			P[playerid][p_skill_desert_eagle] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_DESERT_EAGLE,P[playerid][p_skill_desert_eagle]);
		}
		case 25:{
			if(P[playerid][p_skill_shotgun] == 1000) return true;
			P[playerid][p_skill_shotgun] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_SHOTGUN,P[playerid][p_skill_shotgun]);
		}
		case 28,32:{
			if(P[playerid][p_skill_micro_uzi] == 1000) return true;
			P[playerid][p_skill_micro_uzi] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_MICRO_UZI,P[playerid][p_skill_micro_uzi]);
		}
		case 29:{
			if(P[playerid][p_skill_mp5] == 1000) return true;
			P[playerid][p_skill_mp5] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_MP5,P[playerid][p_skill_mp5]);
		}
		case 30:{
			if(P[playerid][p_skill_ak47] == 1000) return true;
			P[playerid][p_skill_ak47] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_AK47,P[playerid][p_skill_ak47]);
		}
		case 31:{
			if(P[playerid][p_skill_m4] == 1000) return true;
			P[playerid][p_skill_m4] += 10;
			SetPlayerSkillLevel(playerid,WEAPONSKILL_M4,P[playerid][p_skill_m4]);
		}
	}
	orm_update(P[playerid][_p_ormid]);
	return true;
}
public OnPlayerGetProtectionWarning(playerid, Protection:protection, bool:warn_reached, message[])
{
	new
		protection_name[32];

	Protection_GetParamString(protection, PROTECTION_NAME, protection_name);

	P[playerid][_p_cheater]++;
	if(Protection_GetPlayerParamInt(playerid, protection, PROTECTION_PLAYER_WARNING_COUNT) > 1){
		if(P[playerid][_p_cheater] >= 3){
			va_SendClientMessage(playerid, -1,"�� ���� ������� �� ���������� � ���������! {B9C9BF}[%s]",protection_name);
			Kick(playerid);
		}
		return true;
	}	
	
	Message_ToAdmins(0xB9C9BFFF, "[������]: %s[%d] | Cheat: %s | Debug: %s", Name(playerid),playerid, protection_name, message);
	return 1;
}
stock PlaySoundForPlayersInRange(soundid, Float:range, Float:x, Float:y, Float:z)
{
	foreach(new i:Player)
	{
	    if(IsPlayerConnected(i) && IsPlayerInRangeOfPoint(i,range,x,y,z))
	    {
		    PlayerPlaySound(i, soundid, x, y, z);
	    }
	}
}
