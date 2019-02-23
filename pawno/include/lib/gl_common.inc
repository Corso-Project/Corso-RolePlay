stock PlaySoundForPlayersInRange(soundid, Float:range, Float:x, Float:y, Float:z)
{
	for(new i=0; i<MAX_PLAYERS; i++)
	{
	    if(IsPlayerConnected(i) && IsPlayerInRangeOfPoint(i,range,x,y,z))
	    {
		    PlayerPlaySound(i, soundid, x, y, z);
	    }
	}
}
