CMD:repair(playerid, params[])
{
	if (IsPlayerInAnyVehicle(playerid) == 0)
		return 1;

	RepairVehicle(GetPlayerVehicleID(playerid));
	GameTextForPlayer(playerid, "vehicle~n~~g~repaired", 2000, 1);
	return 1;
}

CMD:lock(playerid, params[])
{
	if (GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
		return 1;

    new Float: x, Float: y, Float: z;
	GetPlayerPos(playerid, x,y,z);
	foreach(new i : Vehicle) {
		if (IsVehicleStreamedIn(i, playerid) == 0)
			continue;
		new Float: dist = GetVehicleDistanceFromPoint(i, x,y,z);
		if (dist > 2.5)
			continue;
		if (Vehicle_IsNotForPlayer(i, playerid))
			continue;
		if (Vehicle_WithoutDoor(GetVehicleModel(i)) == 1)
			return 1;
		new engine,lights,alarm,doors,bonnet,boot,objective;
		GetVehicleParamsEx(i, engine,lights,alarm,doors,bonnet,boot,objective);
		switch(doors) {
			case -1, 0: {
				SetVehicleParamsEx(i, engine,lights,alarm,1,bonnet,boot,objective);
				GameTextForPlayer(playerid, "vehicle~n~~r~closed", 2000, 1);
			}
			case 1: {
				SetVehicleParamsEx(i, engine,lights,alarm,0,bonnet,boot,objective);
				GameTextForPlayer(playerid, "vehicle~n~~g~open", 2000, 1);
			}
		}
		break;
	}
    return 1;
}

CMD:fill(playerid, params[])
{
	if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
		return 1;

    for(new i; i < sizeof(PS); i++) {
		if (IsPlayerInRangeOfPoint(playerid, 5.0, PS[i][ps_pos_x],PS[i][ps_pos_y],PS[i][ps_pos_z]) == 0)
			continue;

		new Float: volume, Float: amount;
		new vehicleid = GetPlayerVehicleID(playerid);
		if (sscanf(params, "f", volume))
			return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /fill <объём>");
		if (volume <= 0 || volume > Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)))
			return va_SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Объем заправляемого не может превышать %d литров", Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)));
		if ((volume + V[vehicleid][v_fuel]) > Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)))
			return va_SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Объем заправляемого не может превышать %d литров", Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)));
		amount = volume * Prices_Fuel;
		Cash_Give(playerid, -amount);
		V[vehicleid][v_fuel] = floatadd(V[vehicleid][v_fuel], volume);
		PS[i][ps_volume] -= volume;
		PS[i][ps_profit] += amount;
		va_SendClientMessage(playerid, -1, "Автомобиль заправлен на %d литров за $%.2f", volume,amount);
    }
	return 1;
}

CMD:o(playerid, params[])
{
	if (isnull(params))
		return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /o <текст>");

	switch(P[playerid][p_access]) {
		case 0: {
			if (g_Chat_OOC == 0)
				return 1;
			if ((gettime() - P[playerid][_p_chat_time]) < 3)
				return 1;
			if (containsAnyIP(params))
				return 1;
			strtolower(params);
			if (strlen(P[playerid][_p_chat_msg]) == strlen(params))
				if (strcmp(P[playerid][_p_chat_msg], params, true) == 0)
					return 1;
			if (strlen(params) > 64) {
				new line1[128], line2[128];
				new pos = strfind(params, " ", false, 64);
				if (pos == (-1))
					pos = 64;
				strmid(line1, params, 0, pos);
				strmid(line2, params, pos, strlen(params));
				Message_ToAll(0xE0FFFFFF, "<< %s[%d]: %s", Name(playerid),playerid,line1);
				Message_ToAll(0xE0FFFFFF, line2);
			}
			else Message_ToAll(0xE0FFFFFF, "<< %s[%d]: %s", Name(playerid),playerid,params);
			format(P[playerid][_p_chat_msg], 128, params);
			P[playerid][_p_chat_time] = gettime();
		}
		default: {
			if (strlen(params) > 48) {
				new pos = strfind(params, " ", false, 48);
				new line1[128], line2[128];
				if (pos == (-1))
					pos = 48;
				strmid(line1, params, 0, pos);
				strmid(line2, params, pos, strlen(params));
				Message_ToAll(0xE0FFFFFF, "<< %s %s[%d]: %s", Get_AccessName(playerid),Name(playerid),playerid,line1);
			    Message_ToAll(0xE0FFFFFF, line2);
			}
			else Message_ToAll(0xE0FFFFFF, "<< %s %s[%d]: %s", Get_AccessName(playerid),Name(playerid),playerid,params);
		}
	}
	return 1;
}

