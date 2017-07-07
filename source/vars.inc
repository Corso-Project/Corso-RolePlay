#define GAMEMODE_VERSION    "Corso RP"
#define SERVER_NAME         "{B1413D}Corso RolePlay"

#define FUEL_TANK_LIMIT			25000

#define MOVE_GATE_SPEED     	3.0
#define MOVE_BARRIER_SPEED  	0.2
// Capture
#define TimeForCapt 25
#define GangZoneMinutsDef 7
// Лифт
#define ELEVATOR_SPEED      (5.0)
#define DOORS_SPEED         (5.0)
#define ELEVATOR_WAIT_TIME  (5000)
#define X_DOOR_R_OPENED     (289.542419)
#define X_DOOR_L_OPENED     (286.342407)
#define Y_DOOR_R_OPENED     (-1609.640991)
#define Y_DOOR_L_OPENED     (-1609.076049)
#define X_FDOOR_R_OPENED    (289.492431)
#define X_FDOOR_L_OPENED    (286.292419)
#define Y_FDOOR_R_OPENED    (-1609.870971)
#define Y_FDOOR_L_OPENED    (-1609.306030)
#define GROUND_Z_COORD      (18.755348)
#define X_ELEVATOR_POS      (287.942413)
#define Y_ELEVATOR_POS      (-1609.341064)
#define ELEVATOR_STATE_IDLE     (0)
#define ELEVATOR_STATE_WAITING  (1)
#define ELEVATOR_STATE_MOVING   (2)
#define INVALID_FLOOR           (-1)

enum {
	ORG_UNKNOWN,
	ORG_GOVERNMENT,
	ORG_FBI,
	ORG_LSPD,
	ORG_SFPD,
	ORG_LVPD,
	ORG_MILITARY,
	ORG_EMERGENCY,
	ORG_SANNEWS,
	ORG_AUTOSCHOOL,
	ORG_GROVE,
	ORG_BALLAS,
	ORG_AZTECAS,
	ORG_VAGOS,
	ORG_RIFA,
	ORG_CHINESE,
	ORG_RUSSIAN,
	ORG_ITALIAN,
	JOB_TAXI,
	JOB_ENGINEER,
	JOB_FREIGHTER
}

enum {
	SEX_FEMALE,
	SEX_MALE
}

enum E_PLAYER_DATA {
	PlayerText: _p_speedo,
	PlayerText: _p_cent,
	PlayerText: SpecText,
	bool: _p_in_game,
	bool: _p_spawned,
	bool: _p_dialog,
	ORM: _p_ormid,
	_p_chat_msg[144],
	_p_skin_shop,
	_p_chat_time,
	_p_cheater,
	// mysql synced
	p_uid,
	p_name[MAX_PLAYER_NAME+1],
	p_password[129],
	p_access,
	p_unban_date[16],
	p_last_ip[46],
	p_reg_ip[46],
	p_cash,
	p_mute,
	p_sex,
	p_skin,
	p_job_team,
	p_rang,
	p_level,
	p_exp,
	p_health,
	p_armour,
	p_vehicle,
	p_patrons,
	p_materials,
	p_business_ps,
	p_ticket,
	p_wanted_level,
	p_weapon_1,
	p_weapon_2,
	p_weapon_3,
	p_weapon_4,
	p_ammo_2,
	p_ammo_3,
	p_ammo_4,
	p_lic_moto,
	p_lic_car,
	p_lic_freight,
	p_lic_boat,
	p_lic_helicopter,
	p_lic_aircraft,
	p_lic_weapon
}

enum E_VEHICLE_DATA {
	_v_stream_id,
	_v_stream_url[128],
	// mysql synced
	Float: v_fuel,
}

