stock Load_Budget(){
	new budget_ini = ini_openFile("budget.ini");
	ini_getInteger(budget_ini,"Government",Budget_GOVERNMENT);
	ini_closeFile(budget_ini);
}
stock Load_MySQL(){
	new mysql_ini = ini_openFile("mysql.ini");
	ini_getString(mysql_ini, "Host", g_MySQL_Host);
	ini_getString(mysql_ini, "User", g_MySQL_User);
	ini_getString(mysql_ini, "Database", g_MySQL_Database); 
	ini_getString(mysql_ini, "Password", g_MySQL_Password);
	ini_closeFile(mysql_ini);
}
stock Load_Settings(){
	new settings_ini = ini_openFile("settings.ini");
	ini_getInteger(settings_ini,"Chat_OOC",g_Chat_OOC);
	ini_getInteger(settings_ini,"Payment_Register",g_Payment_Register);
	ini_closeFile(settings_ini);
}
stock Load_Prices(){
	new prices_ini = ini_openFile("prices.ini");
	ini_getInteger(prices_ini,"RentCar_Econom", Prices_RentCar_Econom);
	ini_getInteger(prices_ini,"RentCar_Standart", Prices_RentCar_Standart);
	ini_getInteger(prices_ini,"RentCar_Premium", Prices_RentCar_Premium);
	ini_closeFile(prices_ini);
}
