stock Vehicle_IsNotForPlayer(vehicleid, playerid)
{
	for(new i; i < sizeof(V_FBI); i++) {
	    if(vehicleid != V_FBI[i]) continue;
	    if(P[playerid][p_job_team] != ORG_FBI) return 1;
	    return 0;
	}
	for(new i; i < sizeof(V_GOVERNMENT); i++) {
		if(vehicleid != V_GOVERNMENT[i]) continue;
		if(P[playerid][p_job_team] != ORG_GOVERNMENT) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_LSPD); i++) {
	    if(vehicleid != V_LSPD[i]) continue;
	    if(P[playerid][p_job_team] != ORG_FBI && P[playerid][p_job_team] != ORG_LSPD) return 1;
	    return 0;
	}
	for(new i; i < sizeof(V_SFPD); i++) {
	    if(vehicleid != V_SFPD[i]) continue;
	    if(P[playerid][p_job_team] != ORG_FBI && P[playerid][p_job_team] != ORG_SFPD) return 1;
	    return 0;
	}
	for(new i; i < sizeof(V_LVPD); i++) {
	    if(vehicleid != V_LVPD[i]) continue;
	    if(P[playerid][p_job_team] != ORG_FBI && P[playerid][p_job_team] != ORG_LVPD) return 1;
	    return 0;
	}
	for(new i; i < sizeof(V_MILITARY); i++) {
	    if(vehicleid != V_MILITARY[i]) continue;
	    if(P[playerid][p_job_team] != ORG_FBI && P[playerid][p_job_team] != ORG_MILITARY) return 1;
	    return 0;
	}
	for(new i; i < sizeof(V_EMERGENCY); i++) {
	    if(vehicleid != V_EMERGENCY[i]) continue;
	    if(P[playerid][p_job_team] != ORG_FBI && P[playerid][p_job_team] != ORG_EMERGENCY) return 1;
	    return 0;
	}
	for(new i; i < sizeof(V_AUTOSCHOOL); i++) {
		if(vehicleid != V_AUTOSCHOOL[i]) continue;
		if(P[playerid][p_job_team] != ORG_FBI && P[playerid][p_job_team] != ORG_AUTOSCHOOL) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_GROVE); i++) {
		if(vehicleid != V_GROVE[i]) continue;
		if(P[playerid][p_job_team] != ORG_GROVE) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_BALLAS); i++) {
		if(vehicleid != V_BALLAS[i]) continue;
		if(P[playerid][p_job_team] != ORG_BALLAS) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_AZTECAS); i++) {
		if(vehicleid != V_AZTECAS[i]) continue;
		if(P[playerid][p_job_team] != ORG_AZTECAS) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_VAGOS); i++) {
		if(vehicleid != V_VAGOS[i]) continue;
		if(P[playerid][p_job_team] != ORG_VAGOS) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_RIFA); i++) {
		if(vehicleid != V_RIFA[i]) continue;
		if(P[playerid][p_job_team] != ORG_RIFA) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_CHINESE); i++){
		if(vehicleid != V_CHINESE[i]) continue;
		if(P[playerid][p_job_team] != ORG_CHINESE) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_TAXI); i++) {
		if(vehicleid != V_TAXI[i]) continue;
		if(P[playerid][p_job_team] != JOB_TAXI) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_ENGINEER); i++) {
		if(vehicleid != V_ENGINEER[i]) continue;
		if(P[playerid][p_job_team] != JOB_ENGINEER) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_FREIGHTER); i++) {
		if(vehicleid != V_FREIGHTER[i]) continue;
		if(P[playerid][p_job_team] != JOB_FREIGHTER) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_WHITEWING); i++){
		if(vehicleid != V_WHITEWING[i]) continue;
		if(P[playerid][p_job_team] != JOB_WHITEWING) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_RENT); i++) {
	    if(vehicleid != V_RENT[i]) continue;
	    if(V_RENT_OWNER[i] != P[playerid][p_uid]) return 1;
	    return 0;
	}
	for(new i; i < sizeof(V_RENT_STANDART); i++) {
		if(vehicleid != V_RENT_STANDART[i]) continue;
		if(V_RENT_OWNER_STANDART[i] != P[playerid][p_uid]) return 1;
		return 0;
	}
	for(new i; i < sizeof(V_RENT_PREMIUM); i++) {
		if(vehicleid != V_RENT_PREMIUM[i]) continue;
		if(V_RENT_OWNER_PREMIUM[i] != P[playerid][p_uid]) return 1;
		return 0;
	}
	return 0;
}

