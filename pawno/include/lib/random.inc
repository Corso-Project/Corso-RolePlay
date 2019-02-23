/*
	A Complete Random System.
	Functions:
		//native Random(min, max);
		Return Values:
			Random Value
			0 : On Error.
		//native RandomFloat(Float:min, Float:max, accuracy = 4);
		Return Values:
			Random Float Value
			0.0 : On Error.
	Examples:
		Random(min, max):
			printf("Random (10 - 65):%d",Random(10,65));

			Output Can Be (65 - 10 =) 55 Items.Here Is Some Outputs:
			Random 10 - 65:41
			Random 10 - 65:17
			Random 10 - 65:36
			Random 10 - 65:57
			Random 10 - 65:28

		RandomFloat(Float:min, Float:max) :
			printf("Random Float (5.1 - 44.7):%f",RandomFloat(5.1,44.7));

			Output Can Be Too Many Items.Here Is Some Outputs(We Dont Put Accuracy; And its By Default 4):
			Random Float (5.1 - 44.7):17.2981
			Random Float (5.1 - 44.7):27.1247
			Random Float (5.1 - 44.7):9.1954
			Random Float (5.1 - 44.7):41.2458
			Random Float (5.1 - 44.7):35.5884
*/
#if defined _random_included
	#endinput
#endif
#define _random_included

#if !defined _samp_included
	#tryinclude <a_samp>
	#if !defined _samp_included
		#error Cannot Find a_samp.inc File,Please Check Your Includes Folder!
		#endinput
	#endif
#endif

#if !defined _Float_included
	#tryinclude <float>
	#if !defined _Float_included
		#error Cannot Find float.inc File,Please Check Your Includes Folder!
		#endinput
	#endif
#endif

stock Random(min, max) {
	if (min >= max) return 0;
	if (min < 0 || max < 0) return 0;
	return (random(max - min));
	//return (random(max - min)) + min;
}

stock Float:RandomFloat(Float:min, Float:max, accuracy = 4) {
	if (min >= max) return 0.0;
	if (min < 0.0 || max < 0.0) return 0.0;
	if (accuracy < 1 || accuracy > 6) return 0.0;
	new divValue;
	switch (accuracy) {
		case 1: divValue = 10;
		case 2: divValue = 100;
		case 3: divValue = 1000;
		case 4: divValue = 10000;
		case 5: divValue = 100000;
		case 6: divValue = 1000000;
	}
	return random(floatround(max) - floatround(min)) + min + (random(divValue) / divValue);
}
