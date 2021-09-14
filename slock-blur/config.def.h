/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";

static const int blurlevel[NUMLEVELS] = {
       35,     /* after initialization */
       20,   /* during input */
       35,   /* failed/cleared the input */
};
static const Bool failonclear = False;

//Used for multi-threaded blur effect
#define CPU_THREADS 4

/* default messages */
static const char* messages[NUMLEVELS] = { "Screen locked", "Reading input..😀.", "Wrong password" };

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "-misc-fixed-medium-r-semicondensed--0-0-75-75-c-0-iso8859-1";

/* text position */
static const Bool centertext = False;

static const int text_x = 100;
static const int text_y = 50;


