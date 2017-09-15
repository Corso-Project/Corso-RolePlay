stock Name_IsValid(const string[])
{
	new earth;
	if(!strcmp(string,"Johhny",true)) return true;
	
	for(new i; i < strlen(string); i++) {
		switch(string[i]) {
		    case 'a'..'z': continue;
		    case 'A'..'Z': continue;
		    case '_': earth++;
			default: return 0;
        }
    }
    if(earth != 1) return 0;
	return 1;
}

stock Message_ToAll(color, const fmat[], va_args<>)
{
	foreach(new i : Player) {
		if (P[i][_p_in_game] == false)
            continue;
		SendClientMessage(i, color, va_return(fmat, va_start<2>));
	}
}

stock Message_ToAdmins(color, const fmat[], va_args<>)
{
    foreach(new i : Player)
        if (P[i][p_access] >= 1)
            SendClientMessage(i, color, va_return(fmat, va_start<2>));
}
stock Message_ToJobTeam(playerid,color, const fmat[], va_args<>)
{
	foreach(new i : Player)
		if (P[playerid][p_job_team] == P[i][p_job_team])
			SendClientMessage(i, color, va_return(fmat, va_start<3>));
}
stock Message_ToComuneTeam(job,color, const fmat[], va_args<>){
	foreach(new i : Player){
		switch(job){
			case 2..5: if(P[i][p_job_team] >= 2 && P[i][p_job_team] <= 5) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			default: if(P[i][p_job_team] == job) SendClientMessage(i, color, va_return(fmat, va_start<3>));
		}
	}
}
stock containsAnyIP(const string[])
{
	new digits, digitGroups;
	for(new pos; ; pos++) {
		switch(string[pos]) {
			case 0: break;
			case '0'..'9', 'o', 'O', 'о', 'О', 'з', 'З': digits++;
			default: {
				if(digits >= 2) {
					digitGroups++;
					digits = 0;
				}
			}
		}
	}
	if(digits >= 2) digitGroups++;
	if(digitGroups >= 4) return 1;
	return 0;
}

stock strtolower(source[])
{
	for(new i; i < strlen(source); i++) switch(source[i]) {
		case 168: source[i] = 184;
		case 192..223: source[i] = (source[i] + 32);
		default: source[i] = tolower(source[i]);
	}
}
// Лифт
stock Elevator_Initialize()
{
	Obj_Elevator 			= CreateDynamicObject(18755, X_ELEVATOR_POS, Y_ELEVATOR_POS, GROUND_Z_COORD, 0.000000, 0.000000, 80.000000);
	Obj_ElevatorDoors[0] 	= CreateDynamicObject(18757, X_ELEVATOR_POS, Y_ELEVATOR_POS, GROUND_Z_COORD, 0.000000, 0.000000, 80.000000);
	Obj_ElevatorDoors[1] 	= CreateDynamicObject(18756, X_ELEVATOR_POS, Y_ELEVATOR_POS, GROUND_Z_COORD, 0.000000, 0.000000, 80.000000);

	Label_Elevator = CreateDynamic3DTextLabel("{CCCCCC}Нажмите '{FFFFFF}~k~~CONVERSATION_YES~{CCCCCC}' чтобы использовать лифт", 0xCCCCCCAA, X_ELEVATOR_POS + 1.6, Y_ELEVATOR_POS - 1.85, GROUND_Z_COORD - 0.4, 4.0,INVALID_PLAYER_ID,INVALID_PLAYER_ID,1);

	new string[128], Float:z;

	for (new i; i < sizeof(Obj_FloorDoors); i ++)
	{
	    // Create elevator floor door objects
	    Obj_FloorDoors[i][0] 	= CreateDynamicObject(18757, X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(i) + 0.05, 0.000000, 0.000000, 80.000000);
		Obj_FloorDoors[i][1] 	= CreateDynamicObject(18756, X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(i) + 0.05, 0.000000, 0.000000, 80.000000);

		format(string, sizeof(string), "{CCCCCC}[%s]\n{CCCCCC}Нажмите '{FFFFFF}~k~~CONVERSATION_YES~{CCCCCC}' для вызова лифта", FloorNames[i]);

		z = GetDoorsZCoordForFloor(i);

		Label_Floors[i] = CreateDynamic3DTextLabel(string, 0xCCCCCCAA, X_ELEVATOR_POS + 2, Y_ELEVATOR_POS -3, z - 0.2, 10.5,INVALID_PLAYER_ID,INVALID_PLAYER_ID,1);
	}
	Floor_OpenDoors(0);
	Elevator_OpenDoors();
	return 1;
}

