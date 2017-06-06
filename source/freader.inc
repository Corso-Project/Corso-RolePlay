INI:budget[](name[], value[])
{
	INI_Int("Government", Budget_GOVERNMENT);
	return 0;
}

INI:mysql[](name[], value[])
{
	INI_String("Host", g_MySQL_Host, 46);
	INI_String("User", g_MySQL_User, 46);
	INI_String("Database", g_MySQL_Database, 46);
	INI_String("Password", g_MySQL_Password, 46);
	return 0;
}

INI:prices[](name[], value[])
{
	INI_Int("RentCar_Econom", Prices_RentCar_Econom);
	INI_Int("RentCar_Standart", Prices_RentCar_Standart);
	INI_Int("RentCar_Premium", Prices_RentCar_Premium);
	return 0;
}

INI:settings[](name[], value[])
{
	INI_Int("Chat_OOC", g_Chat_OOC);
	INI_Int("Payment_Register", g_Payment_Register);
	return 0;
}
