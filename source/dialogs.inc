public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	P[playerid][_p_dialog] = false;
    while(strfind(inputtext, "%s",true) !=-1) strdel(inputtext,strfind(inputtext, "%s",true),strfind(inputtext, "%s",true)+2);
	while(strfind(inputtext, "%",true) !=-1) strdel(inputtext,strfind(inputtext, "%",true),strfind(inputtext, "%",true)+2);
    switch(dialogid) {
	// Вход в учётную запись
	case d_account_login: {
	    if(!response) return Kick(playerid);
	    if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_account_login, DIALOG_STYLE_INPUT, "Вход в учётную запись",SERVER_NAME"\n\n{FFFFFF}Введите пароль от своей учётной записи для входа в игру","Вход","Выход");
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
                    Kick(playerid);
					format(source, sizeof(source), SERVER_NAME"\n\n{B22222}Учётная запись {FFFFFF}%s {B22222}заблокирована\n\nДата разблокировки: {FFFFFF}%s", Name(playerid),P[playerid][p_unban_date]);
					return ShowPlayerDialog(playerid, d_account_banned, DIALOG_STYLE_MSGBOX, "Учётная запись заблокирована",source,"Выход","");
	            }
	        }
	    }
	    P[playerid][_p_in_game] = true;
	    GivePlayerMoney(playerid, P[playerid][p_cash]);
	    SetPlayerHealth(playerid, P[playerid][p_health]);
	    TogglePlayerSpectating(playerid, 0);
	    SetSpawnInfo(playerid, 0, P[playerid][p_skin], 1642.4329,-2239.0205,13.4967,180.0, 0,0,0,0,0,0);
        SetPlayerScore(playerid, P[playerid][p_level]);
	    SendClientMessage(playerid, 0xB9C9BFFF, "Вход в учётную запись успешно выполнен.");
	    SendClientMessage(playerid, 0xB9C9BFFF, "Добро пожаловать, в игру на "SERVER_NAME);
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
        if(P[playerid][p_mute] >= 60){
    		va_SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Мут истекает через %i минут.",floatround((P[playerid][p_mute] / 60) - (floatround(P[playerid][p_mute] / 3600) * 60)));
    	} else if(P[playerid][p_mute] > 0 && P[playerid][p_mute] < 60){
    		va_SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}Мут истекает через %i секунд.",P[playerid][p_mute]);
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
		        	case -1,0: {
						SetVehicleParamsEx(vehicleid, engine,lights,alarm,1,bonnet,boot,objective);
						GameTextForPlayer(playerid, "doors~n~~r~locked", 2000, 1);
					}
		        	case 1: {
						SetVehicleParamsEx(vehicleid, engine,lights,alarm,0,bonnet,boot,objective);
						GameTextForPlayer(playerid, "doors ~n~~r~opened", 2000, 1);
					}
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
	    	    SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240.");
	            return RemovePlayerFromVehicle(playerid);
	    	}
	        new amount = minute*Prices_RentCar_Econom;
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта.");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessageF(playerid, -1,"Транспортное средство арендовано на %d минут за $%m.", minute,amount);
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
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240.");
                return RemovePlayerFromVehicle(playerid);
            }
            new amount = minute*Prices_RentCar_Standart;
            if(P[playerid][p_cash] < amount) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта.");
                return RemovePlayerFromVehicle(playerid);
            }
			va_SendClientMessageF(playerid, -1,"Транспортное средство арендовано на %d минут за $%m.", minute,amount); 
            Cash_Give(playerid, -amount);
            Budget_GOVERNMENT += amount;
            for(new i; i < sizeof(V_RENT_STANDART); i++) {
                if(V_RENT_STANDART[i] != GetPlayerVehicleID(playerid)) continue;
                V_RENT_OWNER_STANDART[i] = P[playerid][p_uid];
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
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Количество минут должно быть от 1 до 240.");
                return RemovePlayerFromVehicle(playerid);
            }
            new amount = minute * Prices_RentCar_Premium;
            if(P[playerid][p_cash] < amount) {
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта.");
                return RemovePlayerFromVehicle(playerid);
            }
			va_SendClientMessageF(playerid, -1,"Транспортное средство арендовано на %d минут за $%m.", minute,amount); 
            Cash_Give(playerid, -amount);
            Budget_GOVERNMENT += amount;
            for(new i; i < sizeof(V_RENT_PREMIUM); i++) {
                if(V_RENT_PREMIUM[i] != GetPlayerVehicleID(playerid)) continue;
                V_RENT_OWNER_PREMIUM[i] = P[playerid][p_uid];
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
	        new amount = minute * Prices_RentCar_Econom;
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessageF(playerid, -1,"Транспортное средство арендовано на %d минут за $%m.", minute,amount);
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
	        new amount = minute * Prices_RentCar_Econom;
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessageF(playerid, -1,"Транспортное средство арендовано на %d минут за $%m.", minute,amount);
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
	        new amount = minute * Prices_RentCar_Econom;
	        if(P[playerid][p_cash] < amount) {
	            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
	            return RemovePlayerFromVehicle(playerid);
	        }
	        va_SendClientMessageF(playerid, -1,"Транспортное средство арендовано на %d минут за $%m.", minute,amount);
	        Cash_Give(playerid, -amount);
	        Budget_GOVERNMENT += amount;
	        for(new i; i < sizeof(V_FREIGHTER); i++) {
	            if(V_FREIGHTER[i] != GetPlayerVehicleID(playerid)) continue;
	            V_FREIGHTER_OWNER[i] = P[playerid][p_uid];
	        	defer OnRentVehicleEnd[minute*60*1000](V_FREIGHTER[i], JOB_FREIGHTER);
	        }
            Freighter_Job = CreateDynamicCP(-1034.8696,-617.4734,32.5861,5.0,-1,-1,playerid,20.5);
	    }
	}
    // Мену
	case d_player_menu: if(response) switch(listitem)
	{
	    case 0:Show_PlayerStats(playerid,playerid);
        case 1:ShowPlayerDialog(playerid, d_player_settings, DIALOG_STYLE_LIST,"Настройки учётной записи","Сменить пароль\nСменить русификатор","Выход","");
        case 2:ShowPlayerDialog(playerid, d_null, DIALOG_STYLE_MSGBOX, "Справка о доступных командах", "{FFFFFF}/lock - закрыть/открыть двери автомобиля\n/fill - заправить ТС\n/mn - меню\n/lic - посмотреть список лицензий", "Выход", "");
        case 3:{
            ShowPlayerDialog(playerid, d_null,DIALOG_STYLE_MSGBOX,"Правила сервера",
				"{FFFFFF}Правила игры на сервере.\n\
				{54D5FF}1.{FFFFFF} Revenge Kill (Сокращено RK) запрещён | Warn/Тюрьма на 60 минут\n\
				{54D5FF}2.{FFFFFF} Mеtagаming (Сокращение MG) запрещён | Бан чата 15-60 минут\n\
				{54D5FF}3.{FFFFFF} Powergaming (Сокращение PG) запрещён | Kick/Warn/Тюрьма на 30-60 минут.\n\
				{54D5FF}4.{FFFFFF} Deatmatch (сокращение DM)запрещён. | Kick/Warn/Тюрьма на 60 минут. Последующие нарушения Бан\n\
				{54D5FF}5.{FFFFFF} DriveBy (сокращение DB) запрещён | Тюрьма 30-60 минут,Warn (DB разрешён только пассажирам)\n\
				{54D5FF}6.{FFFFFF} Spawn Kill (Сокращение SK) запрещён |Тюрьма 60 минут,Warn/Бан\n\
				{54D5FF}7.{FFFFFF} Team Kill (Сокращение TK) запрещён | Warn/Бан\n\
				{54D5FF}8.{FFFFFF} Repeat Kill (Сокращение RK) запрещён | Тюрьма 60-120 минут,Warn\n\
				{54D5FF}9.{FFFFFF} FastReload или Scroll (Сокращение FR), а так же Fastmoving (Сокращение FM) запрещён | Warn (Т.к. это багоюз)\n\
				{54D5FF}10.{FFFFFF} Использование Читов/Хаков/Cleo запрещено. | бан на сервере от 10-30 дней до пожизненного.\n\
				{54D5FF}11.{FFFFFF} Нон рп запрещён! | Тюрьма на 60 минут\n\
				{54D5FF}12.{FFFFFF} Использовать аптечки,наркотики во время драки или перестрелки запрещено. | Warn\n\
				{54D5FF}13.{FFFFFF} Флуд в IC и OOC, /s чаты | Бан чата 10-50 минут\n\
				{54D5FF}14.{FFFFFF} Флуд в Репорт, а так же вопросы типа: Можете дать лицензию, деньги, дом, админку | Бан чата 40-100 минут,Kick,Warn\n\
				{54D5FF}15.{FFFFFF} Выход из игры во время RP-процесса | Тюрьма 60-180 минут,Warn\n\
				{54D5FF}16.{FFFFFF} Оскорбление/троллинг/клевета | Бан чата,Kick,Warn,Бан аккаунта\n\
				{54D5FF}17.{FFFFFF} Оскорбление родителей | Бан 15-30 дней\n\
				{54D5FF}18.{FFFFFF} Реклама посторонних ресурсов (серверов, сайтов, читов) | Пожизненный бан\n\n\
				Правила для аккаунтов:\n\
				{5a5fed}1.{FFFFFF} Ваш аккаунт - это ваша собственность и ваша отвественность. За утрату аккаунта (взлом,угон)\n\
				{5a5fed}2.{FFFFFF} Администрация отвественности не несёт и аккаунты игроков не восстанавливает!\n\
				{5a5fed}3.{FFFFFF} Продажа игровых денег,бизнесов,домов и т.д. за реальные деньги карается удалением аккаунта!\n","Закрыть","");
        }
        case 4:ShowPlayerDialog(playerid, d_player_report, DIALOG_STYLE_INPUT,"Обратная связь","{FFFFFF}Введите своё сообщение для администрации сервера\nОно должно быть кратким и ясным\n\n{66CC66}Если вы хотите подать жалобу на игрока,\nобязательно укажите его ID и причину жалобы","Отправить","Закрыть");
    }
    case d_player_settings: if(response) switch(listitem){
        case 0:{
            ShowPlayerDialog(playerid, d_account_change_password, DIALOG_STYLE_INPUT,"Смена пароля учётной записи","{FFFFFF}Введит в поле ниже ваш новый пароль:","Сменить","Назад");
        }
		case 1:{
			for (new i; i < TEXT_RUSSIFIERS_COUNT; i++) { 
				SetPlayerRussifierType(playerid, RussifierType:i); 
				TextDrawShowForPlayer(playerid, Text:TextRusTD[RussifierType:i]); 
			} 
			SelectTextDraw(playerid, 0xAA3333FF); 
		}
    }
    // Репорт
    case d_player_report:{
        if(!response) return ShowPlayerDialog(playerid, d_player_menu, DIALOG_STYLE_LIST, "Главное меню", "Информация о персонаже\nНастройки учётной записи\nСправка о доступных командах\nСправка о правилах сервера\nОбратная связь", "Открыть", "Выход");
        if(!strlen(inputtext)){
            ShowPlayerDialog(playerid, d_player_report, DIALOG_STYLE_INPUT,"Обратная связть","{FFFFFF}Введите своё сообщение для администрации сервера\nОно должно быть кратким и ясным\n\n{66CC66}Если вы хотите подать жалобу на игрока,\nобязательно укажите его ID и причину жалобы","Отправить","Закрыть");
        }
        if(strlen(inputtext) < 4){
            SendClientMessage(playerid,0xAFAFAFAA,"Слишком короткий запрос");
            return ShowPlayerDialog(playerid, d_player_report, DIALOG_STYLE_INPUT,"Обратная связть","{FFFFFF}Введите своё сообщение для администрации сервера\nОно должно быть кратким и ясным\n\n{66CC66}Если вы хотите подать жалобу на игрока,\nобязательно укажите его ID и причину жалобы","Отправить","Закрыть");
        }
        va_SendClientMessage(playerid, -1, "{61D765}Сообщение отправлено администраций сервера: {ffffff}%s",inputtext);
        new string[144];
        format(string, 144, "Жалоба от %s [ID:%d]:{ffffff} %s",Name(playerid), playerid, inputtext);
        Message_ToAdmins(0xAA3333AA, string);
    }
    // Смена пароля
    case d_account_change_password: if(response){
        if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_account_change_password, DIALOG_STYLE_INPUT,"Смена пароля учётной записи","{FFFFFF}Введит в поле ниже ваш новый пароль:","Сменить","Назад");
        if(strlen(inputtext) < 5 || strlen(inputtext) > 18)
            return ShowPlayerDialog(playerid, d_account_change_password, DIALOG_STYLE_INPUT, "Смена пароля учётной записи","{FFFFFF}Введит в поле ниже ваш новый пароль:\nУсловия:\n\t- {B22222}От 5 до 18 символов\n\t{FFFFFF}- Английские буквы и цифры","Далее","Выход");
        for(new i; i < strlen(inputtext); i++) switch(inputtext[i]) {
            case '0'..'9': continue;
            case 'a'..'z': continue;
            case 'A'..'Z': continue;
            default: return ShowPlayerDialog(playerid, d_account_change_password, DIALOG_STYLE_INPUT, "Смена пароля учётной записи","{FFFFFF}Введит в поле ниже ваш новый пароль:\nУсловия:\n\t- От 5 до 18 символов\n\t- {B22222}Английские буквы и цифры","Далее","Выход");
        }
        WP_Hash(P[playerid][p_password], 129, inputtext);
        va_SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы успешно сменили пароль на: {FF8888}%s{FFFFFF}.",inputtext);
        va_SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Рекомендуем сделать скрин (клавиша - F8) что-бы не забыть его.");
        orm_update(P[playerid][_p_ormid]);
    }
    // Покупка оружия
	case d_player_buy_gun: if(response){
		new x = GetPVarInt(playerid, "Ammu_Nation");
		switch(listitem)
		{
			case 0:{
				if(P[playerid][p_cash] < AN[x][an_price_colt45]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,22,30);
				Cash_Give(playerid, -AN[x][an_price_colt45]);
				AN[x][an_profit] += AN[x][an_price_colt45];
			}
			case 1:{
				if(P[playerid][p_cash] < AN[x][an_price_silenced]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,23,30);
				Cash_Give(playerid, -AN[x][an_price_silenced]);
				AN[x][an_profit] += AN[x][an_price_silenced];
			}
			case 2:{
				if(P[playerid][p_cash] < AN[x][an_price_deagle]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,24,15);
				Cash_Give(playerid,-AN[x][an_price_deagle]);
				AN[x][an_profit] += AN[x][an_price_deagle];
			}
			case 3:{
				if(P[playerid][p_cash] < AN[x][an_price_shotgun]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,32,60);
				Cash_Give(playerid, -AN[x][an_price_shotgun]);
				AN[x][an_profit] += AN[x][an_price_shotgun];
			}
			case 4:{
				if(P[playerid][p_cash] < AN[x][an_price_tec9]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,28,60);
				Cash_Give(playerid,-AN[x][an_price_tec9]);
				AN[x][an_profit] += AN[x][an_price_tec9];
			}
			case 5:{
				if(P[playerid][p_cash] < AN[x][an_price_micro_uzi]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,25,15);
				Cash_Give(playerid,-AN[x][an_price_micro_uzi]);
				AN[x][an_profit] += AN[x][an_price_micro_uzi];
			}
			case 6:{
				if(P[playerid][p_cash] < AN[x][an_price_mp5]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,29, 90);
				Cash_Give(playerid,-AN[x][an_price_mp5]);
				AN[x][an_profit] += AN[x][an_price_mp5];
			}
			case 7:{
				if(P[playerid][p_cash] < AN[x][an_price_ak47]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,30,120);
				Cash_Give(playerid,-AN[x][an_price_ak47]);
				AN[x][an_profit] += AN[x][an_price_ak47];
			}
			case 8:{
				if(P[playerid][p_cash] < AN[x][an_price_m4]) return SendClientMessage(playerid,0xB22222FF,"[Справка]: {FFFFFF}У вас не достаточно денег для покупки данного оружия.");
				Weapon_Give(playerid,31,150);
				Cash_Give(playerid,-AN[x][an_price_m4]);
				AN[x][an_profit] += AN[x][an_price_m4];
			}
		}
		orm_update(AN[x][_an_ormid]);
	}
    // Основное меню GPS
    case d_player_gps: if(response) switch(listitem){
        case 0:{
            new min_id;
            new Float:min_distance = 6000.0;
            for (new x; x < sizeof(PS); x++) {
                new Float: distance = GetPlayerDistanceFromPoint(playerid, PS[x][ps_pos_x],PS[x][ps_pos_y],PS[x][ps_pos_z]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_id = x;
                }
            }
            p_gps = CreateDynamicCP(PS[min_id][ps_pos_x], PS[min_id][ps_pos_y], PS[min_id][ps_pos_z],5.0,-1,-1,playerid,6000.0);
            PlayerPlaySound(playerid,1130,0.0,0.0,0.0);
            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Ближайший АЗС была отмечен на радаре.");
        }
        case 1: ShowPlayerDialog(playerid, d_gps_public_places, DIALOG_STYLE_LIST,"Общественные места",
            "1. Автошкола\n\
             2. Автостанция города Лос-Сантос\n\
             3. Авторынок (Эконом класс)\n\
             4. Авторынок (Средний класс)\n\
             5. Авторынок (Премиум класс)\n\
             6. Моторынок","Выбрать","Назад");
        case 2: ShowPlayerDialog(playerid, d_gps_jobs, DIALOG_STYLE_LIST,"Работы",
            "1. Перевозчик топлива","Выбрать","Назад");
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
        case 4: ShowPlayerDialog(playerid, d_gps_banks, DIALOG_STYLE_LIST,"Банки",
            "1. Банк города Los Santos\n\
             2. Банк города San Fierro\n\
             3. Банк города Las Venturas","Выбрать","Назад");
		case 5:{
			new string[341],name[35];
			for(new x;x<sizeof(AN);x++){
				format(name,sizeof(name),"%i. %s\n",x+1,AN[x][an_name]);
				strcat(string,name);
			}
			ShowPlayerDialog(playerid,d_gps_ammu_nations, DIALOG_STYLE_LIST, "Амму-Нации",string,"Выбрать","Назад");
		}
        case 6: ShowPlayerDialog(playerid, d_gps_pleasure, DIALOG_STYLE_LIST,"Развлечения",
            "1. Казино «Четыре дракона»\n\
             2. Казино «Дворец Калигулы»\n\
             3. Казино «Casino Floor»","Выбрать","Назад");
    }
    // Спутниковая Система Навигации: Общественные места
    case d_gps_public_places: if(response) switch(listitem){
        case 0: p_gps = CreateDynamicCP(-2031.4530, -97.4284, 35.1641, 5.0,-1,-1,playerid,6000.0);
        case 1: p_gps = CreateDynamicCP(1811.6638, -1889.9030, 12.9699, 5.0,-1,-1,playerid,6000.0);
        case 2: p_gps = CreateDynamicCP(558.0014, -1257.0792, 16.9318, 5.0,-1,-1,playerid,6000.0);
        case 3: p_gps = CreateDynamicCP(-1988.1427, 288.5436, 34.0706, 5.0,-1,-1,playerid,6000.0);
        case 4: p_gps = CreateDynamicCP(1658.5923, 2177.1665, 10.3988, 5.0,-1,-1,playerid,6000.0);
        case 5: p_gps = CreateDynamicCP(-2717.8606, 195.2175, 4.3418, 5.0,-1,-1,playerid,6000.0);
    }
    // Спутниковая Система Навигации: Работы
    case d_gps_jobs: if(response) switch(listitem){
        case 0: p_gps = CreateDynamicCP(-1034.8696,-617.4734,32.5861, 5.0,-1,-1,playerid,6000.0);
    }
    // Спутниковая Система Навигации: Государственные организации
    case d_gps_state_organizations: if(response) switch(listitem){
        case 0: p_gps = CreateDynamicCP(1137.3706,-2037.2341,68.5749, 5.0,-1,-1,playerid,6000.0);
        case 1: p_gps = CreateDynamicCP(1292.8685,-1650.4521,12.9523, 5.0,-1,-1,playerid,6000.0);
        case 2: p_gps = CreateDynamicCP(1537.1475,-1675.8947,12.9438, 5.0,-1,-1,playerid,6000.0);
        case 3: p_gps = CreateDynamicCP(-1605.4011,724.7184,11.3619, 5.0,-1,-1,playerid,6000.0);
        case 4: p_gps = CreateDynamicCP(2289.8364,2417.6626,10.2683, 5.0,-1,-1,playerid,6000.0);
        case 6: p_gps = CreateDynamicCP(-1531.5959,492.3214,6.9068, 5.0,-1,-1,playerid,6000.0);
        case 11: p_gps = CreateDynamicCP(-2432.2952,490.2813,29.6579, 5.0,-1,-1,playerid,6000.0);
    }
	case d_gps_ammu_nations: if(response){
		new x = listitem;
		p_gps = CreateDynamicCP(AN[x][an_pos_x],AN[x][an_pos_y],AN[x][an_pos_z],4.0,-1,-1,playerid,6000.0);
	}
    // Спутниковая Система Навигации: Казино
    case d_gps_pleasure: if(response) switch(listitem){
        case 0: p_gps = CreateDynamicCP(2038.0607,1007.9816,10.2363,5.0,-1,-1,playerid,6000.0);
    }
    // Спутниковая Система Навигации: Банки
    case d_gps_banks: if(response) switch(listitem){
        case 0: p_gps = CreateDynamicCP(1540.4420,-1276.2134,17.1346, 5.0,-1,-1,playerid,6000.0);
        case 1: p_gps = CreateDynamicCP(-2650.0825,376.0515,6.1563, 5.0,-1,-1,playerid,6000.0);
        case 2: p_gps = CreateDynamicCP(2359.4534,2377.9929,10.5474, 5.0,-1,-1,playerid,6000.0);
    }
    // АШ
    case d_law_test:{
        if(!response){
            SendClientMessage(playerid, 0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы прекратили теоретическую сдачу ПДД.");
            DeletePVar(playerid, "answer_true");
            return 0;
        }
        new ans_true = GetPVarInt(playerid,"answer_true");
        if(ans_true == 0){
            switch(listitem){
                case 0:{
                    new lawstring[256];
                    format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[0],Traffic_Laws_ExamAnswers[0][0],Traffic_Laws_ExamAnswers[0][1],Traffic_Laws_ExamAnswers[0][2],Traffic_Laws_ExamAnswers[0][3]);
                    ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Закрыть");
                }
                case 1:if(Traffic_Laws_ExamAnswers[0][0][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
                case 2:if(Traffic_Laws_ExamAnswers[0][1][e_exam_is_answer]){
                    new lawstring[256];
                    format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[1],Traffic_Laws_ExamAnswers[1][0],Traffic_Laws_ExamAnswers[1][1],Traffic_Laws_ExamAnswers[1][2],Traffic_Laws_ExamAnswers[1][3]);
                    ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Закрыть");
                    SetPVarInt(playerid, "answer_true", 1);
                }
                case 3:if(Traffic_Laws_ExamAnswers[0][2][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
                case 4:if(Traffic_Laws_ExamAnswers[0][3][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
            }
        }
        else if(ans_true == 1){
            switch(listitem){
                case 0:{
                    new lawstring[256];
                    format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[1],Traffic_Laws_ExamAnswers[1][0],Traffic_Laws_ExamAnswers[1][1],Traffic_Laws_ExamAnswers[1][2],Traffic_Laws_ExamAnswers[1][3]);
                    ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Закрыть");
                }
                case 1:if(Traffic_Laws_ExamAnswers[1][0][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
                case 2:if(Traffic_Laws_ExamAnswers[1][1][e_exam_is_answer]){
                    new lawstring[256];
                    format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[2],Traffic_Laws_ExamAnswers[2][0],Traffic_Laws_ExamAnswers[2][1],Traffic_Laws_ExamAnswers[2][2],Traffic_Laws_ExamAnswers[2][3]);
                    ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Закрыть");
                    SetPVarInt(playerid, "answer_true", 2);
                }
                case 3:if(Traffic_Laws_ExamAnswers[1][2][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
                case 4:if(Traffic_Laws_ExamAnswers[1][3][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
            }
        }
        else if(ans_true == 2){
            switch(listitem){
                case 0:{
                    new lawstring[256];
                    format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[2],Traffic_Laws_ExamAnswers[2][0],Traffic_Laws_ExamAnswers[2][1],Traffic_Laws_ExamAnswers[2][2],Traffic_Laws_ExamAnswers[2][3]);
                    ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Закрыть");
                }
                case 1:if(Traffic_Laws_ExamAnswers[2][0][e_exam_is_answer]){
                    new lawstring[256];
                    format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[3],Traffic_Laws_ExamAnswers[3][0],Traffic_Laws_ExamAnswers[3][1],Traffic_Laws_ExamAnswers[3][2],Traffic_Laws_ExamAnswers[3][3]);
                    ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Закрыть");
                    SetPVarInt(playerid, "answer_true", 3);
                }
                case 2:if(Traffic_Laws_ExamAnswers[2][1][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
                case 3:if(Traffic_Laws_ExamAnswers[2][2][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
                case 4:if(Traffic_Laws_ExamAnswers[2][3][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                    DeletePVar(playerid, "answer_true");
                }
            }
        }
        else if(ans_true == 3){
            switch(listitem){
                case 0:{
                    new lawstring[256];
                    format(lawstring,sizeof(lawstring),"%s\n%s\n%s\n%s\n%s\n%s",Traffic_Laws_ExamQuestions[3],Traffic_Laws_ExamAnswers[3][0],Traffic_Laws_ExamAnswers[3][1],Traffic_Laws_ExamAnswers[3][2],Traffic_Laws_ExamAnswers[3][3]);
                    ShowPlayerDialog(playerid,d_law_test,DIALOG_STYLE_LIST,"Теориетическая сдача ПДД",lawstring,"Выбрать","Закрыть");
                }
                case 1:if(Traffic_Laws_ExamAnswers[3][0][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                }
                case 2:if(Traffic_Laws_ExamAnswers[3][1][e_exam_is_answer]){
                    SendClientMessage(playerid,-1,"Поздравляем, вы успешно сдали экзамен!");
                    P[playerid][p_lic_car] = 1;
                    orm_update(P[playerid][_p_ormid]);
                }
                case 3:if(Traffic_Laws_ExamAnswers[3][2][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                }
                case 4:if(Traffic_Laws_ExamAnswers[3][3][e_exam_is_answer]){
                    va_SendClientMessage(playerid, -1,"Вы не сдали экзамен, попробуйте через 30 минут.");
                }
            }
        }
    }
    case d_elevator_chose_floor:{
        if(!response)
            return 0;
        if(FloorRequestedBy[listitem] != INVALID_PLAYER_ID || IsFloorInQueue(listitem))
            GameTextForPlayer(playerid, "~r~В очереди уже находится ~h~~g~нижний этаж", 3500, 4);
        else if(DidPlayerRequestElevator(playerid))
            GameTextForPlayer(playerid, "~r~Вы уже выбрали этаж", 3500, 4);
        else
            CallElevator(playerid, listitem);
        return 1;
    }
    case d_law_sell_lic:{
        if(!response) return DeletePVar(playerid,"give_lic");
        new user = GetPVarInt(playerid,"give_lic");
        switch(listitem){
            case 0:{
                if(P[user][p_lic_car] == 1) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У этого человека уже есть лицензия на вождение лёгково Т.С.");
                if(P[user][p_cash] < 1000) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У данного человека нету денег для покупки лицензий.");
                va_SendClientMessage(playerid,0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы предложили %s купить водительские права.",IC_Name(user));
                va_SendClientMessage(user,0xFFCC66FF,"[Уведомление]: {FFFFFF}%s предлагает вам купить водительские права за {FF8888}1000${FFFFFF}.",IC_Name(playerid));
                va_SendClientMessage(user,0xB22222FF,"[Справка]: {FFFFFF}Что-бы подтвердить покупку нажмите {007F0E}Y{FFFFFF}, {FF0000}N{FFFFFF} для отказа.");
                SetPVarInt(user,"Buy_License_B",1);
            }
            case 1:{
                if(P[user][p_lic_moto] == 1) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У этого человека уже есть права на вождение мотоцикла.");
                if(P[user][p_cash] < 2000) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У даннного человека нету денег для покупки лицензий.");
                va_SendClientMessage(playerid,0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы предложили %s купить права на вождение мотоцикла.",IC_Name(user));
                va_SendClientMessage(user,0xFFCC66FF,"[Уведомление]: {FFFFFF}%s предлагает вам купить права на вождение мотоцикла за {FF8888}2000${FFFFFF}.",IC_Name(playerid));
                va_SendClientMessage(user,0xB22222FF,"[Справка]: {FFFFFF}Что-бы подтвердить покупку нажмите {007F0E}Y{FFFFFF}, {FF0000}N{FFFFFF} для отказа.");
                SetPVarInt(user,"Buy_License_A",1);
            }
            case 2:{
                if(P[user][p_lic_freight] == 1) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У этого человека уже есть права на вождение грузовика.");
                if(P[user][p_cash] < 5000) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}У даннного человека нету денег для покупки лицензий.");
                va_SendClientMessage(playerid,0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы предложили %s купить права на вождение грузовика.",IC_Name(user));
                va_SendClientMessage(user,0xFFCC66FF,"[Уведомление]: {FFFFFF}%s предлагает вам купить права на вождение грузовика за {FF8888}5000${FFFFFF}.",IC_Name(playerid));
                va_SendClientMessage(user,0xB22222FF,"[Справка]: {FFFFFF}Что-бы подтвердить покупку нажмите {007F0E}Y{FFFFFF}, {FF0000}N{FFFFFF} для отказа.");
                SetPVarInt(user,"Buy_License_DE",1);
            }
        }
    }
    case d_gang_storage: if(response){
        new name[8+22+1];
        format(name,sizeof(name),"{FFCC66}%s",Get_GangName(P[playerid][p_job_team]));
        new x = P[playerid][p_job_team]-10;
        switch(listitem){
            case 0:{
                if(GS[x][g_status] == false) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Доступ к складу закрыт.");
                ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                    "{FFFFFF}Введите количество денежных средств, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n  -Сумма не должна привышать ту, что есть в общаке.", "Взять", "Назад");
                SetPVarInt(playerid, "gang_take_cash", 1);
            }
            case 1:{
                if(GS[x][g_status] == false) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Доступ к складу закрыт.");
                ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name, "{FFFFFF}Введите количество патронов, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n  -Количество патронов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
                SetPVarInt(playerid, "gang_take_patrons", 1);
            }
            case 2:{
                if(GS[x][g_status] == false) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Доступ к складу закрыт.");
                ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name, "{FFFFFF}Введите количество материалов, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n  -Количество материалов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
                SetPVarInt(playerid, "gang_take_materials", 1);
            }
            case 3:{
                ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name, "{FFFFFF}Введите количество денежных средств, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n  -Не больше той суммы что у вас есть.", "Добавить", "Назад");
                SetPVarInt(playerid, "gang_put_cash", 1);
            }
            case 4:{
                ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name, "{FFFFFF}Введите количество патронов, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n  -Не больше того количество что у вас есть.", "Добавить", "Назад");
                SetPVarInt(playerid, "gang_put_patrons", 1);
            }
            case 5:{
                ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name, "{FFFFFF}Введите количество материалов, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n  -Не больше того количество что у вас есть.", "Добавить", "Назад");
                SetPVarInt(playerid, "gang_put_materials", 1);
            }
        }
    }
    case d_gang_take:{
        new x = P[playerid][p_job_team]-10;
        new name[8+22+1];
        format(name,sizeof(name),"{FFCC66}%s",Get_GangName(P[playerid][p_job_team]));
        new take = strval(inputtext);
        new gang_take_cash = GetPVarInt(playerid, "gang_take_cash");
        new gang_take_patrons = GetPVarInt(playerid, "gang_take_patrons");
        new gang_take_materials = GetPVarInt(playerid, "gang_take_materials");
        if(!response){
            if(gang_take_cash == 1) DeletePVar(playerid, "gang_take_cash");
            if(gang_take_patrons == 1) DeletePVar(playerid, "gang_take_patrons");
            if(gang_take_materials == 1) DeletePVar(playerid, "gang_take_materials");
            return 0;
        }
        if(gang_take_cash == 1){
            new Float:take_cash = floatstr(inputtext);
            if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество денежных средств, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n  -Сумма не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            if(take_cash < 1) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество денежных средств, которые вы бы хотели взять из общяка:\nУсловие\n{FF0000}  -Число больше 0.\n{FFFFFF}  -Сумма не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            if(take_cash > GS[x][g_cash]) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество денежных средств, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n{FF0000}  -Сумма не должна привышать ту, что есть в общаке.", "Взять", "Назад");
			foreach(new i : Player){
				switch(P[playerid][p_job_team]){
					case 10..17: if(P[i][p_job_team] == P[playerid][p_job_team]) va_SendClientMessageF(i, 0x6699CCFF,"[F] %s %s взял со склада $%m.",Get_RangName(playerid), IC_Name(playerid), floatround(take_cash*100));
				}
			}
            GS[x][g_cash] -= floatround(take_cash*100);
            Cash_Give(playerid, floatround(take_cash*100));
            orm_update(GS[x][_g_ormid]);
            DeletePVar(playerid, "gang_take_cash");
        }
        else if(gang_take_patrons == 1){
            if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество патронов, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n  -Количество патронов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            if(take < 1) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество патронов, которые вы бы хотели взять из общяка:\nУсловие\n{FF0000}  -Число больше 0.\n{FFFFFF}  -Количество патронов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            if(take > GS[x][g_ammo]) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество патронов, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n{FF0000}  -Количество патронов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            Message_ToComuneTeam(P[playerid][p_job_team],0x6699CCFF,"[F] %s %s взял со склада %i патронов",Get_RangName(playerid), IC_Name(playerid), take);
            GS[x][g_ammo] -= take;
            P[playerid][p_patrons] += take;
            orm_update(GS[x][_g_ormid]);
            DeletePVar(playerid, "gang_take_patrons");
        }
        else if(gang_take_materials == 1){
            if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество материалов, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n  -Количество материалов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            if(take < 1) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество материалов, которые вы бы хотели взять из общяка:\nУсловие\n{FF0000}  -Число больше 0.\n{FFFFFF}  -Количество материалов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            if(take > GS[x][g_materials]) return ShowPlayerDialog(playerid, d_gang_take, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество материалов, которые вы бы хотели взять из общяка:\nУсловие:\n  -Число больше 0.\n{FF0000}  -Количество материалов не должна привышать ту, что есть в общаке.", "Взять", "Назад");
            Message_ToComuneTeam(P[playerid][p_job_team],0x6699CCFF,"[F] %s %s взял со склада %i материалов",Get_RangName(playerid), IC_Name(playerid), take);
            GS[x][g_materials] -= take;
            P[playerid][p_materials] += take;
            orm_update(GS[x][_g_ormid]);
            DeletePVar(playerid, "gang_take_materials");
        }
    }
    case d_gang_put:{
        new x = P[playerid][p_job_team]-10;
        new name[8+22+1];
        format(name,sizeof(name),"{FFCC66}%s",Get_GangName(P[playerid][p_job_team]));
        new put = strval(inputtext);
        new gang_put_cash = GetPVarInt(playerid, "gang_put_cash");
        new gang_put_patrons = GetPVarInt(playerid, "gang_put_patrons");
        new gang_put_materials = GetPVarInt(playerid, "gang_put_materials");
        if(!response){
            if(gang_put_cash == 1) DeletePVar(playerid, "gang_put_cash");
            if(gang_put_patrons == 1) DeletePVar(playerid, "gang_put_patrons");
            if(gang_put_materials == 1) DeletePVar(playerid, "gang_put_materials");
            return 0;
        }
        if(gang_put_cash == 1){
            new Float:put_cash = floatstr(inputtext);
            if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество денежных средств, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n  -Не больше той суммы что у вас есть.", "Добавить", "Назад");
            if(put_cash < 1) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество денежных средств, которые вы бы хотели положить в общяк:\nУсловиие:\n{FF0000}  -Число больше 0.\n{FFFFFF}  -Не больше той суммы что у вас есть.", "Добавить", "Назад");
            if(put_cash > P[playerid][p_cash]) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество денежных средств, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n{FF0000}  -Не больше той суммы что у вас есть.", "Добавить", "Назад");
			foreach(new i : Player){
				switch(P[playerid][p_job_team]){
					case 10..17: if(P[i][p_job_team] == P[playerid][p_job_team]) va_SendClientMessageF(i, 0x6699CCFF,"[F] %s %s положил в общак $%m.",Get_RangName(playerid), IC_Name(playerid), floatround(put_cash*100));
				}
			}
            GS[x][g_cash] += floatround(put_cash*100);
            Cash_Give(playerid, -floatround(put_cash*100));
            orm_update(GS[x][_g_ormid]);
            DeletePVar(playerid, "gang_put_cash");
        }
        if(gang_put_patrons == 1){
            if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество патронов, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n  -Не больше того количество что у вас есть.", "Добавить", "Назад");
            if(put < 1) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество патронов, которые вы бы хотели положить в общяк:\nУсловиие:\n{FF0000}  -Число больше 0.\n{FFFFFF}  -Не больше того количество что у вас есть.", "Добавить", "Назад");
            if(put > P[playerid][p_patrons]) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество патронов, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n{FF0000}  -Не больше того количество что у вас есть.", "Добавить", "Назад");
            Message_ToComuneTeam(P[playerid][p_job_team],0x6699CCFF,"[F] %s %s положил в общак %d патронов.",Get_RangName(playerid), IC_Name(playerid), put);
            GS[x][g_ammo] += put;
            P[playerid][p_patrons] -= put;
            orm_update(GS[x][_g_ormid]);
            DeletePVar(playerid, "gang_put_patrons");
        }
        if(gang_put_materials == 1){
            if(!strlen(inputtext)) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество материалов, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n  -Не больше того количество что у вас есть.", "Добавить", "Назад");
            if(put < 1) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество материалов, которые вы бы хотели положить в общяк:\nУсловиие:\n{FF0000}  -Число больше 0.\n{FFFFFF}  -Не больше того количество что у вас Добавить.", "Взять", "Назад");
            if(put > P[playerid][p_materials]) return ShowPlayerDialog(playerid, d_gang_put, DIALOG_STYLE_INPUT, name,
                "{FFFFFF}Введите количество материалов, которые вы бы хотели положить в общяк:\nУсловиие:\n  -Число больше 0.\n{FF0000}  -Не больше того количество что у вас есть.", "Добавить", "Назад");
            Message_ToComuneTeam(P[playerid][p_job_team],0x6699CCFF,"[F] %s %s положил в общак %d материалов.",Get_RangName(playerid), IC_Name(playerid), put);
            GS[x][g_materials] += put;
            P[playerid][p_materials] -= put;
            orm_update(GS[x][_g_ormid]);
            DeletePVar(playerid, "gang_put_materials");
        }
    }
    case d_ps_business_show_edit:if(response){
        new x = P[playerid][p_business_ps],
        	ps_name_[30+7],
            str_status[44],
            info[134+44];
        format(ps_name_,sizeof(ps_name_),"{FFFFFF}%s",PS[x][ps_name]);

        str_status = (PS[x][ps_status] == 0) ? "{00FF00}Открыть {FFFFFF}заправочную станцию" : "{FF0000}Закрыть {FFFFFF}заправочную станцию";

        format(info,sizeof(info),"%s\nУстановить цену за 1л топливо\nДобавить деньги в бюджет АЗС\nВзять деньги из бюджета АЗС\nЗаказать топливо\nПродать АЗС по гос. цене",str_status);
        ShowPlayerDialog(playerid, d_ps_business_edit, DIALOG_STYLE_LIST, ps_name_, info, "Открыть", "Закрыть");
    }
    case d_ps_business_edit:if(response){
        new x = P[playerid][p_business_ps],
            ps_name_[30+7];
        format(ps_name_,sizeof(ps_name_),"{FFFFFF}%s",PS[x][ps_name]);
        switch(listitem){
            case 0: switch(PS[x][ps_status]){
                case 0:PS[x][ps_status] = 1;
                case 1:PS[x][ps_status] = 0;
            }
            case 1:{
                SetPVarInt(playerid, "d_ps_business_set", 1);
                ShowPlayerDialog(playerid, d_ps_business_set_take, DIALOG_STYLE_INPUT, ps_name_,
                    "{FFFFFF}Введите стоимость одного литра топливо:\nУсловие:\n  -От 0.00$ до 150.00$.", "Взять", "Назад");
            }
            case 2:{
                SetPVarInt(playerid, "d_ps_business_put",1);
                new info[150];
                format(info,sizeof(info),"{FFFFFF}Введите количество денежных средств, которые вы бы хотели добавить в кассу АЗС:\nУсловие:\n  -Не больше того количество денег что у вас есть.");
                ShowPlayerDialog(playerid, d_ps_business_set_take, DIALOG_STYLE_INPUT, ps_name_, info,"Положить","Назад");
            }
            case 3:{
                SetPVarInt(playerid, "d_ps_business_take", 1);
                new info[125];
                format(info,sizeof(info),"{FFFFFF}Введите количество денежных средств, которые вы бы хотели взять из кассы АЗС:\nУсловие:\n  -Число от 0.00$ до $%m.",PS[x][ps_profit]);
                ShowPlayerDialog(playerid, d_ps_business_set_take, DIALOG_STYLE_INPUT, ps_name_,info, "Взять", "Назад");
            }
            case 4:{
                if(PS[x][ps_buy_fuel] != 0) return SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Вы уже в очереди заказов. Ждите.");
                ShowPlayerDialog(playerid, d_ps_business_get_fuel, DIALOG_STYLE_INPUT, ps_name_, "{FFFFFF}Введите количество топлива которую хотите заказать:\nУсловие:\n  -Заказывать можно от 100 до 5000 литров топлива.", "Далее","Отмена");
            }
            case 5:{
                SetPVarInt(playerid, "d_ps_state_bussiness", 1);
                new sell_business_ps[221+1];
                format(sell_business_ps, sizeof(sell_business_ps), "{FFFFFF}Государственная цена: {FF8888}$%m\n\
                    {FFFFFF}Цена за которую Вы продаете бизнес гос-ву: {FF8888}$%m\n\n\
                    {FFCC66}Вы потеряете 20 процентов от государственной цены.\n\
                    Вы уверены что хотите продать свой бизнес?",PS[x][ps_price],PS[x][ps_price]/100*80);
                ShowPlayerDialog(playerid,d_ps_business_set_take,DIALOG_STYLE_MSGBOX,"Продажа АЗС",sell_business_ps,"Да","Нет");
            }
        }
        orm_update(PS[x][_ps_ormid]);
    }
    case d_ps_business_set_take: if(response){
        if(!response){
            if(GetPVarInt(playerid, "d_ps_business_set") == 1)
                DeletePVar(playerid, "d_ps_business_set");
            if(GetPVarInt(playerid, "d_ps_business_put") == 1)
                DeletePVar(playerid, "d_ps_business_put");
            if(GetPVarInt(playerid, "d_ps_business_take") == 1)
                DeletePVar(playerid, "d_ps_business_take");
            if(GetPVarInt(playerid, "d_ps_state_bussiness") == 1)
                DeletePVar(playerid, "d_ps_state_bussiness");
            return 0;
        }
        new Float: price = floatstr(inputtext),
            x = P[playerid][p_business_ps],
            ps_name_[30+7];
        format(ps_name_,sizeof(ps_name_),"{FFFFFF}%s",PS[x][ps_name]);
        if(GetPVarInt(playerid, "d_ps_business_set") == 1){
            if(price < 1 || price > 150.0)
                return ShowPlayerDialog(playerid, d_ps_business_set_take, DIALOG_STYLE_INPUT, ps_name_,"{FFFFFF}Введите стоимость одного литра топливо:\nУсловие:\n{FF0000}  -От 1.00$ до 150.00$.", "Взять", "Назад");
            PS[x][ps_fuel_price] = floatround(price*100);
            va_SendClientMessageF(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Цена за 1 литр бензина $%m.",price*100);
            PS_Update3DInfo(x);
            DeletePVar(playerid, "d_ps_business_set");
        }
        else if(GetPVarInt(playerid, "d_ps_business_put") == 1){
            new info[142];
            format(info,sizeof(info),"Введите количество денежных средств, которые вы бы хотели добавить в кассу АЗС:\nУсловие:\n  -Не больше того количество денег что у вас есть.");
            if(P[playerid][p_cash] < floatround(price*100))
                return ShowPlayerDialog(playerid, d_ps_business_set_take,DIALOG_STYLE_INPUT,ps_name_,info,"Положить","Назад");
            Cash_Give(playerid, floatround(-price*100));
            PS[x][ps_profit] += floatround(price*100);
            va_SendClientMessageF(playerid, 0xFFCC66FF,"[Уведмоление]: {FFFFFF}Вы добавили в бюджет АЗС $%m",price*100);
            DeletePVar(playerid, "d_ps_business_put");
        }
        else if(GetPVarInt(playerid, "d_ps_business_take") == 1){
            new info[123];
            format(info,sizeof(info),"{FFFFFF}Введите количество денежных средств, которые вы бы хотели взять из кассы АЗС:\nУсловие:\n  -Число от $1.00 до $%m.",PS[x][ps_profit]);
            if(price < 1 || price > PS[x][ps_profit])
                return ShowPlayerDialog(playerid, d_ps_business_set_take, DIALOG_STYLE_INPUT, ps_name_,info, "Взять", "Назад");
            PS[x][ps_profit] -= floatround(price*100);
            Cash_Give(playerid, floatround(price*100));
            va_SendClientMessageF(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Вы взяли из кассы АЗС $%m.",floatround(price*100));
            DeletePVar(playerid, "d_ps_business_take");
        }
        else if(GetPVarInt(playerid, "d_ps_state_bussiness") == 1){
            va_SendClientMessageF(playerid,0xFFCC66FF, "[Уведомление]: {FFFFFF}Вы продали АЗС {FFCC66}%s{FFFFFF} по Гос. цене за $%m",PS[x][ps_name],(PS[x][ps_price]/100*80)*100);
            Cash_Give(playerid, (PS[x][ps_price]/100*80)*100);
            new owner[24+1];
            format(owner,sizeof(owner),"The State");
            PS[x][ps_owner] = owner;
            P[playerid][p_business_ps] = 0;
            orm_update(PS[x][_ps_ormid]);
            orm_update(P[playerid][_p_ormid]);
            PS_Update3DInfo(x);
            DeletePVar(playerid, "d_ps_state_bussiness");
        }
        orm_update(PS[x][_ps_ormid]);
    }
    case d_ps_business_get_fuel:{
        if(!response) return 1;
        new Float: fuel = floatstr(inputtext),
            x = P[playerid][p_business_ps],
            ps_name_[30+7];
        format(ps_name_,sizeof(ps_name_),"{FFFFFF}%s",PS[x][ps_name]);
        if(fuel < 100 || fuel > 5000) return ShowPlayerDialog(playerid, d_ps_business_get_fuel, DIALOG_STYLE_INPUT, ps_name_, "{FFFFFF}Введите количество топлива которую хотите заказать:\nУсловие:\n  -Заказывать можно от 100 до 5000 литров топлива.", "Далее","Отмена");
        //PS[x][ps_buy_fuel] = fuel;
        SetPVarFloat(playerid, "ps_buy_fuel", fuel);
        ShowPlayerDialog(playerid, d_ps_business_get_fuel2, DIALOG_STYLE_INPUT, ps_name_, "{FFFFFF}Введите цену за 1 литр топлива:\nУсловие:\n  -Не меньше 5.45$ до 100$.", "Далее","Отмена");
    }
    case d_ps_business_get_fuel2:{
        if(!response) return 1;
        new Float: price = floatstr(inputtext),
            x = P[playerid][p_business_ps],
            ps_name_[30+7],
            amount;
        format(ps_name_,sizeof(ps_name_),"{FFFFFF}%s",PS[x][ps_name]);
        new Float: ps_buy_fuels = GetPVarFloat(playerid, "ps_buy_fuel");
        if(price < 5.45 || price > 100) return ShowPlayerDialog(playerid, d_ps_business_get_fuel2, DIALOG_STYLE_INPUT, ps_name_, "{FFFFFF}Введите цену за 1 литр топлива:\nУсловие:\n{FF0000}  -Не меньше 5.45$ до 100$.", "Далее","Отмена");
        amount = floatround((ps_buy_fuels * price)*100);
        if(PS[x][ps_profit] < amount){
            SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Бюджет вашей АЗС слишком маленький для установки такой цены за 1 литр топлива.");
            SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}Введите цену поменьше или положите деньги в бюджет и снова попробуйте выполнить данное действие.");
            ShowPlayerDialog(playerid, d_ps_business_get_fuel2, DIALOG_STYLE_INPUT, ps_name_, "{FFFFFF}Введите цену за 1 литр топлива:\nУсловие:\n{FF0000}  -Не меньше 5.45$ до 100$.", "Далее","Отмена");
        }
		PS[x][ps_profit] -= amount;
		va_SendClientMessageF(playerid, 0xFFCC66FF,"[Уведомление]: {FFFFFF}Вы успешно заказали топлива.Сумма: {FF8888}$%m{FFFFFF}.",amount);
		va_SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}- Ожидайте пока вам доставят топливо");
        va_SendClientMessage(playerid, 0xB22222FF,"[Справка]: {FFFFFF}- Также вы можете устроиться развозчиком топливо, и доставить сами.");
        PS[x][ps_buy_fuel] = ps_buy_fuels;
        PS[x][ps_price_buy_fuel] = floatround(price*100);
        orm_update(PS[x][_ps_ormid]);
    }
    case d_job_add_fuell_trailer:{
        if(!response) return 1;
        new Float: fuel = floatstr(inputtext);
        if(fuel < 1 || fuel > 1000)
            return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}От 1 до 1000 литров");
        new amount = floatround((fuel * 5.45)*100);
        if(P[playerid][p_cash] < amount) {
            SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно денежных средств для аренды транспорта");
            ShowPlayerDialog(playerid, d_job_add_fuell_trailer, DIALOG_STYLE_INPUT, "Купить топливо","{FFFFFF}Введите количество топлива которое хотите купить\n  -За 1 литр 5.45$","Ок","Назад");
            return true;
        }
        //доход владельцу
        new vehicleid = GetPlayerVehicleID(playerid);
        new trailerid = GetVehicleTrailer(vehicleid),
            string[42+4+1];
        for(new i; i < sizeof(V_PETROL_TRAILER); i++){
            if(V_PETROL_TRAILER[i] != trailerid) continue;
            if(trailer_fuel_v[i]+fuel > 1000){
                SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Недостаточно места в цистерне для такого количества топлива.");
                ShowPlayerDialog(playerid, d_job_add_fuell_trailer, DIALOG_STYLE_INPUT, "Купить топливо","{FFFFFF}Введите количество топлива которое хотите купить\n  -За 1 литр 5.45$","Ок","Назад");
                return true;
            }
            va_SendClientMessageF(playerid, -1, "Вы наполнили цистерну для топлива на %.0f литров за $%m", fuel,amount);
            Cash_Give(playerid, -amount);
            trailer_fuel_v[i] += fuel;
            format(string,sizeof(string),"{FFFFFF}Топлива в цистерне: %.0f/1000 литров",trailer_fuel_v[i]);
            UpdateDynamic3DTextLabelText(text_trailer[i], -1, string);
        }
    }
    case d_job_fuel_list: {
        if(!response) return true;
        new ps_0 = -1,ps_1 = -1,ps_2 = -1,ps_3 = -1,ps_4 = -1;
        for(new x; x < sizeof(PS); x++) {
    		if(PS[x][ps_buy_fuel] == 0) continue;
            if(ps_0 == -1) ps_0 = PS[x][ps_uid];
			else if(ps_1 == -1) ps_1 = PS[x][ps_uid];
			else if(ps_2 == -1) ps_2 = PS[x][ps_uid];
			else if(ps_3 == -1) ps_3 = PS[x][ps_uid];
			else if(ps_4 == -1) ps_4 = PS[x][ps_uid];
    	}
        switch(listitem){
            case 0:{
				va_SendClientMessage(playerid,0xFFCC66FF,"[Уведмоление]: {FFFFFF}АЗС {FF8888}%s{FFFFFF} отмечен на вашей карте.",PS[ps_0][ps_name]);
				p_gps = CreateDynamicCP(PS[ps_0][ps_pos_x],PS[ps_0][ps_pos_y],PS[ps_0][ps_pos_z], 5.0,-1,-1,playerid,99999.0);
            }
            case 1:{
				va_SendClientMessage(playerid,0xFFCC66FF,"[Уведмоление]: {FFFFFF}АЗС {FF8888}%s{FFFFFF} отмечен на вашей карте.",PS[ps_1][ps_name]);
				p_gps = CreateDynamicCP(PS[ps_1][ps_pos_x],PS[ps_1][ps_pos_y],PS[ps_1][ps_pos_z], 5.0,-1,-1,playerid,99999.0);
            }
			case 2:{
				va_SendClientMessage(playerid,0xFFCC66FF,"[Уведмоление]: {FFFFFF}АЗС {FF8888}%s{FFFFFF} отмечен на вашей карте.",PS[ps_2][ps_name]);
				p_gps = CreateDynamicCP(PS[ps_2][ps_pos_x],PS[ps_2][ps_pos_y],PS[ps_2][ps_pos_z], 5.0,-1,-1,playerid,99999.0);
            }
			case 3:{
				va_SendClientMessage(playerid,0xFFCC66FF,"[Уведмоление]: {FFFFFF}АЗС {FF8888}%s{FFFFFF} отмечен на вашей карте.",PS[ps_3][ps_name]);
				p_gps = CreateDynamicCP(PS[ps_3][ps_pos_x],PS[ps_3][ps_pos_y],PS[ps_3][ps_pos_z], 5.0,-1,-1,playerid,99999.0);
            }
			case 4:{
				va_SendClientMessage(playerid,0xFFCC66FF,"[Уведмоление]: {FFFFFF}АЗС {FF8888}%s{FFFFFF} отмечен на вашей карте.",PS[ps_4][ps_name]);
				p_gps = CreateDynamicCP(PS[ps_4][ps_pos_x],PS[ps_4][ps_pos_y],PS[ps_4][ps_pos_z], 5.0,-1,-1,playerid,99999.0);
            }
        }
        if(IsPlayerInRangeOfPoint(playerid, 20.5, -1034.8696,-617.4734,32.5861)) return SendClientMessage(playerid, 0xB22222FF, "[Справка]: {FFFFFF}Точка назначения будет показана как только вы отдолитесь от места загрузки топлива.");
    }
    }
    return 1;
}
