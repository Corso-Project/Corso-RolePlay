#include <a_samp>
#include <streamer>

public OnFilterScriptInit()
{
	CreateObject(19121, -2475.6001, 519.09998, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (2)
	CreateObject(19121, -2475.5, 526.5, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (3)
	CreateObject(19121, -2469.1001, 526.40002, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (4)
	CreateObject(19121, -2469, 519.20001, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (5)
	CreateObject(19777, -2438.38989, 494.3111, 31.3, 90, 23, 0.00); //object (FBILogo1) (1)
	CreateObject(19296, -2472.5, 522.5, 50.1, 0.00, 0.00, 0.00); //object (PointLight16) (1)
	SetObjectMaterial(CreateObject(16096, -2489.05005, 514, 52, 0.00, 0.00, 180), 0, 4600, "theatrelan2", "gm_labuld2_b", 0xFFFFFFFF);
	print("map.pwn [loaded]");
	return 1;
}

public OnPlayerConnect(playerid)
{
	RemoveBuildingForPlayer(playerid,968,-2436.8125, 495.4688, 29.6797,10);
	return 1;
}