stock Elevator_Destroy()
{
	DestroyDynamicObject(Obj_Elevator);
	DestroyDynamicObject(Obj_ElevatorDoors[0]);
	DestroyDynamicObject(Obj_ElevatorDoors[1]);
	DestroyDynamic3DTextLabel(Label_Elevator);

	for(new i; i < sizeof(Obj_FloorDoors); i ++)
	{
	    DestroyDynamicObject(Obj_FloorDoors[i][0]);
		DestroyDynamicObject(Obj_FloorDoors[i][1]);
		DestroyDynamic3DTextLabel(Label_Floors[i]);
	}

	return 1;
}

stock Elevator_OpenDoors()
{
	new Float:x, Float:y, Float:z;

	GetDynamicObjectPos(Obj_ElevatorDoors[0], x, y, z);
	MoveDynamicObject(Obj_ElevatorDoors[0], X_DOOR_L_OPENED, Y_DOOR_L_OPENED, z, DOORS_SPEED);
	MoveDynamicObject(Obj_ElevatorDoors[1], X_DOOR_R_OPENED, Y_DOOR_R_OPENED, z, DOORS_SPEED);

	return 1;
}

stock Elevator_CloseDoors()
{
    if(ElevatorState == ELEVATOR_STATE_MOVING)
	    return 0;

    new Float:x, Float:y, Float:z;

	GetDynamicObjectPos(Obj_ElevatorDoors[0], x, y, z);
	MoveDynamicObject(Obj_ElevatorDoors[0], X_ELEVATOR_POS, Y_ELEVATOR_POS, z, DOORS_SPEED);
	MoveDynamicObject(Obj_ElevatorDoors[1], X_ELEVATOR_POS, Y_ELEVATOR_POS, z, DOORS_SPEED);

	return 1;
}

stock Floor_OpenDoors(floorid)
{
    MoveDynamicObject(Obj_FloorDoors[floorid][0], X_FDOOR_L_OPENED, Y_FDOOR_L_OPENED, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);
	MoveDynamicObject(Obj_FloorDoors[floorid][1], X_FDOOR_R_OPENED, Y_FDOOR_R_OPENED, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);

	PlaySoundForPlayersInRange(6401, 50.0, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid) + 5.0);
	return 1;
}

stock Floor_CloseDoors(floorid)
{
    MoveDynamicObject(Obj_FloorDoors[floorid][0], X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);
	MoveDynamicObject(Obj_FloorDoors[floorid][1], X_ELEVATOR_POS, Y_ELEVATOR_POS - 0.245, GetDoorsZCoordForFloor(floorid) + 0.05, DOORS_SPEED);

	PlaySoundForPlayersInRange(6401, 50.0, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid) + 5.0);
	return 1;
}

stock Elevator_MoveToFloor(floorid)
{
	ElevatorState = ELEVATOR_STATE_MOVING;
	ElevatorFloor = floorid;

	MoveDynamicObject(Obj_Elevator, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetElevatorZCoordForFloor(floorid), 0.25);
    MoveDynamicObject(Obj_ElevatorDoors[0], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), 0.25);
    MoveDynamicObject(Obj_ElevatorDoors[1], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), 0.25);
    DestroyDynamic3DTextLabel(Label_Elevator);

	ElevatorBoostTimer = SetTimerEx("Elevator_Boost", 2000, 0, "i", floorid);
	return 1;
}
forward Elevator_Boost(floorid);
public Elevator_Boost(floorid)
{
	StopDynamicObject(Obj_Elevator);
	StopDynamicObject(Obj_ElevatorDoors[0]);
	StopDynamicObject(Obj_ElevatorDoors[1]);

	MoveDynamicObject(Obj_Elevator, X_ELEVATOR_POS, Y_ELEVATOR_POS, GetElevatorZCoordForFloor(floorid), ELEVATOR_SPEED);
    MoveDynamicObject(Obj_ElevatorDoors[0], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), ELEVATOR_SPEED);
    MoveDynamicObject(Obj_ElevatorDoors[1], X_ELEVATOR_POS, Y_ELEVATOR_POS, GetDoorsZCoordForFloor(floorid), ELEVATOR_SPEED);

	return 1;
}
forward Elevator_TurnToIdle();
public Elevator_TurnToIdle()
{
	ElevatorState = ELEVATOR_STATE_IDLE;
	ReadNextFloorInQueue();
	return 1;
}

