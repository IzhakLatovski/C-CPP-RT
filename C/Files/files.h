#ifndef FILES
#define FILES

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
Meeting_t* createMeeting(float a, float b, int room);
void destroyAd(Calendar_t* calendar);
void printAd(Calendar_t* calendar);
int insertAppointment(Calendar_t* calendar, Meeting_t* meeting);
int removeAppointment(Calendar_t* calendar, float begin_hour);
Meeting_t* findAppointment(Calendar_t* calendar, float begin_hour);

void loadFromFile(Calendar_t* calendar);
void storeToFile(Calendar_t* calendar);


#endif
