forward OnMySQL_SelectAccount(playerid);
public OnMySQL_SelectAccount(playerid)
{
	switch(orm_errno(P[playerid][_p_ormid])) {
	    case ERROR_OK: ShowPlayerDialog(playerid, d_account_login, DIALOG_STYLE_PASSWORD, "Вход в учётную запись",SERVER_NAME"\n\n{FFFFFF}Введите пароль от своей учётной записи для входа в игру","Вход","Выход");
	    case ERROR_NO_DATA: ShowPlayerDialog(playerid, d_account_register, DIALOG_STYLE_INPUT, "Создание учётной записи",SERVER_NAME"\n\n{FFFFFF}Придумайте и введите пароль для создания учётной записи.\nУсловия:\n- От 5 до 18 символов\n- Английские буквы и цифры","Далее","Выход");
	}
	orm_setkey(P[playerid][_p_ormid], "UID");
	GetPlayerIp(playerid, P[playerid][p_last_ip], 46);
}

forward OnMySQL_InsertAccount(playerid);
public OnMySQL_InsertAccount(playerid)
{
	orm_load(P[playerid][_p_ormid]);
	TogglePlayerSpectating(playerid, 0);
	SetSpawnInfo(playerid, 0, P[playerid][p_skin], 1642.4329,-2239.0205,13.4967,180.0, 0,0,0,0,0,0);
	P[playerid][p_health] = 100;
	SendClientMessage(playerid, 0xB9C9BFFF, "Создание учётной записи успешно выполнено.");
    SendClientMessage(playerid, 0xB9C9BFFF, "Добро пожаловать, в игру на "SERVER_NAME);
    SendClientMessage(playerid, 0xB9C9BFFF, "Главное меню, клавиша - '{00FF00}~k~~CONVERSATION_NO~{FFFFFF}'");
    SendClientMessage(playerid, 0xB9C9BFFF, "Управление автомобилем, клавиша - '{00FF00}~k~~CONVERSATION_YES~{FFFFFF}'");
}

forward OnMySQL_SelectPetrolStations();
public OnMySQL_SelectPetrolStations()
{
	new ownername[24];
	new string[152];
	new TotalPetrolStations;
	for(new x; x < sizeof(PS); x++) {
	    PS[x][_ps_ormid] = orm_create("petrol_stations");

	    orm_addvar_int(PS[x][_ps_ormid], PS[x][ps_uid], "UID");
	    orm_setkey(PS[x][_ps_ormid], "UID");
	    orm_addvar_string(PS[x][_ps_ormid], PS[x][ps_name], 30, "Name");
	    orm_addvar_int(PS[x][_ps_ormid], PS[x][ps_volume], "Volume");
	    orm_addvar_int(PS[x][_ps_ormid], PS[x][ps_owner], "Owner");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_profit], "Profit");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_pos_x], "Pos_X");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_pos_y], "Pos_Y");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_pos_z], "Pos_Z");

	    orm_apply_cache(PS[x][_ps_ormid], x);

	    switch(PS[x][ps_owner])
		{
		    case 0: ownername = "Правительство штата";
		    default: format(ownername, sizeof(ownername), "UID: %d", PS[x][ps_owner]);
		}
		format(string, sizeof(string),
			"%s\n\
			Владелец: %s\n\
			Цистерна: %d из %d литров\n\
			Цена: $%.2f за 1 литр бензина",
			PS[x][ps_name],ownername,PS[x][ps_volume],FUEL_TANK_LIMIT,Prices_Fuel);
		PS[x][_ps_text3d] = CreateDynamic3DTextLabel(string, 0x4682B4FF, PS[x][ps_pos_x],PS[x][ps_pos_y],PS[x][ps_pos_z]+1,35.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,0,0);
		CreateDynamicMapIcon(PS[x][ps_pos_x],PS[x][ps_pos_y],PS[x][ps_pos_z],47,0xFFFFFFFF,0,0);
		TotalPetrolStations++;
	}
	printf("Загруженно АЗС:%i            [Длительность загрузки: %d ms]",TotalPetrolStations,cache_get_query_exec_time(MILLISECONDS));
}