enum E_PETROL_STATIONS_DATA {
	ORM: _ps_ormid,
	Text3D: _ps_text3d,
	// mysql synced
	ps_uid,
	ps_name[30],
	Float: ps_volume,
	ps_owner[24+1],
	ps_status,
	ps_price,
	ps_fuel_price,
	ps_profit,
	Float: ps_pos_x,
	Float: ps_pos_y,
	Float: ps_pos_z,
	Float: ps_buy_fuel,
	ps_price_buy_fuel
}
enum E_GANG_ZONES_DATA{
	ORM: _gz_ormid,
	_gz_local,
	// mysql synced
	gz_uid,
	Float: gz_min_pos_x,
	Float: gz_min_pos_y,
	Float: gz_max_pos_x,
	Float: gz_max_pos_y,
	gz_team
}
enum E_GANG_STORAGE{
	ORM: _g_ormid,
	// mysql synced
	g_uid,
	g_status,
	g_cash,
	g_patrons,
	g_materials
}
enum
{
	d_null,
	// account dialogs
	d_account_login,
	d_account_register,
	d_account_loggin_error,
	d_account_choose_sex,
	d_account_name_error,
	d_account_banned,
	d_account_change_password,
	// vehicle dialogs
	d_vehicle_panel,
	d_vehicle_radio,
	d_vehicle_url_radio,
	d_vehicle_rent_car,
	d_vehicle_rent_car_standart,
	d_vehicle_rent_car_premium,
	d_vehicle_rent_taxi,
	d_vehicle_rent_officecar,
	d_vehicle_rent_truck,
	// player dialogs
	d_player_menu,
	d_player_buy_gun,
	d_player_settings,
	d_player_report,
	d_player_gps,
	// gps dialogs
	d_gps_public_places,
	d_gps_jobs,
	d_gps_state_organizations,
	d_gps_criminal_organizaions,
	d_gps_banks,
	d_gps_pleasure,
	d_gps_nearest_filling,
	// job dialogs
	d_job_add_fuell_trailer,
	d_job_fuel_list,
	// law's dialogs
	d_law_test,
	d_law_sell_lic,
	// elevator's dialogs
	d_elevator_chose_floor,
	// gang's dialogs
	d_gang_storage,
	d_gang_take,
	d_gang_put,
	// business dialogs
	d_ps_business_show_edit,
	d_ps_business_edit,
	d_ps_business_set_take,
	d_ps_business_get_fuel,
	d_ps_business_get_fuel2
}
enum E_EXAM_ANSWER {
	e_exam_question[88],
    bool:e_exam_is_answer
}
new P[MAX_PLAYERS][E_PLAYER_DATA];
new V[MAX_VEHICLES][E_VEHICLE_DATA];
new PS[16][E_PETROL_STATIONS_DATA];
new GZ[104][E_GANG_ZONES_DATA];
new GS[7][E_GANG_STORAGE];

new V_GOVERNMENT[7],
	V_FBI[7],
	V_LSPD[14],
	V_SFPD[12],
	V_LVPD[10],
	V_MILITARY[15],
	V_EMERGENCY[14],
	//V_SANNEWS[],
	V_AUTOSCHOOL[8],
	V_GROVE[5],
	V_BALLAS[7],
	V_AZTECAS[7],
	V_VAGOS[5],
	V_RIFA[8],
	V_CHINESE[8],
	V_RUSSIAN[8],
	V_ITALIAN[8],
	V_TAXI[21],
	V_ENGINEER[16],
	V_FREIGHTER[13],
	V_PETROL_TRAILER[13],
	V_RENT[42],
	V_RENT_STANDART[18],
	V_RENT_PREMIUM[14];

new V_RENT_OWNER[sizeof V_RENT],
	V_RENT_OWNER_STANDART[sizeof V_RENT_STANDART],
	V_RENT_OWNER_PREMIUM[sizeof V_RENT_PREMIUM],
	V_TAXI_OWNER[sizeof V_TAXI],
	V_ENGINEER_OWNER[sizeof V_ENGINEER],
	V_FREIGHTER_OWNER[sizeof V_FREIGHTER];

new obj_FBI,
	obj_LSPD,
	obj_SFPD[2],
	obj_LVPD,
	obj_MILITARY[2],
	obj_AUTOSCHOOL[1];

new bool: obj_state_FBI,
	bool: obj_state_LSPD,
	bool: obj_state_SFPD[2],
	bool: obj_state_LVPD,
	bool: obj_state_MILITARY[2],
	bool: obj_state_AUTOSCHOOL[1];

new g_hour,
	g_minute;

// budget.ini
new Budget_GOVERNMENT;
// mysql.ini
new g_MySQL_Host[46],
	g_MySQL_User[46],
	g_MySQL_Database[46],
	g_MySQL_Password[46];
// prices.ini
new Prices_RentCar_Econom,
	Prices_RentCar_Standart,
	Prices_RentCar_Premium;
// settings.ini
new g_Chat_OOC,
	g_Payment_Register;
// Пикапы
new PickupGetTime[MAX_PLAYERS];
new Ammu_Nation[8];
new Casino[2];
new FBI[4],
	LSPD[2];
