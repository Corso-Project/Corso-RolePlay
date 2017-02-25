public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch(dialogid) {
	// Вход в учётную запись
	case d_account_login: {
	    if(!response) return Kick(playerid);
	    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_account_login, DIALOG_STYLE_PASSWORD, "Вход в учётную запись",SERVER_NAME"\n\n{FFFFFF}Введите пароль от своей учётной записи для входа в игру","Вход","Выход");
	    WP_Hash(inputtext, 129, inputtext);
	    if(strcmp(P[playerid][p_password], inputtext, false) != 0) return ShowPlayerDialog(playerid, d_account_loggin_error, DIALOG_STYLE_MSGBOX, "Ошибка входа","{B22222}Ошибка входа в учётную запись.\nВы ввели неверный пароль!\n\n{FFFFFF}Повторить или покинуть игру?","Повтор","Выход");

	    new year1,month1,day1,
			year2,month2,day2;
	    getdate(year1,month1,day1);
	    sscanf(P[playerid][p_unban_date], "p<->iii", year2,month2,day2);
	    if(year2 >= year1) {
	        if(month2 >= month1) {
	            if(day2 > day1) {
	                new source[256+1];
					format(source, sizeof(source), SERVER_NAME"\n\n{B22222}Учётная запись {FFFFFF}%s {B22222}заблокирована\n\nДата разблокировки: {FFFFFF}%s", Name(playerid),P[playerid][p_unban_date]);
					return ShowPlayerDialog(playerid, d_account_banned, DIALOG_STYLE_MSGBOX, "Учётная запись заблокирована",source,"Выход","");
	            }
	        }
	    }
	    P[playerid][_p_in_game] = true;
	    GivePlayerMoney(playerid, floatround(P[playerid][p_cash]));
	    SetPlayerHealth(playerid, P[playerid][p_health]);
	    TogglePlayerSpectating(playerid, 0);
	    SetSpawnInfo(playerid, 0, P[playerid][p_skin], 1642.4329,-2239.0205,13.4967,180.0, 0,0,0,0,0,0);
        SetPlayerScore(playerid, P[playerid][p_level]);
	    SendClientMessage(playerid, 0xB9C9BFFF, "Вход в учётную запись успешно выполнен.");
	    SendClientMessage(playerid, 0xB9C9BFFF, "Добро пожаловать, в игру на "SERVER_NAME);
	    SendClientMessage(playerid, 0xB9C9BFFF, "Главное меню, клавиша - '{00FF00}~k~~CONVERSATION_NO~{FFFFFF}'");
	    SendClientMessage(playerid, 0xB9C9BFFF, "Управление автомобилем, клавиша - '{00FF00}~k~~CONVERSATION_YES~{FFFFFF}'");
	    if(P[playerid][p_access] > 0)
		{
	        foreach(new i : Player)
			{
	            if(P[i][_p_in_game] == false) continue;
	            if(P[i][p_access] == 0) continue;
				va_SendClientMessage(i, 0xADFF2FFF, "Подключился %s - %s [%d]", Get_AccessName(playerid),Name(playerid),playerid);
	        }
	    }
	}
	// Создание учётной записи
	case d_account_register: {
	    if(!response) return Kick(playerid);
	    if(strlen(inputtext) < 5 || strlen(inputtext) > 18) return ShowPlayerDialog(playerid, d_account_register, DIALOG_STYLE_INPUT, "Создание учётной записи",SERVER_NAME"\n\n{FFFFFF}Придумайте и введите пароль для создания учётной записи.\nУсловия:\n- {B22222}От 5 до 18 символов\n{FFFFFF}- Английские буквы и цифры","Далее","Выход");
	    for(new i; i < strlen(inputtext); i++) switch(inputtext[i]) {
	        case '0'..'9': continue;
	        case 'a'..'z': continue;
	        case 'A'..'Z': continue;
	        default: return ShowPlayerDialog(playerid, d_account_register, DIALOG_STYLE_INPUT, "Создание учётной записи",SERVER_NAME"\n\n{FFFFFF}Придумайте и введите пароль для создания учётной записи.\nУсловия:\n- От 5 до 18 символов\n- {B22222}Английские буквы и цифры","Далее","Выход");
	    }
        ShowPlayerDialog(playerid, d_account_login, DIALOG_STYLE_INPUT, "Создание учётной записи",SERVER_NAME"\n\n{FFFFFF}Придумайте и введите пароль для создания учётной записи.\nУсловия:\n- От 5 до 18 символов\n- Английские буквы и цифры","Далее","Выход");
	    WP_Hash(P[playerid][p_password], 129, inputtext);
	    ShowPlayerDialog(playerid, d_account_choose_sex, DIALOG_STYLE_MSGBOX, "Выбор пола персонажа",SERVER_NAME"\n\n{FFFFFF}Выберите, какой будет пол у вашего персонажа?","Мужской","Женский");
	}
	// Ошибка входа
	case d_account_loggin_error: switch(response)
	{
	    case 0: return Kick(playerid);
	    case 1: return ShowPlayerDialog(playerid, d_account_login, DIALOG_STYLE_PASSWORD, "Вход в учётную запись",SERVER_NAME"\n\n{FFFFFF}Введите пароль от своей учётной записи для входа в игру","Вход","Выход");
	}
	// Выбор пола персонажа
	case d_account_choose_sex: {
	    P[playerid][p_sex] = response;
	    SkinShop_Show(playerid, ORG_UNKNOWN);
	}
	// Имя персонажа | Учётная запись заблокирована
	case d_account_name_error,d_account_banned: Kick(playerid);
	// Управление автомобилем
	case d_vehicle_panel: {
	    new engine,lights,alarm,doors,bonnet,boot,objective;
	    new vehicleid = GetPlayerVehicleID(playerid);
		GetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,boot,objective);
		if(response) switch(listitem) {
		    // двигатель
		    case 0: switch(engine) {
		        case -1,0: {
		            if(Vehicle_IsNotForPlayer(vehicleid, playerid)) return 1;
		            if(Vehicle_IsPlayerWithLicense(GetVehicleModel(vehicleid), playerid) == 0) {
		                return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}У вас нет опыта и лицензии управления данным транспортным средством!");
		            }
		            if(Vehicle_WithoutFuel(GetVehicleModel(vehicleid)) == 0) {
		                if(V[vehicleid][v_fuel] <= 0) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}В автомобиле закончилось топливо!");
		            }
					SetVehicleParamsEx(vehicleid, 1,lights,alarm,doors,bonnet,boot,objective);
		        }
		        case 1: SetVehicleParamsEx(vehicleid, 0,lights,alarm,doors,bonnet,boot,objective);
		    }
		    // фары
		    case 1: switch(lights) {
		        case -1,0: SetVehicleParamsEx(vehicleid, engine,1,alarm,doors,bonnet,boot,objective);
		        case 1: SetVehicleParamsEx(vehicleid, engine,0,alarm,doors,bonnet,boot,objective);
		    }
		    // двери
		    case 2: {
		        if(Vehicle_IsNotForPlayer(vehicleid, playerid)) return 1;
		        if(Vehicle_WithoutDoor(GetVehicleModel(vehicleid)) == 1) return 1;
				switch(doors) {
		        	case -1,0: SetVehicleParamsEx(vehicleid, engine,lights,alarm,1,bonnet,boot,objective);
		        	case 1: SetVehicleParamsEx(vehicleid, engine,lights,alarm,0,bonnet,boot,objective);
		        }
		    }
		    // капот
		    case 3: switch(bonnet) {
		        case -1,0: SetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,1,boot,objective);
		        case 1: SetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,0,boot,objective);
		    }
		    // багажник
		    case 4: switch(boot) {
		        case -1,0: SetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,1,objective);
		        case 1: SetVehicleParamsEx(vehicleid, engine,lights,alarm,doors,bonnet,0,objective);
		    }
		    // автомобильное радио
		    case 5: {
		        new string[512];
		        for(new i; i < sizeof(Streams); i++) strcat(string, Streams[i][0]);
		        ShowPlayerDialog(playerid, d_vehicle_radio, DIALOG_STYLE_LIST, "Автомобильное радио", string, "Выбор","Отмена");
		    }
		    // отцепить трейлер
		    case 6: DetachTrailerFromVehicle(vehicleid);
		}
	}
	// Автомобильное радио
	case d_vehicle_radio: if(response) switch(listitem) {
	    case 0: {
	        new vehicleid = GetPlayerVehicleID(playerid);
			foreach(new i : Player) {
			    if(P[i][_p_in_game] == false) continue;
	        	if(GetPlayerVehicleID(i) != vehicleid) continue;
				StopAudioStreamForPlayer(i);
			}
			V[vehicleid][_v_stream_id] = 0;
	    }
	    case 1: ShowPlayerDialog(playerid, d_vehicle_url_radio, DIALOG_STYLE_INPUT, "Включить свой URL","{FFFFFF}Введите URL-адрес на интернет-поток с музыкой","Включить","Назад");
	    default: {
	        new vehicleid = GetPlayerVehicleID(playerid);
			foreach(new i : Player) {
			    if(P[i][_p_in_game] == false) continue;
	        	if(GetPlayerVehicleID(i) != vehicleid) continue;
				PlayAudioStreamForPlayer(i, Streams[listitem][1]);
			}
			V[vehicleid][_v_stream_id] = listitem;
			format(V[vehicleid][_v_stream_url], 128, Streams[listitem][1]);
	    }
	}
	// Включить свой URL
	case d_vehicle_url_radio: switch(response) {
	    case 0: CallLocalFunction("OnDialogResponse", "dddd", playerid,6,1,5);
	    case 1: {
	        if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_vehicle_url_radio, DIALOG_STYLE_INPUT, "Включить свой URL","{FFFFFF}Введите URL-адрес на интернет-поток с музыкой","Включить","Назад");
	        new vehicleid = GetPlayerVehicleID(playerid);
			foreach(new i : Player) {
			    if(P[i][_p_in_game] == false) continue;
	        	if(GetPlayerVehicleID(i) != vehicleid) continue;
				PlayAudioStreamForPlayer(i, inputtext);
			}
			V[vehicleid][_v_stream_id] = 1;
			format(V[vehicleid][_v_stream_url], 128, inputtext);
	    }
	}
	// Аренда транспорта
	case d_vehicle_rent_car: switch(response) {
	    case 0: RemovePlayerFromVehicle(playerid);
	    case 1: {
	        new minute = strval(inputtext);
	    	if(minute < 1 || minute > 240) {
	    	    SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240");
	            return RemovePlayerFromVehicle(playerid);
	    	}
	        new Float: amount = floatmul(minute, Prices_RentCar_Econom);
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessage(playerid, -1, "Транспортное средство арендовано на %d минут за $%.2f", minute,amount);
	        Cash_Give(playerid, -amount);
	        Budget_GOVERNMENT += amount;
	        for(new i; i < sizeof(V_RENT); i++) {
	            if(V_RENT[i] != GetPlayerVehicleID(playerid)) continue;
	            V_RENT_OWNER[i] = P[playerid][p_uid];
	        	defer OnRentVehicleEnd[minute*60*1000](V_RENT[i], ORG_UNKNOWN);
	        }
	    }
	}
    // Аренда транспорта среднего класса
    case d_vehicle_rent_car_standart: switch(response) {
        case 0: RemovePlayerFromVehicle(playerid);
        case 1: {
            new minute = strval(inputtext);
            if(minute < 1 || minute > 240) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240");
                return RemovePlayerFromVehicle(playerid);
            }
            new Float: amount = floatmul(minute, Prices_RentCar_Standart);
            if(P[playerid][p_cash] < amount) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
                return RemovePlayerFromVehicle(playerid);
            }
            va_SendClientMessage(playerid, -1, "Транспортное средство арендовано на %d минут за $%.2f", minute,amount);
            Cash_Give(playerid, -amount);
            Budget_GOVERNMENT += amount;
            for(new i; i < sizeof(V_RENT_STANDART); i++) {
                if(V_RENT_STANDART[i] != GetPlayerVehicleID(playerid)) continue;
                V_RENT_OWNER[i] = P[playerid][p_uid];
                defer OnRentVehicleEnd[minute*60*1000](V_RENT_STANDART[i], ORG_UNKNOWN);
            }
        }
    }
    // Аренда транспорта премиум класса
    case d_vehicle_rent_car_premium: switch(response) {
        case 0: RemovePlayerFromVehicle(playerid);
        case 1: {
            new minute = strval(inputtext);
            if(minute < 1 || minute > 240) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240");
                return RemovePlayerFromVehicle(playerid);
            }
            new Float: amount = floatmul(minute, Prices_RentCar_Premium);
            if(P[playerid][p_cash] < amount) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
                return RemovePlayerFromVehicle(playerid);
            }
            va_SendClientMessage(playerid, -1, "Транспортное средство арендовано на %d минут за $%.2f", minute,amount);
            Cash_Give(playerid, -amount);
            Budget_GOVERNMENT += amount;
            for(new i; i < sizeof(V_RENT_PREMIUM); i++) {
                if(V_RENT_PREMIUM[i] != GetPlayerVehicleID(playerid)) continue;
                V_RENT_OWNER[i] = P[playerid][p_uid];
                defer OnRentVehicleEnd[minute*60*1000](V_RENT_PREMIUM[i], ORG_UNKNOWN);
            }
        }
    }
	// Аренда такси
	case d_vehicle_rent_taxi: switch(response) {
	    case 0: RemovePlayerFromVehicle(playerid);
	    case 1: {
	        new minute = strval(inputtext);
	        if(minute < 1 || minute > 240) {
	    	    SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240");
	            return RemovePlayerFromVehicle(playerid);
	    	}
	        new Float: amount = floatmul(minute, Prices_RentCar_Econom);
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessage(playerid, -1, "Автомобиль такси арендован на %d минут за $%.2f", minute,amount);
	        Cash_Give(playerid, -amount);
	        Budget_GOVERNMENT += amount;
	        for(new i; i < sizeof(V_TAXI); i++) {
	            if(V_TAXI[i] != GetPlayerVehicleID(playerid)) continue;
	            V_TAXI_OWNER[i] = P[playerid][p_uid];
	        	defer OnRentVehicleEnd[minute*60*1000](V_TAXI[i], JOB_TAXI);
	        }
	    }
	}
	// Аренда служебного транспорта
	case d_vehicle_rent_officecar: switch(response) {
	    case 0: RemovePlayerFromVehicle(playerid);
	    case 1: {
	        new minute = strval(inputtext);
	        if(minute < 1 || minute > 240) {
	    	    SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240");
	            return RemovePlayerFromVehicle(playerid);
	    	}
	        new Float: amount = floatmul(minute, Prices_RentCar_Econom);
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessage(playerid, -1, "Автомобиль такси арендован на %d минут за $%.2f", minute,amount);
	        Cash_Give(playerid, -amount);
	        Budget_GOVERNMENT += amount;
	        for(new i; i < sizeof(V_ENGINEER); i++) {
	            if(V_ENGINEER[i] != GetPlayerVehicleID(playerid)) continue;
	            V_ENGINEER_OWNER[i] = P[playerid][p_uid];
	        	defer OnRentVehicleEnd[minute*60*1000](V_ENGINEER[i], JOB_ENGINEER);
	        }
	    }
	}
	// Аренда грузовика
	case d_vehicle_rent_truck: switch(response)
	{
	    case 0: RemovePlayerFromVehicle(playerid);
	    case 1: {
	        new minute = strval(inputtext);
	        if(minute < 1 || minute > 240) {
	    	    SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240");
	            return RemovePlayerFromVehicle(playerid);
	    	}
	        new Float: amount = floatmul(minute, Prices_RentCar_Econom);
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessage(playerid, -1, "Автомобиль такси арендован на %d минут за $%.2f", minute,amount);
	        Cash_Give(playerid, -amount);
	        Budget_GOVERNMENT += amount;
	        for(new i; i < sizeof(V_FREIGHTER); i++) {
	            if(V_FREIGHTER[i] != GetPlayerVehicleID(playerid)) continue;
	            V_FREIGHTER_OWNER[i] = P[playerid][p_uid];
	        	defer OnRentVehicleEnd[minute*60*1000](V_FREIGHTER[i], JOB_FREIGHTER);
	        }
	    }
	}
    // Мену
	case d_player_menu: if(response) switch(listitem)
	{
	    case 0:Show_PlayerStats(playerid,playerid);
        case 1:ShowPlayerDialog(playerid,d_player_settings, DIALOG_STYLE_LIST,"Настройки учётной записи","Сменить пароль","Выход","");
        case 2:ShowPlayerDialog(playerid, d_null, DIALOG_STYLE_MSGBOX, "Справка о доступных командах", "{FFFFFF}/lock - закрыть/открыть двери автомобиля\n/fill - заправить ТС\n/mn - меню\n/lic - посмотреть список лицензий", "Выход", "");
        case 3:{
            new string[2048];
            for(new msg;msg<sizeof(Server_Rules);msg++)
            {
                strcat(string,Server_Rules[msg]);
            }
            ShowPlayerDialog(playerid,d_null,DIALOG_STYLE_MSGBOX,"Правила сервера",string,"Закрыть","");
        }
        case 4:ShowPlayerDialog(playerid, d_player_report, DIALOG_STYLE_INPUT,"Обратная связь","{FFFFFF}Введите своё сообщение для администрации сервера\nОно должно быть кратким и ясным\n\n{66CC66}Если вы хотите подать жалобу на игрока,\nобязательно укажите его ID и причину жалобы","Отправить","Закрыть");
    }
    case d_player_settings: if(response) switch(listitem){
        case 0:{
            SendClientMessage(playerid, -1, "Сменить пароль");
        }
    }
    case d_player_report:{
        if(!response) return ShowPlayerDialog(playerid, d_player_menu, DIALOG_STYLE_LIST, "Главное меню", "Информация о персонаже\nНастройки учётной записи\nСправка о доступных командах\nСправка о правилах сервера\nОбратная связь", "Открыть", "Выход");
        if(!strlen(inputtext)){
            ShowPlayerDialog(playerid, d_player_report, DIALOG_STYLE_INPUT,"Обратная связть","{FFFFFF}Введите своё сообщение для администрации сервера\nОно должно быть кратким и ясным\n\n{66CC66}Если вы хотите подать жалобу на игрока,\nобязательно укажите его ID и причину жалобы","Отправить","Закрыть");
        }
        if(strlen(inputtext) < 4){
            SendClientMessage(playerid,COLOR_GREY,"Слишком короткий запрос");
            return ShowPlayerDialog(playerid, d_player_report, DIALOG_STYLE_INPUT,"Обратная связть","{FFFFFF}Введите своё сообщение для администрации сервера\nОно должно быть кратким и ясным\n\n{66CC66}Если вы хотите подать жалобу на игрока,\nобязательно укажите его ID и причину жалобы","Отправить","Закрыть");
        }
        va_SendClientMessage(playerid, -1, "{61D765}Сообщение отправлено администраций сервера: {ffffff}%s",inputtext);
        new string[144];
        format(string, 144, "Жалоба от %s [ID:%d]:{ffffff} %s",Name(playerid), playerid, inputtext);
        Message_ToAdmins(COLOR_RED, string);
    }
    // Покупка оружия
	case d_player_buy_gun: if(response) switch(listitem)
    {
		case 0:{
			Weapon_Give(playerid,24,100);
			Cash_Give(playerid, -Prices_Deagle);
            va_SendClientMessage(playerid, -1, "Вы купили Desert Eagle, с 100 патронами за $%.2f",Prices_Deagle);
            new string[16];
            format(string, sizeof(string), "%.0f Cent", floatmul(floatfract(P[playerid][p_cash]), 100.0));
            PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
		}
		case 1:{
			Weapon_Give(playerid,25,100);
			Cash_Give(playerid, -Prices_ShotGun);
            va_SendClientMessage(playerid, -1, "Вы купили ShotGun, с 100 патронами за $%.2f",Prices_ShotGun);
            new string[16];
            format(string, sizeof(string), "%.0f Cent", floatmul(floatfract(P[playerid][p_cash]), 100.0));
            PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
		}
		case 2:{
			Weapon_Give(playerid,28,100);
			Cash_Give(playerid, -Prices_Uzi);
            va_SendClientMessage(playerid, -1, "Вы купили UZI, с 100 патронами за $%.2f",Prices_Uzi);
            new string[16];
            format(string, sizeof(string), "%.0f Cent", floatmul(floatfract(P[playerid][p_cash]), 100.0));
            PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
		}
		case 3:{
			Weapon_Give(playerid,29,100);
			Cash_Give(playerid, -Prices_MP5);
            va_SendClientMessage(playerid, -1, "Вы купили MP5, с 100 патронами за $%.2f",Prices_MP5);
            new string[16];
            format(string, sizeof(string), "%.0f Cent", floatmul(floatfract(P[playerid][p_cash]), 100.0));
            PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
		}
		case 4:{
			Weapon_Give(playerid,33,100);
			Cash_Give(playerid, -Prices_CRifle);
            va_SendClientMessage(playerid, -1, "Вы купили Country Rifle, с 100 патронами за $%.2f",Prices_CRifle);
            new string[16];
            format(string, sizeof(string), "%.0f Cent", floatmul(floatfract(P[playerid][p_cash]), 100.0));
            PlayerTextDrawSetString(playerid, P[playerid][_p_cent], string);
		}
	}
    // Основное меню GPS
    case d_player_gps: if(response) switch(listitem){
        case 0:{
            new min_id;
            new Float:min_distance = 99999.0;
            for (new x; x < sizeof(PS); x++) {
                new Float: distance = GetPlayerDistanceFromPoint(playerid, PS[x][ps_pos_x],PS[x][ps_pos_y],PS[x][ps_pos_z]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_id = x;
                }
            }
            SetPlayerCheckpoint(playerid, PS[min_id][ps_pos_x], PS[min_id][ps_pos_y], PS[min_id][ps_pos_z], 5.0);
            PlayerPlaySound(playerid,1130,0.0,0.0,0.0);
            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Ближайшая заправка была отмечена на радаре.");
        }
        case 1: ShowPlayerDialog(playerid, d_gps_public_places, DIALOG_STYLE_LIST,"Общественные места",
            "1. Автошкола\n\
             2. Автостанция города Лос-Сантос\n\
             3. Авторынок (Эконом класс)\n\
             4. Авторынок (Средний класс)\n\
             5. Авторынок (Премиум класс)\n\
             6. Моторынок","Выбрать","Назад");
        case 2: ShowPlayerDialog(playerid, d_gps_jobs, DIALOG_STYLE_LIST,"Работы",
            "1. Уборщик улиц г.Лос-Сантос\n\
             2. Уборщик улиц г.Сан-Фиеро\n\
             3. Уборщик улиц г.Лас-Вентурас","Выбрать","Назад");
        case 3: ShowPlayerDialog(playerid, d_gps_state_organizations, DIALOG_STYLE_LIST,"Государственные организации",
            "1. Правительство штата\n\
             2. Федеральное Бюро Расследований\n\
             3. Полция города Los Santos\n\
             4. Полиция города San Fiero\n\
             5. Полиция города Las Venturas\n\
             6. Национальная Гвардия\n\
             7. Военно Воздушные Силы\n\
             8. Военно Морской Флот\n\
             9. Служба Экстренной Помощи\n\
             10. Новости 'San Andreas'\n\
             11. Центр Аттестаций\n\
             12. Федеральное Бюро Расследований","Выбрать","Назад");
        case 4: ShowPlayerDialog(playerid, d_gps_criminal_organizaions, DIALOG_STYLE_LIST,"Мафий/Банды",
            "1. Grove Street\n\
             2. Ballas\n\
             3. Aztecas\n\
             4. Vagos\n\
             5. Rifa \n\
             {CCCC66}6. Семья 'Триада'\n\
             {CCCC66}7. Семья 'Воры в законе'\n\
             {CCCC66}8. Семья 'Ла Коза Ностра'","Выбрать","Назад");
        case 5: ShowPlayerDialog(playerid, d_gps_banks, DIALOG_STYLE_LIST,"Банки",
            "1. Банк города Los Santos\n\
             2. Банк города San Fierro\n\
             3. Банк города Las Venturas","Выбрать","Назад");
        case 6: ShowPlayerDialog(playerid, d_gps_pleasure, DIALOG_STYLE_LIST,"Развлечения",
            "1. Казино «Четыре дракона»\n\
             2. Казино «Дворец Калигулы»\n\
             3. Казино «Casino Floor»","Выбрать","Назад");
    }
    // Спутниковая Система Навигации: Общественные места
    case d_gps_public_places: if(response) switch(listitem){
        case 0: SetPlayerCheckpoint(playerid, -2031.4530, -97.4284, 35.1641, 4.0);
        case 1: SetPlayerCheckpoint(playerid, 1811.6638, -1889.9030, 12.9699, 4.0);
        case 2: SetPlayerCheckpoint(playerid, 558.0014, -1257.0792, 16.9318, 4.0);
        case 3: SetPlayerCheckpoint(playerid, -1988.1427, 288.5436, 34.0706, 4.0);
        case 4: SetPlayerCheckpoint(playerid, 1658.5923, 2177.1665, 10.3988, 4.0);
        case 5: SetPlayerCheckpoint(playerid, -2717.8606, 195.2175, 4.3418, 4.0);
    }
    // Спутниковая Система Навигации: Работы
    case d_gps_jobs: if(response) switch(listitem){
        case 0: SetPlayerCheckpoint(playerid, 1622.3394,-1552.2294,13.2362, 4.0);
    }
    // Спутниковая Система Навигации: Государственные организации
    case d_gps_state_organizations: if(response) switch(listitem){
        case 0: SetPlayerCheckpoint(playerid, 1137.3706,-2037.2341,68.5749, 4.0);
        case 1: SetPlayerCheckpoint(playerid, 1292.8685,-1650.4521,12.9523, 4.0);
        case 2: SetPlayerCheckpoint(playerid, 1537.1475,-1675.8947,12.9438, 4.0);
        case 3: SetPlayerCheckpoint(playerid, -1605.4011,724.7184,11.3619, 4.0);
        case 4: SetPlayerCheckpoint(playerid, 2289.8364,2417.6626,10.2683, 4.0);
        case 6: SetPlayerCheckpoint(playerid, -1531.5959,492.3214,6.9068, 4.0);
        case 11: SetPlayerCheckpoint(playerid, -2432.2952,490.2813,29.6579, 4.0);
    }
    // Спутниковая Система Навигации: Развлечения
    case d_gps_pleasure: if(response) switch(listitem){
        case 0: SetPlayerCheckpoint(playerid, 2038.0607,1007.9816,10.2363,4.0);
    }
    // Спутниковая Система Навигации: Банки
    case d_gps_banks: if(response) switch(listitem){
        case 0: SetPlayerCheckpoint(playerid, 1540.4420,-1276.2134,17.1346, 4.0);
        case 1: SetPlayerCheckpoint(playerid, -2650.0825,376.0515,6.1563, 4.0);
        case 2: SetPlayerCheckpoint(playerid, 2359.4534,2377.9929,10.5474, 4.0);
    }
    // Работа: Уборщик улиц
    case d_job_whitewing: if(response) switch(listitem){
        case 0:{
            if(Whitewing_[0] <= 0) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Эта улица не нуждается в отчистке");
            SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Отправляйтесь на очистку улицы");
            Whitewing_GPS[playerid] = SweeperWay_1;
            Whitewinc_CP[0] = CreateDynamicCP(1655.8282,-1579.3132,13.1099,7.0);
        }
    }
    }
    return 1;
}
