public OnVehicleSpawn(vehicleid)
{
    V[vehicleid][_v_stream_id] = 0;
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
    if(GetPlayerInterior(playerid) == 0) {
		Message_ToAdmins(0xB9C9BFFF, "[Защита]: Модификация машины - %s[%d]", Name(playerid),playerid);
	    Kick(playerid);
        RemoveVehicleComponent(vehicleid, componentid);
        return 0;
    }
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	for(new x; x < sizeof(V_BUS); x++) {
		if(vehicleid != V_BUS[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_BUS_OWNER[x] && vehicleid == GetPVarInt(i,"Bus_Driver_ID")){
				new Float: Bus_Health;
				GetVehicleHealth(vehicleid,Bus_Health);
				if(Bus_Health < 250) return true;
				SendClientMessage(i, 0xB22222FF, "[Справка]: {FFFFFF}У вас есть 10 секунд что-бы вернуться назад в автобус.");
				defer OnJobDutyEnd[10000](GetPVarInt(i,"Bus_Driver_ID"), playerid);
			}
		}
	}
    return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	for(new x; x < sizeof(V_RENT); x++){
		if(vehicleid != V_RENT[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_RENT_OWNER[x]){
				V_RENT_OWNER[x] = 0;
			}
		}
	}
	for(new x; x < sizeof(V_RENT_STANDART); x++){
		if(vehicleid != V_RENT_STANDART[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_RENT_OWNER_STANDART[x]){
				V_RENT_OWNER_STANDART[x] = 0;
			}
		}
	}
	for(new x; x < sizeof(V_RENT_PREMIUM); x++){
		if(vehicleid != V_RENT_PREMIUM[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_RENT_OWNER_PREMIUM[x]){
				V_RENT_OWNER_PREMIUM[x] = 0;
			}
		}
	}
	for(new x; x < sizeof(V_BUS); x++) {
		if(vehicleid != V_BUS[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_BUS_OWNER[x] && vehicleid == GetPVarInt(i,"Bus_Driver_ID")){
				new cash = GetPVarInt(i, "Bus_Route_Cash");
		
				SendClientMessage(i, 0xB22222FF, "[Справка]: {FFFFFF}Вы закончили работу.");
				va_SendClientMessageF(i, 0xB22222FF, "[Справка]: {FFFFFF}Вы получили $%m.",cash);
				Cash_Give(i,cash);
				
				TogglePlayerDynamicRaceCP(i, Bus_Route_CheckPoint,0);
				
				SetPVarInt(i, "Bus_Driver_ID",0);
				V_BUS_OWNER[x] = 0;
				DestroyDynamic3DTextLabel(text_bus_route[x]);
				SetVehicleToRespawn(GetPVarInt(i,"Bus_Driver_ID"));
				
				DeletePVar(i,"Bus_Route_CP");
				DeletePVar(i, "Bus_Route_To_Go");
				DeletePVar(i, "Bus_Route_Cash");
			}
		}
	}
	for(new x; x < sizeof(V_TAXI); x++){
		if(vehicleid != V_TAXI[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_TAXI_OWNER[x]){
				V_TAXI_OWNER[x] = 0;
			}
		}
	}
	for(new x; x < sizeof(V_ENGINEER); x++){
		if(vehicleid != V_ENGINEER[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_ENGINEER_OWNER[x]){
				V_ENGINEER_OWNER[x] = 0;
			}
		}
	}
	for(new x; x < sizeof(V_FREIGHTER); x++){
		if(vehicleid != V_FREIGHTER[x]) continue;
		foreach(new i:Player){
			if(P[i][p_uid] == V_FREIGHTER_OWNER[x]){
				V_FREIGHTER_OWNER[x] = 0;
			}
		}
	}
    return 1;
}