CMD:b(playerid, params[])
{
	if (isnull(params))
		return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /b <текст>");
	if ((gettime() - P[playerid][_p_chat_time]) < 3)
		return 1;
	if (containsAnyIP(params))
		return 1;
	strtolower(params);
	if (strlen(P[playerid][_p_chat_msg]) == strlen(params))
		if (strcmp(P[playerid][_p_chat_msg], params, true) == 0)
			return 1;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x,y,z);
	foreach(new i : Player) {
	    if (P[i][_p_in_game] == false)
			continue;
	    if (IsPlayerInRangeOfPoint(i, 70.0, x,y,z) == 0)
			continue;
	    if (GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid))
			continue;
	    if (GetPlayerInterior(i) != GetPlayerInterior(playerid))
			continue;
		if (strlen(params) > 64) {
			new line1[128], line2[128];
			new pos = strfind(params, " ", false, 64);
			if (pos == (-1))
				pos = 64;
			strmid(line1, params, 0, pos);
			strmid(line2, params, pos, strlen(params));
			va_SendClientMessage(i, 0xFFDEADFF, "(( %s[%d]: %s", Name(playerid),playerid,line1);
			SendClientMessage(i, 0xFFDEADFF, line2);
		}
		else va_SendClientMessage(i, 0xFFDEADFF, "(( %s[%d]: %s", Name(playerid),playerid,params);
	}
	format(P[playerid][_p_chat_msg], 128, params);
	P[playerid][_p_chat_time] = gettime();
	return 1;
}

CMD:s(playerid, params[])
{
	if(isnull(params)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /s <текст>");
	if((gettime() - P[playerid][_p_chat_time]) < 3) return 1;
	if(containsAnyIP(params)) return 1;
	strtolower(params);
	if(strlen(P[playerid][_p_chat_msg]) == strlen(params)) {
		if(strcmp(P[playerid][_p_chat_msg], params, true) == 0) return 1;
	}
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x,y,z);
	SetPlayerChatBubble(playerid, params, 0xFFFF00FF, 70.0, 5000);
	ApplyAnimation(playerid, "RIOT", "RIOT_shout", 4.1, 0, 1,1, 0, 0, 1);
	foreach(new i : Player) {
	    if(P[i][_p_in_game] == false) continue;
	    if(!IsPlayerInRangeOfPoint(i, 70.0, x,y,z)) continue;
	    if(GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) continue;
	    if(GetPlayerInterior(i) != GetPlayerInterior(playerid)) continue;
		if(strlen(params) > 64) {
			new line1[128], line2[128];
			new pos = strfind(params, " ", false, 64);
			if(pos == (-1)) pos = 64;
			strmid(line1, params, 0, pos);
			strmid(line2, params, pos, strlen(params));
			va_SendClientMessage(i, -1, "%s кричит: %s", IC_Name(playerid),line1);
			va_SendClientMessage(i, -1, "%s%c", line2,'!');
		} else va_SendClientMessage(i, -1, "%s кричит: %s!", IC_Name(playerid),params);
	}
	format(P[playerid][_p_chat_msg], 128, params);
	P[playerid][_p_chat_time] = gettime();
	return 1;
}