new CityHall[2];
new Grove[2],
	Ballas[2],
	Aztecas[2],
	Vagos[2],
	Rifa[2];
new Chinese[2],
	Russian[2],
	Italian[2];
new AutoSchool_Exam[1];
// CheckPoint
new Buy_Weapon,
	Gang_Storage[5],
	Mafia_Storage[3],
	p_gps;
	// Race
new Freighter_Job;
// Text-Draws
new Text:Corso;
new Text:Capture[2];
// Spec
new gSpectateID[MAX_PLAYERS];
new gSpectateType[MAX_PLAYERS];
// Работы
	// 3D текст
new Text3D: text_trailer[13];
new Float: trailer_fuel_v[13] = 0.0;
// NPC's
new FBI_Actors[3];
// Capture
new bool:waractive = false;
new gangs[2] = 0,
	CaptureTime=0,
	zone = 0,
	gangskills[2] = 0;
new GangZoneSeconds,
	GangZoneMinuts;
//TD
new PlayerText: ChoseSkin[8],
	PlayerText: Press_ALT[5],
	PlayerText: Wanted_New_Cash;
//Динамические зоны
new auto_school_press_alt[5],
	police_press_alt[4];
// Gang Zone
new army;
// Скины
new male_skins[] = {
	3,6,136,78,200,137,79,2,7,230
};

new female_skins[] = {
	10,11,12,13,40
};
new Streams[][][] = {
{"Выключить радио\n", ""},
{"Включить музыку с URL\n", ""},
{"SESHstation", "https://stream.sesh.team/stream.m3u"}
};
new Server_Rules[][] = {
"{FFFFFF}Правила игры на сервере.\n",
"{54D5FF}1.{FFFFFF} Revenge Kill (Сокращено RK) запрещён | Warn/Тюрьма на 60 минут\n",
"{54D5FF}2.{FFFFFF} Mеtagаming (Сокращение MG) запрещён | Бан чата 15-60 минут\n",
"{54D5FF}3.{FFFFFF} Powergaming (Сокращение PG) запрещён | Kick/Warn/Тюрьма на 30-60 минут.\n",
"{54D5FF}4.{FFFFFF} Deatmatch (сокращение DM)запрещён. | Kick/Warn/Тюрьма на 60 минут. Последующие нарушения Бан\n",
"{54D5FF}5.{FFFFFF} DriveBy (сокращение DB) запрещён | Тюрьма 30-60 минут,Warn (DB разрешён только пассажирам)\n",
"{54D5FF}6.{FFFFFF} Spawn Kill (Сокращение SK) запрещён |Тюрьма 60 минут,Warn/Бан\n",
"{54D5FF}7.{FFFFFF} Team Kill (Сокращение TK) запрещён | Warn/Бан\n",
"{54D5FF}8.{FFFFFF} Repeat Kill (Сокращение RK) запрещён | Тюрьма 60-120 минут,Warn\n",
"{54D5FF}9.{FFFFFF} FastReload или Scroll (Сокращение FR), а так же Fastmoving (Сокращение FM) запрещён | Warn (Т.к. это багоюз)\n",
"{54D5FF}10.{FFFFFF} Использование Читов/Хаков/Cleo запрещено. | бан на сервере от 10-30 дней до пожизненного.\n",
"{54D5FF}11.{FFFFFF} Нон рп запрещён! | Тюрьма на 60 минут\n",
"{54D5FF}12.{FFFFFF} Использовать аптечки,наркотики во время драки или перестрелки запрещено. | Warn\n",
"{54D5FF}13.{FFFFFF} Флуд в IC и OOC, /s чаты | Бан чата 10-50 минут\n",
"{54D5FF}14.{FFFFFF} Флуд в Репорт, а так же вопросы типа: Можете дать лицензию, деньги, дом, админку | Бан чата 40-100 минут,Kick,Warn\n",
"{54D5FF}15.{FFFFFF} Выход из игры во время RP-процесса | Тюрьма 60-180 минут,Warn\n",
"{54D5FF}16.{FFFFFF} Оскорбление/троллинг/клевета | Бан чата,Kick,Warn,Бан аккаунта\n",
"{54D5FF}17.{FFFFFF} Оскорбление родителей | Бан 15-30 дней\n",
"{54D5FF}18.{FFFFFF} Реклама посторонних ресурсов (серверов, сайтов, читов) | Пожизненный бан\n\n",
"Правила для аккаунтов:\n",
"{5a5fed}1.{FFFFFF} Ваш аккаунт - это ваша собственность и ваша отвественность. За утрату аккаунта (взлом,угон)\n",
"{5a5fed}2.{FFFFFF} Администрация отвественности не несёт и аккаунты игроков не восстанавливает!\n",
"{5a5fed}3.{FFFFFF} Продажа игровых денег,бизнесов,домов и т.д. за реальные деньги карается удалением аккаунта!\n"
};
new Float:cam_start_pos[][] = {
	{1482.074462, -898.318481, 92.719245, 1482.074462, -898.318481, 92.719245},
	{423.594848, -2073.024902, 43.753078, 423.594848, -2073.024902, 43.753078},
	{905.401794, -1200.925048, 106.217491, 905.401794, -1200.925048, 106.217491},
	{2042.314697, 1462.658447, 34.089710, 2042.314697, 1462.658447, 34.089710},
	{-1168.268310, 1134.234008, 136.937957, -1168.268310, 1134.234008, 136.937957},
	{-1011.961486, 2105.833984, 149.920181, -1011.961486, 2105.833984, 149.920181},
	{22.611024, -1959.371337, 84.940864, 22.611024, -1959.371337, 84.940864},

	{2158.117431, 1082.130737, 88.801651, 2174.856201, 1066.589477, 88.791961}
};

