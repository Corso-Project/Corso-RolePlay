#define GAMEMODE_VERSION    "Corso RP"
#define SERVER_NAME         "{B1413D}Corso RolePlay"

#define FUEL_TANK_LIMIT			25000

#define MOVE_GATE_SPEED     	3.0
#define MOVE_BARRIER_SPEED  	0.2

#define ADMIN_SPEC_TYPE_NONE 0
#define ADMIN_SPEC_TYPE_PLAYER 1
#define ADMIN_SPEC_TYPE_VEHICLE 2
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
// Тир
#define Target_1 2.0
#define Target_2 3.0
#define Target_3 4.0
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
	JOB_BUS,
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
	p_weapon_5,
	p_ammo_2,
	p_ammo_3,
	p_ammo_4,
	p_ammo_5,
	p_lic_moto,
	p_lic_car,
	p_lic_freight,
	p_lic_boat,
	p_lic_helicopter,
	p_lic_aircraft,
	p_lic_weapon,
	p_russifier_type,
	p_skill_pistol,
	p_skill_pistol_silenced,
	p_skill_desert_eagle,
	p_skill_shotgun,
	p_skill_micro_uzi,
	p_skill_mp5,
	p_skill_ak47,
	p_skill_m4
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
enum E_AMMU_NATION_DATA{
	ORM: _an_ormid,
	Text3D: _an_text3d,
	// mysql synced
	an_uid,
	an_name[31],
	an_owner[24+1],
	an_price,
	an_profit,
	Float: an_pos_x,
	Float: an_pos_y,
	Float: an_pos_z,
	an_price_colt45,
	an_price_silenced,
	an_price_deagle,
	an_price_shotgun,
	an_price_tec9,
	an_price_micro_uzi,
	an_price_mp5,
	an_price_ak47,
	an_price_m4
}
enum E_GANG_STORAGE{
	ORM: _g_ormid,
	// mysql synced
	g_uid,
	bool: g_status,
	g_cash,
	g_ammo,
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
	d_vehicle_rent_bus,
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
	d_job_bus_route,
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
	d_ps_business_get_fuel2,
	// ammu-nation
	d_gps_ammu_nations
}
enum E_EXAM_ANSWER {
	e_exam_question[88],
    bool:e_exam_is_answer
}
new P[MAX_PLAYERS][E_PLAYER_DATA];
new V[MAX_VEHICLES][E_VEHICLE_DATA];
new PS[16][E_PETROL_STATIONS_DATA];
new GZ[104][E_GANG_ZONES_DATA];
new GS[8][E_GANG_STORAGE];
new AN[11][E_AMMU_NATION_DATA];

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
	V_BUS[11],
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
	V_BUS_OWNER[sizeof V_BUS],
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
new Ammu_Nation[22],
	Ammu_Nation_Range[6];
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
new AutoSchool_Exam[2],
	AutoSchool[4];
// CheckPoint
new Buy_Weapon,
	Gang_Storage[5],
	Mafia_Storage[3],
	p_gps,
	Bus_Route_CheckPoint;
	// Race
new Freighter_Job;
// Text-Draws
new Text:Corso;
new Text:Capture[2];
// Работы
	// 3D текст
new Text3D: text_trailer[13],
	Text3D: text_bus_route[1];
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
	GangZoneMinuts,
	Captured_Zones[6];
//TD
new PlayerText: ChoseSkin[8],
	PlayerText: Press_ALT[5],
	PlayerText: Wanted_New_Cash;
//Динамические зоны
new police_press_alt[4];
// Gang Zone
new army;
// Скины
new male_skins[] = {
	3,6,136,78,200,137,79,2,7,230
};

new female_skins[] = {
	10,11,12,13,40
};
// Тир в Амунаций
new target_frame[9],
	target_shot[MAX_PLAYERS];
	//Ammu-Nation LV
new target_lv_1[7],
	target_lv_2[7],
	target_lv_3[7];
	//Ammu-Nation Central LS
new target_ls_1[7],
	target_ls_2[7],
	target_ls_3[7];
	
new LoopStatus[6] = 0,
	target_count_lv = 0,
	target_count_ls = 0;