CMD:me(playerid, params[])
{
	if(isnull(params)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /me <действие>");
	if(containsAnyIP(params)) return 1;

	strtolower(params);
	IC_Me(playerid, params);
	return 1;
}

CMD:try(playerid, params[])
{
	if(isnull(params)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /try <действие>");
	if(containsAnyIP(params)) return 1;

	new string[128];
	switch(random(2)) {
	    case 0: format(string, sizeof(string), "неудачно %s", params);
	    case 1: format(string, sizeof(string), "удачно %s", params);
	}
	IC_Me(playerid, string);
	return 1;
}

CMD:veh(playerid, params[])
{
    if(P[playerid][_p_in_game] == false) return 1;
    if(P[playerid][p_access] < 1) return 1;

	new model,color1 = (-1),color2 = (-1);
	sscanf(params, "iii", model,color1,color2);
	if(isnull(params)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /veh <модель> [Цвет1] [Цвет2]");

	new Float: x, Float: y, Float: z, Float: a;
	GetPlayerPos(playerid, x,y,z);
	GetPlayerFacingAngle(playerid, a);
	Vehicle_Add(model, x+1,y+1,z,a, color1,color2);
	return 1;
}

CMD:mn(playerid, params[])
{
	ShowPlayerDialog(playerid, d_player_menu, DIALOG_STYLE_LIST, "Меню", "1. Статистика\n2. Список команд\n3. Личные настройки\n4. Обратная связь\n5. Правила сервера", "Открыть", "Выход");
	return 1;
}

CMD:gotopos(playerid, params[])
{
 	new Float:paramss[3];
	if(sscanf(params, "fff", paramss[0], paramss[1], paramss[2])) return SendClientMessage(playerid, -1, "Используйте: /gotopos [X] [Y] [Z]");
	SetPlayerPos(playerid, paramss[0], paramss[1], paramss[2]);
	va_SendClientMessage(playerid, 0xB9C9BFFF, "Вы телепортированы: X:%f; Y:%f; Z:%f.", paramss[0], paramss[1], paramss[2]);
	return true;
}
CMD:makeleader(playerid, params[])
{
  	new string[144],
    user,org;
	if(P[playerid][p_access] < 6) return 1;
	if(sscanf(params, "ui", user,org)) return SendClientMessage(playerid, 0xff0000ff,"Используйте:{ffffff} /makeleader [ID] [ID Фракции]");
	if(org > 19) return 1;
	P[user][p_job_team] = org;
	va_SendClientMessage(user,COLOR_YELLOW, "%s[%d] назначил Вас лидером организации \"%s\" ",Name(playerid), playerid, Get_TeamName(user));
	va_SendClientMessage(playerid,COLOR_ORANGE, "Вы назначили игрока %s[%d] на лидерство фракции \"%s\" ",Name(user), user, Get_TeamName(user));
	format(string, 144, "[A] %s[%d] назначил %s[%d] лидером организации \"%s\"",Name(playerid), playerid, Name(user), user, Get_TeamName(user));
	Message_ToAdmins(COLOR_GREY, string);
  	orm_update(P[user][_p_ormid]);
	//SpawnPlayer(user);
	return 1;
}
CMD:goto(playerid, params[])
{
	if(P[playerid][p_access] < 1) return 1;
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, -1, "{CECFCE} Использование: /goto [ID] ");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xC9C5C5, "Неверный ID");
	new Float:plocx,Float:plocy,Float:plocz;
	GetPlayerPos(params[0], plocx, plocy, plocz);
	SetPlayerPos(playerid,plocx,plocy+2, plocz);
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(params[0]));
	SetPlayerInterior(playerid, GetPlayerInterior(params[0]));
	return 1;
}
CMD:sethp(playerid, params[])
{
	new player,health;
	if(P[playerid][p_access] < 1) return 1;
	if(sscanf(params,"ui",player,health))return SendClientMessage(playerid, COLOR_GREY, "Использовать: /sethp [ID] [HP]");
	if(health < 0 || health > 100) return SendClientMessage(playerid, COLOR_GREY, "Жизни не меньше 0 и не больше 100");
	SetPlayerHealth(player, health);
	return true;
}
CMD:msg(playerid, params[])
{
	if(P[playerid][p_access] < 1) return 1;
	if(sscanf(params, "s[120]", params[0])) return SendClientMessage(playerid, -1, "{CECFCE}Использование: /msg [сообщение]");
	va_SendClientMessageToAll(0xFFCD00AA, "Администратор %s: %s",  Name(playerid), params[0]);
	return 1;
}
CMD:kick(playerid, params[])
{
	if(P[playerid][p_access] < 1) return 1;
    if(sscanf(params,"us[64]",params[0], params[1])) return SendClientMessage(playerid, -1, "Введите: /kick [ID] [Причина]");
   	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xCECFCEFF, "Веденный вами ID не найден на сервере");
    va_SendClientMessageToAll(0xFF5030AA, "Администратор %s кикнул игрока %s. Причина: %s", Name(playerid), Name(params[0]), params[1]);
    Kick(params[0]);
    return 1;
}
CMD:skick(playerid, params[])
{
	if(P[playerid][p_access] < 3) return 1;
	new mes[116];
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, -1, "Введите: /skick [ID]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xCECFCEFF, "Веденный вами ID не найден на сервере");
	format(mes, sizeof(mes),"Администратор %s тихо кикнул игрока %s", Name(playerid), Name(params[0]));
	Message_ToAdmins(0xAFAFAFFF, mes);
	Kick(params[0]);
	return 1;
}
CMD:ans(playerid,params[])
{
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"us[94]",params[0],params[1])) return SendClientMessage(playerid, -1, "Введите /ans [ID] [Ответ]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xCECFCEFF, "Веденный вами ID не найден на сервере");
	va_SendClientMessage(params[0],0xFF9945FF,"Ответ администратора %s[%d]: %s",Name(playerid),playerid,params[1]);
	PlayerPlaySound(params[0], 1085, 0.0, 0.0, 0.0);
	new mes[164];
	format(mes, sizeof(mes),"Администратор %s[%d] для %s[%d]: %s",Name(playerid),playerid,Name(params[0]),params[0],params[1]);
	Message_ToAdmins(0xAFAFAFFF, mes);
	return true;
}
CMD:stats(playerid,params[]){

	new string[100];
	format(string,sizeof string,"{FFFFFF}Имя:\t\t%s\nОрганизация:\t\t%s\nПол:\t\t%d\nДенег:\t\t$%.2f",Name(playerid),Get_TeamName(playerid),P[playerid][p_sex],P[playerid][p_cash]);
	ShowPlayerDialog(playerid,d_null,DIALOG_STYLE_MSGBOX,"Статистика",string,"Выход","");
	return true;
}
CMD:lic(playerid, params[])
{
    new output[570],lic_car[45],lic_aircraft[26],lic_boat[26],lic_moto[26],lic_weapon[26],lic_business[26],lic_freight[26],lic_helicopter[26];
    lic_car = (P[playerid][p_lic_car] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    lic_aircraft = (P[playerid][p_lic_aircraft] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    lic_boat = (P[playerid][p_lic_boat] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    lic_moto = (P[playerid][p_lic_moto] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    lic_weapon = (P[playerid][p_lic_weapon] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    lic_business = (P[playerid][p_lic_business] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    lic_freight = (P[playerid][p_lic_freight] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    lic_helicopter = (P[playerid][p_lic_helicopter] == 1) ? "{33AA33}В наличии{FFFFFF}" : "{AA3333}Нет{FFFFFF}";
    format(output, sizeof(output),
        "{FFFFFF}Водительские права:\t\t\t\t\t%s\n\
        Лицензия пилотирования самолётом:\t\t%s\n\
        Лицензия на водный транспорт:\t\t\t%s\n\
        Лицензия на вождения спорт байка:\t\t%s\n\
        Лицензия на оружиею:\t\t\t\t%s\n\
        Лицензия на бизнес:\t\t\t\t\t%s\n\
        Лицензия на грузо-перевозку:\t\t\t%s\n\
        Лицензия на пилотирования вертолётом:\t\t%s",
        lic_car,lic_aircraft,lic_boat,lic_moto,lic_weapon,lic_business,lic_freight,lic_helicopter);
    ShowPlayerDialog(playerid, d_null, DIALOG_STYLE_MSGBOX, "Лицензии", output, "Ок","");
    return 1;
}
CMD:givegun(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"udd",params[0],params[1],params[2])) return SendClientMessage(playerid,-1, "/givegun [ID] [ID GUN] [PT]");
	Weapon_Give(params[0],params[1],params[2]);
	return true;
}
