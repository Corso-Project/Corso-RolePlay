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
	// АвтоШкола
	CreateObject(19957, -2081.8999, -149.89999, 34.3, 0.00, 0.00, 180); //object (SAMPRoadSign10) (1)
	CreateObject(19425, -2080.19995, -149.7, 34.3, 0.00, 0.00, 0.00); //object (speed_bump01) (1)
	CreateObject(19425, -2077.1001, -149.7, 34.3, 0.00, 0.00, 0.00); //object (speed_bump01) (2)
	CreateObject(19957, -2075.3999, -149.89999, 34.3, 0.00, 0.00, 179.995); //object (SAMPRoadSign10) (2)
	CreateObject(1238, -2081.6001, -152.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (1)
	CreateObject(1238, -2081.59961, -150.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (2)
	CreateObject(1238, -2081.59961, -151, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (3)
	CreateObject(1238, -2081.59961, -151.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (4)
	CreateObject(1238, -2081.6001, -156.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (5)
	CreateObject(1238, -2081.59961, -153.09961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (6)
	CreateObject(1238, -2081.59961, -153.7998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (7)
	CreateObject(1238, -2081.59961, -154.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (8)
	CreateObject(1238, -2081.59961, -155.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (9)
	CreateObject(1238, -2081.59961, -155.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (10)
	CreateObject(1238, -2081.6001, -157.3, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (11)
	CreateObject(1238, -2081.6001, -160.8, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (12)
	CreateObject(1238, -2081.59961, -158, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (13)
	CreateObject(1238, -2081.59961, -158.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (14)
	CreateObject(1238, -2081.6001, -159.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (15)
	CreateObject(1238, -2081.59961, -160.09961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (16)
	CreateObject(1238, -2081.6001, -162.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (17)
	CreateObject(1238, -2075.6001, -151, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (18)
	CreateObject(1238, -2075.59961, -150.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (19)
	CreateObject(1238, -2075.6001, -151.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (20)
	CreateObject(1238, -2075.6001, -152.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (21)
	CreateObject(1238, -2075.6001, -153.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (22)
	CreateObject(1238, -2075.6001, -153.8, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (23)
	CreateObject(1238, -2075.6001, -154.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (24)
	CreateObject(1238, -2075.6001, -156.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (25)
	CreateObject(1238, -2075.59961, -155.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (26)
	CreateObject(1238, -2075.59961, -155.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (27)
	CreateObject(1238, -2075.6001, -157.3, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (28)
	CreateObject(1238, -2075.6001, -158.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (29)
	CreateObject(1238, -2075.59961, -158, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (30)
	CreateObject(1238, -2075.6001, -159.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (31)
	CreateObject(1238, -2075.6001, -160.8, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (32)
	CreateObject(1238, -2075.59961, -160.09961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (33)
	CreateObject(1238, -2075.6001, -162.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (34)
	CreateObject(1238, -2075.59961, -161.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (35)
	CreateObject(1238, -2075.6001, -162.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (36)
	CreateObject(1238, -2075.6001, -163.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (37)
	CreateObject(1238, -2075.6001, -164.3, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (38)
	CreateObject(1238, -2075.6001, -165, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (39)
	CreateObject(1238, -2075.6001, -165.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (40)
	CreateObject(1238, -2075.6001, -166.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (41)
	CreateObject(1238, -2075.6001, -167.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (42)
	CreateObject(1238, -2075.6001, -167.8, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (43)
	CreateObject(1238, -2075.6001, -168.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (44)
	CreateObject(1238, -2075.6001, -169.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (45)
	CreateObject(1238, -2075.6001, -169.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (46)
	CreateObject(1238, -2078, -175.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (47)
	CreateObject(1238, -2075.59961, -170.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (48)
	CreateObject(1238, -2075.59961, -171.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (49)
	CreateObject(1238, -2075.59961, -172, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (50)
	CreateObject(19956, -2076, -172.10001, 34.35859, 0.00, 0.00, 190); //object (SAMPRoadSign9) (1)
	CreateObject(1238, -2076, -172.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (51)
	CreateObject(1238, -2076.5, -173.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (52)
	CreateObject(1238, -2077, -173.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (53)
	CreateObject(1238, -2081.59961, -161.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (54)
	CreateObject(1238, -2081.6001, -163.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (55)
	CreateObject(1238, -2081.59961, -162.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (56)
	CreateObject(1238, -2081.6001, -164.3, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (57)
	CreateObject(1238, -2081.6001, -165.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (58)
	CreateObject(1238, -2081.59961, -165, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (59)
	CreateObject(1238, -2081.6001, -166.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (60)
	CreateObject(1238, -2081.6001, -170.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (61)
	CreateObject(1238, -2081.59961, -167.09961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (62)
	CreateObject(1238, -2081.59961, -167.7998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (63)
	CreateObject(1238, -2081.59961, -168.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (64)
	CreateObject(1238, -2081.59961, -169.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (65)
	CreateObject(1238, -2081.59961, -169.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (66)
	CreateObject(1238, -2081.6001, -171.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (67)
	CreateObject(1238, -2081.59961, -171.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (68)
	CreateObject(1238, -2081.6001, -172.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (69)
	CreateObject(1238, -2081.6001, -178.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (70)
	CreateObject(1238, -2081.59961, -173.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (71)
	CreateObject(1238, -2081.59961, -174, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (72)
	CreateObject(1238, -2081.59961, -174.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (73)
	CreateObject(1238, -2081.59961, -175.39941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (74)
	CreateObject(1238, -2077.5, -174.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (75)
	CreateObject(1238, -2078, -174.7998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (76)
	CreateObject(1238, -2078, -176.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (77)
	CreateObject(1238, -2078, -179, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (78)
	CreateObject(1238, -2078, -176.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (79)
	CreateObject(1238, -2078, -177.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (80)
	CreateObject(1238, -2078, -178.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (81)
	CreateObject(1238, -2078, -181.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (82)
	CreateObject(1238, -2078, -179.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (83)
	CreateObject(1238, -2078, -180.39941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (84)
	CreateObject(1238, -2081.59961, -176.09961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (85)
	CreateObject(1238, -2081.59961, -176.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (86)
	CreateObject(1238, -2081.59961, -177.39941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (87)
	CreateObject(1238, -2077.69995, -182.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (88)
	CreateObject(1238, -2081.59961, -178.7998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (89)
	CreateObject(1238, -2081.59961, -179.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (90)
	CreateObject(1238, -2081.59961, -180.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (91)
	CreateObject(1238, -2081.59961, -180.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (92)
	CreateObject(1238, -2081.59961, -181.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (93)
	CreateObject(1238, -2081.59961, -182.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (94)
	CreateObject(1238, -2081.59961, -183, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (95)
	CreateObject(1238, -2081.59961, -183.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (96)
	CreateObject(1238, -2078, -181.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (97)
	CreateObject(1238, -2077.30005, -183, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (98)
	CreateObject(1238, -2074.19995, -187.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (99)
	CreateObject(1238, -2076.7998, -183.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (100)
	CreateObject(1238, -2076.39941, -184.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (101)
	CreateObject(1238, -2081.30005, -184.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (102)
	CreateObject(1238, -2081, -185.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (103)
	CreateObject(1238, -2080.6001, -185.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (104)
	CreateObject(1238, -2077.8999, -189.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (105)
	CreateObject(1238, -2080.19922, -186.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (106)
	CreateObject(19960, -2081.3999, -184, 34.3, 0.00, 0.00, 190); //object (SAMPRoadSign13) (1)
	CreateObject(1238, -2079.69922, -186.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (107)
	CreateObject(1238, -2079.19922, -187.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (108)
	CreateObject(1238, -2078.7998, -188, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (109)
	CreateObject(1238, -2076, -184.7998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (110)
	CreateObject(1238, -2075.59961, -185.39941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (111)
	CreateObject(1238, -2075.19922, -186, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (112)
	CreateObject(1238, -2074.7998, -186.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (113)
	CreateObject(1238, -2078.2998, -188.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (114)
	CreateObject(1238, -2077.8999, -192.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (115)
	CreateObject(1238, -2077.89941, -189.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (116)
	CreateObject(1238, -2077.89941, -190.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (117)
	CreateObject(1238, -2077.89941, -191.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (118)
	CreateObject(1238, -2077.89941, -192, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (119)
	CreateObject(1238, -2077.8999, -193.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (120)
	CreateObject(1238, -2077.8999, -194.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (121)
	CreateObject(1238, -2077.8999, -196.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (122)
	CreateObject(1238, -2077.89941, -194.7998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (123)
	CreateObject(1238, -2077.89941, -195.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (124)
	CreateObject(1238, -2078.8999, -198.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (125)
	CreateObject(1238, -2074.19995, -187.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (126)
	CreateObject(1238, -2074.30005, -189.3, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (127)
	CreateObject(1238, -2074.19995, -188.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (128)
	CreateObject(1238, -2074.30005, -192.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (129)
	CreateObject(1238, -2074.30005, -190, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (130)
	CreateObject(1238, -2074.30005, -190.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (131)
	CreateObject(1238, -2074.30005, -191.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (132)
	CreateObject(1238, -2074.30005, -192.8, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (133)
	CreateObject(1238, -2074.30005, -194.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (134)
	CreateObject(1238, -2074.30005, -193.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (135)
	CreateObject(1238, -2074.30005, -194.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (136)
	CreateObject(1238, -2074.30005, -196.3, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (137)
	CreateObject(1238, -2074.30005, -195.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (138)
	CreateObject(1238, -2074.30005, -197.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (139)
	CreateObject(1238, -2074.30005, -197, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (140)
	CreateObject(1238, -2074.19995, -198.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (141)
	CreateObject(1238, -2077.89941, -196.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (142)
	CreateObject(1238, -2078.39941, -197.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (143)
	CreateObject(1238, -2079.3999, -198.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (144)
	CreateObject(1238, -2080.8999, -202.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (145)
	CreateObject(1238, -2079.89941, -199.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (146)
	CreateObject(1238, -2080.39941, -199.69922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (147)
	CreateObject(1238, -2075.1001, -199.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (148)
	CreateObject(1238, -2074.69995, -199.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (149)
	CreateObject(1238, -2075.6001, -200.3, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (150)
	CreateObject(1238, -2076.6001, -201.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (151)
	CreateObject(1238, -2076.1001, -200.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (152)
	CreateObject(19959, -2074.5, -198.8, 34.3, 0.00, 0.00, 180); //object (SAMPRoadSign12) (1)
	CreateObject(1238, -2080.89941, -200.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (153)
	CreateObject(1238, -2080.89941, -200.89941, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (154)
	CreateObject(1238, -2080.89941, -201.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (155)
	CreateObject(1238, -2080.8999, -202.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (156)
	CreateObject(1238, -2080.8999, -205.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (157)
	CreateObject(1238, -2080.89941, -203.59961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (158)
	CreateObject(1238, -2076.6001, -202.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (159)
	CreateObject(1238, -2076.59961, -202.19922, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (160)
	CreateObject(1238, -2076.6001, -203.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (161)
	CreateObject(1238, -2076.6001, -204.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (162)
	CreateObject(1238, -2080.89941, -204.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (164)
	CreateObject(1238, -2080.89941, -205, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (165)
	CreateObject(1238, -2080.8999, -206.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (166)
	CreateObject(1238, -2080.8999, -209.2, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (167)
	CreateObject(1238, -2080.89941, -207.09961, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (168)
	CreateObject(1238, -2080.89941, -207.7998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (169)
	CreateObject(1238, -2080.89941, -208.5, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (170)
	CreateObject(1238, -2080.8999, -209.8, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (171)
	CreateObject(1238, -2076.6001, -204.89999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (172)
	CreateObject(1238, -2076.6001, -205.60001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (173)
	CreateObject(1238, -2076.6001, -207, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (174)
	CreateObject(1238, -2076.59961, -206.2998, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (175)
	CreateObject(1238, -2076.6001, -207.7, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (176)
	CreateObject(1238, -2076.6001, -208.39999, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (177)
	CreateObject(1238, -2076.6001, -209.10001, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (178)
	CreateObject(1238, -2076.6001, -209.8, 34.6, 0.00, 0.00, 0.00); //object (trafficcone) (179)
	CreateObject(19425, -2078.80005, -209.8, 34.3, 0.00, 0.00, 0.00); //object (speed_bump01) (3)

	print("map.pwn [loaded]");
	return 1;
}

public OnPlayerConnect(playerid)
{
	RemoveBuildingForPlayer(playerid,968,-2436.8125, 495.4688, 29.6797,10);
	return 1;
}