// All
new Streams[][][] = {
	{"Выключить радио\n", ""},
	{"Включить музыку с URL\n", ""},
	{"SESHstation", "https://stream.sesh.team/stream.m3u"}
};

new gSpectateID[MAX_PLAYERS];
new gSpectateType[MAX_PLAYERS];

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
new Traffic_Laws_ExamQuestions[17][77] = {
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
	"Что следует делать при возникновении ДТП в первую очередь?",//14
	"Где могут двигаться пешеходы в жилой зоне?",//15
	"Более устойчив против опрокидывания на повороте легковой автомобиль:"//16
};
new Traffic_Laws_ExamAnswers[17][4][E_EXAM_ANSWER] =
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
	{ // 15 
		{"1. Включить аварийную сигнализацию.",false},
		{"2. Вызвать скорую помощь и полицию.",false},
		{"3. Если есть пострадавшие, оказать первую помощь.",false},
		{"4. Все ответы верны.",true}
	},
	{
		{"1. Только по тротуарам.",false},
		{"2. По тротуарам и в один ряд по краю проезжей части.",false},
		{"3. По тротуарам и по всей ширине проезжей части.",true},
		{"",false}
	},
	{
		{"1. Без пассажиров и груза.",true},
		{"2. Без пассажиров, но с грузом на верхнем багажнике.",false},
		{"3. С пассажирами, но без груза.",false},
		{"4. С пассажирами и грузом.",false}
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
// Русификатор
new  
    TextRusTD[RussifierType]; 

const 
    Float:TEXT_BASE_X = 150.0, 
    Float:TEXT_BASE_Y = 200.0, 
    TEXT_RUSSIFIERS_COUNT = 7; // only Russian localizations 
	
// Работы
	// Автобусники
new Float: Bus_Route[2][][] =
{
	{ // Мэрия ЛС - Авто Школа
		{1108.5847,-1743.1787,13.1255},
		{1162.1027,-1743.0968,13.1255},
		{1173.1707,-1840.3479,13.1344},
		{1260.8370,-1854.6989,13.1099},
		{1391.1296,-1874.6123,13.1099},
		{1511.5068,-1874.5719,13.1099},
		{1551.5702,-1874.6598,13.1099},
		{1571.9684,-1744.9921,13.1099},
		{1481.3604,-1729.6593,13.1099},
		{1407.9941,-1730.1110,13.1177},
		{1386.7400,-1859.2793,13.1099},
		{1513.7930,-1874.2997,13.1099},
		{1527.4628,-1935.4329,17.0592},
		{1561.3003,-2109.7930,33.1241},
		{1698.8914,-2168.6292,15.6006},
		{1809.5581,-2168.9553,13.1099},
		{1977.1396,-2168.6111,13.1029},
		{2131.4268,-2214.4255,13.1099},
		{2101.2773,-2264.4202,13.1099},
		{2176.0173,-2362.3379,13.1047},
		{2157.5791,-2489.1216,13.1021},
		{2043.5085,-2667.4995,12.0904},
		{1465.9811,-2667.6938,11.9373},
		{1349.0151,-2507.2383,13.1021},
		{1349.2701,-2332.8137,13.1099},
		{1415.2971,-2288.7905,13.1099},
		{1445.4700,-2329.4968,13.1099},
		{1522.1954,-2301.8853,13.1127},
		{1562.3396,-2288.7280,13.1150},
		{1573.3052,-2309.3853,13.1044},
		{1604.3743,-2321.4333,13.1099},
		{1673.4456,-2321.0862,13.1099},
		{1708.6757,-2321.5964,13.1099},
		{1734.6233,-2292.5203,13.1026},
		{1692.2452,-2251.4836,13.1099},
		{1629.6747,-2251.3970,13.0528},
		{1573.8578,-2269.3232,13.1067},
		{1533.9891,-2284.2361,13.1099},
		{1426.3938,-2273.2253,13.1150},
		{1355.3439,-2268.7268,13.1161},
		{1363.4644,-2180.9526,13.1099},
		{1563.0739,-2124.4121,15.3682},
		{1642.7175,-1860.5227,25.1963},
		{1613.6685,-1499.4844,28.3130},
		{1660.8654,-1160.2278,56.7423},
		{1685.9250,-1081.5369,54.9610},
		{1554.4227,-924.5225,43.8341,},
		{1353.5103,-928.6450,34.0440},
		{1105.8395,-943.8044,42.3977},
		{844.9363,-1014.5017,28.1247},
		{597.6831,-1213.2773,17.7161},
		{377.4228,-1355.8909,14.1964},
		{167.4664,-1522.2887,11.9047},
		{72.9597,-1525.0894,4.5586},
		{-129.7750,-1212.6917,2.4224},
		{-87.5322,-1114.6371,1.1677},
		{-222.9805,-909.0341,40.7539},
		{-461.3665,-843.9791,49.9755},
		{-757.9784,-1002.4285,77.1644},
		{-881.1935,-1102.0363,97.5124},
		{-959.1246,-1043.3789,95.8824},
		{-1218.8394,-775.6454,63.6398},
		{-1367.1880,-813.4216,79.3453},
		{-1578.3300,-802.0889,50.0744},
		{-1721.4808,-736.3987,35.0611},
		{-1759.4224,-598.3183,16.0054},
		{-1803.2820,-573.7614,15.7570},
		{-1973.1827,-577.5978,25.3885},
		{-2109.7537,-532.4637,34.0584},
		{-2251.9326,-315.2766,49.7083},
		{-2251.8042,-208.3624,35.1256},
		{-2251.8042,-83.0972,34.8990},
		{-2026.9076,-72.5796,34.8989},
		{-1964.4658,-66.8159,25.5119},
		{-1812.9141,-118.4531,5.2246},
		{-1801.2770,-267.7229,20.1350},
		{-1820.8662,-561.0198,15.9622},
		{-1781.6735,-584.9821,16.0630},
		{-1764.4608,-624.6641,16.9007},
		{-1680.3319,-768.0688,41.0888},
		{-1447.7957,-822.0767,75.2153},
		{-1235.7281,-778.6190,64.2888},
		{-1098.3738,-906.7896,76.8951},
		{-899.7525,-1111.5078,98.4636},
		{-813.4388,-1012.8868,82.4606},
		{-533.4986,-913.9109,56.2773},
		{-305.6050,-873.8811,46.5771},
		{-170.7385,-952.4842,30.8579},
		{-88.4613,-1101.2805,3.5328},
		{-135.8832,-1212.0082,2.4225},
		{-132.6728,-1456.8364,2.4224},
		{32.4570,-1536.1552,4.8324},
		{128.2942,-1556.9399,8.7592},
		{179.0291,-1533.1232,12.3001},
		{217.0309,-1521.9155,17.2042},
		{281.0929,-1487.6144,31.9721},
		{237.8120,-1568.7598,32.7700},
		{284.7267,-1640.2594,32.8833},
		{614.9629,-1679.0413,15.7266},
		{794.9378,-1676.8560,13.0704},
		{904.0871,-1575.2549,13.1099},
		{919.8911,-1418.7869,12.9514},
		{1048.3239,-1409.1052,13.0670},
		{1215.1750,-1408.2607,12.9287},
		{1327.5646,-1407.9878,13.0593},
		{1326.1893,-1484.9458,13.1099},
		{1295.1295,-1682.6511,13.1099},
		{1294.7349,-1836.0475,13.1099},
		{1364.3835,-1871.3136,13.1099}
	},
	{ // Мэрия ЛС - Банк
		{1110.8948,-1743.3965,13.4964},
		{1160.6689,-1743.4645,13.4933},
		{1172.8970,-1837.8068,13.5009},
		{1285.0828,-1855.0142,13.4820},
		{1392.6615,-1874.9890,13.4923},
		{1552.3798,-1875.3862,13.4842},
		{1572.0784,-1804.9308,13.4832},
		{1572.0408,-1747.0170,13.4833},
		{1485.0798,-1729.8295,13.4834},
		{1327.0942,-1730.0822,13.4829},
		{1315.0854,-1620.2205,13.4847},
		{1359.2083,-1434.4419,13.4861},
		{1282.7415,-1392.3820,13.3492},
		{1092.5985,-1393.5048,13.6289},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0},
		{0.0,0.0,0.0}
	}
};