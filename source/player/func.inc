stock Get_AccessName(playerid)
{
	new dests[17];
	switch(P[playerid][p_access])
	{
	    case 0: dests = "Гражданин";
		case 1: dests = "Helper";
	    case 2: dests = "Модератор";
	    case 3: dests = "Супермодератор";
	    case 4: dests = "Администратор";
	    case 5: dests = "Гл.Администратор";
		case 6: dests = "Основатель";
	}
	return dests;
}

stock Get_TeamName(playerid)
{
	new dests[32];
	switch(P[playerid][p_job_team]){
		case ORG_UNKNOWN: dests = "Гражданин";
		case ORG_GOVERNMENT: dests = "Правительство Штата";
		case ORG_FBI: dests = "Федеральное Бюро Расследований";
		case ORG_LSPD: dests = "Полиция Лос Сантос";
		case ORG_SFPD: dests = "Полиция Сан Фиерро";
		case ORG_LVPD: dests = "Полиция Лас Вентурас";
		case ORG_MILITARY: dests = "Национальная Гвардия";
		case ORG_EMERGENCY: dests = "Служба Экстренной Помощи";
		case ORG_SANNEWS: dests = "Новости Сан Андреас";
		case ORG_AUTOSCHOOL: dests = "Центр Аттестации";
		case ORG_GROVE: dests = "Банда Grove Street";
		case ORG_BALLAS: dests = "Банда Ballas";
		case ORG_AZTECAS: dests = "Банда Aztecas";
		case ORG_VAGOS: dests = "Банда Vagos";
		case ORG_RIFA: dests = "Банда Rifa";
		case ORG_CHINESE: dests = "Семья 'Триада'";
		case ORG_RUSSIAN: dests = "Семья 'Воры в законе'";
		case ORG_ITALIAN: dests = "Семья 'Ла Коза Ностра'";
		case JOB_TAXI: dests = "Таксист";
		case JOB_ENGINEER: dests = "Инженер";
		case JOB_FREIGHTER: dests = "Грузоперевозчик";
		case JOB_WHITEWING: dests = "Уборщик улиц";
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
            SetSpawnInfo(playerid, team, female_skins[team][2], 199.5363,-127.6896,1003.5152,175.2766, 0,0,0,0,0,0);
        case SEX_MALE:
            SetSpawnInfo(playerid, team, male_skins[team][2], 199.5363,-127.6896,1003.5152,175.2766, 0,0,0,0,0,0);
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

stock Cash_Give(playerid, Float: amount)
{
	P[playerid][p_cash] = floatadd(P[playerid][p_cash],amount);
	GivePlayerMoney(playerid, floatround(amount));
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

stock Weapon_Sync(playerid)
{
	new mes[164];
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
				P[playerid][p_ammo_2] = 0;
				P[playerid][p_ammo_3] = 0;
				P[playerid][p_ammo_4] = 0;
				//Message_ToAdmins(0xB9C9BFFF, "[Защита]: Чёрный список оружия - %s[%d] | W: %d / A: %d", Name(playerid),playerid,weapon[i],ammo[i]);

				format(mes, sizeof(mes),"[Защита]: Чёрный список оружия - %s[%d] | W: %d / A: %d", Name(playerid),playerid,weapon[i],ammo[i]);
				Message_ToAdmins(0xB9C9BFFF, mes);
				printf("[Защита]: Чёрный список оружия - %s[%d] | W: %d / A: %d", Name(playerid),playerid,weapon[i],ammo[i]);
				P[playerid][_p_cheater]++;
			}
			default:
			{
			    if(weapon[i] == P[playerid][p_weapon_1]) continue;
			    else if(weapon[i] == P[playerid][p_weapon_2])
				{
			        if(ammo[i] > P[playerid][p_ammo_2]+1 && ammo[i] > P[playerid][p_ammo_2]+2)
					{
						Message_ToAdmins(0xB9C9BFFF, "[Защита]: Несоответствие патронов - %s[%d] | %d | C: %d / S: %d",Name(playerid),playerid,weapon[i],ammo[i],P[playerid][p_ammo_2]);
						SetPlayerAmmo(playerid, P[playerid][p_weapon_2], P[playerid][p_ammo_2]);
						P[playerid][_p_cheater]++;
			        }
			    }
			    else if(weapon[i] == P[playerid][p_weapon_3])
				{
			        if(ammo[i] > P[playerid][p_ammo_3]+1 && ammo[i] > P[playerid][p_ammo_3]+2) {
						Message_ToAdmins(0xB9C9BFFF, "[Защита]: Несоответствие патронов - %s[%d] | %d | C: %d / S: %d",Name(playerid),playerid,weapon[i],ammo[i],P[playerid][p_ammo_3]);
						SetPlayerAmmo(playerid, P[playerid][p_weapon_3], P[playerid][p_ammo_3]);
						P[playerid][_p_cheater]++;
			        }
			    }
			    else if(weapon[i] == P[playerid][p_weapon_4])
				{
			        if(ammo[i] > P[playerid][p_ammo_4]+1 && ammo[i] > P[playerid][p_ammo_4]+2) {
						Message_ToAdmins(0xB9C9BFFF, "[Защита]: Несоответствие патронов - %s[%d] | %d | C: %d / S: %d",Name(playerid),playerid,weapon[i],ammo[i],P[playerid][p_ammo_4]);
						SetPlayerAmmo(playerid, P[playerid][p_weapon_4], P[playerid][p_ammo_4]);
						P[playerid][_p_cheater]++;
			        }
			    }
				else
				{
					Message_ToAdmins(0xB9C9BFFF, "[Защита]: Несоответствие патронов - %s[%d] | %d / %d",Name(playerid),playerid,weapon[i],ammo[i]);
			        ResetPlayerWeapons(playerid);
			        if(P[playerid][p_weapon_1] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_1],1);
					if(P[playerid][p_weapon_2] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_2],P[playerid][p_ammo_2]);
					if(P[playerid][p_weapon_3] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_3],P[playerid][p_ammo_3]);
					if(P[playerid][p_weapon_4] != 0) GivePlayerWeapon(playerid, P[playerid][p_weapon_4],P[playerid][p_ammo_4]);
					P[playerid][_p_cheater]++;
			    }
			} // default
	    } // switch
	} // for
	printf("debug12451 67");
	return 1;
}

