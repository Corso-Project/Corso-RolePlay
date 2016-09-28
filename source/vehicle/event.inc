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