stock RemoveFirstQueueFloor()
{
	for(new i; i < sizeof(ElevatorQueue) - 1; i ++)
	    ElevatorQueue[i] = ElevatorQueue[i + 1];
	ElevatorQueue[sizeof(ElevatorQueue) - 1] = INVALID_FLOOR;
	return 1;
}

stock AddFloorToQueue(floorid)
{
	new slot = -1;
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    if(ElevatorQueue[i] == INVALID_FLOOR)
	    {
	        slot = i;
	        break;
	    }
	}
	if(slot != -1)
	{
	    ElevatorQueue[slot] = floorid;
	    if(ElevatorState == ELEVATOR_STATE_IDLE)
	        ReadNextFloorInQueue();
	    return 1;
	}
	return 0;
}

stock ResetElevatorQueue()
{
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    ElevatorQueue[i] 	= INVALID_FLOOR;
	    FloorRequestedBy[i] = INVALID_PLAYER_ID;
	}
	return 1;
}

stock IsFloorInQueue(floorid)
{
	for(new i; i < sizeof(ElevatorQueue); i ++)
	    if(ElevatorQueue[i] == floorid)
	        return 1;
	return 0;
}

stock ReadNextFloorInQueue()
{
	if(ElevatorState != ELEVATOR_STATE_IDLE || ElevatorQueue[0] == INVALID_FLOOR)
	    return 0;
	Elevator_CloseDoors();
	Floor_CloseDoors(ElevatorFloor);
	return 1;
}

stock DidPlayerRequestElevator(playerid)
{
	for(new i; i < sizeof(FloorRequestedBy); i ++)
	    if(FloorRequestedBy[i] == playerid)
	        return 1;
	return 0;
}

stock ShowElevatorDialog(playerid)
{
	new string[182+1];
	for(new i; i < sizeof(ElevatorQueue); i ++)
	{
	    if(FloorRequestedBy[i] != INVALID_PLAYER_ID)
	        strcat(string, "{FF0000}");
	    strcat(string, FloorNames[i]);
	    strcat(string, "\n");
	}
	ShowPlayerDialog(playerid, d_elevator_chose_floor, DIALOG_STYLE_LIST, "Выбирите этаж", string, "Выбрать", "Закрыть");
	return 1;
}

stock CallElevator(playerid, floorid)
{
	if(FloorRequestedBy[floorid] != INVALID_PLAYER_ID || IsFloorInQueue(floorid))
	    return 0;
	FloorRequestedBy[floorid] = playerid;
	AddFloorToQueue(floorid);
	return 1;
}
stock Float:GetElevatorZCoordForFloor(floorid)
{
    return (GROUND_Z_COORD + FloorZOffsets[floorid]);
}