stock Vehicle_GetMaxFuel(vehiclemodel)
{
	switch(vehiclemodel) {
	    // bikes
	    case 448,461..463,468,471,521..523,581,586: return 50;
	    // convertibles
	    case 439,480,533,555: return 75;
	    // industrial
	    case 403,408,413,414,422,440,443,455,456,459,478,482,498,499,514,515,524,531,543,552,554,578,582,600,605,609: return 150;
	    // lowriders
	    case 412,534..536,566,567,575,576: return 75;
	    // off road
	    case 424,568: return 50;
	    case 400,444,470,489,495,500,505,556,557,573,579: return 100;
	    // public service
	    case 407,416,420,427,438,490,528,544,596..599,601: return 75;
	    case 431..433,437: return 150;
	    // saloons
	    case 401,405,410,419,421,426,436,445,466,467,474,491,492,504,507,516..518,526,527,529,540,542,546,547,549..551,560,562,580,585,604: return 75;
	    // sport
	    case 402,411,415,429,451,475,477,494,496,502,503,506,541,558,559,565,587,589,602,603: return 75;
	    // station wagons
	    case 404,418,458,479,561: return 100;
	    // unique
	    case 406,486: return 150;
	    case 409,423,428,434,442,483,508,525,532,545,588: return 75;
	    case 457,485,530,539,571,572,574,583: return 50;
	}
	return 0;
}

stock Vehicle_WithoutFuel(vehiclemodel)
{
	switch(vehiclemodel) {
	    // air vehicles
	    case 417,425,447,460,469,476,487,488,497,511..513,519,520,548,553,563,577,592,593: return 1;
	    // boats
	    case 430,446,452..454,472,473,484,493,595: return 1;
	    // bikes
	    case 481,509,510: return 1;
	    // trailers
	    case 435,450,569,570,584,590,591,606..608,610,611: return 1;
	    // unique
	    case 449,537,538: return 1;
	    // RC
	    case 441,464,465,501,564,594: return 1;
	}
	return 0;
}

stock Vehicle_WithoutDoor(vehiclemodel)
{
	switch(vehiclemodel) {
	    // bikes
	    case 448,461..463,468,471,481,509,510,521..523,581,586: return 1;
	}
	return 0;
}

stock Vehicle_IsPlayerWithLicense(vehiclemodel, playerid)
{
	switch(vehiclemodel) {
	    // moto
	    case 461,463,468,471,521..523,581,586: return P[playerid][p_lic_moto];
	    // car
	    case 400..402,404,405,409,410..412,415,418..422,424,426,429,434,436,438,439,442,444,445,451,458,466,467,470,474,475,477..479,480,483,490..492,494..496,500,502..507,516..518,525..529,533..535,536,540..543,545..547,549..552,554..559,560..562,565..568,575,576,579,580,585,587,589,596..599,600,602..605: return P[playerid][p_lic_car];
	    // freight
	    case 403,406..408,413,414,416,423,427,428,431..433,437,440,443,455,456,459,482,486,498,499,508,514,515,524,531,532,544,573,578,582,588,601,609: return P[playerid][p_lic_freight];
	    // helicopter
	    case 417,425,447,469,487,488,497,563,548: return P[playerid][p_lic_helicopter];
	    // aircraft
	    case 460,476,511..513,519,520,553,577,592,593: return P[playerid][p_lic_aircraft];
	    // boat
	    case 430,446,452..454,472,473,484,493,595: return P[playerid][p_lic_boat];
	    // other
	    default: return 1;
	}
	return 0;
}

stock Vehicle_Add(model, Float:x, Float:y, Float:z, Float:angle, color1 = (-1), color2 = (-1))
{
	new vehicleid = CreateVehicle(model, x,y,z,angle, color1,color2, -1);

	if(vehicleid == INVALID_VEHICLE_ID) return vehicleid;

	new number_plate[7+1];
	format(number_plate,7+1, "%c%c%c%i%c%c",65+random(25),65+random(25),65+random(25),random(99),65+random(25),65+random(25));
    SetVehicleNumberPlate(vehicleid, number_plate);
	
	V[vehicleid][v_fuel] = Vehicle_GetMaxFuel(model);
	Iter_Add(Vehicle, vehicleid);
	return vehicleid;
}

stock Vehicle_Speed(vehicleid)
{
    new Float: x, Float: y, Float: z;
	GetVehicleVelocity(vehicleid, x,y,z);
	new Float: f_KMH = floatsqroot(((x * x) + (y * y)) + (z * z)) * 179.0;
	return floatround(f_KMH);
}
stock GetEngineStat(vehicleid)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
    GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	return engine;
}
