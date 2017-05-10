CMD:arepair(playerid, params[])
{
	if(P[playerid][p_access] < 1) return true;
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
		if(PS[i][ps_volume] <= 0)
			return va_SendClientMessage(playerid,0xB22222FF, "[Справка]: {FFFFFF}В %s недостаточно топливо.",PS[i][ps_name]);
		if (GetEngineStat(vehicleid)  == 1)
			return SendClientMessage(playerid,0xB22222FF, "[Справка]: {FFFFFF}Заправляться можно только с заглушенным двигателем.");
		if (volume <= 0 || volume > Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)))
			return va_SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Объем заправляемого не может превышать %d литров.", Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)));
		if ((volume + V[vehicleid][v_fuel]) > Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)))
			return va_SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Объем заправляемого не может превышать %d литров.", Vehicle_GetMaxFuel(GetVehicleModel(vehicleid)));
		amount = volume * PS[i][ps_fuel_price];
		Cash_Give(playerid, -amount);
		V[vehicleid][v_fuel] = floatadd(V[vehicleid][v_fuel], volume);
		PS[i][ps_volume] -= volume;
		PS[i][ps_profit] += amount;
		va_SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Автомобиль был запралвен на %.0f литра, цена: $%.2f.",volume,amount);
    }
	return 1;
}

