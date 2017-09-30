timer OnWeatherChanger[60*60*1000]()
{
	SetWorldTime(g_hour);
	SetWeather(random(20));
	defer OnWeatherChanger[random(60)*60*1000]();
}

timer OnJobDutyEnd[10000](vehicleid, playerid){
	if(P[playerid][p_job_team] == JOB_BUS){
		for(new x; x < sizeof(V_BUS); x++) {
			if(vehicleid != V_BUS[x]) continue;
			if(V_BUS_OWNER[x] == 0 && GetPVarInt(playerid,"Bus_Driver_ID") == 0) return true;
			if((GetPlayerState(playerid) == 2 && IsPlayerInVehicle(playerid,vehicleid)) && P[playerid][p_uid] == V_BUS_OWNER[x] && vehicleid == GetPVarInt(playerid,"Bus_Driver_ID")) return true;
			new cash = GetPVarInt(playerid, "Bus_Route_Cash");
		
			SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы закончили работу.");
			va_SendClientMessageF(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы получили $%m.",cash);
			Cash_Give(playerid,cash);
			
			TogglePlayerDynamicRaceCP(playerid, Bus_Route_CheckPoint,0);
			
			SetPVarInt(playerid, "Bus_Driver_ID",0);
			DeletePVar(playerid,"Bus_Route_CP");
			DeletePVar(playerid, "Bus_Route_To_Go");
			DeletePVar(playerid, "Bus_Route_Cash");
			
			V_BUS_OWNER[x] = 0;
			DestroyDynamic3DTextLabel(text_bus_route[x]);
			SetVehicleToRespawn(vehicleid);
		}
	}
	return true;
}

timer OnRentVehicleEnd[30*60*1000](vehicleid, category)
{
	switch(category) {
	    case ORG_UNKNOWN: {
			for(new i; i < sizeof(V_RENT); i++) {
			  	if(vehicleid != V_RENT[i]) continue;
			    V_RENT_OWNER[i] = 0;
			}
			for(new i; i < sizeof(V_RENT_STANDART); i++) {
				if(vehicleid != V_RENT_STANDART[i]) continue;
				V_RENT_OWNER_STANDART[i] = 0;
			}
			for(new i; i < sizeof(V_RENT_PREMIUM); i++) {
				if(vehicleid != V_RENT_PREMIUM[i]) continue;
				V_RENT_OWNER_PREMIUM[i] = 0;
			}
			new engine,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(vehicleid, 0,lights,alarm,0,bonnet,boot,objective);
		}
		case JOB_TAXI: {
		    for(new i; i < sizeof(V_TAXI); i++) {
			    if(vehicleid != V_TAXI[i]) continue;
			    V_TAXI_OWNER[i] = 0;
			}
			new engine,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(vehicleid, 0,lights,alarm,doors,bonnet,boot,objective);
		}
		case JOB_BUS: {
		    for(new i; i < sizeof(V_BUS); i++) {
			    if(vehicleid != V_BUS[i]) continue;
			    V_BUS_OWNER[i] = 0;
			}
			new engine,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(vehicleid, 0,lights,alarm,doors,bonnet,boot,objective);
		}
		case JOB_ENGINEER: {
		    for(new i; i < sizeof(V_ENGINEER); i++) {
			    if(vehicleid != V_ENGINEER[i]) continue;
			    V_ENGINEER_OWNER[i] = 0;
			}
			new engine,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(vehicleid, 0,lights,alarm,doors,bonnet,boot,objective);
		}
		case JOB_FREIGHTER: {
		    for(new i; i < sizeof(V_FREIGHTER); i++) {
			    if(vehicleid != V_FREIGHTER[i]) continue;
			    V_FREIGHTER_OWNER[i] = 0;
			}
			new engine,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(vehicleid, 0,lights,alarm,doors,bonnet,boot,objective);
		}
	}
}

timer OnGateClosed[7500](objectid)
{
	if(objectid == obj_FBI) {
		obj_state_FBI = false;
		MoveDynamicObject(obj_FBI, -2436.8999, 495.46875, 29.8, MOVE_BARRIER_SPEED, 0.00, 90, 90);
	}
	if(objectid == obj_LSPD) {
		obj_state_LSPD = false;
		MoveDynamicObject(obj_LSPD, 1544.68994, -1630.98999, 13.22000, MOVE_BARRIER_SPEED, 0.00000, 90.00000, 90.00000);
	}
	if(objectid == obj_SFPD[0]) {
		obj_state_SFPD[0] = false;
		MoveDynamicObject(obj_SFPD[0], -1572.19995, 658.63000, 6.98000, MOVE_BARRIER_SPEED, 0.00000, 90.00000, 90.00000);
	}
	if(objectid == obj_SFPD[1]) {
		obj_state_SFPD[1] = false;
		MoveDynamicObject(obj_SFPD[1], -1701.43005, 687.79498, 24.78000, MOVE_BARRIER_SPEED, 0.00000, 90.00000, 270.00000);
	}
	if(objectid == obj_LVPD) {
		obj_state_LVPD = false;
		MoveDynamicObject(obj_LVPD, 2238.18994, 2450.21997, 10.71000, MOVE_BARRIER_SPEED, 0.00000, 90.00000, 90.00000);
	}
	if(objectid == obj_MILITARY[0]) {
		obj_state_MILITARY[0] = false;
		MoveDynamicObject(obj_MILITARY[0], 286.00000, 1822.00000, 20.03000, MOVE_GATE_SPEED, 0.00000, 0.00000, 90.00000);
	}
	if(objectid == obj_MILITARY[1]) {
		obj_state_MILITARY[1] = false;
		MoveDynamicObject(obj_MILITARY[1], 134.85001, 1941.53406, 21.71000, MOVE_GATE_SPEED, 0.00000, 0.00000, 180.00000);
	}
	if(objectid == obj_AUTOSCHOOL[0]){
		obj_state_AUTOSCHOOL[0] = false;
		MoveDynamicObject(obj_AUTOSCHOOL[0], -2057.275634, -94.831848-0.05, 34.890388, 0.03,  0.000000, 90.000000, 270.000000);
	}
}

task OnSecUpdate[1000](){
	foreach(new i : Player)
		if(P[i][_p_in_game] == false) return true;
	if(waractive == true){
		new string[76];
		GangZoneSeconds--;
		if(GangZoneSeconds < 0) {
			GangZoneSeconds = 59;
			GangZoneMinuts--;
			if(GangZoneMinuts < 0) {
				if(gangskills[0] > gangskills[1]){
					foreach(new i: Player){
						if(P[i][p_job_team] == gangs[0]) SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы успешно захватили данную территорию.");
						if(P[i][p_job_team] == gangs[1]) SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы проиграли в защите своей территорий...");
						GZ[zone][gz_team] = gangs[0]-9;
						GangZoneHideForAll(zone);
						GangZoneShowForAll(zone, Get_TeamZoneColor(GZ[zone][gz_team]));
					}
				}else if(gangskills[1] > gangskills[0]){
					foreach(new i: Player){
						if(P[i][p_job_team] == gangs[0]) SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вам не удалось захватить данную территорию.");
						if(P[i][p_job_team] == gangs[1]) SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы защитили свою территорию!");
						GangZoneStopFlashForAll(zone);
					}
				}else if(gangskills[1] == gangskills[0]){
					foreach(new i: Player){
						if(P[i][p_job_team] == gangs[0]) SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Ничья! Попробуйте в следующий раз.");
						if(P[i][p_job_team] == gangs[1]) SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Ничья! Территория остаётся под вашим контролем!");
						GangZoneStopFlashForAll(zone);
					}
				}
				gangs[0] = 0, gangs[1] = 0, gangskills[0] = 0, gangskills[1] = 0;
				waractive = false;
				CaptureTime = TimeForCapt;
				stop OnSecUpdate();
				for(new x; x < 2; x++) TextDrawHideForAll(Capture[x]);
				orm_update(GZ[zone][_gz_ormid]);
				return true;
			}
		}
		format(string, sizeof(string), "       Time: %d:%02d~n~%s~n~%s", GangZoneMinuts,GangZoneSeconds, Get_GangName(gangs[0]), Get_GangName(gangs[1]));
		TextDrawSetString(Capture[0],string);
		foreach(new i : Player)
			TextDrawShowForPlayer(i, Capture[0]);
	}
	return true;
}

timer OnMinUpdate[60000](){
	if(CaptureTime) CaptureTime--;
	return true;
}

task OnUpdateTime[10*1000]()
{
	switch(g_minute) {
	    case 0..58: g_minute++;
	    case 59:{
			switch(g_hour) {
		        case 0..22: {
		            g_hour++;
			        g_minute = 0;
		        }
		        case 23: {
		            g_hour = 0;
		            g_minute = 0;
		        }
			}
		}
	}
}
task PayDay[60*1000]()
{
	new hour, minute, second;
	gettime(hour, minute, second);
	if(minute == 00){
		foreach(new i : Player) {
			// Розыск
			if(P[i][p_wanted_level] != 0){
				P[i][p_wanted_level] -= 1;
				SetPlayerWantedLevel(i, P[i][p_wanted_level]);
			}
			else if(P[i][p_wanted_level] == 0){
				PlayerTextDrawHide(i, Wanted_New_Cash);
				
				new string[16];
				format(string, sizeof(string), "%d Cent", P[i][p_cash] % 100);
				PlayerTextDrawSetString(i, P[i][_p_cent], string);
				PlayerTextDrawShow(i, P[i][_p_cent]);
			}
			// 1200000 milliseconds = 20 min
			if(NetStats_GetConnectedTime(i) < 1200000)
				SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы не получили зарплату так как отыграли меньше 20 минут.");
			else{
				// Уровень
				P[i][p_exp]++;
				if(P[i][p_exp] >= P[i][p_level]*6)
				{
					P[i][p_exp] = 0;
					P[i][p_level]++;
					SetPlayerScore(i, P[i][p_level]);
					va_SendClientMessage(i, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы перешли на %i уровень.",P[i][p_level]);
				}
			}
			orm_update(P[i][_p_ormid]);
			va_SendClientMessage(i,0xB9C9BFFF,"Аккаунт {B1BBBB}%s{B9C9BF} успешно сохранен.",P[i][p_name]);
		}
	}
	return true;
}
task OnSecTimer[1000]()
{
	foreach(new i : Player){
		if(!P[i][_p_in_game]) return 0;
		if(P[i][p_mute] >= 0){
			P[i][p_mute]--;
			if(P[i][p_mute] == 0){
				P[i][p_mute] = -1;
				SendClientMessage(i,0xFFCC66FF,"[Уведомление]: {FFFFFF}Срок мута истёк. Все возможности были восстановлены, пожалуйста, не нарушайте правила сервера больше.");
			}
		}
	}
	return true;
}
timer OnPlayerClearAnimation[500](playerid){
	ClearAnimations(playerid);
}
ptask OnPlayerVehicleFuelSync[1000](playerid)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
		new vehicleid = GetPlayerVehicleID(playerid);
		new engine,lights,alarm,doors,bonnet,boot,objective;
		new KMH = Vehicle_Speed(vehicleid);
		GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
		if(engine == 1) switch(KMH) {
			case 0: V[vehicleid][v_fuel] = floatsub(V[vehicleid][v_fuel], 0.00080);
			default: V[vehicleid][v_fuel] = floatsub(V[vehicleid][v_fuel], (KMH * 0.00099));
		}
		if(Vehicle_WithoutFuel(GetVehicleModel(vehicleid)) == 0) {
			if(V[vehicleid][v_fuel] <= 0) {
				SetVehicleParamsEx(vehicleid, 0,lights,alarm,doors,bonnet,boot,objective);
				SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}В вашем автомобиле закончилось топливо!");
			}
		}
	}
}
