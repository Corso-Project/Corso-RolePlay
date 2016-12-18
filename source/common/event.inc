public OnGameModeInit()
{
	// Дополнительная конфигурация
	INI_Load("budget.ini");
	INI_Load("mysql.ini");
	INI_Load("prices.ini");
	INI_Load("settings.ini");
	// Подключение MySQL
	mysql_log(ERROR | WARNING | INFO | DEBUG);
	mysql_connect(g_MySQL_Host,g_MySQL_User,g_MySQL_Password,g_MySQL_Database);
	if(mysql_errno() != 0) {
	    print("\n[Ошибка]: Внимание! Подключение к базе данных MySQL не установлено.\n");
		SendRconCommand("exit");
	    return 0;
	}
	// АЗС
	mysql_tquery(MySQL:1,"SELECT * FROM `petrol_stations`", "OnMySQL_SelectPetrolStations");
	// Параметры игрового режима
	SendRconCommand("loadfs map");
	SetGameModeText(GAMEMODE_VERSION);
	SetMaxConnections(1);
	ShowNameTags(1);
	ShowPlayerMarkers(0);
	EnableStuntBonusForAll(0);
	DisableNameTagLOS();
	DisableInteriorEnterExits();
	ManualVehicleEngineAndLights();
	gettime(g_hour, g_minute);
	OnWeatherChanger();
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED);
	for(new i=0; i < sizeof(ZoneInfo); i++)
		ZoneID[i] = GangZoneCreate(ZoneInfo[i][zMinX], ZoneInfo[i][zMinY], ZoneInfo[i][zMaxX], ZoneInfo[i][zMaxY]);
	//==========================================================================
	// Pay'n'Spray
	CreateDynamicMapIcon(1025.05,-1024.23,32.1, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(487.68,-1740.87,11.13, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(-1420.73,2583.37,55.56, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(-1904.39,284.97,40.75, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(-2425.91,1022.33,50.10, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(1975.60,2162.16,10.77, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(2065.38,-1831.51,13.25, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(-99.55,1118.36,19.44, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(721.07,-455.94,16.04, 63, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(2393.74,1493.01,10.52, 63, 0xFFFFFFFF, 0,0);
	// Modding shops
	CreateDynamicMapIcon(2644.252,-2028.246,12.5547, 27, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(1043.4,-1025.3,34.4, 27, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(2386.4558,1041.3969,10.8203, 27, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(-2716.514404,218.293624,4.077047, 27, 0xFFFFFFFF, 0,0);
	CreateDynamicMapIcon(-1936.977172,236.758300,33.975135, 27, 0xFFFFFFFF, 0,0);
	// Станция грузчиков
	CreateDynamicMapIcon(-1056.0469,-632.4141,82.7891, 51, 0xFFFFFFFF, 0,0);
	//Police Departament
	CreateDynamicMapIcon(1555.5056,-1675.6830,16.1953,30,0xFFFFFFFF,0,0); //Los Santos Police Departament
	//Ammu-Nation
	CreateDynamicMapIcon(1368.9360,-1279.7216,13.5469,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(-2625.8296,208.2379,4.8125,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2159.5449,943.2165,10.8203,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2400.5959,-1981.9949,13.5469,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2539.5420,2084.0088,10.8203,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(-2093.7271,-2464.8933,30.6250,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(-316.1618,829.9474,14.2422,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(776.7205,1871.4976,4.9072,6,0xFFFFFFFF,0,0);
	// Casino
	CreateDynamicMapIcon(2019.3190,1007.7921,10.8203,43,0xFFFFFFFF,0,0);
	//==========================================================================
	// Правительство Штата
	V_GOVERNMENT[0] = Vehicle_Add(489, 1246.6714, -2010.0225, 59.5282, 0.0000,1,1);
	V_GOVERNMENT[1] = Vehicle_Add(489, 1250.9849, -2010.0314, 59.4050, 0.0000,1,1);
	V_GOVERNMENT[2] = Vehicle_Add(489, 1256.0861, -2009.9465, 59.2592, 0.0000,1,1);
	V_GOVERNMENT[3] = Vehicle_Add(489, 1260.8561, -2009.9620, 59.1229, 0.0000,1,1);
	// Федеральное Бюро Расследований
	V_FBI[0] = Vehicle_Add(427, 1262.2622, -1648.6503, 13.6227, 220.0000);
	V_FBI[1] = Vehicle_Add(427, 1263.8562, -1642.9408, 13.6227, 220.0000);
	V_FBI[2] = Vehicle_Add(490, 1265.2472, -1662.2999, 13.7971, 0.0000);
	V_FBI[3] = Vehicle_Add(490, 1266.2246, -1673.2351, 13.7971, 0.0000);
	V_FBI[4] = Vehicle_Add(490, 1261.2570, -1672.5151, 13.7971, 0.0000);
	V_FBI[5] = Vehicle_Add(497, 1254.7615, -1685.4443, 34.9332, 0.0000, 0,0);
	V_FBI[6] = Vehicle_Add(497, 1230.9314, -1685.1746, 34.9332, 0.0000, 0,0);
	// Полиция Лос Сантос
	V_LSPD[0] = Vehicle_Add(596,1554.5928,-1615.0944,13.1075,143.0);
	V_LSPD[1] = Vehicle_Add(523,1560.2781,-1614.7255,13.1065,143.0);
	V_LSPD[2] = Vehicle_Add(596,1565.3577,-1615.1208,13.1006,143.0);
	V_LSPD[3] = Vehicle_Add(596,1570.3990,-1615.1421,13.1035,143.0);
	V_LSPD[4] = Vehicle_Add(596,1575.5455,-1615.0767,13.1051,143.0);
	V_LSPD[5] = Vehicle_Add(596,1602.4196,-1683.8865,5.6119,269.8652);
	V_LSPD[6] = Vehicle_Add(596,1591.4985,-1711.0421,5.6128,0.0437);
	V_LSPD[7] = Vehicle_Add(596,1602.2015,-1687.9944,5.6107,89.8454);
	V_LSPD[8] = Vehicle_Add(596,1602.0392,-1692.0045,5.6110,89.1947);
	V_LSPD[9] = Vehicle_Add(596,1595.4047,-1711.5936,5.6116,180.3378);
	V_LSPD[10] = Vehicle_Add(523,1582.1798,-1667.0845,5.4650,240.5349);
	V_LSPD[11] = Vehicle_Add(523,1582.3419,-1669.2539,5.4650,239.3729);
	V_LSPD[12] = Vehicle_Add(523,1582.1704,-1671.2072,5.4657,237.9856);
	V_LSPD[13] = Vehicle_Add(523,1582.1514,-1673.4630,5.4652,238.0086);
	// Полиция Сан Фиерро
	V_SFPD[0] = Vehicle_Add(497,-1679.7035,706.0008,30.7781,89.8724);
	V_SFPD[1] = Vehicle_Add(523,-1576.0360,673.7034,6.7563,174.5967);
	V_SFPD[2] = Vehicle_Add(523,-1575.9231,650.4584,6.7582,0.9076);
	V_SFPD[3] = Vehicle_Add(523,-1612.2233,674.1516,6.7545,184.0847);
	V_SFPD[4] = Vehicle_Add(597,-1593.6233,651.7213,6.9566,1.3899);
	V_SFPD[5] = Vehicle_Add(597,-1622.5198,651.7484,6.9555,359.8126);
	V_SFPD[6] = Vehicle_Add(597,-1573.9720,726.4003,-5.4722,91.1968);
	V_SFPD[7] = Vehicle_Add(597,-1596.5836,749.3448,-5.4725,178.5932);
	V_SFPD[8] = Vehicle_Add(597,-1606.3083,673.1804,6.9553,179.1846);
	V_SFPD[9] = Vehicle_Add(597,-1610.8358,651.5052,6.9564,359.9975);
	V_SFPD[10] = Vehicle_Add(597,-1622.9977,653.4961,-5.4742,89.9343);
	V_SFPD[11] = Vehicle_Add(597,-1639.4895,677.9890,-5.4743,269.9376);
	// Полиция Лас Вентурас
	V_LVPD[0] = Vehicle_Add(523,2297.4980,2464.5881,1.0,88.5560);
	V_LVPD[1] = Vehicle_Add(598,2269.0366,2460.2317,8.9674,181.9338);
	V_LVPD[2] = Vehicle_Add(598,2276.6790,2473.7705,1.4201,184.7489);
	V_LVPD[3] = Vehicle_Add(598,2315.3213,2464.7903,1.4219,270.0937);
	V_LVPD[4] = Vehicle_Add(598,2299.4771,2451.7512,3.4199,270.3331);
	V_LVPD[5] = Vehicle_Add(598,2278.0327,2459.1831,8.9495,1.6668);
	V_LVPD[6] = Vehicle_Add(598,2255.8301,2443.1006,8.9475,179.7459);
	V_LVPD[7] = Vehicle_Add(598,2239.7317,2456.6294,1.4036,88.4757);
	V_LVPD[8] = Vehicle_Add(598,2314.2158,2484.8979,3.3994,92.8849);
	V_LVPD[9] = Vehicle_Add(598,2240.0923,2436.7124,3.4017,91.8532);
	// Национальная гвардия
	V_MILITARY[0] = Vehicle_Add(470,304.7515,1839.3784,17.5989,336.0933);
	V_MILITARY[1] = Vehicle_Add(433,301.7500,1863.8750,18.0533,360.0000);
	V_MILITARY[2] = Vehicle_Add(548,296.0859,1925.9017,19.3104,236.2604);
	V_MILITARY[3] = Vehicle_Add(548,314.9759,2046.6259,19.2481,157.8634);
	V_MILITARY[4] = Vehicle_Add(548,350.5939,1984.1194,19.3047,92.2205);
	V_MILITARY[5] = Vehicle_Add(470,282.3898,1955.3890,17.6341,270.8638);
	V_MILITARY[6] = Vehicle_Add(433,277.9318,2020.2458,18.0773,271.3422);
	V_MILITARY[7] = Vehicle_Add(433,277.5226,2025.6991,18.0772,270.0389);
	V_MILITARY[8] = Vehicle_Add(470,183.5019,1930.6356,17.8497,181.7918);
	V_MILITARY[9] = Vehicle_Add(470,270.1317,1830.0344,17.6344,143.8543);
	V_MILITARY[10] = Vehicle_Add(470,121.0928,1926.0619,19.0886,306.0423);
	V_MILITARY[11] = Vehicle_Add(470,103.0628,1914.8339,18.3727,40.8428);
	V_MILITARY[12] = Vehicle_Add(470,134.6078,1849.7643,17.6816,91.4023);
	V_MILITARY[13] = Vehicle_Add(433,301.8881,1877.5836,18.0772,359.7517);
	V_MILITARY[14] = Vehicle_Add(548,359.2137,1913.9470,19.2744,133.3756);
	// Служба экстренной помощи
	V_EMERGENCY[0] = Vehicle_Add(416,2033.1270,-1432.2743,17.2845,180.0169);
	V_EMERGENCY[1] = Vehicle_Add(416,2016.3477,-1414.9769,17.1412,86.7151);
	V_EMERGENCY[2] = Vehicle_Add(416,1590.5470,1849.9900,10.9690,359.8599);
	V_EMERGENCY[3] = Vehicle_Add(544,1769.6177,2075.1941,11.0567,179.5683);
	V_EMERGENCY[4] = Vehicle_Add(544,1750.6584,2077.1130,11.0558,180.0440);
	V_EMERGENCY[5] = Vehicle_Add(544,1763.4852,2076.7075,11.0525,179.6720);
	V_EMERGENCY[6] = Vehicle_Add(544,1757.0782,2075.0398,11.0568,177.5558);
	V_EMERGENCY[7] = Vehicle_Add(416,-2643.2285,630.0392,14.6034,87.3837);
	V_EMERGENCY[8] = Vehicle_Add(416,-2683.8833,628.2059,14.6035,272.5255);
	V_EMERGENCY[9] = Vehicle_Add(416,-2668.5364,610.7019,14.6043,179.8035);
	V_EMERGENCY[10] = Vehicle_Add(416,-2639.3809,609.7971,14.6020,180.4547);
	V_EMERGENCY[11] = Vehicle_Add(544,-2053.1836,75.5582,28.6258,91.8533);
	V_EMERGENCY[12] = Vehicle_Add(544,-2020.6779,75.7322,28.2849,270.8804);
	V_EMERGENCY[13] = Vehicle_Add(544,-2020.4115,92.3531,28.1826,271.5041);
	// Такси
	V_TAXI[0] = Vehicle_Add(420, 1552.7000, -2211.7000, 13.5000, 180.0000, 1,1);
	V_TAXI[1] = Vehicle_Add(438, 1546.2400, -2211.7000, 13.7000, 180.0000, 1,1);
	V_TAXI[2] = Vehicle_Add(420, 1539.6400, -2211.7000, 13.5000, 180.0000, 1,1);
	V_TAXI[3] = Vehicle_Add(438, 1533.1000, -2211.7000, 13.7000, 180.0000, 1,1);
	V_TAXI[4] = Vehicle_Add(420, 1526.6000, -2211.7000, 13.5000, 180.0000, 1,1);
	V_TAXI[5] = Vehicle_Add(438, 1518.6800, -2211.7000, 13.7000, 180.0000, 1,1);
	V_TAXI[6] = Vehicle_Add(420, 1512.1400, -2211.7000, 13.5000, 180.0000, 1,1);
	V_TAXI[7] = Vehicle_Add(438, 1505.5600, -2211.7000, 13.7000, 180.0000, 1,1);
	V_TAXI[8] = Vehicle_Add(420, 1499.0200, -2211.7000, 13.5000, 180.0000, 1,1);
	V_TAXI[9] = Vehicle_Add(438, 1492.5000, -2211.7000, 13.7000, 180.0000, 1,1);
	V_TAXI[10] = Vehicle_Add(420, -1976.0000, 173.0000, 27.2000, 90.0000, 1,1);
	V_TAXI[11] = Vehicle_Add(438, -1976.0000, 178.0000, 27.2000, 90.0000, 1,1);
	V_TAXI[12] = Vehicle_Add(420, -1976.0000, 183.0000, 27.2000, 90.0000, 1,1);
	V_TAXI[13] = Vehicle_Add(438, -1976.0000, 188.0000, 27.2000, 90.0000, 1,1);
	V_TAXI[14] = Vehicle_Add(420, -1976.0000, 193.0000, 27.2000, 90.0000, 1,1);
	V_TAXI[15] = Vehicle_Add(438, -1976.0000, 198.0000, 27.2000, 90.0000, 1,1);
	V_TAXI[16] = Vehicle_Add(420, 2794.7000, 1295.0000, 10.5000, 180.0000, 1,1);
	V_TAXI[17] = Vehicle_Add(438, 2788.3999, 1295.0000, 10.5000, 180.0000, 1,1);
	V_TAXI[18] = Vehicle_Add(420, 2782.0000, 1295.0000, 10.5000, 180.0000, 1,1);
	V_TAXI[19] = Vehicle_Add(438, 2775.6001, 1295.0000, 10.5000, 180.0000, 1,1);
	V_TAXI[20] = Vehicle_Add(420, 2769.3000, 1295.0000, 10.5000, 180.0000, 1,1);
	// Инженерные
	V_ENGINEER[0] = Vehicle_Add(525, 1552.7000, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[1] = Vehicle_Add(552, 1546.2400, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[2] = Vehicle_Add(525, 1539.6400, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[3] = Vehicle_Add(525, 1526.6000, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[4] = Vehicle_Add(552, 1533.1000, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[5] = Vehicle_Add(552, 1518.6800, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[6] = Vehicle_Add(525, 1512.1400, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[7] = Vehicle_Add(552, 1505.5600, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[8] = Vehicle_Add(525, 1499.0200, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[9] = Vehicle_Add(552, 1492.5000, -2361.0000, 13.5000, 0.0000);
	V_ENGINEER[10] = Vehicle_Add(525, -2031.0000, 170.0000, 28.7000, -90.0000);
	V_ENGINEER[11] = Vehicle_Add(552, -2031.0000, 177.0000, 28.7000, -90.0000);
	V_ENGINEER[12] = Vehicle_Add(525, 2766.0000, 1288.0000, 10.5000, -90.0000);
	V_ENGINEER[13] = Vehicle_Add(552, 2766.0000, 1281.6000, 10.5000, -90.0000);
	V_ENGINEER[14] = Vehicle_Add(525, 2766.0000, 1275.3000, 10.5000, -90.0000);
	V_ENGINEER[15] = Vehicle_Add(552, 2766.0000, 1268.8000, 10.5000, -90.0000);
	// Грузоперевозчики
	V_FREIGHTER[0] = Vehicle_Add(403, -1004.0000, -623.1000, 32.5000, 90.0000);
	V_FREIGHTER[1] = Vehicle_Add(514, -1004.0000, -628.2000, 32.5000, 90.0000);
	V_FREIGHTER[2] = Vehicle_Add(515, -1004.0000, -633.3000, 33.0000, 90.0000);
	V_FREIGHTER[3] = Vehicle_Add(403, -1004.0000, -638.4000, 32.5000, 90.0000);
	V_FREIGHTER[4] = Vehicle_Add(514, -1004.0000, -643.5000, 32.5000, 90.0000);
	V_FREIGHTER[5] = Vehicle_Add(515, -1004.0000, -648.6000, 33.0000, 90.0000);
	V_FREIGHTER[6] = Vehicle_Add(403, -1004.0000, -653.7000, 32.5000, 90.0000);
	V_FREIGHTER[7] = Vehicle_Add(514, -1004.0000, -658.8000, 32.5000, 90.0000);
	V_FREIGHTER[8] = Vehicle_Add(515, -1004.0000, -663.9000, 33.0000, 90.0000);
	V_FREIGHTER[9] = Vehicle_Add(403, -1004.0000, -669.9000, 32.5000, 90.0000);
	V_FREIGHTER[10] = Vehicle_Add(514, -1004.0000, -674.1000, 32.5000, 90.0000);
	V_FREIGHTER[11] = Vehicle_Add(515, -1004.0000, -679.2000, 33.0000, 90.0000);
	V_FREIGHTER[12] = Vehicle_Add(403, -1004.0000, -684.3000, 32.5000, 90.0000);
	// Прицеп с топливом
	V_PETROL_TRAILER[0] = Vehicle_Add(584, -980.0000, -623.1000, 33.0000, 90.0000);
	V_PETROL_TRAILER[1] = Vehicle_Add(584, -980.0000, -628.2000, 33.0000, 90.0000);
	V_PETROL_TRAILER[2] = Vehicle_Add(584, -980.0000, -633.3000, 33.0000, 90.0000);
	V_PETROL_TRAILER[3] = Vehicle_Add(584, -980.0000, -638.4000, 33.0000, 90.0000);
	V_PETROL_TRAILER[4] = Vehicle_Add(584, -980.0000, -643.5000, 33.0000, 90.0000);
	V_PETROL_TRAILER[5] = Vehicle_Add(584, -980.0000, -648.6000, 33.0000, 90.0000);
	V_PETROL_TRAILER[6] = Vehicle_Add(584, -980.0000, -653.7000, 33.0000, 90.0000);
	V_PETROL_TRAILER[7] = Vehicle_Add(584, -980.0000, -658.8000, 33.0000, 90.0000);
	V_PETROL_TRAILER[8] = Vehicle_Add(584, -980.0000, -663.9000, 33.0000, 90.0000);
	V_PETROL_TRAILER[9] = Vehicle_Add(584, -980.0000, -669.0000, 33.0000, 90.0000);
	V_PETROL_TRAILER[10] = Vehicle_Add(584, -980.0000, -674.1000, 33.0000, 90.0000);
	V_PETROL_TRAILER[11] = Vehicle_Add(584, -980.0000, -679.2000, 33.0000, 90.0000);
	V_PETROL_TRAILER[12] = Vehicle_Add(584, -980.0000, -684.3000, 33.0000, 90.0000);
	// Для аренды
	V_RENT[0] = Vehicle_Add(462, 1560.5000, -2237.7600, 13.3000, 90.0000);
	V_RENT[1] = Vehicle_Add(462, 1560.5000, -2241.1001, 13.1000, 90.0000);
	V_RENT[2] = Vehicle_Add(462, 1560.5000, -2234.5000, 13.1000, 90.0000);
	V_RENT[3] = Vehicle_Add(462, 1560.5000, -2244.4500, 13.3000, 90.0000);
	V_RENT[4] = Vehicle_Add(462, 1560.5000, -2247.7002, 13.1000, 90.0000);
	V_RENT[5] = Vehicle_Add(462, 1560.5000, -2250.9399, 13.3000, 90.0000);
	V_RENT[6] = Vehicle_Add(462, 1560.5000, -2254.3000, 13.1000, 90.0000);
	V_RENT[7] = Vehicle_Add(462, 1560.5000, -2257.5000, 13.3000, 90.0000);
	V_RENT[8] = Vehicle_Add(462, 1560.5000, -2260.8000, 13.1000, 90.0000);
	V_RENT[9] = Vehicle_Add(462, 1560.5000, -2264.0801, 13.3000, 90.0000);
	V_RENT[10] = Vehicle_Add(401, 1560.6924, -2338.4568, 13.3265, 90.0);
	V_RENT[11] = Vehicle_Add(527, 1560.6257, -2331.8857, 13.2636, 90.0);
	V_RENT[12] = Vehicle_Add(475, 1560.5176, -2325.3398, 13.3522, 90.0);
	V_RENT[13] = Vehicle_Add(436, 1560.6837, -2318.7056, 13.3194, 90.0);
	V_RENT[14] = Vehicle_Add(410, 1560.4878, -2312.1973, 13.1999, 90.0);
	V_RENT[15] = Vehicle_Add(462, -1978.0000, 105.0000, 27.2000, 90.0000);
	V_RENT[16] = Vehicle_Add(462, -1978.0000, 103.0000, 27.2000, 90.0000);
	V_RENT[17] = Vehicle_Add(462, -1978.0000, 101.0000, 27.2000, 90.0000);
	V_RENT[18] = Vehicle_Add(462, -1978.0000, 99.0000, 27.2000, 90.0000);
	V_RENT[19] = Vehicle_Add(462, -1978.0000, 97.0000, 27.2000, 90.0000);
	V_RENT[20] = Vehicle_Add(462, -1978.0000, 95.0000, 27.2000, 90.0000);
	V_RENT[21] = Vehicle_Add(462, -1978.0000, 93.0000, 27.2000, 90.0000);
	V_RENT[22] = Vehicle_Add(462, -1978.0000, 91.0000, 27.2000, 90.0000);
	V_RENT[23] = Vehicle_Add(462, -1978.0000, 89.0000, 27.2000, 90.0000);
	V_RENT[24] = Vehicle_Add(462, -1978.0000, 87.0000, 27.2000, 90.0000);
	V_RENT[25] = Vehicle_Add(401, -1989.0000, 275.0000, 35.0000, -90.0000);
	V_RENT[26] = Vehicle_Add(527, -1989.0000, 270.0000, 35.0000, -90.0000);
	V_RENT[27] = Vehicle_Add(507, -1989.0000, 265.0000, 35.0000, -90.0000);
	V_RENT[28] = Vehicle_Add(585, -1989.0000, 260.0000, 35.0000, -90.0000);
	V_RENT[29] = Vehicle_Add(526, -1989.0000, 255.0000, 35.0000, -90.0000);
	V_RENT[30] = Vehicle_Add(546, -1989.0000, 250.0000, 35.0000, -90.0000);
	V_RENT[31] = Vehicle_Add(462, 2854.0000, 1367.7000, 10.3000, 90.0000);
	V_RENT[32] = Vehicle_Add(462, 2854.0000, 1364.5000, 10.3000, 90.0000);
	V_RENT[33] = Vehicle_Add(462, 2854.0000, 1361.3000, 10.3000, 90.0000);
	V_RENT[34] = Vehicle_Add(462, 2854.0000, 1358.1000, 10.3000, 90.0000);
	V_RENT[35] = Vehicle_Add(462, 2854.0000, 1355.0000, 10.3000, 90.0000);
	V_RENT[36] = Vehicle_Add(462, 2854.0000, 1351.7000, 10.3000, 90.0000);
	V_RENT[37] = Vehicle_Add(462, 2854.0000, 1348.5000, 10.3000, 90.0000);
	V_RENT[38] = Vehicle_Add(426, 2805.0000, 1348.6000, 10.5000, -90.0000);
	V_RENT[39] = Vehicle_Add(516, 2805.0000, 1355.0000, 10.5000, -90.0000);
	V_RENT[40] = Vehicle_Add(527, 2805.0000, 1361.4000, 10.5000, -90.0000);
	V_RENT[41] = Vehicle_Add(401, 2805.0000, 1367.8000, 10.5000, -90.0000);
	V_RENT[42] = Vehicle_Add(547, 2805.0000, 1342.2000, 10.5000, -90.0000);
	//==========================================================================
	// Ворота, шлагбаумы
	obj_FBI = CreateDynamicObject(16773, 1286.17004, -1652.09998, 16.55000,   0.00000, 0.00000, 90.00000);
	obj_LSPD = CreateDynamicObject(968, 1544.68994, -1630.98999, 13.22000,   0.00000, 90.00000, 90.00000);
	obj_SFPD[0] = CreateDynamicObject(968, -1572.19995, 658.63000, 6.98000,   0.00000, 90.00000, 90.00000);
	obj_SFPD[1] = CreateDynamicObject(968, -1701.43005, 687.79498, 24.78000,   0.00000, 90.00000, 270.00000);
	obj_LVPD = CreateDynamicObject(968, 2238.18994, 2450.21997, 10.71000,   0.00000, 90.00000, 90.00000);
	obj_MILITARY[0] = CreateDynamicObject(19313, 286.00000, 1822.00000, 20.03000,   0.00000, 0.00000, 90.00000);
	obj_MILITARY[1] = CreateDynamicObject(19313, 134.85001, 1941.53406, 21.71000,   0.00000, 0.00000, 180.00000);
	// Мишени
	CreateDynamicObject(19315, 250.77870, 2068.24194, 21.57660,   0.00000, 0.00000, 180.00000);
	CreateDynamicObject(19315, 253.85001, 2072.42725, 20.28720,   0.00000, 0.00000, 180.00000);
	CreateDynamicObject(19315, 262.70380, 2068.51904, 20.64404,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19315, 249.74660, 2068.36279, 17.11980,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19315, 259.59869, 2066.96582, 17.77970,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19315, 269.96164, 2068.13623, 22.56484,   0.00000, 0.00000, 180.00000);
	CreateDynamicObject(19315, 257.19031, 2066.94263, 20.51266,   0.00000, 0.00000, 0.00000);
	// Пикапы Аммунаций
	Ammu_Nation[0] = CreateDynamicPickup(1318,23,1368.9360,-1279.7216,13.5469);
	Ammu_Nation[1] = CreateDynamicPickup(1318,23,285.4752,-41.7966,1001.5156);
	Ammu_Nation[2] = CreateDynamicPickup(1318,23,-2625.8296,208.2379,4.8125);
	Ammu_Nation[3] = CreateDynamicPickup(1318,23,285.9187,-86.7644,1001.5229);
	Ammu_Nation[4] = CreateDynamicPickup(1318,23,2159.5449,943.2165,10.8203);
	Ammu_Nation[5] = CreateDynamicPickup(1318,23,315.8831,-143.6591,999.6016);
	Ammu_Nation[6] = CreateDynamicPickup(1318,23,2400.5959,-1981.9949,13.5469);
	Ammu_Nation[7] = CreateDynamicPickup(1318,23,296.8016,-112.0710,1001.5156);
	// Пикапы Казино
	Casino[0] = CreateDynamicPickup(1318,23,2019.3190,1007.7921,10.8203);
	Casino[1] = CreateDynamicPickup(1318,23,2019.0719,1017.8466,996.8750);
	// Пикапы Полиций
	LSPD[0] = CreateDynamicPickup(1318,23,1555.5056,-1675.6830,16.1953);
	LSPD[1] = CreateDynamicPickup(1318,23,246.8327,62.3205,1003.6406);
	// Пикапы Мэрий
	CityHall[0] = CreateDynamicPickup(1318,23,1481.0337,-1772.3137,18.7958);
	// NPC
	CreateActor(179, 287.9097,-104.5135,1001.5156,176.2943);
	// TextDraw
	Corso = TextDrawCreate(577.000000, 7.000000, "CORSO");
	TextDrawAlignment(Corso, 2);
	TextDrawBackgroundColor(Corso, 0xB1413DAA);
	TextDrawFont(Corso, 2);
	TextDrawLetterSize(Corso, 0.250000, 1.400000);
	TextDrawColor(Corso, 0xB1413DAA);
	TextDrawSetOutline(Corso, 0);
	TextDrawSetProportional(Corso, 1);
	TextDrawSetShadow(Corso, 0);

	return 1;
}

public OnGameModeExit()
{
    SendRconCommand("unloadfs map");
    // Обновление игроков
    foreach(new i : Player) CallLocalFunction("OnPlayerDisconnect", "dd", i,1);
	// Обновление конфигурации
	new INI: txtfile = INI_Open("budget.ini");
	INI_WriteFloat(txtfile, "Government", Budget_GOVERNMENT);
	INI_Close(txtfile);
	txtfile = INI_Open("settings.ini");
	INI_WriteInt(txtfile, "Chat_OOC", g_Chat_OOC);
	INI_Close(txtfile);
	// АЗС
	for(new i; i < sizeof(PS); i++) {
		if(!PS[i][_ps_ormid]) continue;
		orm_update(PS[i][_ps_ormid]);
		orm_destroy(PS[i][_ps_ormid]);
	}
	//Уничтожаем TextDraw-ы
	TextDrawDestroy(Corso);
	for(new i; i < 3; i++){
		TextDrawDestroy(Text:ChoseSkin[i]);
	}
	// Отключение MySQL
	mysql_close();
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	if(!success) {
		new ip_dest[46];
		foreach(new i : Player)
		{
		    GetPlayerIp(i, ip_dest, sizeof(ip_dest));
		    if(!strcmp(ip, ip_dest, false)) continue;
			Message_ToAdmins(0xB9C9BFFF, "[Защита]: Взлом RCON - %s[%d] | %s", Name(i),i,ip_dest);
		    Kick(i);
		}
	}
	return 1;
}