stock Float:GetDoorsZCoordForFloor(floorid)
{
	return (GROUND_Z_COORD + FloorZOffsets[floorid]);
}
stock PS_Update3DInfo(x){
	new string[226];
	if(!strcmp(PS[x][ps_owner], "The State")){
		format(string, sizeof(string),
            "Автозаправочная станция:\n{FFFFAD}%s\n\
            Владелец: {99b4ff}Правительство штата{FFFFAD}\n\
            Стоимость: $%m\n\
            Цистерна: %.0f из %d литров\n\
            Цена: $%m за 1 литр бензина\n\
            Заправится: {99b4ff}/fill",
            PS[x][ps_name],PS[x][ps_price],PS[x][ps_volume],FUEL_TANK_LIMIT,PS[x][ps_fuel_price]);
	}else{
		format(string, sizeof(string),
			"Автозаправочная станция:\n{FFFFAD}%s\n\
			Владелец: {99b4ff}%s{FFFFAD}\n\
			Стоимость: $%m\n\
			Цистерна: %.0f из %d литров\n\
			Цена: $%m за 1 литр бензина\n\
			Заправится: {99b4ff}/fill",
			PS[x][ps_name],PS[x][ps_owner],PS[x][ps_price],PS[x][ps_volume],FUEL_TANK_LIMIT,PS[x][ps_fuel_price]);
	}
	UpdateDynamic3DTextLabelText(PS[x][_ps_text3d],0xFFFFFFFF,string);
	return true;
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
FormatSpecifier<'m'>(output[], money) { 
    format(output, sizeof(output), "%i.%i", money / 100, money % 100); 
}
stock Create_Target(){		
	// ammu-nation lv
	target_frame[0] = CreateDynamicObject(3025, 289.498077, -142.043945, 1006.789062, 0.0, 0.0, 90.0, -1,7);

	target_lv_1[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_1[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_1[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_1[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_1[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_1[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_1[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	
	AttachDynamicObjectToObject(target_lv_1[0],target_frame[0],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_1[1],target_frame[0],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_1[2],target_frame[0],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_1[3],target_frame[0],-0.02,0.0059509,0.0395, 0,0,0);
	AttachDynamicObjectToObject(target_lv_1[4],target_frame[0],-0.022,0.0059509,0.044678, 0,0,0);
	AttachDynamicObjectToObject(target_lv_1[5],target_frame[0],-0.02,0.028061,0.046204, 0,0,0);
	AttachDynamicObjectToObject(target_lv_1[6],target_frame[0],-0.02,0.016861,0.046204, 0,0,0);
	
	MoveDynamicObject(target_frame[0],289.498077, -126.685920, 1006.789062,Target_1, 0.000099, 0.0, 90.0);
	LoopStatus[0] = 1;
	
	target_frame[1] = CreateDynamicObject(3025, 284.531585, -142.043945, 1006.789062, 0.0, 0.0, 90.0, -1,7);
	
	target_lv_2[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_2[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_2[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_2[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_2[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_2[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_2[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	
	AttachDynamicObjectToObject(target_lv_2[0],target_frame[1],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_2[1],target_frame[1],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_2[2],target_frame[1],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_2[3],target_frame[1],-0.02,0.0059509,0.0395, 0,0,0);
	AttachDynamicObjectToObject(target_lv_2[4],target_frame[1],-0.022,0.0059509,0.044678, 0,0,0);
	AttachDynamicObjectToObject(target_lv_2[5],target_frame[1],-0.02,0.028061,0.046204, 0,0,0);
	AttachDynamicObjectToObject(target_lv_2[6],target_frame[1],-0.02,0.016861,0.046204, 0,0,0);
	
	MoveDynamicObject(target_frame[1],284.531585, -126.685920, 1006.789062,Target_2, 0.0, 0.0, 90.0);
	LoopStatus[1] = 1;
	
	target_frame[2] = CreateDynamicObject(3025, 278.451599, -142.043945, 1006.789062, 0.0, 0.0, 90.0, -1,7);
	
	target_lv_3[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_3[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_3[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_3[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_3[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_3[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	target_lv_3[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
	
	AttachDynamicObjectToObject(target_lv_3[0],target_frame[2],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_3[1],target_frame[2],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_3[2],target_frame[2],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_lv_3[3],target_frame[2],-0.02,0.0059509,0.0395, 0,0,0);
	AttachDynamicObjectToObject(target_lv_3[4],target_frame[2],-0.022,0.0059509,0.044678, 0,0,0);
	AttachDynamicObjectToObject(target_lv_3[5],target_frame[2],-0.02,0.028061,0.046204, 0,0,0);
	AttachDynamicObjectToObject(target_lv_3[6],target_frame[2],-0.02,0.016861,0.046204, 0,0,0);
	
	MoveDynamicObject(target_frame[2],278.451599, -126.685920, 1006.789062,Target_3, 0.0, 0.0, 90.0);
	LoopStatus[2] = 1;
	
	// ammu-nation central ls
	target_frame[3] = CreateDynamicObject(3025, 285.388122, -18.029937, 1004.186157, 0.0, 0.0, 0.0, -1,1);
	
	target_ls_1[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_1[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_1[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_1[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_1[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_1[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_1[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	
	AttachDynamicObjectToObject(target_ls_1[0],target_frame[3],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_1[1],target_frame[3],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_1[2],target_frame[3],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_1[3],target_frame[3],-0.02,0.0059509,0.0395, 0,0,0);
	AttachDynamicObjectToObject(target_ls_1[4],target_frame[3],-0.022,0.0059509,0.044678, 0,0,0);
	AttachDynamicObjectToObject(target_ls_1[5],target_frame[3],-0.02,0.028061,0.046204, 0,0,0);
	AttachDynamicObjectToObject(target_ls_1[6],target_frame[3],-0.02,0.016861,0.046204, 0,0,0);
	
	MoveDynamicObject(target_frame[3],298.885986, -18.029937, 1004.186157,Target_1, 0.0, 0.0, 0.0);
	LoopStatus[3] = 1;
	
	target_frame[4] = CreateDynamicObject(3025, 285.388122, -12.759922, 1004.186157, 0.0, 0.0, 0.0, -1,1);
	
	target_ls_2[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_2[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_2[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_2[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_2[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_2[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_2[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	
	AttachDynamicObjectToObject(target_ls_2[0],target_frame[4],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_2[1],target_frame[4],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_2[2],target_frame[4],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_2[3],target_frame[4],-0.02,0.0059509,0.0395, 0,0,0);
	AttachDynamicObjectToObject(target_ls_2[4],target_frame[4],-0.022,0.0059509,0.044678, 0,0,0);
	AttachDynamicObjectToObject(target_ls_2[5],target_frame[4],-0.02,0.028061,0.046204, 0,0,0);
	AttachDynamicObjectToObject(target_ls_2[6],target_frame[4],-0.02,0.016861,0.046204, 0,0,0);
	
	MoveDynamicObject(target_frame[4],298.885986, -12.759922, 1004.186157,Target_2, 0.0, 0.0, 0.0);
	LoopStatus[4] = 1;
	
	target_frame[5] = CreateDynamicObject(3025, 285.388122, -7.349909, 1004.186157, 0.0, 0.0, 0.0, -1,1);
	
	target_ls_3[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_3[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_3[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_3[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_3[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_3[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	target_ls_3[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
	
	AttachDynamicObjectToObject(target_ls_3[0],target_frame[5],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_3[1],target_frame[5],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_3[2],target_frame[5],-0.02,0.0059509,0.035522, 0,0,0);
	AttachDynamicObjectToObject(target_ls_3[3],target_frame[5],-0.02,0.0059509,0.0395, 0,0,0);
	AttachDynamicObjectToObject(target_ls_3[4],target_frame[5],-0.022,0.0059509,0.044678, 0,0,0);
	AttachDynamicObjectToObject(target_ls_3[5],target_frame[5],-0.02,0.028061,0.046204, 0,0,0);
	AttachDynamicObjectToObject(target_ls_3[6],target_frame[5],-0.02,0.016861,0.046204, 0,0,0);
	
	MoveDynamicObject(target_frame[5],298.885986, -7.349909, 1004.186157,Target_3, 0.0, 0.0, 0.0);
	LoopStatus[5] = 1;
	
	// Ocean Flats Ammu-Nation
	target_frame[7] = CreateDynamicObject(3025,318.309265, -58.041698, 1004.219421, 0.0, -0.0, -90.0,3,2);
}
stock Update_Target(ammunation){
	switch(ammunation){
		case 1:{
			target_lv_1[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_1[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_1[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_1[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_1[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_1[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_1[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			
			AttachDynamicObjectToObject(target_lv_1[0],target_frame[0],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_1[1],target_frame[0],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_1[2],target_frame[0],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_1[3],target_frame[0],-0.02,0.0059509,0.0395, 0,0,0);
			AttachDynamicObjectToObject(target_lv_1[4],target_frame[0],-0.022,0.0059509,0.044678, 0,0,0);
			AttachDynamicObjectToObject(target_lv_1[5],target_frame[0],-0.02,0.028061,0.046204, 0,0,0);
			AttachDynamicObjectToObject(target_lv_1[6],target_frame[0],-0.02,0.016861,0.046204, 0,0,0);
				
			target_lv_2[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_2[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_2[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_2[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_2[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_2[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_2[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
				
			AttachDynamicObjectToObject(target_lv_2[0],target_frame[1],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_2[1],target_frame[1],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_2[2],target_frame[1],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_2[3],target_frame[1],-0.02,0.0059509,0.0395, 0,0,0);
			AttachDynamicObjectToObject(target_lv_2[4],target_frame[1],-0.022,0.0059509,0.044678, 0,0,0);
			AttachDynamicObjectToObject(target_lv_2[5],target_frame[1],-0.02,0.028061,0.046204, 0,0,0);
			AttachDynamicObjectToObject(target_lv_2[6],target_frame[1],-0.02,0.016861,0.046204, 0,0,0);
			
			target_lv_3[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_3[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_3[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_3[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_3[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_3[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
			target_lv_3[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,90.0, -1,7);
				
			AttachDynamicObjectToObject(target_lv_3[0],target_frame[2],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_3[1],target_frame[2],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_3[2],target_frame[2],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_lv_3[3],target_frame[2],-0.02,0.0059509,0.0395, 0,0,0);
			AttachDynamicObjectToObject(target_lv_3[4],target_frame[2],-0.022,0.0059509,0.044678, 0,0,0);
			AttachDynamicObjectToObject(target_lv_3[5],target_frame[2],-0.02,0.028061,0.046204, 0,0,0);
			AttachDynamicObjectToObject(target_lv_3[6],target_frame[2],-0.02,0.016861,0.046204, 0,0,0);
		}
		case 2:{ // Central Ammu-Nation LS
			target_ls_1[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_1[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_1[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_1[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_1[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_1[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_1[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			
			AttachDynamicObjectToObject(target_ls_1[0],target_frame[3],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_1[1],target_frame[3],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_1[2],target_frame[3],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_1[3],target_frame[3],-0.02,0.0059509,0.0395, 0,0,0);
			AttachDynamicObjectToObject(target_ls_1[4],target_frame[3],-0.022,0.0059509,0.044678, 0,0,0);
			AttachDynamicObjectToObject(target_ls_1[5],target_frame[3],-0.02,0.028061,0.046204, 0,0,0);
			AttachDynamicObjectToObject(target_ls_1[6],target_frame[3],-0.02,0.016861,0.046204, 0,0,0);
			
			target_ls_2[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_2[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_2[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_2[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_2[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_2[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_2[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			
			AttachDynamicObjectToObject(target_ls_2[0],target_frame[4],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_2[1],target_frame[4],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_2[2],target_frame[4],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_2[3],target_frame[4],-0.02,0.0059509,0.0395, 0,0,0);
			AttachDynamicObjectToObject(target_ls_2[4],target_frame[4],-0.022,0.0059509,0.044678, 0,0,0);
			AttachDynamicObjectToObject(target_ls_2[5],target_frame[4],-0.02,0.028061,0.046204, 0,0,0);
			AttachDynamicObjectToObject(target_ls_2[6],target_frame[4],-0.02,0.016861,0.046204, 0,0,0);
	
			target_ls_3[0] = CreateDynamicObject(3024, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_3[1] = CreateDynamicObject(3023, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_3[2] = CreateDynamicObject(3022, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_3[3] = CreateDynamicObject(3021, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_3[4] = CreateDynamicObject(3020, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_3[5] = CreateDynamicObject(3019, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			target_ls_3[6] = CreateDynamicObject(3018, 0.0,0.0,0.0, 0.0,0.0,0.0, -1,1);
			
			AttachDynamicObjectToObject(target_ls_3[0],target_frame[5],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_3[1],target_frame[5],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_3[2],target_frame[5],-0.02,0.0059509,0.035522, 0,0,0);
			AttachDynamicObjectToObject(target_ls_3[3],target_frame[5],-0.02,0.0059509,0.0395, 0,0,0);
			AttachDynamicObjectToObject(target_ls_3[4],target_frame[5],-0.022,0.0059509,0.044678, 0,0,0);
			AttachDynamicObjectToObject(target_ls_3[5],target_frame[5],-0.02,0.028061,0.046204, 0,0,0);
			AttachDynamicObjectToObject(target_ls_3[6],target_frame[5],-0.02,0.016861,0.046204, 0,0,0);
		}
	}
}