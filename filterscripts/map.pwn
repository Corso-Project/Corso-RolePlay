//��� AutoEncoding-a
//������������������������������������������������������������������������������������������������������������������������������������������������������������������������
//������������������������������������������������������������������������������������������������������������������������������������������������������������������������
#include <a_samp>
#include <streamer>
#include <mapfix>

public OnFilterScriptInit()
{
	CreateDynamicObject(19121, -2475.6001, 519.09998, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (2)
	CreateDynamicObject(19121, -2475.5, 526.5, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (3)
	CreateDynamicObject(19121, -2469.1001, 526.40002, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (4)
	CreateDynamicObject(19121, -2469, 519.20001, 49.9, 0.00, 0.00, 0.00); //object (BollardLight1) (5)
	CreateDynamicObject(19777, -2438.38989, 494.3111, 31.3, 90, 23, 0.00); //object (FBILogo1) (1)
	CreateDynamicObject(19296, -2472.5, 522.5, 50.1, 0.00, 0.00, 0.00); //object (PointLight16) (1)
	SetObjectMaterial(CreateDynamicObject(16096, -2489.05005, 514, 52, 0.00, 0.00, 180), 0, 4600, "theatrelan2", "gm_labuld2_b", 0xFFFFFFFF);
	//
	CreateDynamicObject(19425, 1808.406128, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1805.109253, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1801.812134, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1798.515137, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1795.218140, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1791.921021, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1788.624146, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1785.474121, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1782.345215, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	CreateDynamicObject(19425, 1779.930054, 823.396423, 9.764700, 0.000000, 0.000000, 0.000000);
	//
	new tmpobjid;
	tmpobjid = CreateDynamicObject(19447, -2091.258789, -148.410125, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19480, -2088.262939, -144.268447, 34.330348, 0.000000, -89.699768, 90.900032, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "START", 120, "Ariel", 50, 0, 0xFFFFFFFF, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, -2088.164794, -146.077819, 34.328342, 0.399971, -90.400016, 809.900146, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 14668, "711c", "CJ_7_11_TILE", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "�", 120, "Wingdings", 150, 0, 0xFFFF0000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -148.410125, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2091.266845, -158.030059, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2091.268554, -167.660339, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -158.030059, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2091.266113, -177.290496, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -167.660339, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -177.290496, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -186.900573, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2091.266113, -186.900573, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -196.520553, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2091.265625, -196.520553, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -206.140548, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2091.267333, -206.140548, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19367, -2088.228515, -210.640792, 32.617294, 0.000000, 0.000000, -88.000015, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2085.304931, -224.510665, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2091.257568, -224.510665, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19367, -2088.308837, -220.159500, 32.617294, 0.000000, 0.000000, -88.000015, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2084.591064, -229.417877, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2091.970703, -229.417877, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2082.989501, -229.417877, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2093.562255, -229.417877, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2082.102050, -234.150619, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2094.455810, -234.144729, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2082.102050, -243.750778, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2094.455810, -243.734863, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, -2088.118896, -231.580307, 34.329982, 0.399971, -90.400016, 809.900146, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 14668, "711c", "CJ_7_11_TILE", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "�", 130, "Wingdings", 150, 0, 0xFFFF0000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19441, -2081.389892, -267.847778, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2082.102050, -253.310806, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2082.102050, -262.940734, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2094.455810, -253.374923, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2094.455810, -263.004730, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2094.455810, -272.614837, 32.590343, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2093.742431, -277.518005, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2088.123291, -277.517730, 32.582328, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2080.499267, -268.557708, 32.583160, 0.000000, 0.000000, 720.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2079.785644, -269.449645, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2078.894042, -270.162841, 32.583160, 0.000000, 0.000000, 720.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2078.180908, -271.055541, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2078.522705, -277.517730, 32.582328, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2072.562988, -271.057739, 32.582328, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2068.892089, -277.517730, 32.582328, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2063.307617, -277.517791, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2062.953369, -271.057739, 32.582328, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19817, -2070.010009, -274.023956, 33.838714, 0.000000, 0.000000, -90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "metpat64", 0x00000000);
	tmpobjid = CreateDynamicObject(19817, -2065.599121, -274.023956, 33.838714, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "metpat64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2061.718261, -277.517761, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19441, -2060.117187, -277.517761, 32.583160, 0.000000, 0.000000, 630.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, -2088.126708, -236.850509, 34.343158, 0.399971, -90.400016, 809.900146, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 14668, "711c", "CJ_7_11_TILE", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "�", 130, "Wingdings", 150, 0, 0xFFFF0000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, -2088.139404, -244.630538, 34.328834, 0.399971, -90.400016, 809.900146, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 14668, "711c", "CJ_7_11_TILE", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "�", 130, "Wingdings", 150, 0, 0xFFFF0000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, -2088.152832, -252.810852, 34.341690, 0.399971, -90.400016, 809.900146, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 14668, "711c", "CJ_7_11_TILE", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "�", 130, "Wingdings", 150, 0, 0xFFFF0000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, -2088.165527, -260.760803, 34.326225, 0.399971, -90.400016, 809.900146, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 14668, "711c", "CJ_7_11_TILE", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "�", 130, "Wingdings", 150, 0, 0xFFFF0000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19447, -2054.500244, -277.517730, 32.582328, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19447, -2054.500244, -271.067779, 32.582328, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19367, -2050.149169, -274.158599, 32.617294, 0.000000, 0.000000, 540.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(1492, -2027.677001, -102.334617, 34.159584, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 1, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2034.669921, -107.041656, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2034.669921, -116.658622, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2031.169555, -107.041656, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2027.668334, -107.042655, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2024.167968, -107.042655, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2020.666503, -107.041656, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2031.169799, -116.658622, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2027.667968, -116.658622, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2024.166259, -116.658622, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2020.665893, -116.658622, 34.151077, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 14709, "lamidint2", "mp_apt1_bathfloor1", 0x00000000);
	tmpobjid = CreateDynamicObject(1492, -2036.427368, -111.014602, 34.159584, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 1, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2031.169555, -107.041656, 37.581073, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2034.669921, -107.041656, 37.581066, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2027.668334, -107.042655, 37.581020, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2024.167968, -107.042655, 37.581069, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2020.666503, -107.041656, 37.581016, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2034.669921, -116.658622, 37.591102, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2031.169799, -116.658622, 37.591068, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2027.667968, -116.658622, 37.591068, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2024.166259, -116.658622, 37.591064, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19450, -2020.665893, -116.658622, 37.601051, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 9525, "boigas_sfw", "GEwhite1_64", 0x00000000);
	tmpobjid = CreateDynamicObject(19483, -2020.911132, -120.107528, 36.110103, 0.000000, 0.000000, 131.500000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "Nick_0\nNick_1", 140, "Ariel", 59, 0, 0xFFFFFFFF, 0x00000000, 0);
	tmpobjid = CreateDynamicObject(19483, -2020.911132, -120.107528, 36.550090, 0.000000, 0.000000, 131.500000, -1, -1, -1, 300.00, 300.00);
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "����� �������:", 140, "Ariel", 52, 0, 0xFF00FFFF, 0x00000000, 0);

	tmpobjid = CreateDynamicObject(11099, -2056.989990, -184.546997, 34.324153, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -192.099426, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -192.609375, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -193.119262, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19989, -2085.304199, -191.659881, 34.320312, 0.000000, 0.000000, 179.700164, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19989, -2091.267578, -191.598922, 34.320312, 0.000000, 0.000000, 179.700164, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -195.209320, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -195.709213, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -196.199188, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -198.039031, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -198.549072, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2088.250000, -199.059005, 34.309432, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19957, -2085.318847, -210.927429, 34.310543, 0.000000, 0.000000, 179.800048, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19957, -2091.263916, -210.927429, 34.310543, 0.000000, 0.000000, 178.600051, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1278, -2095.130859, -237.433364, 48.351600, 0.000000, 0.000000, -92.000045, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1238, -2088.308593, -233.586975, 34.640609, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1238, -2088.308593, -241.076828, 34.640609, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1238, -2088.308593, -249.386962, 34.640609, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1238, -2088.308593, -256.957214, 34.640609, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1238, -2088.308593, -264.516967, 34.640609, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19955, -2080.480224, -269.439300, 34.311466, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19388, -2026.894409, -102.314277, 35.919696, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19404, -2030.101928, -102.313003, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19404, -2023.691528, -102.313003, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2021.301269, -102.313003, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2019.730468, -102.313003, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(971, -2040.951049, -102.313003, 33.989067, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19450, -2036.440551, -116.660644, 35.921043, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2035.701782, -102.313003, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19404, -2033.310546, -102.313003, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2035.701782, -121.392944, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19450, -2019.010009, -116.660644, 35.921043, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19450, -2019.010375, -107.040657, 35.921043, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2019.750000, -121.392944, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19450, -2030.099853, -121.390663, 35.921043, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19404, -2023.701416, -121.390663, 35.921043, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2021.310791, -121.392944, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2023.299194, -121.477035, 35.763278, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2023.299194, -121.303970, 35.763278, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2023.299194, -102.401046, 35.763278, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2023.299194, -102.225013, 35.763278, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2033.662597, -102.225013, 35.763278, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2033.751220, -102.401046, 35.763278, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2030.009033, -102.225013, 35.763278, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1649, -2029.969604, -102.401046, 35.763278, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19450, -2031.558593, -112.670631, 35.921043, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2019.868530, -112.672912, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2025.949829, -112.672912, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19431, -2019.868530, -112.672912, 35.919033, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1506, -2025.153320, -112.670982, 34.228664, 0.000000, 0.000000, 106.299987, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1506, -2020.715209, -112.769729, 34.228664, 0.000000, 0.000000, 89.100028, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(3077, -2020.657592, -119.939216, 34.256622, 0.000000, 0.000000, 41.099998, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19388, -2036.438110, -110.238281, 35.920700, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19358, -2036.438110, -107.048278, 35.920700, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19358, -2036.438110, -103.988265, 35.920700, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(971, -2052.714599, -102.313003, 33.989067, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2185, -2035.844360, -118.920593, 34.233673, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1707, -2035.746948, -106.385810, 34.192222, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1707, -2032.476318, -103.005790, 34.192222, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19786, -2031.473876, -112.613372, 36.159114, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2030, -2035.058959, -103.329658, 34.814094, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(11737, -2026.853637, -101.834884, 34.164817, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1546, -2035.260986, -103.956375, 35.312099, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19897, -2034.353027, -103.342941, 35.224639, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19896, -2036.299926, -104.320358, 34.270103, -0.099999, 44.899993, 2.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2480, -2036.321777, -113.920410, 34.812866, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2855, -2034.984008, -103.335754, 35.209407, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2370, -2035.875488, -108.310455, 34.231918, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2059, -2035.462036, -107.704666, 35.099887, 0.000000, 0.000000, -141.499938, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2059, -2035.547119, -108.243995, 35.099887, 0.000000, 0.000000, -1.999961, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1721, -2033.701782, -119.728355, 34.229305, 0.000000, 0.000000, -133.199951, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(1721, -2035.370727, -119.938499, 34.259296, 0.000000, 0.000000, 89.500007, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2185, -2033.973754, -120.840621, 34.233673, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19786, -2036.387207, -116.626762, 36.278293, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(14687, -2031.345703, -107.387008, 35.997768, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(18075, -2025.048950, -108.580383, 37.439105, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(14687, -2031.345703, -113.106979, 35.997768, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(18075, -2027.809814, -117.020423, 37.479087, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(18762, -2047.820190, -102.702606, 36.696571, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(18762, -2046.830322, -102.702606, 36.696571, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(18762, -2045.850219, -102.702606, 36.696571, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2886, -2045.722778, -102.136260, 35.607597, 0.000000, 0.000000, 540.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2886, -2047.912719, -102.136260, 35.607597, 0.000000, 0.000000, 540.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2886, -2045.722778, -103.206237, 35.607597, 0.000000, 0.000000, 720.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(2886, -2047.912719, -103.196243, 35.607597, 0.000000, 0.000000, 720.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2057.210449, -82.325935, 34.860000, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2057.210449, -86.515930, 34.860000, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(967, -2056.885009, -93.754776, 34.397655, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(968, -2057.275634, -94.831848, 34.890388, 0.000000, 90.000000, 270.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(966, -2057.277099, -94.855888, 34.126804, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2057.210449, -90.675926, 34.860000, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2063.412109, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2067.582031, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2059.251708, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2071.751708, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2075.921875, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2080.091308, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2084.250488, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2088.420898, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2092.591308, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2093.902343, -80.245941, 34.860000, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2036.917480, -82.484146, 34.984130, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2036.917480, -85.564178, 34.984130, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2017.386108, -82.484146, 34.984130, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2017.386596, -85.564178, 34.984130, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2034.856689, -80.424156, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2030.706054, -80.424156, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2026.535522, -80.424156, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2022.375366, -80.424156, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2019.463745, -80.424156, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2034.856689, -87.624137, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2030.686035, -87.624137, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2026.525390, -87.624137, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2022.355346, -87.624137, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2019.435058, -87.624137, 34.984130, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(738, -2021.912963, -84.365699, 34.546703, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(738, -2027.373291, -84.365699, 34.546703, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(738, -2033.084228, -84.365699, 34.546703, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2050.509521, -80.539413, 34.167743, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2047.189208, -80.539413, 34.167758, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(19425, -2043.859375, -80.539413, 34.167758, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2017.206542, -89.944152, 34.854141, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2017.206542, -94.104164, 34.854141, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	tmpobjid = CreateDynamicObject(970, -2017.177490, -100.464187, 34.854141, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
	print("map.pwn [loaded]");
	return 1;
}

public OnPlayerConnect(playerid)
{
	RemoveBuildingForPlayer(playerid,968,-2436.8125, 495.4688, 29.6797,10);
	// ������� �����
	RemoveBuildingForPlayer(playerid, 1250, 997.4141, 1707.5234, 10.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 1250, 997.7266, 1759.1250, 10.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 1251, 997.0469, 1710.9531, 11.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1251, 998.0938, 1755.6875, 11.2656, 0.25);
	// ����-�����
	RemoveBuildingForPlayer(playerid, 11099, -2056.989, -184.546, 34.414, 0.250);
	RemoveBuildingForPlayer(playerid, 1278, -2094.340, -237.460, 48.351, 0.250);
	RemoveBuildingForPlayer(playerid, 11015, -2028.130, -111.273, 36.132, 0.250);
	RemoveBuildingForPlayer(playerid, 11371, -2028.130, -111.273, 36.132, 0.250);
	RemoveBuildingForPlayer(playerid, 1532, -2025.829, -102.469, 34.273, 0.250);
	RemoveBuildingForPlayer(playerid, 1497, -2029.020, -120.063, 34.257, 0.250);
	RemoveBuildingForPlayer(playerid, 11014, -2076.439, -107.930, 36.968, 0.250);
	RemoveBuildingForPlayer(playerid, 11372, -2076.439, -107.930, 36.968, 0.250);
	return 1;
}
