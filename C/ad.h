#ifndef AD
#define AD

typedef struct
{
	float start_time;
	float end_time;
	int room_number;
} Meeting_t;

typedef struct
{
	int capacity;
	int index;
	Meeting_t** array;	
} Calendar_t;

Calendar_t* createAd(int size);
Meeting_t* createMeeting();
void destroyAd(Calendar_t* calendar);
void printAd(Calendar_t* calendar);
int insertAppointment(Calendar_t* calendar, Meeting_t* meeting);
int removeAppointment(Calendar_t* calendar, float begin_hour);
int findAppointment(Calendar_t* calendar, float begin_hour);


#endif
