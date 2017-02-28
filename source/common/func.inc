stock Name_IsValid(const string[])
{
	new earth;
	for(new i; i < strlen(string); i++) {
		switch(string[i]) {
		    case 'a'..'z': continue;
		    case 'A'..'Z': continue;
		    case '_': earth++;
			default: return 0;
        }
    }
    if(earth != 1) return 0;
	return 1;
}

stock Message_ToAll(color, const fmat[], va_args<>)
{
	foreach(new i : Player) {
		if (P[i][_p_in_game] == false)
            continue;
		SendClientMessage(i, color, va_return(fmat, va_start<2>));
	}
}

stock Message_ToAdmins(color, const fmat[], va_args<>)
{
    foreach(new i : Player)
        if (P[i][p_access] >= 1)
            SendClientMessage(i, color, va_return(fmat, va_start<2>));
}
stock Message_ToJobTeam(playerid,color, const fmat[], va_args<>)
{
	foreach(new i : Player)
		if (P[playerid][p_job_team] == P[i][p_job_team])
			SendClientMessage(i, color, va_return(fmat, va_start<3>));
}
stock Message_ToComuneTeam(job,color, const fmat[], va_args<>){
	foreach(new i : Player){
		switch(job){
			case 2..5: if(P[i][p_job_team] >= 2 && P[i][p_job_team] <= 5) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 10: if(P[i][p_job_team] == 10) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 11: if(P[i][p_job_team] == 11) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 12: if(P[i][p_job_team] == 12) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 13: if(P[i][p_job_team] == 13) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 14: if(P[i][p_job_team] == 14) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 15: if(P[i][p_job_team] == 15) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 16: if(P[i][p_job_team] == 16) SendClientMessage(i, color, va_return(fmat, va_start<3>));
			case 17: if(P[i][p_job_team] == 17) SendClientMessage(i, color, va_return(fmat, va_start<3>));
		}
	}
}
stock containsAnyIP(const string[])
{
	new digits, digitGroups;
	for(new pos; ; pos++) {
		switch(string[pos]) {
			case 0: break;
			case '0'..'9', 'o', 'O', 'î', 'Î', 'ç', 'Ç': digits++;
			default: {
				if(digits >= 2) {
					digitGroups++;
					digits = 0;
				}
			}
		}
	}
	if(digits >= 2) digitGroups++;
	if(digitGroups >= 4) return 1;
	return 0;
}

stock strtolower(source[])
{
	for(new i; i < strlen(source); i++) switch(source[i]) {
		case 168: source[i] = 184;
		case 192..223: source[i] = (source[i] + 32);
		default: source[i] = tolower(source[i]);
	}
}
