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
	}
	return dests;
}
stock Get_RangName(playerid)
{
	new dests[41+1];
	switch(P[playerid][p_job_team]){
		case ORG_UNKNOWN, JOB_TAXI, JOB_ENGINEER, JOB_FREIGHTER : dests = "-";
		case ORG_GOVERNMENT:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Водитель";
				case 2: dests = "Охранник";
				case 3: dests = "Нач. Охраны";
				case 4: dests = "Пресс-Секретарь";
				case 5: dests = "Советник по мэриям";
				case 6: dests = "Советник по армиям";
				case 7: dests = "Советник по органам внутренних дел";
				case 8: dests = "Контролер органов здравоохранения";
				case 9: dests = "Советник по средствам массовой информации";
				case 10: dests = "Вице-президент";
				case 11: dests = "Президент";

			}
		}
		case ORG_FBI:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Стажер";
				case 2: dests = "Младший агент";
				case 3: dests = "Агент отдела ГНК";
				case 4: dests = "Агент отдела КСО";
				case 5: dests = "Старший агент";
				case 6: dests = "Глава отдела ГНК";
				case 7: dests = "Глава отдела КСО";
				case 8: dests = "Инспектор ФБР";
				case 9: dests = "Заместитель директора ФБР";
				case 10: dests = "Директор ФБР";
			}
		}
		case ORG_LSPD, ORG_SFPD, ORG_LVPD:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Кадет";
				case 2: dests = "Патрульный";
				case 3: dests = "Офицер";
				case 4: dests = "Детектив";
				case 5: dests = "Сержант";
				case 6: dests = "Лейтенант";
				case 7: dests = "Капитан";
				case 8: dests = "Инспектор";
				case 9: dests = "Комиссар";
				case 10: dests = "Генерал";
			}
		}
		case ORG_EMERGENCY:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Интерн";
				case 2: dests = "Младший медработник";
				case 3: dests = "Старший медработник";
				case 4: dests = "Врач-участковый";
				case 5: dests = "Врач-терапевт";
				case 6: dests = "Врач-хирург";
				case 7: dests = "Младший специалист";
				case 8: dests = "Старший специалист";
				case 9: dests = "Заведующий отделением";
				case 10: dests = "Главный врач";
			}
		}
		case ORG_AUTOSCHOOL:{
			switch(P[playerid][p_rang]){
				case 1: dests = "Стажер";
				case 2: dests = "Консультант";
				case 3: dests = "Экзаменатор";
				case 4: dests = "Младший Инструктор";
				case 5: dests = "Инструктор";
				case 6: dests = "Координатор";
				case 7: dests = "Младший Менеджер";
				case 8: dests = "Менеджер";
				case 9: dests = "Зам. Директора";
				case 10: dests = "Директор";
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
				case 1: dests = "Чистый";
				case 2: dests = "Арестант";
				case 3: dests = "Смотрящий";
				case 4: dests = "Правильный";
				case 5: dests = "Жулик";
				case 6: dests = "Босяк";
				case 7: dests = "Бродяга";
				case 8: dests = "Козырный фраер";
				case 9: dests = "Авторитет";
				case 10: dests = "Вор в законе";
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
				Message_ToAdmins(0xB9C9BFFF, "[Защита]: Чёрный список оружия - %s[%d] | W: %d / A: %d", Name(playerid),playerid,weapon[i],ammo[i]);
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
}/*
forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code)
{
	if(type) BlockIpAddress(ip_address, 0); //Среагировал на IP (например за попытку брута ркона) - блочим его
	else //Среагировал на ID игрока
	{
		switch(code) //Какой чит?
		{
			case 5: return 1; //Телепорт незанятых авто (античит в любом случае вернёт её на прежнее место, наказание лучше не делать)
			case 7:{
				Message_ToAdmins(0xB22222FF, "[Защита]: {FFFFFF}Подозрение на FlyHack (onfoot) - %s[%d]",Name(playerid),playerid);
				return 1;
			}
			case 8:{
				Message_ToAdmins(0xB22222FF, "[Защита]: {FFFFFF}Подозрение на FlyHack (in vehicle) - %s[%d]",Name(playerid),playerid);
				return 1;
			}
			case 11: //Починка транспорта, лучше вернуть ему старое хп (если не применит его - сработает уже анти-ноп)
			{
				new vehid = GetPlayerVehicleID(playerid), Float:vhealth;
				AntiCheatGetVehicleHealth(vehid, vhealth);
				SetVehicleHealth(vehid, vhealth);
				return 1;
			}
			case 14: //Деньги
			{
				//Возвращаем старую сумму
				new a = AntiCheatGetMoney(playerid);
				ResetPlayerMoney(playerid);
				GivePlayerMoney(playerid, a);
				return 1; //Иное наказание также нам не нужно
			}
			case 32: return ClearAnimations(playerid, 1); //CarJack, выкидываем игрока из авто
			case 40: SendClientMessage(playerid, -1, MAX_CONNECTS_MSG); //Песочница (вход 2-х и более человек с одного IP), прощаемся
			case 41: SendClientMessage(playerid, -1, UNKNOWN_CLIENT_MSG); //Версия клиента игрока не определена, прощаемся с ним
			case 43..47: //Крашеры
			{
				Kick(playerid); //КРАЙНЕ рекомендуется кикать без задержки, иначе ОНО успеет крашнуть игроков
				return 1;
			}
			default: //Здесь все остальные читы
			{
				va_SendClientMessage(playerid, -1, "Вы были кикнуты по причине %s (#%d)", CheatNames[code], code);
				Kick(playerid);
				return 1;
			}
		}
		new pPing = GetPlayerPing(playerid) + 150;
		SetTimerEx("ac_KickTimer", (pPing > 500 ? 500 : pPing), false, "i", playerid); //Кик за 40 и 41 код, ac_KickTimer есть в античите и успешно сработает
	}
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
        case 25..27, 30, 31, 33:
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
stock Get_TeamZoneColor(teamid)
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
stock Get_GangOnline(gangid){
	foreach(new i:Player)
	{
		if(!IsPlayerConnected(i)) continue;
		if(P[i][p_job_team] == gangid) return true;
	}
	return false;
}
stock Get_GangName(gangid){
	new dests[22+1];
	switch(gangid){
		case ORG_GROVE: dests = "Grove Street";
		case ORG_BALLAS: dests = "Ballas Gangs";
		case ORG_AZTECAS: dests = "Varios Los Aztecas";
		case ORG_VAGOS: dests = "Los Santos Vagos";
		case ORG_RIFA: dests = "The Rifa";
		case ORG_CHINESE: dests = "Семья 'Триада'";
		case ORG_RUSSIAN: dests = "Семья 'Воры в законе'";
		case ORG_ITALIAN: dests = "Семья 'Ла Коза Ностра'";
	}
	return dests;
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