new Float:cam_start_look[][] = {
	{1479.071166, -894.389892, 91.979782, 1479.071166, -894.389892, 91.979782},
	{422.012817, -2068.566406, 42.134643, 422.012817, -2068.566406, 42.134643},
	{910.388732, -1201.068725, 105.885704, 910.388732, -1201.068725, 105.885704},
	{2038.087890, 1460.144287, 33.188415, 2038.087890, 1460.144287, 33.188415},
	{-1172.385009, 1131.439697, 136.442672, -1172.385009, 1131.439697, 136.442672},
	{-1007.483459, 2104.049316, 148.592544, -1007.483459, 2104.049316, 148.592544},
	{26.822828, -1956.851684, 83.985832, 26.822828, -1956.851684, 83.985832},

	{2154.756347, 1079.329711, 86.381553, 2171.865234, 1063.261596, 86.560485}
};
forward SetPlayerCameraPos_(playerid);
public SetPlayerCameraPos_(playerid)
{
    SetPlayerInterior(playerid, 0);
	new rand = random(sizeof(cam_start_pos));
	InterpolateCameraPos(playerid, cam_start_pos[rand][0], cam_start_pos[rand][1], cam_start_pos[rand][2], cam_start_pos[rand][3], cam_start_pos[rand][4], cam_start_pos[rand][5], 1000);
	InterpolateCameraLookAt(playerid, cam_start_look[rand][0], cam_start_look[rand][1], cam_start_look[rand][2], cam_start_look[rand][3], cam_start_look[rand][4], cam_start_look[rand][5], 1000);
}
new Traffic_Laws_ExamQuestions[15][77] = {
	"Что означает мигание зеленого сигнала светофора?",//0
	"При какой неисправности Вам разрешается эксплуатация транспортного средства?",//1
	"В каких из перечисленных случаев запрещена буксировка на гибкой сцепке?",//2
	"В каких случаях водитель не должен подавать сигнал указателями поворота?",//3
	"Что означает разметка в виде надписи «СТОП» на проезжей части?",//4
	"В каких случаях разрешено применять звуковые сигналы в населенных пунктах?",//5
	"Остановка на автомагистрали разрешена:",//6
	"Водителям мопедов разрешено двигаться:",//7
	"Разрешается ли на двухполосной дороге выполнять обгон на перекрестках?",//8
	"Являются ли тротуары и обочины частью дороги?",//9
	"Разрешается ли водителю движение со слишком малой скоростью?",//10
	"Разрешено ли перевозить людей в буксируемом легковом автомобиле?",//11
	"Движение транспортных средств задним ходом разрешается:",//12
	"Запрещено ли выполнить обгон на подъеме?",//13
	"Что следует делать при возникновении ДТП в первую очередь?"//14
};
new Traffic_Laws_ExamAnswers[15][4][E_EXAM_ANSWER] =
{
    {
        {"1. Запрещает дальнейшее движение.",false},
        {"2. Разрешает движение и информирует о том, что вскоре будет включен запрещающий сигнал.",true},
        {"3. Предупреждает о неисправности светофора.",false},
        {"",false}
    },
    {
        {"1. Не работает механизм регулировки сиденья водителя.",false},
        {"2. Не работает стеклоподъемник.",true},
        {"3. Не работает устройство обогрева и обдува стекла.",false},
        {"4. Не работают запоры горловин топливных баков.",false}
    },
    {
        {"1. Только в гололедицу.",true},
        {"2. Только в темное время суток и в условиях недостаточной видимости.",false},
        {"3. Во всех перечисленных случаях.",false},
        {"4. Только на горных дорогах.",false}
    },
	{
		{"1. Только при отсутствии на дороге других участников движения.",false},
		{"2. Только если сигнал может ввести в заблуждение других участников движения.",true},
		{"3. В обоих перечисленных случаях.",false},
		{"",false}
	},
	{
		{"1. Предупреждает о приближении к стоп-линии перед регулируемым перекрестком.",false},
		{"2. Предупреждает о приближении к стоп-линии и знаку «Движение без остановки запрещено».",true},
		{"3. Предупреждает о приближении к знаку «Уступите дорогу».",false},
		{"",false}
	},
	{
		{"1. Только для предупреждения о намерении произвести обгон.",false},
		{"2. Только для предотвращения дорожно-транспортного происшествия.",true},
		{"3. В обоих перечисленных случаях.",false},
		{"",false}
	},
	{
		{"1. В любых местах за пределами проезжей части.",false},
		{"2. Только правее линии разметки, обозначающей край проезжей части.",false},
		{"3. Только на специальных площадках для стоянки, обозначенных соответствующими знаками.",true},
		{"",false}
	},
	{
		{"1. Только по правому краю проезжей части в один ряд.",false},
		{"2. Только по обочине, если не создаются помехи пешеходам.",false},
		{"3. Только по полосе для велосипедистов.",false},
		{"4. Во всех перечисленных случаях.",true}
	},
	{
		{"1. Разрешается.",false},
		{"2. Разрешается только на нерегулируемых перекрестках.",false},
		{"3. Разрешается только на перекрестках, при движении по главной дороге.",true},
		{"4. Запрещается.",false}
	},
	{
		{"1. Являются.",true},
		{"2. Являются только обочины.",false},
		{"2. Являются только обочины.",false},
		{"",false}
	},
	{
		{"1. Разрешается.",false},
		{"2. Разрешается, если при этом не создаются помехи другим транспортным средствам.",true},
		{"3. Запрещается.",false},
		{"",false}
	},
	{
		{"1. Разрешено.",false},
		{"2. Разрешено только при буксировке на гибкой или жесткой сцепке.",true},
		{"3. Запрещено.",false},
		{"",false}
	},
	{
		{"1. На перекрестках.",false},
		{"2. На дорогах с односторонним движением.",true},
		{"3. На пешеходных переходах.",false},
		{"4. В местах остановок маршрутных транспортных средств.",false}
	},
	{
		{"1. Запрещено.",false},
		{"2. Запрещено только в конце подъема.",true},
		{"3. Разрешено.",false},
		{"",false}
	},
	{
		{"1. Включить аварийную сигнализацию.",false},
		{"2. Вызвать скорую помощь и полицию.",false},
		{"3. Если есть пострадавшие, оказать первую помощь.",false},
		{"4. Все ответы верны.",true}
	}
};
// Лифт
new FloorNames[14][] =
{
	"Парковка",
	"Нижний этаж",
	"Первый этаж",
	"Второй этаж",
	"Третий этаж",
	"Четвертый этаж",
	"Пятый этаж",
	"Шестой этаж",
	"Седьмой этаж",
	"Восьмой этаж",
	"Девятый этаж",
	"Десятый этаж",
	"Одиннадцатый этаж",
	"Двенадцатый этаж"
};
new Float:FloorZOffsets[14] =
{
    0.0,
    15.069729,
    29.130733,
    33.630733,
    38.130733,
    42.630733,
    47.130733,
    51.630733,
    56.130733,
    60.630733,
    65.130733,
    69.630733,
    74.130733,
    78.630733,
};

new Obj_Elevator, Obj_ElevatorDoors[2], Obj_FloorDoors[14][2];
new Text3D:Label_Elevator, Text3D:Label_Floors[14];
new ElevatorState;
new	ElevatorFloor;
new ElevatorQueue[14];
new	FloorRequestedBy[14];
new ElevatorBoostTimer;

forward Float:GetElevatorZCoordForFloor(floorid);
forward Float:GetDoorsZCoordForFloor(floorid);