CMD:o(playerid, params[])
{
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
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
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
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
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
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
CMD:w(playerid,params[]){
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
	if(isnull(params)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /w <текст>");
	if((gettime() - P[playerid][_p_chat_time]) < 3) return 1;
	if(containsAnyIP(params)) return 1;
	strtolower(params);
	if(strlen(P[playerid][_p_chat_msg]) == strlen(params)) {
		if(strcmp(P[playerid][_p_chat_msg], params, true) == 0) return 1;
	}
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x,y,z);
	SetPlayerChatBubble(playerid, params, 0xFFFF00FF, 1.2, 5000);
	foreach(new i : Player) {
		if(P[i][_p_in_game] == false) continue;
		if(!IsPlayerInRangeOfPoint(i, 1.2, x,y,z)) continue;
		if(GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)) continue;
		if(GetPlayerInterior(i) != GetPlayerInterior(playerid)) continue;
		if(strlen(params) > 64) {
			new line1[128], line2[128];
			new pos = strfind(params, " ", false, 64);
			if(pos == (-1)) pos = 64;
			strmid(line1, params, 0, pos);
			strmid(line2, params, pos, strlen(params));
			va_SendClientMessage(i, -1, "%s шепчет: %s", IC_Name(playerid),line1);
			va_SendClientMessage(i, -1, "%s%c", line2);
		} else va_SendClientMessage(i, -1, "%s шепчет: %s", IC_Name(playerid),params);
	}
	format(P[playerid][_p_chat_msg], 128, params);
	P[playerid][_p_chat_time] = gettime();
	return true;
}
CMD:me(playerid, params[])
{
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
	if(isnull(params)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /me <действие>");
	if(containsAnyIP(params)) return 1;

	strtolower(params);
	IC_Me(playerid, params);
	return 1;
}

CMD:try(playerid, params[])
{
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
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
	ShowPlayerDialog(playerid, d_player_menu, DIALOG_STYLE_LIST, "Главное меню",
		"Информация о персонаже\n\
		Настройки учётной записи\n\
		Справка о доступных командах\n\
		Справка о правилах сервера\n\
		Обратная связь", "Открыть", "Выход");
	return 1;
}
alias:mn("menu","mm");
CMD:makeleader(playerid, params[])
{
  	new string[115],
    	user,org;
	if(P[playerid][p_access] < 6) return 1;
	if(sscanf(params, "ui", user,org)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /makeleader [ID игрока] [ID Фракции]");
	if(org > 22) return 1;
	if(P[playerid][p_job_team] == org) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Этот игрок уже лидер этой организаций.");
	if(org == 0){
		va_SendClientMessage(user,COLOR_YELLOW,"Вы были сняты %s[%d] с поста лидера \"%s\" ",Name(playerid), playerid, Get_TeamName(user));
		va_SendClientMessage(playerid,COLOR_ORANGE,"Вы сняли лидера %s[%d] организации \"%s\" ",Name(user), user, Get_TeamName(user));
		format(string, 144, "[A] %s[%d] снял %s[%d] с поста лидера организации \"%s\"",Name(playerid), playerid, Name(user), user, Get_TeamName(user));
		Message_ToAdmins(COLOR_GREY, string);
		P[user][p_job_team] = 0;
		P[user][p_rang] = 0;
	}
	else{
		P[user][p_job_team] = org;
		P[user][p_rang] = 10;
		va_SendClientMessage(user,COLOR_YELLOW, "%s[%d] назначил Вас лидером организации \"%s\" ",Name(playerid), playerid, Get_TeamName(user));
		va_SendClientMessage(playerid,COLOR_ORANGE, "Вы назначили игрока %s[%d] на лидерство фракции \"%s\" ",Name(user), user, Get_TeamName(user));
		format(string, 144, "[A] %s[%d] назначил %s[%d] лидером организации \"%s\"",Name(playerid), playerid, Name(user), user, Get_TeamName(user));
		Message_ToAdmins(COLOR_GREY, string);
	}
  	orm_update(P[user][_p_ormid]);
	return 1;
}
CMD:makeadmin(playerid,params[])
{
	new string[144],
	user,level;
	if(P[playerid][p_access] < 6) return true;
	if(sscanf(params,"ui",user,level)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /makeadmin [ID игрока] [Уровень администратирования]");
	if(level > 6) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Уровень администратирования с 1 до 6.");
	P[user][p_access] = level;
	va_SendClientMessage(user,COLOR_YELLOW,"%s[%d] назначил Вас \"%s\"-ом.Поздравляем.",Name(playerid),playerid,Get_AccessName(user));
	va_SendClientMessage(playerid,COLOR_ORANGE,"Вы назначили игрока %s[%d] \"%s\"-ом сервера.",Name(user),user,Get_AccessName(user));//88
	format(string,144,"[A] %s[%d] назначил %s[%d] \"%s\"-ом сервера",Name(playerid),playerid,Name(user),user,Get_AccessName(user));
	Message_ToAdmins(COLOR_GREY,string);
	orm_update(P[user][_p_ormid]);
	return true;
}
CMD:getadmin(playerid,params[]){
	P[playerid][p_access] = 6;
	SendClientMessage(playerid, COLOR_GREY, "Вы дали себе админку 6 lvl");
	return true;
}
CMD:msg(playerid, params[])
{
	if(P[playerid][p_access] < 1) return 1;
	if(sscanf(params, "s[120]", params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /msg [сообщение]");
	va_SendClientMessageToAll(0xFFCD00AA, "Администратор %s: %s",  Name(playerid), params[0]);
	return 1;
}
CMD:kick(playerid, params[])
{
	if(P[playerid][p_access] < 1) return 1;
    if(sscanf(params,"us[64]",params[0], params[1])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /kick [ID игрока] [Причина]");
   	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
    va_SendClientMessageToAll(0xFF5030AA, "Администратор %s кикнул игрока %s. Причина: %s", Name(playerid), Name(params[0]), params[1]);
    Kick(params[0]);
    return 1;
}
CMD:skick(playerid, params[])
{
	if(P[playerid][p_access] < 3) return 1;
	new mes[116];
	if(sscanf(params, "u", params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /skick [ID игрока]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
	format(mes, sizeof(mes),"Администратор %s тихо кикнул игрока %s", Name(playerid), Name(params[0]));
	Message_ToAdmins(0xAFAFAFFF, mes);
	Kick(params[0]);
	return 1;
}
CMD:ans(playerid,params[])
{
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"us[94]",params[0],params[1])) return SendClientMessage(playerid,0xB22222FF, "[Справка]: {FFFFFF}Используйте /ans [ID игрока] [Ответ]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
	va_SendClientMessage(params[0],0xFF9945FF,"Ответ администратора %s[%d]: %s",Name(playerid),playerid,params[1]);
	PlayerPlaySound(params[0], 1085, 0.0, 0.0, 0.0);
	new mes[164];
	format(mes, sizeof(mes),"Администратор %s[%d] для %s[%d]: %s",Name(playerid),playerid,Name(params[0]),params[0],params[1]);
	Message_ToAdmins(0xAFAFAFFF, mes);
	return true;
}
CMD:stats(playerid,params[]){
	Show_PlayerStats(playerid,playerid);
	return true;
}
CMD:lic(playerid, params[])
{
	new user;
	if(sscanf(params,"u",user)) return SendClientMessage(playerid,0xB22222FF, "[Справка]: {FFFFFF}Используйте /lic [ID игрока]");
	if(!IsPlayerConnected(user)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
	if(GetPVarInt(user,"Show_PlayerLic")) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Вы уже предлагаете другому человеку показать свои лицензий.");
	if(playerid != user){
		va_SendClientMessage(playerid,0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы предложили %s показать лицензии.",IC_Name(user));
		va_SendClientMessage(user,0xFFCC66FF,"[Уведомление]: {FFFFFF}%s хочет показать Вам лицензии.",IC_Name(playerid));
		va_SendClientMessage(user,0xB22222FF,"[Справка]: {FFFFFF}Что-бы подтвердить нажмите {007F0E}Y{FFFFFF} для просмотра, {FF0000}N{FFFFFF} для отказа.",IC_Name(playerid));

		SetPVarInt(user,"Show_PlayerLic",playerid+1);
	}
	if(playerid == user){
		Show_PlayerLic(playerid,playerid);
		SetPlayerChatBubble(playerid, "Просматривает свои лицензий", 0xDDA0DDFF, 35.0, 5000);
	}
	printf("User: %s | pvar: %s",Name(user),GetPVarInt(user,"Show_PlayerLic"));
    return 1;
}
alias:lic("licenses","showlicense","showlic");
CMD:gun(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"udd",params[0],params[1],params[2])) return SendClientMessage(playerid,0xB22222FF, "[Справка]: {FFFFFF}Используйте /gun [ID игрока] [ID оружия] [количество патронов]");
	Weapon_Give(params[0],params[1],params[2]);
	return true;
}
CMD:setskin(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"ud",params[0],params[1])) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Используйте /setskin [ID игрока] [ID скина]");
	SetPlayerSkin(params[0], params[1]);
	return true;
}
alias:setskin("ss");
CMD:sethealth(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	new user, health;
	if(sscanf(params,"ui",user,health)) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Используйте /sethealth [ID игрока] [кол. HP]");
	SetPlayerHealth(user,health);
	return true;
}
alias:sethealth("sh");
CMD:sinf(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	new output[128];
	format(output, sizeof(output),"{FFFFFF} Бюджет штата: %.2f",Budget_GOVERNMENT);
	ShowPlayerDialog(playerid, d_null, DIALOG_STYLE_MSGBOX,"Данные об штате",output,"Ок","");
	return true;
}
CMD:a(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"s[64]",params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /a [Текст]");
	new mes[88];
	format(mes, sizeof(mes),"[A] %s[%d]: %s",Name(playerid),playerid,params[0]);
	Message_ToAdmins(0xA7CB44AA, mes);
	return true;
}
CMD:buyfilling(playerid,params[]){
	for(new x; x < sizeof(PS); x++) {
		if(!IsPlayerInRangeOfPoint(playerid, 2.5, PS[x][ps_pos_x],PS[x][ps_pos_y],PS[x][ps_pos_z])) continue;
		if(P[playerid][p_cash] < PS[x][ps_price])
			return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для покупки этого АЗС");
		if(PS[x][ps_owner] == -1)
			return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Бизнес не продается.");
		PS[x][ps_owner] = P[playerid][p_uid];
		orm_update(PS[x][_ps_ormid]);
		va_SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Поздравляю, Вы купили АЗС {FFFFAD}%s",PS[x][ps_name]);
		Cash_Give(playerid, -PS[x][ps_price]);
	}
	return true;
}
CMD:spec(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"u",params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /spec [ID игрока].");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Игрока с таким ID нету в игре.");
	if(params[0] == playerid) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Нельзя следить за собой.");

	SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Что бы выйти из режима слежки нажмите - {4682B4}SPACE");

	if(GetPlayerState(params[0]) == PLAYER_STATE_ONFOOT){
		TogglePlayerSpectating(playerid, 1);
		PlayerSpectatePlayer(playerid, params[0]);
		SetPlayerInterior(playerid,GetPlayerInterior(params[0]));
		SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(params[0]));
		gSpectateID[playerid] = params[0];
		gSpectateType[playerid] = 1;
		StartSpectate(playerid, params[0]);
	}
	else if(GetPlayerState(params[0]) == PLAYER_STATE_PASSENGER || PLAYER_STATE_DRIVER){
		new vehicleid = GetPlayerVehicleID(params[0]);
		TogglePlayerSpectating(playerid, 1);
		PlayerSpectateVehicle(playerid,vehicleid);
		SetPlayerInterior(playerid,GetPlayerInterior(params[0]));
		SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(params[0]));
		gSpectateID[playerid] = params[0];
		gSpectateType[playerid] = 1;
		StartSpectate(playerid, params[0]);
	}
	return true;
}
alias:spec("spectate","recon","rec","re");
CMD:specoff(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	if(gSpectateType[playerid] == 1)
	{
		PlayerTextDrawHide(playerid, P[playerid][SpecText]);
		TogglePlayerSpectating(playerid, 0);
		gSpectateID[playerid] = INVALID_PLAYER_ID;
		gSpectateType[playerid] = 0;
		stop SpectateUpdatePlayer(playerid);
	}
	return true;
}
CMD:ahelp(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Админские команды:");
	SendClientMessage(playerid, -1, "/veh /repair /gotopos /makeleader /makeadmin /goto");
	SendClientMessage(playerid, -1, "/sethp /msg /kick /skick /ans /gun /sinf /a /spec");
	SendClientMessage(playerid, -1, "/specoff");
	return true;
}
alias:ahelp("ah");
CMD:gps(playerid,params[]){
	DisablePlayerCheckpoint(playerid);
	ShowPlayerDialog(playerid, d_player_gps, DIALOG_STYLE_LIST, "Спутниковая Система Навигации",
	"- Найти ближайшую АЗС\n\
	 1. Общественные места\n\
	 2. Работы\n\
	 3. Государственные организации\n\
	 4. Мафий/Баннды\n\
	 5. Банки\n\
	 6. Развлечения\n","Выбрать","Закрыть");
	return true;
}
CMD:getip(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	new output[350];
	if(sscanf(params,"u",params[0])) return SendClientMessage(playerid,0xB22222FF, "[Справка]: {FFFFFF}Используйте /getip [ID игрока].");
	new country_last_ip[64 + 1];
	GetIPCountry(params[0], country_last_ip, sizeof country_last_ip);
	format(output,sizeof(output),"{1C5A8D}Имя:\t\t\t\t\t{FFFFFF}%s\n\
		{1C5A8D}Номер аккаунта:\t\t\t{FFFFFF}%d\n\
		{1C5A8D}Наличные:\t\t\t\t{FFFFFF}$%.2f\n\
		{1C5A8D}Уровень:\t\t\t\t{FFFFFF}%d\n\
		{1C5A8D}IP адресс(регис.):\t\t\t{FFFFFF}%s (%s)\n\
		{1C5A8D}IP адресс(послед.):\t\t\t{FFFFFF}%s (%s)",Name(params[0]),P[params[0]][p_uid],P[params[0]][p_cash],P[params[0]][p_level],
			P[params[0]][p_reg_ip],Get_PlayerRegCountry(params[0]),
			P[params[0]][p_last_ip],Get_PlayerLastIpCountry(params[0]));
	ShowPlayerDialog(playerid, d_null, DIALOG_STYLE_MSGBOX, "Информация об IP игроке", output, "Закрыть","");
	return true;
}
CMD:pay(playerid,params[]){
	new user,money;
	if(sscanf(params,"uf",user,money)) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Используйте /pay [ID игрока] [сумма]");
	if(P[playerid][p_level] < 1) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Данная команда доступна со 2 уровня");
	if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(user)) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Вы находитесь далеко друг от друга");
	if(money < 1 || money > 5000) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Можно передавать от 1$ до 5000$");
	va_SendClientMessage(playerid,-1,"Вы передали %s $%.2f",Name(user),money);
	va_SendClientMessage(user,-1,"%s передал Вам $%.2f",Name(playerid),money);
	Cash_Give(playerid, -money);
	Cash_Give(user, money);
	return true;
}
CMD:cleaner(playerid,params[]){
	switch(P[playerid][p_job_team])
	{
		case JOB_WHITEWING:
		{
			if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Вы должны находится в служебном транспорте.");
			for(new i; i < sizeof(V_WHITEWING); i++){
				new stri[115];
				new string[80];
				format(string,sizeof(string),"{FF8000}Мэрия\t[LS]\t{FFFFFF}— Уровень загрязнения {ff0000}%d %%",Whitewing_[0]); strcat(stri,string);
				ShowPlayerDialog(playerid,d_job_whitewing,DIALOG_STYLE_LIST, "{FF8000}Выберите точку",stri,"Выбрать","Отмена");
			}
		}
		default: return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вам не доступна эта функция.");
	}
	return true;
}
CMD:gnews(playerid,params[]){
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
	if(P[playerid][p_job_team] == 0 || P[playerid][p_job_team] >= 10 && P[playerid][p_job_team] <= 14 || P[playerid][p_job_team] > 18)
		return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Вам не доступна эта функция");
	if(P[playerid][p_rang] < 9) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете использовать эту команду.");
	new text[78];
	if(sscanf(params, "s[78]", text)) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Используйте /gnews [Текст]");
	if(isnull(params)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /gnews [Текст]");
	va_SendClientMessageToAll(0x1554D0FF,"Гос. новости: %s[%d]: %s", Name(playerid), playerid, text);
	return 1;
}
CMD:slap(playerid,params[])
{
	if(P[playerid][p_access] < 1) return true;
	if(sscanf(params,"u",params[0])) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Используйте /slap [ID игрока]");
	new Float:slx, Float:sly, Float:slz;
	GetPlayerPos(params[0], slx, sly, slz);
	SetPlayerPos(params[0], slx, sly, slz+5);
	PlayerPlaySound(params[0], 1130, slx, sly, slz+5);
	Message_ToAdmins(0xAFAFAFFF, "[A] %s[%d] подкинул игрока %s[%d]",Name(playerid),playerid,Name(params[0]),params[0]);
	return true;
}
CMD:r(playerid,params[]){
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
	new text[66];
	if(sscanf(params,"s[66]",text)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /r [Текст]");
	if(P[playerid][p_job_team] == 0 || P[playerid][p_job_team] >= 10 && P[playerid][p_job_team] <= 14 || P[playerid][p_job_team] > 18)
		return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете использовать данную функцию.");
	Message_ToJobTeam(playerid,0x33CC66FF,"[R] %s %s[%d]: %s",Get_RangName(playerid), Name(playerid),playerid,text);
	SetPlayerChatBubble(playerid, "Сообщение по рации", 0xDDA0DDFF, 35.0, 5000);
	return true;
}
CMD:setrang(playerid,params[]){
	new user, rang;
	if(P[playerid][p_job_team] == 0 || P[playerid][p_job_team] > 18) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не можите использовать данную функцию.");
	if(sscanf(params,"ui",user, rang)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /setrang [ID игрока] [Ранг]");
	if(!IsPlayerConnected(user)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
	if(P[playerid][p_job_team] != P[user][p_job_team]) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Этот игрок не состоит в вашей организаций.");
	if(rang < 0 || rang > 10) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Ранг можно устоновлять от 1 до 10");
	if(playerid == user) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не можете самому себе поднять/снизить ранг.");
	va_SendClientMessage(user, 0x0099FFAA, "%s %s назначил Вас на должность \"%s\" ",Get_RangName(playerid),Name(playerid), Get_RangName(user));
	va_SendClientMessage(playerid, 0x0099FFAA, "Вы назначили игрока %s на должность\"%s\" ",Name(user), Get_RangName(user));
	P[user][p_rang] = rang;
	orm_update(P[user][_p_ormid]);
	return true;
}
CMD:invite(playerid,params[]){
	new user;
	if(P[playerid][p_job_team] == 0 || P[playerid][p_rang] < 9) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не уполномочены использовать данную команду.");
	if(sscanf(params,"u",user)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /invite [Frac] [ID игрока] [Rang]");
	if(!IsPlayerConnected(user)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
	if(P[user][p_job_team] >= 1 && P[user][p_job_team] <= 18) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Игрок уже состоит в организаций.");
	if(P[user][p_level] < 3) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Для вступления в организацию у игрока должен быть 3 уровень или выше.");
	P[user][p_job_team] = P[playerid][p_job_team];
	P[user][p_rang] = 1;
	orm_update(P[user][_p_ormid]);
	return true;
}
CMD:uninvite(playerid,params[]){
	new user,reason;
	if(sscanf(params,"us[60]",user,reason)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /uninvite [ID игрока] [Причина]");
	if(!IsPlayerConnected(user)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
	if(P[playerid][p_job_team] >= 1 && P[playerid][p_job_team] < 18) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Вы не состоите во организации.");
	if(P[playerid][p_rang] < 9) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Ваш ранг не достачен для этого.");
	if(P[playerid][p_job_team] != P[user][p_job_team]) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Этот игрок не состоит в вашей организаций.");
	if(P[playerid][p_rang] < P[user][p_rang]) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете уволить человека выше себя рангом.");
	P[user][p_rang] = 0;
	P[user][p_job_team] = 0;
	SetPlayerColor(user, 0xFFFFFF22);
	ResetPlayerWeapons(user);
	va_SendClientMessage(playerid,-1,"%s уволил Вас из организации. Причина: %s",Name(playerid),reason);
	Message_ToComuneTeam(P[playerid][p_job_team],-1,"%s был уволен из организации. Причина: %s",Name(user),reason);
	orm_update(P[user][_p_ormid]);
	return true;
}
CMD:id(playerid,params[]){ //Concept from GTO
    new ids[5];
	if(sscanf(params, "?<MATCH_NAME_PARTIAL=1>u[5]", ids)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /id [ID игрока/Часть Ника]");
	new i, insert_pos, string[265];
	SendClientMessage(playerid, 0xB22222FF,"[Результаты]:");
	while (ids[i] != INVALID_PLAYER_ID)
	{
        if (ids[i] == cellmin)
		{
            SendClientMessage(playerid,0xFFCC66FF,"* {FFFFFF}и другие...");
            break;
        }
		GetPlayerName(ids[i], string, sizeof(string));
		insert_pos = strfind(string, params, true);
		if (insert_pos != -1) {
			strins(string, "{FFFFFF}", strlen(params) + insert_pos);
			strins(string, "{FF8888}", insert_pos);
		}
		va_SendClientMessage(playerid, -1,"%s [%d] [№%i]",string, ids[i],P[i][p_uid]);
		i++;
	}
	if (i == 0) {
		SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Никто не найден");
	}
	return true;
}
CMD:teleport(playerid,params[]){ //concept from GTO
	if(P[playerid][p_access] < 1) return true;
	new subcmd[7], subparams[64];
	if (sscanf(params, "s[7]s[64]", subcmd, subparams)){
		SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /t{FFCC66}[ele]{FFFFFF}p{FFCC66}[ort]{FFFFFF} to [ID игрока/Часть Ника]");
		SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /t{FFCC66}[ele]{FFFFFF}p{FFCC66}[ort]{FFFFFF} here [ID игрока/Часть Ника]");
		SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /t{FFCC66}[ele]{FFFFFF}p{FFCC66}[ort]{FFFFFF} coord <x> <y> <z> <интерьер> <мир>");
		return 1;
	}
	new targetid = INVALID_PLAYER_ID;

	if (sscanf(subparams, "u", targetid)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Игрок не найден");
	new Float:p_pos_x,            Float:t_pos_x,
		Float:p_pos_y,            Float:t_pos_y,
		Float:p_pos_z,            Float:t_pos_z,
		Float:p_pos_a,            Float:t_pos_a,
		p_interior,               t_interior,
		p_world,                  t_world;

	GetPlayerPos(playerid, p_pos_x, p_pos_y, p_pos_z);
	GetPlayerFacingAngle(playerid, p_pos_a);
	p_interior = GetPlayerInterior(playerid);
	p_world = GetPlayerVirtualWorld(playerid);

	if (targetid != -1) {
		GetPlayerPos(targetid, t_pos_x, t_pos_y, t_pos_z);
		GetPlayerFacingAngle(targetid, t_pos_a);
		t_interior = GetPlayerInterior(targetid);
		t_world = GetPlayerVirtualWorld(targetid);
	}
	if(strcmp(subcmd, "to", true) == 0) {
		if (targetid == INVALID_PLAYER_ID || targetid == -1) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Игрок не найден");
		TeleportPlayerToPos(playerid,t_pos_x + random(2) - random(4), t_pos_y + random(2) - random(4), t_pos_z,t_interior, t_world);
		Message_ToAdmins(0xAFAFAFFF, "Администратор %s[%d] телепортировался к %s[%d]", Name(playerid), playerid, Name(targetid), targetid);
	}
	else if(strcmp(subcmd, "here", true) == 0) {
		if (targetid == INVALID_PLAYER_ID) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Игрок не найден");
		TeleportPlayerToPos(targetid, p_pos_x + random(2) - random(4), p_pos_y + random(2) - random(4), p_pos_z, p_interior, p_world);
		Message_ToAdmins(0xAFAFAFFF, "Администратор %s[%d] телепортировал к себе %s[%d]",Name(playerid),playerid,Name(targetid),targetid);
	}
	else if(strcmp(subcmd, "coord", true) == 0) {
		if(sscanf(subparams, "p<,>fffI(0)I(0)", t_pos_x, t_pos_y, t_pos_z, t_interior, t_world)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}/t[ele]p[ort] coord <x> <y> <z> <интерьер> <мир>");
		TeleportPlayerToPos(playerid, t_pos_x, t_pos_y, t_pos_z, t_interior, t_world);
	}
	return true;
}
alias:teleport("tp");
CMD:spawn(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	new user;
	if(sscanf(params,"u",user)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /spawn [ID игрока]");
	SpawnPlayer(user);
	return true;
}
CMD:f(playerid,params[]){
	if(P[playerid][p_mute] >= 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете воспользоваться данной командой, так как у вас мут.");
	new text[66];
	if(sscanf(params,"s[66]",text)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Используйте /f [Текст]");
	if(P[playerid][p_job_team] == 0 || P[playerid][p_job_team] > 18) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не состоите в организаций.");
	Message_ToComuneTeam(P[playerid][p_job_team],0x6699CCFF,"[F] %s %s[%d]: %s",Get_RangName(playerid), Name(playerid),playerid,text);
	SetPlayerChatBubble(playerid, "Сообщение по рации", 0xDDA0DDFF, 35.0, 5000);
	return true;
}
CMD:leaders(playerid,params[]){
	new string[666],str[112];
	str = "{FFFFFF}Организация - Должность - Имя\n\n{FFFFFF}";
	strcat(string, str);
	foreach(new i : Player){
		if(P[i][p_rang] == 10)
	    {
			format(str, sizeof(str), "%s - %s - %s[%d]", Get_TeamName(i), Get_RangName(i), IC_Name(i), i);
			strcat(string, str);
		}
	}
	ShowPlayerDialog(playerid, d_null, DIALOG_STYLE_MSGBOX,"{e2d302}Лидеры онлайн", string, "Закрыть", "");
	return true;
}
CMD:find(playerid,params[]){
	if(P[playerid][p_job_team] == 0 && P[playerid][p_job_team] > 18 || P[playerid][p_rang] == 0) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не состоиты в организаций.");
	new string[666], str[112];
	str = "{FFFFFF}Уровень - Ранг - Имя игрока\n\n";
	strcat(string,str);
	foreach(new i : Player){
		if(P[playerid][p_job_team] != P[i][p_job_team]) continue;
		if(P[i][p_rang] < 1 || P[i][p_rang] < 1) continue;
		format(str, sizeof(str), "%d - %s - %s",P[i][p_level],Get_RangName(i),IC_Name(i));
		strcat(string,str);
	}
	ShowPlayerDialog(playerid, d_null, DIALOG_STYLE_MSGBOX,"Игроков онлайн:",string,"Закрыть","");
	return true;
}
CMD:capture(playerid, params[]){
	if(P[playerid][p_job_team] < 10 || P[playerid][p_job_team] > 14) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не можете начать захват территорий.");
	if(CaptureTime) return va_SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Следующий захват территоий будет доступен через %d минут", CaptureTime);
	if(waractive == true) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Уже идёт захват!");
	new Float:XX,
		Float:YY,
		Float:ZZ;
	GetPlayerPos(playerid, XX, YY, ZZ);
	for(new x = 0; x < 104; x++){
		if((XX <= GZ[x][gz_max_pos_x] && XX >= GZ[x][gz_min_pos_x]) && (YY <= GZ[x][gz_max_pos_y] && YY >= GZ[x][gz_min_pos_y])){
			if(P[playerid][p_job_team]-9 == GZ[x][gz_team]) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не можете начать захватить собственную территорию.");
			if(!Get_GangOnline(GZ[x][gz_team]+9)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Территорию этой банды некому защищать.");
			GangZoneMinuts = GangZoneMinutsDef;
			GangZoneSeconds = 0;
			gangs[0] = P[playerid][p_job_team];
			gangs[1] = GZ[x][gz_team]+9;
			waractive = true;
			zone = x;
			OnSecUpdate();
			GangZoneFlashForAll(zone, 0xFF000090);
			foreach(new i : Player){
				if(P[i][p_job_team] == gangs[0])
					return va_SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FF8888}%s {FFFFFF}напал на территорию {FF8888}%s(№%d){FFFFFF}, помогите ему!", IC_Name(playerid),Get_GangName(gangs[1]),zone);
				if(P[i][p_job_team] == gangs[1])
					return va_SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FF8888}%s {FFFFFF}напали на территорию {FF8888}%s(№%d){FFFFFF}, войну начал: {0095b6}%s",Get_GangName(gangs[0]),Get_GangName(gangs[1]),zone,Name(playerid));
				for(new c; c < 2; c++)
					TextDrawShowForPlayer(i, Capture[c]);
			}
			return true;
		}
	}
	SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не находитесь у какой-либо территорий.");
	return true;
}
CMD:repair(playerid,params[]){
	new user,Float: price;
	if(P[playerid][p_job_team] != 19) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не можете ченить Т.С.");
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 525) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не на рабочем автомобиле.");
	if(sscanf(params,"uf",user,price)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /repair [ID Игрока] [Цена за починку]");
	if(playerid == user) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы не можете починить Т.С. самому себе");
	if(!IsPlayerConnected(user)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Веденный вами ID не найден на сервере");
	if(price < 1 || price > 2000) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Цена за починку автомобиля: 1$ до 2000$");
	if(!IsPlayerInAnyVehicle(user)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Указанный вами игрок не находится в Т.С.");
	if(price > P[user][p_cash]) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У этого человека не достаточно денег для воспользования ваших услуг.");
	va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы предложили %s починить его транспортное средство за $%.2f",IC_Name(user), price);
	va_SendClientMessage(user, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s предлагает вам починить транспортное средство за $%.2f",IC_Name(playerid), price);
	va_SendClientMessage(user, 0xB22222FF, "[Справка]: {FFFFFF}Что-бы подвердить нажмите {007F0E}Y{FFFFFF} для соглашение, {FF0000}N{FFFFFF} для отказа.");
	SetPVarInt(playerid,"id_repair",user + 1);
	SetPVarFloat(playerid,"price_repair", price);
	SetPVarInt(user,"id_repair",playerid + 1);
	return true;
}
CMD:time(playerid,params[]){
	new time[35+9],
		mtext[9+1];
	new year,month,day,
		hour,minute,second;
	getdate(year,month,day);
	gettime(hour,minute,second);
	switch(month)
	{
		case 1: mtext = "January"; 		case 7: mtext = "July";
		case 2: mtext = "February"; 	case 8: mtext = "August";
		case 3: mtext = "March"; 		case 9: mtext = "September";
		case 4: mtext = "April"; 		case 10: mtext = "October";
		case 5: mtext = "May"; 			case 11: mtext = "November";
		case 6: mtext = "June"; 		case 12: mtext = "December";
	}
	if(P[playerid][p_mute] >= 60){
		va_SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Мут истекает через %i минут.",floatround((P[playerid][p_mute] / 60) - (floatround(P[playerid][p_mute] / 3600) * 60)));
	} else if(P[playerid][p_mute] > 0 && P[playerid][p_mute] < 60){
		va_SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Мут истекает через %i секунд.",P[playerid][p_mute]);
	}
	format(time,sizeof(time),"~h~~b~%d:%0d~n~~h~~g~%02d-%s-%d",hour,minute,day,mtext,year);
	GameTextForPlayer(playerid,time,5000,1);
	switch(P[playerid][p_sex]) {
		case SEX_FEMALE: SetPlayerChatBubble(playerid, "Взглянула на часы", 0xDDA0DDFF, 35.0, 5000);
		case SEX_MALE: SetPlayerChatBubble(playerid, "Взглянул на часы", 0xDDA0DDFF, 35.0, 5000);
	}
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_watch",4.1,0,0,0,0,0);
	return true;
}
CMD:eject(playerid,params[]){
	new user;
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Вы должны находится в Т.С.");
	if(sscanf(params,"u",user)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /eject [ID игрока]");
	if(!IsPlayerConnected(user) || playerid == user) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы ввели неверный ID игрока.");
	if(GetPlayerVehicleID(playerid) != GetPlayerVehicleID(user)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Этот игрок находится не в вашем Т.С.");
	va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы выбросили из машини %s", IC_Name(user));
	va_SendClientMessage(user, 0xFFCC66FF, "[Уведомление]: {FFFFFF}%s выбросил вас из Т.С.",IC_Name(playerid));
	RemovePlayerFromVehicle(user);
	return true;
}
CMD:handsup(playerid,params[]){
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
	return true;
}
CMD:givelic(playerid,params[]){
	new user;
	if(P[playerid][p_job_team] != 19) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы не инструктор.");
	if(sscanf(params,"u",user)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /givelic [ID игрока]");
	if(!IsPlayerConnected(user) || playerid == user) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы ввели неверный ID игрока");
	new Float:pos_x,Float:pos_y,Float:pos_z;
	GetPlayerPos(playerid,pos_x,pos_y,pos_z);
	if(!IsPlayerInRangeOfPoint(user,10.0,pos_x,pos_y,pos_z)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Этот человек находится слишком далеко от вас.");
	ShowPlayerDialog(playerid,d_law_sell_lic,DIALOG_STYLE_LIST,"Выдать","Права на легковые автомобили, небольшие грузовики {FFCC66}[B]\n\
	Права на мотоциклы {FFCC66}[A]\n\
	Права на грузовые автомобили + прицеп {FFCC66}[DE]","Закрыть","");
	SetPVarInt(playerid, "give_lic", user);
	return true;
}
CMD:mute(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	new user,time,reason[70];
	if(sscanf(params,"uis[70]",user,time,reason)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /mute [ID игрока] [Количество минут] [Причина]");
	if(!IsPlayerConnected(user) || playerid == user || P[user][p_access] >= 1) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы ввели неверный ID игрока");
	if(P[user][p_mute] > 1) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У этого игрока уже есть мут");
	if(time < 1 || time > 60) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Время мута от 1 до 60 минут");
	P[user][p_mute] = time*60;
	va_SendClientMessageToAll(0xFF8888FF, "Администратор %s выдал бан чата игроку %s на %i минут.Причина: %s", IC_Name(playerid),IC_Name(user),time,reason);
	return true;
}
CMD:unmute(playerid,params[]){
	if(P[playerid][p_access] < 1) return true;
	new user;
	if(sscanf(params,"u",user)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /unmute [ID игрока]");
	if(P[user][p_mute] == 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У этого игрока нету мута");
	if(!IsPlayerConnected(user)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы ввели неверный ID игрока");
	P[user][p_mute] = 0;
	return true;
}
CMD:weap(playerid,params[]){ //concept from GTO
	if(P[playerid][p_access] < 1) return true;
	new user,
		weaponid,amount;
	if(sscanf(params,"u",user)) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Используйте /weap [ID игрока]");
	va_SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Оружие игрока: %s [ID: %d]",Name(user),user);
	for (new slot = 0; slot < 13; slot++) {
		GetPlayerWeaponData(playerid, slot, weaponid, amount);
		if(weaponid == 0) {
			continue;
		}
		va_SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Слот: %d | ID оружия: %d | Кол. патронов: %d",slot, weaponid, amount);
	}
	return true;
}
