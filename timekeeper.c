#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_hours(char * tbuf);
int get_minutes(char * tbuf);
int get_time(char * tbuf);
int get_day_hours(int day_of_week);

int debug = 0;

char weekdays[7][12] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

// gets hours part of time string
int get_hours(char * tbuf)
{
	char tmp[4];
	int i,j=0;

	if (debug)
		printf("tbuf: '%s'\n",tbuf);
	
	memset(tmp,0x00,sizeof(tmp));
	
	if (debug)
		printf("tmp: '%s'\n",tmp);

    i = 0;
    j = 0;	

	if (debug)
		printf("i: '%d', j: '%d', \n",i,j);

	tmp[i++] = tbuf[j++];
	tmp[i++] = tbuf[j++];
	tmp[i++] = 0;

	if (debug)
		printf("i: '%d', j: '%d', \n",i,j);
	
	if (debug)
		printf("tmp: '%s'\n",tmp);
	
	if (debug)
		printf("atoi(tmp): '%d'\n",atoi(tmp));
	
	return(atoi(tmp));
}

// gets minutes part of time string
int get_minutes(char * tbuf)
{
	char tmp[4];
	int i,j=0;

	if (debug)
		printf("tbuf: '%s'\n",tbuf);

	memset(tmp,0x00,sizeof(tmp));
	
	if (debug)
		printf("tmp: '%s'\n",tmp);
	
    i = 0;
    j = 2;	

	if (debug)
		printf("i: '%d', j: '%d', \n",i,j);

	tmp[i++] = tbuf[j++];
	tmp[i++] = tbuf[j++];
	tmp[i++] = 0;

	if (debug)
		printf("i: '%d', j: '%d', \n",i,j);
	
	if (debug)
		printf("tmp: '%s'\n",tmp);
	
	if (debug)
		printf("atoi(tmp): '%d'\n",atoi(tmp));

	return(atoi(tmp));
}

// gets time of day in minutes from midnight
int get_time(char * tbuf)
{
	if (debug)
		printf("tbuf: '%s'\n",tbuf);
	
	int hrs = get_hours(tbuf);
	
	if (debug)
		printf("hrs: '%d'\n",hrs);
	
	int mins = get_minutes(tbuf);
	
	if (debug)
		printf("mins: '%d'\n",mins);
	
	int t = hrs * 60 + mins;
	
	if (debug)
		printf("t: '%d'\n",t);
	
	return(t);
}

int get_day_hours(int day_of_week)
{
	char inbuf[120];

	printf("Enter times for '%s'\n",weekdays[day_of_week]);
	
	printf("Enter beginning time: ");
	scanf("%10s",inbuf);
	
	if (inbuf[0] == 'x')
		return(0);
		
	if (debug)
		printf("inbuf: '%s'\n",inbuf);
	
	int btime = get_time(inbuf);

	if (debug)
		printf("btime: '%d'\n",btime);
	
	printf("Enter ending time: ");
	scanf("%10s",inbuf);
	
	if (debug)
		printf("inbuf: '%s'\n",inbuf);

	int etime = get_time(inbuf);
	
	if (debug)
		printf("etime: '%d'\n",etime);
	
	int ttime = etime-btime;
	if (debug)
		printf("ttime: '%d'\n",ttime);
	
	printf("Total Minutes: %d\n",ttime);
	
	return(ttime);
}

int main(int argc, char * argv[])
{
	int i;
	int days[] = {0,0,0,0,0,0,0};
	int ttime, dtime,thrs,tmins;
	
	for (i=0;i<7;i++)
		days[i] = get_day_hours(i);
	
	ttime = 0;

	for (i=0;i<7;i++)
	{
		dtime = days[i];
		
		thrs = dtime / 60;
	
		tmins = dtime - (thrs * 60);
		
		ttime = ttime + dtime;
		
		printf("%s: %02d:%02d [%d] (%d)\n",weekdays[i],thrs,tmins,dtime,ttime);
	}

	exit(0);

}

