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
	GangZoneMinuts,
	Captured_Zones[6];
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
new Float: Bus_Route[1][][] =
{
	{ // Мэрия ЛС - Авто Школа
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
		{962.9703,-1392.9751,13.1946},
		{817.1071,-1392.9729,13.4904},
		{652.0573,-1392.2886,13.5745},
		{508.2496,-1414.0692,16.0773},
		{351.1371,-1517.6617,33.1659},
		{263.9750,-1572.7380,33.0575},
		{275.2678,-1515.1915,32.3513},
		{265.4745,-1477.0023,28.5989},
		{193.2150,-1518.1161,12.8864},
		{155.4156,-1541.9231,10.9141},
		{44.5384,-1521.4341,5.2417},
		{-109.8505,-1478.1614,2.7960},
		{-126.3167,-1204.4745,2.7949},
		{-91.0433,-1122.6064,1.1905},
		{-132.2491,-975.5624,26.2817},
		{-283.8061,-876.6829,46.2458},
		{-458.2804,-841.1224,50.1393},
		{-596.6969,-966.3015,63.1597},
		{-694.6760,-1005.2303,72.6382},
		{-871.3551,-1067.1866,93.0333},
		{-983.7172,-1017.6024,95.2420},
		{-1098.2572,-900.4852,76.7594},
		{-1210.7714,-784.2886,64.3183},
		{-1271.2096,-791.9222,68.5489},
		{-1448.6626,-817.1611,75.6686},
		{-1590.3871,-798.5839,49.2870},
		{-1740.6055,-719.1315,31.0045},
		{-1759.3130,-598.7896,16.3743},
		{-1802.5197,-576.0484,16.2331},
		{-1969.0471,-577.0052,25.4459},
		{-2073.5698,-562.2826,30.6403},
		{-2171.4092,-472.6181,46.4921},
		{-2251.4138,-316.0574,50.1557},
		{-2252.7241,-204.7092,35.3994},
		{-2251.7527,-85.0706,35.2692},
		{-2182.1985,-72.8102,35.2699},
		{-2025.9758,-72.7256,35.2732},
		{-1936.7421,-67.5761,25.6511},
		{-1814.3055,-118.7855,5.5972},
		{-1801.6949,-218.7410,17.5603},
		{-1806.4430,-344.0307,21.8520},
		{-1821.0569,-432.2069,15.0385},
		{-1821.6586,-560.9583,16.3355},
		{-1782.4004,-584.7834,16.4371},
		{-1758.2474,-705.4946,27.9469},
		{-1606.0906,-799.9493,48.0662},
		{-1481.5258,-823.6598,67.1627},
		{-1346.1140,-817.6686,77.2409},
		{-1238.1754,-779.9633,65.0068},
		{-1159.1396,-845.0097,67.7793},
		{-1065.3800,-941.5453,82.8673},
		{-984.6949,-1024.7240,95.4520},
		{-899.8729,-1111.6290,98.8397},
		{-871.9296,-1086.9945,95.3129},
		{-707.5451,-1011.3065,73.6916},
		{-578.7609,-960.1398,61.6571},
		{-484.5206,-866.9391,52.1205},
		{-404.4693,-831.3943,47.6124},
		{-313.9480,-871.3665,46.9655},
		{-188.7889,-938.3931,34.2988},
		{-98.0340,-1026.4336,24.2003},
		{-95.0196,-1119.3201,1.2968},
		{-133.4718,-1202.6857,2.8016},
		{-151.5789,-1309.4395,2.7957},
		{-154.7346,-1385.9117,2.7957},
		{-136.3129,-1451.1656,2.7958},
		{-88.1129,-1503.3081,2.7994},
		{-37.5673,-1518.3154,1.9215},
		{27.8760,-1535.4016,4.8932},
		{159.8887,-1593.0145,13.1529},
		{215.4980,-1662.1573,12.4454},
		{324.7100,-1716.6766,6.6215},
		{419.5761,-1719.3799,9.2523},
		{545.2446,-1734.7151,12.5647},
		{625.5590,-1747.7015,13.3689},
		{780.0814,-1785.1552,13.1391},
		{903.9519,-1789.4482,13.5027},
		{1005.6660,-1809.7793,14.1503},
		{1039.8827,-1735.4723,13.4826},
		{1153.1807,-1714.4501,13.8834},
		{1172.6649,-1837.1366,13.5075}
	}
};
