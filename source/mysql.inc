forward OnMySQL_SelectAccount(playerid);
public OnMySQL_SelectAccount(playerid)
{
	switch(orm_errno(P[playerid][_p_ormid])) {
	    case ERROR_OK: ShowPlayerDialog(playerid, d_account_login, DIALOG_STYLE_INPUT, "Вход в учётную запись",SERVER_NAME"\n\n{FFFFFF}Введите пароль от своей учётной записи для входа в игру","Вход","Выход");
		case ERROR_NO_DATA: ShowPlayerDialog(playerid, d_account_register, DIALOG_STYLE_INPUT, "Создание учётной записи",SERVER_NAME"\n\n{FFFFFF}Придумайте и введите пароль для создания учётной записи.\nУсловия:\n- От 5 до 18 символов\n- Английские буквы и цифры","Далее","Выход");
	}
	orm_setkey(P[playerid][_p_ormid], "UID");
	GetPlayerIp(playerid, P[playerid][p_last_ip], 46);
}

forward OnMySQL_InsertAccount(playerid);
public OnMySQL_InsertAccount(playerid)
{
	P[playerid][p_mute] = -1;
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
	new string[226];
	new TotalPetrolStations;
	for(new x; x < sizeof(PS); x++) {
	    PS[x][_ps_ormid] = orm_create("petrol_stations");

	    orm_addvar_int(PS[x][_ps_ormid], PS[x][ps_uid], "UID");
	    orm_setkey(PS[x][_ps_ormid], "UID");
	    orm_addvar_string(PS[x][_ps_ormid], PS[x][ps_name], 30, "Name");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_volume], "Volume");
	    orm_addvar_string(PS[x][_ps_ormid], PS[x][ps_owner], 24, "Owner");
		orm_addvar_int(PS[x][_ps_ormid], PS[x][ps_status], "Status");
		orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_price], "Price");
		orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_fuel_price], "Fuel_Price");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_profit], "Profit");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_pos_x], "Pos_X");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_pos_y], "Pos_Y");
	    orm_addvar_float(PS[x][_ps_ormid], PS[x][ps_pos_z], "Pos_Z");

	    orm_apply_cache(PS[x][_ps_ormid], x);

		if(!strcmp(PS[x][ps_owner], "The State")){
			format(string, sizeof(string),
			    "Автозаправочная станция:\n{FFFFAD}%s\n\
			    Владелец: {99b4ff}Правительство штата{FFFFAD}\n\
			    Стоимость: $%.2f\n\
			    Цистерна: %.0f из %d литров\n\
			    Цена: $%.2f за 1 литр бензина\n\
			    Заправится: {99b4ff}/fill",
			    PS[x][ps_name],PS[x][ps_price],PS[x][ps_volume],FUEL_TANK_LIMIT,PS[x][ps_fuel_price]);
		}else{
			format(string, sizeof(string),
			    "Автозаправочная станция:\n{FFFFAD}%s\n\
			    Владелец: {99b4ff}%s{FFFFAD}\n\
			    Стоимость: $%.2f\n\
			    Цистерна: %.0f из %d литров\n\
			    Цена: $%.2f за 1 литр бензина\n\
			    Заправится: {99b4ff}/fill",
			    PS[x][ps_name],PS[x][ps_owner],PS[x][ps_price],PS[x][ps_volume],FUEL_TANK_LIMIT,PS[x][ps_fuel_price]);
		}
		PS[x][_ps_text3d] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, PS[x][ps_pos_x],PS[x][ps_pos_y],PS[x][ps_pos_z]+1,35.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,0,0);
		CreateDynamicMapIcon(PS[x][ps_pos_x],PS[x][ps_pos_y],PS[x][ps_pos_z],47,0xFFFFFFFF,0,0);
		TotalPetrolStations++;
	}
	printf("Загруженно АЗС:%i            [Длительность загрузки: %d ms]",TotalPetrolStations,cache_get_query_exec_time(MILLISECONDS));
}
forward OnMySQL_SelectGangZones();
public OnMySQL_SelectGangZones()
{
	new TotalGangZones;
	for(new x; x < sizeof(GZ); x++) {
		GZ[x][_gz_ormid] = orm_create("gangzones");

		orm_addvar_int(GZ[x][_gz_ormid], GZ[x][gz_uid], "UID");
	    orm_setkey(GZ[x][_gz_ormid], "UID");
	    orm_addvar_float(GZ[x][_gz_ormid], GZ[x][gz_min_pos_x], "Pos_Min_X");
		orm_addvar_float(GZ[x][_gz_ormid], GZ[x][gz_min_pos_y], "Pos_Min_Y");
		orm_addvar_float(GZ[x][_gz_ormid], GZ[x][gz_max_pos_x], "Pos_Max_X");
		orm_addvar_float(GZ[x][_gz_ormid], GZ[x][gz_max_pos_y], "Pos_Max_Y");
	    orm_addvar_int(GZ[x][_gz_ormid], GZ[x][gz_team],"Team");

	    orm_apply_cache(GZ[x][_gz_ormid], x);

		GZ[x][_gz_local] = GangZoneCreate(GZ[x][gz_min_pos_x], GZ[x][gz_min_pos_y], GZ[x][gz_max_pos_x], GZ[x][gz_max_pos_y]);
		TotalGangZones++;
	}
	printf("Загруженно Ганг Зон:%i      [Длительность загрузки: %d ms]",TotalGangZones,cache_get_query_exec_time(MILLISECONDS));
}
forward OnMySQL_SelectGangStorage();
public OnMySQL_SelectGangStorage()
{
	new TotalGangStorage;
	for(new x; x < sizeof(GS); x++){
		GS[x][_g_ormid] = orm_create("gang_storage");

		orm_addvar_int(GS[x][_g_ormid], GS[x][g_uid], "UID");
		orm_setkey(GS[x][_g_ormid], "UID");
		orm_addvar_int(GS[x][_g_ormid], GS[x][g_status],"Status");
		orm_addvar_float(GS[x][_g_ormid], GS[x][g_cash], "Money");
		orm_addvar_int(GS[x][_g_ormid], GS[x][g_patrons],"Patrons");
		orm_addvar_int(GS[x][_g_ormid], GS[x][g_materials],"Materials");

		orm_apply_cache(GS[x][_g_ormid], x);

		TotalGangStorage++;
	}
	printf("Загруженно Общаков:%i         [Длительность загрузки: %d ms]",TotalGangStorage,cache_get_query_exec_time(MILLISECONDS));
}