stock Health_Sync(playerid)
{
	if(P[playerid][_p_spawned] == false) return 1;
	switch(GetPlayerState(playerid)) {
	    case 0,7..9: return 1;
	}
    new Float: fhealth;
	GetPlayerHealth(playerid, fhealth);
	new health = floatround(fhealth);
	if(health > P[playerid][p_health]) {
	    if(IsPlayerNearVending(playerid, 1 | 2)) {
			P[playerid][p_health] += 5;
			if(P[playerid][p_health] > 100) P[playerid][p_health] = 100;
			SetPlayerHealth(playerid, P[playerid][p_health]);
	    } else {
			Message_ToAdmins(0xB9C9BFFF, "[Защита]: Несоответствие здоровья - %s[%d] | C: %d / S: %d",Name(playerid),playerid,health,P[playerid][p_health]);
	        SetPlayerHealth(playerid, P[playerid][p_health]);
	        P[playerid][_p_cheater]++;
	    }
	}
	return 1;
}

stock Armour_Sync(playerid)
{
    if(P[playerid][_p_spawned] == false) return 1;
	switch(GetPlayerState(playerid))
	{
	    case 0,7..9: return 1;
	}
    new Float: farmour;
	GetPlayerArmour(playerid, farmour);
	new armour = floatround(farmour);
	if(armour > P[playerid][p_armour])
	{
		Message_ToAdmins(0xB9C9BFFF, "[Защита]: Несоответствие бронежилета - %s[%d] | C: %d / S: %d",Name(playerid),playerid,armour,P[playerid][p_armour]);
	    SetPlayerArmour(playerid, P[playerid][p_armour]);
	    P[playerid][_p_cheater]++;
	}
	return 1;
}

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
            GivePlayerWeapon(playerid, P[playerid][p_weapon_2], P[playerid][p_ammo_2]);
            GivePlayerWeapon(playerid, P[playerid][p_weapon_3], P[playerid][p_ammo_3]);
			GivePlayerWeapon(playerid, P[playerid][p_weapon_4], P[playerid][p_ammo_4]);
        }
        case 22..24:
		{
            P[playerid][p_weapon_2] = weaponid;
            P[playerid][p_ammo_2] += ammo;
            GivePlayerWeapon(playerid, P[playerid][p_weapon_1], 1);
            GivePlayerWeapon(playerid, weaponid, ammo);
            GivePlayerWeapon(playerid, P[playerid][p_weapon_3], P[playerid][p_ammo_3]);
			GivePlayerWeapon(playerid, P[playerid][p_weapon_4], P[playerid][p_ammo_4]);
        }
        case 28, 29, 32:
        {
            P[playerid][p_weapon_3] = weaponid;
            P[playerid][p_ammo_3] += ammo;
            GivePlayerWeapon(playerid, P[playerid][p_weapon_1], 1);
			GivePlayerWeapon(playerid, P[playerid][p_weapon_2], P[playerid][p_ammo_2]);
            GivePlayerWeapon(playerid, weaponid, ammo);
			GivePlayerWeapon(playerid, P[playerid][p_weapon_4], P[playerid][p_ammo_4]);
        }
        case 25..27, 30, 31,33:
		{
            P[playerid][p_weapon_4] = weaponid;
            P[playerid][p_ammo_4] += ammo;
            GivePlayerWeapon(playerid, P[playerid][p_weapon_1], 1);
            GivePlayerWeapon(playerid, P[playerid][p_weapon_2], P[playerid][p_ammo_2]);
			GivePlayerWeapon(playerid, P[playerid][p_weapon_3], P[playerid][p_ammo_3]);
            GivePlayerWeapon(playerid, weaponid, ammo);
        }
    }
}
stock GetTeamZoneColor(teamid)
{
	switch(teamid)
	{
		case 1: return 0x009900AA;
		case 2: return 0xCC00FFAA;
		case 3: return 0x00CCFFAA;
		case 4: return 0xFFFF00AA;
		case 5: return 0x6666FFAA;
	}
	return -1;
}
new weaponName[][] = {
	{"Fist"}, // 0
	{"Brass Knuckles"}, // 1
	{"Golf Club"}, // 2
	{"Night Stick"}, // 3
	{"Knife"}, // 4
	{"Baseball Bat"}, // 5
	{"Shovel"}, // 6
	{"Pool Cue"}, // 7
	{"Katana"}, // 8
	{"Chainsaw"}, // 9
	{"Purple Dildo"}, // 10
	{"Big White Vibrator"}, // 11
	{"Medium White Vibrator"}, // 12
	{"Small White Vibrator"}, // 13
	{"Flowers"}, // 14
	{"Cane"}, // 15
	{"Grenade"}, // 16
	{"Teargas"}, // 17
	{"Molotov"}, // 18
	{" "}, // 19
	{" "}, // 20
	{" "}, // 21
	{"Colt 45"}, // 22
	{"Silenced"}, // 23
	{"Deagle"}, // 24
	{"Shotgun"}, // 25
	{"Sawnoff"}, // 26
	{"Combat"}, // 27
	{"Uzi"}, // 28
	{"MP5"}, // 29
	{"AK47"}, // 30
	{"M4"}, // 31
	{"Tec9"}, // 32
	{"Rifle"}, // 33
	{"Sniper"}, // 34
	{"RPG"}, // 35
	{"HS RPG"}, // 36
	{"Flame"}, // 37
	{"Minigun"}, // 38
	{"Satchel Charge"}, // 39
	{"Detonator"}, // 40
	{"Spray Can"}, // 41
	{"Fire Extinguisher"}, // 42
	{"Camera"}, // 43
	{"Nightvision"}, // 44
	{"Infrared Vision"}, // 45
	{"Parachute"}, // 46
	{"Fake Pistol"} // 47
};
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

		    if(strlen(string) > 4) format(string,256,"%s, %s(~y~%d~r~)", string, weaponName[WeaponID], Ammo);
			else format(string,256,"%s(~y~%d~r~)", weaponName[WeaponID], Ammo);
		}
	}
	if(strlen(string) < 3) string = "N~w~/~r~A";
	return string;
}
stock GetPlayerRegCountry(playerid)
{
    new dest[128];
    GetIPCountry(P[playerid][p_reg_ip], dest);
    return dest;
}
