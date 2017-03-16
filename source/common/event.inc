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
	// GangZones
	mysql_tquery(MySQL:1,"SELECT * FROM `gangzones`", "OnMySQL_SelectGangZones");
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
	CreateDynamicMapIcon(2539.5420,2084.0088,10.8203,6,0xFFFFFFFF,0,0);// Без пикапа
	CreateDynamicMapIcon(-2093.7271,-2464.8933,30.6250,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(-316.1618,829.9474,14.2422,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(776.7205,1871.4976,4.9072,6,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2333.0837,61.5298,26.7058,6,0xFFFFFFFF,0,0);
	// Casino
	CreateDynamicMapIcon(2019.3190,1007.7921,10.8203,43,0xFFFFFFFF,0,0);
	// Работы
	CreateDynamicMapIcon(1622.3585,-1552.2335,13.6824,56,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(-2070.7686,8.4370,35.3203,56,0xFFFFFFFF,0,0);
	// Банды
	CreateDynamicMapIcon(2495.4309,-1691.1400,14.7656,62,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2022.8790,-1120.2637,26.4210,59,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2185.8176,-1814.6786,13.5469,58,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2756.2825,-1182.4691,69.3998,60,0xFFFFFFFF,0,0);
	CreateDynamicMapIcon(2787.0759,-1926.1780,13.5469,61,0xFFFFFFFF,0,0);
	//==========================================================================
	// Правительство Штата
	V_GOVERNMENT[0] = Vehicle_Add(533, 1245.3002, -2043.3801, 59.5569, 270.6839,1,1);
	V_GOVERNMENT[1] = Vehicle_Add(490, 1276.5042, -2032.8441, 59.1283, 88.7442,1,1);
	V_GOVERNMENT[2] = Vehicle_Add(490, 1276.6667, -2024.1534, 59.0894, 90.4294,1,1);
	V_GOVERNMENT[3] = Vehicle_Add(409, 1244.0831, -2020.7385, 59.6821, 180.0797,1,1);
	V_GOVERNMENT[4] = Vehicle_Add(445, 1263.4374, -2010.2500, 59.1971, 179.5778,1,1);
	V_GOVERNMENT[5] = Vehicle_Add(445, 1256.8389, -2010.1326, 59.3873, 179.5774,1,1);
	V_GOVERNMENT[6] = Vehicle_Add(487, 1155.5461, -2053.8367, 69.1791, 271.3965,1,1);
	// Федеральное Бюро Расследований
	V_FBI[0] = Vehicle_Add(497, -2472.19995, 522, 51.3, 0.00, 53, 63);
	V_FBI[1] = Vehicle_Add(490, -2429.7561, 515.2703, 30.0581, 216.0932);
	V_FBI[2] = Vehicle_Add(490, -2425.7576, 518.2924, 30.0575, 222.0774);
	V_FBI[3] = Vehicle_Add(490, -2422.2813, 521.6543, 30.0592, 226.4474);
	V_FBI[4] = Vehicle_Add(490, -2419.0820, 525.0062, 30.0581, 231.1993);
	V_FBI[5] = Vehicle_Add(490, -2414.8752, 531.9378, 30.0554, 247.5684);
/*	V_FBI[6] = Vehicle_Add(490, 1261.2570, -1672.5151, 13.7971, 0.0000);
	V_FBI[7] = Vehicle_Add(497, 1254.7615, -1685.4443, 34.9332, 0.0000, 0,0);
	V_FBI[8] = Vehicle_Add(497, 1230.9314, -1685.1746, 34.9332, 0.0000, 0,0);*/
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
	//Авто-Школа
	V_AUTOSCHOOL[0] = Vehicle_Add(410,-2064.4763,-83.9578,34.9072,180.3327,103,103);
	V_AUTOSCHOOL[1] = Vehicle_Add(410,-2068.7195,-84.2227,34.9070,179.1029,103,103);
	V_AUTOSCHOOL[2] = Vehicle_Add(410,-2072.8586,-84.1812,34.9079,179.3012,103,103);
	V_AUTOSCHOOL[3] = Vehicle_Add(410,-2076.7844,-84.0811,34.9070,179.1321,103,103);
	V_AUTOSCHOOL[4] = Vehicle_Add(410,-2081.0637,-84.0294,34.9071,178.8306,103,103);
	V_AUTOSCHOOL[5] = Vehicle_Add(410,-2085.3965,-84.0140,34.9071,179.4417,103,103);
	V_AUTOSCHOOL[6] = Vehicle_Add(410,-2089.6570,-83.8969,34.9069,179.9201,103,103);
	V_AUTOSCHOOL[7] = Vehicle_Add(410,-2093.5469,-83.8435,34.9072,179.9613,103,103);
	// Грув
	V_GROVE[0] = Vehicle_Add(412,2493.8000,-1681.1999,13.2000,0.0,86,86);
	V_GROVE[1] = Vehicle_Add(492,2489.6001,-1680.8000,13.2000,0.0,86,86);
	V_GROVE[2] = Vehicle_Add(567,2485.8000,-1680.6999,13.2000,0.0,86,86);
	V_GROVE[3] = Vehicle_Add(492,2475.5000,-1676.5000,13.2000,328.0,86,86);
	V_GROVE[4] = Vehicle_Add(405,2472.3999,-1671.5000,13.2000,307.9970,86,86);
	// Баллас
	V_BALLAS[0] = Vehicle_Add(566,2036.1999,-1128.9,24.4,270.0,147,147);
	V_BALLAS[1] = Vehicle_Add(566,2029.0999,-1129.0,24.6,270.0,147,147);
	V_BALLAS[2] = Vehicle_Add(517,2018.4000,-1128.5999,24.9,270.0,147,147);
	V_BALLAS[3] = Vehicle_Add(517,2015.5999,-1143.3,25.0,272.0,147,147);
	V_BALLAS[4] = Vehicle_Add(491,2024.0999,-1143.0998,24.7,272.0,147,147);
	V_BALLAS[5] = Vehicle_Add(566,2032.8000,-1143.0,24.5,272.0,147,147);
	V_BALLAS[6] = Vehicle_Add(412,2040.8000,-1143.1999,24.2,272.0,147,147);
	// Азтекас
	V_AZTECAS[0] = Vehicle_Add(474,2168.8999000,-1807.0,13.2,0.0,165,165);
	V_AZTECAS[1] = Vehicle_Add(575,2165.1001,-1806.9,13.2,0.0,165,165);
	V_AZTECAS[2] = Vehicle_Add(466,2161.1001,-1806.9,13.2,0.0,165,165);
	V_AZTECAS[3] = Vehicle_Add(466,2157.1001,-1807.0,13.2,0.0,165,165);
	V_AZTECAS[4] = Vehicle_Add(567,2173.1001,-1806.6999,13.2,0.0,165,165);
	V_AZTECAS[5] = Vehicle_Add(534,2159.3,-1792.9,13.2,270.0,165,165);
	V_AZTECAS[6] = Vehicle_Add(576,2159.1001,-1797.0,13.2,270.0,165,165);
	// Вагос
	V_VAGOS[0] = Vehicle_Add(474,2761.1113,-1177.4034,69.1072,90.9622,6,1);
	V_VAGOS[1] = Vehicle_Add(576,2742.7019,-1188.0476,69.0791,0.6235,6,6);
	V_VAGOS[2] = Vehicle_Add(576,2742.1958,-1166.2170,69.1452,2.7342,6,6);
	V_VAGOS[3] = Vehicle_Add(467,2742.1863,-1149.0377,69.2538,0.2541,6,6);
	V_VAGOS[4] = Vehicle_Add(467,2742.0378,-1134.9971,69.2553,0.2727,6,6);
	// Рифа
	V_RIFA[0] = Vehicle_Add(536,2774.0278,-1907.8258,11.6699,0.3627,198,198);
	V_RIFA[1] = Vehicle_Add(536,2774.1218,-1919.3033,12.9702,1.0832,198,198);
	V_RIFA[2] = Vehicle_Add(439,2774.0767,-1932.5342,13.3059,0.4862,198,198);
	V_RIFA[3] = Vehicle_Add(439,2774.3379,-1950.8381,13.3063,1.4531,198,198);
	V_RIFA[4] = Vehicle_Add(566,2763.9497,-1911.0905,11.9163,0.3543,198,198);
	V_RIFA[5] = Vehicle_Add(566,2764.1392,-1923.2371,13.1346,0.6155,198,198);
	V_RIFA[6] = Vehicle_Add(475,2764.4043,-1935.8153,13.1914,0.3832,198,198);
	V_RIFA[7] = Vehicle_Add(439,2764.5476,-1945.1934,13.1941,0.4081,198,198);
	// Триады
	V_CHINESE[0] = Vehicle_Add(429,2602.2261,1862.5442,10.5000,268.9338,0,0);
	V_CHINESE[1] = Vehicle_Add(429,2602.1470,1856.1696,10.5005,270.5139,0,0);
	V_CHINESE[2] = Vehicle_Add(561,2592.5845,1862.6935,10.6381,90.7983,0,0);
	V_CHINESE[3] = Vehicle_Add(561,2592.6694,1856.2819,10.6340,90.2919,0,0);
	V_CHINESE[4] = Vehicle_Add(560,2602.0710,1849.7856,10.5253,270.5330,0,0);
	V_CHINESE[5] = Vehicle_Add(560,2602.1421,1843.4707,10.5256,269.5220,0,0);
	V_CHINESE[6] = Vehicle_Add(562,2592.8848,1849.8975,10.4790,90.0678,0,0);
	V_CHINESE[7] = Vehicle_Add(562,2592.8557,1843.4615,10.4790,90.2454,0,0);
	// Русскя Мафия
	V_RUSSIAN[0] = Vehicle_Add(560,983.2957,1737.4088,8.5534,91.2358,0,0);
	V_RUSSIAN[1] = Vehicle_Add(560,983.2543,1743.2643,8.5500,90.8934,0,0);
	V_RUSSIAN[2] = Vehicle_Add(560,982.8906,1728.7925,8.4766,90.5115,0,0);
	V_RUSSIAN[3] = Vehicle_Add(581,983.0646,1722.6996,8.4553,92.4928,0,0);
	V_RUSSIAN[4] = Vehicle_Add(581,966.7562,1707.4666,8.7388,270.1411,0,0);
	V_RUSSIAN[5] = Vehicle_Add(579,962.7622,1757.2515,8.2951,180.6648,0,0);
	V_RUSSIAN[6] = Vehicle_Add(579,957.1893,1757.2397,8.3790,179.5177,0,0);
	V_RUSSIAN[7] = Vehicle_Add(579,950.0536,1720.3049,8.4780,180.0000,0,0);
	// Италианская Мафия
	V_ITALIAN[0] = Vehicle_Add(445,1489.4847,2848.3916,10.9005,179.5161,0,0);
	V_ITALIAN[1] = Vehicle_Add(445,1494.3987,2848.6724,10.5000,179.6496,0,0);
	V_ITALIAN[2] = Vehicle_Add(445,1484.5610,2848.4897,10.6238,180.5806,0,0);
	V_ITALIAN[3] = Vehicle_Add(533,1479.6790,2848.4487,10.6284,179.5388,0,0);
	V_ITALIAN[4] = Vehicle_Add(533,1470.2561,2847.9077,10.6208,179.7856,0,0);
	V_ITALIAN[5] = Vehicle_Add(533,1474.9502,2847.9304,10.6243,178.9046,0,0);
	V_ITALIAN[6] = Vehicle_Add(409,1460.5490,2847.1379,10.6203,180.0582,0,0);
	V_ITALIAN[7] = Vehicle_Add(451,1465.3999,2847.9902,10.6262,179.3685,0,0);
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
	V_RENT[15] = Vehicle_Add(462, 2854.0000, 1367.7000, 10.3000, 90.0000);
	V_RENT[16] = Vehicle_Add(462, 2854.0000, 1364.5000, 10.3000, 90.0000);
	V_RENT[17] = Vehicle_Add(462, 2854.0000, 1361.3000, 10.3000, 90.0000);
	V_RENT[18] = Vehicle_Add(462, 2854.0000, 1358.1000, 10.3000, 90.0000);
	V_RENT[19] = Vehicle_Add(462, 2854.0000, 1355.0000, 10.3000, 90.0000);
	V_RENT[20] = Vehicle_Add(462, 2854.0000, 1351.7000, 10.3000, 90.0000);
	V_RENT[21] = Vehicle_Add(462, 2854.0000, 1348.5000, 10.3000, 90.0000);
	V_RENT[22] = Vehicle_Add(426, 2805.0000, 1348.6000, 10.5000, -90.0000);
	V_RENT[23] = Vehicle_Add(516, 2805.0000, 1355.0000, 10.5000, -90.0000);
	V_RENT[24] = Vehicle_Add(527, 2805.0000, 1361.4000, 10.5000, -90.0000);
	V_RENT[25] = Vehicle_Add(401, 2805.0000, 1367.8000, 10.5000, -90.0000);
	V_RENT[26] = Vehicle_Add(547, 2805.0000, 1342.2000, 10.5000, -90.0000);
	// Аренда транспорта эконом класса
	V_RENT[27] = Vehicle_Add(549, 567.7411, -1289.9541, 16.9023, 102.4603);
	V_RENT[28] = Vehicle_Add(517, 566.4779, -1285.7397, 17.1062, 103.0531);
	V_RENT[29] = Vehicle_Add(404, 565.5590, -1281.8456, 16.9926, 103.0280);
	V_RENT[30] = Vehicle_Add(410, 565.2111, -1277.9575, 16.9003, 102.7820);
	V_RENT[31] = Vehicle_Add(413, 563.8026, -1273.8774, 17.3212, 102.7136);
	V_RENT[32] = Vehicle_Add(479, 562.9036, -1269.7040, 17.0541, 101.4529);
	V_RENT[33] = Vehicle_Add(419, 551.7404, -1263.8223, 17.0030, 212.2984);
	V_RENT[34] = Vehicle_Add(422, 548.4000, -1265.9045, 17.2344, 211.5931);
	V_RENT[35] = Vehicle_Add(467, 545.6901, -1268.2334, 17.0022, 211.2404);
	V_RENT[36] = Vehicle_Add(542, 542.4440, -1270.7157, 17.0088, 214.6165);
	V_RENT[37] = Vehicle_Add(600, 539.0390, -1272.9336, 16.9829, 216.9707);
	V_RENT[38] = Vehicle_Add(439, 536.0904, -1275.5901, 17.1553, 217.0152);
	V_RENT[39] = Vehicle_Add(401, 532.7888, -1277.6384, 16.9990, 218.3660);
	V_RENT[40] = Vehicle_Add(474, 528.7848, -1290.6345, 16.9687, 359.6989);
	V_RENT[41] = Vehicle_Add(576, 524.7858, -1290.5372, 16.8845, 0.1671);
	// Аренда транспорта среднего класса
	V_RENT_STANDART[0] = Vehicle_Add(496, -1969.8522, 307.0460, 34.8905, 181.1986);
	V_RENT_STANDART[1] = Vehicle_Add(507, -1973.4025, 306.1534, 34.9865, 181.2821);
	V_RENT_STANDART[2] = Vehicle_Add(526, -1988.5404, 307.9772, 34.9408, 269.3918);
	V_RENT_STANDART[3] = Vehicle_Add(445, -1988.0979, 304.3044, 34.9996, 270.0682);
	V_RENT_STANDART[4] = Vehicle_Add(580, -1987.9697, 300.3725, 34.9949, 270.4717);
	V_RENT_STANDART[5] = Vehicle_Add(426, -1989.3358, 276.0218, 34.9263, 267.7980);
	V_RENT_STANDART[6] = Vehicle_Add(558, -1989.8579, 272.3896, 34.7981, 266.1813);
	V_RENT_STANDART[7] = Vehicle_Add(533, -1990.2920, 268.7908, 34.9114, 266.9391);
	V_RENT_STANDART[8] = Vehicle_Add(561, -1990.4771, 265.2222, 34.9373, 267.0046);
	V_RENT_STANDART[9] = Vehicle_Add(421, -1990.4192, 261.3848, 35.0217, 266.6927);
	V_RENT_STANDART[10] = Vehicle_Add(589, -1991.1045, 257.9108, 34.8161, 266.3199);
	V_RENT_STANDART[11] = Vehicle_Add(566, -1991.7557, 250.2282, 34.9528, 261.2961);
	V_RENT_STANDART[12] = Vehicle_Add(535, -1991.4877, 254.2502, 34.9367, 262.7495);
	V_RENT_STANDART[13] = Vehicle_Add(527, -1993.0313, 246.0543, 34.8875, 261.7697);
	V_RENT_STANDART[14] = Vehicle_Add(489, -1982.2109, 242.2534, 35.2498, 359.3475);
	V_RENT_STANDART[15] = Vehicle_Add(579, -1978.4880, 242.2893, 35.0851, 0.7097);
	V_RENT_STANDART[16] = Vehicle_Add(400, -1974.5654, 241.8802, 35.2519, 1.1602);
	V_RENT_STANDART[17] = Vehicle_Add(500, -1971.1576, 241.5307, 35.3121, 0.3465);
	// Аренда транспорта премиум класса
	V_RENT_PREMIUM[0] = Vehicle_Add(602, 1674.8523, 2220.2839, 10.6337, 90.2718);
	V_RENT_PREMIUM[1] = Vehicle_Add(587, 1674.6687, 2216.2927, 10.4988, 90.9156);
	V_RENT_PREMIUM[2] = Vehicle_Add(559, 1674.9752, 2212.3328, 10.4928, 90.7857);
	V_RENT_PREMIUM[3] = Vehicle_Add(434, 1674.9614, 2208.5774, 10.7933, 91.2392);
	V_RENT_PREMIUM[4] = Vehicle_Add(560, 1674.8262, 2204.8352, 10.4902, 91.7820);
	V_RENT_PREMIUM[5] = Vehicle_Add(562, 1675.0105, 2201.4592, 10.4715, 90.3050);
	V_RENT_PREMIUM[6] = Vehicle_Add(506, 1674.6909, 2198.0222, 10.4987, 88.8147);
	V_RENT_PREMIUM[7] = Vehicle_Add(480, 1674.8149, 2194.6936, 10.6082, 89.9012);
	V_RENT_PREMIUM[8] = Vehicle_Add(402, 1674.3173, 2190.9592, 10.5983,  90.1075);
	V_RENT_PREMIUM[9] = Vehicle_Add(429, 1649.3253, 2197.7485, 10.5263, 178.2108);
	V_RENT_PREMIUM[10] = Vehicle_Add(415, 1643.7244, 2197.7029, 10.4354, 179.8881);
	V_RENT_PREMIUM[11] = Vehicle_Add(477, 1638.1572, 2197.6831, 10.6041, 182.8852);
	V_RENT_PREMIUM[12] = Vehicle_Add(541, 1632.4949, 2197.7153, 10.4514, 180.8835);
	V_RENT_PREMIUM[13] = Vehicle_Add(451, 1626.6339, 2197.5586, 10.5419, 180.2225);
	// Транспорт уборщика улиц LS
	V_WHITEWING[0] = Vehicle_Add(574,1619.8025,-1553.5758,13.3112,356.3448,86,86);
	V_WHITEWING[1] = Vehicle_Add(574,1615.8712,-1553.3247,13.3069,356.3448,86,86);
	V_WHITEWING[2] = Vehicle_Add(574,1611.4750,-1553.0437,13.3021,356.3448,86,86);
	V_WHITEWING[3] = Vehicle_Add(574,1606.2161,-1552.7073,13.2964,356.3448,86,86);
	V_WHITEWING[4] = Vehicle_Add(574,1602.0444,-1552.4407,13.2919,356.3448,86,86);
	V_WHITEWING[5] = Vehicle_Add(574,1598.1580,-1552.1921,13.2876,356.3448,86,86);
	V_WHITEWING[6] = Vehicle_Add(574,1593.9841,-1551.9254,13.2831,356.3448,86,86);
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
	// Пикапы Работ
	Whitewing[0] = CreateDynamicPickup(1275,23,-2070.7686,8.4370,35.3203);
	Whitewing[1] = CreateDynamicPickup(1275,23,1622.3585,-1552.2335,13.6824);
	// Пикапы F.B.I
	FBI[0] = CreateDynamicPickup(1318,23,-2456.1501,503.9673,30.0781);
	FBI[1] = CreateDynamicPickup(1318,23,238.7148,138.6364,1003.0234);
	FBI[2] = CreateDynamicPickup(1318,23,-2486.0371,514.0226,51.4849);
	FBI[3] = CreateDynamicPickup(1318,23,288.8309,166.9291,1007.1719);
	// Пикапы Grove
	Grove[0] = CreateDynamicPickup(1318,23,2495.4309,-1691.1400,14.7656);
	Grove[1] = CreateDynamicPickup(1318,23,2468.4163,-1698.2432,1013.5078);
	// Пикапы Ballas
	Ballas[0] = CreateDynamicPickup(1318,23,2022.8790,-1120.2637,26.4210);
	Ballas[1] = CreateDynamicPickup(1318,23,-42.6055,1405.7949,1084.4297);
	// Пикапы Aztecas
	Aztecas[0] = CreateDynamicPickup(1318,23,2185.8176,-1814.6786,13.5469);
	Aztecas[1] = CreateDynamicPickup(1318,23,225.756989,1240.000000,1082.149902);
	// Пикапы Vagos
	Vagos[0] = CreateDynamicPickup(1318,23,2756.2825,-1182.4691,69.3998);
	Vagos[1] = CreateDynamicPickup(1318,23,318.6152,1114.8966,1083.8828);
	// Пикапы Rifa
	Rifa[0] = CreateDynamicPickup(1318,23,2787.0759,-1926.1780,13.5469);
	Rifa[1] = CreateDynamicPickup(1318,23,-68.8279,1351.3553,1080.2109);
	// Пикапы Chinese
	Chinese[0] = CreateDynamicPickup(1318,23,2597.6414,1900.9031,11.0312);
	Chinese[1] = CreateDynamicPickup(1318,23,1298.9392,-797.0093,1084.0078);
	// NPC's
	testbot = FCNPC_Create("Bot_1");
	FCNPC_Spawn(testbot,179,287.9097,-104.5135,1001.5156);
	FCNPC_GiveAngle(testbot,176.2943);
	FCNPC_SetArmour(testbot,100);
	FCNPC_SetWeapon(testbot, 31);
	FCNPC_SetAmmo(testbot, 500);
	// FBI NPC
	FBI_Actors[0] = CreateActor(286,293.1147,182.5184,1007.1719,133.6613);
	FBI_Actors[1] = CreateActor(163,231.9374,159.9906,1003.0234,219.8474);
	FBI_Actors[2] = CreateActor(166,230.5688,165.0592,1003.0234,270.5266);
	for(new i;i<3;i++)
	{
		ApplyActorAnimation(FBI_Actors[i],"DEALER","Dealer_idle",4.1,1,0,0,0,0);
		SetActorInvulnerable(FBI_Actors[i], 1);
	}
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
	// Capture textdraw
	Capture[0] = TextDrawCreate(31.599884, 295.680114, "_");
	TextDrawLetterSize(Capture[0], 0.273199, 1.171911);
	TextDrawTextSize(Capture[0], 147.199981, 42.311103);
	TextDrawAlignment(Capture[0], 1);
	TextDrawColor(Capture[0], -1);
	TextDrawUseBox(Capture[0], true);
	TextDrawBoxColor(Capture[0], 70);
	TextDrawSetShadow(Capture[0], 0);
	TextDrawSetOutline(Capture[0], 1);
	TextDrawBackgroundColor(Capture[0], 51);
	TextDrawFont(Capture[0], 1);
	TextDrawSetProportional(Capture[0], 1);

	Capture[1] = TextDrawCreate(134.000015, 307.128845, "_");
	TextDrawLetterSize(Capture[1], 0.273198, 1.171911);
	TextDrawAlignment(Capture[1], 1);
	TextDrawColor(Capture[1], -5963521);
	TextDrawSetShadow(Capture[1], 0);
	TextDrawSetOutline(Capture[1], 1);
	TextDrawBackgroundColor(Capture[1], 51);
	TextDrawFont(Capture[1], 1);
	TextDrawSetProportional(Capture[1], 1);
	// 3D текст
	CreateDynamic3DTextLabel("Уборщик улиц",0x1E90FFFF, 1622.3585, -1552.2335, 13.6824, 35.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,0,0);
	CreateDynamic3DTextLabel("Уборщик улиц",0x1E90FFFF, -2070.7686, 8.4370, 35.3203, 35.0,INVALID_PLAYER_ID,INVALID_VEHICLE_ID,1,0,0);
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
public FCNPC_OnDeath(npcid, killerid, weaponid)
{
	//FCNPC_OnSpawn(testbot);
    return 1;
}
public FCNPC_OnTakeDamage(npcid, damagerid, weaponid, bodypart, Float:health_loss){
	return true;
}
